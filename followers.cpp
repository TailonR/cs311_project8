// followers.cpp
// Tailon Russell
// Matt Perry
// Started : 11/23/2019
// Finished: 11/25/2019
// For CS311 Project8
// followers.cpp is the main program for reading a file and storing the instructed information in a table

#include "followers.h"

int main()
{
	std::vector<std::string> vectOfFirstWords;
	std::string filename;
	std::ifstream fileReader; 
	std::string word;
	std::map<std::string, std::list<std::string>> tableOfWords; //string=current word, list=the words following current word
	std::list<std::string> followingWordsList;
	std::string prevWord = " ";

	getName(filename);
	if(cleanInput)
	{
		std::cout << "Attempting to open " << filename << std::endl;
		fileReader.open(filename);
	}
	else
	{
		std::cout << "Illegal file name "<< filename << std::endl;
		return 0;
	}

	if (!fileReader)
	{
		std::cout << "Failed to open "<< filename << std::endl;
		return 0;
	}
	else
	{
		if(!fileReader.eof()){
			insertWords(word, prevWord, fileReader, tableOfWords, followingWordsList);
			sortWords(vectOfFirstWords, tableOfWords);
			printWords(vectOfFirstWords, tableOfWords, std::cout);
		}
	}
	return 0;
}