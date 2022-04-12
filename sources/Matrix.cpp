#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Matrix.hpp"

namespace zich{

    void Matrix::setRow(int row){
        if(row<=0){
            throw std::invalid_argument("The MAtrix size as to be at least 1");
        }
        this -> rows = row;
    }

    void Matrix::setCol(int col){
        if(col<=0){
            throw std::invalid_argument("The MAtrix size as to be at least 1");
        }
        this -> columns = col;
    }

    void Matrix::setArr(const std::vector<double>& arr,int row,int col){
        if(arr.size() != row*col){
            throw std::invalid_argument("Given data does not fit given parameters");
        }
        this -> array = arr;
    }

    void Matrix::setMatrix(const std::vector<double>& arr,int row,int col){
        setRow(row);
        setCol(col);
        setArr(arr, row, col);
    }

    Matrix::Matrix(){
        columns = 1;
        rows = 1;
        setMatrix({0},1,1);
    }

    Matrix::Matrix(const std::vector<double>& arr, int n, int m){
        columns = 1;
        rows = 1;
        setMatrix(arr,n,m);
    }

    void Matrix::printMat(){
        for (size_t i = 0; i < array.size(); i++)
        {
            std::cout << array.at(i) <<",";
        }
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