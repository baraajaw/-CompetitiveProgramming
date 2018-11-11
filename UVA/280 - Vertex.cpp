#include <bits/stdc++.h>
using namespace std;
int v, a, b, c;
vector<vector<int> > g;
vector<int> res;
bool vis[101];

void DFS(int src){
	for(int i = 0; i < g[src].size(); i++)
		if(!vis[g[src][i]]) {
	        vis[g[src][i]] = true;
	        DFS(g[src][i]);
	    }

}
int main() {
	while(scanf("%d", &v) == 1 && v){

		g.clear();
		g.resize(v);

		while(scanf("%d", &a) && a)
			while(scanf("%d", &b) && b)
				g[a - 1].push_back(b - 1);
			
		scanf("%d", &a);
		while(a--){
			res.clear();
			scanf("%d", &b);
			memset(vis, false, sizeof vis);
			DFS(--b);

			c = 0;
			for(int i = 0; i < v; ++i)
				if(!vis[i]) {
                    c++;
                    res.push_back(i+1);
                }
            printf("%d", c);
            for(int i = 0; i < res.size(); i++)
                printf(" %d", res[i]);
            putchar('\n');
		}

	}

    return 0;

}
