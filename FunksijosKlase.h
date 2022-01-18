
#ifndef V1_1_1_FUNKSIJOSKLASE_H
#define V1_1_1_FUNKSIJOSKLASE_H
void NuskaitymasKLASE(vector<studentu_duom> &studentai, int studentuSkaicius, int NDSkaicius);

void SkirstymasIGrupesKLASE(vector<studentu_duom> &studentai,
                            vector<studentu_duom> &kietuoliai, vector<studentu_duom> &silpnuoliai);

void SpausdinimasKLASE(int studentuSkaicius, const vector<studentu_duom> &kietuoliai,
                       const vector<studentu_duom> &silpnuoliai);
#endif //V1_1_1_FUNKSIJOSKLASE_H
