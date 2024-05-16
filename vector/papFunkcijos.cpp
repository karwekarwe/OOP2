#include "funkcijos.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iomanip>


using namespace std;

    
    double vidurkis (Stud& s) {
        double suma = 0;
        double avg = 0;
        double gal;
     //   vector<int>& namuDarbai = s.getNamuDarbai();
        for (int balas : s.getNamuDarbai()) {
            suma+= balas;
        }
        avg = suma / s.getNamuDarbai().size();
        
        gal = avg*0.4 + s.getEgzaminas()*0.6;

        return gal;
    }

        double mediana (Stud& s) {
        double med = 0;
        double gal;
       // vector<int>& namuDarbai = s.getNamuDarbai();

        sort(s.getNamuDarbai().begin(), s.getNamuDarbai().end());

        if (s.getNamuDarbai().size() % 2 == 0) {
            med = (s.getNamuDarbai()[s.getNamuDarbai().size() / 2 - 1] + s.getNamuDarbai()[s.getNamuDarbai().size() / 2]) / 2.0;
        }
        else {
            med = s.getNamuDarbai()[s.getNamuDarbai().size() / 2];
        }
        gal = med*0.4 + s.getEgzaminas()*0.6;

        return gal;
    }

    bool rusiavimasV(const Stud& a, const Stud& b) {
        return a.getVardas() < b.getVardas();
    }
    bool rusiavimasP(const Stud& a, const Stud& b) {
        return a.getPavarde() < b.getPavarde();
    }
    bool rusiavimasG(const Stud& a, const Stud& b) {
        return a.getGal() > b.getGal();
    }

    void testai(){

        // constructor
    vector<int> nd = {1, 2, 3};
    std::string vardas = "John";
    std::string pavarde = "Doe";
    Stud s2(nd, vardas, pavarde, 0, 0.0, 3);
    assert(s2.getVardas() == "John");
    assert(s2.getPavarde() == "Doe");
    assert(s2.getNamuDarbai() == nd);
    assert(s2.getEgzaminas() == 0);
    assert(s2.getGal() == 0.0);
    assert(s2.getNdcount() == 3);

        // copy contruct
    Stud s3 = s2;
    assert(s3.getVardas() == "John");
    assert(s3.getPavarde() == "Doe");
    assert(s3.getNamuDarbai() == nd);
    assert(s3.getEgzaminas() == 0);
    assert(s3.getGal() == 0.0);
    assert(s3.getNdcount() == 3);


        // moce constr

    Stud s4 = std::move(s3);
    assert(s4.getVardas() == "John");
    assert(s4.getPavarde() == "Doe");
    assert(s4.getNamuDarbai() == nd);
    assert(s4.getEgzaminas() == 0);
    assert(s4.getGal() == 0.0);
    assert(s4.getNdcount() == 3);

    assert(s3.getVardas().empty());
    assert(s3.getPavarde().empty());
    assert(s3.getNamuDarbai().empty());
    assert(s3.getEgzaminas() == 0);
    assert(s3.getGal() == 0.0);
    assert(s3.getNdcount() == 0);

    cout << "Testai sekmingi" <<endl;
    }

void isvedimas_i_ekrana(const vector<Stud>& luzeriukai, const vector<Stud>& studentai) {
        cout << "Luzeriukai:" << endl;
    for (const auto& studentas : luzeriukai) {
            cout << studentas;
    }
    cout << "Intelektualai:" << endl;
    for (const auto& studentas : studentai) {
            cout << studentas;
    }
}


void isvedimas_i_faila(const vector<Stud>& luzeriukai, const vector<Stud>& studentai, const string& failPav) {
     ofstream outputFileUnder("luzeriukai " + failPav);
    if (!outputFileUnder.is_open()) {
        cerr << "Nepavyko sukurti naujo failo. outputFileUnder" << endl;
        return;
    }
    ofstream outputFileOver("intelektualai " + failPav);
    if (!outputFileOver.is_open()) {
        cerr << "Nepavyko sukurti naujo failo. outputFileOver" << endl;
        return;
    }
        for (const auto& studentas : luzeriukai){
            outputFileUnder << studentas;
        }   
        for (const auto& studentas : studentai){
            outputFileOver << studentas;
        } 

        outputFileUnder.close();
        outputFileOver.close();
    }
