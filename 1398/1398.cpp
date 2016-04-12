#include <cstdio>
#define LIMIT 1000000007

long long dp[22][10][220][2] = {}; //length, first_number, sum+100, sum:num
long long basics[22] = {0, 1};
long long lower, upper, sum;

long long GetResult(long long number){
    int len = 0;
    for(long long i = number; i; i /= 10, ++len);
    long long result = 0;
    if(sum == 0)
        ++result;
    for(int i = 1; i < len; ++i)
        for(int j = 1; j < 10; ++j)
            result = (result + dp[i][j][sum + 100][0]) % LIMIT;
    long long num = 0;
    for(int i = len, tmp_sum = sum + 100, j; i > 0;
         number -= basics[i] * j, --i, tmp_sum = 200 - (tmp_sum - j), num = num * 10 + j){
        for(j = 0; basics[i] * (j+1) <= number; ++j){
            if (i == len && j == 0)
                continue;
            result += dp[i][j][tmp_sum][0] + dp[i][j][tmp_sum][1] * (num * basics[i+1] % LIMIT) % LIMIT;
        }
        result %= LIMIT;
    }
    return result;
}

int main(){
    for(int i = 2; i < 22; ++i)
        basics[i] = basics[i-1] * 10;
    scanf("%lld%lld%lld", &lower, &upper, &sum);
    for(int i = 0; i < 10; ++i){
        dp[1][i][i+100][0] = i;
        dp[1][i][i+100][1] = 1;
    }
    for(int i = 2; i < 22; ++i)
        for(int j = 0; j < 10; ++j)
            for(int k = 0; k < 200; ++k){
                for(int m = 0; m < 10; ++m){
                    dp[i][j][k][0] += dp[i-1][m][200 - (k - j)][0];
                    dp[i][j][k][1] += dp[i-1][m][200 - (k - j)][1];
                }
                dp[i][j][k][0] += dp[i][j][k][1] * (j * basics[i] % LIMIT) % LIMIT;
                dp[i][j][k][0] %= LIMIT;
                dp[i][j][k][1] %= LIMIT;
            }
    long long result_upper = GetResult(upper+1);
    long long result_lower = GetResult(lower);
    long long result = result_upper - result_lower;
    if(result < 0)
        result += LIMIT;
    printf("%lld\n", result);
}