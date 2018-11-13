#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
bool vis[26];

void DFS(int node){
	vis[node] = true;
    for (int i = 0; i < g[node].size(); ++i)
    	if(!vis[g[node][i]])
      		DFS(g[node][i]);
    
}
int main() {
	int t;
	scanf("%d\n", &t);

	while (t--){
		g.clear();
		memset(vis, false, sizeof vis);

		char tmp;
		scanf(" %c", &tmp);
		int end = tmp - 'A' + 1; 
		g.resize(end);

		for (int i = 0; i < end; i++) g[i].push_back(i);

		string s;
		cin.ignore();
		while (getline(cin, s) && s != "") {
			int a = s[0] - 'A';
			int b = s[1] - 'A';
			g[a].push_back(b);
			g[b].push_back(a);
		}

		int ans = 0;
		for (int i = 0; i < g.size(); ++i)
			for (int j = 0; j < g[i].size(); ++j)
				if (!vis[g[i][j]]) {
					ans++;
					DFS(g[i][j]);
				}
		printf("%d\n", ans);
		if(t)	puts("");

	}

    return 0;

}
