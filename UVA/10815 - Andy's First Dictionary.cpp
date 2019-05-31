#include<bits/stdc++.h>
#define ll long long 
using namespace std;


char s[5006];
set<string > st;

int main(){

    
    while (gets(s)){
    	string tmp = "";
    	for (int i = 0; i < strlen(s); ++i){
    		if (isalpha(s[i]))
    			tmp += tolower(s[i]);
    		else{
    			if (tmp != "")
    				st.insert(tmp);
    			tmp = "";
    		}
    	}
    	if (tmp != "")
    		st.insert(tmp);
    }
    for (auto it = st.begin(); it != st.end(); ++it)
    	printf("%s\n", (*it).c_str());

}
