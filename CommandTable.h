
#ifndef PROGECT_COMMANDTABLE_H
#define PROGECT_COMMANDTABLE_H
#include <map>
#include <string>
#include "CommandExpression.h"
#include "LoopCommand.h"

using namespace std;

/**
 * CommandTable Class
 *
 */
class CommandTable {
private:
    static CommandTable *instance;
    map<string, Expression*> commandTable;
    vector<Expression*> allExp;

public:

    /**
     * Constructor
     * saves all the commands that we create
     */
    CommandTable();

    /**
     * destructor
     */
    ~CommandTable();

    /**
     *
     * @return the table witch contains all the variables
     */
    static CommandTable *getInstance();

    /**
    *
    * @param commandName the name of the command
    * @param exp the data of the command
    */
    void addValue(string commandName, Expression *exp);

    /**
     *
     * @return the table of the command and the expressions of them
     */
    map<string, Expression*> getTable();

    /**
     * set the values of the map and put them in the vec of all experession
     */
    void setMapValues();
};

#endif //PROGECT_COMMANDTABLE_H
