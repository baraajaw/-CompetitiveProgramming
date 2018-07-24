#include <bits/stdc++.h>
#define ll long long 
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)
using namespace std;
string s, c;
int n, m, dp[5001][5001];
int cal(int i, int j){
    if (i == n) 
      return m - j;
    if ( j == m)
      return n - i;
    int &ret = dp[i][j];
    if (ret != -1) return ret;
    ret = 0;
    if ( s[i] == c[j]) 
     return ret = cal ( i + 1, j + 1);
    return  ret =  min ( cal (i + 1, j) + 1, min ( cal(i, j + 1) + 1, cal (i + 1, j + 1) + 1));
      
}
int main() {
 while (cin >> n >> s >> m >> c){
    memset(dp, -1, sizeof dp);
    cout << cal(0, 0)<< endl;
 }
 
  return 0;
 }
