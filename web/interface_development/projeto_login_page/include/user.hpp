#pragma once

#include <iostream>
#include <string.h>

class User {
    public:   
        User();
        User(std::string firstName, std::string secondName, std::string email, std::string id);

        std::string Email() const;
        std::string Name() const;
        std::string Id() const;


    private:
        void _mergeName (std::string& firstName, std::string& secondName);
        
        std::string _email;
        std::string _name;
        std::string _id_user;
};
