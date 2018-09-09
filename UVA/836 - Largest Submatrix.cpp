#include <bits/stdc++.h>
using namespace std;
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
int n;
char s[30];
string a;
vector <string > v;
int main() {

    int t;
    scanf("%d", &t);
    cin.ignore();
	cin.ignore();
    while(t--){
    	v.clear();

        gets(s); n = strlen(s);		a = s;
        v.push_back(a);
        f (i , 1, n){
        	gets(s);	a = s;
        	v.push_back(a);
        }
       	cin.ignore();

       	int cm[30][30] = { };
        f(i, 0, n ){
        	f(j , 0, n)
        		cm[i + 1][j + 1] = (v[i][j] - '0') + cm[i][j + 1] + cm[i + 1][j] - cm[i][j];
        }
        int res = 0;
       	for(int i = 1; i<= n; ++i)
       		for(int j = 1; j<= n; ++j)
       			for(int k = i; k <= n; ++k)
       				for(int l = j; l <= n; ++l){
       					int c = cm[k][l] - cm[k][j - 1] - cm[i - 1][l] + cm[i - 1][j - 1];
						int a = (k - i + 1) * (l - j + 1);
						if (c == a)
							res = max(res, a);
       				}
       	printf("%d\n", res);			
       	if (t != 0)
			puts("");
    }
    

return 0;
}
