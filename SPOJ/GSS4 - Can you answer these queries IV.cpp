#include <bits/stdc++.h>
using namespace std;
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
int const N = 1e5 + 1;
int n, q, s, e, p[N];
ll a[N], seg[4*N]; 

int find(int u) {
  if(p[u] == u) return u;
  return p[u] = find(p[u]);
}
 

void build(int p, int l, int r){
  if(l == r){
    seg[p] = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(p*2, l, mid);
  build(p*2+1, mid+1, r);
  seg[p] = seg[p*2] + seg[p*2+1];
} 
ll get(int p, int l, int r, int a, int b) {
  if(r < a || l > b) return 0;
  if(a <= l && r <= b) return seg[p];
  int mid = (l + r) / 2;
  return get(p*2, l, mid, a, b) + get(p*2+1, mid+1, r, a, b);
}
void update(int p, int l, int r, int idx, ll val){
  if(l == r){
    a[idx] = val;
    seg[p] = val;
    return;
  }
  int mid = (l + r) / 2;
  if(idx <= mid)
    update(p*2, l, mid, idx, val);
  else
    update(p*2+1, mid+1, r, idx, val);
  seg[p] = seg[p*2] + seg[p*2+1];
}

int main(){
  int kase = 0; 
  while(scanf("%d", &n) != EOF){
    printf("Case #%d:\n", ++kase);
    f(i, 0, n)
      scanf("%lld", &a[i]);
    build(1, 0, n - 1);

    for(int i=0; i<n; ++i)
      p[i] = i;
    p[n] = n;

    scanf("%d", &q);
    while(q--){
      int type;
      scanf("%d%d%d", &type, &s, &e);
      if(s > e)
        swap(s, e);
      --s; --e;

      if(type == 0){
        ll val;
        for(int i = find(s); i <= e; i = find(i + 1)){
          val = sqrt(a[i]);
          update(1, 0, n - 1, i, val);
          if(val == 1)
            p[i] = find(i + 1);
        }
      }
      else{
        printf("%lld\n", get(1, 0, n - 1, s, e));
      }
    }
  }
 
  return 0;       
}
    
