#include "../include/parser.hpp"

Parser::Parser()
{
    parsingTable = {
        {{"S", "if"}, {"if", "E", "then", "S", "else", "S"}},
        {{"S", "a"}, {"a"}},
        {{"E", "b"}, {"b"}},
        {{"E", "c"}, {"c"}}};
}

bool Parser::isTerminal(const string &symbol)
{
    return symbol == "if" || symbol == "then" || symbol == "else" ||
           symbol == "a" || symbol == "b" || symbol == "c" || symbol == "$";
}

bool Parser::parse(vector<string> input)
{
    stack<string> parsingStack;
    parsingStack.push("$");
    parsingStack.push("S");

    int index = 0;
    while (!parsingStack.empty())
    {
        string top = parsingStack.top();
        string lookahead = input[index];

        cout << "Pilha: ";
        stack<string> tempStack = parsingStack;
        while (!tempStack.empty())
        {
            cout << tempStack.top() << " ";
            tempStack.pop();
        }
        cout << "\t Entrada: ";
        for (size_t i = index; i < input.size(); i++)
        {
            cout << input[i] << " ";
        }
        cout << endl;

        if (top == lookahead)
        {
            parsingStack.pop();
            index++;
        }
        else if (!isTerminal(top))
        {
            if (parsingTable.find({top, lookahead}) != parsingTable.end())
            {
                parsingStack.pop();
                vector<string> production = parsingTable[{top, lookahead}];
                for (auto it = production.rbegin(); it != production.rend(); ++it)
                {
                    parsingStack.push(*it);
                }
            }
            else
            {
                cout << "Erro de sintaxe!" << endl;
                return false;
            }
        }
        else
        {
            cout << "Erro de sintaxe!" << endl;
            return false;
        }
    }
    return index == input.size();
}