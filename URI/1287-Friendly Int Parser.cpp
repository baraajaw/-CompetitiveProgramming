#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
string s;
ll x = 0;
bool o, c, v;

int main() {
  while(getline (cin, s)){
       o = v = c = true;
       x = 0;
       replace( s.begin(), s.end(), 'o', '0');
       replace( s.begin(), s.end(), 'O', '0');
       replace( s.begin(), s.end(), 'l', '1');
       s.erase(std::remove(s.begin(), s.end(), ','), s.end());
       s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
       f(i, 0, s.size())
            if (s[i] != '0')
                o = false;
       f(i, 0, s.size()){
            x = x * 10 + (s[i] - '0');
            if (x > 2147483647) v = false;
       }
       f(i, 0, s.size())
            if (!isdigit(s[i]))
                c = false;  
       if ( !c || !v || s.size() < 1) puts("error");
       else if (o) puts("0");
       else printf("%lld\n", x );     
  }

  return 0;
}
