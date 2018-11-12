#include <bits/stdc++.h>
using namespace std;
int n, m, ans , cnt;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
string g[110];

void DFS(int i, int j){
	g[i][j] = '.';
	cnt++;
	for (int k = 0; k < 8; ++k){
		int nx = dx[k] + i;
		int ny = dy[k] + j;
		if (nx < n && nx >= 0 && ny < m && ny >= 0 && g[nx][ny] == '*')
			DFS(nx, ny);
	}
}
int main() {
	while (scanf("%d%d", &n, &m) && n && m){

		for (int i = 0; i < n; ++i)
			cin>> g[i];

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (g[i][j] == '*'){
					cnt = 0;
					DFS(i, j);
					if(cnt == 1)
					ans++;
				}
		printf("%d\n", ans);
		ans = 0;
	}

    return 0;

}
