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
	
	//��һ�ֹ��캯��
	string str1;
	assert(str1.size()==0);
	assert(*str1.data()=='\0');
	assert(!strcmp(str1.data(),""));

	//�ڶ��ֹ��캯��
	string str2("Hello world");//��const char* s����
	//assert(str2=="Hello world");//û�ж���==�����������������Ƚ�
	assert(!strcmp(str2.data(),"Hello world"));
	assert(!strcmp(str2.c_str(),"Hello world"));
	assert(str2.size()==11);

	string str5("");
	assert(str5.size()==0);
	assert(*str5.data()=='\0');
	assert(!strcmp(str5.data(),""));

	//�����ֹ��캯��
	string str4("Have you had dinner?",6);//��const char* s��size_t len����
	assert(!strcmp(str4.data(),"Have y"));
	assert(str4.size()==6);

	//�����ֹ��캯��
	string str3(str1);
	assert(str3.size()==0);
	assert(!strcmp(str3.data(),""));
	assert(!strcmp(str3.c_str(),""));
	assert(*str3.data()=='\0');
	assert(*str3.c_str()=='\0');
	
	string str6(str2);
	assert(str6.size()==11);
	assert(!strcmp(str6.data(),"Hello world"));
	assert(!strcmp(str6.c_str(),"Hello world"));

	//��ֵ������"="
	string str7=str1;
	assert(str7.size()==0);
	assert(!strcmp(str7.data(),""));
	assert(*str7.data()=='\0');

	string str8=str2;
	assert(str8.size()==11);
	assert(!strcmp(str8.data(),"Hello world"));
	assert(!strcmp(str8.c_str(),"Hello world"));

	//���Һ���
	assert(str2[2]=='l');//str2=="Hello world"

	printf("All tests passed!\n");

#ifdef WIN32
    system("pause");
#endif

	return 0;
}

