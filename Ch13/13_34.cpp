#include "stdafx.h"
#include "Message_Folder.h"
int main() {
	Message firstMail("hello");
	Message signInMail("welcome to cppprimer");
	Folder mailBox;

	//firstMail.print_debug(); // print: "hello"
	firstMail.save(mailBox); // send to mailBox
	//mailBox.print_debug();   // print: "hello"

	//signInMail.print_debug(); // print "welcome to cppprimer"
	signInMail.save(mailBox); // send to mailBox
	//mailBox.print_debug();    // print "welcome to cppprimer hello"

	firstMail = firstMail;   // test for assignment to self.
	//firstMail.print_debug(); // print "hello"
	//mailBox.print_debug();   // print "welcome to cppprimer hello"
	
	return 0;
}