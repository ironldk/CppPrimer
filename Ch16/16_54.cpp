#include <iostream>
using std::cout;
using std::cin;
using std::endl;
//
//struct stringy {
//	char *str;
//	int len;
//};
//
//void set(stringy s, const char *cstr) {
//	int len;
//	for (len = 0; cstr[len] != '\0'; ++len);
//	s.str = new char[len];
//	for (int i = 0; i < len; ++i)
//		s.str[i] = cstr[i];
//	s.len = len;
//}
//
//void show(stringy s, int times = 1) {
//	for (int i = 0; i < times; ++i) {
//		cout << s.str << endl;
//	}
//}
//
//int main() {
//	char str[23] = { "hello ao;sdifj;aosdijf" };
//	stringy s = {str, 22};
//	set(s, "hello stringy!");
//	show(s, 3);
//	return 0;
//}

void set(char *c, char s) {
	c = new char;
	*c = s;
}

int main() {
	char* c = '\0';
	char s = 'k';
	set(c, s);
	cout << c;
	return 0;
}