#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
char a[85], b[85];
int n, m, t =1, dp[85][85];
int cal (int i, int j){
    if(n == i && j == m)
        return 0;
    if ( i > n || j > m)
        return 2e9;
    int & res = dp[i][j];
    if ( res != -1)
      return res;
    if (a[i] == b[j])
      return res = cal(i + 1, j + 1);
    int x = cal (i + 1, j) + 1;
    int y = cal (i, j + 1) + 1;
    int z = cal (i + 1, j + 1) + 1;
    res = min(x, min (y, z));
    return res;
}
void path(int i, int j, int inc, int dec ){
  if (i == n && j == m)
    return;
  
  if (a[i] == b[j]){
    path(i + 1, j + 1, inc, dec);
    return;
  }
  int x = cal (i + 1, j) + 1;
  int y = cal (i, j + 1) + 1;
  int z = cal (i + 1, j + 1) + 1;
  int mn = min (x, min(y,z));
  int len = i + 1 + inc - dec; 
  printf("%d", t++);
  if ( x == mn){
    printf(" Delete %d\n", len);
    path(i + 1, j, inc, dec + 1);
    return ;
  }
  if ( y == mn){
    printf(" Insert %d,%c\n", len, b[j]);
    path(i, j + 1, inc + 1, dec);
    return;
  }
  printf(" Replace %d,%c\n", len, b[j]);

  path(i + 1, j + 1, inc, dec);

}
int main() {
  bool ok = false;
  while (gets(a) > 0){
      if (ok) puts("");
      ok = true;
      gets(b);
      n = strlen(a);
      m = strlen(b);
      memset(dp, -1, sizeof dp);
      printf("%d\n", cal(0, 0));
      path(0, 0, 0, 0);
      t = 1;

  }
  return 0;
}
