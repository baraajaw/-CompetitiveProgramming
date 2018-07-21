#include <bits/stdc++.h>
#define ll long long 
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)
using namespace std;

int main() {
  int t, m, n;
  int x[1001], y[1001];

  scanf("%d", &t);
  while(t--){
    scanf("%d%d", &n, &m);
    --n; --m;
    int s1 = 0, s2 = 0, ans = 0;
    f(i, 0, n){
       scanf("%d", x + i);
       s1 += x[i];
    }
    f(i, 0, m){
      scanf("%d", y + i);
      s2 += y[i];
    } 
    ans = s1 + s2;
    sort(x, x + n);
    sort(y, y + m);
    for ( int i = n - 1 , j = m - 1 ; i >= 0 && j >= 0; ){
        if (y[j] >= x[i]){
          ans += s1;
          s2 -= y[j];
          --j;
        }
        else{
          ans += s2;
          s1 -= x[i];
          --i;
        }
    }
    printf("%d\n", ans  );  
  }



  return 0;
}
