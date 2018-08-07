#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
#define INT_MAX  2147483647 
using namespace std;
int l, n, a[60], dp[60][60];
int cal( int i, int j){
  
    int &res = dp[i][j];
    if (res != -1)
      return res;
    res = 1e9;
    for(int k = i + 1; k < j; ++k)
      res = min(res, cal(i, k) + cal(k, j) + (a[j] - a[i]));
    if ( res >= 1e9)
      res = 0;
    return res;

}
int main() {
  while(scanf("%d", &l) && l != 0){
      scanf("%d", &n);
      a[0] = 0;
      for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
      a[n + 1] = l;
      sort(a, a + n + 2);
      memset(dp, -1, sizeof dp);
      printf("The minimum cutting is %d.\n", cal(0, n + 1));
  }
  return 0;
}
