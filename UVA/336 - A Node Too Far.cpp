#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
int m, n;
map < int, int > mp;
vector < int > g[30];
queue< int > q;
bool vis[30]; 
int bfs(int src, int mx){
  memset(vis, false, sizeof vis);
  while (!q.empty()) q.pop();
  vis[src] = true;
  q.push(src);
  int level = 0;
  while(!q.empty() && level < mx){
      int size = q.size();
      while (size-- != 0){
        int fr = q.front();
        q.pop();
        f(i, 0, g[fr].size()){
              int u = g[fr][i];
              if (!vis[u])
                vis[u] = true, q.push(u);
        }// f loop end       
      }
      ++level;
  }
  int ans = 0;
  f(i, 0, n)
    if (!vis[i])
      ans++;
  return ans;  
}
int main() {
  int case_num = 1;
  while (scanf("%d", &m) && m != 0){
    f(i, 0, 30)  g[i].clear();
    mp.clear();
    n = 0;  

    while ( m-- != 0){
      int a, b;
      scanf("%d%d", &a, &b);
      if (mp.find(a) == mp.end())
        mp[a] = n++;
      if (mp.find(b) == mp.end())
        mp[b] = n++;
      a = mp[a], b = mp[b];
      g[a].push_back(b);
      g[b].push_back(a);
    }
    int src, level;
    while ( scanf("%d%d", &src, &level) > 0 && (src || level))
      printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", case_num++, bfs(mp[src], level), src, level);
  }  
 
  return 0;
  
}
