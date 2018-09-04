#include <bits/stdc++.h>
using namespace std;
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long

int const N = 1e5 + 1;
int n, c, a[N], val;
ll seg[N*4], lazy[N*4];
void build(int p, int l, int r) {
  if(l == r) {
    seg[p] = 0;
    return;
  }
  int mid = (l + r) / 2;
  build(p*2, l, mid);
  build(p*2+1, mid+1, r);
  seg[p] = seg[p*2] + seg[p*2+1];
}
void pro(int idx, int l, int r) {
  seg[idx] += lazy[idx] * (r - l + 1);
  if(l != r){
    lazy[idx * 2] += lazy[idx];
    lazy[idx * 2 + 1] += lazy[idx];
  }
  lazy[idx] = 0;
}

void update (int p, int l, int r, int a, int b, int val){
	if(lazy[p] != 0)
		pro(p, l, r);

	if (r < a || l > b) return;
	if (a <= l && r <= b){
		lazy[p] += val;
		pro(p, l, r);
		return;
	}
	int mid = (l+r)/2;
	update(p*2, l, mid, a, b, val);
	update(p*2+1, mid+1, r, a, b, val);
	seg[p] = seg[p*2] + seg[p*2+1];
}
ll  get(int p, int l, int r, int a, int b) {
 if(lazy[p] != 0)
      pro(p, l, r);
  if(r < a || l > b) return 0;
  if(a <= l && r <= b) return seg[p];
  int mid = (l+r)/2;
  return get(p*2, l, mid, a, b) + get(p*2+1, mid+1, r, a, b);
}


int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &c);

		memset(seg, 0, sizeof seg);
   		memset(lazy, 0, sizeof lazy);  
		build(1, 1, n);
		
		
		while(c--){
			int type, x, y;
			scanf("%d%d%d", &type, &x, &y);
			if(type == 0){
				scanf("%d", &val);
				update(1, 1, n, x, y, val);
			}
			else 
				printf("%lld\n", get(1, 1, n, x, y));
			
		}// c-- while 

	}// t-- while 


	return 0;				
		
	
}
