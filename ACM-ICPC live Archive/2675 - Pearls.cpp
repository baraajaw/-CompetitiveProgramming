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
#include <sstream>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
int cnt[101], pri[101], dp[101][101], n;

int cal ( int idx, int last_idx, int tot_sum){
  if ( idx == n){
       if ( last_idx != idx)
              return 1e9;
       return 0;  
  }
  int & ret = dp[idx][last_idx];
  if ( ret != -1 )
      return ret;
  ret = cal (idx + 1, idx + 1, 0) + (tot_sum + cnt[idx] + 10) * pri[idx];
  ret = min (ret, cal (idx + 1, last_idx , tot_sum + cnt[idx]));
  return ret; 
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    f(i, 0, n)
      scanf("%d%d", cnt + i, pri + i);
    memset(dp, -1 , sizeof dp);
    printf("%d\n", cal ( 0, 0, 0));
  
  }  
  return 0;
  
}
