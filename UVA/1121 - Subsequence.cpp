#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int const N = 1e5 + 10;
int  main() {

  int n, s, a[N];
  while (scanf("%d%d", &n, &s) == 2){
    int sum = 0, ans = n + 1;

    for (int i = 0; i < n; ++i){
      scanf("%d", &a[i]);
      sum += a[i];
    }

    if(sum < s)
        ans = 0;
    sum = 0;  
    int l = 0, r = 0;
    
    while (r < n){
        sum += a[r];
        r++;
        while (sum >= s && l <= r ){
          sum -= a[l];
          ans = min (ans, r - l);
          l++;
        }
    }
    ans = min(ans, r - l + 1  );
    printf("%d\n", ans);
}



  return 0;
}
 
