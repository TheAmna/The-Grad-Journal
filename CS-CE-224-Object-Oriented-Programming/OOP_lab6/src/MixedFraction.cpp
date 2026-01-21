#include "MixedFraction.hpp"
#include <iostream>
#include <cmath>
using namespace std;

int gcd(const int a, const int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

std::ostream& operator<<(std::ostream& os, const MixedFraction& mf) {
    os << "MixedFraction(" << mf.m_whole << " " << mf.m_numerator << "/"
       << mf.m_denominator << ")";
    return os;
}

//helper 
void MixedFraction::check_fraction() {
    int common_div = gcd(m_numerator, m_denominator);
    m_numerator /= common_div;
    m_denominator /= common_div;
    // improper to mixed 
    if (m_numerator >= m_denominator) {
        m_whole += m_numerator / m_denominator;
        m_numerator = m_numerator % m_denominator;
    }
}

MixedFraction::MixedFraction(const int whole, const int numerator, const int denominator) {
    m_whole = whole;
    m_numerator = numerator;
    m_denominator = denominator;
    check_fraction();
}

int MixedFraction::getWhole() const {
    return m_whole;
}

int MixedFraction::getNumerator() const {
    return m_numerator;
}

int MixedFraction::getDenominator() const {
    return m_denominator;
}

MixedFraction MixedFraction::operator+(const MixedFraction& other) const {
    int common_denominator = m_denominator * other.m_denominator;
    int total_num1 = m_whole * common_denominator + 
                    m_numerator * other.m_denominator;
    int total_num2 = other.m_whole * common_denominator + 
                    other.m_numerator * m_denominator;
    int new_numerator = total_num1 + total_num2;
    MixedFraction result(0, new_numerator, common_denominator);
    return result;
}

MixedFraction MixedFraction::operator-(const MixedFraction& other) const {
    int common_denominator = m_denominator * other.m_denominator;
    int total_num1 = m_whole * common_denominator + 
                    m_numerator * other.m_denominator;
    int total_num2 = other.m_whole * common_denominator + 
                    other.m_numerator * m_denominator;
    int new_numerator = total_num1 - total_num2;
    MixedFraction result(0, new_numerator, common_denominator);
    return result;
}

MixedFraction MixedFraction::operator*(const MixedFraction& other) const {
    int num1 = m_whole * m_denominator + m_numerator;
    int num2 = other.m_whole * other.m_denominator + other.m_numerator;
    int new_numerator = num1 * num2;
    int new_denominator = m_denominator * other.m_denominator;
    MixedFraction result(0, new_numerator, new_denominator);
    return result;
}

MixedFraction MixedFraction::operator/(const MixedFraction& other) const {
    int num1 = m_whole * m_denominator + m_numerator;
    int num2 = other.m_whole * other.m_denominator + other.m_numerator;
    int new_numerator = num1 * other.m_denominator;
    int new_denominator = m_denominator * num2;
    MixedFraction result(0, new_numerator, new_denominator);
    return result;
}

MixedFraction& MixedFraction::operator+=(const MixedFraction& other) {
    int common_denominator = m_denominator * other.m_denominator;
    int total_num1 = m_whole * common_denominator + 
                    m_numerator * other.m_denominator;
    int total_num2 = other.m_whole * common_denominator + 
                    other.m_numerator * m_denominator;
    int new_numerator = total_num1 + total_num2;
    m_whole = 0;
    m_numerator = new_numerator;
    m_denominator = common_denominator;
    check_fraction();
    return *this;
}

MixedFraction& MixedFraction::operator-=(const MixedFraction& other) {
    int common_denominator = m_denominator * other.m_denominator;
    int total_num1 = m_whole * common_denominator + 
                    m_numerator * other.m_denominator;
    int total_num2 = other.m_whole * common_denominator + 
                    other.m_numerator * m_denominator;
    int new_numerator = total_num1 - total_num2;
    m_whole = 0;
    m_numerator = new_numerator;
    m_denominator = common_denominator;
    check_fraction();
    return *this;
}

MixedFraction& MixedFraction::operator*=(const MixedFraction& other) {
    int num1 = m_whole * m_denominator + m_numerator;
    int num2 = other.m_whole * other.m_denominator + other.m_numerator;
    m_whole = 0;
    m_numerator = num1 * num2;
    m_denominator = m_denominator * other.m_denominator;
    check_fraction();
    return *this;

}

MixedFraction& MixedFraction::operator/=(const MixedFraction& other) {
    int num1 = m_whole * m_denominator + m_numerator;
    int num2 = other.m_whole * other.m_denominator + other.m_numerator;
    m_whole = 0;
    m_numerator = num1 * other.m_denominator;  
    m_denominator = m_denominator * num2;
    check_fraction();
    return *this;
}

bool MixedFraction::operator==(const MixedFraction& other) const {
    int total_num1 = m_whole * m_denominator + m_numerator;
    int total_num2 = other.m_whole * other.m_denominator + other.m_numerator;
    if (total_num1 * other.m_denominator == total_num2 * m_denominator){
        return true;}
    return false;
}

bool MixedFraction::operator!=(const MixedFraction& other) const {
    int total_num1 = m_whole * m_denominator + m_numerator;
    int total_num2 = other.m_whole * other.m_denominator + other.m_numerator;
    if (total_num1 * other.m_denominator != total_num2 * m_denominator){
        return true;}
    return false;
}