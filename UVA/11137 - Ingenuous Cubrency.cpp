#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
int n;
ll dp[10001][22];
vector <int> v;
ll cal (int sum, int last){
  if ( sum == n)
    return 1;
  if ( sum > n)
      return 0;
  ll &res = dp[sum][last];
  if ( res != -1)
    return res;
  res = 0;
  f(i, last, 21) 
      res += cal (sum + v[i], i);   
  return res;
}
int main() {
  
  f(i, 1, 22)
    v.push_back(i * i * i);
  while (scanf("%d", &n) == 1){
    memset(dp, -1, sizeof dp);
    cout << cal (0, 0)<< endl;
  }
  

  return 0;
  
}
