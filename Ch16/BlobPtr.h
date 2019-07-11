#pragma once
#include "Blob.h"
using std::weak_ptr;
using std::size_t;
template <typename> class BlobPtr;
template <typename T>
bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T>
bool operator<(const BlobPtr<T>&, const BlobPtr<T>&);
// BlobPtr throws an exception on attempts to access a nonexistent element
template <typename T> class BlobPtr {
	friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
	friend bool operator< <T>(const BlobPtr<T>&, const BlobPtr<T>&);
public:
	BlobPtr() : curr(0) { }
	BlobPtr(Blob<T> &a, size_t sz = 0) :
		wptr(a.data), curr(sz) { }
	T& operator*() const {
		auto p = check(curr, "dereference past end");
		return (*p)[curr]; // (*p) is the vector to which this object points
	}
	// increment and decrement
	BlobPtr& operator++(); // prefix operators
	BlobPtr& operator--();
	BlobPtr operator++(int); // prefix operators
	BlobPtr operator--(int);
private:
	// check returns a shared_ptr to the vector if the check succeeds
	shared_ptr<vector<T>> check(size_t, const string&) const;
	// store a weak_ptr, which means the underlying vector might be destroyed
	weak_ptr<vector<T>> wptr;
	size_t curr; // current position within the array
};
template <typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(size_t i, const string &msg) const {
	if (i >= wptr->size()) throw std::out_of_range(msg);
	return make_shared<vector<T>>(wptr);
}
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++() {
	check(curr, "increment out of range");
	++curr;
	return *this;
}
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--() {
	check(curr, "decrement out of range");
	--curr;
	return *this;
}
// postfix: increment/decrement the object but return the unchanged value
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
	// no check needed here; the call to prefix increment will do the check
	BlobPtr ret = *this; // save the current value
	++*this; // advance one element; prefix ++ checks the increment
	return ret; // return the saved state
}
template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int) {
	BlobPtr ret = *this;
	--*this;
	return ret;
}
template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	if (lhs.wptr.lock() != rhs.wptr.lock())
		throw runtime_error("ptrs to different Blobs!");
	return lhs.curr == rhs.curr;
}
template <typename T>
bool operator< (const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	if (lhs.wptr.lock() != rhs.wptr.lock())
		throw runtime_error("ptrs to different Blobs!");
	return lhs.curr < rhs.curr;
}