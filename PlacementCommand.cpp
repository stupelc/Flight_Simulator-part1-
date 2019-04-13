//
// Created by chagit on 12/24/18.
//

#include "PlacementCommand.h"

/**
     * update the class for recognize our tables
     */
PlacementCommand::PlacementCommand() {
    this->symbolTable = SymbolTable::getInstance();
}

/**
 *
 * @param var a specific var
 * @param path the var's path
 * add a pair from the type 'var-path' to the map
 */
void PlacementCommand::setVarPath(string var, string path) {
    this->symbolTable->addPathToVar(var, path);
}

/**
 *
 * @param var a specific var
 * @param val the var's val
 * add a pair from the type 'var-val' to the map
 */
void PlacementCommand::serVarValue(string var, double val) {
    this->symbolTable->addSymbolValue(var, val);
}