
#include "BinaryExpression.h"

/**
 *
 * @return the right side of the exspression
 */
Expression *BinaryExpression::getRightExp() const {
    return this->rightExp;
}

/**
 *
 * @return te left side of the expression
 */
Expression *BinaryExpression::getLeftExp() const {
    return this->leftExp;
}

/**
 *
 * @param leftExp the left side of the expression
 * @param rightExp the right side of the expression
 * create a new expression with right and left side
 */
BinaryExpression::BinaryExpression(Expression *leftExp, Expression *rightExp) {
    this->leftExp = leftExp;
    this->rightExp = rightExp;
}
