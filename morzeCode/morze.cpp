#include <string.h>
#include <string>
#include <vector>
#include "morze.hpp"
#include <iostream>
#include <map>

using namespace std;

Morze::Morze(string text){
    this->text = text;
    this->size = text.length();
}

string Morze::getMorze() {
    this->morze = "";
    for (int i = 0; i < this->size;i++) {
        switch (this->text[i]) {
            case 'A':
            case 'a':
                this->morze+="*- ";
                break;
            case 'B':
            case 'b':
                this->morze+="-*** ";
                break;
            case 'C':
            case 'c':
                this->morze+="-*-* ";
                break;
            case 'D':
            case 'd':
                this->morze+="-** ";
                break;
            case 'E':
            case 'e':
                this->morze+="* ";
                break;
            case 'F':
            case 'f':
                this->morze+="**-* ";
                break;
            case 'G':
            case 'g':
                this->morze+="--* ";
                break;
            case 'H':
            case 'h':
                this->morze+="**** ";
                break;
            case 'I':
            case 'i':
                this->morze+="** ";
                break;
            case 'J':
            case 'j':
                this->morze+="*--- ";
                break;
            case 'K':
            case 'k':
                this->morze+="-*- ";
                break;
            case 'L':
            case 'l':
                this->morze+="*-** ";
                break;
            case 'M':
            case 'm':
                this->morze+="-- ";
                break;
            case 'N':
            case 'n':
                this->morze+="-* ";
                break;
            case 'O':
            case 'o':
                this->morze+="--- ";
                break;
            case 'P':
            case 'p':
                this->morze+="*--* ";
                break;
            case 'Q':
            case 'q':
                this->morze+="--*- ";
                break;
            case 'R':
            case 'r':
                this->morze+="*-* ";
                break;
            case 'S':
            case 's':
                this->morze+="*** ";
                break;
            case 'T':
            case 't':
                this->morze+="- ";
                break;
            case 'U':
            case 'u':
                this->morze+="**- ";
                break;
            case 'V':
            case 'v':
                this->morze+="***- ";
                break;
            case 'W':
            case 'w':
                this->morze+="*-- ";
                break;
            case 'X':
            case 'x':
                this->morze+="-**- ";
                break;
            case 'Y':
            case 'y':
                this->morze+="-*-- ";
                break;
            case 'Z':
            case 'z':
                this->morze+="--** ";
                break;
            case '0':
                this->morze+="----- ";
                break;
            case '1':
                this->morze+="*---- ";
                break;
            case '2':
                this->morze+="**--- ";
                break;
            case '3':
                this->morze+="***-- ";
                break;
            case '4':
                this->morze+="****- ";
                break;
            case '5':
                this->morze+="***** ";
                break;
            case '6':
                this->morze+="-**** ";
                break;
            case '7':
                this->morze+="--*** ";
                break;
            case '8':
                this->morze+="---** ";
                break;
            case '9':
                this->morze+="----* ";
                break;
        }
    }
    return this->morze;
}

    string  Morze::getText() {
    std::cout << this->size << std::endl;
    vector<string> str;
    string data = "";
    for (int i = 0; i < this->size; i++) {
        if (this->text[i] != ' ' )
            data += this->text[i];
        else {
            str.push_back(data);
            std::cout << data << std::endl;
            data = "";
        }
    }

    string normText = "";
    map<string, string> mape;
    mape["*-"] = "A";
    mape["-***"] = "B";
    mape["-*-*"] = "C";
    mape["-**"] = "D";
    mape["*"] = "E";
    mape["**-*"] = "F";
    mape["--*"] = "G";
    mape["****"] = "H";
    mape["**"] = "I";
    mape["*---"] = "J";
    mape["-*-"] = "K";
    mape["*-**"] = "L";
    mape["--"] = "M";
    mape["-*"] = "N";
    mape["---"] = "O";
    mape["*--*"] = "P";
    mape["--*-"] = "Q";
    mape["*-*"] = "R";
    mape["***"] = "S";
    mape["-"] = "T";
    mape["**-"] = "U";
    mape["***-"] = "V";
    mape["*--"] = "W";
    mape["-**-"] = "X";
    mape["-*--"] = "Y";
    mape["--**"] = "Z";
    mape["*----"] = "1";
    mape["**---"] = "2";
    mape["***--"] = "3";
    mape["****-"] = "4";
    mape["*****"] = "5";
    mape["-****"] = "6";
    mape["--***"] = "7";
    mape["---**"] = "8";
    mape["---*"] = "9";
    mape["-----"] = "0";

    for (size_t i = 0; i < str.size() + 1; i++) {
        std::cout << mape[str[i]];
    }
    std::cout << std::endl;
    return 0;
}
