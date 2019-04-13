
#include "Number.h"

/**
 *
 * @param value a double variable
 * build a new Number
 */
Number::Number(double value) : value(value) {}

/**
 *
 * @param symbolTable a table that consist all the variables in the map
 * @return the value of the number
 */
double Number::calculate() {
    return this->value;
}

Number::~Number() {

}
