 ///
 /// @file    ex12_27-30.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-22 21:57:47
 ///
#ifndef CP5_ex12_27_H
#define CP5_ex12_27_H

#include<vector>
using std::vector;

#include<memory>
using std::shared_ptr;

#include<iostream>
#include<fstream>
#include<map>
#include<set>
using std::string;

class QueryResult;
class TextQuery
{
	public:
		using LineNo=vector<string>::size_type;
		TextQuery(std::ifstream&);
		QueryResult query(const string&)const;

	private:
 		shared_ptr<vector<string> >input;
		std::map<string,shared_ptr<std::set<LineNo> > >result;
};
class QueryResult{
	 public:
		friend std::ostream& print(std::ostream&,const QueryResult&);
	public:
		QueryResult(const string& s,shared_ptr<std::set<TextQuery::LineNo> >set,
				shared_ptr<vector<string> > v)
			:word(s),nos(set),input(v)
		{
		}
	private:
	 	string word;
		shared_ptr<std::set<TextQuery::LineNo> >nos;
		shared_ptr<std::vector<string> >input;
};

std::ostream& print(std::ostream&,const QueryResult&);
#endif
