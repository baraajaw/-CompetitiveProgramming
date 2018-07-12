#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#define ll long long 
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)
using namespace std;

int main() {
  int x,y, t = 0;
  pair< int, int > dp[1001];
  vector < pair < int, pair < int, int > > > v;
  vector < int > vc;
  while ( cin >> x >> y)
      v.push_back(make_pair(x,make_pair(y, t++)));
  sort(v.begin(),v.end());
  
   f (i, 0, v.size())
        dp[i].first = 1;
   f (i, 1, v.size())
    f(j, 0, i) 
      if ( v[i].second.first < v[j].second.first && dp[i].first < dp[j].first + 1){
          dp[i].first = dp[j].first + 1;
          dp[i].second = j;
      }
  int ans = 0, ind = 0;
  f(i, 0, v.size())
    if (ans < dp[i].first){
      ans = dp[i].first;
      ind = i;
  }
   printf("%d\n", ans );
  f(i, 0, ans){
    vc.push_back(v[ind].second.second);
    ind = dp[ind].second;
  }
  reverse(vc.begin(), vc.end());
  f(i, 0, vc.size())
    printf("%d\n", vc[i] + 1 );
  
  return 0;
}
