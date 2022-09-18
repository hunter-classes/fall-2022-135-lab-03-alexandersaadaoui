#include "reverseorder.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string.h>
#include "reservoir.h"

void reverse_order(std::string date1, std::string date2){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open the file
    }

    std::string junk;        // new string variable
    getline(fin, junk); // read one line from the file 

    std::string dateSearch;
    double eastSt;
    double eastEl;
    double westSt;
    double westEl;
    double ft[366];
    std::string dates[366];
    int size;
    int count = 0;
    bool interval = false;
    while(fin >> dateSearch >> eastSt >> eastEl >> westSt >> westEl){
        if(dateSearch == date1)
        {
            interval = true;
        }
        if(interval){
            dates[count] = dateSearch;
            ft[count] = westEl;
            size++;
            count++;
        }
        if(dateSearch == date2)
            {
            interval = false;
            }
        fin.ignore(INT_MAX, '\n');
    };
    
    for(int count2 = size - 1; count2 >= 0; count2--){
        std::cout << dates[count2] << " ";
        std::cout << " " << ft[count2] << " ft " << std::endl;
    }
}