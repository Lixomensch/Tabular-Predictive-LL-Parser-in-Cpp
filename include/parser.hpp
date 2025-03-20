#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Parser
{
private:
    map<pair<string, string>, vector<string>> parsingTable;
    bool isTerminal(const string &symbol);

public:
    Parser();
    bool parse(vector<string> input);
};

#endif // PARSER_HPP