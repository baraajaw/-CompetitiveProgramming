#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
int const N = 1e6 + 1;
int m, q, cnt =0;
int parent[N];
bool vis[N];
string a, b;
vector < vector < int > > g;
vector < int> path;
map <string, int> le;
map <int, string> ri;
queue<int> qu;
void BFS(int src , int des){
      memset(vis, false, sizeof vis);
      memset(parent, -1, sizeof parent);
      while (!qu.empty()) qu.pop();
      qu.push(src);
      vis[src] = true;

      while (!qu.empty()){
          int fr = qu.front();
          qu.pop();
          f(i, 0, g[fr].size()){
                int u = g[fr][i];
                if (!vis[u]){
                    parent[u] = fr;
                    vis[u] = true;
                    qu.push(u);
                }
          }
      }

}
void buildpath(int v){
  path.clear();
  while (v != -1){
    path.push_back(v);
    v = parent[v];
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--){
      scanf("%d%d", &m, &q);
      cnt = 0;
      g.clear();
      g.resize(N);
      le.clear();
      ri.clear();
      f(i, 0, m){
        cin >> a>> b;
        if (!le.count(a)){
          le[a] = cnt;
          ri[cnt] = a;
          cnt++;
        }
        if (!le.count(b)){
          le[b] = cnt;
          ri[cnt] = b;
          cnt++;
        }
        g[le[a]].push_back(le[b]);
        g[le[b]].push_back(le[a]);
      }
      f(i, 0, q){
        cin >> a >> b;
        BFS(le[a], le[b]);
        buildpath(le[b]);
        for(int i = path.size() - 1; i>= 0; --i)
          cout << ri[path[i]][0];
        cout << endl;
      }
      if (t != 0)
        puts("");  
      
  }
 
  return 0;
  
}
