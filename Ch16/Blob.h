#pragma once
#include <initializer_list>
#include <string>
#include <vector>
#include <memory>
using std::initializer_list;
using std::string;
using std::vector;
using std::shared_ptr;
using std::make_shared;
// forward declarations needed for friend declarations in Blob
template <typename> class BlobPtr;
template <typename> class Blob; // needed for parameters in operator==
template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);
template <typename T> class Blob {
	// each instantiation of Blob grants access to the version of
	// BlobPtr and the equality operator instantiated with the same type
	friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
public:
	typedef T value_type;
	typedef typename vector<T>::size_type size_type;
	// constructors
	Blob();
	Blob(initializer_list<T> il);
	template <typename T> // type parameter for the class
	template <typename It> // type parameter for the constructor
	Blob<T>::Blob(It b, It e) :
		data(make_shared<vector<T>>(b, e)) { }
	// number of elements in the Blob
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	// add and remove elements
	void push_back(const T &t) { data->push_back(t); }
	// move version; see ¡ì 13.6.3 (p. 548)
	void push_back(T &&t) { data->push_back(std::move(t)); }
	void pop_back();
	// element access
	T& back();
	T& operator[](size_type i); // defined in ¡ì 14.5 (p. 566)
private:
	shared_ptr<vector<T>> data;
	// throws msg if data[i] isn't valid
	void check(size_type i, const string &msg) const;
};
template <typename T>
Blob<T>::Blob() : data(make_shared<vector<T>>()) { }
template <typename T>
Blob<T>::Blob(initializer_list<T> il) :
	data(make_shared<vector<T>>(il)) { }
template <typename T>
T& Blob<T>::back() {
	check(0, "back on empty Blob");
	return data->back();
}
template <typename T>
T& Blob<T>::operator[](size_type i) {
	// if i is too big, check will throw, preventing access to a nonexistent element
	check(i, "subscript out of range");
	return (*data)[i];
}
template <typename T>
void Blob<T>::pop_back() {
	check(0, "pop_back on empty Blob");
	data->pop_back();
}
template <typename T>
void Blob<T>::check(size_type i, const string &msg) const {
	if (i >= data->size())
		throw std::out_of_range(msg);
}
template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {
	return *lhs.data == *rhs.data;
}