#include<iostream>
int main()
{
int a, b;
std::cout << "Enter two integers: ";
std::cin >> a >> b;
while(a < b)
{std::cout << a << std::endl;++a;}
while(a > b)
{std::cout << b << std::endl;++b;}
while(a == b)
{std::cout << a << std::endl; a=a+1;}
return 0;
}