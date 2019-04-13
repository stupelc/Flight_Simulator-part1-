//
// Created by almogg on 12/17/18.
//

#include "Pow.h"
#include <cmath>
Pow::Pow(Expression *leftExp, Expression *rightExp) : BinaryExpression(leftExp, rightExp) {}

double Pow::calculate() {
    return (pow(this->getLeftExp()->calculate(),this->getRightExp()->calculate()));
}

Pow::~Pow() {

}