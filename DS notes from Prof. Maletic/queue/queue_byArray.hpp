/*
 * queue_buArray.hpp
 *
 */

#ifndef QUEUE_ARRAY_HPP_
#define QUEUE_ARRAY_HPP_
#include<cassert>
const int maxQueueSize = 100;

template<typename T>
class queue{
	private:
		int  front,back;
		bool empty;
		T    q[maxQueueSize];

	public:
        queue():front (0), back (0), empty(true){}; //default ctor
	    void  enqueue(const T&);
	       T  dequeue();
        bool  isEmpty()const{return empty;};
        bool  isfull()const{ return (front == back) && !empty;};
};

template<typename T>
void  enqueue(const T& item){
	assert(!isfull());
	q[back]=item; // back is at one more behind of the last eliment
	back = (back+1)% maxQueueSize;
	empty = false;
}

template<typename T>
T  dequeue(){
	assert(!empty);
	T result = q[front];
	front = (front+1)% maxQueueSize;
	if(front == back) empty = true;
	return result;
}





#endif /* QUEUE_ARRAY_HPP_ */
