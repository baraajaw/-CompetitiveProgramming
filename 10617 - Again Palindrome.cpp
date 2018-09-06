#include <bits/stdc++.h>
using namespace std;
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
char s[62];
ll dp[60][60];

ll cal (int i, int j){
	if(i == j)
		return 1;
	if( i > j || j < 0) 
		return 0;
	ll &res = dp[i][j];
	if(res != -1)
		return res;
	res = 0;
	if(s[i] == s[j])
		res += cal( i + 1, j - 1) + 1;
	res += cal(i+1, j);
	res += cal(i, j-1);
	res -= cal(i+1, j-1);
	return res;
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		memset(dp, -1, sizeof dp);
		printf("%lld\n", cal(0, strlen(s) - 1));
	}	
	
return 0;				
}
