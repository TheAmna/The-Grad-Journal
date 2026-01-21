#include "Vector2D.hpp"
#include <iostream>
using namespace std;

/// @brief Stream output operator for `Vector2D`
/// @param os The output stream
/// @param v The vector to output
/// @return The output stream

std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
    os << "Vector2D(" << v.m_x << ", " << v.m_y << ")";
    return os;
}

Vector2D::Vector2D(const double x, const double y){
    m_x = x;      //ctor
    m_y = y;
}

Vector2D Vector2D::operator+(const Vector2D& other) const {
    double  result_x, result_y;
    result_x = m_x + other.m_x;
    result_y = m_y + other.m_y;
    Vector2D result_vector(result_x,result_y);
    return result_vector;
}

 
Vector2D Vector2D::operator-(const Vector2D& other) const {
   double result_x, result_y;
    result_x = m_x - other.m_x;
    result_y = m_y - other.m_y;
    Vector2D result_vector(result_x, result_y);
    return result_vector;
}


Vector2D Vector2D::operator*(const double scalar) const {
    double result_x, result_y;
    result_x = m_x * scalar;
    result_y = m_y * scalar;
    Vector2D result_vector(result_x, result_y);
    return result_vector;
}


Vector2D& Vector2D::operator+=(const Vector2D& other) {
    m_x = m_x + other.m_x;
    m_y = m_y + other.m_y;
    return *this;
}


Vector2D& Vector2D::operator-=(const Vector2D& other) {
    m_x = m_x - other.m_x;
    m_y = m_y - other.m_y;
    return *this;
}


Vector2D& Vector2D::operator*=(const double scalar) {
     m_x *= scalar;
    m_y *= scalar;
    return *this;
 }


double Vector2D::operator*(const Vector2D& other) const {
    double result = (m_x * other.m_x) + (m_y * other.m_y); 
    return result ;
}


bool Vector2D::operator==(const Vector2D& other) const {
    if ((m_x == other.m_x) & (m_y == other.m_y)){
        return true;
    }
    return false;
}

bool Vector2D::operator!=(const Vector2D& other) const {
    if ((m_x != other.m_x) & (m_y != other.m_y)){
        return true;
    }
    return false;
}


double Vector2D::operator[](int index) const {
    if (index == 0){ 
        return m_x;
    }
    if (index == 1){
        return m_y;
    }
    else {cout << "Vector2D index out of range";}
}
