 ///
 /// @file    ex12_33.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-22 16:47:38
 ///
#include"ex12_33.h"

#include<sstream>
#include<algorithm>
#include<iterator>

TextQuery::TextQuery(std::ifstream& ifs):input(new StrBlob)
{
	StrBlob::size_type lineNo{0};
	for(string line;std::getline(ifs,line);++lineNo)
	{
	 	input->push_back(line);
		std::istringstream line_stream(line);
		for(string text,word;line_stream>>text;word.clear()){
	 		//avoid read a word followed  by punchtuation(such as word)
			std::remove_copy_if(text.begin(),text.end()
					,std::back_inserter(word),ispunct);
			auto& nos =result[word];//decltype 与auto引用有些不同，dcltype((value))的结果永远都是引用,decltype(variable)只有当valiable本身是一个引用时，结果才是引用
			if(!nos)nos.reset(new std::set<StrBlob::size_type>);
		}
	}
}
QueryResult TextQuery::query(const string& str)const
{
	//use s tatic just allocate once
	static shared_ptr<std::set<StrBlob::size_type> >nodate(
	 		new std::set<StrBlob::size_type>);
		auto found =result.find(str);
	if(found == result.end())
		return QueryResult(str,nodate,input);
	else 
		return QueryResult(str,found->second,input);
}
std::ostream& print(std::ostream& out,const QueryResult& qr)
{
	 out<<qr.word<<"occurs"<<qr.nos->size()
		<<(qr.nos->size()>1?"times":"time")<<std::endl;
	for(auto it=qr.begin();it!=qr.end();++it){
	 	ConstStrBlobPtr p(*qr.get_file(),*it);
		out<<"\t(line"<<*it+1<<")"<<p.deref()<<std::endl;
	}
	return out;
}
