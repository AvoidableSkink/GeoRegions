//
// Created by Stephen Clyde on 2/3/17.
//

#ifndef GEO_REGIONS_UTILS_H
#define GEO_REGIONS_UTILS_H

#include <string>
#include <fstream>

std::string getStringInput(std::string prompt);

bool split(const std::string& s, char delimiter, std::string elements[], int expectedNumberOfElements);
int convertStringToInt(const std::string& s, bool* valid = nullptr);
unsigned int convertStringToUnsignedInt(const std::string& s, bool* valid = nullptr);
double convertStringToDouble(const std::string& s, bool* valid = nullptr);

std::string leftTrim(const std::string &str);
std::string rightTrim(const std::string &str);
std::string trim(const std::string& str);
bool IsNotWhiteSpace (char ch);


#endif //GEO_REGIONS_UTILS_H
