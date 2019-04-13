//
// Created by almogg on 12/17/18.
//

#ifndef PROGECT_DIV_H
#define PROGECT_DIV_H

#include "BinaryExpression.h"

/**
 * Div Class -
 * present the expression of 'div'
 */
class Div : public BinaryExpression{
public:
    /**
     *
     * @param leftExp the left expression
     * @param rightExp the right expression
     * build a div expression with right and left side
     */
    Div(Expression *leftExp, Expression *rightExp);

    /**
     *
     * @param symbolTable the table that contains all the variables
     * @return the calclation of the div expression
     */
    double calculate() override;

    ~Div();
};

#endif //PROGECT_DIV_H
