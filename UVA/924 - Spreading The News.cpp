#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
int e, level[2501];
vector < vector < int> > g;
map < int , int > mp;
bool vis[2501];
queue<int> qu;

pair < int,int >  BFS(int src) {
  memset(vis, false, sizeof vis);
  memset(level, 0, sizeof level);
  mp.clear();
  pair < int , int > p;
  p.first = p.second = 0;
  
  qu.push(src);
  vis[src] = true;
  
  while(!qu.empty()) {
    int fr = qu.front();
    qu.pop();
    
    for(int i = 0; i < (int)g[fr].size(); ++i) {
      int u = g[fr][i];
      if(!vis[u]) {
        qu.push(u);
        vis[u] = true;
        level[u] = level[fr] + 1;
      }
    }
  }
  f(i, 0, e)
    if(vis[i])
      mp[level[i]]++;
  mp[level[src]]--;  
  for ( auto it = mp.begin(); it != mp.end(); ++it)
      if ( it -> second > p.first)
          p.first = it -> second, p.second = it-> first;
  return p ;      

}

int main() {
  int a, n;
  while ( scanf("%d", &e) == 1){
  g.clear();  
  g.resize(e);
  f(i, 0, e){
    scanf("%d", &n);
    f(j, 0, n){
      scanf("%d", &a);
      g[i].push_back(a);
    }
  }
  scanf("%d", &n);
  f(i, 0, n){
    scanf ("%d", &a);
    pair < int , int > p = BFS(a);
    if ( p.first > 0)
      printf("%d %d\n", p.first, p.second);
    else
      puts("0");
  }



 }
  return 0;
  
}
