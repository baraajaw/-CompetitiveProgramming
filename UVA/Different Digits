#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int x , y , z , p[10]={0 ,0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,0},count = 0 , count1 = 0;
	while(cin >> x >> y)
	{
	for ( int i = x ; i <= y ; i++)
	{
		z = i;
		while (  z != 0 )
		{
         p[z % 10]++;
         z = z / 10;
		}
		for ( int j = 0 ; j < 10 ; j++)
		{
		if(p[j] >= 2)
			  count++;
		}
		if( count == 0)
			count1++;
		   count = 0;
		   
		for ( int j = 0 ; j < 10 ; j++)
			p[j] = 0;
	}
	cout<<count1<<endl;
	count1  =  0;
}
	return 0;
}
