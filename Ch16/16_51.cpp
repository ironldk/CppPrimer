#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
// Args is a template parameter pack; rest is a function parameter pack
// Args represents zero or more template type parameters
// rest represents zero or more function parameters
template <typename T, typename... Args>
void foo(const T &t, const Args& ... rest) {
	cout << sizeof...(Args) << endl; // number of type parameters
	cout << sizeof...(rest) << endl; // number of function parameters
}
int main() {
	int i = 0; double d = 3.14; string s = "how now brown cow";
	foo(i, s, 42, d); // three parameters in the pack
	foo(s, 42, "hi"); // two parameters in the pack
	foo(d, s); // one parameter in the pack
	foo("hi"); // empty pack
	return 0;
}