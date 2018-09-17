#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int n, mxLen, at;
vector < vector < int > > g;

void DFS(int v, int par, int len){
  for (int i = 0; i < g[v].size(); ++i)
    if (g[v][i] != par)
      DFS(g[v][i], v, len + 1);
    if(len > mxLen){
      mxLen = len;
      at = v;
    }
}
int  main() {
  while (scanf("%d", &n) > 0){
    g.clear();
    g.resize(n);
    int u, v;
    for ( int i = 1; i < n; ++i){
      scanf("%d%d", &u, &v);
      --u; --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    mxLen = -1;
    DFS(0, -1, 0);
    DFS(at, -1, 0);
    printf("%d\n", mxLen);
  }
  
  return 0;
}
 
