
#include "OtherFunctions.h"

/**
 *
 * @param str a string
 * @return a string with a spaces after every char
 */
string putSpaces(string str) {
    str = newStr(str);
    int i = 0;
    string newStr = "";
    newStr = str[0];

    if (str[i] == '-') {
        newStr = newStr + " ";
    }
    //run on all the string and add spaces
    for (i = 1; i < str.length(); i++) {
        if (!isdigit(str[i]) && (str[i] != '.')) {
            if (str[i] == '-' || str[i] == ')' || str[i] == '(' || str[i] == '+' || str[i] == '*' || str[i] == '/') {
                newStr = newStr + " " + str[i] + " ";
            } else //it is a letter
                newStr = newStr + str[i];
        } else {
            newStr = newStr + str[i];
        }

    }
    return newStr + ' ';
}

/**
 *
 * @param str a string
 * @return a string witch considerate in neg numbers
 */
string newStr(string str) {
    string afterChange = str;
    string before = "";
    string after = "";
    for (int i = 0; i < str.size(); i++) {
        if (i == 0 && str[0] == '-') {
            afterChange = "0" + str;
        }
        if (str[i + 1] == '-') {
            if (str[i] == '(' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
                before = str.substr(0, i + 1);
                after = str.substr(i + 1, str.size() - 1);
                afterChange = before + "(0" + after + ")";
            }
        }
    }
    return afterChange;
}