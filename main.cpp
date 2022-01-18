#include "StudentasKlase.h"
#include "FunksijosKlase.h"
#include "StudentasStruct.h"
#include "FunkcijosStruct.h"

int main() {

    int NDSkaicius = 4;
    string pavadinimas;
    int studentuSkaiciai[2] = {100000, 1000000};

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

    vector<StudentasStruct> studentaiStruct;
    vector<StudentasStruct> kietuoliaiStruct;
    vector<StudentasStruct> silpnuoliaiStruct;

    for (int i : studentuSkaiciai) {
        int studentuSkaicius = i;
        NuskaitymasIsFailo(studentaiStruct, studentuSkaicius, NDSkaicius);
        SkirstymasIGrupes(studentaiStruct, kietuoliaiStruct, silpnuoliaiStruct);
        Spausdinimas(studentuSkaicius, kietuoliaiStruct, silpnuoliaiStruct);
    }

    return 0;
}
