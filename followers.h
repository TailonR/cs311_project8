// followers.cpp
// Tailon Russell
// Matt Perry
// Started : 11/23/2019
// Finished: 11/25/2019
// For CS311 Project8
// followers.h is the headerfile for functions for followers.cpp

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


#ifndef FILE_FOLLOWERS_H_INCLUDED
#define FILE_FOLLOWERS_H_INCLUDED

void getName(std::string & filename)
{
	std::cout << "Enter a filename" << std::endl;
	std::getline(std::cin, filename);
	std::cout << std::endl;
}

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

void sortWords(std::vector<std::string> & vectOfFirstWords, const std::map<std::string,std::list<std::string>> & tableOfWords)
{
    for (auto i : tableOfWords)
    {
        vectOfFirstWords.push_back(i.first);
    }
    std::sort(vectOfFirstWords.begin(), vectOfFirstWords.end());
}

void printWords(std::vector<std::string> & vectOfFirstWords, const std::map<std::string,std::list<std::string>> & tableOfWords, std::ostream & os)
{
	os << "Number of distinct words: " << tableOfWords.size() << std::endl;
	os << std::endl;
	for (auto i : vectOfFirstWords)
	{
		std::vector<std::string> vectOfListElements;
		for (auto j : tableOfWords.find(i)->second)
		{
			vectOfListElements.push_back(j);
		}
		std::sort(vectOfListElements.begin(), vectOfListElements.end()); //sorting the values of the linked lists before printing them

		std::cout << i << ": ";
		for (auto k : vectOfListElements)
		{
			os << k << " ";
		}
		os << "\n";
	}
}

int numberOfAppearances(const std::string & prevWord, const std::map<std::string,std::list<std::string>> & tableOfWords, const std::string & word)
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
        
        if (numberOfAppearances(prevWord, tableOfWords, word) == 0)
        {
            tableOfWords.find(prevWord)->second.push_back(word); //only insert the prevWord and current word once if they are the same 
        }
    }
    prevWord = word;
}

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


#endif