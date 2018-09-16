#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int n, sx, sy, fx, fy, g[51][51];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int cost[51][51][1<<10];
bool vis[51][51][1<<10];
struct state{
  int x, y;
  bitset<11> msk;
  state(int x, int y, bitset<11> msk) :
      x(x), y(y), msk(msk) {
  }
};
queue<state> qu;
int BFS(){
  while(!qu.empty())  qu.pop();
  memset(vis, false, sizeof vis);
  memset(cost, 0, sizeof cost);
  bitset<11> bs;
  bs.reset();
  bs[g[sx][sy]] = 1;
  qu.push(state(sx, sy, bs));
  vis[sx][sy][bs.to_ulong()] = true;
  cost[sx][sy][bs.to_ulong()] = 1;


  int ans = 1e9, lev = 0;

  while(!qu.empty()){
    state s = qu.front();
    qu.pop();
    for(int i = 0; i < 4; ++i){
      int nx = dx[i] + s.x;
      int ny = dy[i] + s.y;
      if(nx < 0 || ny < 0 || nx >= n || ny >= n)
        continue;
      bitset<11> bs = s.msk;
      if (bs[g[nx][ny]] == 0)
        lev = 1;
      else
        lev = 0;

      if ( nx == fx && ny == fy){
        ans = min(ans, cost[s.x][s.y][s.msk.to_ulong()] + lev );
        continue;
      }
      
      bs[g[nx][ny]] = 1;
      if(vis[nx][ny][bs.to_ulong()])  continue;
      vis[nx][ny][bs.to_ulong()] = true;
      cost[nx][ny][bs.to_ulong()] = cost[s.x][s.y][s.msk.to_ulong()] + lev;
      qu.push(state(nx, ny, bs));

    }// end of for 
  } // end of !qu.empty()
  return ans;
}

int  main() {
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        scanf("%d", &g[i][j]);
    scanf("%d%d%d%d", &sx, &sy, &fx, &fy);
    cout << BFS()<<endl;  
  }
 
  return 0;
}
 
