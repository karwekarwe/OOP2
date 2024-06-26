#include "vector.h"
#include <iostream>
#include <chrono>

#include "student.h"
#include "funkcijos.h"

using namespace std;

chrono::milliseconds totalTime(0); 

int main() {

    Vector<Stud> studentai;
    string failPav;
    Vector<Stud> luzeriukai;



        try {

                char rf;
                cout << "Ivestis ranka - 1, Is failo - 2, Vector klasės testavimas - 3" <<endl;
                cin >> rf;

                if (rf == '1') {
                    ranka(studentai);
                }
                else if (rf == '2'){

                char ne;
                cout << "Generuoti nauja ar naudoti esama? (Nauja - N. Esama - E)" << endl;
                cin >> ne;

                char pasDyd;
                cout << "Pasirinkite, su kokio dydzio failu norite dirbti: 1. 1000 2. 10000 3. 100000 4. 1000000 5. 10000000"<< endl;
                cin >> pasDyd;
            int dyd;
     
                if (ne == 'N' || ne == 'n') {

                        
                    switch (pasDyd) {
                        case '1':
                        failuGen("studentai1000.txt", 1000);
                        failPav = "studentai1000.txt";
                        dyd = 1000;
                        break;
                        case '2':
                        failuGen("studentai10000.txt", 10000);
                        failPav = "studentai10000.txt";
                        dyd = 10000;
                        break;
                        case '3':
                        failuGen("studentai100000.txt", 100000);
                        failPav = "studentai100000.txt";
                        dyd = 100000;
                        break;
                        case '4':
                        failuGen("studentai1000000.txt", 1000000);
                        failPav = "studentai1000000.txt";
                        dyd = 1000000;
                        break;
                        case '5':
                        failuGen("studentai10000000.txt", 10000000);
                        failPav = "studentai10000000.txt";
                        dyd = 10000000;
                        break;
                        default:
                        throw invalid_argument("Klaida");

                    }
                    cout << "Failas sugeneruotas." << endl;
                    isFailo(failPav, studentai, dyd); 
                    rusiavimasGen(failPav, studentai, luzeriukai); 
  

                }
                else if (ne == 'E' || ne == 'e') {

                    switch (pasDyd) {
                        case '1':
                        failPav = "studentai1000.txt";
                        dyd = 1000;
                        break;
                        case '2':
                        failPav = "studentai10000.txt";
                        dyd = 10000;
                        break;
                        case '3':
                        failPav = "studentai100000.txt";
                        dyd = 100000;
                        break;
                        case '4':
                        failPav = "studentai1000000.txt";
                        dyd = 1000000;
                        break;
                        case '5':
                        failPav = "studentai10000000.txt";
                        dyd = 10000000;
                        break;
                        default:
                        throw invalid_argument("Klaida");
                    }

                    isFailo(failPav, studentai, dyd); 
                    rusiavimasGen(failPav, studentai, luzeriukai); 
                }

                char isvestis;
                cout << "Kaip isvesti rezultatus? 1 - i faila. 2 - i ekrana" << endl;
                cin >> isvestis;

                if (isvestis == '1'){
                isvedimas_i_faila(luzeriukai, studentai, failPav);

                }
                else if (isvestis == '2'){
                isvedimas_i_ekrana(luzeriukai, studentai);

                }

            
                }

                else if (rf == '3'){
                testai();
                VectorTest();
                insertTest();
                vectorVsVector();
                }


        } catch (const invalid_argument& e) {
            cout << "Klaida: " << e.what() << " Prašome įvesti tinkamą pasirinkimą.\n";
        } catch (const exception& e) {
            cout << "Neatpažinta klaida: " << e.what() << " Programa baigia darba.\n";
            return 1;
        }

    cout << "Visos programos veikimo laikas: " << totalTime.count() << " milisekundes" << endl;

    return 0;
}

