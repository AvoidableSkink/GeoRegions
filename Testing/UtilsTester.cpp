//
// Created by Stephen Clyde on 2/3/17.
//

#include "UtilsTester.h"

#include <iostream>
#include <cmath>

#include "../Utils.h"

void UtilsTester::testSplit()
{
    std::cout << "Execute UtilsTester::testSplit" << std::endl;

    // Check good cases

    std::string pieces[20];
    std::string lineToSplit = "ABC,DEF,GHI";
    if (split(lineToSplit, ',', pieces, 3)) {
        if (pieces[0] != "ABC" || pieces[1] != "DEF" || pieces[2] != "GHI") {
            std::cout << "Failure in split(lineToSplit, ',', pieces, 3) for lineToSplit=\""
                      << lineToSplit << "\": pieces not as expected" << std::endl;
            return;
        }
    } else {
        std::cout << "Failure in split(lineToSplit, ',', pieces, 3) for lineToSplit=\""
                  << lineToSplit << "\": result value not as expected" << std::endl;
        return;
    }

    lineToSplit = "ABCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC,D,E";
    if (split(lineToSplit, ',', pieces, 3)) {
        if (pieces[0] != "ABCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC" || pieces[1] != "D" || pieces[2] != "E") {
            std::cout << "Failure in split(lineToSplit, ',', pieces, 3) for lineToSplit=\""
                      << lineToSplit << "\": pieces not as expected" << std::endl;
            return;
        }
    } else {
        std::cout << "Failure in split(lineToSplit, ',', pieces, 3) for lineToSplit=\""
                  << lineToSplit << "\": result value not as expected" << std::endl;
        return;
    }

    lineToSplit = "ABCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDD";
    if (split(lineToSplit, ',', pieces, 1)) {
        if (pieces[0] != "ABCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDD" || pieces[1] != "D" || pieces[2] != "E") {
            std::cout << "Failure in split(lineToSplit, ',', pieces, 1) for lineToSplit=\""
                      << lineToSplit << "\": pieces not as expected" << std::endl;
            return;
        }
    } else {
        std::cout << "Failure in split(lineToSplit, ',', pieces, 1) for lineToSplit=\""
                  << lineToSplit << "\": result value not as expected" << std::endl;
        return;
    }

    lineToSplit = "MNO,PQR,STU";
    if (split(lineToSplit, ',', pieces, 0)) {
        if (pieces[0] != "ABCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDD" || pieces[1] != "D" || pieces[2] != "E") {
            std::cout << "Failure in split(lineToSplit, ',', pieces, 0) for lineToSplit=\""
                      << lineToSplit << "\": pieces not as expected" << std::endl;
            return;
        }
    } else {
        std::cout << "Failure in split(lineToSplit, ',', pieces, 0) for lineToSplit=\""
                  << lineToSplit << "\": result value not as expected" << std::endl;
        return;
    }

    lineToSplit = "MNO,,STU";
    if (split(lineToSplit, ',', pieces, 3)) {
        if (pieces[0] != "MNO" || pieces[1] != "" || pieces[2] != "STU") {
            std::cout << "Failure in split(lineToSplit, ',', pieces, 0) for lineToSplit=\""
                      << lineToSplit << "\": pieces not as expected" << std::endl;
            return;
        }
    } else {
        std::cout << "Failure in split(lineToSplit, ',', pieces, 0) for lineToSplit=\""
                  << lineToSplit << "\": result value not as expected" << std::endl;
        return;
    }

    // Check bad cases
    lineToSplit = "MNO,PQR,STU";
    if (split(lineToSplit, ',', pieces, 4)) {
        std::cout << "Failure in split(lineToSplit, ',', pieces, 0) for lineToSplit=\""
                  << lineToSplit << "\": result value not as expected" << std::endl;
        return;
    }
}

void UtilsTester::testConvertToInt()
{
    std::cout << "Execute UtilsTester::testConvertToInt" << std::endl;

    bool isValid;

    // Check good numbers

    std::string s = "123";
    int result = convertStringToInt(s, &isValid);
    if (result != 123 || !isValid) {
        std::cout << "Failure in convertStringToInt(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "  4567";
    result = convertStringToInt(s, &isValid);
    if (result != 4567 || !isValid) {
        std::cout << "Failure in convertStringToInt(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "1234567  ";
    result = convertStringToInt(s, &isValid);
    if (result != 1234567 || !isValid) {
        std::cout << "Failure in convertStringToInt(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "   1234567  ";
    result = convertStringToInt(s, &isValid);
    if (result != 1234567 || !isValid) {
        std::cout << "Failure in convertStringToInt(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "-1234567";
    result = convertStringToInt(s, &isValid);
    if (result != -1234567 || !isValid) {
        std::cout << "Failure in convertStringToInt(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "  -123";
    result = convertStringToInt(s);
    if (result != -123) {
        std::cout << "Failure in convertStringToInt(s) for s=\"" << s
                  << "\" and no valid flag, result=" << result << " isValid=" << isValid << std::endl;
        return;
    }
    // Check bad numbers

    s = "- 123";
    result = convertStringToInt(s, &isValid);
    if (result != 0 || isValid) {
        std::cout << "Failure in convertStringToInt(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "123.45";
    result = convertStringToInt(s, &isValid);
    if (result != 0 || isValid) {
        std::cout << "Failure in convertStringToInt(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "A123";
    result = convertStringToInt(s, &isValid);
    if (result != 0 || isValid) {
        std::cout << "Failure in convertStringToInt(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "1237A";
    result = convertStringToInt(s, &isValid);
    if (result != 0 || isValid) {
        std::cout << "Failure in convertStringToInt(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "12372355225233333223";
    result = convertStringToInt(s, &isValid);
    if (result != 0 || isValid) {
        std::cout << "Failure in convertStringToInt(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }
}

void UtilsTester::testConvertToUnsignedInt()
{
    std::cout << "Execute UtilsTester::testConvertToUnsignedInt" << std::endl;

    bool isValid;

    // Check good numbers

    std::string s = "123";
    unsigned int result = convertStringToUnsignedInt(s, &isValid);
    if (result != 123 || !isValid) {
        std::cout << "Failure in convertStringToUnsignedInt(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "  4567";
    result = convertStringToUnsignedInt(s, &isValid);
    if (result != 4567 || !isValid) {
        std::cout << "Failure in convertStringToUnsignedInt(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "1234567  ";
    result = convertStringToUnsignedInt(s, &isValid);
    if (result != 1234567 || !isValid) {
        std::cout << "Failure in convertStringToUnsignedInt(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "   1234567  ";
    result = convertStringToUnsignedInt(s, &isValid);
    if (result != 1234567 || !isValid) {
        std::cout << "Failure in convertStringToUnsignedInt(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    // Check bad numbers

    s = "-123";
    result = convertStringToUnsignedInt(s, &isValid);
    if (result != 0 || isValid) {
        std::cout << "Failure in convertStringToUnsignedInt(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "- 123";
    result = convertStringToUnsignedInt(s, &isValid);
    if (result != 0 || isValid) {
        std::cout << "Failure in convertStringToUnsignedInt(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "123.45";
    result = convertStringToUnsignedInt(s, &isValid);
    if (result != 0 || isValid) {
        std::cout << "Failure in convertStringToUnsignedInt(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "A123";
    result = convertStringToUnsignedInt(s, &isValid);
    if (result != 0 || isValid) {
        std::cout << "Failure in convertStringToUnsignedInt(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "1237A";
    result = convertStringToUnsignedInt(s, &isValid);
    if (result != 0 || isValid) {
        std::cout << "Failure in convertStringToUnsignedInt(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "12372355225233333223";
    result = convertStringToUnsignedInt(s, &isValid);
    if (result != 0 || isValid) {
        std::cout << "Failure in convertStringToUnsignedInt(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }
}


void UtilsTester::testConvertToDouble()
{
    std::cout << "Execute UtilsTester::testConvertToDouble" << std::endl;

    bool isValid;

    // Check good numbers

    std::string s = "123.4567";
    double result = convertStringToDouble(s, &isValid);
    if (result != 123.4567 || !isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "  123.4567";
    result = convertStringToDouble(s, &isValid);
    if (result != 123.4567 || !isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "123.4567  ";
    result = convertStringToDouble(s, &isValid);
    if (result != 123.4567 || !isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "   123.4567  ";
    result = convertStringToDouble(s, &isValid);
    if (result != 123.4567 || !isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "-123.4567";
    result = convertStringToDouble(s, &isValid);
    if (result != -123.4567 || !isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "1.234567e2";
    result = convertStringToDouble(s, &isValid);
    if (result != 123.4567 || !isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "12345.67e-2";
    result = convertStringToDouble(s, &isValid);
    if (result != 123.4567 || !isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "INF";
    result = convertStringToDouble(s, &isValid);
    if (result != INFINITY || !isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "INFINITY";
    result = convertStringToDouble(s, &isValid);
    if (result != INFINITY || !isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "123.4567";
    result = convertStringToDouble(s, nullptr);
    if (result != 123.4567) {
        std::cout << "Failure in convertStringToDouble(s) for s=\"" << s
                  << "\" and no valid flag, result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "-12.456";
    result = convertStringToDouble(s);
    if (result != -12.456) {
        std::cout << "Failure in convertStringToDouble(s) for s=\"" << s
                  << "\" and no valid flag, result=" << result << " isValid=" << isValid << std::endl;
        return;
    }
    // Check bad numbers

    s = "- 123.4567";
    result = convertStringToDouble(s, &isValid);
    if (result != 0 || isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "123.45.67";
    result = convertStringToDouble(s, &isValid);
    if (result != 0 || isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "A123.4567";
    result = convertStringToDouble(s, &isValid);
    if (result != 0 || isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "123.4567A";
    result = convertStringToDouble(s, &isValid);
    if (result != 0 || isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

}

void UtilsTester::testLeftTrim()
{
    std::cout << "Execute UtilsTester::testLeftTrim" << std::endl;

    std::string s = "ABC";
    std::string result = leftTrim(s);
    if (result != "ABC") {
        std::cout << "Failure in trim(s) for s=\"" << s
                  << "\" result=" << result << std::endl;
        return;
    }

    s = "   ABC";
    result = leftTrim(s);
    if (result != "ABC") {
        std::cout << "Failure in trim(s) for s=\"" << s
                  << "\" result=" << result << std::endl;
        return;
    }

    s = "ABC    ";
    result = leftTrim(s);
    if (result != "ABC    ") {
        std::cout << "Failure in trim(s) for s=\"" << s
                  << "\" result=" << result << std::endl;
        return;
    }

    s = "    ABC    ";
    result = leftTrim(s);
    if (result != "ABC    ") {
        std::cout << "Failure in trim(s) for s=\"" << s
                  << "\" result=" << result << std::endl;
        return;
    }

    s = "\t\tABC\t\t";
    result = leftTrim(s);
    if (result != "ABC\t\t") {
        std::cout << "Failure in trim(s) for s=\"" << s
                  << "\" result=" << result << std::endl;
        return;
    }

    s = "\nABC\n";
    result = leftTrim(s);
    if (result != "ABC\n") {
        std::cout << "Failure in trim(s) for s=\"" << s
                  << "\" result=" << result << std::endl;
        return;
    }

    s = "";
    result = leftTrim(s);
    if (result != "") {
        std::cout << "Failure in trim(s) for s=\"" << s
                  << "\" result=" << result << std::endl;
        return;
    }

    s = "      ";
    result = leftTrim(s);
    if (result != "") {
        std::cout << "Failure in trim(s) for s=\"" << s
                  << "\" result=" << result << std::endl;
        return;
    }

    s = "      \t\t\n\t    ";
    result = trim(s);
    if (result != "") {
        std::cout << "Failure in trim(s) for s=\"" << s
                  << "\" result=" << result << std::endl;
        return;
    }

}


void UtilsTester::testRightTrim()
{
    std::cout << "Execute UtilsTester::testRightTrim" << std::endl;

    std::string s = "ABC";
    std::string result = rightTrim(s);
    if (result != "ABC") {
        std::cout << "Failure in trim(s) for s=\"" << s
                  << "\" result=" << result << std::endl;
        return;
    }

    s = "   ABC";
    result = rightTrim(s);
    if (result != "   ABC") {
        std::cout << "Failure in trim(s) for s=\"" << s
                  << "\" result=" << result << std::endl;
        return;
    }

    s = "ABC    ";
    result = rightTrim(s);
    if (result != "ABC") {
        std::cout << "Failure in trim(s) for s=\"" << s
                  << "\" result=" << result << std::endl;
        return;
    }

    s = "    ABC    ";
    result = rightTrim(s);
    if (result != "    ABC") {
        std::cout << "Failure in trim(s) for s=\"" << s
                  << "\" result=" << result << std::endl;
        return;
    }

    s = "\t\tABC\t\t";
    result = rightTrim(s);
    if (result != "\t\tABC") {
        std::cout << "Failure in trim(s) for s=\"" << s
                  << "\" result=" << result << std::endl;
        return;
    }

    s = "\nABC\n";
    result = rightTrim(s);
    if (result != "\nABC") {
        std::cout << "Failure in trim(s) for s=\"" << s
                  << "\" result=" << result << std::endl;
        return;
    }

    s = "";
    result = rightTrim(s);
    if (result != "") {
        std::cout << "Failure in trim(s) for s=\"" << s
                  << "\" result=" << result << std::endl;
        return;
    }

    s = "      ";
    result = rightTrim(s);
    if (result != "") {
        std::cout << "Failure in trim(s) for s=\"" << s
                  << "\" result=" << result << std::endl;
        return;
    }

    s = "      \t\t\n\t    ";
    result = rightTrim(s);
    if (result != "") {
        std::cout << "Failure in trim(s) for s=\"" << s
                  << "\" result=" << result << std::endl;
        return;
    }

}

void UtilsTester::testTrim()
{
    std::cout << "Execute UtilsTester::testTrim" << std::endl;

    std::string s = "ABC";
    std::string result = trim(s);
    if (result != "ABC") {
        std::cout << "Failure in trim(s) for s=\"" << s
                  << "\" result=" << result << std::endl;
        return;
    }

    s = "   ABC";
    result = trim(s);
    if (result != "ABC") {
        std::cout << "Failure in trim(s) for s=\"" << s
                  << "\" result=" << result << std::endl;
        return;
    }

    s = "ABC    ";
    result = trim(s);
    if (result != "ABC") {
        std::cout << "Failure in trim(s) for s=\"" << s
                  << "\" result=" << result << std::endl;
        return;
    }

    s = "    ABC    ";
    result = trim(s);
    if (result != "ABC") {
        std::cout << "Failure in trim(s) for s=\"" << s
                  << "\" result=" << result << std::endl;
        return;
    }

    s = "\t\tABC\t\t";
    result = trim(s);
    if (result != "ABC") {
        std::cout << "Failure in trim(s) for s=\"" << s
                  << "\" result=" << result << std::endl;
        return;
    }

    s = "\nABC\n";
    result = trim(s);
    if (result != "ABC") {
        std::cout << "Failure in trim(s) for s=\"" << s
                  << "\" result=" << result << std::endl;
        return;
    }

    s = "";
    result = trim(s);
    if (result != "") {
        std::cout << "Failure in trim(s) for s=\"" << s
                  << "\" result=" << result << std::endl;
        return;
    }

    s = "      ";
    result = trim(s);
    if (result != "") {
        std::cout << "Failure in trim(s) for s=\"" << s
                  << "\" result=" << result << std::endl;
        return;
    }

    s = "      \t\t\n\t    ";
    result = trim(s);
    if (result != "") {
        std::cout << "Failure in trim(s) for s=\"" << s
                  << "\" result=" << result << std::endl;
        return;
    }


}

