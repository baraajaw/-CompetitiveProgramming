#include <bits/stdc++.h>
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)
using namespace std;
int n, m;
vector < int > v, p;
vector < vector < int > > vv;
int dp[101], g[101][101];
bool ok ( vector<int>&v, vector < int>&vv){
  f(i, 0, v.size())
      if ( v[i]>= vv[i])
          return false;
  return true;      
}
int cal ( int i){
  if ( i == n )
    return 0;
  int & ret = dp[i];
  if ( ret != -1) 
    return ret;
  ret = 0 ;
  f(j, 0, n)
      if ( g[i][j])
          ret = max (ret, cal ( j) + 1);
  return ret;
}
void path(int i){
  int ind = -1, ans= -1;
  f(j, 0, n){
    if ( !g[i][j]) continue;
    int tmp = cal (j);
    if ( tmp > ans)
      ans = tmp, ind = j;
  }
  p.push_back(i + 1);
  if (ind != -1)
    path(ind);
}
int main() {
  int t= 1;
 
  while ( scanf ("%d%d", &n, &m)  > 0){
    vv.clear();
    f(i, 0, n){
      v.clear();
      v.resize(m);
      f(j, 0, m)
        scanf("%d", &v[j]);
      sort(v.begin(), v.end());
      vv.push_back(v);  
    }
    f(i, 0, n)
        f(j, 0, n)
          g[i][j] = ok ( vv[i], vv[j]);
    memset(dp, -1, sizeof dp);
    int ans = 0, ind;
    f(i, 0, n){
      int tmp = cal(i)+ 1;
      if ( tmp > ans)
        ans = tmp,  ind = i;
    }
    p.clear();
    printf("%d\n", ans );
    path (ind);
    f(i, 0, p.size()){
      printf("%d", p[i]);
      if ( i + 1 < p.size()) printf(" ");
    }      
    puts("");
  }
  
  return 0;
}
