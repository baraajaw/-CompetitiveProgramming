#include <bits/stdc++.h>
#define ll long long 
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)
using namespace std;
string a, b, c;
int dp[1001][1001];
vector < string > ans, x, y;
int cal ( int i, int j){
  if ( i == x.size() || j == y.size())
    return 0;
  int & ret = dp[i][j];
  if ( ret != -1) 
    return ret;
  ret = 0 ;
  if ( x[i] == y[j]) 
      return ret = cal (i+ 1, j + 1)+ 1;
  ret = max ( ret, cal (i + 1, j));
  ret = max ( ret, cal (i, j + 1));
  return ret;
}

int main() {
  int t = 1;
  while (getline (cin, a) && getline(cin, b)){
      x.clear();
      y.clear();
      c = "";
      f(i, 0, a.size()) if ( !isalpha (a[i]) && !isdigit(a[i])) a[i] = ' ';
      f(i, 0, b.size()) if ( !isalpha (b[i]) && !isdigit(b[i])) b[i] = ' ';
      stringstream aa(a);
      stringstream bb(b);
      while (aa >> c)
          x.push_back(c);
      c.clear();
      while( bb >> c)
          y.push_back(c);
      if ( x.empty() || y.empty()){
         printf("%2d. Blank!\n", t++);
         continue;
      }
      memset(dp, -1, sizeof dp);
      printf("%2d. Length of longest match: %d\n", t++, cal (0, 0));

  }
  return 0;
}
