#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int n;
char s[80];
map< string, int> mp;

int main(){
	
   	scanf("%d\n", &n);

   	for (int i = 0; i < n; ++i){
   		scanf("%s", s);
   		mp[s]++;
   		gets(s);
   	}

   	for (auto it = mp.begin(); it != mp.end(); ++it)
   		printf("%s %d\n", it->first.c_str(), it->second);
   
}
