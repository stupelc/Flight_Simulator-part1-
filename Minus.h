
#ifndef PROGECT_MINUS_H
#define PROGECT_MINUS_H

#include "BinaryExpression.h"

/**
 * Minus Class -
 * present the expression of 'Minus'
 */
class Minus : public BinaryExpression{
public:

    /**
     *
     * @param leftExp the left expression
     * @param rightExp the right expression
     * build a minus expression with right and left side
     */
    Minus(Expression *leftExp, Expression *rightExp);

    /**
     *
     * @param symbolTable the table that contains all the variables
     * @return the calclation of the minus expression
     */
    double calculate() override;

    ~Minus();
};
#endif //PROGECT_MINUS_H
