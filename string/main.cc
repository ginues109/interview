#include <stdio.h>
#include <stdlib.h>
#include "qh_string.h"
#include <assert.h>
#include <string>

using namespace qh;
int main(int argc, char* argv[])
{
    //TODO ��������ӵ�Ԫ���ԣ�Խ��Խ�ã�����·��������ԽȫԽ��
    //TODO ��Ԫ����д����ο�INIParser�Ǹ���Ŀ����Ҫдһ��printf��Ҫ��assert���ж����жϡ�
	//���ֹ��캯��
	string str1;
	assert(str1.size()==0&&str1.data()==NULL);
	string str2("Hello world");//��const char* s����
	printf(str2.data());
	if(!strcmp(str2.data(),"Hello world")){
		printf("they are equal");
	}
	assert(str2.size()==11);

	//string str3("Have you had dinner?",6);//��const char* s��size_t len����
	//assert(str3.size()==6);

	//string str4(str2);
	//
	

	//string tmp=str2;
	////string str6(str1);
	//string str5=str3;
	////assert(str5.size()==0);
	//printf("%s\n",str2);
	//printf("%s\n",str3.data());
	//str3=str2;
	//assert(str2.data()==tmp.data());
	//printf("%s\n",str3.data());
	//
	//printf("%s\n",str4.data());
	//printf("%s\n",str5.data());
	//printf("%c\n",str3.data()[2]);
	//assert(sizeof(str3.data()[2])==1);
	//printf("%s\n",str3.data());
	////printf("%s\n",str4[2]);
	

#ifdef WIN32
    system("pause");
#endif

	return 0;
}

