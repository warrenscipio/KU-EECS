/**
@Filename Executive.h
@Author Warren Scipio
*/

#ifndef _EXECUTIVE_
#define _EXECUTIVE_
#include "CountList.h"
#include <iostream>
#include <string>




class Executive
{
private:
   

    CountList<char> charArray;
    CountList<int> intArray;
    CountList<std::string> strArray;

    template <typename T>
    static void print(CountList<T> arr); // arr MUST be passed by value

    template <typename T>
    static void read(istream& is, CountList<T>& arr, string name);
	
public: 
        
    Executive();
    Executive(std::istream& charFile, std::istream& intFile,
              std::istream& stringFile);

    void print() const;
};

#endif
