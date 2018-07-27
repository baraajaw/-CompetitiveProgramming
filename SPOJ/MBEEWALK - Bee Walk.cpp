#include <bits/stdc++.h>
using namespace std;
 
int dx[]={ -2 , 2 , 1 , 1 , -1 , -1 };
int dy[]={ 0 , 0 , -1 , 1 , -1 , 1 };
int dp[100][100][20];
vector < pair < int , int > > vc;
 
int cal ( int x , int y , int rem){
    
    if ( rem == 0 )          
      return (x == 50 && y == 50 ? 1 : 0);
 
    int & ret = dp[x][y][rem];
    if ( ret != -1)
      return ret ;
    ret = 0; 
    for ( int i = 0 ; i < 6 ; ++i){
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        ret +=  cal ( nx , ny , rem - 1);
    }
 
    return ret ;  
}
int main() {
 
    
   
   int t , n;
 
   cin >> t;
   while ( t--){
 
    cin >> n;
    memset ( dp , -1 , sizeof dp);
    cout << cal ( 50 , 50 , n) << endl;
   } 
  
 
 
return 0;
}
