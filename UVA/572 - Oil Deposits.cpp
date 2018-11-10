#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
string g[101];

void DFS(int i, int j){
	g[i][j] = '*';
	for(int k = 0; k < 8; ++k){
		int nx = dx[k] + i;
		int ny = dy[k] + j;
		if(nx < n && nx >= 0 && ny < m && ny >= 0 && g[nx][ny] == '@')
			DFS(nx, ny);
	}
}
int main() {
	while (scanf("%d%d", &n, &m) && n != 0 && m !=0){
		ans = 0;

		for (int i = 0; i < n; ++i)
			cin >> g[i];

		for (int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				if(g[i][j] == '@'){
					ans++;
					DFS(i, j);
				}
		printf("%d\n", ans);
	}

    return 0;

}
