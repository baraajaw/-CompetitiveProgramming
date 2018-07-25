#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
int n, tt;
ll dp[66][10];

ll cal(int cnt, int last){
  if ( cnt == n)
      return 1;
  ll &res = dp[cnt][last];
  if (res != -1)
      return res;
  res = 0;
  f(i, last, 10)
      res += cal(cnt + 1, i);
  return res;       
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--){
    scanf("%d%d", &tt, &n);
    memset(dp, -1, sizeof dp);
    printf("%d %lld\n", tt, cal(0, 0) );
  }
  return 0;
  
}
