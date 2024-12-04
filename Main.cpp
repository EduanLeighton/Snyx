#include <string>
#include <iostream>
#include "Tokenizer.h"

using namespace std;

int main()
{
    string input;

    cout << "Enter code: " << endl;
    getline(cin, input);
 
    vector<string> Tokens = Tokenizer::tokenize(input);
 
    for (size_t i = 0; i < Tokens.size(); i++)
    {
        cout << Tokens[i] << endl;
    }

}
