#ifndef NODE_H
#define NODE_H

#include <vector>
#include <fstream>

class Node{
public:
    std::string name;
    Node(std::string name, std::vector<std::string> pubs, std::vector<std::string> subs);
};


#endif