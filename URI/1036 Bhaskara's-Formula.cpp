#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std; 

int main()
{
  float a,b,c;
  double x,y;
  cin>>a>>b>>c;
  if(a==0.0||(b*b)<(4*a*c))
  {
    cout<<"Impossivel calcular"<<endl;
  }
  else
  {
    x=(-b+sqrt(b*b-4*a*c))/(2*a);
    y=(-b-sqrt(b*b-4*a*c))/(2*a);
    cout<<fixed<<setprecision(5);
  cout<<"R1 = "<<x<<endl;
  cout<<"R2 = "<<y<<endl;
  }
  
  return 0; 
}
