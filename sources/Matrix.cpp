#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Matrix.hpp"

namespace zich{

    // set functin for the row parameter
    void Matrix::setRow(int row){
        if(row<=0){
            throw std::invalid_argument("The MAtrix size as to be at least 1");
        }
        this -> rows = row;
    }

    // set functin for the column parameter
    void Matrix::setCol(int col){
        if(col<=0){
            throw std::invalid_argument("The MAtrix size as to be at least 1");
        }
        this -> columns = col;
    }

    // set functin for the data parameter
    void Matrix::setArr(const std::vector<double>& arr,int row,int col){
        if(arr.size() != row*col){
            throw std::invalid_argument("Given data does not fit given parameters");
        }
        this -> array = arr;
    }

    // set functin for a new Matrix
    void Matrix::setMatrix(const std::vector<double>& arr,int row,int col){
        setRow(row);
        setCol(col);
        setArr(arr, row, col);
    }

    // Empty Constructor 
    Matrix::Matrix(){
        columns = 1;
        rows = 1;
        setMatrix({0},1,1);
    }

    // Constructor
    Matrix::Matrix(const std::vector<double>& arr, int n, int m){
        columns = 1;
        rows = 1;
        setMatrix(arr,n,m);
    }

    // DELETE THIS
    void Matrix::printMat(){
        for (size_t i = 0; i < array.size(); i++)
        {
            std::cout << array.at(i) <<",";
        }
    }

    // Function that test the input
    void Matrix::Test_Input(const Matrix& other) const{
        if(other.rows != this -> rows || other.columns != this -> columns){
            throw::std::invalid_argument("The size parameters of the Matrixes have to be the same");
        }
    }

    // plus and minus operators
    Matrix Matrix::operator+() const {
        return Matrix(array,rows,columns);
    }

    Matrix Matrix::operator+(const Matrix& other) const {
        Test_Input(other);

        std::vector<double> newArr;
        double newData= 0;
        for (size_t i = 0; i < rows*columns; i++)
        {
            newData= array.at(i) + other.array.at(i);
            newArr.push_back(newData);
        }
        return Matrix(newArr,rows,columns);
    }

    Matrix& Matrix::operator+=(const Matrix& other) {
        Test_Input(other);

        for (size_t i = 0; i < rows*columns; i++)
        {
            this -> array.at(i) = array.at(i) + other.array.at(i);
        }
        return *this;
    }

    Matrix Matrix::operator-() const {
        std::vector<double> newArr;
        double newData = 0;
        for (size_t i = 0; i < rows*columns; i++)
        {
            newData= array.at(i)*(-1);
            newArr.push_back(newData);
        }
        return Matrix(newArr,rows,columns);
    }

    Matrix Matrix::operator-(const Matrix& other) const {
        Test_Input(other);

        std::vector<double> newArr;
        double newData = 0;
        for (size_t i = 0; i < rows*columns; i++)
        {
            newData= array.at(i) - other.array.at(i);
            newArr.push_back(newData);
        }
        return Matrix(newArr,rows,columns);
    }

    Matrix& Matrix::operator-=(const Matrix& other) {
        Test_Input(other);

        for (size_t i = 0; i < rows*columns; i++)
        {
            this -> array.at(i) = array.at(i) - other.array.at(i);
        }
        return *this;
    }

    double Matrix::Matrix_Sum() const{
        double sum = 0;
        for (size_t i = 0; i < rows*columns; i++){
            sum += array.at(i);
        }
        return sum;
    }

    // Comaprsion Operators
    bool Matrix::operator>(const Matrix& other) const{
        Test_Input(other);
        return Matrix_Sum() > other.Matrix_Sum();
    }

    bool Matrix::operator>=(const Matrix& other) const{
        Test_Input(other);
        return Matrix_Sum() >= other.Matrix_Sum();
    }

    bool Matrix::operator<(const Matrix& other) const{
        Test_Input(other);
        return Matrix_Sum() < other.Matrix_Sum();
    }

    bool Matrix::operator<=(const Matrix& other) const{
        Test_Input(other);
        return Matrix_Sum() <= other.Matrix_Sum();
    }

    bool Matrix::operator==(const Matrix& other) const{
        Test_Input(other);
        for (size_t i = 0; i < rows*columns; i++)
        {
            if (array.at(i) != other.array.at(i))
            {
                return false;
            }
        }
        return true;
    }

    bool Matrix::operator!=(const Matrix& other) const{
        Test_Input(other);
        return !(*this==other);
    }

    // addition and substition by 1, prefix and postfix
    Matrix& Matrix::operator++(){
        for (size_t i = 0; i < rows*columns; i++)
        {
            this -> array.at(i) = array.at(i) + 1;
        }
        return *this;
    }

    Matrix Matrix::operator++(int){
        Matrix temp = Matrix(array,rows,columns);
        ++(*this);
        return temp;
    }

    Matrix& Matrix::operator--(){
        for (size_t i = 0; i < rows*columns; i++)
        {
            this -> array.at(i) = array.at(i) - 1;
        }
        return *this;
    }

    Matrix Matrix::operator--(int){
        Matrix temp = Matrix(array,rows,columns);
        --(*this);
        return temp;
    }

    // multiplication operator
    Matrix operator*(double real_number,const Matrix& other){
        return other*real_number;
    }

    Matrix Matrix::operator*(const Matrix& other) const{
        if(columns != other.rows){
            throw std::invalid_argument("The size parameters don't allow the use of Matrix Manipulation");
        }
        std::vector<double> newArr;
        std::vector<double> single_row;
        double newData = 0;
        double index = 0;

        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < columns; j++)
                {
                    index = (int)i *columns + (int)j; 
                    newData = array.at(index);
                    single_row.push_back(newData);
            }
            for (size_t j = 0; j < other.columns; j++)
            {
                newData = 0;
                for (size_t i = 0; i < other.rows; i++)
                {
                    index = (int)j + other.columns*(int)i;
                    newData += single_row.at(i)*other.array.at(index);
                }
                newArr.push_back(newData);
            }
            single_row.clear();
        }
        return Matrix(newArr,rows,other.columns);
    }

    Matrix& Matrix::operator*=(const Matrix& other){
        *this = *this * other;
        return *this;
    }

    Matrix Matrix::operator*(double real_number) const{
        std::vector<double> newArr;
        double newData = 0;
        for (size_t i = 0; i < rows*columns; i++)
        {
            newData= array.at(i) * real_number;
            newArr.push_back(newData);
        }
        return Matrix(newArr,rows,columns);
    }

    Matrix& Matrix::operator*=(double real_number){
        for (size_t i = 0; i < rows*columns; i++)
        {
            this -> array.at(i) = array.at(i)*real_number;
        }
        return *this;
    }

    // input and output oprators
    std::ostream& operator<< (std::ostream& output, const Matrix& other){
        double input = 0;
        for (int i = 0; i < other.rows; i++)
        {
            output << "[";
            for (int j = 0; j < other.columns; j++)
            {
                input = j + (int)other.rows*i;
                output << other.array.at(input);
                if( j == other.columns - 1){
                    output<<"]";
                }
                else{
                    output<<" ";
                }
            }
            if( i != other.rows - 1){
                output<<"\n";
            }
        }
        return output;
    }

    std::vector<double> check_braket(std::string input,unsigned long start){
        std::vector<double> arr;
        if(input[start] != '['){
            throw std::invalid_argument("Input has something else than invalid before a bracket");
        }
        bool atNumber = true;
        // unfinshed
        return arr; 
    }


    std::istream& operator>> (std::istream& input , Matrix& other){
        std::string s(std::istreambuf_iterator<char>(input), {});
        unsigned long start = 0;
        int rows = 0;
        int cols = 0;
        std::vector<double> arr;

        // going over the brackets
        cols = check_braket(s,0).size();
        while(start < s.length()){
            std::vector<double> bracket = check_braket(s,start);
            rows++;
            // Test if all the brackets are of the same size
            if(cols != bracket.size()){
                throw std::invalid_argument("Input has rows with different sizes");
            }

            // Test in between the brackets
            start += 2*(unsigned long)cols;
            if(s.at(start)=='\n'){
                if(start == s.size()-1){
                    start++;
                }
                else{
                    throw std::invalid_argument("Input has line end in the middle of the input");
                }
            }
            else{
                if(s.at(start)==',' && s.at(start)==' '){
                    start += 2;
                }
                else{
                    throw std::invalid_argument("Input has something else than ', ' between the brackets");
                }
            }

            // copy the brackets numbers into the complete array
            for (size_t i = 0; i < bracket.size(); i++)
            {
                arr.push_back(bracket.at(i));
            }
            
        }
        other = Matrix(arr,rows,cols);
        return input;
    }


};