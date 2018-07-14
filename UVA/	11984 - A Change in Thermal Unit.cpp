#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
int x;
    cin >> x;
for (int i = 1; i <= x; ++i)
    {
double f, c;
        cin >> f>> c;
        f = f + 5.0 / 9.0 * c;
        cout<<fixed<<setprecision(2);
         cout<<f<<endl;
    }
}
