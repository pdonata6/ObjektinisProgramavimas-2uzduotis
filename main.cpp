
#include "biblioteka.h"
#include "funkcijos.h"

int main()
{
    std::chrono::steady_clock sc;
    string EntryChoice;
    int Entry;
    int t, p;
    vector <studentu_duom> Stud, vargsiukai, protinguoliai;
    Entry = pasirinkimas();

    for (int i = 0; i < 1; i++)
    {
        if (Entry == 1)
        {
            nuskaitymas(Stud, "kursiokai.txt");
            t = 2;
            skaiciavimai(Stud);
            sort(Stud.begin(), Stud.end());
            spausdinimas(Stud, t, "kursiokai2.txt");
        }
        else if (Entry == 2)
        {
            ivedimas(Stud);

            std::cout << "\nKaip norite apskaiciuoti studentu galutini pazymi?\nSpauskite:"
                         "\n1. Jei norite, jog butu naudojamas studento namu darbu rezultatu vidurkis"
                         "\n2. Jei norite, jog butu naudojama mediana. " << std::endl;
            int FMChoice;
            std::string Entry2;

            while (std::cin >> Entry2)
            {
                if (Entry2 == "1")
                {
                    FMChoice = 1;
                    break;
                }
                else if (Entry2 == "2")
                {
                    FMChoice = 2;
                    break;
                }
                else
                    std::cout << "Klaida, toks pasirinkimas negalimas" << std::endl;
            }
            std::cin.ignore();

            for (int i = 0; i < 1; i++)
            {
                if (FMChoice == 1)
                {
                    t = 1;
                    skaiciavimai(Stud);
                    sort(Stud.begin(), Stud.end());
                    spausdinimas(Stud, t, "Rezultatai.txt");
                }

                else if (FMChoice == 2)
                {
                    t = 0;
                    skaiciavimai(Stud);
                    sort(Stud.begin(), Stud.end());
                    spausdinimas(Stud, t, "Rezultatai.txt");
                }

                else
                {
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Klaida - veskite dar karta" << endl;
                    cin >> EntryChoice;
                    i--;
                }

            }
        }


        else if (Entry == 3)
        {
            int a;
            std::cout << "Jeigu norite naudoti jau sugeneruotus failus spauskite 1, bet jei norite generuoti is naujo spauskite 0\n";
            label:
            std::cin >> a;
            for (int i = 0; i < 1; i++)
            {

                if (a == 0)
                {

                    std::cout << "\nKaip norite apskaiciuoti studentu galutini pazymi?\nSpauskite:"
                                 "\n1. Jei norite, jog butu naudojamas studento namu darbu rezultatu vidurkis"
                                 "\n2. Jei norite, jog butu naudojama mediana. " << std::endl;
                    int FMChoice;
                    std::string Entry2;

                    while (std::cin >> Entry2)
                    {
                        if (Entry2 == "1")
                        {
                            FMChoice = 0;
                            break;
                        }
                        else if (Entry2 == "2")
                        {
                            FMChoice = 1;
                            break;
                        }
                        else
                        {
                            cin.clear();
                            cin.ignore(256, '\n');
                            cout << "Klaida,toks pasirinkimas negalimas - veskite dar karta" << endl;
                            cin >> EntryChoice;
                            i--;
                        }

                    }

                    string filename;
                    for (std::size_t i = 1000; i != 10000000; i *= 10)
                    {
                        Stud.clear();
                        auto Start = sc.now();
                        generavimas(i);
                        auto End = sc.now();
                        cout << i << " failo generavimas uztruko " << std::chrono::duration_cast<std::chrono::milliseconds>(End - Start).count() << " ms." << std::endl;
                    }


                    for (int i = 1000; i < 10000000; i * 10)
                    {

                        filename = "Studentai_" + std::to_string(i) + ".txt";
                        auto StartSorting = sc.now();
                        nuskaitymas(Stud, filename);

                        skaiciavimai(Stud);
                        sort(Stud.begin(), Stud.end());

                        GeneravimasIFaila(Stud, vargsiukai, protinguoliai, t);
                        spausdinimas(vargsiukai, t, "Kvaili_" + std::to_string(a) + ".txt");
                        spausdinimas(protinguoliai, t, "Protingi_" + std::to_string(a) + ".txt");

                        vargsiukai.clear();
                        Stud.clear();

                        auto EndSorting = sc.now();


                        cout << i << " skirstymas ir spausdinimas uztruko" << std::chrono::duration_cast<std::chrono::milliseconds>(EndSorting - StartSorting).count() << " ms." << std::endl;

                    }

                }

                else
                    goto label;
            }
        }
        else
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Klaida! Iveskite dar karta" << endl;
            cin >> EntryChoice;
            i--;
        }
    }
    return 0;
}