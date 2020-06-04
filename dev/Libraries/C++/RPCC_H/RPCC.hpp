#ifndef RPCC_H
#define RPCC_H

#include <string>
#include <vector>

//Publisher Class
class Publisher{
public:
    std::string name, node, workspace_path;

    Publisher(std::string pub_name, std::string node_name, std::string workspace_dir){
        name = pub_name;
        node = node_name;
        workspace_path = workspace_dir;
    }

    void notify_all(){
        //send notification to notification pipes
    }
    void publish_string(std::string data){

    }
    void publish_int(int data){
        //Publish integer 

    }
    void publish_double(double data){

    }
    void publish_bool(bool data){

    }
    void publish_vector_int(std::vector<int> data){

    }
    void publish_vector_double(std::vector<int> data){

    }

};


//Subscriber Class
class Subscriber{
    Subscriber();
};
#endif