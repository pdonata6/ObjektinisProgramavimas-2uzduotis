//
// Created by Admin on 2021-12-17.
//

#include "biblioteka.h"

bool teigiami (double vidurkis){
    if (vidurkis >= 5)
        return true;
    else return false;
}

bool neigiami(double vidurkis){
    if (vidurkis < 5)
        return true;
    else return false;
}

double galutinis(double vidurkis, int egzaminas){
    return 0.4 * vidurkis + 0.6 * egzaminas;
}

TEST_CASE("Galutinis pazymys") {

    REQUIRE(galutinis(5.1, 7) == 6.24;
    REQUIRE(galutinis(4.1, 10) == 7.64);
    REQUIRE(galutinis(9.2, 4) == 6.08);
    REQUIRE(galutinis(8.5, 9) == 8.8);
    REQUIRE(galutinis(8.5, 3) == 5.2);

}

TEST_CASE("Studentai islaike") {

REQUIRE(teigiami(9) == true);
REQUIRE(teigiami(4) == false);
REQUIRE(teigiami(10) == true);
REQUIRE(teigiami(7) == true);
REQUIRE(teigiami(5) == true);

}
TEST_CASE("Studentai neislaike") {

REQUIRE(neigiami(7) == false);
REQUIRE(neigiami(5) == false);
REQUIRE(neigiami(4) == true);
REQUIRE(neigiami(1) == true);
REQUIRE(neigiami(3) == true);

}
