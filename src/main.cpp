#include "../include/parser.hpp"

int main()
{
    vector<string> input = {"if", "b", "then", "a", "else", "a", "$"};
    Parser parser;
    if (parser.parse(input))
    {
        cout << "Entrada aceita!" << endl;
    }
    else
    {
        cout << "Entrada rejeitada!" << endl;
    }
    return 0;
}