#pragma once
#include <iostream>

using namespace std;


class Array {
private:
    int size;
    int step;
    int* array;
    int real_size;


public:
    Array(int size = 1, int step = 1);
    ~Array();
    void expandArray(int);
    void setValue(int);
    void showElements();
    int getSize();
    int getElemSize();
    void setArray(int*, int);
    Array operator+(int val) const;
    Array operator-(int val) const;
    Array operator+=(int val) const;
    Array operator++(int);
    int& operator[](int index);
    Array operator+(const Array& other) const;
    bool operator==(const Array& other) const;
    bool operator!=(const Array& other) const;
    Array(const Array&);
    Array& operator = (const Array&);
    friend Array operator+(int value, const Array& arr);
    friend std::ostream& operator<<(std::ostream& os, const Array& arr);
};