#include<iostream>
#include<vector>
#include<stdio.h>
#include<queue>
#include<memory.h>
using namespace std;

int const N = 1000;
int const M = 2 * 1e9 + 1;
int dx[] = { -1 , 0 , 1 , 0 };
int dy[] = { 0 , 1 , 0 , -1};
int  n , m ;
int board[N][N];
int cost[N][N];
bool vis[N][N];
priority_queue<pair < int , pair < int , int > > > q;

void Dijkstra()
{
  pair < int , int > v;
  int c ;
  cost[0][0] = board[0][0];
   q.push(make_pair(-cost[0][0], make_pair(0, 0)));
   
  while ( !q.empty())
  {
    v = q.top().second;
    c = -q.top().first;
     q.pop();
    vis[0][0] = true;
    for ( int i = 0 ; i < 4 ; ++i)
      {
        int nx = dx[i] + v.first;
        int ny = dy[i] + v.second;
        if ( nx >= 0 && nx < n && ny >= 0 && ny < m )
        {
           vis[nx][ny] = true;
           
           if(c + board[nx][ny] < cost[nx][ny]) {
                    cost[nx][ny] = c + board[nx][ny];
                    q.push(make_pair(-cost[nx][ny], make_pair(nx, ny)));
                }
        }
      }
  }


}
int main()
{
  int t;
  scanf ("%d" , &t);
  while ( t--)
  {
    scanf ("%d%d" , &n , &m);
    while (!q.empty()) q.pop();
    
     for(int i = 0; i < n; i++)
       for(int j = 0; j < m; j++)
              cost[i][j] = M;
     memset(vis, false, sizeof vis);
     
     for ( int i = 0 ; i < n ; ++i)
       for ( int j = 0 ; j < m ; ++j)
          scanf ("%d" , &board[i][j]);
  Dijkstra();      
    printf ("%d\n" , cost[n - 1 ][m - 1]);
  }

return 0;
}
