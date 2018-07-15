#include <bits/stdc++.h>
#define ll long long 
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)
using namespace std;
int   n;
int coins[] = {1, 5, 10, 25, 50}; 
ll dp[30001][5];
ll cal (int rem, int i){
    if ( rem < 0 || i == 5) 
        return 0;
    if ( rem == 0)
        return 1;
    ll &ret = dp[rem][i];
    if ( ret != -1) return ret; 
    ret = 0;
    f(k, i, 5) 
      ret+= cal (rem - coins[k], k);     
    return ret;   
}
int main() {
  memset(dp, -1, sizeof dp);

  while ( scanf("%d", &n) == 1){
    ll res = cal (n, 0);
    if ( res == 1)
      printf("There is only 1 way to produce %d cents change.\n", n);
    else
      printf("There are %lld ways to produce %d cents change.\n", cal(n, 0), n);


  }


  return 0;
}
