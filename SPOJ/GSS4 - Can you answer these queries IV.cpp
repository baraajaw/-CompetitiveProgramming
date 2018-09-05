#include <bits/stdc++.h>
using namespace std;
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
int const N = 1e5 + 1;
int n, q;
ll  a[N], seg[4*N];

void build(int p, int l, int r) {
  if(l == r) {
    seg[p] = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(p*2, l, mid);
  build(p*2+1, mid+1, r);
  seg[p] = seg[p*2] + seg[p*2+1];
}
void update(int p, int l, int r, int x, int y){
	if(r < x || l > y) return;
	if(l == r) {
    	seg[p] = a[l] = sqrt(a[l]);
    	return;
  	}
	if(seg[p] == r - l + 1) return;
	int mid = (l + r) /2;
	update(p*2, l, mid, x, y);
	update(p*2+1, mid+1, r, x, y);
  	seg[p] = seg[p*2] + seg[p*2+1];
}
long long get(int p, int l, int r, int a, int b) {
  if(b < l || a > r)
    return 0;
  
  if(l >= a && r <= b)
    return seg[p];
  
  int mid = (l + r) / 2;
  return get(p*2, l, mid, a, b) + get(p*2+1, mid+1, r, a, b);
}
int main(){
	int t = 1, type, x, y;
	while(scanf("%d", &n) == 1){
		f(i, 1, n+1) scanf("%lld", &a[i]);
		build(1, 1, n);	
		scanf("%d", &q);
		printf("Case #%d:\n", t++);
		while(q-- != 0) {
      		scanf("%d %d %d", &type, &x, &y);
      
     		 if(x > y)
        		swap(x, y);
      
     	 if(type == 0)
        	update(1, 1, n, x, y);
     	 else
        	printf("%lld\n", get(1, 1, n, x, y));
    	}
    	puts("");


	}



	return 0;				
}
