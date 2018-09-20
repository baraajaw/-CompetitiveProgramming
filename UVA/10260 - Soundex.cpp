#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int  main() {
  map <char, char > mp;
  mp['A'] = mp['E'] = mp['I'] = mp['O'] = mp['U'] = mp['H'] = mp['W'] = mp['Y'] = '0';
  mp['B'] = mp['F'] = mp['P'] = mp['V'] = '1';
  mp['C'] = mp['G'] = mp['J'] = mp['K'] = mp['Q'] = mp['S'] = mp['X'] = mp['Z'] = '2';
  mp['D'] = mp['T'] = '3';
  mp['L'] = '4';
  mp['M'] = mp['N'] = '5';
  mp['R'] = '6';
  string s;
  while (cin >> s){
    string ans = "";
    if(mp[s[0]] != '0') ans += mp[s[0]];
    for (int i = 1; i < s.size(); ++i)
      if(mp[s[i]] != mp[s[i-1]] && mp[s[i]] != '0')
        ans += mp[s[i]];
    cout << ans << endl;  
  }



  return 0;
}
 
