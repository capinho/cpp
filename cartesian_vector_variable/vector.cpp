//
//  vector.cpp
//  cartesian_vector_variable
//
//  Created by pape ibrahima diawara on 25/10/2022.
//

#include "vector.hpp"


Vector::Vector(const Vector &v) {
    this->vecteur = std::make_unique<value[]>(v.size());
    for (size_t i = 0; i < v.size() ; ++i) vecteur[i] = v[i];
    n = v.size();
}

Vector& Vector::operator=(const Vector &v) {
    this->vecteur = std::make_unique<value[]>(v.size());
    for (size_t i = 0; i < v.size() ; ++i) vecteur[i] = v[i];
    n = v.size();
    return *this;
}

Vector::Vector(std::initializer_list<value> l) {
    n = l.size();
    value i = 0;
    vecteur = std::make_unique<value[]>(l.size());
    for (value val : l) {
        vecteur[i++] = val;
    }
    
}

Vector::Vector(size_t N) {
    vecteur = std::make_unique<value[]>(N);
    for (int i = 0; i < N; i++) {
        vecteur[i] = 0;
    }
    n = N;
}


Vector& Vector::operator+=(const Vector& rhs) {
    if (n != rhs.size())
        std::runtime_error("Incompatible size");
    for (int i = 0; i < rhs.size(); i++) {
        vecteur[i] += rhs[i];
    }

    return *this;
}

Vector& Vector::operator-=(const Vector& rhs){
    if (n != rhs.size())
        std::runtime_error("Incompatible size");
    for (int i = 0; i < rhs.size(); i++) {
        vecteur[i] -= rhs[i];
    }
    return *this;
}

Vector& Vector::operator+=(value v) {
    for (int i = 0; i < n; i++) {
        vecteur[i] += v;
    }
    return *this;
}

Vector& Vector::operator*=(value v){
    for (int i = 0; i < n; i++) {
        vecteur[i] *= v;
    }
    return *this;
}

Vector Vector::operator+(const Vector& rhs) const {
    if (n != rhs.size())
        std::runtime_error("Incompatible size");
    for (int i = 0; i < rhs.size(); i++) {
        vecteur[i] += rhs[i];
    }
    return *this;
}

Vector Vector::operator+(value v) const {
    for (int i = 0; i < n; i++) {
        vecteur[i] += v;
    }
    return *this;
}

value Vector::operator*(const Vector& rhs) const {
    if (n != rhs.size())
        std::runtime_error("Incompatible size");
    value u = 0;
    for (int i = 0; i < rhs.size(); i++) {
        u += rhs[i] * (*this)[i];
    }
    return u;
}

Vector Vector::operator*(value x) const {
    for (int i = 0; i < n; i++) {
        vecteur[i] *= x;
    }
    return *this;

}

value& Vector::operator[](size_t idx) {
    if (n < idx)
        std::runtime_error("Incompatible size");
    return vecteur[idx];
}

value Vector::operator[](size_t idx) const {
    if (n < idx)
        std::runtime_error("Incompatible size");
    return vecteur[idx];
}


//my no member functions
Vector operator+(const Vector& v,const value& x) {
    Vector vec = Vector(v.size());
    for (int i = 0; i < v.size(); i++) {
        vec[i] = v[i] + x;
    }
    return vec;
}

Vector operator*(const Vector& v,const value& x) {
    Vector vec = Vector(v.size());
    for (int i = 0; i < v.size(); i++) {
        vec[i] = v[i] * x;
    }
    return vec;
}


// Vector: Output stream

std::ostream& operator<<(std::ostream &o, const Vector& v)
{
    o << "{";
    for (int i = 0; i < v.size(); i++)
        o << v[i] << (i == v.size() - 1 ? "" : ",");
    return o << "}";
}
