#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
int n, m, t = 1;
string x,y;
char a[101], b[101];
int dp[101][101];
int cal ( int i, int j){
  if ( i == x.size() || j == y.size())
    return 0;
  int & ret = dp[i][j];
  if ( ret != -1) 
    return ret;
  ret = 0 ;
  if ( x[i] == y[j]) 
      return ret = cal (i + 1, j + 1)+ 1;
  ret = max ( ret, cal (i + 1, j));
  ret = max ( ret, cal (i, j + 1));
  return ret;
}

int main() {
  while ( true){
      gets(a); x = a;
      gets(b); y = b;
      if ( x[0] == '#') break;
      memset(dp, -1, sizeof dp);
     printf("Case #%d: you can visit at most %d cities.\n", t++, cal(0, 0) );
  }  
  return 0;
  
}
  
