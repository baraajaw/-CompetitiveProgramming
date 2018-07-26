#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
int n , v[2001];
ll dp[2001][2001];
ll cal (int i, int j, int cnt){
    if ( i > j) 
          return 0;
    ll & res = dp[i][j];
    if ( res != -1)
        return res;  
    res = 0;
    res = max (res, cal ( i + 1, j, cnt + 1) + ( v[i] * cnt));
    res = max (res, cal ( i, j - 1, cnt + 1) + ( v[j] * cnt));
    return res;
}
int main() {
  scanf("%d", &n);
  f(i, 0, n)
      scanf("%d", &v[i]);
  memset(dp, -1, sizeof dp);
  printf("%lld\n", cal (0, n - 1, 1));    
  

  return 0;
  
}
