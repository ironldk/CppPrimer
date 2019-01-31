#include<iostream>
#include<typeinfo>
int main()
{
    std::cout << typeid('a').name() << '\t'
              << typeid(L'a').name() << '\t'
              << typeid("a").name() << '\t'
              << typeid(L"a").name() << std::endl;
    std::cout << typeid(10).name() << '\t'
              << typeid(10u).name() << '\t'
              << typeid(10L).name() << '\t'
              << typeid(10uL).name() << '\t'
              << typeid(012).name() << '\t'
              << typeid(0xC).name() << std::endl;
    std::cout << typeid(3.14).name() << '\t'
              << typeid(3.14f).name() << '\t'
              << typeid(3.14L).name() << std::endl;
    std::cout << typeid(10).name() << '\t'
              << typeid(10u).name() << '\t'
              << typeid(10.).name() << '\t'
              << typeid(10e-2).name() << std::endl;
    return 0;
}
