#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
int n, ans = 0, at ;
bool vis[10000];
vector < vector < int > > g;
void DFS(int node, int cnt){
    vis[node] = true;
    f(i, 0, g[node].size())
        if (!vis[g[node][i]])
              DFS(g[node][i], cnt + 1);
    if ( cnt > ans)        
        ans = cnt , at = node;         

}
int main() {
  while (scanf("%d", &n) > 0){
        ans = 0;  
        g.clear();  
        g.resize(n);
        memset(vis, false, sizeof vis);
        f(i, 0, n - 1){
            int a, b;
            scanf("%d%d", &a, &b);
            --a; --b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        DFS(0,0);
        memset(vis, false, sizeof vis);
        DFS(at, 0);
        printf("%d\n", ans );
  }
  return 0;
}
