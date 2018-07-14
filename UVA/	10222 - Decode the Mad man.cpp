#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	getline ( cin , s);
	for ( int i = 0 ; i < s.size() ; i++)
	{
		
	if ( tolower(s[i]) == '1')
		cout<<"`";
	else if ( tolower(s[i]) == '`')
		cout<<".";
	else if ( tolower(s[i]) == '2')
	  cout<<"`";
	else if ( tolower(s[i]) == '3')
		  cout<<"1";
	else if ( tolower(s[i]) == '4')
		  cout<<"2";
	else if ( tolower(s[i]) == '5')
		  cout<<"3";
	else if ( tolower(s[i]) == '6')
		  cout<<"4";
	else if ( tolower(s[i]) == '7')
		  cout<<"5";
	else if ( tolower(s[i]) == '8')
		  cout<<"6";
	else if ( tolower(s[i]) == '9')
		  cout<<"7";
	else if ( tolower(s[i]) == '0')
		  cout<<"8";
	else if ( tolower(s[i]) == 'q')
		  cout<<"9";
	else if ( tolower(s[i]) == 'w')
		  cout<<"0";
	else if ( tolower(s[i]) == 'e')
		  cout<<"q";
	else if ( tolower(s[i]) == 'r')
		  cout<<"w";
	else if ( tolower(s[i]) == 't')
		  cout<<"e";
	else if ( tolower(s[i]) == 'y')
		  cout<<"r";
	else if ( tolower(s[i]) == 'u')
		  cout<<"t";
	else if ( tolower(s[i]) == 'i')
		  cout<<"y";
	else if ( tolower(s[i]) == 'o')
		  cout<<"u";
	else if ( tolower(s[i]) == 'p')
		  cout<<"i";
	else if ( tolower(s[i]) == '[')
		  cout<<"o";
	else if ( tolower(s[i]) == ']')
		  cout<<"p";
	else if ( tolower(s[i]) == 'a')
		  cout<<"[";
	else if ( tolower(s[i]) == 's')
		  cout<<"]";
	else if ( tolower(s[i]) == 'd')
		  cout<<"a";
	else if ( tolower(s[i]) == 'f')
		  cout<<"s";
	else if ( tolower(s[i]) == 'g')
		  cout<<"d";
	else if ( tolower(s[i]) == 'h')
		  cout<<"f";
	else if ( tolower(s[i]) == 'j')
		  cout<<"g";
	else if ( tolower(s[i]) == 'k')
		  cout<<"h";
	else if ( tolower(s[i]) == 'l')
		  cout<<"j";
	else if ( tolower(s[i]) == ';')
		  cout<<"k";
	else if ( tolower(s[i]) == '\'')
		  cout<<"l";
	else if ( tolower(s[i]) == 'z')
			  cout<<";";
	else if ( tolower(s[i]) == 'x')
			  cout<<"'";
	else if ( tolower(s[i]) == 'c')
			  cout<<"z";
	else if ( tolower(s[i]) == 'v')
				  cout<<"x";
	else if ( tolower(s[i]) == 'b')
				  cout<<"c";
	else if ( tolower(s[i]) == 'n')
				  cout<<"v";
	else if ( tolower(s[i]) == 'm')
				  cout<<"b";
	else if ( tolower(s[i]) == ',')
				  cout<<"n";
	else if ( tolower(s[i]) == '.')
				  cout<<"m";
	else if ( tolower(s[i]) == '/')
				  cout<<",";
	else if ( tolower(s[i]) == ' ')
				  cout<<" ";
	
	
}
	cout<<endl;
	
	
	return 0;
}
