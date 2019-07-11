#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
template <typename C> void print1(const C &c) {
	for (typename C::size_type i = 0; i != c.size(); ++i) {
		cout << c[i] << " ";
	}
}
template <typename C> void print2(const C &c) {
	for (auto i = c.begin(); i != c.end(); ++i) {
		cout << *i << " ";
	}
}
int main() {
	std::vector<int> vec{ 2, 4, 6, 8, 7, 5, 3, 1 };
	print1(vec);
	print2(vec);
	return 0;
}