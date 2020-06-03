#ifndef RPCC_H
#define RPCC_H

#include <string>
#include <vector>

//Publisher Class
class Publisher{
public:
    std::string = name, node, workspace_path;

    Publisher(std::string pub_name, std::string node_name, std::string workspace_dir){
        name = pub_name;
        node = node_name;
        workspace_path = workspace_dir;
    }

    void publish(auto data){

    }

};


//Subscriber Class
class Subscriber{
    Subscriber();
};
#endif