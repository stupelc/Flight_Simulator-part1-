//
// Created by chagit on 12/24/18.
//

#include <iostream>
#include <sstream>
#include "PrintCommand.h"
#include "SymbolTable.h"

PrintCommand::PrintCommand() {
}

int PrintCommand::setParameters(vector<string> data, int index) {
    SymbolTable *symbolTab = SymbolTable::getInstance();
    this->isString = false;
    string str;
    //take the first and second
    //check if string
    if (data[index + 1].at(0) == '"') {
        this->printStr = data[index + 1].substr(1, data[index + 1].size() - 2);
        this->isString = true;
    } else {
        this->isString = false;
        //expression
        this->printStr = data[index + 1];
//        std::ostringstream strs;
//        strs << printExp->calculate();
//        std::string testStr = strs.str();

        //  this->printStr = testStr;
    }

    //read the command name and the var of it - num of time for sleeping
    return 2;
}

void PrintCommand::doCommand() {
    if (this->isString == false) {
        ExpressionDetect *expressionDetect;
        string str = putSpaces(this->printStr);
        Expression *printExp = expressionDetect->evaluate(str);
        cout << printExp->calculate() << endl;
    } else {
        cout << this->printStr << endl;
    }
}
