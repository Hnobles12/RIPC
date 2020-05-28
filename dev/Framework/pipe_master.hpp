#ifndef PIPE_MASTER_H
#define PIPE_MASTER_H

#include <iostream>
#include <fstream>
#include <vector>
//Read Node list
//Start Pipes
//Wait for shutdown

void nodeSetup(std::string path){
    std::ifstream nodefile(path);
    std::string node_name;
    std::vector<std::string> nodes;
    
    while (!nodefile.eof()){
        getline(nodefile, node_name);
        nodes.push_back(node_name);
    }


}
#endif