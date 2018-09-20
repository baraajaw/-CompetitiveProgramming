#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int  main() {
  int n, a[3003];
  bool f = true;
  vector < int > v;
  while (scanf("%d", &n) > 0){
    v.clear();
    f = true;
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    for (int i = 1; i < n; ++i)
      v.push_back(abs(a[i - 1] - a[i])); 
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); ++i)
        if(v[i] != i + 1)
          f = false;
    if(f)
      puts("Jolly");
    else
      puts("Not jolly");      
  }
  return 0;
}
 
