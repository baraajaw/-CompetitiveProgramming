#include<iostream>
#include<string>
using namespace std;
int main()
{
	long long p , budget , ho , we , p1  , count = 0 , b = 0 , c;
	int *p2;
	while (cin >> p >> budget >> ho >> we)
	{
	    c = 1e18 + 1;
	p2 = new int[we];
	for (int j = 0 ; j < ho ;j++)
	{
	cin >> p1;
	for ( int i = 0 ; i < we ; i++)
	{
		cin >> p2[i];
		 if ( p <=p2[i])
			 count++;
	}
	if ( count > 0)
	{
	b = p1 * p;
	if ( b <= budget && c > b)
	   c = b;
	}
count = 0;
	}
	if ( c != 1e18 + 1)
		cout<<c<<endl;
	else
		cout<<"stay home"<<endl;
		c = 0;
	}

	return 0;
}
