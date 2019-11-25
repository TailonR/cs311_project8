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

int main()
{
	std::string filename;
	std::cout << "Enter a filename" << std::endl;
	std::getline(std::cin, filename);
	std::cout << std::endl;
	std::ifstream fileReader; 
	std::string word;
	std::map<std::string, std::list<std::string>> tableOfWords; //string=current word, list=the words following current word
	std::list<std::string> followingWordsList;
	std::string prevWord = " ";
	if (filename.substr(filename.size() - 3, filename.size() - 1) != "exe")
	{
		fileReader.open(filename);
	}
	else
	{
		return 0;
	}

	if (!fileReader)
	{
		if (fileReader.eof())
		{
			std::cout << "This didn't work" << std::endl;
		}
	}
	else
	{
		//**************************************************** Inserting words and lists into the table **********************************************************************//
		for (std::string line; std::getline(fileReader, line);) //reads each line of the file
		{
			std::stringstream words(line);
			while (words >> word) //extracts each word of the line
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
					int numOfAppearances = 0;
					for (auto i : tableOfWords.find(prevWord)->second) 
					{
						if (i == word) //if the word that follows is already in the list
						{
							numOfAppearances++;
						}
					}
					if (numOfAppearances == 0)
					{
						tableOfWords.find(prevWord)->second.push_back(word); //only insert the prevWord and current word once if they are the same 
					}
				}
				prevWord = word;
			}
				tableOfWords.insert(std::pair<std::string, std::list<std::string>>(prevWord, followingWordsList)); //inserts to the table the word as a key 
		}
		//************************************************** End of inserting words and lists into the table *******************************************************************//

		//********************************************* Sorting the keys of the map using a vector ****************************************************************//
		std::vector<std::string> vectOfFirstWords;
		for (auto i : tableOfWords)
		{
			vectOfFirstWords.push_back(i.first);
		}
		std::sort(vectOfFirstWords.begin(), vectOfFirstWords.end());
		//********************************************* End of sorting the keys of the map using a vector ****************************************************************//

		//******************************************** Printing the values of the table in the format as instructed *****************************************************//
		std::cout << "Number of distinct words: " << tableOfWords.size() << std::endl;
		std::cout << std::endl;
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
				std::cout << k << " ";
			}
			std::cout << "\n";
		}
		//******************************************** End of printing the values of the table in the format as instructed *****************************************************//

	}


	

	
	return 0;
}