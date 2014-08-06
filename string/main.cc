#include <stdio.h>
#include <stdlib.h>
#include "qh_string.h"
#include <assert.h>
#include <string>

using namespace qh;
int main(int argc, char* argv[])
{
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好
    //TODO 单元测试写法请参考INIParser那个项目，不要写一堆printf，要用assert进行断言判断。
	
	//第一种构造函数
	string str1;
	assert(str1.size()==0);
	assert(*str1.data()=='\0');
	assert(!strcmp(str1.data(),""));

	//第二种构造函数
	string str2("Hello world");//用const char* s构造
	//assert(str2=="Hello world");//没有定义==操作符，不能这样比较
	assert(!strcmp(str2.data(),"Hello world"));
	assert(!strcmp(str2.c_str(),"Hello world"));
	assert(str2.size()==11);

	string str5("");
	assert(str5.size()==0);
	assert(*str5.data()=='\0');
	assert(!strcmp(str5.data(),""));

	//第三种构造函数
	string str4("Have you had dinner?",6);//用const char* s和size_t len构造
	assert(!strcmp(str4.data(),"Have y"));
	assert(str4.size()==6);

	//第四种构造函数
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

	//赋值操作符"="
	string str7=str1;
	assert(str7.size()==0);
	assert(!strcmp(str7.data(),""));
	assert(*str7.data()=='\0');

	string str8=str2;
	assert(str8.size()==11);
	assert(!strcmp(str8.data(),"Hello world"));
	assert(!strcmp(str8.c_str(),"Hello world"));

	//查找函数
	assert(str2[2]=='l');//str2=="Hello world"

	printf("All tests passed!\n");

#ifdef WIN32
    system("pause");
#endif

	return 0;
}

