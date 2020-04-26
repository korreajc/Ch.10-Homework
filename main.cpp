#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
#include <cstring>


string sentence;

string getString();

bool checkString(string);

string spaceString(string);

string moveFirstLetterToFront(string);

string pigLatin(string);

int main() {

  string userString = getString();

  string spacedString = spaceString(userString);

  string moveLettersString = moveFirstLetterToFront(spacedString);

  string pigLatinString = pigLatin(moveLettersString);

  cout << "Spaced String: " << spacedString << endl;

  cout << "Pig Lating String: " << pigLatinString << endl;
}

string getString(){

  string sentence;
  bool inputCheck;
 
 //takes input in 
  cout << "Enter your sentence: " << endl;
  getline(cin, sentence);

  //calls check strin gfunction to check if input is valid
  inputCheck = checkString(sentence);

  //while loop for input validation
  while(inputCheck == false){

    cout << "Invaild Input. String must be longer than one word, contain no spaces, and every first letter of every word must be capitalized"<< endl;
    getline(cin, sentence);
    inputCheck = checkString(sentence);

  }
  return sentence;
}

bool checkString(string userSentence){

  //variables used to count number of uppercase letters and spaces in string
  int upperCaseCount = 0;
  int spaceCount = 0;
  bool check;

  //runs through string increasing the varibales if found
  for(int i = 0; i < userSentence.length(); i++){

      if(isupper(userSentence[i])){
        upperCaseCount++;
      }
      else if(userSentence[i] == ' ')
      {
        spaceCount++;
      }

  }

  //returns false if there were spaces and more less than or equal to one uppercase letter in string
  if(spaceCount > 0 || upperCaseCount <= 1){

    check = false;
  }
  else if(spaceCount == 0 && upperCaseCount > 1) //returns true if input is valid
  {
    check = true;
  }

  return check;

}


string spaceString(string sentence){

  //runs through loop and inserts a space after every uppercase letter and lowercases every letter besides the first letter
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

//moves the first letter of every word into the front
string moveFirstLetterToFront(string pigLatinSentence){
  
  //variables to store the amount of spaces found and its location
  int spaceCounter = 0;
  int spaceLocation;
  int newFirst;
 
  for(int i = 0; i < pigLatinSentence.length(); i++){   

    //char variables temporarily hold the first and last letter of everyword
    char firstLetterChar;
    char lastLetterChar;
    //chars will be converted into strings for easier use
    string firstLetterString;
    string lastLetterString;

    
    if(spaceCounter == 0 && pigLatinSentence[i] == ' '){ // used for modifying first word of strong

      spaceLocation = i;
      //stores first letter of first word in char, converts it into a string
      firstLetterChar = pigLatinSentence[0];
      firstLetterString.push_back(firstLetterChar);

      //stores last letter of first word into a char, converts into a string
      lastLetterChar = pigLatinSentence[spaceLocation-1];
      lastLetterString.push_back(lastLetterChar);

      //moves first letter to the end of word, erases the variable from front and puts space after the last letter of word
      pigLatinSentence.replace(spaceLocation, 1, firstLetterString);
      pigLatinSentence.erase(0,1);
      pigLatinSentence.insert(spaceLocation, " ");

      spaceCounter++;
      newFirst = spaceLocation + 1; // stores the location of the next starting point which is the first letter of the next word, found after the space

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

      firstLetterChar = pigLatinSentence[newFirst];
      firstLetterString.push_back(firstLetterChar);

      lastLetterChar = pigLatinSentence[i];
      lastLetterString.push_back(lastLetterChar);

      //space is inserted first here because the last word of the string
      pigLatinSentence.insert(i+1, " ");
      pigLatinSentence.replace(i+1, 1, firstLetterString);
      pigLatinSentence.erase(newFirst, 1);

    }
  }
    return pigLatinSentence;
}

string pigLatin(string spacedSentence){

  int spaceLocation;
  string phrase = "ay";

  for(int i = 0; i < spacedSentence.length(); i++){

    if(spacedSentence[i] == ' '){
      
      //sets the location of the space to i, and inserts pig latin phrase at it
      spaceLocation = i;
      spacedSentence.insert(spaceLocation, phrase);

      //starts i two spaces after space because there are now two additional characters added into string with "ay"
      i = spaceLocation + 2;

    }  
  }

  // adds the pig latin phrase to the last word of the string
  spacedSentence.insert(spacedSentence.length(), phrase);

  return spacedSentence;
}

