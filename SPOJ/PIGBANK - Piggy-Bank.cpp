#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
int n , e, f;
pair < int , int > p[501];
ll dp[501][10001];
ll cal (int i, int c){
    if ( i == n) 
          return (c== 0)? 0 : 2e9;
    if (c == 0)
        return 0;    
    ll & res = dp[i][c];
    if ( res != -1)
        return res;  
    res = 2e9;
    if ( c - p[i].second >= 0){
      res = min (res, cal ( i + 1, c - p[i].second) +p[i].first);
      res = min (res, cal(i, c - p[i].second) + p[i].first);
    }
    res = min (res, cal ( i + 1, c));
    return res;
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--){
  scanf("%d%d%d", &e, &f, &n);
  f(i, 0, n)
      scanf("%d%d", &p[i].first, &p[i].second);
  memset(dp, -1, sizeof dp);
  ll ans = cal (0, f - e);
  if ( ans == 2000000000)
      puts("This is impossible.");
  else  
      printf("The minimum amount of money in the piggy-bank is %lld.\n", cal (0, f - e));    
  }

  return 0;
  
}
