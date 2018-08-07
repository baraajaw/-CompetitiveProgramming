#include <bits/stdc++.>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
int n, k, dp[1 << 12][100];
int get(int mask, int d){
  int res = 0;
  f(i, 0, n)
    if (((mask >> i) & 1) == 1 && i != d && i > d)
      ++res;
  return res;
}
int cal(int mask, int cnt){
  if (mask == (1 << n) - 1 && cnt == k)
      return 1;
  if (cnt > k)
      return 0;
  int &res = dp[mask][cnt];
  if(res != -1)
      return res;
  
  res =0;
  f(i, 0, n)
      if((( mask >> i) & 1) == 0 )
        res += cal((mask | ( 1 << i)), cnt + get(mask, i));
  return res;    
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%d%d", &n, &k);
    memset(dp, -1, sizeof dp);
    printf("%d\n", cal(0, 0));
 
  }
 
  return 0;
}
