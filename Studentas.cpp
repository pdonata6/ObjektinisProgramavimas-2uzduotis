
#include "StudentasKlase.h"

studentu_duom::studentu_duom(ifstream& fd, int NDSkaicius)
{
    readStudentas(fd, NDSkaicius);
}

double studentu_duom::getGalutinis() {
    double galutinis = 0.4 * (accumulate(this->ND.begin(), this->ND.end(), 0.0)
                              / this->ND.size()) + 0.6 * this -> egz;
    return galutinis;
}

void studentu_duom::readStudentas(ifstream &fd, int namuDarbuSkaicius) {
    fd >> this->Vardas >> this->Pavarde;
    this->ND.reserve(namuDarbuSkaicius);
    for (int i = 0; i < namuDarbuSkaicius; i++)
    {
        int ivestis;
        fd >> ivestis;
        this->ND.push_back(ivestis);
    }
    fd >> this-> egz;
}
