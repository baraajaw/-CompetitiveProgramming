#include <bits/stdc++.h>
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

struct point {
    int x, y;

    point(int x, int y) :
        x(x), y(y) {}
};

int n, m, ds[100001];
double  tot_cost = 0;
vector<edge> edges;
vector<point> points;

int dist(point a, point b) {
    return ((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y));
}

int find(int x) {
    if(ds[x] == x)
        return x;
    return ds[x] = find(ds[x]);
}

int main() {
 int from, to, cost, t, x, y;
 scanf("%d", &t);
 while ( t-- ){
     scanf("%d", &n);
     f(i, 0, n)
          ds[i] = i;
     edges.clear();
     points.clear();

     f(i, 0, n){
      scanf("%d%d", &x, &y);
      points.push_back(point(x, y));
     }
     f(i, 0, n)
        f(j, 0, n)
            if ( i != j)
             edges.push_back(edge(i, j, dist(points[i], points[j])));

     sort(edges.begin(), edges.end());
     int ta = 0;
     for (int i = 0, a, b; i < edges.size(), ta < n - 1; ++i) {
        a = find(edges[i].from);
        b = find(edges[i].to);
        
        if(ds[a] == ds[b])
            continue;
        ++ta;
        ds[a] = b;
        tot_cost += sqrt(edges[i].cost);
        
    }
    printf("%.2lf\n", tot_cost / 100 );     
    tot_cost = 0;
    
    
 }


  return 0;
}
