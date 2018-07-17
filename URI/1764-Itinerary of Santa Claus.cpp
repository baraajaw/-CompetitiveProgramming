#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <sstream>
#define ll long long 
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)
using namespace std;
struct edge {
    int from, to, cost;
    edge() {}
    edge(int from, int to, int cost) :
        from(from), to(to), cost(cost) {}
    bool operator<(const edge &e) const {
        return cost < e.cost;
    }
};
int n, m, ds[100001], tot_cost = 0;
vector<edge> edges;
int find(int x) {
    if(ds[x] == x)
        return x;
    return ds[x] = find(ds[x]);
}

int main() {
int from, to, cost;
 while ( scanf ("%d%d", &n, &m) && n ){
     f(i, 0, n)
          ds[i] = i;
     edges.clear();

     f(i, 0, m){
      scanf("%d%d%d", &from, &to, &cost);
      edges.push_back(edge(from, to, cost));
     }
     sort(edges.begin(), edges.end());
     int taken = 0;
     f(i, 0, m) {
        edge e = edges[i];
        
        from = find(e.from);
        to = find(e.to);
        
        if(from == to)
            continue;
        
        ds[from] = to;
        tot_cost += e.cost;
        
        if(taken == n - 1)
            break;
    }
    printf("%d\n", tot_cost );     
    tot_cost = 0;
    
    
 }


  return 0;
}
