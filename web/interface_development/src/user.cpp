#include "../include/user.hpp"

User::User(){}

// Constructor to inicialize the private name
User::User(std::string firstName, std::string secondName, std::string email, std::string id){
    User::_mergeName(firstName, secondName);
    _email = email;
    _id_user = id;
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


// Treat and merge name and surname
void User::_mergeName
(std::string& firstName, std::string& secondName){
    if (!firstName.empty()) {
        firstName[0] = std::toupper(firstName[0]);
        for (int i = 1; i < firstName.size(); ++i) {
            firstName[i] = std::tolower(firstName[i]);
        }
    }

    if (!secondName.empty()) {
        secondName[0] = std::toupper(secondName[0]);
        for (int j = 1; j < secondName.size(); ++j) {
            secondName[j] = std::tolower(secondName[j]);
        }
    }

    _name = firstName + " " + secondName;
}
