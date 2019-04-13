
#include "Minus.h"

/**
 *
 * @param symbolTable the table that contains all the variables
 * @return the calclation of the minus expression
 */
double Minus::calculate() {
    return (this->getLeftExp()->calculate() - this->getRightExp()->calculate());
}

/**
 *
 * @param leftExp the left expression
 * @param rightExp the right expression
 * build a minus expression with right and left side
 */
Minus::Minus(Expression *leftExp, Expression *rightExp) : BinaryExpression(leftExp, rightExp) {}

Minus::~Minus() {

}