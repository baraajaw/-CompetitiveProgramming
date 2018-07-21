#include <bits/stdc++.h>
#define ll long long 
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)
using namespace std;
struct trie {
  trie *next[4];
  int prefix;  
  trie() {
    
      f(i, 0, 4)
        next[i] = NULL;
      prefix = 0;
  }
};
trie *root;
char s[1001];
int len;
string res;
bool cont = true;

void insert(int j){
    trie * cur = root;
    for ( int i = j , num; s[i] != '\0'; ++i){
      num = s[i] - '0';
      if (cur ->next[num] == NULL)
          cur ->next[num] = new trie();
      cur = cur ->next[num];
      cur->prefix++;
      if ( cur ->prefix > 1)  
        len = max ( len, i - j + 1);
    }
}
void find ( trie *cur, int cnt){
    if (cnt == len){
        for ( int i = 0 ; i < res.size(); ++i){
           if(res[i] == '0') putchar('A');
           else if(res[i] == '1') putchar('C');
           else if(res[i] == '2') putchar('G');
           else if(res[i] == '3') putchar('T');
        }// end of for
        printf(" %d\n", cur->prefix);
        cont = false;
        return;
    } // end of if 
    for ( int i = 0; i < 4 && cont; ++i){
        if ( cur -> next[i] != NULL && cur -> next[i] -> prefix > 1){
            res += char(i + '0');
            find ( cur -> next[i], cnt + 1);
            res.pop_back();
        }// end of if 
    }// end of for 
}

void freeTrie(trie *cur) {
  for(int i = 0; i < 4; i++)
    if(cur->next[i] != NULL)
      freeTrie(cur->next[i]);
  delete[] cur;
}
int main() {
  int t;
  scanf("%d", &t);
  while ( t--){
      root = new trie();
      len = 0;
      cont = true;
      res = "";

      scanf("%s", s);

      for ( int i = 0 ; s[i] != '\0' ; ++i){
        if ( s[i] == 'A') s[i] = '0';
        else if (s[i] == 'C') s[i] = '1';
        else if (s[i] == 'G') s[i] = '2';
        else if (s[i] == 'T') s[i] = '3';
      }
      for( int i = 0; s[i] != '\0'; ++i)
          insert(i);

      if (len == 0) 
          puts("No repetitions found!");
      else
          find (root, 0);  


      freeTrie(root);
  }
  


  return 0;
}
