#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
char a[25], b[25];
int n, m, dp[25][25];
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
void put(int len){
  if ( len < 10)
    putchar('0');
  printf("%d", len);
}
void path(int i, int j, int inc, int dec ){
  if (i == n && j == m){
      putchar('E');
      return ;
  }
  if (a[i] == b[j]){
    path(i + 1, j + 1, inc, dec);
    return;
  }
  int x = cal (i + 1, j) + 1;
  int y = cal (i, j + 1) + 1;
  int z = cal (i + 1, j + 1) + 1;
  int mn = min (x, min(y,z));
  int len = i + 1 + inc - dec; 
  if ( x == mn){
    putchar('D');
    putchar(a[i]);
    put(len);
    path(i + 1, j, inc, dec + 1);
    return ;
  }
  if ( y == mn){
    putchar('I');
    putchar(b[j]);
    put(len);
    path(i, j + 1, inc + 1, dec);
    return;
  }
  putchar('C');
  putchar(b[j]);
  put(len);
  path(i + 1, j + 1, inc, dec);

}
int main() {
  while (scanf("%s", a) && a[0] != '#'){
      scanf("%s", b);
      n = strlen(a);
      m = strlen(b);
      memset(dp, -1, sizeof dp);
      path(0, 0, 0, 0);
      puts("");

  }
  return 0;
}
