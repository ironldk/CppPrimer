#include <iostream>
using std::cout;
using std::cin;
using std::endl;
//
//struct stringy {
//	char *str;
//	int len;
//};
//
//void set(stringy s, const char *cstr) {
//	int len;
//	for (len = 0; cstr[len] != '\0'; ++len);
//	s.str = new char[len];
//	for (int i = 0; i < len; ++i)
//		s.str[i] = cstr[i];
//	s.len = len;
//}
//
//void show(stringy s, int times = 1) {
//	for (int i = 0; i < times; ++i) {
//		cout << s.str << endl;
//	}
//}
//
//int main() {
//	char str[23] = { "hello ao;sdifj;aosdijf" };
//	stringy s = {str, 22};
//	set(s, "hello stringy!");
//	show(s, 3);
//	return 0;
//}

//void set(char *c, char s) {
//	c = new char;
//	*c = s;
//}
//
//int main() {
//	char* c = '\0';
//	char s = 'k';
//	set(c, s);
//	cout << c;
//	return 0;
//}
#include <string>
#include <vector>
#include <io.h>
#include <stdio.h>

using std::string;
using std::vector;

std::vector<string> vec;

void findfile(string path, string mode) {
	_finddata_t file;
	intptr_t HANDLE;
	string Onepath = path + mode;
	HANDLE = _findfirst(Onepath.c_str(), &file);
	if (HANDLE == -1L)
	{
		cout << "can not match the folder path" << endl;
		system("pause");
	}
	do {
		//判断是否有子目录  
		if (file.attrib & _A_SUBDIR)
		{
			//判断是否为"."当前目录，".."上一层目录
			if ((strcmp(file.name, ".") != 0) && (strcmp(file.name, "..") != 0))
			{
				string newPath = path + "\\" + file.name;
				findfile(newPath, mode);
			}
		}
		else
		{
			cout << file.name << " " << endl;
			/*if (string::npos != string(file.name).substr())*/ {
				vec.push_back(string(file.name));
			}
		}
	} while (_findnext(HANDLE, &file) == 0);
	_findclose(HANDLE);
}

int main(int argc, char** argv) {
	string mode = "\\*.*";
	string path = "E:\\Movie";
	findfile(path, mode);
	cout << endl;
	for (auto item : vec) {
		cout << item << endl;
	}
	system("pause");
	return 0;
}