#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
#include <cstring>


string sentence;

string moveFirstLetterToFront(string);

string getString();

string spaceString(string);

string pigLatin(string);

int main() {

  string firstString = getString();

  string spacedString = spaceString(firstString);

  string moveLettersString = moveFirstLetterToFront(spacedString);

  string pigLatinString = pigLatin(moveLettersString);

  cout << "Spaced String: " << spacedString << endl;

  cout << "Pig Lating String: " << pigLatinString << endl;
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
  return sentence;
}

string pigLatin(string spacedSentence){

  int i = 0;
  int zeroLocation;
  bool foundZero = false;
  string phrase = "ay";

  for( i = 0; i < spacedSentence.length(); i++){

    if(spacedSentence[i] == ' '){

      zeroLocation = i;
      spacedSentence.insert(zeroLocation, phrase);
      i = zeroLocation + 2;
    }  
  }

  spacedSentence.insert(spacedSentence.length(), phrase);

  return spacedSentence;
}

string moveFirstLetterToFront(string pigLatinSentence){
  
  int spaceCounter = 0;
  int spaceLocation;
  int newFirst;
 
  for(int i = 0; i < pigLatinSentence.length(); i++){   

    char firstLetterChar;
    char lastLetterChar;
    string firstLetterString;
    string lastLetterString;

    
    if(spaceCounter == 0 && pigLatinSentence[i] == ' '){ // used for modifying first word of strong

      //very first  char
      spaceLocation = i;
      //first letter
      firstLetterChar = pigLatinSentence[0];
      firstLetterString.push_back(firstLetterChar);
      //last letter
      lastLetterChar = pigLatinSentence[spaceLocation-1];
      lastLetterString.push_back(lastLetterChar);

      //first letter turns to last letter
      //last letter turns to first letter
      pigLatinSentence.replace(spaceLocation, 1, firstLetterString);
      pigLatinSentence.erase(0,1);

      pigLatinSentence.insert(spaceLocation, " ");

      spaceCounter++;
      newFirst = spaceLocation + 1;

    }
    else if(spaceCounter > 0 && pigLatinSentence[i] == ' ') //used to modify every word of string besides last word
    {
      spaceLocation = i;
      firstLetterChar = pigLatinSentence[newFirst];
      firstLetterString.push_back(firstLetterChar);

      lastLetterChar = pigLatinSentence[spaceLocation-1];
      lastLetterString.push_back(lastLetterChar);

      pigLatinSentence.replace(spaceLocation, 1, firstLetterString);
      pigLatinSentence.erase(newFirst, 1);
      pigLatinSentence.insert(spaceLocation, " ");

      spaceCounter++;
      newFirst = spaceLocation +1;    
 
    }else if(i == pigLatinSentence.length()-1){ //used to modify last word of string

      spaceLocation = newFirst - 1;

      firstLetterChar = pigLatinSentence[newFirst];
      firstLetterString.push_back(firstLetterChar);

      lastLetterChar = pigLatinSentence[i];
      lastLetterString.push_back(lastLetterChar);

      pigLatinSentence.insert(i+1, " ");
      pigLatinSentence.replace(i+1, 1, firstLetterString);
      pigLatinSentence.erase(newFirst, 1);

    }
  }

    return pigLatinSentence;

}