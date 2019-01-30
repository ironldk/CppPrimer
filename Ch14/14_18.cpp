#pragma once
#include "stdafx.h"
#include "..\..\CppPrimerRepo\Ch13\String.h"
#include "..\..\CppPrimerRepo\Ch13\StrVec.h"
#include "..\..\CppPrimerRepo\Ch13\StrBlob.h"
void foo(String x) {
	std::cout << x << std::endl;
}

void bar(const String& x) {
	std::cout << x.c_str() << std::endl;
}

String baz() {
	String ret("world");
	return ret;
}
int main() {
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

	StrBlob sb1{ "a", "b", "c" };
	StrBlob sb2{ "a", "b", "b" };

	if (sb1 > sb2) {
		for (ConstStrBlobPtr iter = sb1.cbegin(); iter < sb1.cend();
			iter.incr())
			std::cout << iter.deref() << " ";
		std::cout << std::endl;
	}
	return 0;
}