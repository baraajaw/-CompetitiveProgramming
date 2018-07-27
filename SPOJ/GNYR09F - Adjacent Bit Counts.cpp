#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
int n, k, m;
ll dp[101][101][2];
ll cal ( int i, int cu, int cnt){
    if ( i == n)
      return ( cnt == k) ? 1 : 0;
    ll & res = dp[i][cnt][cu];
    if (res != -1) return res;
    res = 0;
    res += cal ( i + 1, 0, cnt);
    res += cal ( i + 1, 1, cnt + cu);
    return res;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--){
    scanf("%d%d%d", &m, &n, &k);
    memset(dp, -1, sizeof dp);
    printf("%d %lld\n", m, cal(0, 0, 0) );
  }

  return 0;
  
}
