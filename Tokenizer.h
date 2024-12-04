#ifndef TOKNIZER_H
#define TOKNIZER_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>


using namespace std;

class Tokenizer
{
public:
	// Tokenizes a string
	static vector<string> tokenize(string Input)
	{
		// Decleration of variables
		vector<string> Tokens;
		string token, tempStr;
		stringstream strToken(Input);

		// 
		int i = 0, k = 0;

		getline(strToken, token);

		for (i = 0; i < token.length(); i++)
		{
			if (token[i] == ',')
			{
				tempStr = token.substr(k, i - k);
				if (isWhitespace(tempStr))
				{
					Tokens.push_back(tempStr);
				}
				k = i + 1;
			}
			else if (token[i] == ' ')
			{
				tempStr = token.substr(k, i - k);
				if (isWhitespace(tempStr))
				{
					Tokens.push_back(tempStr);
				}
				k = i + 1;
			}
			else if (token[i] == '.')
			{
				tempStr = token.substr(k, i - k);
				if (isWhitespace(tempStr))
				{
					Tokens.push_back(tempStr);
				}
				k = i + 1;
			}
		}

		return Tokens;
	}

private:
	static bool isWhitespace(string c)
	{
		if (c == " " || c == "\t" || c == "\n" || c == "\r" || c == "")
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};

#endif // TOKNIZER_H