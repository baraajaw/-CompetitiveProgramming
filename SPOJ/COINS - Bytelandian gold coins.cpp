#include <bits/stdc++.h>
using namespace std;
#define ll long long 
map< int, ll> dp;
ll cal (ll i){
  if(i == 0)
    return 0;
  if(dp.find(i) != dp.end())
    return dp[i];
  ll res = cal(i / 2) + cal(i / 3) + cal(i / 4);

  return dp[i] = max (i, res);
}
int  main() {
  int n;
  while (scanf("%d", &n) > 0)
    cout << cal(n)<< endl;
  
  return 0;
}
 
