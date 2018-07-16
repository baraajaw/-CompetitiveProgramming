#include <bits/stdc++.h>
#define ll long long 
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)
using namespace std;
vector < int > v, res;
int n, l, r, a[10001], lis[10001], lds[10001], tmp[10001] ;
int main() {
  int inf, Maxlis, Maxlds;
 
  while ( scanf("%d", &n) == 1){
      f(i, 0, n) 
        scanf("%d", &a[i]);
        
      f(i, 0, n)  tmp[i] = inf;
      tmp[0] = -inf;
      Maxlis = 0;
       // this part is to find LIS O(nlogn)
      f(i, 0, n){
        l =0, r = Maxlis;
        while ( l <= r) {
          int mid = ( l + r) / 2;
          if (a[i] > tmp[mid])
             l = mid + 1;
          else
            r = mid - 1;
        }
        tmp[l] = a[i];
        lis[i] = l;
        Maxlis = max (l, Maxlis);
      }

      f(i, 0, n)  tmp[i] = inf;
      tmp[0] = -inf;  
      reverse(a, a+ n);
      Maxlds = 0;
        // this part is to find LDS O(nlogn)
      f(i, 0, n){
        l =0, r = Maxlds;
        while ( l <= r) {
          int mid = ( l + r) / 2;
          if (a[i] > tmp[mid])
             l = mid + 1;
          else
            r = mid - 1;
        }
        tmp[l] = a[i];
        lds[i] = l;
        Maxlds = max (l, Maxlds);
      }
      reverse (lds, lds + n);
      
      int ans = 1;
      l = 0, r = n -1;
      while ( l <= r){
        if ( lis[l] == lds[r]){
            ans = max (ans, lis[l]);
            l++; r--;
        }
        else if (lis[l] < lds[r]) 
          l++;
        else
          r--;
      }
      printf("%d\n", 2 * ans -1 );
  }
       
  
  

  return 0;
}
