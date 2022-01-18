#include "StudentasKlase.h"
#include "FunksijosKlase.h"


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
    string silpnuoliuG = "silpnuoliai_klase" + to_string(studentuSkaicius) + ".txt";
    ofstream silp(silpnuoliuG);
    string kietuoliuG = "kietuoliai_klase" + to_string(studentuSkaicius) + ".txt";
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
