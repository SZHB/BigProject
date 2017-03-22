 ///
 /// @file    ex12_27.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-21 09:21:28
 ///
 
#ifndef CP5_ex12_27_H_
#define CP5_ex12_27_H_

#include<string>
using std::cout;
using std::endl;

#include<memory>
using std::shared_ptr;

#include<vector>
using std::vector;

#include<iostream>
#include<fstream>
#include<map>
#include<set>

class QueryResult;
class TextQuery
{
	public:
		using LineNo = vector<string>::szie_type;
		QueryResult query(const string&) const;

	private:
		shared_ptr<vector<string> >input;
		std::map<string,shared_ptr<std::set<LineNo>>> result;
};
class QueryResult
{
	public:
		friend std::ostream& printf(std::ostream&,const QueryResult&);
	public:
		QueryResult(const string& s,shared_ptr<std::set<TextQuery::LineNo>>set;
				shared_ptr<vector<string>> v)
			:word(s),nos(set),input(v)
		{
		}

	private:
		string word;
		shared_ptr <std::set<TextQuery::LineNo>> nos;
		shared_ptr<vector<string>>input;
};
std::ostream& print(std::ostream&,const QueryResult&);
#endif

