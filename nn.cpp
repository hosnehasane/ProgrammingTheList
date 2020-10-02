#include<bits/stdc++.h>
using namespace std;

#define MAX_WORD 5

class WordList
{
        private:
                vector<string> wordList;
        public:
                WordList(){
                        this->wordList = vector<string> ();
                }
                WordList(WordList &obj) 
                {
                        wordList = obj.getList();
                } 

                // get the list of word
                vector<string> getList(){
                        return this->wordList;
                }
                void Load_Word_List(string file){
                        ifstream in(file);
                        if(!in) {
                        cout << "Cannot open input file.\n";
                        return;
                        }
                        char str1[255];
                        
                        while(in) {
                        in.getline(str1,255);
                        if(in){
                                if(wordList.size() >= MAX_WORD){
                                        cout << "Cannot load list, the number of words in the file exceeds the maximum words in the list" << endl;
                                        return;
                                }
                                wordList.push_back(str1);
                        }
                }
                }
                void Add_Word(string word){
                        if(wordList.size() >= 5){
                                cout << "List full, word not added" << endl;
                                return;
                        }
                        wordList.push_back(word);
                }

                bool Contains(string word){
                        for(int i = 0; i < wordList.size(); i++){
                                if(wordList[i] == word)
                                        return true;
                        }
                        return false;
                }

                bool Equal_Lists(WordList wordList){
                        return this->getList() == wordList.getList();
                }
                void Display_Word_List(){
                        cout << "WordList is : ";
                        for(int i = 0; i < wordList.size(); i++){
                                cout << wordList[i] << "\n";
                        }
                        cout << endl;
                }

                // overloading of = operator
                void operator = (WordList  &obj){
                        vector<string> l = obj.getList();
                        wordList = l;

                }

                // overloading of [] operator
                string &operator [] (int i){
         return wordList[i];
                }

                // destructor of wordList
                ~WordList(){

                }
};


int main(int argc, char const *argv[])
{
        
        WordList w;
        string file;
        cout << "Enter the name of file : ";
        cin >> file;
        w.Load_Word_List(file);
        w.Display_Word_List();

        string word;
        cout << "Enter word to add in list : ";
        cin >> word;
        w.Add_Word(word);

        string wordSearch;
        cout << "Enter word to search in list : ";
        cin >> wordSearch;
        bool s = w.Contains(wordSearch);
        if(s)
                cout << "found!" << endl;
        else
                cout << "Not found!" << endl;

        WordList w2;
        string file2;
        cout << "Enter the name of file2 : ";
        cin >> file2;
        w2.Load_Word_List(file2);
        w2.Display_Word_List();

        bool res = w2.Equal_Lists(w);
        if(res)
                cout << "Equal list" << endl;
        else 
                cout << "Not Equal list." << endl;

        WordList w3(w);
        WordList w4;
        w4 = w2;
        w4.Display_Word_List(); 

        int index;
        cout << "Enter index : ";
        cin >> index;

        cout << w4[index] << endl;

        w4.Display_Word_List();


        return 0;
}
