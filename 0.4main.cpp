#include <iostream>
#include <vector>

#include "student.h"
#include "funkcijos.h"

using namespace std;

int main() {

    vector<Stud> studentai;
    string failPav;


        try {
               
                char pasDyd;
                cout << "Pasirinkite, kokio dydžio failą norite generuoti: 1. 1000 2. 10000 3. 10000 4. 1000000 5. 10000000"<< endl;
                cin >> pasDyd;

                switch (pasDyd) {
                    case '1':
                    failuGen("studentai1000.txt", 1000);
                    failPav = "studentai1000.txt";
                    break;
                    case '2':
                    failuGen("studentai10000.txt", 10000);
                    failPav = "studentai10000.txt";
                    break;
                    case '3':
                    failuGen("studentai100000.txt", 100000);
                    failPav = "studentai100000.txt";
                    break;
                    case '4':
                    failuGen("studentai1000000.txt", 1000000);
                    failPav = "studentai1000000.txt";
                    break;
                    case '5':
                    failuGen("studentai10000000.txt", 10000000);
                    failPav = "studentai10000000.txt";
                    break;
                    default:
                    throw invalid_argument("Klaida");

                }
                cout << "Failas sugeneruotas." << endl;
                isFailo(failPav, studentai);          

                rusiavimasGen(failPav, studentai); 
            


        } catch (const invalid_argument& e) {
            cout << "Klaida: " << e.what() << " Prašome įvesti tinkamą pasirinkimą.\n";
        } catch (const exception& e) {
            cout << "Neatpažinta klaida: " << e.what() << " Programa baigia darba.\n";
            return 1;
        }
    
    return 0;
}
