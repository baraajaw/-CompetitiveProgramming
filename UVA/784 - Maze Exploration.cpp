#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
string s;
vector<string> g;

void DFS(int x , int y ){
    g[x][y] = '#';
    for ( int i = 0 ; i < 8 ; ++i ){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < g.size() && nx >= 0 && ny >= 0  && ny < g[x].size()&& g[nx][ny] ==' ')
      	DFS( nx , ny );
    }
}
int main() {
	int test;
	scanf("%d\n", &test);

	while(test--){
		g.clear();
		while(getline(cin, s) && s[0] != '_')
			g.push_back(s);
		
		for ( int i = 0 ; i < g.size() ; ++i)
     		for ( int j = 0 ; j < g[i].size() ; ++j)
        		if ( g[i][j] == '*')
           			DFS( i , j);
		for ( int i = 0 ; i < g.size() ; ++i)
     		cout<< g[i]<<endl;
  		cout<<s<<endl;
	}

    return 0;

}
