#include "ini_parser.h"
#include <iostream>
#include <assert.h>

void test1()
{
    const char* ini_text= "a=1\nb=2\n"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "\n", "=")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "");
	//std::cout<<c.data()<<std::endl;
}

void test2()
{
    const char* ini_text= "a=1||b=2||c=3"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", "=")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "3");
}

void test3()
{
    const char* ini_text= "||||a:1||b:2||||c:3||||||"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", ":")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "3");
}

void test4()
{
    const char* ini_text= "str1=this||str2=is||str3=me"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", "=")) {
        assert(false);
    }

    const std::string& str1 = parser.Get("str1", NULL);
    assert(str1 == "this");

    std::string b = parser.Get("str2", NULL);
    assert(b == "is");

    const std::string& c = parser.Get("str3", NULL);
    assert(c == "me");
}

void test5()
{
    const char* ini_text= "a=1&&b=&&c="; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "&&", "=")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "");
}

void test6()
{
    const std::string& ini_text= "test.txt";//读硬盘数据
    qh::INIParser parser;
    if (!parser.Parse(ini_text)) {
        assert(false);
    }

	if (!parser.Parse(parser.ini_data, strlen(parser.ini_data), "||", ":")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");
	
    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "");
	
	const std::string& hello = parser.Get("hello", NULL);
    assert(hello == "4");
}

void test7()
{
    const char* ini_text= "a=1&&b=&&c=&&"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "&&", "=")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "");
}

void test8()
{
    const std::string& ini_text= "a=1||b=2||isempty=false"; 
    qh::INIParser parser;

	const std::string& a = parser.Get(ini_text,"a", NULL);
    assert(a == "1");

    std::string b = parser.Get(ini_text,"b", NULL);
    assert(b == "2");

    const std::string& isempty = parser.Get(ini_text,"isempty", NULL);
    assert(isempty == "false");

	const std::string& empty = parser.Get(ini_text,"empty", NULL);
    assert(empty == "");
}

int main(int argc, char* argv[])
{
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好
	
    test1();//"a=1\nb=2\n"
    test2();//"a=1||b=2||c=3"
    test3();//"||||a:1||b:2||||c:3||||||"
	test4();//"str1=this||str2=is||str3=me"
	test5();//"a=1&&b=&&c="
	test6();//"||||a:1||b:2||||c:||||hello:4" from test.txt
	test7();//"a=1&&b=&&c=&&"
	test8();//"a=1||b=2||isempty=false"直接通过get获得value
	printf("All tests passed!\n");
    return 0;
}


