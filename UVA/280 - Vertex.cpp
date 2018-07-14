#include <bits/stdc++.h>
#define ll long long 
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)
using namespace std;
int n, q, x, y;
bool vis[101];
vector < vector < int > > g;
vector < int > ans;
void dfs(int node){
  f(i, 0, g[node].size()){
    if (!vis[g[node][i]]){
      vis[g[node][i]] = 1;
      dfs(g[node][i]);
    }
  }
}
int main() {
  
  while ( scanf("%d", &n) && n != 0){
    g.clear();
    g.resize(n);
    while( scanf("%d", &x) && x != 0) {
        --x;
        while ( scanf("%d", &y) && y != 0){
          --y;
          g[x].push_back(y);
        }
    }
    scanf("%d", &q);
    while ( q--){
      scanf ("%d", &x);
      memset(vis, 0, sizeof vis);
      --x;
      dfs(x);
      f(i, 0, n){
        if( !vis[i])
          ans.push_back(i + 1);
      }
      printf("%d", ans.size());
      f(i, 0, ans.size())
          printf(" %d", ans[i] );
      puts("");
      ans.clear();    
    }
  }
  


  return 0;
}
