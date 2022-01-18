
#ifndef V1_1_1_STUDENTASKLASE_H
#define V1_1_1_STUDENTASKLASE_H
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <numeric>
#include <fstream>
#include <chrono>
using namespace std;
class studentu_duom {
private:
    string Vardas, Pavarde;
    vector<int> ND;
    int egz;
public:
    studentu_duom() : egz(0) {};
    studentu_duom(ifstream& fd, int namuDarbuSkaicius);
    inline string getVardas() const { return Vardas;}
    inline string getPavarde() const { return Pavarde;}
    double getGalutinis();
    void readStudentas(ifstream&, int);

};
#endif //V1_1_1_STUDENTASKLASE_H
