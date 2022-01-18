#include "StudentasStruct.h"
#include "FunkcijosStruct.h"


double NamuDarbuVidurkioSkaiciavimas(StudentasStruct studentas) {
    double vidurkis = accumulate(studentas.ND.begin(), studentas.ND.end(), 0.0) / studentas.ND.size();
    return vidurkis;
}

void NuskaitymasIsFailo(vector<StudentasStruct> &studentai, int studentuSkaicius, int NDSkaicius) {
    int indeksas = 0;
    ifstream fd;
    string pavadinimas = "Studentai" + to_string(studentuSkaicius) + ".txt";
    fd.open(pavadinimas);
    auto start = std::chrono::high_resolution_clock::now();
    auto startas = start;
    while (indeksas < studentuSkaicius) {
        studentai.resize(studentai.size() + 1);
        fd >> studentai.at(indeksas).Vardas;
        fd >> studentai.at(indeksas).Pavarde;
        int ivestis;
        for (int i = 0; i < NDSkaicius; i++) {
            fd >> ivestis;
            studentai.at(indeksas).ND.push_back(ivestis);
        }
        fd >> studentai.at(indeksas).egz;
        studentai.at(indeksas).gal_paz = NamuDarbuVidurkioSkaiciavimas(studentai.at(indeksas)) * 0.4
                                           + studentai.at(indeksas).egz * 0.6;
        indeksas++;
    }
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << to_string(studentuSkaicius) << " studentu duomenu nuskaitymas "
                                           "uztruko (naudojant struct): " << diff.count() << " s\n";
}

void SkirstymasIGrupes(vector<StudentasStruct> &studentai,
                       vector<StudentasStruct> &kietuoliai, vector<StudentasStruct> &silpnuoliai) {

    auto start = std::chrono::high_resolution_clock::now();
    auto startas = start;
    for (auto &i : studentai) {
        if (i.gal_paz < 5.00) {
            silpnuoliai.push_back(i);
        } else {
            kietuoliai.push_back(i);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << "Studentu skirstymas i grupes uztruko (naudojant struct): " << diff.count() << " s\n";
}

void Spausdinimas(int studentuSkaicius, const vector<StudentasStruct> &kietuoliai,
                  const vector<StudentasStruct> &silpnuoliai) {
    string silpnuoliuG = "silpnuoliai_struct " + to_string(studentuSkaicius) + ".txt";
    ofstream silp(silpnuoliuG);
    string kietuoliuG = "kietuoliai_struct" + to_string(studentuSkaicius) + ".txt";
    ofstream kiet(kietuoliuG);

    for (const auto &elementas:silpnuoliai) {
        silp << elementas.Vardas << " " << elementas.Pavarde << " "
            << fixed << setprecision(2) << elementas.gal_paz << endl;
    }
    for (const auto &elementas : kietuoliai) {
        kiet << elementas.Vardas << " " << elementas.Pavarde << " " << fixed << setprecision(2) <<
              elementas.gal_paz << endl;
    }
    cout << "-------------------------------------------------------------------------" << endl;
}
