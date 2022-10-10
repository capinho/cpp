//
//  vector.cpp
//  cartesian_vector_param
//
//  Created by pape ibrahima diawara on 01/10/2022.
//
#include <ostream>
#include <iostream>

#include "vector.hh"



Vector::Vector()
{
    n = NDIM;
    for(size_t i = 0;i < n; i++) p[i] = 0;
}

// Vector: Constructor with given size and data
Vector::Vector(std::initializer_list<value> l)
{
    n = l.size();
    int i = 0;
    for(auto & val : l)
    {
        p[i++] = val;
    }
}

// Vector: v += rhs

Vector& Vector::operator+=(const Vector& rhs)
{
    if (n!=rhs.n) {
      std::cout << "Bad vector sizes\n";
      exit(EXIT_FAILURE);
    }
    for (int i = 0; i < rhs.size(); i++) p[i] += rhs.p[i];
    return *this;
}


// Vector: v -= rhs

Vector& Vector::operator-=(const Vector& rhs)
{
    if (n!=rhs.n) {
      std::cout << "Bad vector sizes\n";
      exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rhs.size(); i++) p[i] -= rhs.p[i];
    return *this;
}

Vector Vector::operator+(const Vector& rhs)
{
    auto u = Vector();
    for (int i = 0; i < rhs.size(); i++)
        u[i] = rhs[i] + (*this)[i];
    return u;
}

Vector Vector::operator-(const Vector& rhs)
{
    auto u = Vector();
    for (int i = 0; i < rhs.size(); i++)
        u[i] = rhs[i] - (*this)[i];
    return u;
}

value Vector::operator*(const Vector& rhs)
{
    value u = 0;
    for (int i = 0; i < rhs.size(); i++)
        u += rhs[i] * (*this)[i];
    return u;
}


value& Vector::operator[](size_t i)
{
    return p[i];
}

value Vector::operator[](size_t idx) const
{
    return p[idx];
}


Vector operator*=(Vector& rhs, const value x)
{
    for (int i = 0; i < rhs.size(); i++)
        rhs[i] *= x;
    return rhs;
}

Vector operator*(Vector& rhs,const value x)
{
    auto vec = Vector();
    for (int i = 0; i < rhs.size(); i++)
        vec[i] = rhs[i] * x;
    return vec;
}

Vector operator+=(Vector& rhs, const value x)
{
    for (int i = 0; i < rhs.size(); i++)
        rhs[i] += x;
    return rhs;
}

// Vector: Output stream

std::ostream& operator<<(std::ostream &o, const Vector& v)
{
    o << "{";
    for (int i = 0; i < v.size(); i++)
        o << v[i] << (i == v.size() - 1 ? "" : ",");
    return o << "}";
}
