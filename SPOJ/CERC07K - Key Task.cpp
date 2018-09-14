#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int n, m, sx, sy;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool vis[101][101][1<<4];
char g[102][102];

//vector<string> g;
struct state{
  int x, y;
  bitset<4> msk;
  state(int x, int y, bitset<4> msk) :
      x(x), y(y), msk(msk) {
  }
};
queue<state> qu;
pair<char, int> arr[4] = { make_pair('B', 0 ), make_pair('Y', 1 ), make_pair( 'R', 2 ), make_pair( 'G', 3 ) };
int BFS(){
  while(!qu.empty()) qu.pop();
  memset(vis, false, sizeof vis);
  bitset<4> bs;
  bs.reset();

  qu.push(state(sx, sy, bs));
  vis[sx][sy][bs.to_ulong()] = true;
  int res = -1, lev = 1;
  while (!qu.empty()){
    int si = qu.size();
    while (si-- != 0){
      state s = qu.front();
      qu.pop();
      for (int i = 0; i < 4; ++i){
        int nx = dx[i] + s.x;
        int ny = dy[i] + s.y;
        if (nx < 0 || ny < 0 || nx >= n || ny >= m || g[nx][ny] == '#')
          continue;
        if (g[nx][ny] == 'X') {
            res = lev;
            break;
          }
        if(g[nx][ny] == '.' || g[nx][ny] == '*'){
          if(!vis[nx][ny][s.msk.to_ulong()]){
            vis[nx][ny][s.msk.to_ulong()] = true;
            qu.push(state(nx, ny, s.msk));
          }// end of !vis 
          continue;
        }
        bool ok = false;
        for(int j = 0; j < 4; ++j){
          if(g[nx][ny] != tolower(arr[j].first))
            continue;
          bitset<4> bs = s.msk;
          bs[arr[j].second] = 1;
          if(!vis[nx][ny][bs.to_ulong()]){
            vis[nx][ny][bs.to_ulong()] = true;
            qu.push(state(nx, ny, bs));
          } // end of if 
          ok = true;
          break;
        }
        if (ok)
            continue;
        for(int j = 0; j < 4; ++j){
          if(g[nx][ny] != arr[j].first)
            continue;
          if(s.msk[arr[j].second] && !vis[nx][ny][s.msk.to_ulong()]){
            vis[nx][ny][s.msk.to_ulong()] = true;
            qu.push(state(nx, ny, s.msk));
          }
          break;
        }  
      }// end of for
       if (res != -1)
        break;
    }// end of si--
    if (res != -1)
          break;
      ++lev;
  }// end of qu.empty
  return res;
}
int  main() {
  while(scanf("%d%d", &n, &m) && n != 0){
    for(int i = 0; i < n; ++i){
      scanf("%s", g[i]);
      for(int j = 0; j < m; ++j)
       if(g[i][j] == '*')
        sx = i, sy = j;   
    }
    int ans = BFS();
    if(ans == -1)
      puts("The poor student is trapped!");
    else
      printf("Escape possible in %d steps.\n", ans);


  }// end of while 
  
  return 0;
}
