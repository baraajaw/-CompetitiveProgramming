#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
int m, n;
vector < vector < int > > g;
bool vis[10001], cycle = false;
void DFS(int node, int p ){

  vis[node] = true;
  f(i, 0, g[node].size()){
    int u = g[node][i];
    if (vis[u] && u != p) 
        cycle = true;
    else if (!vis[u])
        DFS(u, node);
  }
}
int main() {
  while (scanf("%d%d", &n, &m) > 0 ){
  cycle = false;
  g.clear();  
  g.resize(n);
  memset(vis, false, sizeof vis);
  if ( m + 1 != n)
    cycle = true ;  
  f(i, 0, m){
    int a , b; 
    scanf("%d%d", &a, &b);
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for ( int i = 0 ; i < n && !cycle ; ++i)
      if (!vis[i])
        DFS(i, -1);
  if (!cycle)
    puts("YES");
  else
    puts("NO");
}
  return 0;
  
  
}
