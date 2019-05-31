#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int n, m;
map<int, int > mp;

int main(){

   
    while (scanf("%d%d", &n, &m) && n != 0 && m != 0){
    	
     int x, ans = 0;
    	mp.clear();
    	
    	for (int i = 0; i < n; ++i){
    		scanf("%d", &x);
    		mp[x]++;
    	}
    	for (int i = 0; i < m; ++i){
    		scanf("%d", &x);
    		mp[x]++;
    	}

    	for (auto it = mp.begin(); it != mp.end(); ++it)
    		ans += (it->second > 1 ? 1 : 0);

    	printf("%d\n", ans);
    	
    }

}
