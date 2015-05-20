/*  Tim Strawbridge
 *  CS 23001
 *  2/16/15
 *  Bigint, Part 3
 */

#include "bigint.hpp"


/*Function definitions that initialize bigint, print bigint, compare two bigints, 
add together two bigints, and reads bigint from a file
*/


//Initializes bigint to 0
bigint::bigint() {
  
  for (int i = 0; i < maxDigits; ++i){
    numberOfDigits[i] = 0;
  }

}


//Initializes bigint to a user defined int
bigint::bigint(int intVar){

  for (int i = 0; i < maxDigits; ++i){
    numberOfDigits[i] = 0;
  }

  //for loop to assign values to each memory location in array
  for (int i = 0; i < maxDigits; ++i){
    numberOfDigits[i] = intVar % 10;
    intVar = intVar / 10;
  }

}


//Returns the length of the string for the char array
int stringLength(const char charVar[]){

  int length = 0;
  
  //breaks loop when null character reached, until then increases length
  for (int i = 0; i < maxDigits; ++i){
    
    if (charVar[i] == '\0'){
      break;
    }
    
    ++length;

  }
  
  return length;

}

//Initializes bigint to a user defined char
bigint::bigint(const char charVar[]){

  for (int i = 0; i < maxDigits; ++i){
    numberOfDigits[i] = 0;
  }

  //ints for do while loop
  int length = stringLength(charVar) - 1;
  int loc = 0;
  
  //do while loop that converts chars into ints by subtracting the char stored at loc
  //by the smallest char '0', as long charVar[loc] is not equal to the null character
  do{
    numberOfDigits[loc] = charVar[length] - '0';
    ++loc;
    --length;
  } while (charVar[loc] != '\0');

}


//Compares two bigints, returns true if they are equal and false if they are not
bool bigint::operator==(const bigint& bigintVar) const{

  //loop that goes over each value stored in array and returns the appropriate bool
  for (int i = 0; i < maxDigits; ++i){
    
    if (bigintVar.numberOfDigits[i] != numberOfDigits[i]){
      return false;
    }
    
  }

  return true;

}


//Overloaded output that outputs a maximum 60 digits per line
void bigint::output(std::ostream& out){

  int loops = maxDigits;
  
  //loops until a significant digit is reached
  do{
    --loops;
  } while (numberOfDigits[loops] == 0);

  //loop that ensures only 60 digits are printed per line
  for (int i = loops; i >= 0; --i){
    
    if (i % 60 == 0){
      out << numberOfDigits[i] << std::endl;
    }

    else{
      out << numberOfDigits[i];
    }

  }

  //outputs the special case 0
  if ((loops = 1 && (numberOfDigits[loops] / 10 != 0))){
    numberOfDigits[loops] = 0;
    out << numberOfDigits[loops] << std::endl;
  }

}


//Overload of << operator to output bigint
std::ostream& operator<<(std::ostream& out, const bigint& rhs){

  int loops = maxDigits;

  //loops until a significant digit is reached
  do{
    --loops;
  } while (rhs.numberOfDigits[loops] == 0);

  //loop that ensures only 60 digits are printed per line
  for (int i = loops; i >= 0; --i){

    if (i % 60 == 0){
      out << rhs.numberOfDigits[i] << std::endl;
    }

    else{
      out << rhs.numberOfDigits[i];
    }

  }

  //outputs the special case 0
  if ((loops = 1 && (rhs.numberOfDigits[loops] / 10 != 0))){
    out << "0" << std::endl;
  }

  return out;

}


//Overload of >> operator to read stream from file
std::istream& operator>>(std::istream& in, bigint& bigintVar){
  
  int digitCount = 0;
  char chr = '0';
  char tempArray[maxDigits] = { 0 };

  //do while loop that reads a character, inserts it into array and reads next digit
  do{
    tempArray[digitCount] = chr;
    in >> chr;
    ++digitCount;
  } while ((chr != ';') && (!in.eof()));

  //resets array and sets the bigint passed by reference equal to the array
  tempArray[digitCount] = 0;
  bigintVar = tempArray;

  return in;

}


//Adds two bigints together
bigint bigint::operator+(const bigint& rhs) const{

  bigint result;
  int rightMostNumber = 0;
  int leftMostNumber = 0;

  //for loop that adds together two bigints by placing first number in result of
  //addition in position i and carrying over numbers
  for (int i = 0; i < maxDigits; ++i){
    leftMostNumber = rhs.numberOfDigits[i] + numberOfDigits[i] + leftMostNumber;
    rightMostNumber = leftMostNumber % 10;
    leftMostNumber = leftMostNumber / 10;
    result.numberOfDigits[i] = rightMostNumber;
  }

  return result;

}


//Gets the number located in location loc from some int
int& bigint::operator[](int loc){

  return numberOfDigits[loc];

}


//Gets the number located in the location loc from some constant int
int bigint::operator[](int loc) const{

  return numberOfDigits[loc];

}


//Overloaded * operator to multiply two bigints
bigint bigint::operator*(const bigint& bigintVar) const{

  bigint product = 0;
  bigint temp;

  //for loop to get the product of bigint multiplication
  for (int i = 0; i < maxDigits - 1; ++i){
    temp = *this;
    temp = bigintVar.timesDigit(numberOfDigits[i]);
    product = product + temp.timesTen(i);
  }

  return product;

}


//Multiplies bigint by a signle digit
bigint bigint::timesDigit(const int singleDigit) const{

  bigint result;
  int carry = 0;

  //for loop to get the product of multiplication and place it in a bigint
  for (int i = 0; i < maxDigits; ++i){
    result[i] = ((numberOfDigits[i] * singleDigit) + carry) % 10;
    carry = ((numberOfDigits[i] * singleDigit) + carry) / 10;
  }

  return result;

}



//Raises bigint by a power of ten
bigint bigint::timesTen(int tensDigit) const{

  bigint timesTenResult;

  //shift number at initial position tensDigit to the left
  for (int i = 0; i < maxDigits - tensDigit; ++i){
    timesTenResult[i + tensDigit] = numberOfDigits[i];
  }
  
  return timesTenResult;

}



