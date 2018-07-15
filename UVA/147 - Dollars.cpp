#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#define ll long long 
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)
using namespace std;
double  n;
int coins[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
ll dp[11][ 30001];
int main() {
  f(i, 0, 11)
    dp[i][0] = 1;
  for ( int i = 5; i < 30001 ; i+= 5){
    f(j, 0, 11){
      if (j)
        dp[j][i] = dp[j - 1][i];
      if ( i - coins[j] >= 0)
        dp[j][i] += dp[j][i - coins[j]];
    }
  }
  while ( scanf ("%lf", &n) && n != 0){
          int v = (n + 1e-9) * 100;
          printf("%6.2lf%17lld\n", n, dp[10][v]);


  }


  return 0;
}
