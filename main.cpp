#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
#include <cstring>


string sentence;

string swapString(string);

string getString();

string spaceString(string);

string pigLatin(string);

int main() {

  string firstString = getString();

  string spacedString = spaceString(firstString);

  string swapLettersString = swapString(spacedString);

  string pigLatinString = pigLatin(swapLettersString);

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

string swapString(string spacedSentence){

  int zeroCounter = 0;
  int zeroLocation;
  int newFirst;

  for(int i = 0; i < spacedSentence.length(); i++){   
    
    if(zeroCounter == 0 && spacedSentence[i] == ' '){

      //very first  char
      zeroLocation = i;
      //first letter
      char firstWordTempChar;
      char firstWordLastTempChar;
      string firstWordTempString;
      string firstWordLastTempString;
      firstWordTempChar = spacedSentence[0];
      firstWordTempString.push_back(firstWordTempChar);
      //last letter
      firstWordLastTempChar = spacedSentence[zeroLocation-1];
      firstWordLastTempString.push_back(firstWordLastTempChar);

      //first letter turns to last letter
      //last letter turns to first letter
      spacedSentence.replace(zeroLocation, 1, firstWordTempString);
      spacedSentence.erase(0,1);

      spacedSentence.insert(zeroLocation, " ");
      zeroCounter++;
      i = zeroLocation+1;
      newFirst = zeroLocation + 1;

    }
    else if(zeroCounter > 0 && spacedSentence[i] == ' ')
    {
      zeroLocation = i;
      char tempOneO = spacedSentence[newFirst];
      string tempNumOneS;
      tempNumOneS.push_back(tempOneO);

      char tempTwoO = spacedSentence[zeroLocation-1];
      string tempNumTwoO;
      tempNumTwoO.push_back(tempTwoO);

      spacedSentence.replace(zeroLocation, 1, tempNumOneS);
      spacedSentence.erase(newFirst, 1);
      spacedSentence.insert(zeroLocation, " ");

      zeroCounter++;
      i = zeroLocation + 1;
      newFirst = zeroLocation +1;    
 
    }else if(i == spacedSentence.length()-1){

      zeroLocation = newFirst - 1;

      char firstLetterChar = spacedSentence[newFirst];
      string firstLetterString;
      firstLetterString.push_back(firstLetterChar);

      char lastLetterChar = spacedSentence[i];
      string lastLetterString;
      lastLetterString.push_back(lastLetterChar);

      spacedSentence.insert(i+1, " ");
      spacedSentence.replace(i+1, 1, firstLetterString);
      spacedSentence.erase(newFirst, 1);

    }
  }
    return spacedSentence;

}