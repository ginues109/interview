#include "qh_string.h"

#include <string.h>

namespace qh
{
    // TODO 将在这里写实现代码

    string::string()
        : data_(NULL), len_(0)
    {
    }

    string::string( const char* s )
    {
		if(s==NULL){
			string();
		}
		else{
			data_= new char[strlen(s)+1];
			strcpy(this->data_, s);
			len_=strlen(s);
		}
    }

    string::string( const char* s, size_t len )
    {
		if(s==NULL)
			string();
		else{
			this->len_=len;
			strncpy(this->data_,s,len_);
			this->data_[len_]='\0';
		}
    }

    string::string( const string& rhs )
    {
		this->data_=new char[strlen(rhs.data_)+1];
		strcpy(this->data_,rhs.data_);
    }

    string& string::operator=( const string& rhs )
    {//is it necessary to consider an empty rhs?
        this->data_=new char[strlen(rhs.data_)+1];
		strcpy(this->data_,rhs.data_);
		return *this;
    }

    string::~string()
    {
		delete[] data_;
    }

    size_t string::size() const
    {
        return len_;
    }

    const char* string::data() const
    {
        return data_;
    }

    const char* string::c_str() const
    {
        return data_;
    }

    char& string::operator[]( size_t index )
    {
		if(index>=0&&index<len_){
			return data_[index];
		}
		
    }
}
