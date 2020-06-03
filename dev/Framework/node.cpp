#include "node.hpp"

Node::Node(std::string name, std::vector<std::string> pubs, std::vector<std::string> subs, std::string workspace_path){
    Node::name = name;
    Node::publishers = pubs;
    Node::subscribers = subs;
    Node::workspace_path = workspace_path;

    //Create publisher pipes
    for (int i=0; i<Node::publishers.size(); i++){
        std::string pipe_name = Node::name + "_pub_" + Node::publishers[i];
        Node::pub_pipes.push_back(pipe_name);
        Node::makePipe(pipe_name);
    }
    //Create subscriber pipes
    for (int i=0; i<Node::subscribers.size(); i++){
        std::string pipe_name = Node::name + "_sub_" + Node::subscribers[i];
        Node::sub_pipes.push_back(pipe_name);
        Node::makePipe(pipe_name);
    }
    //Create Notification pipes
    for (int i=0; i<Node::subscribers.size(); i++){
        std::string pipe_name = Node::name + "_notif_" + Node::subscribers[i];
        Node::sub_pipes.push_back(pipe_name);
        Node::makePipe(pipe_name);
    }
    
}

Node::~Node(){
    //Cleanup all pipes
    for (int i=0; i<Node::pub_pipes.size(); i++){
        Node::removePipe(Node::pub_pipes[i]);
    }
    for (int i=0; i<Node::sub_pipes.size(); i++){
        Node::removePipe(Node::sub_pipes[i]);
    }
    for (int i=0; i<Node::notif_pipes.size(); i++){
        Node::removePipe(Node::notif_pipes[i]);
    }
}

void Node::makePipe(std::string name){
    std::string make_command = "mkfifo ";
    make_command = make_command + Node::workspace_path + name;
    system(make_command.c_str());
}

void Node::removePipe(std::string name){
    std::string remove_command = "rm -f ";
    remove_command = remove_command + Node::workspace_path + name;
    system(remove_command.c_str());
}