#ifndef PROJECTOFDEATH_LINKEDLIST_H
#define PROJECTOFDEATH_LINKEDLIST_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class LinkedList{

public:
    struct Node{
        Node();
        ~Node();
        T data;
        Node *next;
        Node *prev;
    };
    //Accessors
    void PrintForward () const;
    void PrintReverse() const;
    unsigned int NodeCount() const;
    void FindAll(vector<Node *> &outData, const T&value) const;
    const Node *Find(const T &data) const;
    Node *Find(const T &data);
    const Node * GetNode(unsigned int index) const;
    Node * GetNode(unsigned int index);
    Node *Head();
    const Node *Head() const;
    Node *Tail();
    const Node *Tail() const;

    //Insertion
    void AddHead(const T &data);
    void AddTail (const T &data);
    void AddNodesHead(const T *data, unsigned int count);
    void AddNodesTail(const T *data, unsigned int count);
    void InsertAfter(Node *node, const T &data);
    void InsertBefore(Node *node, const T &data);
    void InsertAt(const T &data, unsigned int index);

    //Removal
    bool RemoveHead();
    bool RemoveTail();
    unsigned int Remove(const T &data);
    bool RemoveAt(int index);
    void Clear();

    //Operators
    const T & operator[](unsigned int index) const;
    T & operator[](unsigned int index);
    bool operator==(const LinkedList<T> &rhs) const;
    LinkedList<T> & operator=(const LinkedList<T> &rhs);

    //Construction
    LinkedList(); //Done
    LinkedList(const LinkedList<T> &list); //Done Maybe
    ~LinkedList(); //Done Maybe

private:
    Node *ptrHead;
    Node *ptrTail;
    unsigned int totalNodes;

};

template <typename T>
void LinkedList<T>::PrintForward() const {
    Node *nextItem = ptrHead;

    for(unsigned int i = 0; i < totalNodes; i++) {
        cout << nextItem->data<<endl;
        nextItem = nextItem->next;
    }
}

template <typename T>
void LinkedList<T>::PrintReverse() const {
    Node *prevItem = ptrTail;

    for (unsigned int i = 0; i < totalNodes; i++) {
        cout << prevItem->data<<endl;
        prevItem = prevItem->prev;
    }
}

template<typename T>
unsigned int LinkedList<T>::NodeCount() const {
    return totalNodes;
}

template<typename T>
void LinkedList<T>::FindAll(vector<LinkedList::Node *> &outData, const T &value) const {
    Node *nextItem = ptrHead;
    while (nextItem) {
        if(nextItem->data == value){
            outData.push_back(nextItem);
        }
        nextItem = nextItem->next;
    }
}

template<typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Find(const T &data) const {
    Node *nextItem = ptrHead;
    while (nextItem) {
        if(nextItem->data == data){
            return nextItem;
        }
        nextItem = nextItem->next;
    }
    return nullptr;
}

template<typename T>
typename LinkedList<T>::Node *LinkedList<T>::Find(const T &data) {
    Node *nextItem = ptrHead;
    while (nextItem) {
        if(nextItem->data == data){
            return nextItem;
        }
        nextItem = nextItem->next;
    }
    return nullptr;
}

template<typename T>
const typename LinkedList<T>::Node *LinkedList<T>::GetNode(unsigned int index) const {
    Node *AtIndex = ptrHead;
    if (index < totalNodes){
        for(unsigned int i = 0; i < index; i++){
            AtIndex = AtIndex->next;
        }
        AtIndex->prev = AtIndex->next->prev;
        return AtIndex;
    }
    else{
        throw "Error! Invalid Index";
    }
}

template<typename T>
typename LinkedList<T>::Node *LinkedList<T>::GetNode(unsigned int index) {
    Node *AtIndex = ptrHead;
    if (index < totalNodes){
        for(unsigned int i = 0; i < index; i++){
            AtIndex = AtIndex->next;
        }
        AtIndex->prev = AtIndex->next->prev;
        return AtIndex;
    }
    else{
        throw "Error! Invalid Index";
    }
}

template<typename T>
typename LinkedList<T>::Node *LinkedList<T>::Head() {
    return ptrHead;
}

template<typename T>
const typename LinkedList<T>::Node *LinkedList<T>::Head() const {
    return ptrHead;
}

template<typename T>
typename LinkedList<T>::Node *LinkedList<T>::Tail() {
    return ptrTail;
}

template<typename T>
const typename LinkedList<T>::Node *LinkedList<T>::Tail() const {
    return ptrTail;
}

template<typename T>
void LinkedList<T>::AddHead(const T &data) {
    Node *addHead = new Node();
    addHead->data = data;
    if(ptrTail == nullptr){
        ptrTail = addHead;
    }
    else{
        ptrHead->prev = addHead;
    }

    addHead->next = ptrHead;
    ptrHead = addHead;
    totalNodes++;
}

template<typename T>
void LinkedList<T>::AddTail(const T &data) {
    Node *addTail = new Node();
    addTail->data = data;
    if (ptrHead == nullptr){
        ptrHead = addTail;
    }
    else{
        ptrTail->next = addTail;
    }

    addTail->prev = ptrTail;
    ptrTail = addTail;
    totalNodes++;
}

template<typename T>
void LinkedList<T>::AddNodesHead(const T *data, unsigned int count) {
    for(unsigned int i = 1; i <= count; i++){
        Node *addHeads = new Node();
        addHeads->data = data[count - i];
        if(ptrHead == nullptr){
            ptrTail = addHeads;
        }
        else{
            ptrHead->prev = addHeads;
        }
        addHeads->next = ptrHead;
        ptrHead = addHeads;
        totalNodes++;
    }
}

template<typename T>
void LinkedList<T>::AddNodesTail(const T *data, unsigned int count) {
    for(unsigned int i = 0; i < count; i++){
        Node *addTails = new Node();
        addTails->data = data[i];
        if(ptrTail == nullptr){
            ptrHead = addTails;
        }
        else{
            ptrTail->next = addTails;
        }
        addTails->prev = ptrTail;
        ptrTail = addTails;
        totalNodes++;
    }
}

template<typename T>
void LinkedList<T>::InsertAfter(LinkedList::Node *node, const T &data) {
    Node *newNode = new Node();
    Node *nextNode = node->next;
    newNode->data = data;

    newNode->next = nextNode;
    node->next = newNode;
    totalNodes++;
}

template<typename T>
void LinkedList<T>::InsertBefore(LinkedList::Node *node, const T &data) {
    Node *newNode = new Node();
    Node *prevNode = node->prev;
    newNode->data = data;

    newNode->next = node;
    prevNode->next = newNode;
    totalNodes++;
}

template<typename T>
void LinkedList<T>::InsertAt(const T &data, unsigned int index) {
    Node *AtIndex = ptrHead;
    Node *newNode = new Node();

    unsigned int i = 1;
    if(index == 0){
        AddHead(data);
        delete newNode;
    }
    else {
        while (i < index) {
            AtIndex = AtIndex->next;
            i++;
        }
        newNode->data = data;
        newNode->next = AtIndex->next;
        AtIndex->next = newNode;
        totalNodes++;
    }
}

template<typename T>
bool LinkedList<T>::RemoveHead() {
    if(totalNodes > 0){
        Node *newHead = ptrHead->next;
        delete ptrHead;
        ptrHead = newHead;
        totalNodes--;
        return true;
    }
    else{
        return false;
    }
}

template<typename T>
bool LinkedList<T>::RemoveTail() {
    if(totalNodes > 0){
        Node *newTail = ptrTail->prev;
        delete ptrTail;
        ptrTail = newTail;
        ptrTail->next = nullptr;
        totalNodes--;
        return true;
    }
    else{
        return false;
    }
}

template<typename T>
unsigned int LinkedList<T>::Remove(const T &data) {
    Node *node = ptrHead;
    unsigned int removedCount = 0;
    unsigned int i = 0;
    while (node) {
        if(node->data == data){
            Node *temp = node->next;
            node->data = node->next->data;
            node->next = temp->next;
            delete temp;
            removedCount++;
            totalNodes--;
            i++;
        }
        node = node->next;
    }
    return removedCount;
}

template<typename T>
bool LinkedList<T>::RemoveAt(int index) {
    int i = 1;
    Node *node = ptrHead;
    if (index < (int)totalNodes) {
        while (i < index+1) {
            node = node->next;
            i++;
        }
        Node *temp = node->next;
        node->data = node->next->data;
        node->next = temp->next;
        delete temp;
        totalNodes--;
        return true;
    }
    else{
        return false;
    }
}

template<typename T>
void LinkedList<T>::Clear() {
    Node *next = ptrHead;
    for(unsigned int i = 0; i < totalNodes; i++) {
        Node *deleteHead = next;
        next = next->next;
        delete deleteHead;
    }
    ptrHead = nullptr;
    ptrTail = nullptr;
    totalNodes = 0;
}

template<typename T>
const T &LinkedList<T>::operator[](unsigned int index) const {
    Node *AtIndex = ptrHead;
    if (index < totalNodes){
        if(index == 0){
            return ptrHead->data;
        }
        else{
            for(unsigned int i = 0; i < index; i++){
                AtIndex = AtIndex->next;
            }
        }
        return AtIndex->data;
    }
    else{
        throw "Error! Invalid Index";
    }
}

template<typename T>
T &LinkedList<T>::operator[](unsigned int index) {
    Node *AtIndex = ptrHead;
    if (index < totalNodes){
        if(index == 0){
            return ptrHead->data;
        }
        else{
            for(unsigned int i = 0; i < index; i++){
                AtIndex = AtIndex->next;
            }
        }
        return AtIndex->data;
    }
    else{
        throw "Error! Invalid Index";
    }
}

template<typename T>
bool LinkedList<T>::operator==(const LinkedList<T> &rhs) const {
    Node *temp = ptrHead;
    unsigned int count = 0;
    for(unsigned int i = 0; i < totalNodes; i++){
        if(temp->data == rhs[i]){
            count++;
        }
        temp = temp->next;
    }
    return count == totalNodes;
}

template<typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs) {
    if (rhs.ptrHead == nullptr){
        ptrHead = nullptr;
        ptrTail = nullptr;
    }
    else{
        for(unsigned int i = 0; i < rhs.totalNodes; i++){
            AddTail(rhs[i]);
        }
    }
    return *this;
}

template<typename T>
LinkedList<T>::LinkedList() {
    ptrHead = nullptr;
    ptrTail = nullptr;
    totalNodes = 0;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list) {
    ptrHead = nullptr;
    ptrTail = nullptr;
    totalNodes = 0;
    for(unsigned int i = 0; i < list.totalNodes; i++){
        AddTail(list[i]);
    }
}

template<typename T>
LinkedList<T>::~LinkedList() {
    Node *next = ptrHead;
    for(unsigned int i = 0; i < totalNodes; i++) {
        Node *deleteHead = next;
        next = next->next;
        delete deleteHead;
    }
}

template<typename T>
LinkedList<T>::Node::Node() {
    next = nullptr;
    prev = nullptr;
}

template<typename T>
LinkedList<T>::Node::~Node() {

}

#endif //PROJECTOFDEATH_LINKEDLIST_H
