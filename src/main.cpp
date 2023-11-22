#include <iostream>
#include <string>
#include "user.cpp"

int main (){
    std::string input_email, input_name, input_surname;
    
    std::cin >> input_email;

    User user(input_name, input_surname);
    user.changeEmail(input_email);

    while(!user.isEmail(input_email)) {
        std::cout << "Insira um email válido" << std::endl;
        std::cin >> input_email;
        user.changeEmail(input_email);
    }

    std::cin >> input_name;
    std::cin >> input_surname;

    std::cout << user.seeEmail() << std::endl;
    std::cout<< user.seeName() << std::endl;
    return 0;
}