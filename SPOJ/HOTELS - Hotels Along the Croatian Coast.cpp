#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int const N = 300003;
int  main() {

  ll n, m, a[N];

  scanf("%lld%lld", &n, &m);
  for (int i = 0; i < n; ++i)
      scanf("%lld", &a[i]);

  int l = 0, r = 0;
  ll sum = 0, ans = 0;
  
  while (r < n){
    sum += a[r];
    r++;
    while (sum > m){
      sum -= a[l];
      l++;
    }
    ans = max(ans, sum);
  }  
  printf("%lld\n", ans);
  


  return 0;
}
