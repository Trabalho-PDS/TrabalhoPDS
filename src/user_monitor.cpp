#include "../include/user.hpp"
#include "../include/user_monitor.hpp"

Monitor::Monitor(){
    _numberOfEvaluations = 0;
    _starRange = 0;
};


void Monitor::calculateStars (int newEvaluation){
    _numberOfEvaluations++;
    _starRange = (_starRange + (double)(newEvaluation))/_numberOfEvaluations;
}


void Monitor::choseFields(std::string field){
    _fields.push_back(field);
}


void Monitor::seeFields(){
    for (auto it : _fields){
        std::cout << it << std::endl;
    }
}


double Monitor::seeStars (){
    return _starRange;
}
