//Exercise 14.34: Define a function - object class to perform an if - then - else
//operation : The call operator for this class should take three parameters.It
//should test its first parameter and if that test succeeds, it should return its
//second parameter; otherwise, it should return its third parameter.

#include "stdafx.h"

class if_then_else {
	int operator()(bool flag, int first, int second) {
		return flag ? first : second;
	}
};
