
#ifndef PROGECT_BINARYEXPRESSION_H
#define PROGECT_BINARYEXPRESSION_H

#include "Expression.h"

/**
 * BinaryExpression Class
 * present a binary expression with right and left side
 */
class BinaryExpression : public Expression {
protected:
    Expression *leftExp;
    Expression *rightExp;
public:
    /**
     *
     * @param leftExp the expression in the left side
     * @param rightExp the expression in the right side
     */
    BinaryExpression(Expression *leftExp, Expression *rightExp);

    Expression *getLeftExp() const;
    Expression *getRightExp() const;

    /**
     *
     * @param symbolTable the table has all the variables we can use at
     * @return the evaluate the expression using the variable values provided and return the result.
     */
    virtual double calculate() = 0;

};

#endif //PROGECT_BINARYEXPRESSION_H
