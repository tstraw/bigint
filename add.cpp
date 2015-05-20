/*  Tim Strawbridge
 *  CS 23001
 *  2/9/15
 *  Bigint, Part 2
 */

// bigint input from file, add
//
//==============================================================================
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

//==============================================================================
int main()
{
  
  // Define object for input, exit if open fails
  std::ifstream in("data1-1.txt");
  
  if (!in) {
      std::cerr << "Couldn\'t open data1-1.txt, exiting.\n"; exit(1);
    }

  // Input, add, output
  bigint left, right;
  
  while (in >> left && in >> right){
    
    // Output operands
    std::cout << "Left:   " << left << "\n";
    std::cout << "Right:  " << right << "\n";

    // Add
    bigint result = left + right;

    // Output result
    std::cout << "Result: " << result << "\n\n";
  }

  // Close file
  in.close();

  return 0;

}

