#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
int n, dp[1001][1001], a[1001];
int cal ( int i, int j , int cur){
    if ( i > j) 
        return 0;
    int & ret = dp[i][j];
    if ( ret != -1)
      return ret;
    if ( cur == 0)
      ret = max ( a[i] - cal ( i + 1, j , 1) , a[j] - cal (i, j - 1, 1) );
    else{
        if ( a[i] >= a[j]) ret = a[i] - cal (i + 1, j, 0);
        else ret = a[j] - cal ( i, j - 1, 0) ;
    }
    return ret;      
}
int main() {
  int tt = 1;
  while ( scanf ("%d", &n) && n){
      f(i, 0, n)  scanf ("%d", a + i);
      memset(dp, -1, sizeof dp);
      printf("In game %d, the greedy strategy might lose by as many as %d points.\n", tt++, cal (0, n -1, 0) );
  }
  return 0;
  
}
