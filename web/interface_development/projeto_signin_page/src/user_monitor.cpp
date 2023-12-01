#include "../include/user.hpp"
#include "../include/user_monitor.hpp"

Monitor::Monitor(){};

Monitor::Monitor(std::string firstName, std::string secondName, std::string email, std::string id) :
    User(firstName, secondName, email, id){
    _numberOfEvaluations = 0;
    _starRange = 0;
};

void Monitor::calculateStars (int newGrade){
    _numberOfEvaluations++;
    _starRange = (_starRange + (double)(newGrade))/_numberOfEvaluations;
}


double Monitor::seeStars (){
    return _starRange;
}