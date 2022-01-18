#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <numeric>



using namespace std;


class Zmogus
{
protected:
    string Vardas;
    string Pavarde;

public:
    Zmogus() {};
    ~Zmogus() {};
    virtual string getVardas() const = 0;
    virtual string getPavarde() const = 0;
};

class studentu_duom: public Zmogus {
private:
    vector<int> ND;
    int egz;
public:
    studentu_duom() : egz(0) {};
    studentu_duom(ifstream& fd, int NDSkaicius);
    string getVardas() const {return Vardas;}
    string getPavarde() const {return Pavarde;}
    double getGalutinis();
    void readStudentas(ifstream&, int);
};

studentu_duom::studentu_duom(ifstream& fd, int NDSkaicius){
    readStudentas(fd, NDSkaicius);
}

double studentu_duom::getGalutinis() {
    double galutinis = 0.4 * (accumulate(this -> ND.begin(), this ->ND.end(), 0.0)
            / this -> ND.size()) + 0.6 * this -> egz;
    return galutinis;
}

void studentu_duom::readStudentas(ifstream &fd, int NDSkaicius) {
    fd >> this -> Vardas >> this -> Pavarde;
    this -> ND.reserve(NDSkaicius);
    for (int i = 0; i < NDSkaicius; i++) {
        int ivestis;
        fd >> ivestis;
        this -> ND.push_back(ivestis);
    }
    fd >> this -> egz;
}

void NuskaitymasKLASE(vector<studentu_duom> &studentai, int studentuSkaicius, int NDSkaicius);

void SkirstymasIGrupesKLASE(vector<studentu_duom> &studentai,
                            vector<studentu_duom> &kietuoliai, vector<studentu_duom> &silpnuoliai);

void SpausdinimasKLASE(int studentuSkaicius, const vector<studentu_duom> &kietuoliai,
                       const vector<studentu_duom> &silpnuoliai);


void NuskaitymasKLASE(vector<studentu_duom> &studentai, int studentuSkaicius, int NDSkaicius) {
    studentai.reserve(studentuSkaicius);
    ifstream fd;
    string pavadinimas = "Studentai" + to_string(studentuSkaicius) + ".txt";
    fd.open(pavadinimas);
    auto start = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < studentuSkaicius; i++)
    {
        studentu_duom laikinas;
        laikinas.readStudentas(fd, NDSkaicius);
        studentai.push_back(laikinas);
    }
    fd.close();

    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << to_string(studentuSkaicius) << " studentu duomenu nuskaitymas "
                                           "uztruko (naudojant class): " << diff.count() << " s\n";

}


void SkirstymasIGrupesKLASE(vector<studentu_duom> &studentai,
                            vector<studentu_duom> &kietuoliai, vector<studentu_duom> &silpnuoliai) {

    auto start = std::chrono::high_resolution_clock::now();
    for (auto &i : studentai) {
        if (i.getGalutinis() < 5.00) {
            silpnuoliai.push_back(i);
        } else {
            kietuoliai.push_back(i);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << "Studentu skirstymas i grupes uztruko (naudojant class): " << diff.count() << " s\n";
}

void SpausdinimasKLASE(int studentuSkaicius, const vector<studentu_duom> &kietuoliai,
                       const vector<studentu_duom> &silpnuoliai) {
    string silpnuoliuG = "Silpnuoliai_" + to_string(studentuSkaicius) + ".txt";
    ofstream silp(silpnuoliuG);
    string kietuoliuG = "Kietuoliai_" + to_string(studentuSkaicius) + ".txt";
    ofstream kiet(kietuoliuG);

    for (studentu_duom elementas:silpnuoliai) {
        silp << elementas.getVardas() << " " << elementas.getPavarde() << " "
            << fixed << setprecision(2) << elementas.getGalutinis() << endl;
    }
    for (studentu_duom elementas : kietuoliai) {
        kiet << elementas.getVardas() << " " << elementas.getPavarde() << " " << fixed << setprecision(2) <<
              elementas.getGalutinis() << endl;
    }
    cout << "-------------------------------------------------------------------------" << endl;
}

int main() {

    int NDSkaicius = 4;
    string pavadinimas;
    int studentuSkaiciai[2] = {10000, 100000};

    vector<studentu_duom> studentai;
    vector<studentu_duom> kietuoliai;
    vector<studentu_duom> silpnuoliai;

    for (int i : studentuSkaiciai) {
        int studentuSkaicius = i;
        NuskaitymasKLASE(studentai, studentuSkaicius, NDSkaicius);
        SkirstymasIGrupesKLASE(studentai, kietuoliai, silpnuoliai);
        SpausdinimasKLASE(studentuSkaicius, kietuoliai, silpnuoliai);
        studentai.clear();
        kietuoliai.clear();
        silpnuoliai.clear();
    }
}
