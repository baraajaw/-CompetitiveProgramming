#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
int can(int a,int b){
  if(!b)
    return 0;
  if(a/b > 1)
    return 1;
  return can(b,a-b)+1;
}
int main() {
  int a, b;
  while(scanf("%d%d", &a, &b) && a && b){
    if( a == b){
      puts("Stan wins");
      continue;
    }
    if(a < b) swap(a, b);
    if(can(a, b) % 2 != 0)
      puts("Stan wins");
    else
      puts("Ollie wins");

  }
      

  return 0;
}
