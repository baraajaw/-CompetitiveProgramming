#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
#define INT_MAX  2147483647 
using namespace std;
int n;
ll dp[205][12];
char s[205];
ll get(int idx, int len){
    if (len > 1 && s[idx] == '0')
        return 0;
    ll res = 0;
    for(int i = idx, j = 0 ; j < len ; ++i, ++j)
      res = res * 10 + (s[i] - '0');
    if(res <= INT_MAX)
      return res;
    return -1;      
}
ll  cal ( int idx, int len){
  if ( idx == n)
      return 0;
  ll &res = dp[idx][len];  
  if (res != -1)
    return res;
  res = -(2e15);
  if ( len + 1 <= 10 && idx + len < n)
    res = max (res, cal(idx, len + 1));
  ll ans = get (idx, len);
  if ( ans != -1)
      res = max (res, cal (idx + len, 1) + ans);
  return res;          
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--){
    scanf("%s", s);
    n = strlen (s);
    memset(dp, -1, sizeof dp);
    printf("%lld\n", cal (0, 1));
  }
  return 0;
}
