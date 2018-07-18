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


struct trie {
  trie *nxt[10];
  bool end;
  int pre;
  
  trie() {
    for(int i = 0; i < 10; ++i)
      nxt[i] = NULL;
    end = pre = 0;
  }
};

trie *root;
string a;
int cnt = 0, n, t;
vector < string > v;


void insert() {
  trie *cur = root;
  for(int i = 0, num; i < a.size(); ++i) {
    num = a[i] - '0';
    if(cur->nxt[num] == NULL)
      cur->nxt[num] = new trie();
    cur = cur->nxt[num];
    if ( cur -> end == true) cnt++;
    ++cur->pre;
  }
  cur->end = true;
}
void find() {
  trie *cur = root;
  for(int i = 0, num; i < a.size(); ++i) {
    num = a[i] - '0';
    if ( cur -> end) cnt++;
    cur = cur->nxt[num]; 
  }
}

void freeTrie(trie *cur) {
  if(cur == NULL)
    return;
  for(int i = 0; i < 10; ++i)
    freeTrie(cur->nxt[i]);
  delete [] cur;
}


int main() {
  freopen("in", "r", stdin); 
  scanf("%d", &t);
  while (t--){
  root = new trie();  
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    cin >> a;
    v.push_back(a);
    insert();
  }
  f(i, 0, n){
    a = v[i];
     find();
  }
  if ( cnt > 0 ) puts("NO");
  else puts("YES");
  cnt = 0;
  v.clear();
  freeTrie(root);
 }
  
  return 0;
}
