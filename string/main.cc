#include <stdio.h>
#include <stdlib.h>
#include "qh_string.h"
#include <assert.h>

using namespace qh;
int main(int argc, char* argv[])
{
    //TODO ��������ӵ�Ԫ���ԣ�Խ��Խ�ã�����·��������ԽȫԽ��
    //TODO ��Ԫ����д����ο�INIParser�Ǹ���Ŀ����Ҫдһ��printf��Ҫ��assert���ж����жϡ�
	string str1;
	string str2="Hello world";
	string str3="This is the initialized String 3";
	printf(str2.data());
	printf(str3.data());
	str3=str2;
	printf(str3.data());
	//assert(str3.size()==1);
	printf("%s",str3[2]);
	printf(str3.data());
	

#ifdef WIN32
    system("pause");
#endif

	return 0;
}

