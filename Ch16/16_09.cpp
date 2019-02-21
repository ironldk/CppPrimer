#include "Blob.h"
int main() {
	Blob<int> ia; // empty Blob<int>
	Blob<int> ia2 = { 0,1,2,3,4 }; // Blob<int> with five elements
	// these definitions instantiate two distinct Blob types
	Blob<string> names; // Blob that holds strings
	Blob<double> prices;// different element type
	Blob<string> articles = { "a", "an", "the" };
	//instantiates Blob<int> and the initializer_list<int> constructor
	Blob<int> squares = { 0,1,2,3,4,5,6,7,8,9 };
	// instantiates Blob<int>::size() const
	for (size_t i = 0; i != squares.size(); ++i)
		squares[i] = i * i; // instantiates Blob<int>::operator[](size_t)
}