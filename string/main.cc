#include <stdio.h>
#include <stdlib.h>
#include "qh_string.h"
#include <assert.h>

using namespace qh;
int main(int argc, char* argv[])
{
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好
    //TODO 单元测试写法请参考INIParser那个项目，不要写一堆printf，要用assert进行断言判断。
	//四种构造函数
	string str1;
	string str2("Hello world");//用const char* s构造
	string str3("Have you had dinner?",6);//用const char* s和size_t len构造
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

