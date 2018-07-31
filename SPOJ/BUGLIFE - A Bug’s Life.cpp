#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
int n, m;
int type[2000];
bool vis[2000];
vector < vector < int > > g;
void DFS(int node, int gen){
  vis[node] = true;
  type[node] = gen;
  f(i, 0, g[node].size())
      if (!vis[g[node][i]]){
          if (type[node] == -1)
            DFS(g[node][i], 1);
          else
            DFS(g[node][i], -1);
      }
}
int main() {
  int t, tt = 1;
  scanf("%d", &t);
  while (t--){
    scanf("%d%d", &n, &m);
    bool bad = false;
    g.clear();
    g.resize(n);
    memset(vis, false, sizeof vis);
    memset(type, 0, sizeof type);
    f(i, 0, m){
      int a, b;
      scanf("%d%d", &a, &b);
      --a; --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    f(i, 0, n)
      if (!vis[i])
        DFS(i, 1);
    f(i, 0, n)
        f(j, 0, g[i].size())
            if (type[i] == type[g[i][j]])
               bad = true;
    if (bad)
          printf("Scenario #%d:\nSuspicious bugs found!\n", tt++);
    else
          printf("Scenario #%d:\nNo suspicious bugs found!\n", tt++);
  

  }  

  return 0;
}
