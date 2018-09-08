#include <bits/stdc++.h>
using namespace std;
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
int const N = 250 * 250 + 10;
int tot, n, m, val, t[N], lis[N];
int pos[N];
vector < int> v;
int main() {
    freopen ("in" , "r" , stdin);
    int t1, tt = 1;
    scanf("%d", &t1);
    while(t1--){
    	v.clear();
    	f(i, 0, N) pos[i] = -1;

    	scanf("%d%d%d", &tot, &n, &m);
    	n++; m++;
    	f(i, 0, n){	scanf("%d", &val); pos[val] = i; } 
    	f(i, 0, m){	
    		scanf("%d", &val);
    		if(pos[val] == -1)	continue;
    		v.push_back(pos[val]);
    	}
    	memset(t, 0, sizeof t);
    	memset(lis, 0, sizeof lis);
    	int l = 0;
	    for(int i = 0, idx; i < v.size(); ++i) {
	        idx = lower_bound(t, t + l, v[i]) - t;
	        t[idx] = v[i];
	        if(idx == l)
	          ++l;
	        lis[i] = idx + 1;
	    }
	    int ans = 0;
    	for(int i = 0; i < n; ++i)	ans = max(ans, lis[i]);
    	printf("Case %d: %d\n", tt++, ans);
    }

return 0;}
