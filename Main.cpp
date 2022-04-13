/**
 * Main file for the exercise
 *
 * @author Inon Sinn
 * 
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
#include <vector>

#include "Matrix.hpp"
using namespace zich;

int main() {

  try
  {
    Matrix a{{3, 0, 0, 0, 3, 0, 0, 0, 3},3,3};
    a.printMat();
  }
  catch(const std::exception& e)
  {
    std::cout << e.what(); // information from length_error printed
  }
  cout << endl << "End of demo!" << endl;
  return 0;
}
