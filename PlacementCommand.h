//
// Created by chagit on 12/24/18.
//

#ifndef PROGECT_PLACEMENTCOMMAND_H
#define PROGECT_PLACEMENTCOMMAND_H

#include <string>
#include "SymbolTable.h"

using namespace std;

/**
 * PlacementCommand Class
 * the class who updates the tables
 */
class PlacementCommand {
    SymbolTable *symbolTable;
public:
    /**
     * update the class for recognize our tables
     */
    PlacementCommand();

    /**
     *
     * @param var a specific var
     * @param path the var's path
     * add a pair from the type 'var-path' to the map
     */
    void setVarPath(string var, string path);

    /**
     *
     * @param var a specific var
     * @param val the var's val
     * add a pair from the type 'var-val' to the map
     */
    void serVarValue(string var, double val);
};


#endif //PROGECT_PLACEMENTCOMMAND_H
