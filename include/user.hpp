#pragma once

#include <iostream>
#include <string.h>

class User {
    public:
        bool isEmail(std::string email);
        bool isPassword(std::string password);
        void changeEmail(const std::string &email);

        std::string seeEmail() const;
        std::string seeName() const;

        void mergeName (std::string& firstName, std::string& secondName);

    private:
        std::string _email;
        std::string _name;
};
