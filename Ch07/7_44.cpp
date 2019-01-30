#include "stdafx.h"
#include <vector>
using std::vector;

class NoDefault {
public:
	NoDefault(int i) {}
};

class C {
public:
	C(): n(1) {}
private:
	NoDefault n;
};

int main() {
	C c;
	vector<C> vec(10);
	return 0;
}