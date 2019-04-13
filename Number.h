
#ifndef PROGECT_NUMBER_H
#define PROGECT_NUMBER_H

#include "Expression.h"

/**
 * Number Class -
 * present the type 'NUmber'
 */
class Number : public Expression {
private:
    double value;
public:
    /**
     *
     * @param value a double variable
     * build a new Number
     */
    explicit Number(double value);

    /**
     *
     * @param symbolTable a table that consist all the variables in the map
     * @return the value of the number
     */
    double calculate() override;

    ~Number();
};

#endif //PROGECT_NUMBER_H
