#include "../include/user.hpp"

std::string emailDomain[9] =
    {"@ufmg", "@dcc", "@gmail","@hotmail", "@yahoo", "@outlook", "@iCloud", "@mac", "@me"};

bool User::isEmail(std::string email){
    _email = email;
    for (int i=0; i<9; i++) {
        if (email.find(emailDomain[i]) != std::string::npos) return true;
    }
    return false;
};


bool User::isPassword(std::string password){
    if(password == ""){
        std::cout << "A senha não pode ser vazia" << std::endl;
        return false;
    }
    if(password.size() < 8) {
        std::cout << "Sua senha deve conter pelo menos 8 caracteres" << std::endl;
        return false;
    }
    int digits = 0, alphas = 0;
    for(int it = 0; it < password.size(); ++it){
            if(isdigit(password[it])) digits++;
            if(isalpha(password[it])) alphas++;
    }
    if(digits < 2){
        std::cout << "Sua senha deve conter pelo menos 2 dígitos" << std::endl;
        return false;
    }
    if(alphas < 2){
        std::cout << "Sua senha deve conter pelo menos 2 letras" << std::endl;
        return false;
    }
    return true;
};


void User::changeEmail(const std::string& newEmail){
    _email = newEmail;
}

std::string User::seeEmail() const {
    return _email;
}

std::string User::seeName() const {
    return _name;
}

void User::mergeName
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
