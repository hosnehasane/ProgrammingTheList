#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class WordList
{

	string language;
	string *wordList;
	int size;
	int MAX_WORDS;
public:
	WordList(int MAX_Words = 5)
	{
		MAX_WORDS = MAX_Words;
		wordList = new string[MAX_WORDS + 1];
		size = 0;
	}

	
	WordList(const WordList &other)
	{
		language = other.language;
		size = other.size;
		MAX_WORDS = other.MAX_WORDS;

		wordList = new string[MAX_WORDS + 1];

		for (int c = 0; c < size; c++)
			wordList[c] = other.wordList[c];
	}

	void Load_Word_List(string fileName)
	{
		string word;
		int counter = 0;
		ifstream fileRead;
		fileRead.open(fileName.c_str());
		if (!fileRead)
		{
			cout << "\n ERROR: Unable to open the file " << fileName << " for reading.";
			exit(0);
		}
		fileRead >> word;
		while (!fileRead.eof())
		{
			fileRead >> word;
			counter++;
		}
		fileRead.close();

		
		if (counter <= MAX_WORDS)
		{
			wordList = new string[counter + 1];
			size = 0;
			fileRead.open(fileName.c_str());
			fileRead >> word;
			while (!fileRead.eof())
			{
				fileRead >> wordList[size++];
			}
		}

		else
			cout << "\n ERROR: Cannot load list, the number of words in the "
			<< " file exceeds the maximum words in the list.";
		fileRead.close();
	}
	void Add_Word(string word)
	{
		if (size == MAX_WORDS)
			cout << "\n ERROR: List full, word not added.";
		else if (!Contains(word))
			wordList[size++] = word;
		else
			cout << "\n Duplicate word not allowed.";
	}
	bool Contains(string word)
	{
		for (int c = 0; c < size; c++)
			if (word.compare(wordList[c]) == 0)
				return true;
		return false;
	}
	bool Equal_Lists(const WordList &another)
	{
		if (language.compare(another.language) != 0)
			return false;
		else if (size != another.size)
			return false;
		else
		{
			for (int c = 0; c < another.size; c++)
				if (!Contains(another.wordList[c]))
					return false;
		}
		return true;
	}
	void Display_Word_List()
	{
		for (int c = 1; c <= size; c++)
			if (c % 4 == 0)
				cout << left << setw(15) << wordList[c - 1] << endl;
			else
				cout << left << setw(15) << wordList[c - 1];
	}

	WordList operator = (WordList another)
	{
		WordList temp;
		temp.language = another.language;
		temp.size = another.size;
		temp.MAX_WORDS = another.MAX_WORDS;
		for (int c = 0; c < size; c++)
			temp.wordList[c] = another.wordList[c];
		return temp;
	}
	string &operator[](int index)
	{
		if (index < 0 || index > size)
		{
			cout << "\n ERROR: Index out of bounds." << endl;
			return wordList[0];
		}
		return wordList[index];
	}
};

int main()
{
	string word;
	int index;
   
    string filename;
	WordList w1(20);
    cout<<"Enter the name of first word list file : ";
    cin>>filename;
	w1.Load_Word_List(filename);
	cout << "\n\n ****** Word List 1 ******\n";
	w1.Display_Word_List();
	cout << "\n Enter a word to add to Word List 1: ";
	cin >> word;
	w1.Add_Word(word);
	cout << "\n\n ****** After adding word to Word List 1 ******\n";
	w1.Display_Word_List();
	

	cout << "\n\n ****** Search word in Word List 1 ******\n";
	cout << "\n Enter a word to search: ";
	cin >> word;
	if (w1.Contains(word))
		cout << "\n Word: " << word << " found in the list.";
	else
		cout << "\n Word: " << word << " not found in the list.";
	
    cout << "\n Enter a word to search: ";
	cin >> word;
	if (w1.Contains(word))
		cout << "\n Word: " << word << " found in the list.";
	else
		cout << "\n Word: " << word << " not found in the list.";

	WordList w2(30);
    cout<<"\nEnter the name of second word list file : ";
    cin>>filename;
	w2.Load_Word_List(filename);

	cout << "\n\n ****** Word List 2 ******\n";
	w2.Display_Word_List();
	cout << "\n\n ****** Check equality between Word List 1 and Word List 2 ******\n";
	if (w1.Equal_Lists(w2))
		cout << "\n Both are equal";
	else
		cout << "\n Both are not equal";
	WordList w3(w1);
	cout << "\n\n ****** Word List 3 a copy of Word List 1 ******\n";
	w3.Display_Word_List();


	WordList w4 = w2;
	cout << "\n\n ****** Word List 4 a copy of Word List 2 ******\n";
	w4.Display_Word_List();
	cout << "\n Enter a index position for word list 1: ";
	cin >> index;
	cout << "\n Word at " << index << " index position: " << w1[index];
	cout << "\n Enter a index position for word list 2: ";
	cin >> index;
	cout << "\n Word at " << index << " index position: " << w2[index];
	cout << "\n Enter a index position for word list 3: ";
	cin >> index;
	cout << "\n Word at " << index << " index position: " << w3[index];

	cout << "\n Enter a index position for word list 4: ";
	cin >> index;
	cout << "\n Word at " << index << " index position: " << w4[index];
    cout<<"\n";
	return 0;
}