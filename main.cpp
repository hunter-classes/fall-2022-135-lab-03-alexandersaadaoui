// add your code as appropriate 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"
#include "reverseorder.h"

int main()
{
  std::string date = "05/20/2018";
  std::string date2 = "01/05/2018";
  std::string date3 = "09/13/2018";
  
  std::cout << "Enter Date: " << date << std::endl;
  std::cout << "East Basin Storage: " << get_east_storage(date) << " billion gallons" << std::endl;

  std::cout << "minimum storage in East basin: " << get_min_east() << " billion gallons" << std::endl;
  std::cout << "MAXimum storage in East basin: " << get_max_east() << " billion gallons" << std::endl;

  std::cout << "Enter Date: " << date2 << std::endl;
  date = date2;
  std::cout << "Comparing basin elevation: " << compare_basins(date) << std::endl;
  std::cout << "Enter Date: " << date3 << std::endl;
  date = date3;
  std::cout << "Comparing basin elevation: " << compare_basins(date) << std::endl;
  
  date = "05/29/2018";
  date2 = "06/02/2018";
  reverse_order(date, date2);
  std::cout << std::endl;
  
  return 0;
}
