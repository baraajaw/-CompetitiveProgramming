#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
char a[1001];
int dp[1001][1001];
int cal ( int i, int j){
    if ( i > j)
      return 0;
    if ( i == j)
      return 1;
    int & res = dp[i][j];
    if (res != -1) return res;
    res = 0;
    if ( a[i] == a[j])
       return res = cal ( i + 1, j - 1) + 2;
    res = max (cal (i+1, j), cal (i, j-1));
    return res;
}
int main() {
  int t;
  scanf("%d", &t);
  gets(a);
  while ( t--){
      gets(a);
      int n = strlen (a);
      memset(dp, -1, sizeof dp);
      cout << cal (0, n - 1)<< endl;
  }
  return 0;
  
}
