#pragma once
#include "stdafx.h"
#include "String.h"
#include "StrVec.h"
#include "StrBlob.h"
void foo(String x){
	std::cout << x << std::endl;
}

void bar(const String& x){
	std::cout << x.c_str() << std::endl;
}

String baz(){
	String ret("world");
	return ret;
}
int main() {
	StrBlob sb{ "Hello", "World", "Pezy" };
	for (ConstStrBlobPtr iter = sb.cbegin(); iter != sb.cend(); iter.incr()) {
		std::cout << iter.deref() << " ";
	}
	std::cout << std::endl;

	StrVec vec;
	vec.reserve(6);
	std::cout << "capacity(reserve to 6): " << vec.capacity() << std::endl;

	vec.reserve(4);
	std::cout << "capacity(reserve to 4): " << vec.capacity() << std::endl;

	vec.push_back("hello");
	vec.push_back("world");

	vec.resize(4);

	for (auto i = vec.begin(); i != vec.end(); ++i)
		std::cout << *i << std::endl;
	std::cout << "-EOF-" << std::endl;

	vec.resize(1);

	for (auto i = vec.begin(); i != vec.end(); ++i)
		std::cout << *i << std::endl;
	std::cout << "-EOF-" << std::endl;

	StrVec vec_list{ "hello", "world", "pezy" };

	for (auto i = vec_list.begin(); i != vec_list.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	// Test operator==

	const StrVec const_vec_list{ "hello", "world", "pezy" };
	if (vec_list == const_vec_list)
		for (const auto& str : const_vec_list) std::cout << str << " ";
	std::cout << std::endl;

	char text[] = "world";

	String s0;
	String s1("hello");
	String s2(std::move(s0));
	String s3 = s1;
	String s4(text);
	s2 = s1;

	if (s2 == s1) std::cout << "s2 == s1" << std::endl;

	foo(s1);
	bar(s1);
	foo("temporary");
	bar("temporary");
	String s5 = baz();

	std::vector<String> svec;
	// svec.push_back(s0);
	svec.push_back(s1);
	svec.push_back(s2);
	svec.push_back(s3);
	svec.push_back(s4);
	svec.push_back(baz());
	svec.push_back("good job");

	for (const auto& s : svec) {
		std::cout << s << std::endl;
	}

	/*std::cout << "Input a string: ";
	String s6;
	std::cin >> s6;
	std::cout << s6 << std::endl;*/

	if ("i" > s1) std::cout << "s6 > s1" << std::endl;
	return 0;
}