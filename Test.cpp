/**
 * AUTHORS: Inon Sinn
 * 
 * Date: 05/04/2022
 */

#include <iostream>
#include "doctest.h"
#include "Matrix.hpp"

using namespace zich;

TEST_CASE("Construction"){
    std::vector<double> arr1 = {0,0,0,0};
    CHECK_THROWS(Matrix(arr1,-1,1));
    CHECK_THROWS(Matrix(arr1,1,-1));
    CHECK_THROWS(Matrix(arr1,-1,-1));
};

TEST_CASE("Plus minus"){
    std::vector<double> arr1 = {0,0,0,0};
    std::vector<double> arr2 = {3,3,3,3};
    std::vector<double> arr3 = {6,6,6,6};
    Matrix a{arr1, 2, 2};
    Matrix b{arr2, 2, 2};
    Matrix c{arr3, 2, 2};

    // plus
    CHECK_EQ(a+b==b,true);
    CHECK_EQ(b+b==c,true);
    b+=b;
    CHECK_EQ(b==c,true);

    // minus
    CHECK_EQ(b-a==b,true);
    CHECK_EQ(b-b==a,true);
    b-=b;
    CHECK_EQ(b==a,true);
};

TEST_CASE("Comparison"){

    
    std::vector<double> arr1 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    std::vector<double> arr2 = {3, 0, 0, 0, 3, 0};
    Matrix a{arr1, 3, 3}; // sum = 9
    Matrix b{arr2, 3, 2};

    // Check throws for bad input
    // CHECK_THROWS(a<b);
    // CHECK_THROWS(a<=b);
    // CHECK_THROWS(a>b);
    // CHECK_THROWS(a>=b);
    // CHECK_THROWS(a==b);
    // CHECK_THROWS(a!=b);

    std::vector<double> arr3 = {1, 1, 1, 1, 2, 1, 1, 1, 1};
    Matrix c{arr3, 3, 3}; // sum = 10

    // Check correctness

    // >
    CHECK_FALSE(a>b);
    CHECK_EQ(b>a,true);
    // >=
    CHECK_FALSE(a>=b);
    CHECK_EQ(a>=a,true);
    // <
    CHECK_FALSE(b<a);
    CHECK_EQ(a<b,true);
    // <=
    CHECK_FALSE(b<=a);
    CHECK_EQ(a<=a,true);
    // ==
    CHECK_FALSE(a==b);
    CHECK_EQ(a==a,true);
    // !=
    CHECK_FALSE(a!=a);
    CHECK_EQ(a!=b,true);

};

TEST_CASE("prefix and postfix"){
    std::vector<double> arr1 = {0,0,1,1};
    std::vector<double> arr2 = {1,1,2,2};
    std::vector<double> arr3 = {2,2,3,3};
    Matrix a{arr1, 2, 2};
    Matrix b{arr2, 2, 2};
    Matrix c{arr3, 2, 2};

    // prefix
    CHECK_EQ((--c)==b,true);
    CHECK_EQ((++a)==b,true);
    
    c++;
    a--;

    // postfix
    CHECK_EQ((c--)==b,false);
    CHECK_EQ((a++)==b,false);

};

TEST_CASE("Multiplication"){
    std::vector<double> arr1 = {1,1,1,1};
    std::vector<double> arr2 = {3,3,3,3};
    std::vector<double> arr3 = {6,6,6,6};
    Matrix a{arr1, 2, 2};
    Matrix b{arr2, 2, 2};
    Matrix c{arr3, 2, 2};

    // Multiplication with real numbers
    CHECK_EQ(a*3 == b, true);
    CHECK_EQ(b*2 == c, true);
    CHECK_EQ(b*3 != c, true);
    
    Matrix d{arr1, 2, 2};
    Matrix e{arr1, 2, 2};
    d*=3;
    e*=3;
    CHECK_EQ(d == b, true);
    CHECK_EQ(e != c, true);

    // Multiplication with matrixes
    CHECK_EQ(a*b == c, true);
    a*=b;
    CHECK_EQ(a == c, true);

};
