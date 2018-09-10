#include <bits/stdc++.h>
using namespace std;
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
int const N = 31;
int L, R, C;
bool vis[N][N][N];
int cost[N][N][N];
char g[N][N][N];
int dx[] = {-1, 0, 1, 0, 0, 0};
int	dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1}; 
int BFS(int z, int x, int y){
	queue<pair < int, pair < int, int > > > qu;
	memset(vis, false, sizeof vis);
	vis[z][x][y] = true;
	cost[z][x][y] = 0;
	qu.push(make_pair(z, make_pair(x,y)));
	while(!qu.empty()){
		int zz = qu.front().first, xx = qu.front().second.first, yy = qu.front().second.second;
		qu.pop();
		f(i, 0, 6){
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			int nz = zz + dz[i];
			if(nx >= 0 && ny >= 0 && nz >= 0 && nx < R && ny < C && nz < L && !vis[nz][nx][ny] && g[nz][nx][ny] != '#'){
				qu.push(make_pair(nz, make_pair(nx, ny)));
				vis[nz][nx][ny] = true;
				cost[nz][nx][ny] = cost[zz][xx][yy] + 1;
				if(g[nz][nx][ny] == 'E')
						return cost[nz][nx][ny];
			}// end of f 
		}// end of loop;
	}// end of while 
	return -1;
}
int  main() {
	
	while (scanf("%d%d%d", &L, &R, &C) && L){
		f(i, 0, L)
			f(j, 0, R)
					scanf(" %s", g[i][j]);
		int res = 0;
		f(i, 0, L)
			f(j, 0, R)
				f(k, 0, C)
					if(g[i][j][k] == 'S'){
						res = BFS(i, j, k);
						break;
					}
		if(res == -1)
			puts("Trapped!");
		else
			printf("Escaped in %d minute(s).\n", res);
	}


	return 0;
}
