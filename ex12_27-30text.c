 ///
 /// @file    ex12_27_30_Text.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-21 09:30:08
 ///
 
#include"ex12_27-30.h"
#include<iostream>

void runQueries(std::ifstream& infile)
{
	TextQuery tq(infile);
	while(true)
	{
		std::cout <<"enter word to look for,or q to quit"<<std::endl;
		string s;
		if(!(std::cin>>s)||s=="q")break;
		print(std::cout,tq.query(s))<<std::endl;
	}
}
int main()
{
	std::ifstream file("../data/storyDataFile.txt");
	runQueries(file);
}
