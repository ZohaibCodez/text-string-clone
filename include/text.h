#ifndef TEXT_H
#define TEXT_H

#include <cstddef>
#include <iostream>
#include <initializer_list>
#include <cstring>
#include <stdexcept>
#include <limits>

class text {
private:
    char* data;
    size_t len;
    size_t cap;

public:
    static const size_t npos = static_cast<size_t>(-1);

    // Constructors
    text();
    text(const text& tex);
    text(const text& tex, size_t pos, size_t npos);
    text(const char* tex);
    text(const char* tex, size_t n);
    text(size_t n, char c);
    text(const char* first, const char* last);
    text(std::initializer_list<char> il);
    text(text&& tex) noexcept;

    // Destructor
    ~text();

    // Assignments
    text& operator=(const text& tex);
    text& operator=(const char* t);
    text& operator=(char c);
    text& operator=(std::initializer_list<char> il);
    text& operator=(text&& tex) noexcept;

    // Capacity
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

    // Element Access
    char& operator[](size_t pos);
    const char& operator[](size_t pos) const;
    char& at(size_t pos);
    const char& at(size_t pos) const;
    char& back();
    const char& back() const;
    char& front();
    const char& front() const;

    // Modifiers
    text& operator+=(const text& tex);
    text& operator+=(const char* s);
    text& operator+=(char c);

    text& append(const text& tex);
    text& append(const text& tex, size_t subpos, size_t sublen);
    text& append(const char* s);
    text& append(const char* s, size_t n);
    text& append(size_t n, char c);

    void push_back(char c);

    text& assign(const text& tex);
    text& assign(const text& tex, size_t subpos, size_t sublen);
    text& assign(const char* s);
    text& assign(const char* s, size_t n);
    text& assign(size_t n, char c);

    text& insert(size_t pos, const text& tex);
    text& insert(size_t pos, const text& tex, size_t subpos, size_t sublen);
    text& insert(size_t pos, const char* s);
    text& insert(size_t pos, const char* s, size_t n);
    text& insert(size_t pos, size_t n, char c);

    text& erase(size_t pos = 0, size_t n = npos);
    text& replace(size_t pos, size_t n, const text& tex);

    void swap(text& tex);
    void pop_back();

    // String Operations
    const char* c_str() const;
    size_t copy(char* s, size_t len, size_t pos = 0) const;

    size_t find(const text& tex, size_t pos = 0) const;
    size_t find(const char* s, size_t pos = 0) const;
    size_t find(const char* s, size_t pos, size_t n) const;
    size_t find(char c, size_t pos = 0) const;

    size_t rfind(const text& tex, size_t pos = npos) const;
    size_t rfind(const char* s, size_t pos = npos) const;
    size_t rfind(const char* s, size_t pos, size_t n) const;
    size_t rfind(char c, size_t pos = npos) const;

    size_t find_first_of(const text& tex, size_t pos = 0) const;
    size_t find_first_of(const char* s, size_t pos = 0) const;
    size_t find_first_of(const char* s, size_t pos, size_t n) const;
    size_t find_first_of(char c, size_t pos = 0) const;

    size_t find_last_of(const text& tex, size_t pos = npos) const;
    size_t find_last_of(const char* s, size_t pos = npos) const;
    size_t find_last_of(const char* s, size_t pos, size_t n) const;
    size_t find_last_of(char c, size_t pos = npos) const;

    text substr(size_t pos = 0, size_t n = npos) const;

    int compare(const text& tex) const;
    int compare(size_t pos, size_t n, const text& tex) const;
    int compare(const char* s) const;
    int compare(size_t pos, size_t n, const char* s) const;
    int compare(size_t pos, size_t len, const char* s, size_t n) const;

    // Stream operations
    friend std::istream& operator>>(std::istream& is, text& tex);
    friend std::ostream& operator<<(std::ostream& os, const text& tex);

    std::istream& getline(std::istream& is, text& tex, char delim);
    std::istream& getline(std::istream& is, text& tex);

    void print() const;

    // Operators
    friend text operator+(const text& lhs, const text& rhs);
    friend text operator+(const text& lhs, const char* rhs);
    friend text operator+(const char* lhs, const text& rhs);
    friend text operator+(const text& lhs, char rhs);
    friend text operator+(char lhs, const text& rhs);

    friend bool operator==(const text& lhs, const text& rhs);
    friend bool operator==(const char* lhs, const text& rhs);
    friend bool operator==(const text& lhs, const char* rhs);

    friend bool operator!=(const text& lhs, const text& rhs);
    friend bool operator!=(const char* lhs, const text& rhs);
    friend bool operator!=(const text& lhs, const char* rhs);

    friend bool operator<(const text& lhs, const text& rhs);
    friend bool operator<(const char* lhs, const text& rhs);
    friend bool operator<(const text& lhs, const char* rhs);

    friend bool operator<=(const text& lhs, const text& rhs);
    friend bool operator<=(const char* lhs, const text& rhs);
    friend bool operator<=(const text& lhs, const char* rhs);

    friend bool operator>(const text& lhs, const text& rhs);
    friend bool operator>(const char* lhs, const text& rhs);
    friend bool operator>(const text& lhs, const char* rhs);

    friend bool operator>=(const text& lhs, const text& rhs);
    friend bool operator>=(const char* lhs, const text& rhs);
    friend bool operator>=(const text& lhs, const char* rhs);

    static void swap(text& x, text& y);
};

#endif // TEXT_H