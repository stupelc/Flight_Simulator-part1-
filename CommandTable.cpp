
#include "CommandTable.h"
#include "OpenDataServer.h"
#include "VarCommand.h"
#include "ConnectCommand.h"
#include "CommandExpression.h"
#include "LoopCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "IfCommand.h"

#define OPEN_DATA_SERVER "openDataServer"
#define CONNECT "connect"
#define VAR "var"
#define WHILE "while"
#define PRINT "print"
#define SLEEP "sleep"
#define IF "if"
#define EXIT "exit"

CommandTable *CommandTable::instance = nullptr;

/**
 * Constructor
 * saves all the commands that we create
 */
CommandTable::CommandTable() {
    this->commandTable.insert(
            pair<string, Expression *>(OPEN_DATA_SERVER, new CommandExpression(new OpenDataServer())));
    this->allExp.push_back(this->commandTable[OPEN_DATA_SERVER]);
    this->commandTable.insert(pair<string, Expression *>(CONNECT, new CommandExpression(new ConnectCommand())));
    this->allExp.push_back(this->commandTable[CONNECT]);
    this->commandTable.insert(pair<string, Expression *>(VAR, new CommandExpression(new VarCommand())));
    this->allExp.push_back(this->commandTable[VAR]);
    this->commandTable.insert(pair<string, Expression *>(WHILE, new CommandExpression(new LoopCommand())));
    this->allExp.push_back(this->commandTable[WHILE]);
    this->commandTable.insert(pair<string, Expression *>(PRINT, new CommandExpression(new PrintCommand())));
    this->allExp.push_back(this->commandTable[PRINT]);
    this->commandTable.insert(pair<string, Expression *>(SLEEP, new CommandExpression(new SleepCommand())));
    this->allExp.push_back(this->commandTable[SLEEP]);
    this->commandTable.insert(pair<string, Expression *>(IF, new CommandExpression(new IfCommand())));
    this->allExp.push_back(this->commandTable[IF]);
}

/**
 * set the values of the map and put them in the vec of all experession
 */
void CommandTable::setMapValues() {
    this->commandTable[VAR] = new CommandExpression(new VarCommand());
    this->allExp.push_back(this->commandTable[VAR]);
    this->commandTable[IF] = new CommandExpression(new IfCommand());
    this->allExp.push_back(this->commandTable[IF]);
    this->commandTable[WHILE] = new CommandExpression(new LoopCommand());
    this->allExp.push_back(this->commandTable[WHILE]);
    this->commandTable[PRINT] = new CommandExpression(new PrintCommand());
    this->allExp.push_back(this->commandTable[PRINT]);
    this->commandTable[SLEEP] = new CommandExpression(new SleepCommand());
    this->allExp.push_back(this->commandTable[SLEEP]);
}

/**
 *
 * @param commandName the name of the command
 * @param exp the data of the command
 */
void CommandTable::addValue(string commandName, Expression *exp) {
    //check if already in map - change its value
    //else- insert as pair
    map<string, Expression *>::iterator it;
    it = this->commandTable.find(commandName);

    if (it != this->commandTable.end()) {
        //exist - need to update the value
        this->commandTable[commandName] = exp;
    } else {
        //if not exist - need to add the pair
        this->commandTable.insert(pair<string, Expression *>(commandName, exp));
    }
}

/**
 *
 * @return the table with all the vars that we have - if its the first time creates the table
 */
CommandTable *CommandTable::getInstance() {
    //if null - create new one
    if (instance == nullptr) {
        instance = new CommandTable();
    }
    return instance;
}

/**
 * destructor
 */
CommandTable::~CommandTable() {
    //delte all expressions
    if (this->allExp.empty() == false) {
        for (auto &&exp : this->allExp) {
            delete exp;
        }
    }
    delete instance;
}

/**
 *
 * @return the command table
 */
map<string, Expression *> CommandTable::getTable() {
    return this->commandTable;
}