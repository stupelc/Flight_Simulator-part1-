//
// Created by chagit on 12/21/18.
//

#ifndef PROGECT_NEG_H
#define PROGECT_NEG_H

#include "UnaryExpression.h"
#include <map>

class Neg : public UnaryExpression {
public:
    /**
     *
     * @param expression the expression of neg
     */
    Neg(Expression *expression);

    /**
     *
     * @param symbolTable the table that contains all the variables in the programm
     * @return the calculation of the expression
     */
    double calculate() override;

    ~Neg();
};

#endif //PROGECT_NEG_H
