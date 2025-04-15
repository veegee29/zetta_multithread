#include "../include/utility.h"
#include <sstream>

vector<string> split(const string& line, char delimiter) {
    vector<string> tokens;
    stringstream ss(line);
    string token;

    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}/* Method name : split | type : vector of string
    arguments : line | data type : string reference
                delimeiter |     : char -> initially valued as '|' , refer declaration in utility.h

    variables : tokens | data type : vector of string | scope : local
                ss                 : object of stringstream with instance argument as 
                                   line with string data type : local
                token              : string                   : local

    Method feature : to split in parts the whole string of line into small strings using delimiter = '|' as 
    seperation checkpoint as the TPC-H data is seperated using '|' as per the TPC-H documents to return  small strings in a vector
    */
