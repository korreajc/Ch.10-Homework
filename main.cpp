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

  string pigLatinString = pigLatin(spacedString);

  cout << pigLatinString << endl;
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
  cout << "Length" << sentence.length() << endl;
  cout << "Spaced String: " << sentence << endl;

  return sentence;
}

string pigLatin(string spacedSentence){

int i = 0;
int zeroLocation;
bool foundZero = false;

for( i = 0; i < spacedSentence.length(); i++){

    if(spacedSentence[i] == ' '){

      cout << "Zero Located at: " <<  i << endl;
      zeroLocation = i;
      spacedSentence.insert(zeroLocation, "ay");
      cout << spacedSentence << endl;
      i = zeroLocation + 2;
    }

   

  
}


  return spacedSentence;
}