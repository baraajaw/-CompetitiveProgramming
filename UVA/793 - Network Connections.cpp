#include <bits/stdc++.h>
#define ll long long 
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)
using namespace std;
int t, n, x, y, z, w, su= 0, uns = 0;
map < int, int > ds, rankt;
string s, tmp;
int find(int x) {
    if(ds[x] == x)
        return x;
    return ds[x] = find(ds[x]);
}
int main() {
 scanf("%d", &t);
  cin.ignore();
  getline(cin, s);
 while (t--){
  scanf("%d", &n);
  cin.ignore();
  f(i, 0, n)
      ds[i] = i;
  while(getline (cin, s) && s != "") {
    x = y = 0;
    z = s.find(' ');
    w = s.find (' ', z + 1);
    tmp = s.substr(z + 1, w - (z + 1));
    f(i, 0,tmp.size()) x = x * 10 + (tmp[i] - '0');
    tmp = s.substr(w + 1);
    f(i, 0, tmp.size()) y = y * 10 + (tmp[i] - '0');
    x--; y--;
    int a = find(x) , b = find(y);
    if ( s[0] == 'c'){
      ds[a] = b;
    }// end of c if 
    else {
      if (a == b) su++;
      else uns++;
    }// end of else

  }// while get line    
  printf("%d,%d\n", su, uns);
  if (t)
      puts(""); 
  su = uns =0;  
 }
 



  return 0;
}
