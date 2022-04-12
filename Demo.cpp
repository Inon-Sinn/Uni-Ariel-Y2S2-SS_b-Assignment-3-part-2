/**
 * Demo file for the exercise on numbers with units
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 * 
 * Edited by Tal Zichlinsky
 * @since 2022-02
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
