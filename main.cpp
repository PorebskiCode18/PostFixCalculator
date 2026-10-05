#include <iostream>

#include "src/calculator.hpp"
using namespace std;

int main() {
  Calculator calculator;
  cout << calculator.evaluate("2 + 5") << endl;
  cout << calculator.evaluate("3 + 6 * 5") << endl;
  cout << calculator.evaluate("4 * (2 + 3)") << endl;
  cout << calculator.evaluate("(7 + 9) / 8") << endl;
}
