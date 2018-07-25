#include <bits/stdc+.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
int n, a, b;
int dp[1001][22][80];
vector <pair < int, pair < int, int > > > v;
int cal (int i, int c, int d){
    if (c >= a && d >= b) return 0;
    if ( i == n)
        return 2e9;
    int & res = dp[i][c][d];
    if ( res != -1)
        return res;
    res = 2e9;
    res = min ( res, cal (i + 1, min(c +v[i].first, a), min(d + v[i].second.first, b)) + v[i].second.second);
    res = min ( res, cal (i + 1, c, d));
    return res;            
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--){
    scanf("%d%d", &a, &b);
    scanf("%d", &n);
    v.clear();
    v.resize(n);
    f(i, 0, n)
      scanf("%d%d%d", &v[i].first, &v[i].second.first, &v[i].second.second);
    memset(dp, -1, sizeof dp);  
    printf("%d\n", cal (0, 0, 0));
  }
  

  return 0;
  
}
