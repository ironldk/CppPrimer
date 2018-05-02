#include<iostream>
int main()
{
    int i = 0, &r = i;
    auto a = r; // a is an int (r is an alias for i, which has type int)
    const int ci = i, &cr = ci;
    auto b = ci; // b is an int (top-level const in ci is dropped)
    auto c = cr; // c is an int (cr is an alias for ci whose const is top-level)
    auto d = &i; // d is an int*(& of an int object is int*)
    auto e = &ci; // e is const int*(& of a const object is low-level const)
    const auto f = ci; // deduced type of ci is int; f has type const int
    auto &g = ci; // g is a const int& that is bound to ci
    //auto &h = 42; // error: we can't bind a plain reference to a literal
    const auto &j = 42; // ok: we can bind a const reference to a literal
    std::cout << a << std::endl;
    a = 42;
    std::cout << a << std::endl;

    std::cout << b << std::endl;
    b = 42;
    std::cout << b << std::endl;

    std::cout << c << std::endl;
    c = 42;
    std::cout << c << std::endl;

    std::cout << d << std::endl;
    //d = 42;
    //std::cout << d << std::endl;

    std::cout << e << std::endl;
    //e = 42;
    //std::cout << e << std::endl;

    std::cout << g << std::endl;
    //g = 42;
    //std::cout << g << std::endl;

    return 0;
}
