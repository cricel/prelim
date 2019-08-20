/*
 * linklist_queue.hpp
 *
 */

#ifndef LINKLIST_QUEUE_HPP_
#define LINKLIST_QUEUE_HPP_
#include <new>
#include<cassert>
#include<iostream>
#include<cstdlib>
///////////////// node //////////////

template<typename T>
class node{
	public:

	node(){next = NULL;}
	node(const T& v, node<T> *n){
		value = v;
		next = n;
	}

     T  value;
node<T> *next;
};

///////////// Queue ////////////////

template<typename T>
class Queue{
	private:
		node<T> *beginning;
		node<T> *ending;
	public:
			Queue(){beginning = NULL; ending = NULL;}
			~Queue();
	 void  	enqueue(const T&);
	    T  	dequeue();
 Queue<T>&  operator=(const Queue<T>);
			Queue(const Queue<T>&); //copty ctor
    bool    isEmpty()const;
    bool   isFull()const;

};

//----------- destructor ---------------
template<typename T>
Queue<T>::~Queue(){
	while(beginning!=NULL){
		node<T> *temp = beginning;
		beginning = beginning->next;
		delete temp;	// temp is a pointer pointing to node<T> type
	}
}

//----------- enqueue ---------------
template<typename T>
void Queue<T>::enqueue(const T& v){
	if(ending == NULL && beginning == NULL){
		beginning = new node<T>(v,NULL);
		ending = beginning;
	}
	else{
		ending->next = new node<T>(v,NULL);
        ending = ending->next;
	}
}

//----------- dequeue---------------
template<typename T>
T  Queue<T>::dequeue(){
	node<T>*temp = beginning;
	T val= temp->value;
    if(beginning == ending){
        beginning =0;
        ending =0;
    }else{
        beginning = beginning->next;
    }
	delete temp;
	return val;
}
//----------- swap ---------------
void Queue<T>::swap(Queue<T>&  rhs){
    node<T>*temp = beginning;
    beginning= rhs.beginning;
    rhs.beginning = temp;
    temp = ending;
    ending =rhs.ending;
    rhs.ending =temp;
}
//----------- = overload ---------------
//ver1.
/*
template<typename T>
Queue<T>&  Queue<T>::operator=(const Queue<T>& rhs){

	//delete all existing elements in Queue
	while(beginning!=NULL){
		node<T> *temp = beginning;
		beginning = beginning->next;
		delete temp;
	}
	//enqueue all elements same as rhs to  Queue
	node<T>* temp = rhs.beginning;			//the later one is read-only
	beginning = NULL;

	while(temp!=NULL){
		enqueue(temp->value);
		temp=temp->next;
	}
	return *this;
}
*/
//ver.2
Queue<T>&  Queue<T>::operator=(Queue<T> rhs){
    swap(rhs);
    return *this;
}

//-----------copy ctor ---------------
template<typename T>
Queue<T>::Queue(const Queue<T>& rhs){
	node<T>* temp = rhs.beginning;
	beginning = NULL;

	while(temp!=NULL  ){

		if(beginning == NULL){
			ending = new node<T>(temp->value, NULL);
			beginning = ending;

		}
		else{
			ending->next= new node<T>(temp->value, NULL);
            ending = ending->next;

		}

		temp =temp->next;

	}
}

//----------- isEmpty()---------------
bool Queue<T>::isEmpty()const{
    return beginning ==0;
}
//----------- isFull()---------------
bool Queue<T>::isFull()const{
    node<T>* temp = new(std::nothrow) node<T>();
    if(!temp){
        return true;
    }
    delete temp;
    return false;
}

#endif /* LINKLIST_QUEUE_HPP_ */
