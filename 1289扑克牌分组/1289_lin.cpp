#include <iostream>

using namespace std;
int nums[100005]	={0};//存储原始数据
int presum[100005]	={0};//前缀和 后来排序
int uqsum[100005]	={0};//排序且去重的前缀和
int cnt 			= 0; //表示uq的长度
int c[100005]		={0};//树状数组 存储dp
const int MOD = 1000000009;

/*
样例:
5 
2 3 -5 2 1

nums: 2 3 -5 2 1
presum: 0 2 5 0 2 3
presum_sort: 0 0 2 2 3 5
uqsum: 0 2 3 5  (cnt = 4)
由于树状数组的二进制性质 下标是1开始的
dp1 指的是 前缀和是0 那段 有多少种符合条件的分法....依次类推


c数组很抽象 这里以cnt=4时举例 
还记得在上一个算法中的转移方程为 dp[i] = sigma( dp[j] ) 
j满足两个条件 :		1.j<i 		2. presum[j] <= presum[i] 
上一个算法过慢的原因是,2需要每次遍历所有比i小的j来判断presum的关系,我们可以考虑将presum排序从而减少遍历的比较过程
c的每一阶段 是当前和情况下 dp数组的 树状数组 dp不用显式存储
要注意 这里的dp[k]指的是 以k为前缀和时的解决方案数 (可能会疑虑重复的k,不同的位置的问题,这个不会影响,因为dp的更新顺序是根据输入顺序决定的,最后输出的一定是正确的)
在样例中
树状数组: 所以
c1 = dp1
c2 = dp1 + dp2 
c3 = dp3
c4 = dp1 + dp2 + dp3 + dp4

每次更新某一个dp时,要更新每一个c中节点的后继节点(父节点)  因为有重合
每次获取值的时候,要遍历它和它所有的前驱节点
*/


inline int lowbit(int cid){
	return cid & (-cid);
}

inline int getSum(int cid){ //得到树状数组中id是cid的那个节点的值 
	int sum = 0;
	for (int i = cid; i >= 1 ; i -= lowbit(i)) //注意i的更新是找前驱节点
		sum = (sum + c[i]) % MOD;
	return sum;
}

inline void update(int cid, int value){ //更新某一个c[cid]的值 value也是从c里取出来的 所以已经是几个dp的和了
	for (int i = cid; i <= cnt; i += lowbit(i))
		c[i] = (c[i] + value) % MOD;
}

inline int find(int key){ //find(key)+1 表示的是 再uqsum中比key小的个数+1 正好是c中对应的cid
	return lower_bound(uqsum,uqsum+cnt,key) - uqsum; //lower_bound返回的是uqsum中小于cnt的最后一个的指针
}

int main(int argc, char const *argv[])
{
	//输入数据 并且同时计算原始前缀和数组
	int N; cin>>N;
	presum[0]=0;
	for (int i = 1; i <= N; ++i)
	{
		cin>>nums[i];
		presum[i] = presum[i-1] + nums[i];
	}

	//对presum排序 注意presum的长度为N+1
	sort(presum,presum+N+1);
	//去重 加入到uqsum中 
	
	uqsum[cnt] = presum[0];
	for (int i = 1; i < N+1; ++i)
	{
		if(presum[i] != uqsum[cnt])
			uqsum[++cnt] = presum[i];
	}
	cnt++;//cnt表示个数

	//初始化c数组 
	update(find(0)+1,1);// 如果前缀和没有负数: 其实是dp1=1的意思 指的是前缀和为uqsum[0]的分法为1
						// 如果前缀和里有负数: 就是 dp1 = dp2...= dpk = 1 其中uqsum[k-1] = 0

	
	int res = 0; //记录每次的dp和, 用于更新下一阶段
	int curSum = 0;
	for (int i = 1; i <= N; ++i)//针对每个前缀和
	{
		curSum +=  nums[i];
		int cid = find(curSum) + 1; //得到当前和对应的cid
		res = getSum(cid);
		
		update(cid,res);
	}
	cout<<res<<endl;

	// for (int i = 0; i < N+1; ++i)
	// {
	// 	cout<<presum[i]<<" ";
	// }cout<<endl;

	// for (int i = 0; i < cnt; ++i)
	// {
	// 	cout<<uqsum[i]<<" ";
	// }cout<<endl;
	return 0;
}