#include <bits/stdc++.h>
using namespace std;
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
int const N = 1e5 + 1,  M = 1e9 + 7;
int n, dp[N], cnt, nxt[N][26];
char s[N];
bool vis[26];
vector <vector < int > > v(26);
int cal (int at){
	
	int &res = dp[at];
	if(res != -1)	return res;
	res = 1;
	f(i, 0, 26){
		if(nxt[at][i] == -1) continue;
		res += cal(nxt[at][i]);
		if (res >= M)
				res -= M;
	}
	return res;
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		memset(vis, false, sizeof vis);
		scanf("%s", s);
		n = strlen(s);

		int at[26] = { };
		memset(at, -1, sizeof at);
		for (int i = n - 1; i >= 0; --i) {
			for (int j = 0; j < 26; ++j)
				nxt[i][j] = at[j];
			at[s[i] - 'A'] = i;
		}
		
		memset(dp, -1, sizeof dp);
		int res = 1;
		f(i, 0, 26){
			if(at[i] != -1){ 
				res += cal(at[i]);
				if ( res >= M)
					res -= M;
			}
		}
		cout << res <<endl;
	}
	


return 0;
}
