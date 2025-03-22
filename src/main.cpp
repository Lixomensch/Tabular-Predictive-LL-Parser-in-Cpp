// main.cpp
#include "../include/parser.hpp"
#include <fstream>
#include <sstream>

vector<string> tokenize(const string &input)
{
    stringstream ss(input);
    vector<string> tokens;
    string token;
    while (ss >> token)
    {
        tokens.push_back(token);
    }
    tokens.push_back("$"); // Adiciona o marcador de fim de entrada
    return tokens;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "Uso: " << argv[0] << " <arquivo_de_entrada>" << endl;
        return 1;
    }

    ifstream file(argv[1]);
    if (!file)
    {
        cerr << "Erro ao abrir o arquivo: " << argv[1] << endl;
        return 1;
    }

    stringstream buffer;
    buffer << file.rdbuf();
    string content = buffer.str();

    vector<string> input = tokenize(content);

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
