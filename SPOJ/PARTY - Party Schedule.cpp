#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
int n, b;
pair < int , int > p[101];
ll dp[501][101];
ll cal (int i, int c){
    if ( i == n) 
         return 0;    
    ll & res = dp[c][i];
    if ( res != -1)
        return res;  
    res = 0;
    if ( c >= p[i].first)
      res = max (res, cal ( i + 1, c - p[i].first) +p[i].second);
    res = max (res, cal ( i + 1, c));
    return res;
}
int main() {
  while(scanf("%d%d", &b, &n) && b && n ){
      f(i, 0, n)
        scanf("%d%d", &p[i].first, &p[i].second);
      memset(dp, -1, sizeof dp);
      int ans = cal (0, b), l = 0, r = b;
      while(l < r){
        int mid = ( l + r) / 2;
        if ( cal (0, mid) < ans) l = mid + 1;
        else r = mid;
      }
      printf("%d %d\n", l, ans );
  }

  return 0;
  
}
