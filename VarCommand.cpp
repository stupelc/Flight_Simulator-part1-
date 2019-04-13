//
// Created by almogg on 12/18/18.
//

#include <iostream>
#include <sstream>
#include "VarCommand.h"
#include "OtherFunctions.h"
#include "Expression.h"
#include "SymbolTable.h"
#include "equalsCommand.h"
#include "CommandExpression.h"

VarCommand::VarCommand() {
    this->isBind = false;
    this->isCommandExist = false;
}

int VarCommand::setParameters(vector<string> data, int index) {
    int newIndex = 0;
    string varName = "";
    ExpressionDetect *expressionDetect;
    //check if first is Var
    if (data[index] == "var") {
        //get the vector when index is on the string "var"
        //make share size is more then 4
        if ((index + 4) > data.size()) {
            throw "Not Enough Args!";
        }
        //second is the var name
        this->var = data[index + 1];
        string varPath = "";
        //third should be '='
        if (data[index + 2] != "=") {
            throw "Not Correct Argumnent";
        }

        //check if 'bind'
        if (data[index + 3] == "bind") {
            this->isBind = true;
            //take the string
            //make sure in the values
            if ((index + 5) > data.size()) {
                throw "Not Enoght Args!";
            }
            this->path = data[index + 4].substr(1, data[index + 4].size() - 2);

            newIndex = 5;
        } else {
            // this->isBind = false;
            //other var name
            double value;
            //if it can be an expression
            string val = putSpaces(data[index + 3]);
            Expression *valExp = expressionDetect->evaluate(val);

            this->val = valExp;

            //if it will be just name of var - it will take it from the map and return its value there
            //need to put its value in string value
            newIndex = 4;
        }
    } else {
        //start from the real var name
        //make share size is more then 3
        if ((index + 3) > data.size()) {
            throw "Not Enough Args!";
        }
        this->var = data[index];
        if (data[index + 1] != "=") {
            throw "Should be '=' here!";
        }
        //if it can be an expression
        this->valStr = data[index + 2];
        // this->valStr = putSpaces(this->valStr);

        string val = putSpaces(data[index + 2]);
        Expression *valExp = expressionDetect->evaluate(val);
        this->val = valExp;
        //take the expression value

        newIndex = 3;
    }
    return newIndex;
}

void VarCommand::doCommand() {
    SymbolTable *symbolTab = SymbolTable::getInstance();
    //update the maps and send a message to the simulator
    if (this->isBind) {

        //insert the var name with its path
        symbolTab->addPathToVar(this->var, this->path);
        this->isBind = false;
    } else {
        //check if the varName exist in the map 'var-path'
        if (symbolTab->isValExist(this->var)) {
            //need to send a mess to the server about the chaning
            Command *equalsComm = new equalsCommand();
            //this->listEqual.push_back(equalsComm);

            this->isCommandExist = true;

            vector<string> params;
            params.push_back(this->var);
            params.push_back(this->valStr);
            equalsComm->setParameters(params, 0);
            equalsComm->doCommand();

        } else {
            //update the symbol table
            symbolTab->addSymbolValue(this->var, this->val->calculate());
        }
    }

}

VarCommand::~VarCommand() {
    //if (this->isCommandExist) {
 //   delete (this->command);
    //}
//    for (list<Command *>::const_iterator it = this->listEqual.begin(); it != this->listEqual.end(); ++it) {
//        delete *it;
//    }

}
