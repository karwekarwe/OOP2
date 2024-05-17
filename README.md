# README

# v1.2

## Paleisties proceso instrukcija:

1. Visų pirma, iš https://github.com/karwekarwe/OOP2 reikia klonuoti repozitoriją savo darbo aplinkoje naudojant 'git clone'.
2. Atsidarius naują terminalą, nueikite į klonuotos repozitorijos aplnką.
3. Kompiliuokite programą naudojant "Makefile" failą, kuris jau bus klonuotoje repozitorijose - terminale įrašykite "make".
4. Pasirinkite su kokia programos versija norite dirbti.

## Programos veikimas:

1.  Paleidus programą, vartotojui pateikiami pasirinkimai:
+ Duomenų įvestis ranka ar nuskaitymas iš failo. Toliau seka šie pasirinkimai:
     Ranka: 
     - Pilna įvestis ranka / pažymių generavimas / pažymių ir vardų generavimas / baigti darbą.
     - Skaičiavimo metodas: vidurkis / mediana
+ Iš failo:
     - Generuoti naują ar naudoti esamą failą
     - Kokio dydžio failą generuoti / naudoti? (1. 1000 2. 10000 3. 100000 4. 1000000 5. 10000000.)
     - Skaičiavimo metodas: vidurkis / mediana
     - Rikiavimo metodas: vardas / pavardė / galutinis
     - Išvestis į failą ar ekraną.



## Rule of five:
 
+ Destructor

```
    ~Stud() {namuDarbai_.clear(); vardas_.clear(), pavarde_.clear();}
```

+ Copy constructor 
```
   Stud(const Stud& other)
        : vardas_(other.vardas_), pavarde_(other.pavarde_),  egzaminas_(other.egzaminas_),  gal_(other.gal_),  namuDarbai_(other.namuDarbai_), ndcount_(other.ndcount_) {}
```
+ Copy assignment operator
```
    Stud& operator=(const Stud& other) {// copy assignment
        if (this != &other) {
            vardas_ = other.vardas_;
            pavarde_ = other.pavarde_;
            egzaminas_ = other.egzaminas_;
            gal_ = other.gal_;
            namuDarbai_ = other.namuDarbai_;
            ndcount_ = other.ndcount_;    
        }
        return *this;
    }
```
+ Move constructor
```
    Stud(Stud&& other) noexcept // move constructor
        : vardas_(move(other.vardas_)), pavarde_(move(other.pavarde_)), egzaminas_(other.egzaminas_), gal_(other.gal_), namuDarbai_(move(other.namuDarbai_)), ndcount_(move(other.ndcount_)){
        other.ndcount_ = 0;}
```

+ Move assignment operator
```
    Stud(Stud&& other) noexcept // move constructor
        : vardas_(move(other.vardas_)), pavarde_(move(other.pavarde_)), egzaminas_(other.egzaminas_), gal_(other.gal_), namuDarbai_(move(other.namuDarbai_)), ndcount_(move(other.ndcount_)){
        other.ndcount_ = 0;}
```
#Rule of five testavimas:

```
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

```

## Įvesties / Išvesties opratoriai:

+ Input operator: 

```
friend std::istream& operator>>(std::istream& is, Stud& stud) {
    is >> stud.vardas_ >> stud.pavarde_;
    stud.namuDarbai_.clear(); 
    int balas;
    for (int i = 0; i < stud.getNdcount(); ++i) {
        is >> balas;
        stud.namuDarbai_.push_back(balas);
    }
    
    is >> stud.egzaminas_;
    return is;
}
```

+ Output operator:

```
friend std::ostream& operator<<(std::ostream& os, const Stud& stud) {
    os << stud.vardas_ << setw(20) << stud.pavarde_ << setw(20) << stud.gal_ << setw(20) << "\n";
    return os;
}

```

+ Input operator panaudojimas isFailo.cpp faile: 

```
      while (getline(failas, line)) {
            lines.push_back(line);

            if (lines.size() >= dyd) { 
              
                for (const auto& bufferedLine : lines) {
                           
                    stringstream stringBuferis(bufferedLine);
                    naujasS.setNdcount(baluCount);
                    stringBuferis >> naujasS; // input operator panaudojimas

                    studentai.push_back(naujasS);
                }

                lines.clear();
            }
        }
```

+ Output operator panaudimas papFunkcijos.cpp faile: 

```
void isvedimas_i_ekrana(const vector<Stud>& luzeriukai, const vector<Stud>& studentai) {
        cout << "Luzeriukai:" << endl;
    for (const auto& studentas : luzeriukai) {
            cout << studentas; //output operator
    }
    cout << "Intelektualai:" << endl;
    for (const auto& studentas : studentai) {
            cout << studentas; //output operator
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
            outputFileUnder << studentas; //output operator
        }   
        for (const auto& studentas : studentai){
            outputFileOver << studentas; //output operator
        } 

        outputFileUnder.close();
        outputFileOver.close();
    }




