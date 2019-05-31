#include<bits/stdc++.h>
using namespace std;

char s[1002];
bool f = true;
stack<char > st;

int main(){

    
    int T;
    scanf("%d", &T);
    
    while (T--){
    	scanf("%s", s);
    	for (int i = 0; i < strlen(s); ++i)
    		if (s[i] == ']'){
    			if (!st.empty() && st.top() == '[')
    				st.pop();
    			else if (st.empty() || (!st.empty() && st.top() != '[')){
    				f = false;
    				break;
    			}
    		}
    		else if (s[i] == ')'){
    			if (!st.empty() && st.top() == '(')
    				st.pop();
    			else if (st.empty() || (!st.empty() && st.top() != '(')){
    				f = false;
    				break;
    			}
    		}
    		else if (s[i] == '}'){
    			if (!st.empty() && st.top() == '{')
    				st.pop();
    			else if (st.empty() || (!st.empty() && st.top() != '{')){
    				f = false;
    				break;
    			}
    		}
    		else 
    			st.push(s[i]);
    	if (!f || !st.empty())
    		puts("NO");
    	else
    		puts("YES");

    	f = true;
    	while (!st.empty())	st.pop();
    		
    }

}
