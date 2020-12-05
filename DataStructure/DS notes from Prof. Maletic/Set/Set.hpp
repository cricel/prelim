#ifndef CS2_SET_HPP_
#define CS2_SET_HPP_
#include<iostream>
#include<initializer_list>

const int domain = 256; // size

class Set {

public:
	/* reason to need defaut constructor is because when we define object in main,
	default constructor will be called implicitly*/
	Set();
	Set(int);
	Set(int, int);
	Set(int, int, int);
	Set(std::initializer_list<int>); // set a = {3,4,5,6, ...}

	int card() const;
	/* const method cannot modify the object they are called upon
	to avoid unwanted side effect */

	bool operator[](int)const; // const version from professor
	bool operator[](int);  // non const version self add
	Set operator*(const Set&) const; //intersection: No copy by &, and no modified by const
	Set operator+(const Set&) const;
	Set operator-(const Set&) const;
	bool operator==(const Set&) const;
	bool operator<=(const Set&) const;
	bool operator<(const Set&) const;


private:
	bool s[domain];
};

//free function outside of class
std::ostream& operator<<(std::ostream&, const Set&);
bool operator!=(const Set&, const Set&);
bool operator> (const Set&, const Set&);
bool operator>=(const Set&, const Set&);

// a = b+1 will work, since Set(1) convertion let 1 to be a Set obj
// a = 1 + b will not work. so we have to have the following:
Set operator*(int, const Set&);  
Set operator+(int, const Set&);
Set operator-(int, const Set&);



bool operator==(int, const Set&);  // for free function, we dont need const outside to let modification not allowed
bool operator< (int, const Set&);
bool operator<=(int, const Set&);

bool isValid(int);

#endif

/*
foo(set)			pass by value copy made
foo(set&)			pass by reference, no copy, allow modify
foo(set&) const		pass by ref, no copy, not allow modify
*/
