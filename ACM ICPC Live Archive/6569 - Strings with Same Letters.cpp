#include<bits/stdc++.h>
#define ll long long 
using namespace std;

bool f = true;
int freq1[26], freq2[26];
string s, c;

int main(){

 	
 	int T = 1;

    while(cin >>s>>c && s != "END" && c != "END"){
    	f = true;
    	memset(freq1, 0, sizeof freq1);
    	memset(freq2, 0, sizeof freq2);

    	for (int i = 0; i < s.size(); ++i)
    		freq1[s[i] - 'a']++;
    	for (int i = 0; i < c.size(); ++i)
    		freq2[c[i] - 'a']++;

    	for (int i = 0; i < 26; ++i)
    		if (freq1[i] != freq2[i]){
    			f = false;
    			break;
    		}
    	if (f)
    		printf("Case %d: same\n", T++);
    	else
    		printf("Case %d: different\n", T++);
    }




}
