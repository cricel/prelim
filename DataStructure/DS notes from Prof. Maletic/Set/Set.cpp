#include "Set.hpp"

bool isValid(int x) {
	// guarding
	return ((x >= 0) && (x < domain));
}

Set::Set() {
	for (int i = 0; i < domain; ++i) {
		s[i] = false;
	}
}

Set::Set(int a):Set() { // called default Set() to initialize
	if(isValid(a)) s[a] = true;
}

Set::Set(int a, int b):Set(a){
	if (isValid(b)) s[b] = true;
}

Set::Set(int a, int b, int c):Set(a,b) {
	if (isValid(c)) s[c] = true;
}

Set::Set(std::initializer_list<int> lst):Set() {	
	for (int i : lst) {
		s[i] = true;
	}	
}

//only const version of [] in this Set case?

bool Set::operator[](int i) const{
	if (isValid(i)) return s[i];
	return false;
}
// non const version also need
bool Set::operator[](int i) {
	return s[i];
}


int Set::card() const { //card is to return the length with true in cell
	int result = 0;
	for (int i = 0; i < domain; ++i) {
		if (s[i]) ++result;
	}
	return result;
}

bool Set::operator==(const Set& rhs) const {  // const method apply on const obj "rhs"
	for (int i = 0; i < domain; ++i) {
		//if (s[i] != rhs.s[i]) return false;  //rhs[i] might be better since there is a guarding
		if (s[i] != rhs[i]) return false;  // const version of [] method is called
	}
	return true;
}

bool operator== (int lhs, const Set& rhs) {
	return Set(lhs) == rhs;
}

bool operator!= (const Set& lhs, const Set& rhs) {
	return !(lhs == rhs);
}

Set Set::operator*(const Set& rhs) const{
	Set result;
	for (int i = 0; i < domain; ++i) {
		result.s[i] = (s[i] && rhs.s[i]);
	}
	return result;
}

Set Set::operator+(const Set& rhs) const {
	Set result;
	for (int i = 0; i < domain; ++i) {
		result.s[i] = (s[i] || rhs.s[i]);
	}
	return result;
}

Set Set::operator-(const Set& rhs) const {
	Set result;
	for (int i = 0; i < domain; ++i) {
		result.s[i] = (s[i] && (!rhs.s[i]));
	}
	return result;
}

Set operator*(int lhs, const Set& rhs){	
	return Set(lhs)*rhs;
}
Set operator+(int lhs, const Set& rhs) {
	return Set(lhs)+rhs;
}
Set operator-(int lhs, const Set& rhs) {
	return Set(lhs)-rhs;
}

std::ostream& operator<<(std::ostream& out, const Set& rhs) {
	bool printComma = false;
	out << "{";
	for (int i = 0; i < domain; ++i) {
		if (rhs[i]) {  // here since is free function not memeber function, we cannot use rhs.s[i]
			if (printComma) out << ", ";
			out << i;
			printComma = true;
		}
	}
	out << "}";
	return out;
}

bool Set::operator<=(const Set& rhs) const {
	for (int i = 0; i < domain; ++i) {
		if (s[i] && !rhs.s[i]) return false;//compare the highest index spot i, whether s[i] is true and rhs is false, then return false	
	}
	return true;
}
bool Set::operator<(const Set& rhs) const { // issue there how to compare to sets?
	for (int i = 0; i <  domain; ++i) {
		if (!s[i] && rhs.s[i]) return true; //compare the highest index spot i, whether s[i] is true and rhs is false, then return false
	}
	return false;
}

bool operator<= (int i, const Set& rhs) {
	return Set(i) <= rhs;
}

bool operator< (int i, const Set& rhs) {
	return (Set(i) <= rhs) && (Set(i) !=rhs);
}

bool operator> (const Set& lhs, const Set& rhs) {
	return rhs < lhs;
}

bool operator>= (const Set& lhs, const Set& rhs) {
	return rhs <= lhs;
}



