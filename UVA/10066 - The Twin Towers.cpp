#include <bits/stdc++.h>
#define ll long long 
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)
using namespace std;
int n, m ,x[101], y[101];
int dp[101][101];
int cal ( int i, int j){
  if ( i == n || j == m)
    return 0;
  int & ret = dp[i][j];
  if ( ret != -1) 
    return ret;
  ret = 0 ;
  if ( x[i] == y[j]) 
      return ret = cal (i+ 1, j + 1)+ 1;
  ret = max ( ret, cal (i + 1, j));
  ret = max ( ret, cal (i, j + 1));
  return ret;
}

int main() {
  int t= 1;
 
  while ( scanf ("%d%d", &n, &m)  && n!= 0 && m != 0){
    f(i, 0, n) scanf("%d", x + i);
    f(i, 0, m) scanf("%d", y + i); 
    memset(dp, -1, sizeof dp);
    printf("Twin Towers #%d\n", t++ );
    printf("Number of Tiles : %d\n", cal (0, 0));
    puts("");
  }
  
  return 0;
}
