#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
int n, e, ans = 0;
vector < vector < int > > g;
bool vis[100001];
void dfs(int node){
  vis[node] = true;
  f(i, 0, g[node].size())
      if (!vis[g[node][i]])
        dfs(g[node][i]);
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--){
      scanf("%d%d", &n, &e);
        ans = 0;
      g.clear();
      g.resize(n);
      memset(vis, false, sizeof vis);
      f(i, 0, e){
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
      }
      f(i, 0, n)
        if (!vis[i]){
            dfs(i);
            ans++;
        }
      printf("%d\n", ans );  
      
  }
 
  return 0;
  
}
