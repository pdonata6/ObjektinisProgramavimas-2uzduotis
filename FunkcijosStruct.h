#ifndef V1_1_1_FUNKCIJOSSTRUCT_H
#define V1_1_1_FUNKCIJOSSTRUCT_H
double NamuDarbuVidurkioSkaiciavimas(StudentasStruct studentas);

void NuskaitymasIsFailo(vector<StudentasStruct> &studentai, int studentuSkaicius, int NDSkaicius);

void SkirstymasIGrupes(vector<StudentasStruct> &studentai,
                       vector<StudentasStruct> &kietuoliai, vector<StudentasStruct> &silpnuoliai);

void Spausdinimas(int studentuSkaicius, const vector<StudentasStruct> &kietuoliai,
                  const vector<StudentasStruct> &silpnuoliai);
#endif //V1_1_1_FUNKCIJOSSTRUCT_H
