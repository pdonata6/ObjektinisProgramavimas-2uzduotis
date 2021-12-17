//
// Created by Admin on 2021-12-17.
//

#ifndef V2_0_FUNKCIJOS_H
#define V2_0_FUNKCIJOS_H
#include "biblioteka.h"


Person::Person() {}

Person::Person(string Vardas, string Pavarde){
    Vardas_ = Vardas;
    Pavarde_ = Pavarde;
}

Person::~Person() {}

studentu_duom::studentu_duom(const studentu_duom& SenaKlase) {
    Vardas_ = SenaKlase.Vardas_;
    Pavarde_ = SenaKlase.Pavarde_;
    NamuDarbai = SenaKlase.NamuDarbai;
    Egzaminas = SenaKlase.Egzaminas;
    Mediana = SenaKlase.Mediana;
    Vidurkis = SenaKlase.Vidurkis;
    GalutinisMed = SenaKlase.GalutinisMed;
    GalutinisVid = SenaKlase.GalutinisVid;
}

studentu_duom::studentu_duom() {
    int Egzaminas = 0;
    double Vidurkis = 0.0;
    double Mediana = 0.0;
    double GalMed = 0.0;
    double GalVid = 0.0;
}

studentu_duom::~studentu_duom() {}

void studentu_duom::setVardas(string Vardas) {
    Vardas_ = Vardas;
}

void studentu_duom::setPavarde(string Pavarde) {
    Pavarde_ = Pavarde;
}

void studentu_duom::setNamuDarbai(vector<double> NamuDarbai_) {
    NamuDarbai = NamuDarbai_;
}

void studentu_duom::setEgzaminas(int Egzaminas_){
    Egzaminas = Egzaminas_;
}

int studentu_duom::getEgzaminas() const {
    return Egzaminas;
}

string studentu_duom::getVardas() const {
    return Vardas_;
}

string studentu_duom::getPavarde() const {
    return Pavarde_;
}

double studentu_duom::getGalutinisVid() const {
    return GalutinisVid;
}

double studentu_duom::getGalutinisMed() const {
    return GalutinisMed;
}

studentu_duom& studentu_duom::operator=(const studentu_duom& s) {
    if (&s == this)
        return *this;
    Vardas_ = s.getVardas();
    Pavarde_ = s.getPavarde();
    GalutinisVid = s.getGalutinisVid();
    GalutinisMed = s.getGalutinisMed();
    return *this;
}

bool studentu_duom::operator<(const studentu_duom& s2) {
    if (Vardas_ != s2.getVardas())
        return Vardas_ < s2.getVardas();
    else
        return Pavarde_ < s2.getPavarde();
}

bool studentu_duom::operator>(const studentu_duom& s2) {
    if (Vardas_ != s2.getVardas())
        return Vardas_ > s2.getVardas();
    else
        return Pavarde_ > s2.getPavarde();
}

bool studentu_duom::operator==(const studentu_duom& s2) {
    if (Vardas_ == s2.getVardas() &&
        Pavarde_ == s2.getPavarde() &&
        GalutinisMed == s2.getGalutinisMed() &&
        GalutinisVid == s2.getGalutinisVid())
    {
        return true;
    }
}

bool studentu_duom::operator!=(const studentu_duom& s2) {
    if(Vardas_ != s2.getVardas() ||
       Pavarde_ != s2.getPavarde() ||
       GalutinisVid != s2.getGalutinisVid() ||
       GalutinisMed != s2.getGalutinisMed())
    {
        return false;
    }
}

void studentu_duom::skaiciavimas() {
    sort(NamuDarbai.begin(), NamuDarbai.end());
    int position = NamuDarbai.size();

    if (position % 2 == 0) {
        Mediana = ((NamuDarbai.at(position / 2)) + (NamuDarbai.at(position / 2 - 1))) / 2;
    }
    else
    {
        Mediana = NamuDarbai.at(position / 2);
    }

    GalutinisMed = (0.4 * Mediana) + (0.6 * Egzaminas);

    for (int j = 0; j < NamuDarbai.size(); j++) {
        Vidurkis += NamuDarbai.at(j);
    }
    Vidurkis = Vidurkis / NamuDarbai.size();
    GalutinisVid = (0.4 * Vidurkis) + (0.6 * Egzaminas);
}

void generavimas(size_t i) {
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    default_random_engine eng(seed);
    uniform_int_distribution<int> Intervalas(1, 10), Amount(10, 20);

    int StudentuSkaicius = i,
            SkaiciusRez = Amount(eng);

    ofstream Rasymas;
    Rasymas.open("Studentai " + to_string(i) + ".txt");

    for(size_t j = 1; j <= StudentuSkaicius; j++){
        Rasymas << "Vardas" << j << "Pavarde" << j << Intervalas(eng);
        vector<int> rezultatai;
        vector<int> ::iterator IT;

        for (size_t k = 0; k < SkaiciusRez; k++)
            rezultatai.push_back(Intervalas(eng));

        for (IT = rezultatai.begin(); IT < rezultatai.end(); IT++)
            Rasymas << " " << *IT;

        Rasymas << endl;
    }
    Rasymas.close();
}

void nuskaitymas(vector<studentu_duom>& Stud, string filename){
    ifstream in(filename);

    string a;
    int NamuDarbuSK = 0;
    int l;
    studentu_duom Data;

    string Vardas, Pavarde;
    int egzaminas;

    vector<double> NamuDarbai1;

    if (!in){
        cout << "Toks failas neegzistuoja" << endl;
        exit(0);
    }

    in >> a >> a >> a;
    while (a[0] == 'N'){
        NamuDarbuSK++;
        in >> a;
    }

    while(!in.eof()){
        in >> Vardas >> Pavarde;

        Data.setVardas(Vardas);
        Data.setPavarde(Pavarde);

        for (int i = 0; i < NamuDarbuSK; i++)
            in >> i;
        if ((l <0) || (l > 10)){
            l = 0;
            cout << "Patikrinkite ar gerai ivedete pazymius" << endl;
        }
        NamuDarbai1.push_back(l);
    }

    in >> egzaminas;
    Data.setEgzaminas(egzaminas);

    Data.setNamuDarbai(NamuDarbai1);
    Stud.push_back(Data);
    NamuDarbai1.clear();

    in.close();
}

void ivedimas(vector<studentu_duom>& Stud){
    int n, l , egzaminas, pasirinkimas, k;
    string ka;
    string Vardas, Pavarde;
    vector<double> NamuDarbai1;

    cout << "Studentu skaicius: " << endl;
    label1:
    cin >> k;
    if(k > 0){
        studentu_duom Data;
        for (int i = 0; i < k; i++) {
            cout << "Iveskite studento varda ir pavarde: " << endl;
            cin >> Vardas;
            Data.setVardas(Vardas);
            cin >> Pavarde;
            Data.setPavarde(Pavarde);
            cout << "Kaip norite suvesti pazymius? \nSugeneruoti atsitiktinai, spauskite 1 \nNorite suvesti pats, spauskite - 0" << endl;
            cin >> pasirinkimas;

            if(pasirinkimas == 0){
                cout << "Iveskite egzamino pazymi: " << endl;
                label2:
                cin >> egzaminas;
                if (egzaminas > 0 and egzaminas < 11)
                    Data.setEgzaminas(egzaminas);
                else{
                    cout << "Toks pasirinkimas negalimas";
                    goto label2;
                }
                cout << "Iveskite namu darbu pazymiu skaiciu: " << endl;
                label3:
                cin >> n;
                if (egzaminas > 0){
                    cout << "Irasykite pazymius: " << endl;
                    for (int j = 0; j < n; j++) {
                        label4:
                        cin >> l;
                        if ( l > 0 and l <11){
                            NamuDarbai1.push_back(l);
                        }
                        else{
                            cout << "Toks pasirinkimas negalimas";
                            goto label4;
                        }
                    }
                }
                else{
                    cout << "Toks pasirinkimas negalimas";
                    goto label3;
                }
            }

            else if(pasirinkimas == 1){
                srand(time(0));
                Data.setEgzaminas((1 + rand() % 10));
                cout << "Iveskite namu darbu pazymiu skaiciu: " << endl;
                cin >> n;

                for (int j = 0; j < n; j++) {
                    l = (1 + rand() % 10);
                    NamuDarbai1.push_back(l);
                }
            }
        }

        Data.setNamuDarbai(NamuDarbai1);
        Stud.push_back(Data);
        NamuDarbai1.clear();
    }
    else {
        cout << "Bandykite dar karta" << endl;
        goto label1;
    }
}

void skaiciavimai(vector< studentu_duom>& Stud){
    for (int i = 0; i < Stud.size(); i++) {
        Stud.at(i).skaiciavimas();
    }
}

bool vargsiukai1(studentu_duom& Stud){
    return (Stud.getGalutinisVid() > 5);
}

bool vargsiukai2(studentu_duom& Stud){
    return (Stud.getGalutinisMed() > 5);
}

void GeneravimasIFaila(vector<studentu_duom>& Stud, vector<studentu_duom>& vargsiukai, vector<studentu_duom>& protinguoliai, int t){
    if ( t == 0){
        remove_copy_if(Stud.begin(), Stud.end(), back_inserter(vargsiukai), vargsiukai1);
        copy_if(Stud.begin(), Stud.end(), back_inserter(protinguoliai), vargsiukai1);

        Stud.erase(Stud.begin(), Stud.end());
    }
    else{
        std::remove_copy_if(Stud.begin(), Stud.end(), std::back_inserter(vargsiukai), vargsiukai2);
        std::copy_if(Stud.begin(), Stud.end(), std::back_inserter(protinguoliai), vargsiukai2);

        Stud.erase(Stud.begin(), Stud.end());
    }

}
void spausdinimas(vector <studentu_duom>& Stud, int t, string text)
{
    ofstream in(text);

    in << left << setw(25) << "Vardas:" << left << setw(30) << "Pavarde:";
    if (t == 1)
    {
        in << "Mediana" << endl;
    }
    else if (t == 2)
    {
        in << "Vidurkis" << " Mediana" << endl;
    }
    else
    {
        in << "Vidurkis" << endl;
    }

    for (int i = 0; i < Stud.size(); i++)
    {

        in << left << setw(25) << Stud.at(i).getVardas() << left << setw(30) << Stud.at(i).getPavarde();
        if (t != 1)
        {
            in << left << setw(9) << setprecision(3) << Stud.at(i).getGalutinisVid();
        }

        if (t != 0)
        {
            in << left << setw(9) << setprecision(2) << Stud.at(i).getGalutinisMed();
        }

        in << endl;
    }
    in.close();

}

int pasirinkimas()
{
    std::string Entry;
    int EntryChoice;
    std::cout << "Kaip norite gauti stendentu duomenis?\n Spauskite:"
                 "\n1. Jeigu norite duomenis nuskaityti is failo 'kursiokai.txt'"
                 "\n2. Jeigu norite duomenis ivesti pats/pati"
                 "\n3. Jeigu norite skaityti duomenis is sugeneruotu failu" << std::endl;

    while (std::cin >> Entry)
    {
        if (Entry == "1")
        {
            EntryChoice = 1;
            break;
        }
        else if (Entry == "2")
        {
            EntryChoice = 2;
            break;
        }
        else if (Entry == "3")
        {
            EntryChoice = 3;
            break;
        }
        else
            std::cout << "Klaida" << std::endl;
    }
    std::cin.ignore();
    return EntryChoice;
}

#endif //V2_0_FUNKCIJOS_H
