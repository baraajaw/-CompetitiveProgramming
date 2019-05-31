#include<bits/stdc++.h>
using namespace std;

int n, ans ;
char ch[5], cu = 'l';
double l, x;
queue<int > lq, rq;

int main(){

    
    int T;
    scanf("%d", &T);
    
    while (T--){
    	scanf("%lf%d", &l, &n);
    	l *= 100;
    	ans = 0;

    	for (int i = 0; i < n; ++i){
    		scanf("%lf%s", &x, ch);
    		if (ch[0] == 'l')
    			lq.push(x);
    		else
    			rq.push(x);
    	}
    		
    	while (!rq.empty() || !lq.empty()){
    		double sum = 0;

    		if (cu == 'l'){
    			while (!lq.empty() && lq.front() + sum <= l){
    				sum += lq.front();
    				lq.pop();
    			}
    			cu = 'r';	
    		}
    		else {
    			while (!rq.empty() && rq.front() + sum <= l){
    				sum += rq.front();
    				rq.pop();
    			}
    			cu = 'l';
    		}
    		ans++;
    	}
    	printf("%d\n", ans);
    	cu = 'l';
    }

}
