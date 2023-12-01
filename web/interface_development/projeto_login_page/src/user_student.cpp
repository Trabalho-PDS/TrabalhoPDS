#include "../include/user.hpp"
#include "../include/user_student.hpp"

Student::Student(){};

Student::Student(std::string firstName, std::string secondName, std::string email, std::string id) : 
    User(firstName, secondName, email, id){};