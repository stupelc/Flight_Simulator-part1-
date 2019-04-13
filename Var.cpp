
#include <iostream>
#include "Var.h"
#include "SymbolTable.h"

const string &Var::getName() const {
    return this->name;
}

const string &Var::getPath() const {
    return this->path;
}

double Var::getValue() const {
    return this->value;
}

void Var::setName(const string &name) {
    Var::name = name;
}

void Var::setPath(const string &path) {
    Var::path = path;
}

void Var::setValue(double value) {
    Var::value = value;
}

double Var::calculate() {
    SymbolTable *symbolTable = SymbolTable::getInstance();
    //cout<<"in value calc"<<endl;
    return symbolTable->getValue(this->name);
}

Var::Var(const string &name, const string &path, double value) : name(name), path(path), value(value) {

}

Var::Var(const string &name) : name(name) {

}

Var::~Var() {

}