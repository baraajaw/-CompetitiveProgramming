#include<bits/stdc++.h>
using namespace std;

set<int> st;

int main(){
    

     int n,  a[3003];

     while (scanf("%d", &n) > 0){
        st.clear();
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        
        for (int i = 1; i < n; ++i)
            if (abs(a[i] - a[i - 1]) >= 1 && abs(a[i] - a[i - 1]) < n)
                st.insert(abs(a[i] - a[i - 1]));
        if (st.size() == n - 1)
            puts("Jolly");
        else
            puts("Not jolly");

     }



}
