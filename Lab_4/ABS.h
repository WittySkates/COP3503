//
// Created by Connor on 9/30/18.
//

#ifndef LAB_5_ABS_H
#define LAB_5_ABS_H

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class ABS {

private:
    unsigned int Size;
    unsigned int Capacity;
    T *ptr;
public:
    //Constructors
    ABS();
    ABS(unsigned int);

    //Big Three
    ABS(const ABS&other);
    ABS&operator=(const ABS&other);
    ~ABS();

    //Accessors
    unsigned int getMaxCapacity() const;
    unsigned int getSize() const;
    T * getData();
    T peek();

    //Mutators
    void push(T data);
    T pop();
    void Remove(unsigned int index);
    void Resize(unsigned int newSize);
};
//Constructors
template <typename T>
ABS<T>::ABS() {
    Size = 0;
    Capacity = 1;
    this->ptr = new T[this->Capacity];
}

template <typename T>
ABS<T>::ABS(unsigned int max) {
    Size = 0;
    Capacity = max;
    this->ptr = new T[this->Capacity];
}

template <typename T>
ABS<T>::ABS(const ABS &other) {
    Size = other.Size;
    Capacity = other.Capacity;
    this->ptr = new T[this->Capacity];

    for(unsigned int i = 0; i < Capacity; i++){
        ptr[i] = other.ptr[i];
    }
}

template <typename T>
ABS<T> &ABS<T>::operator=(const ABS&other){
    Size = other.Size;
    Capacity = other.Capacity;
    this->ptr = new T[this->Capacity];

    for(unsigned int i = 0; i < Capacity; i++){
        ptr[i] = other.ptr[i];
    }
    return *this;
}

template <typename T>
ABS<T>::~ABS() {
    delete [] ptr;
}

//Accessors
template <typename T>
unsigned int ABS<T>::getMaxCapacity() const {
    return this->Capacity;
}

template <typename T>
unsigned int ABS<T>::getSize() const {
    return this->Size;
}

template <typename T>
T* ABS<T>::getData() {
    return this->ptr;
}

//Mutators
template <typename T>
void ABS<T>::push(T data) {
    if(Size < Capacity) {
        this->ptr[Size] = data;
        Size++;
    }
    else{
        Resize(2 * Capacity);
        this->ptr[Size] = data;
        Size++;
    }
}

template <typename T>
void ABS<T>::Resize(unsigned int newSize) {
    T *ptrTemp = new T[newSize];
    unsigned int i = 0;
    while(i < Capacity && i < newSize){
        ptrTemp[i] = this->ptr[i];
        i++;
    }
    delete [] ptr;
    Capacity = newSize;
    this->ptr = ptrTemp;
}

template <typename T>
T ABS<T>::pop() {
    float Store;
    if(Size == 0){
        throw -1;
    }
    else{

        Store = ptr[Size-1];
        for(unsigned int i = Size-1; i < Size; i++) {
            this->ptr[i] = this->ptr[i+1];
            Size--;
        }
        if (Size < ((float)Capacity/2)){
            Resize(Capacity/2);

        }
    }
    return Store;
}

//Return Specific Element
template<typename T>
T ABS<T>::peek() {
    if (Size == 0) {
        throw -1;
    }
    else{
        return ptr[Size-1];
    }
}

#endif //LAB_5_ABS_H
