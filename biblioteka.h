//
// Created by Admin on 2021-12-17.
//

#ifndef V2_0_BIBLIOTEKA_H
#define V2_0_BIBLIOTEKA_H
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <random>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <list>
#include <chrono>
#include <numeric>
#include <stdexcept>


using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::stoi;
using std::getline;
using std::istringstream;
using std::swap;
using std::istream;
using std::streamsize;
using std::setprecision;
using std::max;
using std::list;
using std::setw;
using std::left;
using std::ofstream;
using std::accumulate;

class Person {
protected:
    string Vardas_;
    string Pavarde_;

public:
    Person(string, string);
    Person();
    ~Person();
    virtual void setVardas(string) = 0;
    virtual void setPavarde(string) = 0;
    string getVardas() const;
    string getPavarde() const;
};

class studentu_duom : public Person
{
public:
    studentu_duom();
    ~studentu_duom();
    void setVardas(string);
    void setPavarde(string);
    void setNamuDarbai(vector<double>);
    void setEgzaminas(int);
    string getVardas() const;
    string getPavarde() const;
    int getEgzaminas() const;
    double getGalutinisMed() const;
    double getGalutinisVid() const;
    studentu_duom& operator = (const studentu_duom& stud);
    bool operator<(const studentu_duom& s2);
    bool operator>(const studentu_duom& s2);
    bool operator!=(const studentu_duom& s2);
    bool operator ==(const studentu_duom& s2);
    void skaiciavimas();
    studentu_duom(const studentu_duom&);

private:
    vector<double> NamuDarbai;
    int Egzaminas;
    double Mediana;
    double Vidurkis;
    double GalutinisMed;
    double GalutinisVid;
};

void generavimas(size_t i);
void nuskaitymas(vector<studentu_duom>& Stud, string filename);
void ivedimas(vector<studentu_duom>& Stud);
void skaiciavimai(vector<studentu_duom>& Stud);
bool vargsiukai1(studentu_duom& Stud);
bool vargsiukai2(studentu_duom& Stud);
void GeneravimasIFaila(vector <studentu_duom>& Stud, vector <studentu_duom>& vargsiukai, vector <studentu_duom>& protinguoliai, int t);
void spausdinimas(vector<studentu_duom>& Stud, int t, string text);
bool skaiciai(const string& str);
int pasirinkimas();
bool teigiami (double vidurkis);
bool neigiami (double vidurkis);
double galutinis(double vidurkis, int exam);

#endif //V2_0_BIBLIOTEKA_H
