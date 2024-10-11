#pragma once
#include <string>

class my_class {
private:
    std::string a;

public:
    my_class();
    my_class(std::string str);
    void print_my_element() const;
};
