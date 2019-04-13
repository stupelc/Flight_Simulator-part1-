//
// Created by almogg on 12/24/18.
//

#include "IfCommand.h"
#include "CommandTable.h"
#include "OtherFunctions.h"
#include "ExpressionDetect.h"

int IfCommand::setParameters(vector<string> data, int index) {
    ExpressionDetect* expressionDetect;
    int newIndex = 5;
    string leftCondition = putSpaces(data[index + 1]);
    this->leftExp = expressionDetect->evaluate(leftCondition); //just make the expression and save it to member

    string rightCond = putSpaces(data[index + 3]);
    this->rightExp = expressionDetect->evaluate(rightCond); // just take the expression and save as member

    //save the condition
    this->condition = data[index + 2];

    newIndex += this->createCommands(data, index + 5);
    //create the loop command - create the vector of commands

    //take the expression value
    return newIndex;
}

void IfCommand::doCommand() {
    //do command just if condition true
    if (this->checkIfCondition()) {
        int i = 0;
        //do all the commands in the vector
        for (int i = 0; i < this->commands.size(); i++) {
            this->commands[i]->calculate(); //do the command
        }
    }
}

int IfCommand::createCommands(vector<string> data, int index) {
    CommandTable *commandTab = CommandTable::getInstance();
    map<string, Expression *> commandTable = commandTab->getTable();
    commandTab->setMapValues();

    commandTable = commandTab->getTable();
    int newIndex = index;

    //check its not the end of the if condition
    while (index < data.size() && data[index] != "}") {
        //add command to the command vector
        map<string, Expression *>::iterator it;
        //need to find the command
        it = commandTable.find(data[index]);
        CommandExpression *dataCommand;
        //check if exist
        if (it != commandTable.end()) {
            dataCommand = dynamic_cast<CommandExpression *>(it->second);
        } else {
            //its a var name
            //need to go to the VarCommand
            dataCommand = dynamic_cast<CommandExpression *>(commandTable.find("var")->second);
        }
        index += dataCommand->getCommand()->setParameters(data, index);
        //add the command to the vector of commands
        this->commands.push_back(dataCommand);

        commandTab->setMapValues();

        commandTable = commandTab->getTable();
    }
    //check if this is the '}'
    if (data[index] == "}") {
        index = index + 1;
    }
    newIndex = index - newIndex; //return the between old and new
    return newIndex;
}

bool IfCommand::checkIfCondition() {
    double leftVal = this->leftExp->calculate();
    double rightVal = this->rightExp->calculate();

    //check what is the condition
    if (this->condition == "==") {
        if (leftVal == rightVal) {
            return true;
        } else {
            return false;
        }
    } else if (this->condition == "<=") {
        if (leftVal <= rightVal) {
            return true;
        } else {
            return false;
        }

    } else if (this->condition == ">=") {
        if (leftVal >= rightVal) {
            return true;
        } else {
            return false;
        }
    } else if (this->condition == "!=") {
        if (leftVal != rightVal) {
            return true;
        } else {
            return false;
        }
    } else if (this->condition == "<") {
        if (leftVal < rightVal) {
            return true;
        } else {
            return false;
        }
    } else if (this->condition == ">") {
        if (leftVal > rightVal) {
            return true;
        } else {
            return false;
        }
    }
}

IfCommand::~IfCommand() {

}