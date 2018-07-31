#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
int n, m, ans = 0, in = 0;
bool vis[50][50];
int cost[50][50];
char a[1000], b[1000];
vector < vector < int > > g;
map < string, int > mp;
queue<int > q;
void BFS(int v){
    while (!q.empty()) q.pop();

    vis[v][v] = true;
    cost[v][v] = 0;
    q.push(v);
    int level = 1;
    while(!q.empty()){
      int size = q.size();
      while (size--){
            int u = q.front();
            q.pop();
            f(i, 0, g[u].size()){
                int w = g[u][i];
                if (vis[v][w])    continue;
                vis[v][w] = true;
                cost[v][w] = level;
                q.push(w);
            }
      }
      ++level;
    }
}
int main() {
  int t = 1;
  while (scanf("%d%d", &n, &m) && n && m){
      g.clear();
      mp.clear();
      g.resize(n);
      in = 0, ans = 0;

      f(i, 0, m){
          scanf("%s%s", a, b);
          if (mp.find(string(a)) == mp.end())
            mp[string(a)] = in++;
          if (mp.find(string(b)) == mp.end())
            mp[string(b)] = in++;
          int x = mp[string(a)], y = mp[string(b)];
          g[x].push_back(y);
          g[y].push_back(x);
      }
      memset(vis, false, sizeof vis);
      memset(cost, -1, sizeof cost);
      f(i, 0, n)
          BFS(i);
      bool ok = true;
      f(i, 0, n)
          if (cost[0][i] == -1)
            ok = false;
      f(i, 0, n)
          f(j, 0, n)
              ans = max ( ans, cost[i][j]);      
      if (!ok)  
          printf("Network %d: DISCONNECTED\n", t++);
      else
          printf("Network %d: %d\n", t++, ans);
      puts("");  

  }  

  return 0;
}
