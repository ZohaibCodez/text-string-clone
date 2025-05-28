#ifndef TEXT_H
#define TEXT_H

#include <cstddef>
#include <iostream>
#include <initializer_list>
#include <cstring>
#include <stdexcept>
#include <limits>
using namespace std;

class text
{
private:
    char *data;
    size_t len;
    size_t cap;

public:
    static const size_t npos = -1;
    // *********************CONSTRUCTORS*********************
    // Default Constructor
    text();
    // Copy Constructor
    text(const text &tex);
    // Substring Constructor
    text(const text &tex, size_t pos, size_t npos);
    // From c-string
    text(const char *tex);
    // From buffer
    text(const char *tex, size_t n);
    // Fill Constructor
    text(size_t n, char c);
    // Range Constructor
    text(const char *first, const char *last);
    // Initializer List Constructor
    text(initializer_list<char> il);
    // Move Constructor
    text(text &&tex) noexcept;

    // *********************DESTRUCTURE*********************
    ~text();

    // *********************OPERATOR=*********************
    // Copy Assignment
    text &operator=(const text &tex);
    // C-String Assignment
    text &operator=(const char *t);
    // Character Assignment
    text &operator=(char c);
    // Initializer List Assignment
    text &operator=(initializer_list<char> il);
    // Move Assignment
    text &operator=(text &&tex) noexcept;

    // *********************CAPACITY*********************
    size_t size() const noexcept;
    size_t length() const noexcept;
    size_t max_size() const noexcept;
    void resize(size_t n);
    void resize(size_t n, char c);
    size_t capacity() const noexcept;
    void reserve(size_t n = 0);
    void clear() noexcept;
    bool empty() const noexcept;
    void shrink_to_fit();

    // *********************ELEMENT ACCESS*********************

    char &operator[](size_t pos);
    const char &operator[](size_t pos) const;
    char &at(size_t pos);
    const char &at(size_t pos) const;
    char &back();
    const char &back() const;
    char &front();
    const char &front() const;

    // *********************MODIFIERS*********************
    text &operator+=(const text &tex); // string
    text &operator+=(const char *s);   // c-string
    text &operator+=(char c);          // character

    text &append(const text &tex);                               // string
    text &append(const text &tex, size_t subpos, size_t sublen); // substring
    text &append(const char *s);                                 // c-string
    text &append(const char *s, size_t n);                       // buffer
    text &append(size_t n, char c);                              // fill

    void push_back(char c);

    text &assign(const text &tex);                               // string
    text &assign(const text &tex, size_t subpos, size_t sublen); // substring
    text &assign(const char *s);                                 // c-string
    text &assign(const char *s, size_t n);                       // buffer
    text &assign(size_t n, char c);                              // fill

    text &insert(size_t pos, const text &tex);                               // string
    text &insert(size_t pos, const text &tex, size_t subpos, size_t sublen); // substring
    text &insert(size_t pos, const char *s);                                 // c-string
    text &insert(size_t pos, const char *s, size_t n);                       // buffer
    text &insert(size_t pos, size_t n, char c);                              // fill

    text &erase(size_t pos = 0, size_t n = npos);

    text &replace(size_t pos, size_t n, const text &tex); // string

    void swap(text &tex);

    void pop_back();

    // *********************STRING OPERATIONS)*********************

    const char *c_str() const;
    // const char *data() const;
    size_t copy(char *s, size_t len, size_t pos = 0) const;

    size_t find(const text &tex, size_t pos = 0) const;     // string
    size_t find(const char *s, size_t pos = 0) const;       // c-string
    size_t find(const char *s, size_t pos, size_t n) const; // buffer
    size_t find(char c, size_t pos = 0) const;              // char

    size_t rfind(const text &tex, size_t pos = npos) const;  // string
    size_t rfind(const char *s, size_t pos = npos) const;    // c-string
    size_t rfind(const char *s, size_t pos, size_t n) const; // buffer
    size_t rfind(char c, size_t pos = npos) const;           // char

    size_t find_first_of(const text &tex, size_t pos = 0) const;     // string
    size_t find_first_of(const char *s, size_t pos = 0) const;       // c-string
    size_t find_first_of(const char *s, size_t pos, size_t n) const; // buffer
    size_t find_first_of(char c, size_t pos = 0) const;              // char

    size_t find_last_of(const text &tex, size_t pos = npos) const;  // string
    size_t find_last_of(const char *s, size_t pos = npos) const;    // c-string
    size_t find_last_of(const char *s, size_t pos, size_t n) const; // buffer
    size_t find_last_of(char c, size_t pos = npos) const;           // char

    text substr(size_t pos = 0, size_t n = npos) const;

    int compare(const text &tex) const;                                 // string
    int compare(size_t pos, size_t n, const text &tex) const;         // sub-string
    int compare(const char *s) const;                                   // c-string
    int compare(size_t pos, size_t n, const char *s) const;           // c-string
    int compare(size_t pos, size_t lenn, const char *s, size_t n) const; // buffer

    // *********************NON-MEMBER(FRIEND FUNCTIONS)*********************

    friend text operator+(const text &lhs, const text &rhs);
    friend text operator+(const text &lhs, const char *rhs);
    friend text operator+(const char *lhs, const text &rhs);
    friend text operator+(const text &lhs, char rhs);
    friend text operator+(char lhs, const text &rhs);

    // == operator
    friend bool operator==(const text &lhs, const text &rhs);
    friend bool operator==(const char *lhs, const text &rhs);
    friend bool operator==(const text &lhs, const char *rhs);

    // != operator
    friend bool operator!=(const text &lhs, const text &rhs);
    friend bool operator!=(const char *lhs, const text &rhs);
    friend bool operator!=(const text &lhs, const char *rhs);

    // < operator
    friend bool operator<(const text &lhs, const text &rhs);
    friend bool operator<(const char *lhs, const text &rhs);
    friend bool operator<(const text &lhs, const char *rhs);

    // <= operator
    friend bool operator<=(const text &lhs, const text &rhs);
    friend bool operator<=(const char *lhs, const text &rhs);
    friend bool operator<=(const text &lhs, const char *rhs);

    // > operator
    friend bool operator>(const text &lhs, const text &rhs);
    friend bool operator>(const char *lhs, const text &rhs);
    friend bool operator>(const text &lhs, const char *rhs);

    // >= operator
    friend bool operator>=(const text &lhs, const text &rhs);
    friend bool operator>=(const char *lhs, const text &rhs);
    friend bool operator>=(const text &lhs, const char *rhs);

    void swap(text &x, text &y);

    friend istream &operator>>(istream &is, text &tex);
    friend ostream &operator<<(ostream &os, const text &tex);

    istream &getline(istream &is, text &tex, char delim);
    istream &getline(istream &is, text &tex);

    void print() const;
};

#endif
