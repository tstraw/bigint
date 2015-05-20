/*  Tim Strawbridge
 *  CS 23001
 *  2/16/15
 *  Bigint, Part 3
 */

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <cassert>
#include <fstream>

/*Function prototypes that initialize bigint, print bigint, compare two bigints, 
add together two bigints, and reads bigint from a file
*/

//constant that specifies maximum number of digits in bigint
const int maxDigits = 300;


class bigint {
public:
  //ENSURES default constructor, initializes bigint to 0
  bigint ();
  //ENSURES initializes bigint to some int
  bigint (int);
  //ENSURES initializes bigint to an array composed of chars
  bigint (const char[]);
  //ENSURES overloaded = operator to compare bigints
  bool operator==(const bigint&) const;
  //ENSURES overloaded output to output bigint
  void output(std::ostream&);
  //ENSURES overloaded + operator to add two bigints
  bigint operator+(const bigint&) const;
  //ENSURES overloaded * operator to multiply bigints
  bigint operator*(const bigint&) const;
  //ENSURES overloaded [] operator to return ith digit (non-constant)
  int& operator[](int);
  //ENSURES overloaded [] operator to return ith digit (constant)
  int operator[](int) const;
  //ENSURES multiplication of bigint by a single digit integer
  bigint timesDigit(const int) const;
  //ENSURES multiplication of bigint by 10^n, where n is some integer
  bigint timesTen(int) const;
  //ENSURES overload of >> operator to read bigint from a external file
  friend std::ostream& operator<<(std::ostream&, const bigint&);


private:
  int numberOfDigits[maxDigits];
};

//ENSURES overlaod of << operator to print at most 60 digits per line
std::istream& operator>>(std::istream&, bigint&);
//ENSURES returns length of string
int stringLength(const char[]);

#endif

