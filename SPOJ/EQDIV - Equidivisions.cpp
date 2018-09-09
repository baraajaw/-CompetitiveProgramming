#include <bits/stdc++.h>
using namespace std;
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
int n, a, b, cnt = 0;
bool f = true;
char buff[101*101];
int g[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void DFS(int x, int y, int src){
	g[x][y] = n + 1;
	for (int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n && g[nx][ny] == src) {
			DFS(nx, ny, src);
			cnt++;
		}
	}
}
int main() {
	
	while(scanf("%d", &n) && n != 0){
		f = true;
		f(i, 0, n)	f(j, 0, n) g[i][j] = 0;

		getchar();
		int k = 1;
		for(int i=0; i<n-1; i++){
			gets(buff);
			stringstream ss(buff);
			for(int j=1; j<=n; j++){
				ss >> a >> b;
				g[a-1][b-1] = k;
			}
			k++;
		}
		f(i, 0, n)	f(j, 0, n)	if(g[i][j] == 0) g[i][j] = n;	
		//f(i, 0, n){	f(j, 0, n)	cout << g[i][j]<<" "; cout << endl;}
		// check 
		f(i, 0, n){
			f(j, 0, n)
				if(g[i][j] != n + 1){
					cnt++;
					DFS(i, j, g[i][j]);
					if(cnt != n){	puts("wrong");	f = false;	cnt = 0; break;}	
					cnt = 0;
				}


			if(!f) break;	
		}
		// end of check
		if(f)	puts("good");

	}


return 0;
}
