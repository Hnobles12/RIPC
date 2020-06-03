#ifndef NODE_SETUP_H
#define NODE_SETUP_H

#include <iostream>
#include <fstream>
#include <vector>
#include "node.hpp"
//Read Node list
//Start Pipes
//Wait for shutdown
class NodeSetup{
public:
    std::vector<std::string> names;
    int count;
    std::string workspace_path;
    std::vector<Node> nodes;

    NodeSetup(std::string wrkspc_dir);

private:
    void readNodes();
    std::vector<Node> setupPSNetwork();
    //void makePipes(); May move to separate node class

};

#endif