#include "../include/user.hpp"

User::User(){}

// Constructor to inicialize the private name
User::User(std::string id_user, std::string email, std::string name){
    _name = name;
    _email = email;
    _id_user = id_user;
}

// Functions to see some data
std::string User::Email() const {
    return _email;
}

std::string User::Name() const {
    return _name;
}

std::string User::Id() const {
    return _id_user;
}
