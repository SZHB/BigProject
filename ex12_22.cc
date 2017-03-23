 ///
 /// @file    ex12_22.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-23 23:26:21
 ///
 
#include "ex12_22.h"

ConstStrBlobPtr StrBlob::begin() const//should add const
{
	return ConstStrBlobPtr(*this);
}
ConstStrBlobPtr StrBlob::end() const
{
	return ConstStrBlobPtr(*this,data->size());
}
