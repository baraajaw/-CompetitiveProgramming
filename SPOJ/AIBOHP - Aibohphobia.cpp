#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
char s[6101];
int n;
int dp[ 6101][ 6101];
int cal ( int i, int j){
    if ( i >= j)
      return 0;
    int & res = dp[i][j];
    if (res != -1) return res;
    res = 1e9;
    if ( s[i] == s[j])
       return res = cal ( i + 1, j - 1);
    int a = cal (i + 1, j) + 1;
    int b = cal (i, j - 1) + 1;
    res = min (a, b); 
    return res;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--){
    scanf("%s", s);
    n = strlen(s);
    memset(dp, -1, sizeof dp);
    cout << cal (0, n - 1)<< endl;
  }

  return 0;
  
}
