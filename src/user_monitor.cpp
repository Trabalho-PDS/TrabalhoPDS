#include "../include/user.hpp"
#include "../include/user_monitor.hpp"

Monitor::Monitor(){
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