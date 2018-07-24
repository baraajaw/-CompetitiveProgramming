#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
char a[1001];
int dp[1001][1001];
int cal ( int i, int j){
    if ( i > j)
      return 0;
    int & res = dp[i][j];
    if (res != -1) return res;
    res = 1e9;
    if ( a[i] == a[j])
       return res = cal ( i + 1, j - 1);
    res = min ( res, min ( cal(i+1, j) + 1, min(cal (i, j-1) + 1, cal (i+1, j-1) + 1))); 
    return res;
}
int main() {
  int t, tt = 1;
  scanf("%d", &t);
  while ( t--){
      scanf("%s", a);
      int n = strlen (a);
      memset(dp, -1, sizeof dp);
      printf("Case %d: %d\n", tt++, cal(0, n - 1) );
  }
  return 0;
  
}
