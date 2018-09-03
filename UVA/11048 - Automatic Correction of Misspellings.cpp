#include <bits/stdc++.h>
using namespace std;
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
int n , q;
bool yes = false;
string dic[10001], s;
vector < int > ans;
map <string, int > mp;
vector < string > v;
void remove(){
	string make = s.substr(1);
	v.push_back(make);
	f(i, 1, s.size() - 1){
		make = s.substr(0, i);
		make += s.substr(i + 1);
		v.push_back(make);
	}
	make = s.substr(0, s.size() - 1);
	v.push_back(make); 
}
void swapl(){
	string make = s;
	f(i, 0, s.size() - 1){
		char tmp = make[i];
		make[i] = make[i+1];
		make[i+1] = tmp;
		v.push_back(make);
		make = s;
	}
}
void changel(){

	string make = s;
	f(i, 0, s.size()){
		make = s;
		f(j, 0, 26){
			make[i] = (j + 'a');
			v.push_back(make); 
		}
	}
}
void addl(){
	
	for (int i = 0; i <= s.size(); i++) {
      for (char c = 'a'; c <= 'z'; c++) {
        string a = s.substr(0, i) + c + s.substr(i);
       	v.push_back(a);
      }
    }

}
int main(){
	
	while(scanf("%d", &n) == 1) {
		mp.clear();
		f(i, 0, n){
			cin >> dic[i];
			mp[dic[i]] = i;
		}
		
		scanf("%d", &q);
		f(i, 0, q){
			cin >> s;
			if (mp.find(s) != mp.end()){
					printf("%s is correct\n", s.c_str());
					continue;
			}// end of if 
			remove();
			swapl();
			changel();
			addl();
			f(j, 0, v.size()){
			 	if(mp.find(v[j]) != mp.end()){
			 		ans.push_back(mp[v[j]]);
			 		yes = true;
			 		
			 	}
			} // end of i loop 
			if (yes){
				sort(ans.begin(), ans.end());
				printf("%s is a misspelling of %s\n", s.c_str(), dic[ans[0]].c_str());
			}
			else if(!yes) printf("%s is unknown\n", s.c_str());	
			v.clear();
			ans.clear();
			yes = false;


		}// end of q loop
	}// end of while 	

	return 0;				
}
