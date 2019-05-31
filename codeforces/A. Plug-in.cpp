#include<bits/stdc++.h>
using namespace std;

string s;
stack <char > st;

int main(){

    
    cin >> s;
    for (int i = 0; i < s.size(); ++i)
    	if (!st.empty() && st.top() == s[i])
    		st.pop();
    	else
    		st.push(s[i]);

    s = "";
    while (!st.empty()){
    	s += st.top();
    	st.pop();
    }
    reverse(s.begin(), s.end());

    printf("%s\n", s.c_str());


  
    

}
