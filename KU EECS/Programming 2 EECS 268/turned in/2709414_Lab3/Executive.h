/**
@Filename Executive.h
@Author Warren Scipio
*/

#ifndef _EXECUTIVE_
#define _EXECUTIVE_
#include "CountArray.h"
#include <iostream>
#include <string>




class Executive
{
private:
   

    CountArray<char> charArray;
    CountArray<int> intArray;
    CountArray<std::string> strArray;

    template <typename T>
    static void print(CountArray<T> arr); // arr MUST be passed by value

    template <typename T>
    static void read(istream& is, CountArray<T>& arr, string name);
	
public: 
        
    Executive();
    Executive(std::istream& charFile, std::istream& intFile,
              std::istream& stringFile);

    void print() const;
};

#endif
