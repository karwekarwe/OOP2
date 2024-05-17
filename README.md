# README

# v1.5

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


## Klasė Zmogus:

```
class Zmogus {

    public:
    std::string vardas_;
    std::string pavarde_;

    Zmogus() : vardas_(""), pavarde_("") {}
    Zmogus(const std::string& vardas, const std::string& pavarde)
    : vardas_(vardas), pavarde_(pavarde) {}

};
```
## Klasė Stud:

```
class Stud : public Zmogus{
private:
  //  string vardas_, pavarde_;
    int egzaminas_, ndcount_;
    double gal_;
    vector<int> namuDarbai_;
public:
    Stud() : egzaminas_(0), gal_(0), ndcount_(0) { }  // default konstruktorius
    Stud(vector <int>& namuDarbai, string& vardas, string& pavarde, int egzaminas, double gal, int ndcount)
        : namuDarbai_(namuDarbai), Zmogus(vardas, pavarde), egzaminas_(egzaminas), gal_(gal), ndcount_(ndcount) {}

    ~Stud() {namuDarbai_.clear(); vardas_.clear(), pavarde_.clear();}

```

## Copy konstruktorius:
```
 // Copy constructor
    Stud(const Stud& other)
        : Zmogus(other.vardas_, other.pavarde_),  egzaminas_(other.egzaminas_),  gal_(other.gal_),  namuDarbai_(other.namuDarbai_), ndcount_(other.ndcount_) {}

```
## Move kostruktorius:

```
 // Move constructor
    Stud(Stud&& other) noexcept 
        : Zmogus(move(other.vardas_), move(other.pavarde_)), egzaminas_(other.egzaminas_), gal_(other.gal_), namuDarbai_(move(other.namuDarbai_)), ndcount_(move(other.ndcount_)){
        other.vardas_.clear(); other.pavarde_.clear(); other.ndcount_ = 0;  other.egzaminas_ = 0; other.gal_ = 0; other.namuDarbai_.clear();}

```


Abstraktumas - negalime sukurti jos objektų:
![image](https://github.com/karwekarwe/OOP2/assets/82239041/b0b7361e-9cdc-4324-bd98-3452e44b553e)
![image](https://github.com/karwekarwe/OOP2/assets/82239041/1d4b1710-1931-4f3c-b0a5-7d17ce177126)


