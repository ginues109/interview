#include <stdio.h>
#include <stdlib.h>
#include "qh_string.h"
#include <assert.h>

using namespace qh;
int main(int argc, char* argv[])
{
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好
    //TODO 单元测试写法请参考INIParser那个项目，不要写一堆printf，要用assert进行断言判断。
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

