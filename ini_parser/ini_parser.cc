#include "ini_parser.h"
#include <string>
#include <fstream>
#include <assert.h>


namespace qh
{
	INIParser::INIParser(){};

	INIParser::~INIParser(){};

	bool INIParser::Parse(const std::string& ini_file_path){
		
		std::string str="";
		char buffer[100];
		
		std::fstream in(ini_file_path,std::ios::in);//test.txt����ĿĿ¼��
		if(!in.is_open()){
			printf("Error opening file");
			return false;
		}
		while(!in.eof()){
			in.getline(buffer,100);
			str+=buffer;
		}
		
		ini_data=new char[100];
		strcpy(ini_data,str.data());

		//printf(ini_data);
		
		return true;
		
	};

	bool INIParser::Parse(const char* ini_data, size_t ini_data_len, const std::string& line_seperator, const std::string& key_value_seperator){
		
		std::string ini_data_string(ini_data);
		std::string lsep(line_seperator);
		std::string kvsep(key_value_seperator);
		printf("%s\n",ini_data_string.data());
		
		int startFrom=0;	//��startFrom��ʼ�����Ҽ�ֵ�ָ���
		int flag=0;			//��ǰ��ֵ�ָ���
//		for(int i=0;(!(flag==-1))&&i<100;i++){
		while((!(flag==-1))){
			int step=0;
			flag = ini_data_string.find_first_of(kvsep,startFrom);
			if(flag==-1) break;
			int _pos = ini_data_string.rfind(lsep,flag);	//�ӵ�ǰ��ֵ�ָ�����ǰ�Ҽ���λ��
			int pos_ = ini_data_string.find(lsep,flag);		//�ӵ�ǰ��ֵ�ָ���������ֵ��λ��
			
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

			std::string key = ini_data_string.substr(_pos + step, flag - _pos - step);	//��ȡ��
			std::string value = ini_data_string.substr(flag + 1, pos_ - flag - 1);		//��ȡֵ
			printf("%s%s%s\n",key.data(),kvsep.data(),value.data());

			keyValuePair[key]=value;

			if(flag+1>ini_data_string.length())
				break;
			else
				startFrom=flag+1;	//��ʼ����һ����ֵ�ָ���
		}
		return true;
	};

	std::string INIParser::Get(const std::string& key, bool* found){
		std::map<std::string,std::string>::iterator it;
		it = keyValuePair.find(key);
		if(it!=keyValuePair.end())
			return it->second;
		//*found = false;
		else
			return "";
	};
}