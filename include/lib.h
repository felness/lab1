#pragma once

#include <string>
#include <iostream>
using namespace std;
class Octal
{ 
public:
   Octal();
   Octal(const size_t &n, unsigned char t);
   Octal(const initializer_list< unsigned char> &t);
   Octal(const string &t);
   Octal(const Octal& other);
   Octal(Octal&& other) noexcept;      
   
   unsigned char* getArray();
   long long getSize();
   Octal add(const Octal& other);
   Octal remove(const Octal& other);
   bool equals(const Octal& other) const;
   bool greaterThan(const Octal& other) const;
   bool lessThan(const Octal& other) const;
   ostream& print(std::ostream& os);

    Octal operator +(const Octal& other);
    Octal operator -(const Octal& other);
    bool operator ==(const Octal& other) const;
    bool operator >(const Octal& other) const;
    bool operator <(const Octal& other) const;
    Octal & operator =(const Octal& other);
    Octal & operator =(Octal&& other);

   friend class OctalBuilder;
   virtual ~Octal() noexcept;
private:
    long long _size;
    unsigned char *_array;
};

ostream &operator <<(ostream& os, const Octal& object);
istream &operator >>(istream& is, Octal& object);