#include <bits/stdc++.h>
using namespace std;
int n, m, cnt ;
char src;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
string g[55];
vector<pair<int, char> > ans;

bool check (pair<int, char> a, pair<int, char> b){
	return (a.first > b.first) || ( a.first == b.first && a.second < b.second);
}

void DFS(int i, int j){
	g[i][j] = '.';
	cnt++;
	for (int k = 0; k < 4; ++k){
		int nx = dx[k] + i;
		int ny = dy[k] + j;
		if (nx < n && nx >= 0 && ny < m && ny >= 0 && g[nx][ny] == src)
			DFS(nx, ny);
	}
}

int main() {
	int testnum = 1;

	while (scanf("%d%d", &n, &m) && n && m){
		ans.clear();

		for (int i = 0; i < n; ++i)
			cin>> g[i];

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (g[i][j] != '.'){
					cnt = 0, src = g[i][j];
					DFS(i, j);
					ans.push_back(make_pair(cnt, src));
				}
		sort(ans.begin(), ans.end(), check);		
		printf("Problem %d:\n", testnum++);
		for(int i = 0; i < ans.size(); ++i)
			printf("%c %d\n", ans[i].second, ans[i].first);
	}

    return 0;

}
