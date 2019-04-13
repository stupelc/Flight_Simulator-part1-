
#ifndef PROGECT_VAR_H
#define PROGECT_VAR_H

#include "string"
#include "Expression.h"

using namespace std;

/**
 * Var Class -
 * present a variables
 */
class Var : public Expression {
private:
    string name;
    string path;
    double value;
public:
    Var(const string &name, const string &path, double value);

    explicit Var(const string &name);

    void setName(const string &name);

    void setPath(const string &path);

    void setValue(double value);

    const string &getName() const;

    const string &getPath() const;

    double getValue() const;

    double calculate() override;

    ~Var();
};

#endif //PROGECT_VAR_H
