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
    protected:

    string vardas_;
    string pavarde_;

    Zmogus() = default;
    Zmogus(const string& vardas, const string& pavarde)
    : vardas_(vardas), pavarde_(pavarde) {}
   

 public:
    virtual ~Zmogus() {}
    virtual string getVardas() const {return vardas_;}
    virtual string getPavarde() const {return pavarde_;}
    virtual void setVardas(const string& vardas) {vardas_ = vardas;}
    virtual void setPavarde(const string& pavarde) {pavarde_ = pavarde;}

};

class Stud : public Zmogus {
private:
    int egzaminas_, ndcount_;
    double gal_;
    vector<int> namuDarbai_;
public:
    Stud() : egzaminas_(0), gal_(0), ndcount_(0) { }  // default konstruktorius
   Stud(const string& vardas, const string& pavarde) : Zmogus(vardas, pavarde), egzaminas_(0), ndcount_(0), gal_(0.0){}

    ~Stud() {namuDarbai_.clear(); vardas_.clear(), pavarde_.clear();}

```

Abstraktumas - negalime sukurti jos objektų:
![image](https://github.com/karwekarwe/OOP2/assets/82239041/b0b7361e-9cdc-4324-bd98-3452e44b553e)
![image](https://github.com/karwekarwe/OOP2/assets/82239041/1d4b1710-1931-4f3c-b0a5-7d17ce177126)


