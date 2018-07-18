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
#include <sstream>
#define ll long long 
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)
using namespace std;
int n, res = 0, mx = 0;
char s[100001];
map < int , int > mp;
string a, b;
int main() {
 scanf("%d", &n);
 scanf("%s", s); a = s;
 scanf("%s", s); b = s;
 f(i, 0, n / 2 ){
    mp[a[i]]++;
    mp[b[i]]++;
    mp[a[n - 1 - i]]++;
    mp[b[n - 1 - i]]++; 
    for ( auto it = mp.begin(); it != mp.end(); it++)
            mx = max ( mx, it ->second);
    if (mp.size() == 2 && mx == 3) res++;    
    else if (mp.size() == 3){
      if (a[i] == a[n - 1 - i]) ++res;  
      ++res;
    }
    else if (mp.size() == 4) res += 2;
    mp.clear();
    mx = 0;

 }
 if ( n % 2 == 1  && a[n / 2] != b[n/2]) ++res;

 printf("%d\n", res);

  return 0;
}
