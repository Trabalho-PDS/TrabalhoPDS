#include "../include/user.hpp"
#include "../include/user_monitor.hpp"

Monitor::Monitor(std::string id_user, std::string email, std::string name, std::string type) :
    User(id_user, email, name){
    _type = type;
}

std::string Monitor::Type(){
    return _type;
}