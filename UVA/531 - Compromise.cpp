#include <bits/stdc++.h>
#define ll long long 
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)
using namespace std;
char s[400];
string c = "";
int dp[101][101];
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
void path ( int i, int j){
   if ( i == x.size() || j == y.size())
      return ;
   if ( x[i] == y[j]){ 
    ans.push_back(x[i]);
    path (i + 1, j + 1);
    return;
   }
   int a = cal (i + 1, j);
   int b = cal ( i, j + 1);
   if ( a > b)
        path ( i + 1, j);
   else
        path (i, j + 1);      
}
int main() {
  while ( gets(s) > 0){
    x.clear();
    y.clear();
    do {
      int len = strlen (s);
      c = "";
      f(i, 0, len){
        if ( s[i] == ' '){
          x.push_back(c);
          c = "";
        }
        else
          c += s[i];
      }
      if ( c != "") x.push_back(c);
    } while (gets(s) && s[0] != '#');
    while (gets(s) && s[0] != '#'){
      int len = strlen (s);
      c = "";
      f(i, 0, len){
        if ( s[i] == ' '){
          y.push_back(c);
          c = "";
        }
        else
          c += s[i];
      }
      if ( c != "") y.push_back(c);
    }  
    memset(dp, -1, sizeof dp);
    cal (0, 0);
    path (0, 0);
    f(i, 0, ans.size()){
      printf("%s", ans[i].c_str());
      if ( i + 1 < ans.size())
        printf(" ");
    }
    puts("");
    ans.clear();
  }
  
  return 0;
}
