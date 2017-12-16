/**
 * File: main.cpp
 * Author: Ethan Randolph
 * Email: randolphe@student.vvc.edu
 * Description: This program will create an index of all the words in a given file. Then this program will print out that index, including the number of times it appears and the line numbers that the word is in.
 */
#include "wordcount.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

/**
 * This will determine if the given character is a white space or not
 * @param c This is the character given.
 * @return Will return true if the character is a whitespace, and false if it isn't.
 */
bool is_whitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

/**
 * This will go through all the whitespaces after a word until it reaches the next word.
 * @param d This is the char the stream is currently on. If it is a newline character, isnewline will be set to true.
 * @param input This is the stream where the whitespace is being read from.
 * @param isnewline This value will be altered if newline is detected in the whitespace.
 */
void eat_whitespace(char& d, std::ifstream& input, bool& isnewline)
{
	for(;;)
	{
		if (d == '\n')
		{
			isnewline = true;
		}
		input.get(d);
		if(input.eof())
			break;
		if(!is_whitespace(d))
		{
			input.putback(d); // this will put the character back on the input stream
			break;
 		}							 
	}
}

/**
 * This will gather the next word in the stream.
 * @param the_stream This is the stream from where the word will be read from.
 * @param isnewline This value is not used in this function, but serves as a reference for the eat_whitespace function.
 */
std::string next_word(std::ifstream& the_stream, bool& isnewline)
{
	std::string word;
	for(;;)
	{
		char e;
		the_stream.get(e);
		if (the_stream.eof())
		{
			break;
		}
		if (e >= 'A' && e <= 'Z')
		{
			e = e + 32; //This adds to the character's decimal character value, which will be the lowercase version of the letter.
			word += e;
		}
		else if ((e >= 'a' && e <= 'z') || (e >= '1' && e <= '9'))
		{
			word += e;
		}
		else if (is_whitespace(e))
		{
			eat_whitespace(e, the_stream, isnewline);
			break;
		}
		//If the character is not any one of these (such as if it was punctuation, then it is left out of the word.
	}
	return word;
}

/**
 * This is the main function that will put both the wordcount header and the nonmember functions in this file.
 * @return This will return 0 if everything is successful, and 1 if the file reading had an error.
 */
int main()
{
	//Variables that will be used by the main function.
	int line_count = 1;
	std::vector<Wordcount> index;
	bool isnewline = false;
	bool encountered = false;

	//Retrieves the filename of the file that will be read.
	std::string fn;
	std::cout << "Please enter the file name: ";
	std::cin >> fn;

	//Open the stream with that file name.
	std::ifstream input;
	input.open(fn.c_str());

	//Double checks if the file can be read, and returns one if it cannot.
	if (input.fail())
	{
		std::cout << "Error! The file could not be read. Abort." << std::endl;
		return 1;
	}

	//Gathers the words in the file and puts them in teh vector of Wordcount
	while (!input.eof())
	{
		isnewline = false;
		encountered = false;
		std::string current = next_word(input, isnewline);
		for (int i = 0; i < index.size(); i++)
		{
			if (index[i].print_word() == current)
			{
				index[i].add_count(line_count);
				encountered = true;
			}
		}

		if (encountered == false)
		{
			Wordcount temporal(current);
			index.push_back(temporal);
			index[index.size()-1].add_count(line_count);
		}

		if (isnewline == true)
		{
			line_count++;
		}
	}
	
	//This will print the index out.
	for (int i = 0; i < index.size(); i++)
	{
		index[i].print();
	}
			
	//Happy Holidays!
	return 0;
}
