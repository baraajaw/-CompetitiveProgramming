#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int n, m;
vector < vector < int > > g;
vector <int > in, sol; 
priority_queue<int> qu;
int  main() {

  scanf("%d%d", &n, &m);
  g.resize(n);
  in.resize(n);

  for (int i = 0, a, b, t; i < m; ++i){
    scanf("%d%d", &b, &t);
    --b;
    while (t--){
      scanf("%d", &a);
      --a;
      g[a].push_back(b);
      ++in[b];
    }
  }
  for (int i = 0; i < n; ++i)
    if(in[i] == 0)
      qu.push(-i);
 
  while (!qu.empty()){
    int v = -qu.top();
    qu.pop();
    sol.push_back(v + 1);
    for (int i = 0; i < g[v].size(); ++i){
      int u = g[v][i];
      if(--in[u] == 0)
        qu.push(-u);
    }
  }
  for(int i = 0; i < sol.size(); ++i)
    printf("%d ", sol[i]);
  puts("");

  
  return 0;
}
 
