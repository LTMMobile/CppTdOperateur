//
//  main.cpp
//  TdOperateur
#include <iostream>

// 1.
class String {
private:
    char * _ptr;
    
public:
    String( const char * p = nullptr ) {
        if( p != NULL ) {
            _ptr = new char[strlen(p)+1];
            strcpy(_ptr, p);
        }else
            _ptr = NULL;
    }
    
    // copy ctor
    String( const String& cs ) {
        if( cs._ptr != NULL ) {
            _ptr = new char[strlen(cs._ptr)+1];
            strcpy(_ptr, cs._ptr);
        }else
            _ptr = NULL;
    }
    
    String& operator = (const String& cs) {
        if( this != &cs && cs._ptr != nullptr ) { 
            if(_ptr != nullptr)
                delete [] _ptr;
            
            _ptr = new char[strlen(cs._ptr)+1];
            strcpy(_ptr, cs._ptr);
        }
        return *this;
    }
    
    // 2.
    operator const char *() const {
        return _ptr;
    }
    
    const char * get() const {
        return _ptr;
    }
    
    // 3. s1 += s2;
    String& operator +=( const String& cs ) {
        
        if(cs._ptr == NULL)
            return *this;
        
        if( _ptr == NULL ) {
            this->_ptr = new char[strlen(cs._ptr)+1];
            strcpy(_ptr, cs._ptr);
        }else {
            char * temp = new char[strlen(_ptr)+strlen(cs._ptr)+1];
            strcpy( temp, _ptr );
            strcat( temp, cs._ptr );
            delete [] _ptr;
            _ptr = temp;
        }
        
        return *this;
    }
    
    // 4 s1 = (s2 + s3);
    String operator + (const String& cs ) const {
        String temp;
        temp += *this;
        temp += cs;
        return temp;
    }
    
    ~String() {
        if(_ptr) {
            delete [] _ptr;
            _ptr = NULL;
        }
    }
};

int main() {
    String s1("test");
    String s3;
    s3 += s1;
    
    String s4("test");
    s4 += s1;
    
    String s5("test");
    String s10 = s4 + s5;
    
    std::cout << s1.get();
    
    return 0;
}
