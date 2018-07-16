#include <bits.stdc++.h>
#define ll long long 
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)
using namespace std;
map < int, int> dp;
vector < int > v, res;
int x, t= 1;
bool ok = false;
int main() {
  while ( scanf("%d", &x) && x != -1){
    if (ok) puts("");
    ok = true;
    v.clear();
    v.push_back(x);
    while ( scanf("%d", &x) && x != -1)
        v.push_back(x);

  reverse (v.begin(), v.end());    
  f (i, 0, v.size())
        dp[i]= 1;
  f(i, 0, v.size())
      f(j, 0, i)
        if ( v[i] >= v[j] && dp[i] < dp[j] + 1)
            dp[i]= dp[j] + 1;
  int ans = 0;
  f(i, 0, v.size())
    if (ans < dp[i])
      ans = dp[i];
  printf("Test #%d:\n", t++ );
  printf("  maximum possible interceptions: %d\n", ans );        
  
  } 

  return 0;
}
