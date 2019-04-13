
#include <regex>
#include "Reader.h"
#include "SymbolTable.h"

/**
 * Split the line by char .
 * @param line . string the line to split
 * @param divide . char to split by it
 * @return vector after been splitted
 */
vector<string> Split(string line, char divide) {
    stringstream temp(line);
    //create from the line
    string segment;
    vector<std::string> seglist;
    //split by ","
    while (getline(temp, segment, divide)) {
        seglist.push_back(segment);
    }
    return seglist;
}

/**
 *
 * @param fileName the file name that contains all the data the user enters
 * @return a vaector that contains all the words in the file (command and expression)
 */
vector<string> Lexer(string fileName) {
    //  SymbolTable *s = SymbolTable::getInstance();
    //  map<string,double > symbols = s->getSymbolTable();
    // s->addValue("z",10);

    vector<string> data;
    bool isInOp = false;
    //read rhe information from the file
    string line;
    //check if the file exist
    ifstream ifs(fileName);
    if (ifs.is_open()) {
        //take a string of line
        while (getline(ifs, line)) {
            //if match \t - replace by " "
            regex reg("\t");
            //change every match to space
            line = regex_replace(line, reg, " ");
            //add the line to the vector
            int i = 0;
            string lineSplitEq = "";
            bool isBeforeCond = false;
            for (i = 0; i < line.length(); i++) {
                //check if '='
                if (line[i] == '=') {
                    //check if before was <>!=
                    if (isBeforeCond) {
                        //put space after it
                        lineSplitEq = lineSplitEq + line[i] + " ";
                        isBeforeCond = false;
                    } else if ((i + 1) < line.length() && line[i + 1] == '=') {
                        //just need to put flag
                        isBeforeCond = true;
                        lineSplitEq = lineSplitEq + " " + line[i];
                    } else {
                        lineSplitEq = lineSplitEq + " " + line[i] + " ";
                    }
                } else if (line[i] == '<' || line[i] == '>' || line[i] == '!') {
                    isBeforeCond = true;
                    //need to put space before it
                    lineSplitEq = lineSplitEq + " " + line[i];
                } else if (line[i] == '{' || line[i] == '}') {
                    lineSplitEq = lineSplitEq + " " + line[i] + " ";
                } else {
                    //check if was condition before
                    if (isBeforeCond) {
                        lineSplitEq = lineSplitEq + " " + line[i];
                        isBeforeCond = false;
                    } else {
                        lineSplitEq = lineSplitEq + line[i];
                    }
                }
            }

            //take the new line
            line = lineSplitEq;

            //need to put space before and after '='
            //regex regEq ("(([<>=])=((?![=<>])))");
            //  line = regex_replace(line,regEq," = ");

            stringstream temp(line);
            //create from the line
            string segment;
            string oldSegmaent;
            string fixedLine = "";
            bool isEqualInLine = false;
            bool latIsEqual = true;

            char last, first;
            bool lastOp = false, firstOp = false, lastIsDigit = false;
            bool isQua = false;

            //split by " "
            while (getline(temp, segment, ' ')) {
                last = segment[segment.length() - 1];
                first = segment[0];

                if (segment != "") {
                    //check if its print - ""
                    if (first == '"' && last != '"') {
                        // data.push_back(segment + " ");
                        isQua = true;
                    }
                    //check if the last one was digit - for the '-'

                    //check if its operator - need to take the next one too
                    if (last == '+' || last == '-' || last == '/' || last == '*') {
                        lastOp = true;
                    }
                    if (first == '+' || first == '-' || first == '/' || first == '*') {
                        firstOp = true;
                    }
                    if (firstOp == true || lastOp == true) {
                        //if just this char
                        if (segment.length() == 1 || (firstOp && lastOp)) {
                            isInOp = true;
                            //check if it - and there is '=' isn't in this line
                            if (first == '-' && !isEqualInLine) {
                                //check if last is digit
                                if (lastIsDigit) {
                                    data[data.size() - 1] = data[data.size() - 1] + segment;
                                } else {
                                    //need new place in the vector - not a continue of reg
                                    data.push_back(segment);
                                }
                            } else {
                                //here if equal in line - need to check if last one is '='
                                if (latIsEqual) {
                                    data.push_back(segment);
                                    latIsEqual = false;
                                } else {
                                    data[data.size() - 1] = data[data.size() - 1] + segment;
                                }
                            }
                        } else {
                            if (firstOp) {
                                if (first == '-' && !isEqualInLine) {
                                    //check if last is digit
                                    if (lastIsDigit) {
                                        data[data.size() - 1] = data[data.size() - 1] + segment;
                                    } else {
                                        //need new place in the vector - not a continue of reg
                                        data.push_back(segment);
                                    }
                                } else {
                                    if (latIsEqual) {
                                        data.push_back(segment);
                                        latIsEqual = false;
                                    } else {
                                        data[data.size() - 1] = data[data.size() - 1] + segment;
                                    }
                                }
                                isInOp = false;
                            }
                            if (lastOp) {
                                if (isInOp == true) {
                                    data[data.size() - 1] = data[data.size() - 1] + segment;
                                } else {
                                    data.push_back(segment);
                                }
                                isInOp = true;
                            }
                        }
                    } else {
                        if (isQua) {
                            if (first == '"') {
                                data.push_back(segment + " ");
                            } else if (last != '"') {
                                data[data.size() - 1] = data[data.size() - 1] + segment + " ";
                            } else {
                                data[data.size() - 1] = data[data.size() - 1] + segment;
                                isQua = false;
                            }
                        } else {
                            //check if last was "
                            //check if end "("
                            if (last == '(') {
                                if (isInOp == true) {
                                    data[data.size() - 1] = data[data.size() - 1] + segment;
                                } else {
                                    data.push_back(segment);
                                }
                                isInOp = true;
                            } else {
                                if (first == ')') {
                                    data[data.size() - 1] = data[data.size() - 1] + segment;
                                }//else if(last == ')') {
                                    //nothing to do - regular
                                    //}
                                else {
                                    if (isInOp == true) {
                                        data[data.size() - 1] = data[data.size() - 1] + segment;
                                    } else {
                                        data.push_back(segment);
                                    }
                                }
                                isInOp = false;
                            }
                        }
                    }

                    //oldSegmaent = segment;

                    //check last one - if = need to know there is in the line
                    if (first == '=' || last == '=' || segment == "while" || segment == "if") {
                        isEqualInLine = true;
                    }
                    //if the last one is = - put a flag
                    if (last == '=') {
                        latIsEqual = true;
                    } else {
                        latIsEqual = false;
                    }
                    //check last one - if digit or op - ok - can be before '-'
                    if (isdigit(last) || lastOp || last == '(' || last == ')') {
                        lastIsDigit = true;
                    } else {
                        lastIsDigit = false;
                    }
                    firstOp = false;
                    lastOp = false;
                }
            }
            isEqualInLine = false;
        }
        ifs.close();
    }
    return data;
}
