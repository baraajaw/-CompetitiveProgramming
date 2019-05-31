#include<bits/stdc++.h>
#define ll long long 
using namespace std;

string s;
int freq[26];
vector<pair<int, int> > v;

bool compare(pair<int, int> i,pair<int, int> j){
    return (i.first > j.first) || (i.first == j.first && i.second < j.second);
}

int main(){

   	
   	int T;
   	scanf("%d", &T);
   	cin.ignore();

   	memset(freq, 0, sizeof freq);

   	while (T--){
   		getline(cin, s);
   		for (int i = 0; i< s.size(); ++i)
   			if (isalpha(s[i]))
   				freq[tolower(s[i]) - 'a']++;
   	}
   	for (int i = 0; i < 26; ++i)
   		if (freq[i] > 0)
   			v.push_back(make_pair(freq[i], i));

   	sort(v.begin(), v.end(), compare);

   	for (int i = 0; i < v.size(); ++i)
   		printf("%c %d\n",v[i].second + 'A', v[i].first );

}
