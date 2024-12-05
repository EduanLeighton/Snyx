#ifndef LANGUAGES_H
#define LANGUAGES_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class SnyxFiles
{
public:
	// Reads the code from a file
	static string readFile(const string& fileName)
	{
		if (fileName.find(".snx") != string::npos)
		{
			ifstream file(fileName);

			if (!file.is_open())
			{
				throw runtime_error("Could not open file: " + fileName);
			}

			stringstream buffer;
			buffer << file.rdbuf();
			file.close();
			return buffer.str();
		}
		else
		{
			throw runtime_error("Wrong file type " + fileName);
		}
	};

	// Saves the code to a file
	static void saveFile(const string& fileName, const string& code)
	{
		ofstream file(fileName);
		if (!file.is_open())
		{
			throw runtime_error("Could not create file: " + fileName);
		}

		if (fileName.find(".snx") != string::npos)
		{
			file << code;
			file.close();
		}
		else
		{
			throw runtime_error("Wrong file type " + fileName);
		}
	};

private:

};

#endif