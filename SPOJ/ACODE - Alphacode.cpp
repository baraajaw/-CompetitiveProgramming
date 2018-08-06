#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
char s[5009];
int n;
ll dp[5009];
bool check (int idx){
  if( idx + 1 >= n)
    return false;
  if(s[idx] == '1')
    return true;
  if(s[idx] == '2' && s[idx + 1] <= '6')
    return true;
  return false;
}
ll cal(int idx){
  if (idx == n)
      return 1;
  if(idx > n)
      return 0;        
  ll &res = dp[idx];
  if(res != -1)
      return res;
  res = 0;
  if(s[idx] == '0')     return res;
  res += cal (idx + 1);
  if (check(idx))
    res += cal(idx + 2);
  return res;    
}
int main() {
  while (scanf("%s", s) && s[0] != '0'){
      n = strlen(s);
      memset(dp, -1, sizeof dp);
      printf("%lld\n", cal(0));
  }
  return 0;
}
