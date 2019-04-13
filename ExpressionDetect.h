//
// Created by chagit on 12/17/18.
//

#ifndef PROGECT_EXPRESSIONDETECT_H
#define PROGECT_EXPRESSIONDETECT_H

#include <list>
#include <vector>
#include "ExpressionHeaders.h"
#include "OtherFunctions.h"

class ExpressionDetect {
    list<Plus *> listOfPlus = list<Plus *>();
    list<Minus *> listOfMinus = list<Minus *>();
    list<Mult *> listOfMult = list<Mult *>();
    list<Div *> listOfDiv = list<Div *>();
    list<Number *> listOfNumber = list<Number *>();
    list<Var *> listOfVars = list<Var *>();
    vector<Expression*>toDelete;


public:
    ExpressionDetect();

    Expression *applyOp(Expression *a, Expression *b, char op);

    int precedence(char op);

    Expression *evaluate(string tokens);

    virtual ~ExpressionDetect();


};


#endif //PROGECT_EXPRESSIONDETECT_H
