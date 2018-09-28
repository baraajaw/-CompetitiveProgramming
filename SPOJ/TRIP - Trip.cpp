#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int const N = 100;
int n, m, dp[N][N];
char a[N], b[N], ans[N];
vector <int> nxt1[26], nxt2[26]; 
 
int cal(int i, int j){
  if(i == n || j == m)
    return 0;
  if(dp[i][j] != -1)
    return dp[i][j];
  if(a[i] == b[j])
    return dp[i][j] = cal(i + 1, j + 1) + 1;
  int x = cal(i + 1, j);
  int y = cal(i, j + 1);
 
  return dp[i][j] = max(x,y);
}
void path(int i, int j, int idx){
  if(idx == cal(0, 0)){
    printf("%s\n", ans);
    return;
  }
  for (int k = 0; k < 26; ++k){
    int u = lower_bound(nxt1[k].begin(), nxt1[k].end(), i) - nxt1[k].begin();
    int v = lower_bound(nxt2[k].begin(), nxt2[k].end(), j) - nxt2[k].begin();
    if(u == nxt1[k].size() || v == nxt2[k].size() ||  cal(0, 0) - idx != cal(nxt1[k][u] + 1, nxt2[k][v] + 1) + 1)
      continue;
    ans[idx] = char(k + 'a');
    path(nxt1[k][u] + 1, nxt2[k][v] + 1, idx + 1);
  }
}
int  main() {
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%s%s", a, b);
    n = strlen(a);
    m = strlen(b);
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < 26; ++i)
      nxt1[i].clear(), nxt2[i].clear();
    for (int i = 0; i < n; ++i)
      nxt1[a[i] - 'a'].push_back(i);
    for (int i = 0; i < m; ++i)
      nxt2[b[i] - 'a'].push_back(i);
    ans[cal(0, 0)] = '\0';
    path(0, 0, 0);
  }
 
 
 
  return 0;
} 
