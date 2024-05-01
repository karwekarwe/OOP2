#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <iomanip>

#include "student.h"
#include "funkcijos.h"

using namespace std;


  void ranka(vector<Stud>& studentai) {


  //  int m = 0; // studentu sk
    string vardas, pavarde;
    int balas, egzBalas;
    char pabaiga;


    srand(time(0));

    while (true) {
    char input;
 
    cout << "Pasirinkite programos eigą: \n 1. Įvestis ranka. \n 2. Generuoti namų darbų ir egzamino pažymius. \n 3. Generuoti ir pažymius, ir vardus bei pavardes. \n 4. Baigti darbą."<< endl;
    cin >> input;

    while (true) {

        Stud naujasS;

        if (input == '4') {
        exit(0);
        }


        else if (input == '1'){
            cout << "Vardas: "<< endl;
            cin >> vardas;
            naujasS.setVardas(vardas); //vardas i class
            cout << "Pavarde: "<< endl;
            cin >> pavarde; 
             naujasS.setPavarde(pavarde); //pavarde i class

            int i = 1;
                do {
                    cout << "Namu darbu "<< i <<" balas (-1 norint baigti): " << endl;
                    cin >> balas;

                    if (cin.fail() || balas == 0 || balas < -1 || balas > 10) {
                        cout << "Įvekite skaičių nuo 1 iki 10" << endl;
                        cin.clear(); 
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                        continue; 
                    }
                    if (balas == -1){
                        if (naujasS.getNamuDarbai().empty()) {
                            cout << "Įveskite bent 1 pažymį: " << endl;
                            continue; 
                        } 
                        else {
                            break; 
                        }
                        }
                
                    naujasS.addND(balas); 
                    i++;
                } while (true);
            

            do {
                cout << "Iveskite egzamino bala: ";
                cin >> egzBalas;

                if (cin.fail() || egzBalas < 1 || egzBalas > 10) {
                    cout << "Įvekite skaičių nuo 1 iki 10" << endl;
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    continue; 
                }
                else {
                    naujasS.setEgzaminas(egzBalas); // egzaminas i class
                    break;
                }      
            } while (true);

        }
        else if (input == '2'){
            cout << "Vardas: "<< endl;
            cin >> vardas; 
            naujasS.setVardas(vardas); //vardas i class
            cout << "Pavarde: "<< endl;
            cin >> pavarde; 
            naujasS.setPavarde(pavarde); //pavarde i class

            int numBal = rand() % 10 + 1;
            for (int i = 0; i < numBal; i++) {
                naujasS.addND(rand() % 10 + 1); // random nd i class
            }
                naujasS.setEgzaminas(rand() % 10 + 1); // random egzaminas i class

        }
        else if (input == '3'){

            vector<string> vardai = {"Jonas", "Petras", "Antanas", "Juozas", "Ona", "Marija", "Gražina", "Laima"};
            vector<string> pavardes = {"Jonaitis", "Petraitis", "Antanaitis", "Juozaitis", "Onaitė", "Marijaitė", "Gražinaitė", "Laimaitė"};

                int numBal = rand() % 10 + 1;
                for (int i = 0; i < numBal; i++) {
                    naujasS.setVardas(vardai[rand() % vardai.size()]); // vardas i class
                    naujasS.setPavarde(pavardes[rand() % pavardes.size()]); //pavarde i class

                    naujasS.addND(rand() % 10 + 1); // random nd i class                
                }
                naujasS.setEgzaminas(rand() % 10 + 1); // random egzaminas i class
                cout << "Sugeneruotas studentas " << naujasS.getVardas() << " " << naujasS.getPavarde() << endl;
            }   
        else {
            cout << "Neteisinga įvestis."<<endl;
        }


            studentai.push_back(naujasS); 

        
            while (true) {
                cout << "Ar baigete ivesti studentus? (y/n): ";
                cin >> pabaiga;
                if (pabaiga == 'y' || pabaiga == 'Y') {
                    break;
                } 
                else if (pabaiga == 'n' || pabaiga == 'N') {
                    break;
                } 
                else {
                    cout << "Įveskite 'n' arba 'y'" << endl;
                }
            }

            if (pabaiga == 'y' || pabaiga == 'Y') {
                break;
            }
    }
    
        char pasirinkimas;

        while (true) {
            try {
                cout << endl;
                cout << "Pasirinkite skaiciavimo metoda (V - vidurkis, M - mediana): " << endl;
                cin >> pasirinkimas;
                pasirinkimas = toupper(pasirinkimas);

                if (pasirinkimas != 'V' && pasirinkimas != 'M') {
                    throw invalid_argument("Neteisinga įvestis.");
                } else {
                    if (pasirinkimas == 'V') {
                        cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(10) << right << "Galutinis (Vid.)" << endl;
                    } else {
                        cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(10) << right << "Galutinis (Med.)" << endl;
                    }
                    cout << "--------------------------------------------" << endl;
                    for (auto& studentas : studentai) {
                        if (pasirinkimas == 'V') {
                            studentas.setGal(vidurkis(studentas)); // galutinis i class
                        } else {
                            studentas.setGal(mediana(studentas)); // galutinis i class
                        }
                        cout << setw(20) << left << studentas.getVardas() << setw(20) << left << studentas.getPavarde() << setw(10) << right << fixed << setprecision(2) << studentas.getGal() << endl;
                    }
                    cout << "--------------------------------------------" << endl;
                    break;
                }
            } catch (const invalid_argument& e) {
                cout << e.what() << endl;
            }
        }

            }

}