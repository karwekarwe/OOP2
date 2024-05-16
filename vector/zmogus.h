#ifndef ZMOGUS_H
#define ZMOGUS_H
#include <string>

class Zmogus {

    public:
    std::string vardas_;
    std::string pavarde_;

    Zmogus() : vardas_(""), pavarde_("") {}
    Zmogus(const std::string& vardas, const std::string& pavarde)
    : vardas_(vardas), pavarde_(pavarde) {}

};

#endif
