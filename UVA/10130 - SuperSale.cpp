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
int n, m, x, dp[2001][2001], ans = 0;
pair < int, int > p[1001];
int cal ( int i, int c){
   if ( c < 0) 
      return -(2e9);
   if ( i == n) 
      return 0;
   int & ret = dp[i][c];
   if ( ret != -1) return ret;
   ret = 0;
   
  ret = max ( ret, cal (i + 1, c - p[i].second) + p[i].first);
  ret = max ( ret, cal ( i + 1, c));
  return ret;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--){
    ans = 0;
    memset(dp, -1, sizeof dp);
    scanf("%d", &n);
    f(i, 0, n) scanf ("%d%d" , &p[i].first, &p[i].second);
    scanf("%d", &m);
    f(i, 0, m){
      scanf("%d", &x);
      ans += cal ( 0, x);
    }
    printf("%d\n", ans);
  }  
  return 0;
}
