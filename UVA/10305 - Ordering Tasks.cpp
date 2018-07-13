#include <bits/stdc++.h>
#define ll long long 
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)
using namespace std;
int n, m;
queue < int > q;
vector < vector < int > > g;
vector < int > ans;
map < int, int > in;
int main() {
  while ( scanf("%d%d", &n, &m) ){
      if ( n == 0 ) break;
      g.clear();
      g.resize(n);
      ans.clear();
      in.clear();

      f(i, 0, m){
          int a, b;
          scanf("%d%d", &a, &b);
          a--; b--;
          g[a].push_back(b);
          in[b]++;
      }
       for(int i = 0; i < n; i++)
            if(in[i] == 0)
                q.push(i);
      while(!q.empty()) {
          int fr = q.front();
          q.pop();
          ans.push_back(fr + 1);
            
          f(i, 0, g[fr].size())
              if(--in[g[fr][i]] == 0)
                    q.push(g[fr][i]);
        }
      f(i, 0, ans.size()){
        printf("%d",ans[i]);
          if ( i + 1 < ans.size())
            printf(" ");
      }
      puts("");    
  }
  
  return 0;
}
