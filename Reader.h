
#ifndef PROGECT_READER_H
#define PROGECT_READER_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

/**
 * Read the information
 */

/**
 *
 * @param fileName the file name that contains all the data the user enters
 * @return a vaector that contains all the words in the file (command and expression)
 */
vector<string> Lexer(string fileName);

/**
 * Split the line by char .
 * @param line . string the line to split
 * @param divide . char to split by it
 * @return vector after been splitted
 */
vector<string> Split(string line, char divide);

#endif //PROGECT_READER_H
