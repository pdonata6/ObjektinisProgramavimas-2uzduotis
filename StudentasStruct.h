
#ifndef V1_1_1_STUDENTASSTRUCT_H
#define V1_1_1_STUDENTASSTRUCT_H
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <numeric>
#include <fstream>
#include <chrono>

using namespace std;
struct StudentasStruct {
    string Vardas, Pavarde;
    vector<int> ND;
    int egz;
    double gal_paz;
};
#endif //V1_1_1_STUDENTASSTRUCT_H
