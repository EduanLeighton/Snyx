#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> Tokenize(string Input)
{
    vector<string> Tokens;
    string token;
    stringstream strToken(Input);

    while (getline(strToken, token, ' '))
    {
        Tokens.push_back(token);
    }

    while (getline(strToken, token, '.'))
    {
		Tokens.push_back(token);
        Tokens.push_back(".");
    }

    return Tokens;
}

int main()
{
    string input;

    cout << "Enter code: " << endl;
    getline(cin, input);
 
    vector<string> Tokens = Tokenize(input);
 
    for (size_t i = 0; i < Tokens.size(); i++)
    {
        cout << Tokens[i] << endl;
    }

}
