//
// Created by Stephen Clyde on 3/4/17.
//

#include <iostream>
#include "UtilsTester.h"
#include "RegionTester.h"

int main() {

    std::cout << "Execute Test Cases" << std::endl;

    UtilsTester utilsTester;
    utilsTester.testSplit();
    utilsTester.testConvertToInt();
    utilsTester.testConvertToUnsignedInt();
    utilsTester.testConvertToDouble();
    utilsTester.testLeftTrim();
    utilsTester.testRightTrim();
    utilsTester.testTrim();

    RegionTester regionTester;
    regionTester.testCreateFromStream();
    regionTester.testCreateFromString();
    regionTester.testCreateFromTypeAndString();
    regionTester.testGettersAndSetters();
    regionTester.testSubRegions();
    regionTester.testComputeTotalPopulation();

}