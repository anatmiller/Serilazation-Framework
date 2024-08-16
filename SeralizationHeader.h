#ifndef SERIALIZATION_HELPERS_HPP
#define SERIALIZATION_HELPERS_HPP
#include "SeralizationHeader.h"

#include <string>
#include <iostream>




// NVP (Name-Value Pair) class template
class NVP  {
public:
  
    // Constructor to initialize name and value
    NVP(const std::string& name, const std::string& value, 
        const std::string& type): name_(name), value_(value),type_(type) {;}

    NVP(const std::string& name, const std::string& value) 
        : name_(name), value_(value) {
        ;
    }
    
   
    // Accessor for name
    std::string getName() const { return name_; }

    std::string getValue() const { return value_; }

    std::string getType() const { return type_; }
   
    ~NVP() { ; }

private:
    std::string name_;
    std::string value_;
    std::string type_;
};

// make_nvp function template
/*template <typename T>
NVP<T> make_nvp(const std::string& name, T& value) {
    return NVP<T>(name, value);
}*/



#endif // SERIALIZATION_HELPERS_HPP