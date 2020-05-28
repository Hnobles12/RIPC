#include "master.hpp"
#include "exceptions.hpp"
#include <iostream>

int main(int argc,char **argv){
    try{
        if (argc < 2){
            throw NodeFilePathMissing();
        }

        



    }
    catch(NodeFilePathMissing err){
        err.message();
        return -1;
    }
    return 0;
}