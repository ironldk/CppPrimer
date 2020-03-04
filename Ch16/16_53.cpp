#include <iostream>
#include <sstream>
#include <string>
using std::string;
using std::ostream;
using std::ostringstream;
using std::cout;
using std::endl;
template<typename T> string debug_rep(const T& t) {
	ostringstream ret;
	ret << t;
	return ret.str();
}
template<typename T> string debug_rep(T* p) {
	ostringstream ret;
	ret << "pointer: " << p;
	if (p)
		ret << " " << debug_rep(*p);
	else
		ret << " null pointer";
	return ret.str();
}

// function to end the recursion and print the last element
// this function must be declared before the variadic version of print is defined
template<typename T>
ostream &print(ostream &os, const T &t) {
	return os << t; // no separator after the last element in the pack
}

// this version of print will be called for all but the last element in the pack
template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args&... rest) {
	os << t << ", "; // print the first argument
	return print(os, rest...); // recursive call; print the other arguments
}

// call debug_rep on each argument in the call to print
template <typename... Args>
ostream &errorMsg(ostream &os, const Args&... rest) {
	// print(os, debug_rep(a1), debug_rep(a2), ..., debug_rep(an)
	return print(os, debug_rep(rest)...);
}

int main() {
	int i = 1; string s = "hello"; double d = 3.14; char a[8] = { " world!" };
	print(cout, i, s); cout << endl;
	print(cout, i, s, 42); cout << endl;
	print(cout, i, s, 42, d, "hello", a); cout << endl;
	return 0;
}