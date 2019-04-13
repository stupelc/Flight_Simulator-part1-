#ifndef PROGECT_SYMBOLTABLE_H
#define PROGECT_SYMBOLTABLE_H

#include <map>
#include <string>
#include <vector>

using namespace std;

/**
 * SymbolTable Class
 * the class that contains all the vars data
 */
class SymbolTable {
    int clientId = -1;
    int serverId = -1;
    bool connect = true;
    bool server = true;

private:
    static SymbolTable *instance;
    map<string, double> symbolTable;
    map<string, string> varPathTable;
    map<string, double> pathDouble;
    vector<string> names;
    pthread_mutex_t mutex;

public:
    /**
     * a default constructor
     */
    SymbolTable();

    /**
     *
     * @param serverId the server id
     */
    void setServerId(int serverId);

    /**
     *
     * @return the syngalton symboltable
     */
    static SymbolTable *getInstance();

    /**
     *
     * @param varName
     * @param value
     * add a var and a value to the map of the symcbol table
     */
    void addSymbolValue(string varName, double value);

    /**
     *
     * @param varName
     * @param path
     * add a var and his path to the their map
     */
    void addPathToVar(string varName, string path);

    /**
     *
     * @param index the index of the path
     * @param val
     * add a path and his val according to the path index
     */
    void addValueByPathIndex(int index, double val);

    /**
     *
     * @param varName
     * @return the double value according to the var name
     */
    double getValue(string varName);

    /**
     *
     * @param varName
     * @return the path of the var that we get
     */
    string getVarPath(string varName);

    /**
     * set up the values into the symbol tabel
     */
    void setValuesInSymbolTable();

    /**
     *
     * @param var a specific var
     * @return 'true' if the val exist in the map, 'false' otherwise
     */
    bool isValExist(string var);

    /**
     *
     * @return 'true ' if we connect to the cliend and 'false' otherwise
     */
    bool isConnect() const;

    /**
     *
     * @param connect
     * change the value of 'connect' member
     */
    void setConnect(bool connect);

    /**
     *
     * @param clientId
     * change the value of 'clientId'
     */
    void setClientId(int clientId);

    /**
     *
     * @return the client id
     */
    int getClientId() const;

    /**
     *
     * @return the server id
     */
    int getServerId() const;

    /**
     *
     * @return the vector of the vars and their paths
     */
    const vector<string> &getNames() const;

    /**
     *
     * @return 'true' if the server is open and 'false' otherwise
     */
    bool isServer() const;

    /**
     *
     * @param server
     * change the value of the server value
     */
    void setServer(bool server);

    /**
     * destructor
     */
    ~SymbolTable();

    void exit();
};

#endif //PROGECT_SYMBOLTABLE_H
