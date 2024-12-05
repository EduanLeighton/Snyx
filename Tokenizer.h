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

		// Decleration of variables
		int i = 0, k = 0;

		// Gets the string to tokenize
		while (getline(strToken, token))
		{
			// Resets variables
			k = 0;

			// Loops through the string
			for (i = 0; i < token.length(); i++)
			{
				//if (token[i] == ',')
				//{
				//	tempStr = token.substr(k, i - k);
				//	if (tempStr != " " || tempStr != "\t" || tempStr != "\n" || tempStr != "\r" || tempStr != "")
				//	{
				//		Tokens.push_back(tempStr);
				//	}
				//	k = i + 1;
				//}
				//else if (token[i] == ' ')
				//{
				//	tempStr = token.substr(k, i - k);
				//	if (tempStr != " " || tempStr != "\t" || tempStr != "\n" || tempStr != "\r" || tempStr != "")
				//	{
				//		Tokens.push_back(tempStr);
				//	}
				//	k = i + 1;
				//}
				//else if (token[i] == '.')
				//{
				//	tempStr = token.substr(k, i - k);
				//	if (tempStr != " " || tempStr != "\t" || tempStr != "\n" || tempStr != "\r" || tempStr != "")
				//	{
				//		Tokens.push_back(tempStr);
				//	}
				//	k = i + 1;
				//}

				// Checks for whitespace as deliminator
				if (token[i] == ' ')
				{
					// Posts the token
					nameless(token, Tokens, i, k);
					// Sets the last position
					k = i + 1;
				}// If
				else if (i == token.length() - 1)
				{
					// Posts the token
					nameless(token, Tokens, i + 1, k);
				}// Else if
			}// For
		}// While

		// Return
		return Tokens;
	}// tokenize

private:
	static void nameless(string& token, vector<string>& Tokens, int currentPos, int lastPos)
	{
		string tempStr;

		tempStr = token.substr(lastPos, currentPos - lastPos);
		if (tempStr != " " || tempStr != "\t" || tempStr != "\n" || tempStr != "\r" || tempStr != "")
		{
			Tokens.push_back(tempStr);
		}
	};


};

#endif // TOKNIZER_H