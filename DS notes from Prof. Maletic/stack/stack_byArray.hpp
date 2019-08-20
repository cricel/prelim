/*
 * stack_byArray.hpp
 *
 */

#ifndef STACK_ARRAY_HPP_
#define STACK_ARRAY_HPP_
#include"String.hpp"
#include<fstream>
#include<cassert>

const int maxsize = 50;

template<typename T>
class Stack{	
	public:
        Stack(){tos = -1;};
        bool isEmpty()const{return tos <= -1;};
        bool isfull()const{return tos >= maxsize-1;};
        T  pop(){assert(!isEmpty());return data[tos--];};
        void  push(const T& x){assert(!isfull());data[++tos] = x;};
        T  top()const{return data[tos];};
    private:
        int tos;
        T   data[maxsize];
};



//--------infix2prefix stack -----------
void infix2prefix(std::ifstream& in, std::ofstream& out){
	String token;
	Stack<String> stk;
	in>>token;
	while(!(token == ";")){
		if(!(token =="(") &&!(token ==")"))
			stk.push(token);
		else if(token ==")"){
			String rhs,op,lhs;
			rhs = stk.pop();
			op  = stk.pop();
			lhs = stk.pop();
			stk.push(op+lhs+rhs);
		}
		in>>token;
	}
	out<<stk.pop();
}



#endif /* STACK_ARRAY_HPP_ */

/* algo :
 Given a valid postfix expression: S
 while(not done with S){
    t = next token(S)
    if (t is operand) push (t)
    else{  //there is t as operator
        rhs = pop();
        lhs = pop();
        push( eval(lhs,t,rhs);
    }
 }
 */


