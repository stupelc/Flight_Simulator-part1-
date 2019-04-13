//
// Created by almogg on 12/17/18.
//

#ifndef PROGECT_MULT_H
#define PROGECT_MULT_H

#include "BinaryExpression.h"

/**
 * Mult Class -
 * present the expression of 'mult'
 */
class Mult : public BinaryExpression{
public:

    /**
     *
     * @param leftExp the left expression
     * @param rightExp the right expression
     * build a mult expression with right and left side
     */
    Mult(Expression *leftExp, Expression *rightExp);

    /**
     *
     * @param symbolTable the table that contains all the variables
     * @return the calclation of the mult expression
     */
    double calculate() override;

    ~Mult();
};
#endif //PROGECT_MULT_H
