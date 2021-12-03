# **Įdiegimo ir naudojimosi instrukcija**

• Norinti gauti programą pirmiausia reikia parsisiųsti vieną iš jos versijų iš [https://github.com/pdonata6/Programavimas-Pirmas/releases](url)

• Parsisiųsti ir įsidiegti C++ kompiliatorių (pvz. GCC)

• Atsidaryti terminalą ir jame įvesti programos vietą diske

• Sukompiliuoti programą

• Programos naudojimasis bus paprastas, nes visi nurodymai bus parodomi ekrane.


# <span style="color: green"> **v0.1** </span>

- Pirmiausia įrašome studentų kiekį, tuomet pagal studentų skaičių atitinkamai ir duomenis apie juos(vardus ir pavardes). 
- Pasirenkame, kaip bus įvedami pažymiai A(automatiškai sugeneruoti skaičiai) arba įvedami pačio vartotojo). 
- Pasirinkus kaip įvesime pažymius, jeigu automatiškai - įvedame pažymių kiekį, o jeigu visgi norime įrašyti patys suvedame pažymius ir norint užbaigti rašome (-1). 
- Galiausiai išvedami studentų duomenys (vardas, pavardė, galutinis pažymys).
 

# _**v0.2**_ 
Programą (v0.1) su vektoriumi papildome taip, kad būtų galima nuskaityti ir duomenis iš failo. Kai duomenys yra nuskaitomi, rezultatas patalpinamas į failą "rezultatai.txt"



# _**v0.3**_
Sukuriame header ir cpp failus, bei pridetas exception, kai failas nuskaitomas, tada patikrina ar failo pavadinimas gerai įvestas ar ne. Jei ne, išspausdina, kad tokio failo nėra.


# _**v0.4**_
Programa paprašo įvesti esamų studentų kiekį ir juos suveda į vieną .txt failą, tada vėl šitas failas nuskaitomas ir studentus suskirsto į 2 grupes- silpnuolius ir keituolius. Studentai perkeliami į silpnųjų sąrašą, jei jų vidurkis mažesnis už 5, į kietuolių sąrašą patenka studentai, kurių galutinis balas 5 arba daugiau.
Taip pat veikia programos veikimo greičio (spartos) analizė:

- failų kūrimas;
- nuskaitymas iš failų;
- studentų rūšiavimas į dvi grupes/kategorijas;
- surūšiuotų studentų išvedimas į du naujus failus;

![image](https://user-images.githubusercontent.com/90028851/139395480-ee1a57cd-4eaf-49d1-bfd9-f5e79223eecf.png)


# _**v0.5**_

Sistemos charakteristikos:
Procesorius-	AMD Ryzen 3 3250U with Radeon Graphics (2.60 GHz)
SSD: 240 GB
RAM: 8GB 

![v0 5](https://user-images.githubusercontent.com/90028851/140510548-83784251-7f60-4f13-a0ec-26126abf9dbd.png)

# _**v1.0**_

![v1 0](https://user-images.githubusercontent.com/90028851/144061202-7c6d8f8d-866f-46ad-8399-1bb27ef97cf0.png)

![v1 00](https://user-images.githubusercontent.com/90028851/144061213-0113458e-7e5f-4e99-9305-ac18fd06c5b5.png)

#






# ObjektinisProgramavimas-2uzduotis


# _**v1.1**_

struct studentu_duom buvo pakeista į class studentu_duom. Spartos analizės lentelė, panaudojus Class:
![v1 1 1](https://user-images.githubusercontent.com/90028851/144562259-eb3d9548-b89c-4c25-a1ab-7a0b3f4557b4.png)

**Palyginimui įkeliu spartos analizės lentelę su struct"**
![analizei](https://user-images.githubusercontent.com/90028851/144562700-65be9bc2-b699-420e-a504-227dbceb7397.png)


# _**v1.2**_

Versija papildytaa su reikiamais operatoriais "Rule of three" (destructor, copy constructor, copy assignment operator)



