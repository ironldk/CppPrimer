// Define a pair of classes X and Y, in which X has a pointer to
// Y, and Y has an object of type X

#include "stdafx.h"

class Y;

class X {
	Y * y = nullptr;
};

class Y {
	X x;
};