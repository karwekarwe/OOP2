#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

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
   //Stud(vector <int>& namuDarbai, string& vardas, string& pavarde, int egzaminas, double gal, int ndcount)
   //     : Zmogus(vardas, pavarde),namuDarbai_(namuDarbai), egzaminas_(egzaminas), gal_(gal), ndcount_(ndcount) {}
   Stud(const string& vardas, const string& pavarde) : Zmogus(vardas, pavarde), egzaminas_(0), ndcount_(0), gal_(0.0){}


    ~Stud() {namuDarbai_.clear(); vardas_.clear(), pavarde_.clear();}

    // Copy constructor
    Stud(const Stud& other)
        : Zmogus(other.vardas_, other.pavarde_),  egzaminas_(other.egzaminas_),  gal_(other.gal_),  namuDarbai_(other.namuDarbai_), ndcount_(other.ndcount_) {}
   
   // Copy assignment operator

    Stud& operator=(const Stud& other) {
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

    // Move constructor
    Stud(Stud&& other) noexcept 
        : Zmogus(move(other.vardas_), move(other.pavarde_)), egzaminas_(other.egzaminas_), gal_(other.gal_), namuDarbai_(move(other.namuDarbai_)), ndcount_(move(other.ndcount_)){
        other.vardas_.empty(); other.pavarde_.empty(); other.ndcount_ = 0;  other.egzaminas_ = 0; other.gal_ = 0; other.namuDarbai_.empty();}// cia ir kiti =0

    // Move assignment operator
    Stud& operator=(Stud&& other) noexcept { 
        if (this != &other) {
            vardas_ = move(other.vardas_);
            pavarde_ = move(other.pavarde_);
            egzaminas_ = move(other.egzaminas_);
            gal_ = move(other.gal_);
            namuDarbai_ = move(other.namuDarbai_);
            ndcount_ = move(other.ndcount_);

            other.vardas_.clear();
            other.pavarde_.clear();
            other.vardas_.empty(); other.pavarde_.empty(); other.ndcount_ = 0;  other.egzaminas_ = 0; other.gal_ = 0; other.namuDarbai_.empty();
        }
        return *this;
    }



    // getteriai
    vector <int> getNamuDarbai() const {return namuDarbai_;}
    int getEgzaminas() const {return egzaminas_;}
    double getGal() const {return gal_;}
    int getNdcount() const {return ndcount_;}

    //setteriai
    void setNamuDarbai(const vector <int>& namuDarbai) {namuDarbai_ = namuDarbai;}
    void setEgzaminas (int egzaminas) {egzaminas_ = egzaminas;}
    void setGal (double gal) {gal_ = gal;}
    void setNdcount (int ndcount) {ndcount_ = ndcount;}

    //kiti
    void addND(int namuDarbai) { namuDarbai_.push_back(namuDarbai); }
    void clearND() { namuDarbai_.clear(); }

  // Input Operator
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

// Output Operator
friend std::ostream& operator<<(std::ostream& os, const Stud& stud) {
    os << stud.vardas_ << setw(20) << stud.pavarde_ << setw(20) << stud.gal_ << setw(20) << "\n";
    return os;
}



};


#endif
