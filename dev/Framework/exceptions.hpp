#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>

class NodeFilePathMissing{
public:
    void message(){
        std::cout << "Error: Node structure file path missing" << std::endl;
    }
};

#endif