#include "node_setup.hpp"
#include "node.hpp"

#include <fstream>
#include <vector>

NodeSetup::NodeSetup(std::string wrkspc_dir){
    NodeSetup::workspace_path = wrkspc_dir;
}
void NodeSetup::readNodes(){
    std::ifstream file(workspace_path+"/nodes.rpcc");
    std::string name;

    while (!file.eof()){
        getline(file, name);
        NodeSetup::names.push_back(name);
    }
    NodeSetup::count = NodeSetup::names.size();
}
void NodeSetup::setupPSNetwork(){
    std::vector<std::string> publishers, subscribers;
    for (int i=0; i < NodeSetup::count; i++){
        std::ifstream pub_file(NodeSetup::workspace_path+"/"+NodeSetup::names[i]+"_pub.rpcc");
        while(!pub_file.eof()){
            std::string pub_data;
            getline(pub_file, pub_data);
            publishers.push_back(pub_data);
        }
        std::ifstream sub_file(NodeSetup::workspace_path+"/"+NodeSetup::names[i]+"_sub.rpcc");
        while(!sub_file.eof()){
            std::string sub_data;
            getline(sub_file, sub_data);
            subscribers.push_back(sub_data);
        }
        Node node_obj(NodeSetup::names[i], publishers, subscribers, NodeSetup::workspace_path);
        NodeSetup::nodes.push_back(node_obj);
    }
}
