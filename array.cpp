#include "array.h"
#include <iostream>

Array::Array(int size, int step) {
    this->size = size > 1 ? size : 1;
    this->step = step > 1 ? step : 1;
    real_size = 0;
    array = new int[size];

}

Array::~Array() {
    delete[] array;
}

void Array::expandArray(int delta) {
    int* array_prom = new int[size + delta];
    for (int i = 0; i < this->size; i++) {
        array_prom[i] = array[i];
    }
    delete[] array;
    array = array_prom;
    size = size + delta;

}

void Array::setValue(int val) {
    //Перевірка на заповненість маситву (чи треба створювати новий, чи ні) 
    if (size >= real_size) {
        expandArray(size + step);
        array[real_size] = val;
        real_size++;
    }
    else {
        array[real_size] = val;
        real_size++;
    }
}

void Array::showElements() {
    for (int i = 0; i < real_size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int Array::getSize() {
    return size;
}
int Array::getElemSize() {
    return real_size;
}

void Array::setArray(int* pArr, int size_mass) {
    if (size_mass + real_size > size) {
        expandArray(size_mass);
    }
    int j = 0;
    for (int i = real_size; i < size; i++) {
        array[i] = pArr[j];
        j++;
    }
    real_size += size_mass;
}


Array& Array::operator=(const Array& temporary)
{
    if (this == &temporary)
    {
        return *this;
    }
    delete[] array;

    real_size = temporary.real_size;
    size = temporary.size;
    
    array = new int[temporary.size];
    
    for (int i = 0; i < temporary.real_size; i++) {
        array[i] = temporary.array[i];
    }
    return *this;
}

Array::Array(const Array& temporary) {
    size = temporary.size;
    real_size = temporary.real_size;
    array = new int[temporary.size];
    for (int i = 0; i < temporary.size; i++)
    {
        array[i] = temporary.array[i];
    }
}


//Оператори:

Array Array::operator+(int val) const{
    for (int i = 0; i < real_size; i++) {
        array[i] = array[i] + val;
    }
    return *this;
}

Array Array::operator-(int val) const {
    for (int i = 0; i < real_size; i++) {
        array[i] = array[i] - val;
    }
    return *this;
}

Array Array::operator+= (int val) const {
    for (int i = 0; i < real_size; i++) {
        array[i] = array[i] + val;
    }
    return *this;
}

Array Array::operator++ (int) {
    for (int i = 0; i < real_size; i++) {
        array[i] = array[i] + 1;
    }
    return *this;
}

int& Array::operator[](int index) {
    if (index >= real_size) {
        return array[0];
    }
    return array[index];
}

Array Array::operator+(const Array& other) const {
    int new_size = size + other.size;
    Array result(new_size, 1);
    result.real_size = 0;
    for (int i = 0; i < real_size; i++) {
        result.array[i] = array[i];
        result.real_size++;
    }
    for (int i = 0; i < other.real_size; i++) {
        result.array[real_size + i] = other.array[i];
        result.real_size++;
    }

    return result;
}


bool Array::operator==(const Array& other) const {
    if (real_size != other.real_size) {
        return false;
    }
    for (int i = 0; i < real_size; i++) {
        if (array[i] != other.array[i]) {
            return false;
        }
    }
    return true;
}

bool Array::operator!=(const Array& other) const {
    if (real_size != other.real_size) {
        return true;
    }
    for (int i = 0; i < real_size; i++) {
        if (array[i] != other.array[i]) {
            return true;
        }
    }
    return false;
}

Array operator+(int value, const Array& arr) {
    return arr + value;
}

std::ostream& operator<<(std::ostream& os, const Array& arr) {
    for (size_t i = 0; i < arr.real_size; i++) {
        os << arr.array[i] << " ";
    }
    return os;
}