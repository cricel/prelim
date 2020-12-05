#include "String.hpp"

int String::Capacity()    const{
    return STRING_SIZE-1;
}

String::String(){
    str[0]=0;
} //default constructor, constructor: no type, no return

String::String(const char ch){
    str[0]= ch;
    str[1]= 0;
}

String::String(const char* cstr){
    int i=0;
    while(cstr[i]!=0){
        str[i]=cstr[i];
        ++i;
        if(i>=Capacity()) break;
    }
    str[i]=0;
}

int String::length() const{
    int i = 0;
    while(str[i]!=0) ++i;
    return i;
}

char& String::operator[](int index){
    assert(index < 0 );
    assert(index > STRING_SIZE);
    return str[index];
    
}

char String::operator[](int index)const{
    assert(index < 0 );
    assert(index > STRING_SIZE);
    return str[index];
}


bool String::operator== (const String& rhs)const{
    int i = 0;
    while(str[i]==rhs.str[i] && str[i]!=0){
        ++i;
    }
    return str[i]==rhs.str[i];
}

bool String::operator<(const String& rhs)const {
    int i = 0;
    while (str[i] != 0 && rhs.str[i] != 0 && str[i] == rhs.str[i]) {
        ++i;
    }
    return str[i] < rhs.str[i];
}


std::ostream& operator<<(std::ostream& out, const String& rhs) {
    out << rhs.str;   // using the c++ string natural property for output
    return out;
}

std::istream& operator>>(std::istream& in, String& rhs) { // String& rhs is not const due to modify
    char temp[STRING_SIZE];
    in >> temp;
    rhs = String(temp);
    return in;
}


bool operator==(const char* lhs, const String& rhs) {
    return String(lhs) == rhs;
}

bool operator==(const char lhs, const String& rhs) {
    return String(lhs) == rhs;
}

bool operator<(const char* lhs, const String& rhs) {
    return String(lhs) < rhs;
}
bool operator<(const char lhs, const String& rhs) {
    return String(lhs) < rhs;
}


bool operator<=(const String& lhs, const String& rhs) {
    return !(rhs < lhs);
}
bool operator!=(const String& lhs, const String& rhs) {
    return !(rhs == lhs);
}
bool operator>=(const String& lhs, const String& rhs) {
    return !(lhs < rhs);
}
bool operator>(const String& lhs, const String& rhs) {
    return (rhs < lhs);
}



String String::operator+(const String& rhs) const {
    int offset = length();
    String result(str); // avoid copying
    int i = 0;
    while (rhs.str[i] != 0) {
        if ((offset + i) >= Capacity()) break;
        result.str[offset + i] = rhs[i];
        ++i;
    }
    result.str[i] = 0;
    return result;
}

String& String::operator+=(const String& rhs) { // need to modify the object itself so &after String
    int start = length();
    int i = 0;
    while (rhs.str[i] != 0) {
        if ((start + i) >= Capacity()) break;
        str[start + i] = rhs.str[i];
        ++i;
    }
    str[start + i] = 0;
    return *this;  // modified the object itself and return itself
}


String String::substr(int s, int e)const {
    String result;
    if (s < 0) s = 0;
    if (s > e) return String();
    if (e >= length()) return e = length() -1;
    int i = 0;
    while(i<(e-s)){
        result[i] = str[i + s];
        ++i;
    }
    result[i] = 0;
    return result;
}

int String::findChar(char ch, int pos)const {
    if(pos < 0) pos =0;
    if(pos > length()-1) return -1;
    int i = pos;
    while(str[i] != 0){
        if(str[i] == ch){
            return i;
        }
        ++i;
    }
    return -1;
}

int String::findSubstr(const String& s, int pos) const{
    if(pos<0) pos = 0;
    if(pos> length()-s.length()) return -1;
    int i = pos;
    int len = s.length();
    while(str[i]!=0){
        if(substr(i,i+len-1) == s)
            return i;
        ++i;
    }
    return -1;
}


String String::insertChar(const char ch, const int pos) const{
    int len = length();
    if(pos <0 ) pos = 0;
    if(pos>len) pos =len;
    String result;
    int i = 0;
    while (str[i] != 0) {
        if( i == pos -1){
            result.str[i] = str[i];
            result.str[i+1] = ch;
        }
        else if (i >= pos)
            result.str[i+1] = str[i];
        else
            result.str[i] = str[i];
        ++i;
    }
    result.str[i] = 0;
    return result;
}

//+++++++++++++ the below is missed from class, but should be like this ++++++++++++++++++
String String::deleteChar(const int pos)const {
    int len = length();
    if(pos <0 ) pos = 0;
    if(pos>len) pos =len;
    String result;
    int i = 0;
    while(str[i]!=0){
        if(i < pos) {
            result[i] = str[i];
        }
        else
            result[i] = str[i + 1];
        
        ++i;
    }
    result[i] = 0;
    return result;
}
// +++++++++++++++++++++++++++++++++++++++++++++++


