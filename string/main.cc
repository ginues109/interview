#include <stdio.h>
#include <stdlib.h>
#include "qh_string.h"
#include <assert.h>

using namespace qh;
int main(int argc, char* argv[])
{
    //TODO ��������ӵ�Ԫ���ԣ�Խ��Խ�ã�����·��������ԽȫԽ��
    //TODO ��Ԫ����д����ο�INIParser�Ǹ���Ŀ����Ҫдһ��printf��Ҫ��assert���ж����жϡ�
	//���ֹ��캯��
	string str1;
	string str2("Hello world");//��const char* s����
	string str3("Have you had dinner?",6);//��const char* s��size_t len����
	assert(str3.size()==6);
	string str4(str2);

	//string str5(str1);
	string str5=str3;
	//assert(str5.size()==0);
	printf("%s\n",str2.data());
	printf("%s\n",str3.data());
	str3=str2;
	printf("%s\n",str3.data());
	//
	printf("%s\n",str4.data());
	printf("%s\n",str5.data());
	printf("%c\n",str3.data()[2]);
	assert(sizeof(str3.data()[2])==1);
	printf("%s\n",str3.data());
	//printf("%s\n",str4[2]);
	

#ifdef WIN32
    system("pause");
#endif

	return 0;
}

