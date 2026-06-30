#include "parser.h"
#include <sstream>

using namespace std;

vector<string> Parser::parse(const string& input) const
{
    vector<string> tokens;

    stringstream ss(input);
    string token;

    while (ss >> token)
    {
        tokens.push_back(token);
    }

    return tokens;
}