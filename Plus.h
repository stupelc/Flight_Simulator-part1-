
#ifndef PROGECT_PLUS_H
#define PROGECT_PLUS_H

#include "BinaryExpression.h"

/**
 * Plus Class -
 * present the expression of 'plus'
 */
class Plus : public BinaryExpression {
public:
/**
     *
     * @param leftExp the left expression
     * @param rightExp the right expression
     * build a plus expression with right and left side
     */
    Plus(Expression *leftExp, Expression *rightExp);

    /**
     *
     * @param symbolTable the table that contains all the variables
     * @return the calclation of the plus expression
     */
    double calculate() override;

    ~Plus();
};

#endif //PROGECT_PLUS_H
