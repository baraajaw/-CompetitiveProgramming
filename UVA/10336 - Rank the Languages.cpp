#include <bits/stdc++.h>
using namespace std;
int n, m;
char src;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vector<string> g;
pair <int, char> frq[26];

bool comp ( pair <int , char> a , pair < int , char> b){
	return ( a.first > b.first || ( a.first == b.first && a.second < b.second));
}

void DFS( int x, int y){
    g[x][y] = '.';
   for ( int i = 0; i < 4; ++i){
	   int nx = x + dx[i];
	   int ny = y + dy[i];
	   if ( nx < n && nx >= 0 && ny < m && ny >= 0 && g[nx][ny] == src)
		    DFS(nx, ny);
	   
   }
}

int main() {
	int test;
	scanf("%d", &test);

	for(int num = 1; test-- != 0; ++num){
		scanf("%d%d", &n, &m);
		
		g.clear();
		g.resize(n);
		for(int i = 0; i < 26; ++i)
			frq[i].first = 0, frq[i].second = i + 'a';

		for(int i = 0; i < n; ++i)
			cin >> g[i];

		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m ; ++j)
				if(g[i][j] != '.'){
					src = g[i][j];
					DFS(i, j);
					frq[src - 'a'].first++;
				}
		sort(frq, frq + 26, comp);
		printf("World #%d\n", num);
		for(int i = 0; i < 26 && frq[i].first > 0; ++i)
			printf("%c: %d\n", frq[i].second, frq[i].first);

		


	}

    return 0;

}
