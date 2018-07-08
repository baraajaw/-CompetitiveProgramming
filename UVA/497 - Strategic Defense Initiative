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
#include <time.h>
#include <sstream>
#include <bitset>
#define ll long long 
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)
using namespace std;
int const N = 1001;
int t, n;
pair< int, int > dp[N];
string s;
vector < int > v, a;
int main() {

scanf("%d", &t);
cin.ignore();
cin.ignore();
while ( t--){ 
  n = 0;
  v.clear();
  a.clear();
  while ( getline(cin, s) && s != "" ) {
    int x ;
    stringstream ss(s);
    ss >> x;  
    a.push_back(x); 
  }
  n = a.size();
  f (i, 0, n)
        dp[i].first = 1;
  f (i, 1, n)
    f(j, 0, i) 
      if ( a[i] > a[j] && dp[i].first < dp[j].first + 1){
          dp[i].first = dp[j].first + 1;
          dp[i].second = j;
      }
  int ans = 0, ind = 0;
  f(i, 0, n)
    if (ans < dp[i].first){
      ans = dp[i].first;
      ind = i;
    }
  printf("Max hits: %d\n", ans );
  f(i, 0, ans){
    v.push_back(a[ind]);
    ind = dp[ind].second;
  }
  reverse(v.begin(), v.end());
  f(i, 0, v.size())
    printf("%d\n", v[i] );
  if ( t)  
  puts("");

}
 
  return 0;
}
