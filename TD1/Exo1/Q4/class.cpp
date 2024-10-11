#include "class.h"
#include <iostream>

using namespace std;

my_class::my_class() {
    a = "Hello World2 !";
}

my_class::my_class(std::string str) {
    a = str;
}

void my_class::print_my_element() const {
    cout << a << endl;
}
