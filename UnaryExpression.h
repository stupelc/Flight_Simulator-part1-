
#ifndef PROGECT_UNARYEXPRESSION_H
#define PROGECT_UNARYEXPRESSION_H

#include "Expression.h"

/**
 * UnaryExpression Class
 * present a unary expression with one element
 */
class UnaryExpression : public Expression {
protected:
    Expression *expression;

public:
    /**
     *
     * @param leftExp the expression in the left side
     * @param rightExp the expression in the right side
     */
    UnaryExpression(Expression *expression);

    Expression *getExpression() const;

    /**
     *
     * @param symbolTable the table has all the variables we can use at
     * @return the evaluate the expression using the variable values provided and return the result.
     */
    virtual double calculate(map<string,double> symbolTable) = 0;

};

#endif //PROGECT_UNARYEXPRESSION_H
