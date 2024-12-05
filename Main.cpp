#include <string>
#include <iostream>
#include "Tokenizer.h"
#include "LanguageFiles.h" // I know weird names, but it works

using namespace std;

int main()
{
    string fileName, code;

	cout << "Enter file name (without extention): " << endl;
	getline(cin, fileName);
    
    if (fileName.find(".snx") != string::npos) 
    {
        code = SnyxFiles::readFile(fileName);
    }
    else
    {
        fileName = fileName + ".snx";
		code = SnyxFiles::readFile(fileName);
    }

    vector<string> Tokens = Tokenizer::tokenize(code);
 
    for (size_t i = 0; i < Tokens.size(); i++)
    {
        cout << Tokens[i] << endl;
    }

}
