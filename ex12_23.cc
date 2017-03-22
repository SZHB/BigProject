 ///
 /// @file    ex12_23.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-20 00:04:06
 ///
 
#include <iostream>
#include<string.h>
#include<cstring>
using std::cout;
using std::endl;
int main()
{
	const char *c1="Hello";
	const char *c2="World";
	unsigned len =strlen(c1)+strlen(c2)+1;
	char *r=new char[len]();
	strncat(r,len,c1);
	strncat(r,len,c2);
	cout<<r<<endl;

	std::string s1="hello";
	std::string s2="world";
	strncpy(r,len,(s1+s2).c_str());
	cout<<r<<endl;

	delete[] r;
	return 0;
}
