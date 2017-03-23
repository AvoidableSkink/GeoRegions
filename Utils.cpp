//
// Created by Stephen Clyde on 2/3/17.
//


#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <limits>
#include "Utils.h"

std::string getStringInput(std::string prompt)
{
    std::string userInput;

    std::cout << std::endl;
    std::cout << prompt << std::endl;
    std::getline(std::cin, userInput);

    return userInput;
}

// Splits a string up by the specified delimiter and stores the pieces into an array of strings, and checks
// to see if the expected number of pieces were found in the string
//
// Return a true if the string was split into the expected number of pieces, otherwise a it return a false.
bool split(const std::string& s, char delimiter, std::string pieces[], int expectedNumberOfPieces)
{
    std::stringstream ss;
    ss.str(s);
    std::string item;

    int i=0;
    while (std::getline(ss, item, delimiter) && i<expectedNumberOfPieces)
    {
        pieces[i++] = trim(item);
    }
    return (i==expectedNumberOfPieces);
}

int convertStringToInt(const std::string& s, bool* valid)
{
    int result = 0;
    if (valid!= nullptr)
        *valid = false;

    std::size_t numberOfConvertedCharacters = 0;
    if (s!="")
    {
        try {
            std::string trimmedString = trim(s);
            result = std::stoi(trimmedString, &numberOfConvertedCharacters);
            if (valid!=nullptr && numberOfConvertedCharacters==trimmedString.length())
                *valid = true;
            else if (numberOfConvertedCharacters!=trimmedString.length())
                result = 0;
        }
        catch (std::exception)
        {
            // do nothing, let the result remain 0 and the valid flag false
        }
    }

    return result;
}

unsigned int convertStringToUnsignedInt(const std::string& s, bool* valid)
{
    unsigned int result = 0;
    if (valid!= nullptr)
        *valid = false;

    std::size_t numberOfConvertedCharacters = 0;
    if (s!="")
    {
        try {
            std::string trimmedString = trim(s);
            if (trimmedString.substr(0,1)!="-")
            {
                unsigned long tmp = std::stoul(trimmedString, &numberOfConvertedCharacters);
                if (tmp <= UINT32_MAX)
                {
                    result = (unsigned int) tmp;
                    if (valid != nullptr && numberOfConvertedCharacters == trimmedString.length())
                        *valid = true;
                    else if (numberOfConvertedCharacters != trimmedString.length())
                        result = 0;
                }
            }
        }
        catch (std::exception)
        {
            // do nothing, let the result remain 0 and the valid flag false
        }
    }

    return result;
}

// Converts a string to a double
//
// Return the double value represented (0 if the string is not value) and set a valid flag, if provided, if the string
// represented an acceptable double.  The valid flag is a point to a bool.  If the pointer is null, then the function
// will still try to convert the string, but it will not try to set the valid flag.
double convertStringToDouble(const std::string& s, bool* valid)
{
    double result = 0;
    if (valid!= nullptr)
        *valid = false;

    std::size_t numberOfConvertedCharacters = 0;
    if (s!="")
    {
        try {
            std::string trimmedString = trim(s);
            result = std::stod(trimmedString, &numberOfConvertedCharacters);
            if (valid!=nullptr && numberOfConvertedCharacters==trimmedString.length())
                *valid = true;
            else if (numberOfConvertedCharacters!=trimmedString.length())
                result = 0;
        }
        catch (std::exception)
        {
            // do nothing, let the result remain 0 and the valid flag false
        }
    }

    return result;
}

//  Note: trim, leftTrim, and rightTrim were adapted from
//      http://stackoverflow.com/questions/25829143/c-trim-whitespace-from-a-string

// Removes leading whitespace, include space, tabs, newlines, and returns
std::string leftTrim(const std::string &inputStr) {
    std::string str = inputStr;
    auto it2 =  std::find_if( str.begin() , str.end() , IsNotWhiteSpace );
    str.erase( str.begin() , it2);
    return str;
}

// Removes trailing whitespace, include space, tabs, newlines, and returns
std::string rightTrim(const std::string &inputStr)
{
    std::string str = inputStr;
    auto it1 =  std::find_if( str.rbegin() , str.rend() , IsNotWhiteSpace );
    str.erase( it1.base() , str.end() );
    return str;
}

// Removes leading and trailing whitespace, include space, tabs, newlines, and returns
std::string trim(const std::string& str) {
    return leftTrim(rightTrim(str));
}

// Function to check if a character is a not a whitespace character, namely
//      space (0x20, ' ')
//      form feed (0x0c, '\f')
//      line feed (0x0a, '\n')
//      carriage return (0x0d, '\r')
//      horizontal tab (0x09, '\t')
//       vertical tab (0x0b, '\v')
bool IsNotWhiteSpace (char ch) {
    return !std::isspace<char>(ch , std::locale::classic() );
}