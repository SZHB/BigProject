 ///
 /// @file    ex12_27_30.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-22 22:18:17
 ///
 
#include"ex12_27-30.h"
#include<sstream>
#include<algorithm>
#include<iterator>

TextQuery::TextQuery(std::ifstream& ifs):input(new vector<string>)
{
	LineNo lineNo{0};
	for(string line;std::getline(ifs,line);++lineNo){
		input->push_back(line);
		std::istringstream line_stream(line);
		for(string text,word;line_stream>>text;word.clear()){
			std::remove_copy_if(text.begin(),text.end(),std::back_inserter(word),ispunct);

			auto & nos =result[word];
			if(!nos) nos.reset(new std::set<LineNo>);
			nos->insert(lineNo);
		}
	}
}
QueryResult TextQuery::query(const string& str) const
{
	static shared_ptr<std::set<LineNo> > nodate(new std::set<LineNo>);
	auto found=result.find(str);
	if(found ==result.end())
		return QueryResult(str,nodate,input);
	else
		return QueryResult(str,found->second,input);//返回第二个属性
}

std::ostream& print(std::ostream& out,const QueryResult& qr)
{
	out<<qr.word<<"occurs"<<qr.nos->size()
		<<(qr.nos->size()>1?"times":"time")<<std::endl;
	for(auto i:*qr.nos)
		out<<"\t(line"<<i+1<<")"<<qr.input->at(i)<<std::endl;
	return out;
}
	
