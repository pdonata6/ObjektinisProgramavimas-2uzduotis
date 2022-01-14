#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <list>
#include <chrono>
#include <random>
#include <numeric>
#include <stdexcept>

using namespace std;

class studentu_duom
{
private:
    string Vardas, Pavarde;
    vector<int> NamuDarbai;
    int Egzaminas;
public:
    studentu_duom() : NamuDarbai(0) { }; //konstruktorius

    ~studentu_duom() //destructor
    = default;

    void setStudentas(string, string, string);
    void setNamuDarbai(int);
    void TustiNd();
    string getVardas() const { return Vardas; }
    string getPavarde() const { return Pavarde; }
    double gal_paz(int, double);
    double gal_paz(int, const vector<int>);
    double gal_paz(double (*) (vector<int>));
};

double Mediana(vector<int> paz);
double Vidurkis(vector<int>);


void studentu_duom::setStudentas(std::string vardas_, std::string pavarde_, std::string egzaminas_)
{
    Vardas = vardas_;
    Pavarde = pavarde_;
    Egzaminas = std::stoi(egzaminas_);
}

void studentu_duom::setNamuDarbai(int paz)
{
    NamuDarbai.push_back(paz);
}


void studentu_duom::TustiNd()
{
    NamuDarbai.clear();
}

double studentu_duom::gal_paz(int egzaminas, double pazymys)
{
    return 0.4 * pazymys + 0.6 * egzaminas;
}

double studentu_duom::gal_paz(int egzaminas, const std::vector<int> pazymys)
{
    if (NamuDarbai.size() == 0)
        throw std::domain_error("Nera pazymiu.");
    return gal_paz(Egzaminas, Vidurkis(NamuDarbai));
}

double studentu_duom::gal_paz(double (*pasirinkimas)(std::vector<int>))
{
    return gal_paz(Egzaminas, pasirinkimas(NamuDarbai));
}


double Vidurkis(std::vector<int> pazymys)
{
    return accumulate(pazymys.begin(), pazymys.end(), 0.0) / pazymys.size();
}

double Mediana(vector<int> pazymys)
{
    sort(pazymys.begin(), pazymys.end());

    if (pazymys.size() % 2 == 0)
    {
        return float(((pazymys[pazymys.size() / 2]) + (pazymys[(pazymys.size() / 2 + 1)])) / 2.0);
    }
    else
    {
        return float(pazymys[(pazymys.size() / 2)]);
    }
}

int main() {
    vector<studentu_duom> stud;
    studentu_duom Student;
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine eng(seed);
    std::uniform_int_distribution<int> dist(1, 10);
    int pasirinkimas;

    cout<< "Spauskite '1' norint sugeneruoti failus";
    cin >> pasirinkimas;
    while (pasirinkimas != 1) {

        if (pasirinkimas == 1)
            break;
        cout << "Netinkama reiksme. Pakartokite.\n";
        cout<< "Spauskite '1' norint sugeneruoti failus";
        cin >> pasirinkimas;
        cin.clear();
        cin.ignore();
        cin >> pasirinkimas;

    }


    if (pasirinkimas == 1) {
        for (size_t i = 1000; i <= 10000000; i *= 10) {
            stud.clear();
            string vardas_, pavarde_, egz_;
            string line;
            int Entry;

            auto StartGenerating = std::chrono::high_resolution_clock::now();
            unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
            std::default_random_engine eng(seed);
            std::uniform_int_distribution<int> Interval(1, 10), Amount(5, 20);
            int paz = Amount(eng);
            int NumberOfStudents = i;

            ofstream Write;
            Write.open("Studentai_" + std::to_string(i) + ".txt");

            for (size_t j = 1; j <= NumberOfStudents; j++) {
                Write << "Vardas" + std::to_string(j) << " Pavarde" + std::to_string(j) << " " << Interval(eng);

                vector<int> nd;
                vector<int>::iterator it;

                for (size_t k = 0; k < paz; k++)
                    nd.push_back(Interval(eng));

                for (it = nd.begin(); it < nd.end(); it++)
                    Write << " " << *it;

                Write << endl;
            }
            Write.close();
            auto EndGenerating = std::chrono::high_resolution_clock::now();
            cout << "Studentai_" + std::to_string(i) + ".txt generavimas uztruko "
                 << std::chrono::duration_cast<std::chrono::milliseconds>(EndGenerating - StartGenerating).count()
                 << " ms." << endl;
            stud.clear();

            // Sugeneruotu failu skaitymas

            auto StartReading = std::chrono::high_resolution_clock::now();
            ifstream failas("Studentai_" + std::to_string(i) + ".txt");


            try {
                if (!failas.good())
                    throw "Tokio failo nera";
            }
            catch (const char *Message) {
                cout << Message << endl;
            }

            while (getline(failas, line)) {
                istringstream ReadLine(line);
                ReadLine >> vardas_ >> pavarde_ >> egz_;
                Student.setStudentas(vardas_, pavarde_, egz_);
                if (ReadLine) {
                    Student.TustiNd();
                    while (ReadLine >> Entry) {

                        Student.setNamuDarbai(Entry);

                    }

                    stud.push_back(Student);
                    ReadLine.clear();
                }
                ReadLine.end;
            }
            auto EndReading = std::chrono::high_resolution_clock::now();
            cout << "Failo su " + std::to_string(i) + " studentais nuskaitymas uztruko:  "
                 << std::chrono::duration_cast<std::chrono::milliseconds>(EndReading - StartReading).count() << " ms."
                 << endl;

            // Sugeneruotu failu rusiavimas

            auto StartSorting = std::chrono::high_resolution_clock::now();
            vector<studentu_duom> Vargsiukai;
            vector<studentu_duom> Protinguoliai;
            vector<studentu_duom>::iterator student = stud.begin();
            while (student != stud.end()) {
                if ((*student).gal_paz(Vidurkis) < 5.0) {
                    Vargsiukai.push_back(*student);
                } else {
                    Protinguoliai.push_back(*student);
                }
                student++;
            }


            ofstream Vargsiukai_to_file;
            Vargsiukai_to_file.open("Vargsiukai.txt");

            Vargsiukai_to_file << "Vardas" << " " << "Pavarde" << " " <<
                               "Galutinis" << endl;

            for (vector<studentu_duom>::iterator student = Vargsiukai.begin(); student != Vargsiukai.end(); student++) {
                Vargsiukai_to_file << (*student).getVardas() << " " << (*student).getPavarde() << " " <<
                                   setprecision(2) << (*student).gal_paz(Vidurkis) << endl;
            }
            Vargsiukai_to_file.close();

            ofstream Protinguoliai_to_file;
            Protinguoliai_to_file.open("Protinguoliai.txt");

            Protinguoliai_to_file << "Vardas" << " " << "Pavarde" << " " <<
                                  "Galutinis" << endl;

            for (vector<studentu_duom>::iterator student = Protinguoliai.begin();
                 student != Protinguoliai.end(); student++) {
                Protinguoliai_to_file << (*student).getVardas() << " " << (*student).getPavarde() << " " <<
                                      setprecision(2) << (*student).gal_paz(Vidurkis) << endl;
            }
            Protinguoliai_to_file.close();

            auto EndSorting = std::chrono::high_resolution_clock::now();
            cout << "Studentu skirstymas ir isvedimas i grupes uztruko:  "
                 << std::chrono::duration_cast<std::chrono::milliseconds>(EndSorting - StartSorting).count() << " ms."
                 << endl;
        }
    }
    return 0;
}
