#include "pch.h"
#include "Base.h"

// Constructor implementation
Base::Base() : m_name("Default"), m_id(0) {
    
}

Base::Base(const std::string& name,int id):m_name(name),m_id(id) {
    ;
}

Base::~Base() {
    
}