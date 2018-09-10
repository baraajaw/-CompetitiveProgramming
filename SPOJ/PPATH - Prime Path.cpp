#include <bits/stdc++.h>
using namespace std;
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
int const N = 1e4 + 1;
bool prime[N], vis[N];
vector<int> primes;
int cost[N];
void sieve() {
  memset(prime, true, sizeof prime);
  
  prime[0] = false;
  prime[1] = false;
  
  for(int i = 2; i * i < N; i++)
    if(prime[i])
      for(int j = i + i; j < N; j += i)
        prime[j] = false;
  
  for(int i = 0; i < N; i++)
    if(prime[i])
      primes.push_back(i);
}
int change(int fr, int i, int j){
	string s = "";
	int tmp = fr;
	while(tmp != 0){
		s += (tmp % 10) + '0';
		tmp/= 10;
	}
	reverse(s.begin(), s.end());
	s[j] = i + '0';
	tmp = 0;
	f(k, 0, s.size())
		tmp = tmp * 10 + (s[k] - '0');
	return tmp;	
}
int BFS(int src, int des){
	queue<int> qu;
	if (des == src) 
		return 0;
	memset(vis, false, sizeof vis);
	qu.push(src);
	vis[src] = true;
	cost[src] = 0;
	while(!qu.empty()){
		int fr = qu.front();
		qu.pop();
		f(i, 0, 10)
			f(j, 0, 4){
				int to = change(fr, i, j);
				if(!vis[to] && prime[to]){
					if(to == des)
						return cost[fr] + 1;
					vis[to] = true;
					qu.push(to);
					cost[to] = cost[fr] + 1;
				}// end of f
			}// end o j
	}// end of while
	return -1;
}
int main() {
	sieve(); // 168
	int t;
	scanf("%d", &t);
	while(t--){
		int src, dest;
		scanf("%d%d", &src, &dest);
		int res = BFS(src, dest);
		if(res == -1)
			puts("Impossible");
		else
			printf("%d\n", res);

	}



	return 0;
}
