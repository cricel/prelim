//
//  string.hpp
//  
//


#ifndef string_hpp
#define string_hpp

#include <stdio.h>
#include<iostream>
#include<cassert>

const int STRING_SIZE = 256;

class String{
public:
    String            ();
    String            (const char*);
    String            (const char);
    
    char&    operator[]        (int);
    char    operator[]        (int)                        const;
    int        Capacity        ()                            const;
    int        length            ()                          const;
    bool    operator==        (const String&)                const;
    bool    operator<        (const String&)                const;
    String  operator+        (const String&)                const;
    String& operator+=        (const String&);
    
    String insertChar        (const char, const int)        const;
    String deleteChar        (const int)                    const;
    String substr            (int, int)                    const;
//    String prefix            (int)                        const; // no code for class, but maybe in their lab code
//    String suffix            (int)                        const;
    int       findChar           (const char, const int)        const;
    int       findSubstr        (const String&, const int)    const;
    
    friend std::ostream& operator<<(std::ostream&, const String&);
    
private:
    char str[STRING_SIZE];
};

std::istream& operator>>(std::istream&, String&); 

bool operator==(const char*, const String&);
bool operator==(const char,  const String&);

bool operator< (const char*, const String&);
bool operator< (const char,  const String&);

bool operator<=(const String&, const String&);
bool operator!=(const String&, const String&);
bool operator>=(const String&, const String&);
bool operator>(const String&, const String&);

#endif /* string_hpp */
