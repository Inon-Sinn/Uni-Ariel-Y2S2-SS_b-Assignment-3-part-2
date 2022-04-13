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
  std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  std::vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
  Matrix a{identity, 3, 3};  
  Matrix b{arr, 3, 3};

  cout << a << endl;

  cout << (-a) << endl;

  cout << (+a) << endl;

  cout << (3*a) << endl;

  cout << (a+b) << endl;

  cout << (b-a) << endl;

  cout << (a*b) << endl;

  cout << "End of demo!" << endl;
  return 0;
}
