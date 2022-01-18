#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <numeric>
#include <list>
#include <chrono>
#include <iterator>

using namespace std;


struct studentu_duom {
    string Vardas, Pavarde;
    vector<int> ND;
    float gal_paz;
    int egz;
};


double NamuDarbuVidurkioSkaiciavimas(studentu_duom studentas);

void AtsitiktiniuStudentuDuomenuGeneravimas(int &studentuSkaicius, int &NDskaicius);

void NuskaitymasIsFailo(list<studentu_duom> &studentai, int studentuSkaicius, int NDskaicius);

void SkirstymasIGrupes(list<studentu_duom> studentai, list<studentu_duom> &kietuoliai,
                       list<studentu_duom> &silpnuoliai, int &silpni, int &kieti);

void Spausdinimas(int studentuSkaicius, list<studentu_duom> &kietuoliai,
                  list<studentu_duom> &silpnuoliai, int silpni, int kieti);

int main() {

    int NDskaicius = 4;
    string pavadinimas;
    int studentuSkaiciai[5] = {1000, 10000, 100000, 1000000, 10000000};

    list<studentu_duom> studentai;
    list<studentu_duom> kietuoliai;
    list<studentu_duom> silpnuoliai;

    int kieti = 0;
    int silpni = 0;

    for (int i : studentuSkaiciai) {
        int studentuSkaicius = i;
        AtsitiktiniuStudentuDuomenuGeneravimas(studentuSkaicius, NDskaicius);
        NuskaitymasIsFailo(studentai, studentuSkaicius, NDskaicius);
        SkirstymasIGrupes(studentai, kietuoliai, silpnuoliai, silpni, kieti);
        Spausdinimas(studentuSkaicius, kietuoliai, silpnuoliai, silpni, kieti);
    }

    return 0;
}

double NamuDarbuVidurkioSkaiciavimas(studentu_duom studentas) {
    double vidurkis =
            accumulate(studentas.ND.begin(), studentas.ND.end(), 0.0) / studentas.ND.size();
    return vidurkis;
}


void AtsitiktiniuStudentuDuomenuGeneravimas(int &studentuSkaicius, int &NDskaicius) {
    string pavadinimas = "Studentai" + to_string(studentuSkaicius) + ".txt";
    ofstream stud(pavadinimas);
    srand(time(NULL));
    for (int i = 0; i < studentuSkaicius; i++) {
        stud << "Vardas" + to_string(i + 1) << " " << "Pavarde" + to_string(i + 1) << " ";
        for (int j = 0; j < NDskaicius + 1; j++) { //+1 nes prisideda egzamino pazymys
            stud << rand() % 10 + 1 << " ";
        }
        stud << endl;
    }
}


void NuskaitymasIsFailo(list<studentu_duom> &studentai, int studentuSkaicius, int NDskaicius) {
    int indeksas = 0;
    ifstream fd;
    string pavadinimas = "Studentai" + to_string(studentuSkaicius) + ".txt";
    fd.open(pavadinimas);
    auto start = std::chrono::high_resolution_clock::now();
    auto startas = start;
    while (indeksas < studentuSkaicius) {
        studentu_duom studentas;
        fd >> studentas.Vardas;
        fd >> studentas.Pavarde;
        int ivestis;
        for (int i = 0; i < NDskaicius; i++) {
            fd >> ivestis;
            studentas.ND.push_back(ivestis);
        }
        fd >> studentas.egz;
        studentas.gal_paz = NamuDarbuVidurkioSkaiciavimas(studentas) * 0.4
                              + studentas.egz * 0.6;
        studentai.push_back(studentas);
        indeksas++;
    }
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << to_string(studentuSkaicius) << " studentu duomenu nuskaitymas "
                                           "uztruko (naudojant list): " << diff.count() << " s\n";

}

void SkirstymasIGrupes(list<studentu_duom> studentai, list<studentu_duom> &kietuoliai,
                       list<studentu_duom> &silpnuoliai, int &silpni, int &kieti) {

    list<studentu_duom>::iterator it;

    auto start = std::chrono::high_resolution_clock::now();
    auto startas = start;

    for (it = studentai.begin(); it != studentai.end(); ++it) {
        if (it->gal_paz < 5.00) {
            studentu_duom silpnas;
            silpnas.Vardas = it->Vardas;
            silpnas.Pavarde = it->Pavarde;
            silpnas.gal_paz = it->gal_paz;
            silpnuoliai.push_back(silpnas);
            silpni++;
        } else {
            studentu_duom kietas;
            kietas.Vardas = it->Vardas;
            kietas.Pavarde = it->Pavarde;
            kietas.gal_paz = it->gal_paz;
            kietuoliai.push_back(kietas);
            kieti++;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << "Studentu skirstymas i grupes uztruko (naudojant list): " << diff.count() << " s\n";
}

void Spausdinimas(int studentuSkaicius, list<studentu_duom> &kietuoliai,
                  list<studentu_duom> &silpnuoliai, int silpni, int kieti) {
    string silpnuoliuG = "Silpnuoliai_" + to_string(studentuSkaicius) + ".txt";
    ofstream silp(silpnuoliuG);
    string kietuoliuG = "Kietuoliai_" + to_string(studentuSkaicius) + ".txt";
    ofstream kiet(kietuoliuG);

    for (studentu_duom silpnas : silpnuoliai) {
        silp << silpnas.Vardas << " " <<
            silpnas.Pavarde << " " << fixed << setprecision(2) <<
            silpnas.gal_paz << endl;
    }
    for (studentu_duom kietas : kietuoliai) {
        kiet << kietas.Vardas << " " <<
                kietas.Pavarde << " " << fixed << setprecision(2) <<
                kietas.gal_paz << endl;
    }
    silpnuoliai.clear();
    kietuoliai.clear();
    cout << "-------------------------------------------------------------------------" << endl;
}
