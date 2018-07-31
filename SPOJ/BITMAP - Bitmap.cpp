#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
int n, m;
char g[190][190];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int cost[190][190];
queue<pair < int, int > > q;
void BFS(){
    while (!q.empty()){
      pair < int , int > p;
      p = q.front();
      q.pop();
      f(i, 0, 4){
          int nx = dx[i] + p.first;
          int ny = dy[i] + p.second;
          if ( nx < n && nx >= 0 && ny < m && ny >= 0 && g[nx][ny] == '0' && cost[nx][ny] > cost[p.first][p.second] + 1){
              q.push(make_pair(nx, ny));
              cost[nx][ny] = cost[p.first][p.second] + 1;
          }
      }
    }
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%d%d", &n, &m);
    f(i, 0, n)
        f(j, 0, m){
            scanf(" %c", &g[i][j]);
            cost[i][j] = 1e9;
            if (g[i][j] == '1'){
                  cost[i][j] = 0;
                  q.push(make_pair(i, j));
            }
        }
    BFS();
    f(i, 0, n){
      printf("%d", cost[i][0]);
      f(j, 1, m)
          printf(" %d", cost[i][j]);
      puts("");    
    }
        
  }

  return 0;
}
