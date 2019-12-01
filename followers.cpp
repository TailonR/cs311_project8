// followers.cpp
// Tailon Russell
// Matt Perry
// Started : 11/23/2019
// Finished: 11/25/2019
// For CS311 Project8
// followers.cpp is the main program for reading a file and storing the instructed information in a table

#include <iostream>
//for std::cout and std::endl
#include <fstream>
//for std::ifstream
#include <string>
//for std::string and std::getline()
#include <vector>
//for std::vector
#include <sstream>
//for std::stringstream
#include <map>
//for std::map
#include <algorithm>
//for std::sort
#include <list>
//for std::list

//getName()
//DESC: Gets input from user and assigns it to the parameter
//PRE: Filename needs to be a valid string
//Requirements on types: None
//ERROR: No-except Guarantee
void getName(std::string & filename)
{
	std::cout << "Enter a filename" << std::endl;
	std::getline(std::cin, filename);
	std::cout << std::endl;
}

//cleanInput()
//DESC: Given a string, it checks if the the string is the name of an executable
//PRE: Filname needs to be a valid string
//Requirements on types: None
//Error: Strong Guarantee
bool cleanInput(std::string & filename)
{
	if (filename.substr(filename.size() - 3, filename.size() - 1) != "exe")
	{
		return true;
	}
	else
	{
		return false;
	}
}

//sortWords
//DESC: Given a vector and map, it adds sorts the vector in lexicographical order
//PRE: vectOfFirstWords needs to be a valid vector, and tableOfWords needs to be a valid map
//Requirement on types: vectOfFirstWords needs to be a vector of strings, and map needs to be a map of strings and lists of strings
//ERROR: Strong Guarantee
void sortWords(std::vector<std::string> & vectOfFirstWords, const std::map<std::string,std::list<std::string>> & tableOfWords)
{
	try 
	{
		for (auto i : tableOfWords)
		{
			vectOfFirstWords.push_back(i.first);
		}
		std::sort(vectOfFirstWords.begin(), vectOfFirstWords.end());
	}
	catch (...)
	{
		throw;
	}
}

//sortList()
//DESC: Given a string, a vector of strings, and a map it sorts the words in the list 
//PRE: i needs to be a valid string, vecOfListElemetns needs to be a valid vector, and tableOfWords needs to be a valid map
//Requirements on types: vectOfListElements needs to be a vector strings and tableOfWords needs to be a map of strings and lists
//ERROR: Strong Guarantee
void sortList(const std::string & i, std::vector<std::string> & vectOfListElements, const std::map<std::string,std::list<std::string>> & tableOfWords)
{
	try
	{
		for (auto j : tableOfWords.find(i)->second)
		{
			vectOfListElements.push_back(j);
		}
		std::sort(vectOfListElements.begin(), vectOfListElements.end()); //sorting the values of the linked lists before printing them
	}
	catch (...)
	{
		throw;
	}
}

//printWords()
//DESC: Given a vector of, a map of strings and lists, and an ostream prints the number of distinct words 
//	and each word followed by the words that follow it 
//PRE: vectOfWords needs to be a valid vector of strings, tableOfWords needs to be a valid map, and os needs to be a valid ostream
//Requirements on types: vectorOfWords needs to be a vector of strings, tableOfWords needs to be a map of strings and lists
//ERROR: Strong Error
void printWords(std::vector<std::string> & vectOfFirstWords, const std::map<std::string,std::list<std::string>> & tableOfWords, std::ostream & os)
{
	os << "Number of distinct words: " << tableOfWords.size() << std::endl;
	os << std::endl;
	for (auto i : vectOfFirstWords)
	{
		std::vector<std::string> vectOfListElements;

		try
		{
			sortList(i,vectOfListElements,tableOfWords);
		}
		catch (...)
		{
			throw;
		}

		std::cout << i << ": ";
		for (auto k : vectOfListElements)
		{
			os << k << " ";
		}
		os << "\n";
	}
}

//numberOfAppearances()
//DESC: Given two strings, a map, and a string, looks to see if the second string is in the list attributed to the first string,
//	and returns the number of times the word appears
//PRE: prevWord  and word needs to be valid strings and tableOfWords needs to be a valid map
//Requirements on types: tableOfWords needs to be a map of strings and lists
//ERROR: NO-throw (or None?)
int numberOfAppearances(const std::string & prevWord, const std::string& word, const std::map<std::string,std::list<std::string>> & tableOfWords)
{
	int numOfAppearances = 0;
	for (auto i : tableOfWords.find(prevWord)->second) 
	{
		if (i == word) //if the word that follows is already in the list
		{
			numOfAppearances++;
		}
	}
	return numOfAppearances;
}

//insertWord()
//DESC: Given two strings, and a map, inserts a inserts one of the strings into the list
//	asscociated with the other string
//PRE: word and prevWord need to be valid strings, and tableOfWords needs to be a valid map
//Requirements on types: tableOfWords needs to be a map of strings and lists
//ERROR: Strong Guarantee
void insertWord(std::string & word, std::string & prevWord, std::map<std::string,std::list<std::string>> & tableOfWords)
{
    std::list<std::string> list;
    if (tableOfWords.size() == 0)
    {
        if (prevWord != " ")
        {
            list.push_back(word);
        }
        tableOfWords.insert(std::pair<std::string, std::list<std::string>>(word, list)); //adds the previous word to the table as a key
                                                                                                //	and the list of words that follows it as the associative value
                                                                                                //		to the table
    }
    else if (tableOfWords.find(prevWord) == tableOfWords.end()) //if prevWord is not found
    {
        list.push_back(word);
        tableOfWords.insert(std::pair<std::string, std::list<std::string>>(prevWord, list)); //same as the previous insert
    }
    else if (tableOfWords.find(prevWord) != tableOfWords.end()) //if prevWord is found
    {
        
        if (numberOfAppearances(prevWord, word, tableOfWords) == 0)
        {
            tableOfWords.find(prevWord)->second.push_back(word); //only insert the prevWord and current word once if they are the same 
        }
    }
    prevWord = word;
}

//insertWords()
//DESC: Given two strings, an ifstream, a map, and a list, it reads from the ifstream 
//	and then inserts one of the strings and the list into the map 
//PRE: word and prevWord need to be valid strings, fileReader needs to be a valid ifstream, 
//	tableOfWords needs to be a valid map, and followingWordList needs to be a valid list
//Requirements on types: tableOfWords needs to be a map of lists and strings, 
//	and followingWordsList needs to be a list of strings
//ERROR: Strong Guarantee
void insertWords(std::string & word, std::string & prevWord, std::ifstream & fileReader,std::map<std::string,
					 std::list<std::string>> & tableOfWords, std::list<std::string> & followingWordsList)
{
	for (std::string line; std::getline(fileReader, line);) //reads each line of the file
	{
		std::stringstream words(line);
		while (words >> word) //extracts each word of the line
		{
            insertWord(word,prevWord,tableOfWords);
		}
		tableOfWords.insert(std::pair<std::string, std::list<std::string>>(prevWord, followingWordsList)); //inserts to the table the word as a key 
	}
}

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