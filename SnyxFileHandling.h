#ifndef SNYXFILEHANDLING_H
#define SNYXFILEHANDLING_H

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
		// Check the file type
		if (fileName.find(".snx") != string::npos)
		{
			ifstream file(fileName); // Open the file

			// Check if the file is open
			if (!file.is_open())
			{
				// Runtime error for file opening
				throw runtime_error("Could not open file: " + fileName);
			}

			// Read the code from the file
			stringstream buffer;
			buffer << file.rdbuf();
			file.close(); // Close the file

			// Return the code as a string
			return buffer.str();
		} // If
		else
		{
			// Runtime error for wrong file type
			throw runtime_error("Wrong file type " + fileName);
		} // Else
	};

	// Saves the code to a file
	static void saveFile(const string& fileName, const string& code)
	{
		ofstream file(fileName); // Open the file

		// Check if the file is open
		if (!file.is_open())
		{
			// Runtime error for file opening
			throw runtime_error("Could not open file: " + fileName);
		}

		// Check the file type
		if (fileName.find(".snx") != string::npos)
		{
			// Write the code to the file
			file << code;
			file.close(); // Close the file
		} // If
		else
		{
			// Runtime error for wrong file type
			throw runtime_error("Wrong file type " + fileName);
		} // Else
	}; // saveFile

private:
	// Creates the snx file
	static void createFile(const string& fileName)
	{
		ofstream file(fileName); // Open the file

		// Check if the file is open
		if (!file.is_open())
		{
			// Runtime error for file creation
			throw runtime_error("Could not create file: " + fileName);
		}

		file.close(); // Close the file
	};

};

#endif // SNYXFILEHANDLING_H