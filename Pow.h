//
// Created by almogg on 12/17/18.
//

#ifndef PROGECT_POW_H
#define PROGECT_POW_H

#include "BinaryExpression.h"

class Pow : public BinaryExpression{
public:
    double calculate() override;

public:
    Pow(Expression *leftExp, Expression *rightExp);
    ~Pow();
};
#endif //PROGECT_POW_H
