#include "qh_string.h"
#include <stdio.h>
#include <string.h>

namespace qh
{
    // TODO 将在这里写实现代码

    string::string()
        : data_(NULL), len_(0)
    {
		data_='\0';
		len_=0;
    }

    string::string( const char* s )
    {
		if(s==NULL){
			string();
		}
		else{
			data_= new char[strlen(s)+1];//data_是一个字符数组指针变量
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
			data_=new char[len_+1];
			strncpy(this->data_,s,len_);
			this->data_[len_]='\0';
		}
    }

    string::string( const string& rhs )
    {
		if(!rhs.data_){
			string();
		}
		else{
			this->data_=new char[strlen(rhs.data_)+1];
			strcpy(this->data_,rhs.data_);
			len_=strlen(rhs.data_);
		}
    }

    string& string::operator=( const string& rhs )
    {
		if(this!=&rhs){
			delete[] data_;
			if(!rhs.data_) data_=0;
			else{
				this->data_=new char[strlen(rhs.data_)+1];
				strcpy(this->data_,rhs.data_);
				len_=strlen(rhs.data_);
			}
		}
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

  //  char* string::operator[]( size_t index )
  //  {
		//if(index>=0&&index<len_){
		//	char* tmp=new char[index+2];
		//	strncpy(tmp,this->data_,index+2);
		//	tmp[index+1]='\0';
		//	return tmp+index;
		//	//return data_[index];
		//}
  //  }

	char& string::operator[]( size_t index )
    {
		if(index>=0&&index<len_){
			return data_[index];
		}
    }
}
