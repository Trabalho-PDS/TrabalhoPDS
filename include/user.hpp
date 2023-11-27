#pragma once

#include <iostream>
#include <string.h>

class User {
    public:   
        User(std::string& firstName, std::string& secondName, std::string &email, std::string &password);
        User();
           
        bool isEmail(std::string email);
        bool isPassword(std::string password);

        void changeEmail(const std::string &newEmail);
        void changePassword(const std::string &newPassword);

        std::string seeEmail() const;
        std::string seeName() const;
        std::string seePassword() const;


    private:
        void _mergeName (std::string& firstName, std::string& secondName);
        
        std::string _email;
        std::string _name;
        std::string _password;
        std::string _id_user;
};
