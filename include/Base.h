#ifndef BASE_H
#define BASE_H
#include <string>
#include "SerializationAlgorithm.h"

class Base {
protected:
    std::string m_name;
    int m_id;

public:
    Base();
    Base(const std::string& name, int id);
    virtual ~Base();
    virtual std::vector<std::shared_ptr<NVP>> searlize() = 0;
    virtual void deserialize(std::vector<std::shared_ptr<NVP>> ShapeVecValues)=0;

    //virtual void printInfo() const = 0; // Pure virtual function
};

#endif // BASE_H