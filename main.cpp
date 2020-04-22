#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
#include <cstring>


string sentence;

string getString();

string spaceString(string);

string pigLatin(string);

int main() {

  string firstString = getString();

  string spacedString = spaceString(firstString);

  cout << spacedString << endl;
}

string getString(){

  cout << "Enter your sentence: " << endl;
  getline(cin, sentence);

  return sentence;
}

string spaceString(string sentence){

  for(int i = 1; i < sentence.length(); i++)
  {

    if(isupper(sentence[i]))
    {
      sentence[i] = tolower(sentence[i]);
      sentence.insert(i ," ");
    }

  }
  cout << sentence.length() << endl;
  return sentence;
}

string pigLatin(string spacedSentence){









  return spacedSentence;
}