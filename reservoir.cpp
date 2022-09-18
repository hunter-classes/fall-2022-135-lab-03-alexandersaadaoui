#include "reservoir.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

double get_east_storage(std::string date) {
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
    while(fin >> dateSearch >> eastSt >> eastEl >> westSt >> westEl) { 
        fin.ignore(INT_MAX, '\n'); 
        if(dateSearch == date){
            return eastSt;
        }   
    }
    
    fin.close();
    return 0;
}

double get_min_east() {
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
    double max = INT_MAX;
    while(fin >> dateSearch >> eastSt >> eastEl >> westSt >> westEl) { 
        fin.ignore(INT_MAX, '\n'); 
        if(max > eastSt){
            max = eastSt;
        }   
    }
    
    fin.close();
    return max;
}

double get_max_east() {
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
    double min = INT_MIN;
    while(fin >> dateSearch >> eastSt >> eastEl >> westSt >> westEl) { 
        fin.ignore(INT_MAX, '\n'); 
        if(min < eastSt){
            min = eastSt;
        }   
    }
    
    fin.close();
    return min;
}

std::string compare_basins(std::string date) {
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open the file
    }

    std::string junk;        // new string variable
    getline(fin, junk); // read one line from the file 

    std::string dateSearch;
    std::string answer;
    double eastSt;
    double eastEl;
    double westSt;
    double westEl;
    while(fin >> dateSearch >> eastSt >> eastEl >> westSt >> westEl) { 
        if(date == dateSearch){
            if(eastEl > westEl){
                return "East";
            }else if(westEl > eastEl){
                return "West";
            }else{
                return "Equal";
            }
        }
    }
    
    fin.close();
    return "Unknown";
}


  

  
