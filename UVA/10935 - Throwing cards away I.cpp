#include<bits/stdc++.h>
using namespace std;


int n;
queue<int >q;
vector<int > ans;

int main(){


    while (scanf("%d", &n) && n > 0){
        for (int i = 0; i < n; ++i)
            q.push(i + 1);

        while (q.size() > 1){
            ans.push_back(q.front());
            q.pop();
            q.push(q.front());
            q.pop();
        }
        printf("Discarded cards:");
        for ( int i = 0; i < ans.size(); ++i){
            printf(" %d", ans[i]);
            if (i + 1 < ans.size())
                printf(",");
        }
        puts("");
        printf("Remaining card: %d\n", q.front());

        while(!q.empty())   q.pop();
        ans.clear(); 
    }


}
