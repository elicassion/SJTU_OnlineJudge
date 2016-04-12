#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int n, m;
vector<pair<string, int> > dict;
 
bool match(string& pref, string& word) {
	if (pref.size() > word.size()) return false;
	return word.substr(0, pref.size()) == pref;
}
 
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		dict.push_back(make_pair(s, i));
	}
	sort(dict.begin(), dict.end());
	for (int i = 0; i < m; i++) {
		int k;
		string pref;
		cin >> k >> pref;
		k--;
		int pos = lower_bound(dict.begin(), dict.end(), make_pair(pref, 0)) - dict.begin();
		// Ignore whether pos even matches at all
		int poss = pos + k;
		if (poss < dict.size() && match(pref, dict[poss].first)) {
			cout << dict[poss].second + 1 << '\n';
		} else {
			cout << -1 << '\n';
		}
	}
}