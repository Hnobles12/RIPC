#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>
//#include <fstream>

class Node{
public:
    std::string name, workspace_path;
    std::vector<std::string> publishers, subscribers, pub_pipes, sub_pipes, notif_pipes;

    Node(std::string name, std::vector<std::string> pubs, std::vector<std::string> subs, std::string workspace_path);
    ~Node();
private:
    void makePipe(std::string name);
    void removePipe(std::string name);
};


#endif 