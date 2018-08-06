#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
int n, k, dp[101][100];
int M = 1e6;
int cal (int sum, int cnt){
    if ( cnt == k)
      return (sum == n) ? 1 : 0; 
    int &res = dp[sum][cnt];
    if ( res != -1)
        return res;
    res = 0;  
    f(i, 0, n + 1)
      if (sum + i <= n)
        res = ( res + cal (sum + i, cnt + 1)) % M;
    return res;  
}
int main() {
  while ( scanf("%d%d", &n, &k) && n && k){
    memset(dp, -1, sizeof dp);
    printf("%d\n", cal(0, 0));

  }
  return 0;
}
