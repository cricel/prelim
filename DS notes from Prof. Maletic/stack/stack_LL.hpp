/*
 * linklist_stack.hpp
 */

#ifndef LINKLIST_STACK_HPP_
#define LINKLIST_STACK_HPP_
#include <new>
#include<cassert>

//---------class node ------------
template<typename T>
class Node{
public:
    Node(){next = 0;}
    Node(const T& x){data = x; next = 0;}
    T   data;
    Node<T> *next;
};

//---------class Stack------------
template<typename T>
class Stack{
private:
    Node<T> *tos;
public:
    Stack(){tos=0;}
    Stack(const Stack<T>&);
    ~Stack();
    void   swap(Stack<T>&);
    Stack<T>&   operator =(Stack<T>);
    bool   isEmpty()const{return tos == 0;}
    bool   isFull()const;
    T   top()const;
    T   pop();
    void   push(const T&);
    
};


//---------copy ctor ------------
template<typename T>
Stack<T>::Stack(const Stack<T>& actual){
    Node<T> *bottom, *temp = actual.tos;
    tos = 0;
    while(temp!=0){
        if(tos ==0){
            tos = new Node<T>(temp->data);
            bottom = tos;
        }
        else{
            bottom = new Node<T>(temp->data);
            bottom = bottom->next;
        }
        temp = temp->next;
    }
}

//---------destructor ------------
template<typename T>
Stack<T>::~Stack(){
    Node<T> *temp;
    while (tos!=0){
        temp = tos;
        tos = tos->next;
        delete temp;
    }
}

//---------swap------------
template<typename T>
void Stack<T>::swap(Stack<T>& rhs){
    Node<T> *temp= tos;
    tos = rhs.tos;
    rhs.tos = temp;
}
//---------assinment overload------------
template<typename T>
Stack<T>&  Stack<T>::operator=(Stack<T> rhs){
    swap(rhs);
    return *this;
}

//--------isFull()------------
template<typename T>
bool Stack<T>::isFull()const{
    Node<T> *temp = new(std::nothrow)Node<T>();
    if(!temp) return true;
    else delete temp;
    return false;
}
//---------top ------------
template<typename T>
T  Stack<T>::top()const{
    assert(tos!=0);
    return tos->data;
}

//---------pop ------------
template<typename T>
T  Stack<T>::pop(){
    assert(tos!=0);
    T result = tos->data;
    Node<T> *temp = tos;
    tos = tos->next;
    delete temp;
    return result;
}

//---------push ------------
template<typename T>
void Stack<T>::push(const T& newItem){
    assert(!isFull());
    Node<T> *temp = new Node<T>(newItem);
    temp->next =tos;
    tos = temp;
}

#endif /* LINKLIST_STACK_HPP_ */
