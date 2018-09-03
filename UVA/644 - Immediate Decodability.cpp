#include <bits/stdc++.h>
using namespace std;
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long

int main(){
	string code[11];
	int n, Case = 1;
	while (cin >> code[0]){
		n = 0;
		do{
			++n;
			cin >> code[n];
		} while (code[n][0] != '9');
		bool yes = true;
		for(int i = 0; i < n && yes ; ++i){
			for(int j = i + 1; j < n && yes ; ++j){
				string try1 = code[i].substr (0, code[j].size());
				if( try1 == code[j]) yes = false;
				try1 = code[j].substr(0, code[i].size());
				if(try1 == code[i]) yes = false;

			}// end of j loop 
		}// end of i loop 
		printf("Set %d is ", Case++);
		if (yes)
			printf("immediately decodable\n");
		else
			printf("not immediately decodable\n");


	}// end of while 
	

	return 0;				
}
