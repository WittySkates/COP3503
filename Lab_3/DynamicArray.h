//
// Created by Connor on 9/18/18.
//

#ifndef LAB_4_DYNAMICARRAY_H
#define LAB_4_DYNAMICARRAY_H

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

template <typename T>
class DynamicArray {

private:
    unsigned int Size;
    unsigned int Capacity;
    T *ptr;
public:
    //Constructors
    DynamicArray();
    DynamicArray(unsigned int);

    //Big Three
    DynamicArray(const DynamicArray&other);
    DynamicArray&operator=(const DynamicArray&other);
    ~DynamicArray();

    //Accessors
    unsigned int GetCapacity() const;
    unsigned int GetSize() const;
    const T *   GetData();

    //Return Specific Element
    const T &operator[](unsigned int index) const;
    T &operator[](unsigned int index);

    //Question Mark
    const T &At(unsigned int index) const;
    T &At(unsigned int index);

    //Mutators
    void Add(const T &data);
    void Resize(unsigned int newSize);
    void Remove(unsigned int index);
};
//Constructors
template <typename T>
DynamicArray<T>::DynamicArray() {
    this->Size = 0;
    this->Capacity = 0;
    this->ptr = nullptr;
}

template <typename T>
DynamicArray<T>::DynamicArray(unsigned int max) {
    this->Size = 0;
    this->Capacity = max;
    this->ptr = new T[this->Capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray &other) {
    this->Size = other.Size;
    this->Capacity = other.Capacity;
    this->ptr = new T[this->Capacity];

    for(unsigned int i = 0; i < Capacity; i++){
        ptr[i] = other.ptr[i];
    }
}

template <typename T>
DynamicArray<T> &DynamicArray<T>::operator=(const DynamicArray&other){
    this->Size = other.Size;
    this->Capacity = other.Capacity;
    this->ptr = new T[this->Capacity];

    for(unsigned int i = 0; i < Capacity; i++){
        ptr[i] = other.ptr[i];
    }
    return *this;
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete [] ptr;
}

//Accessors
template <typename T>
unsigned int DynamicArray<T>::GetCapacity() const {
    return this->Capacity;
}

template <typename T>
unsigned int DynamicArray<T>::GetSize() const {
    return this->Size;
}

template <typename T>
const T* DynamicArray<T>::GetData() {
    return this->ptr;
}

//Mutators
template <typename T>
void DynamicArray<T>::Add(const T &data) {
    if(Size < Capacity) {
        this->ptr[Size] = data;
        this->Size++;
    }
    else{
        Resize(Capacity + 1);
        this->ptr[Size] = data;
        this->Size++;
    }
}

template <typename T>
void DynamicArray<T>::Resize(unsigned int newSize) {
    T *ptrTemp = new T[newSize];
    unsigned int i = 0;
    Size = 0;
    while(i < Capacity && i < newSize){
        ptrTemp[i] = this->ptr[i];
        Size++;
        i++;
    }
    cout << "Resizing...\told capacity: " << this->Capacity;
    delete [] ptr;
    Capacity = newSize;
    cout << "\tNew capacity: " << this->Capacity << endl;
    this->ptr = ptrTemp;
}

template <typename T>
void DynamicArray<T>::Remove(unsigned int index) {
    if(Capacity == 0){
        throw "Error! Invalid index";
    }
    else if(index < Capacity - 1){
        for(unsigned int i = index; i < Capacity-1; i++) {
            this->ptr[i] = this->ptr[i+1];
        }
        Size--;
    }
    else if(index < Capacity){
        Size--;
    }
    else{
        throw "Error! Invalid index";
    }
}

//Return Specific Element
template <typename T>
const T& DynamicArray<T>::At(unsigned int index) const {
    if(index < Capacity){
    return this->ptr[index];
    }
    else{
        throw "Error: Invalid index";
    }
}

template <typename T>
T& DynamicArray<T>::At(unsigned int index) {
    if(index < Capacity){
        return this->ptr[index];
    }
    else{
        throw "Error: Invalid index";
    }}

//Question Mark
template <typename T>
const T& DynamicArray<T>::operator[](unsigned int index) const {
    if(index < Capacity){
        return this->ptr[index];
    }
    else{
        throw "Error: Invalid index";
    }
}

template <typename T>
T& DynamicArray<T>::operator[](unsigned int index) {
    if(index < Capacity){
        return this->ptr[index];
    }
    else{
        throw "Error: Invalid index";
    }
}

#endif //LAB_4_DYNAMICARRAY_H
