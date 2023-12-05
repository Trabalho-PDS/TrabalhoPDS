#include "../include/user.hpp"
#include "../include/user_student.hpp"

Student::Student(std::string id_user, std::string email, std::string name, std::string type) : 
    User(id_user, email, name){
        _type = type;
}

std::string Student::Type(){
    return _type;
}