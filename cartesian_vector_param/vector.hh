//
//  vector.hh
//  cartesian_vector_param
//
//  Created by pape ibrahima diawara on 29/09/2022.
//

#pragma once

#include <ostream>
#include <initializer_list>
#include <cassert>
#include <memory>

#include "config.h"

class Vector
{
public:
// DO NOT CHANGE THIS
    Vector(const Vector&) = default;
    Vector& operator=(const Vector&) = default;
    ~Vector() = default;
//

// Add suitable constructors
    Vector();  // Constructor for a zero vector
    Vector(std::initializer_list<value> l);
    // possibly more
    size_t size() const {return n;};

// Public Member functions here
    Vector& operator+=(const Vector& rhs); // v += rhs
    Vector& operator-=(const Vector& rhs); // v -= rhs
    Vector operator+(const Vector& rhs);
    value operator*(const Vector& rhs);
    Vector operator-(const Vector& rhs);
    value& operator[](size_t i);
    value operator[](size_t idx) const;
private:
    // Private Member functions here (if necessary)

    // Member variables are ALWAYS private, and they
    size_t n;
    value p[NDIM];
};

// Nonmember function operators go here
Vector operator*(Vector& rhs, const value x);
Vector operator*=(Vector& rhs, const value x);
Vector operator+=(Vector& rhs, const value x);
std::ostream& operator<<(std::ostream& o, const Vector& v);
