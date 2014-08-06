#include "ini_parser.h"
#include <string>
#include <iostream>


namespace qh
{
	//bool INIParser::Parse(const std::string& ini_file_path){
	//};

	INIParser::INIParser(){};

	INIParser::~INIParser(){};

	bool INIParser::Parse(const char* ini_data, size_t ini_data_len, const std::string& line_seperator, const std::string& key_value_seperator){
		std::string ini_data_string(ini_data);
		std::string lsep(line_seperator);
		std::string kvsep(key_value_seperator);
		printf("%s\n",ini_data_string.data());
		//std::cout<<ini_data_string;
		int startFrom=0;//look for next key_value_seperator from startFrom
		int flag=0;//pointer pointed at current key_value_seperator
		for(int i=0;(!(flag==-1))&&i<100;i++){
			int step=0;
			flag = ini_data_string.find_first_of(kvsep,startFrom);
			if(flag==-1) break;

			int _pos = ini_data_string.rfind(lsep,flag);
			int pos_ = ini_data_string.find(lsep,flag);
			
			if(_pos==-1){
				_pos=0;
				step=0;
			}
			else{
				step=lsep.length();
			}

			if(pos_==-1){
				pos_=ini_data_len;
			}

			std::string key = ini_data_string.substr(_pos + step, flag - _pos - step);
			std::string value = ini_data_string.substr(flag + 1, pos_ - flag - 1);
			printf("%s:%s\n",key.data(),value.data());
			keyValuePair[i][0]=key;
			keyValuePair[i][1]=value;
			//std::cout<<key<<":"<<value<<std::endl;
			if(flag+1>ini_data_string.length())
				break;
			else
				startFrom=flag+1;
		}
		return true;
	};

	const std::string& INIParser::Get(const std::string& key, bool* found){
		for(int i=0;i<100;i++){
			if(keyValuePair[i][0]==key){
				*found = true;
				return keyValuePair[i][1];
			};
		}
	};
}