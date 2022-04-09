#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Matrix.hpp"

namespace zich{

    Matrix::Matrix()
        : array({}), rows(0), columns(0){
        
    }

    Matrix::Matrix(std::vector<double> arr, int n, int m)
        : array(arr), rows(n), columns(m){
        
    }

    // plus and minus operators
    Matrix Matrix::operator+() const {
        return Matrix();
    }

    Matrix Matrix::operator+(const Matrix& other) const {
        return Matrix();
    }

    Matrix& Matrix::operator+=(const Matrix& other) {
        return *this;
    }

    Matrix Matrix::operator-() const {
        return Matrix();
    }

    Matrix Matrix::operator-(const Matrix& other) const {
        return Matrix();
    }

    Matrix& Matrix::operator-=(const Matrix& other) {
        return *this;
    }

    // Comaprsion Operators
    bool Matrix::operator>(const Matrix& other) const{
        return true;
    }

    bool Matrix::operator>=(const Matrix& other) const{
        return true;
    }

    bool Matrix::operator<(const Matrix& other) const{
        return true;
    }

    bool Matrix::operator<=(const Matrix& other) const{
        return true;
    }

    bool Matrix::operator==(const Matrix& other) const{
        return true;
    }

    bool Matrix::operator!=(const Matrix& other) const{
        return true;
    }

    // addition and substition by 1, prefix and postfix
    Matrix& Matrix::operator++(){
        return *this;
    }

    Matrix& Matrix::operator++(int){
        return *this;
    }

    Matrix& Matrix::operator--(){
        return *this;
    }

    Matrix& Matrix::operator--(int){
        return *this;
    }

    // multiplication operator
    Matrix operator*(double real_number,const Matrix& other){
        return Matrix();
    }

    Matrix Matrix::operator*(const Matrix& other) const{
        return Matrix();
    }

    Matrix& Matrix::operator*=(const Matrix& other){
        return *this;
    }

    Matrix Matrix::operator*(double real_number) const{
        return Matrix();
    }

    Matrix& Matrix::operator*=(double real_number){
        return *this;
    }

    // input and output oprators
    std::ostream& operator<< (std::ostream& output, const Matrix& other){
        return output;
    }

    std::istream& operator>> (std::istream& input , Matrix& other){
        return input;
    }

};