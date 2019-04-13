
#include "UnaryExpression.h"

double UnaryExpression::calculate(map<string, double> symbolTable) {
    return 0;
}

Expression *UnaryExpression::getExpression() const {
    return this->expression;
}

UnaryExpression::UnaryExpression(Expression *expression) : expression(expression) {}
