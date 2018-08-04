#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
int n, a, b, c, dp[90]; 
vector < pair < pair < int, int >, int > > v;
int main() {
  while (scanf("%d", &n) && n){
    v.clear();
    // read input 
    f(i, 0, n){
       vector <int> p(3);
       scanf("%d%d%d", &p[0], &p[1], &p[2]);
       sort(p.begin(), p.end());
       do{
        v.push_back(make_pair(make_pair(p[0], p[1]), p[2]));
       }while (next_permutation(p.begin(), p.end()));
    } // end of loop 
    sort(v.begin(), v.end());
    int  ans = -1;
    f(i, 0, v.size()){
     dp[i] = v[i].second;
      f(j, 0, i)
          if ( (v[j].first.first <v[i].first.first && v[j].first.second <v[i].first.second))
              dp[i]= max (dp[i], dp[j] + v[i].second);
      ans = max (ans, dp[i]);      
    }
    cout << ans << endl;                

  }
  return 0;
}
