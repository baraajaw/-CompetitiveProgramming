#include<bits/stdc++.h>
#define ll long long 
using namespace std;

string s;
int freqs[26], freqc[26];

int main(){

    
    while (getline(cin, s)){
    	memset(freqs, 0, sizeof freqs);
    	memset(freqc, 0, sizeof freqc);

    	for (int i = 0; i < s.size(); ++i){
    		if (islower(s[i]))
    			freqs[s[i] - 'a']++;
    		else if (isupper(s[i]))
    			freqc[s[i] - 'A']++;
    	}
    	int mx = 0;
    	string ans = "";
    	for (int i = 0; i < 26; ++i){
    		if (freqs[i] > mx)
    			mx = freqs[i], ans = (i + 'a');
    		else if (freqs[i] == mx)
    			ans += (i + 'a');
    		if (freqc[i] > mx)
    			mx = freqc[i], ans = (i + 'A');
    		else if (freqc[i] == mx)
    			ans += (i + 'A');
    	}
    	sort(ans.begin(), ans.end());
    	printf("%s %d\n", ans.c_str(), mx);
    	
    }


}
