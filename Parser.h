//
// Created by almogg on 12/18/18.
//

#ifndef PROGECT_PARSER_H
#define PROGECT_PARSER_H

#include "Command.h"
#include "Expression.h"
#include <map>
#include <string>
#include <vector>

using namespace std;

class Parser {
    map<string, Expression*> commandTable;
public:
    Parser();
    ~Parser();
    void parser(vector<string> data);
};

#endif //PROGECT_PARSER_H
