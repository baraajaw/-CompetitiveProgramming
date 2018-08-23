#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
int const N = 1e4 + 1, MAX = 1e6 + 1;
int n, q, a[N], seg[4 * N], lazy[4 * N];
bitset<MAX> prime;
void sieve() {
  prime.set();
  prime[0] = prime[1] = 0;
  for(int i = 2; i * i < MAX; ++i)
    if(prime[i])
      for(int j = i * i; j < MAX; j += i)
        prime[j] = 0;
}

void build(int p, int l, int r) {
  if(l == r) {
    seg[p] = prime[a[l]];
    return;
  }
  int mid = (l + r) / 2;
  build(p*2, l, mid);
  build(p*2+1, mid+1, r);
  seg[p] = seg[p*2] + seg[p*2+1];
}
void pro(int idx, int l, int r) {
  seg[idx] = prime[lazy[idx]] * (r - l + 1);
  if(l != r)
    lazy[idx * 2] = lazy[idx * 2 + 1] = lazy[idx];
  lazy[idx] = 0;
}

void update(int p, int l, int r, int a, int b, int val) {
  if(lazy[p] != 0)
      pro(p, l, r);

  if(r < a || l > b) return;
  if(a <= l && r <= b) {
    lazy[p] = val;
    pro(p, l, r);
    return;
  }
  int mid = (l+r)/2;
  update(p*2, l, mid, a, b, val);
  update(p*2+1, mid+1, r, a, b, val);
  seg[p] = seg[p*2] + seg[p*2+1];
}

int  get(int p, int l, int r, int a, int b) {
 if(lazy[p] != 0)
      pro(p, l, r);
  if(r < a || l > b) return 0;
  if(a <= l && r <= b) return seg[p];
  int mid = (l+r)/2;
  return get(p*2, l, mid, a, b) + get(p*2+1, mid+1, r, a, b);
}

int main() {
  sieve();

  int t, x, y, type, val, tt = 1;
  scanf("%d", &t);  
  while(t--){
    printf("Case %d:\n", tt++);
    scanf("%d%d", &n, &q);
    f(i, 1, n + 1)  
      scanf("%d", &a[i]);

    memset(seg, 0, sizeof seg);
    memset(lazy, 0, sizeof lazy);  
    build(1, 1, n);
    while(q--){
        scanf("%d%d%d", &type, &x, &y);
        if(type == 0){
          scanf("%d", &val);
          update(1, 1, n, x, y, val);
        }
        else
          printf("%d\n", get(1, 1, n, x, y));
    }  
  }    

  return 0;
}
