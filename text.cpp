#include "text.h"

// Default Constructor
text::text() : data(nullptr), len(0), cap(1)
{
    data = new char[1];
    data[0] = '\0';
}

// Copy Constructor
text::text(const text &other) : len(other.len), cap(other.cap)
{
    data = new char[cap];
    memcpy(data, other.data, len + 1);
}

// Substring Constructor
text::text(const text &tex, size_t pos, size_t npos)
{
    if (pos > tex.len)
        throw out_of_range("Substring Constructor out of Range.");
    if (npos == -1 || pos + npos > tex.len)
    {
        npos = tex.len - pos;
    }
    len = npos;
    cap = npos + 1;
    data = new char[cap];
    memcpy(data, tex.data + pos, npos);
    data[len] = '\0';
}

// From C-String
text::text(const char *tex)
{
    len = strlen(tex);
    cap = len + 1;
    data = new char[cap];
    memcpy(data, tex, len + 1);
}

// From Buffer
text::text(const char *tex, size_t n) : len(n), cap(n + 1)
{
    data = new char[cap];
    memcpy(data, tex, n);
    data[n] = '\0';
}

// Fill Constructor
text::text(size_t n, char c) : len(n), cap(n + 1)
{
    data = new char[cap];
    for (int i = 0; i < len; i++)
    {
        data[i] = c;
    }
    data[n] = '\0';
}

// Range Constructor
text::text(const char *first, const char *last)
{
    len = last - first;
    cap = len + 1;
    data = new char[cap];
    memcpy(data, first, len);
    data[len] = '\0';
}

// Initializer List Constructor
text::text(initializer_list<char> il) : len(il.size()), cap(il.size() + 1)
{
    data = new char[cap];
    int i = 0;
    for (char c : il)
    {
        data[i] = c;
        i++;
    }
    data[len] = '\0';
}

// Move Constructor
text::text(text &&other) noexcept : data(other.data), len(other.len), cap(other.cap)
{
    other.data = nullptr;
    other.len = 0;
    other.cap = 0;
}

// Destructure
text::~text()
{
    delete[] data;
}

// Copy Assignment
text &text::operator=(const text &other)
{
    if (this != &other)
    {
        delete[] data;
        len = other.len;
        cap = other.cap;
        data = new char[cap];
        memcpy(data, other.data, len + 1);
    }
    return *this;
}

// C-String Assignment
text &text::operator=(const char *c)
{
    if (c == nullptr)
    {
        delete[] data;
        data = new char[1];
        data[0] = '\0';
        len = 0;
        cap = 1;
    }
    else
    {
        delete[] data;
        len = strlen(c);
        cap = len + 1;
        data = new char[cap];
        memcpy(data, c, len + 1);
    }
    return *this;
}

// Character Assignment
text &text::operator=(char c)
{
    delete[] data;
    len = 1;
    cap = 2;
    data = new char[cap];
    data[0] = c;
    data[1] = '\0';
    return *this;
}

// Initializer List Assignment
text &text::operator=(initializer_list<char> il)
{
    delete[] data;
    len = il.size();
    cap = len + 1;
    int i = 0;
    data = new char[cap];
    for (char c : il)
    {
        data[i++] = c;
    }
    data[len] = '\0';
    return *this;
}

// Move Assignment
text &text::operator=(text &&other) noexcept
{
    if (this != &other)
    {
        delete[] data;
        data = other.data;
        len = other.len;
        cap = other.cap;
        other.data = nullptr;
        other.len = 0;
        other.cap = 0;
    }
    return *this;
}

void text::print() const
{
    cout << data << endl;
}

// Capacity

size_t text::size() const noexcept
{
    return this->len;
}

size_t text::length() const noexcept
{
    return this->len;
}

size_t text::max_size() const noexcept
{
    return numeric_limits<size_t>::max() / sizeof(char) - 1;
}

void text::resize(size_t n)
{
    resize(n, '\0');
}

void text::resize(size_t n, char c)
{
    if (n < len)
    {
        len = n;
        data[len] = '\0';
    }
    else if (n > len)
    {
        cap = n + 1;
        char *newData = new char[cap];
        memcpy(newData, data, len);
        memset(newData + len, c, n - len);
        newData[n] = '\0';
        delete[] data;
        data = newData;
        if (c != '\0')
            len = n;
    }
}

size_t text::capacity() const noexcept
{
    return this->cap;
}

void text::reserve(size_t n)
{
    if (n > cap)
    {
        cap = n;
        char *newData = new char[n + 1];
        memcpy(newData, data, len);
        newData[len] = '\0';
        delete[] data;
        data = newData;
    }
}

void text::clear() noexcept
{
    if (data)
        data[0] = '\0';
    len = 0;
}

bool text::empty() const noexcept
{
    return (len == 0 ? true : false);
}

void text::shrink_to_fit()
{
    if (len < cap)
    {
        char *newData = new char[len + 1];
        memcpy(newData, data, len + 1);
        delete[] data;
        data = newData;
        cap = len;
    }
}

// ELEMENT ACCESS

char &text::operator[](size_t pos)
{
    return data[pos];
}

const char &text::operator[](size_t pos) const
{
    return data[pos];
}

char &text::at(size_t pos)
{
    if (pos >= len)
        throw out_of_range("Index Accessed is out of Range.");
    return data[pos];
}

const char &text::at(size_t pos) const
{
    if (pos >= len)
        throw out_of_range("Index Accessed is out of Range.");
    return data[pos];
}

char &text::back()
{
    return data[len - 1];
}

const char &text::back() const
{
    return data[len - 1];
}

char &text::front()
{
    return data[0];
}

const char &text::front() const
{
    return data[0];
}

// Modifiers

// += string
text &text::operator+=(const text &tex)
{
    append(tex);
    return *this;
}

//+= c-string
text &text::operator+=(const char *s)
{
    append(s);
    return *this;
}

// += character
text &text::operator+=(char c)
{
    append(1, c);
    return *this;
}

// append string
text &text::append(const text &tex)
{
    reserve(len + tex.len);
    memcpy(data + len, tex.data, tex.len);
    len = len + tex.len;
    data[len] = '\0';
    return *this;
}

// append sub-string
text &text::append(const text &tex, size_t subpos, size_t sublen)
{
    if (subpos > tex.len)
        subpos = tex.len;
    if (subpos + sublen > tex.len || sublen == static_cast<size_t>(-1))
        sublen = tex.len - subpos;
    reserve(len + sublen);
    memcpy(data + len, tex.data + subpos, sublen);
    len += tex.len;
    data[len] = '\0';
    return *this;
}

// append c-string
text &text::append(const char *s)
{
    size_t slen = strlen(s);
    reserve(len + slen);
    memcpy(data + len, s, slen);
    len += slen;
    data[len] = '\0';
    return *this;
}

// append buffer
text &text::append(const char *s, size_t n)
{
    reserve(len + n);
    memcpy(data + len, s, n);
    len += n;
    data[len] = '\0';
    return *this;
}

// append fill
text &text::append(size_t n, char c)
{
    reserve(len + n);
    for (int i = 0; i < n; i++)
    {
        data[len + i] = c;
    }
    len += n;
    data[len] = '\0';
    return *this;
}

void text::push_back(char c)
{
    reserve(len + 1);
    data[len++] = c;
    data[len] = '\0';
}

// assign string
text &text::assign(const text &tex)
{
    if (this != &tex)
    {
        reserve(tex.len);
        memcpy(data, tex.data, tex.len);
        len = tex.len;
        data[len] += '\0';
    }
    return *this;
}

// assign substring
text &text::assign(const text &tex, size_t subpos, size_t sublen)
{
    if (subpos > tex.len)
        subpos = tex.len;
    if (subpos + sublen > tex.len || sublen == static_cast<size_t>(-1))
        sublen = tex.len - subpos;
    reserve(sublen);
    memcpy(data, tex.data + subpos, sublen);
    len = sublen;
    data[len] = '\0';
    return *this;
}

// assign c-string
text &text::assign(const char *s)
{
    size_t slen = strlen(s);
    reserve(slen);
    memcpy(data, s, slen);
    len = slen;
    data[len] = '\0';
    return *this;
}

// assign buffer
text &text::assign(const char *s, size_t n)
{
    reserve(n);
    memcpy(data, s, n);
    len = n;
    data[len] = '\0';
    return *this;
}

// assign fill
text &text::assign(size_t n, char c)
{
    reserve(n);
    for (size_t i = 0; i < n; ++i)
        data[i] = c;
    len = n;
    data[len] = '\0';
    return *this;
}

// insert string
text &text::insert(size_t pos, const text &tex)
{
    if (pos > len)
        pos = len;
    reserve(len + tex.len);
    memmove(data + pos + tex.len, data + pos, len - pos);
    memcpy(data + pos, tex.data, tex.len);
    data[len] = '\0';
    len += tex.len;
    return *this;
}

// insert substring
text &text::insert(size_t pos, const text &tex, size_t subpos, size_t sublen)
{
    if (subpos > tex.len)
        subpos = tex.len;
    if (subpos + sublen > tex.len || sublen == static_cast<size_t>(-1))
        sublen = tex.len - subpos;
    if (pos > len)
        pos = len;
    reserve(len + sublen);
    memmove(data + pos + sublen, data + pos, len - pos);
    memcpy(data + pos, tex.data + subpos, sublen);
    len += sublen;
    data[len] = '\0';
    return *this;
}

// insert c-string
text &text::insert(size_t pos, const char *s)
{
    return insert(pos, s, strlen(s));
}

// insert buffer
text &text::insert(size_t pos, const char *s, size_t n)
{
    if (pos > len)
        pos = len;
    reserve(len + n);
    memmove(data + pos + n, data + pos, len - pos);
    memcpy(data + pos, s, n);
    len += n;
    data[len] = '\0';
    return *this;
}

// insert fill
text &text::insert(size_t pos, size_t n, char c)
{
    if (pos > len)
        pos = len;
    reserve(len + n);
    memmove(data + pos + n, data + pos, len - pos);
    for (int i = 0; i < n; i++)
    {
        data[pos + i] = c;
    }
    len += n;
    data[len] = '\0';
    return *this;
}

text &text::erase(size_t pos, size_t n)
{
    if (pos > len)
        pos = len;
    if (pos + n > len || n == static_cast<size_t>(-1))
        n = len - pos;
    memmove(data + pos, data + pos + n, len - pos - n);
    len -= n;
    data[len] = '\0';
    return *this;
}

text &text::replace(size_t pos, size_t n, const text &tex)
{
    erase(pos, n);
    insert(pos, tex);
    return *this;
}

void text::swap(text &tex)
{
    std::swap(data, tex.data);
    std::swap(len, tex.len);
    std::swap(cap, tex.cap);
}

void text::pop_back()
{
    if (len > 0)
    {
        len--;
        data[len] = '\0';
    }
}

// text + text
text operator+(const text &lhs, const text &rhs)
{
    text result(lhs);
    result.append(rhs);
    return result;
}

// text + C-string
text operator+(const text &lhs, const char *rhs)
{
    text result(lhs);
    result.append(rhs);
    return result;
}

// C-string + text
text operator+(const char *lhs, const text &rhs)
{
    text result(lhs);
    result.append(rhs);
    return result;
}

// text + char
text operator+(const text &lhs, char rhs)
{
    text result(lhs);
    result.push_back(rhs);
    return result;
}

// char + text
text operator+(char lhs, const text &rhs)
{
    text result(1, lhs);
    result.append(rhs);
    return result;
}

// == operator
bool operator==(const text &lhs, const text &rhs)
{
    return strcmp(lhs.data, rhs.data) == 0;
}
bool operator==(const char *lhs, const text &rhs)
{
    return strcmp(lhs, rhs.data) == 0;
}
bool operator==(const text &lhs, const char *rhs)
{
    return strcmp(lhs.data, rhs) == 0;
}

// != operator
bool operator!=(const text &lhs, const text &rhs)
{
    return !(lhs == rhs);
}
bool operator!=(const char *lhs, const text &rhs)
{
    return !(lhs == rhs);
}
bool operator!=(const text &lhs, const char *rhs)
{
    return !(lhs == rhs);
}

// < operator
bool operator<(const text &lhs, const text &rhs)
{
    return strcmp(lhs.data, rhs.data) < 0;
}
bool operator<(const char *lhs, const text &rhs)
{
    return strcmp(lhs, rhs.data) < 0;
}
bool operator<(const text &lhs, const char *rhs)
{
    return strcmp(lhs.data, rhs) < 0;
}

// <= operator
bool operator<=(const text &lhs, const text &rhs)
{
    return !(rhs < lhs);
}
bool operator<=(const char *lhs, const text &rhs)
{
    return !(rhs < lhs);
}
bool operator<=(const text &lhs, const char *rhs)
{
    return !(rhs < lhs);
}

// > operator
bool operator>(const text &lhs, const text &rhs)
{
    return rhs < lhs;
}
bool operator>(const char *lhs, const text &rhs)
{
    return rhs < lhs;
}
bool operator>(const text &lhs, const char *rhs)
{
    return rhs < lhs;
}

// >= operator
bool operator>=(const text &lhs, const text &rhs)
{
    return !(lhs < rhs);
}
bool operator>=(const char *lhs, const text &rhs)
{
    return !(lhs < rhs);
}
bool operator>=(const text &lhs, const char *rhs)
{
    return !(lhs < rhs);
}

void text::swap(text &x, text &y)
{
    std::swap(x.data, y.data);
    std::swap(x.len, y.len);
    std::swap(x.cap, y.cap);
}

istream &operator>>(istream &is, text &tex)
{
    tex.clear();
    char buffer[1024];
    is >> buffer;
    size_t n = strlen(buffer);
    tex.reserve(n);
    memmove(tex.data, buffer, n);
    tex.data[n] = '\0';
    tex.len = n;
    return is;
}

ostream &operator<<(ostream &os, const text &tex)
{
    os << tex.data;
    return os;
}

istream &text::getline(istream &is, text &tex, char delim)
{
    tex.clear();
    char ch;
    while (is.get(ch) && ch != delim)
    {
        tex.push_back(ch);
    }
    return is;
}

istream &text::getline(istream &is, text &tex)
{
    return getline(is, tex, '\n');
}

const char *text::c_str() const
{
    return data;
}

size_t text::copy(char *s, size_t len, size_t pos) const
{
    if (pos > len)
        throw out_of_range("Copy Out Of Range.");
    size_t rlen = (len < (this->len - pos)) ? len : (this->len - pos);
    memcpy(s, this->data + pos, rlen);
    return rlen;
}

// string find
size_t text::find(const text &tex, size_t pos) const
{
    return find(tex.data, pos, tex.len);
}

// c-string find
size_t text::find(const char *s, size_t pos) const
{
    return find(s, pos, strlen(s));
}

// buffer find
size_t text::find(const char *s, size_t pos, size_t n) const
{
    if (!s || pos > len)
        return text::npos;
    for (size_t i = pos; i + n <= this->len; i++)
    {
        bool match = true;

        for (size_t j = 0; j < n; j++)
        {
            if (this->data[i + j] != s[j])
            {
                match = false;
                break;
            }
        }
        if (match)
            return i;
    }
    return text::npos;
}

// char find
size_t text::find(char c, size_t pos) const
{
    for (size_t i = pos; i < this->len; i++)
    {
        if (c == this->data[i])
            return i;
    }
    return npos;
}

// rfind string
size_t text::rfind(const text &tex, size_t pos) const
{
    return rfind(tex.data, pos, tex.len);
}

// rfind c-string
size_t text::rfind(const char *s, size_t pos) const
{
    return rfind(s, pos, strlen(s));
}

// buffer rfind
size_t text::rfind(const char *s, size_t pos, size_t n) const
{
    if (len < n)
        return npos;

    size_t start = (pos < (len - n)) ? pos : (len - n);

    for (size_t i = start; i >= 0; i--)
    {
        bool match = true;
        for (size_t j = 0; j < n; j++)
        {
            if (this->data[i + j] != s[j])
            {
                match = false;
                break;
            }
        }
        if (match)
            return i;
    }
    return npos;
}

// rfind char
size_t text::rfind(char c, size_t pos) const
{
    if (len == 0)
        return npos;
    size_t i = (pos < len) ? pos : (len - 1);
    for (i; i >= 0; i--)
    {
        if (c == this->data[i])
        {
            return i;
        }
    }
    return npos;
}

// first_find_of string
size_t text::find_first_of(const text &tex, size_t pos) const
{
    return find_first_of(tex.data, pos, tex.len);
}

// first_find_of c-string
size_t text::find_first_of(const char *s, size_t pos) const
{
    return find_first_of(s, pos, strlen(s));
}

// first_find_of buffer
size_t text::find_first_of(const char *s, size_t pos, size_t n) const
{
    if (pos > len || n == 0)
        return npos;
    for (size_t i = pos; i < len; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (data[i] == s[j])
            {
                return i;
            }
        }
    }
    return npos;
}

// first_find_of char
size_t text::find_first_of(char c, size_t pos) const
{
    return find(c, pos);
}

// find_last_of string
size_t text::find_last_of(const text &tex, size_t pos) const
{
    return find_last_of(tex.data, pos, tex.len);
}

// find_last_of c-string
size_t text::find_last_of(const char *s, size_t pos) const
{
    return find_last_of(s, pos, strlen(s));
}

// find_last_of buffer
size_t text::find_last_of(const char *s, size_t pos, size_t n) const
{
    if (len == 0 || n == 0)
        return npos;
    size_t end = (pos < len) ? pos : (len - 1);
    for (size_t i = end; i >= 0; i--)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (data[i] == s[j])
                return i;
        }
    }
    return npos;
}

// find_last_of char
size_t text::find_last_of(char c, size_t pos) const
{
    return rfind(c, pos);
}

text text::substr(size_t pos , size_t n) const
{
    if (pos > len)
        throw out_of_range("substr pos out of range.");
    n = (n < (len - pos)) ? n : (len - pos);
    return text(data + pos, n);
}

// compare string
int text::compare(const text &tex) const
{
    size_t min_len = (len < tex.len) ? len : tex.len;

    for (size_t i = 0; i < min_len; i++)
    {
        if (data[i] < tex.data[i])
            return -1;
        if (data[i] > tex.data[i])
            return 1;
    }

    if (len < tex.len)
        return -1;
    if (len > tex.len)
        return 1;

    return 0;
}

// compare sub-string
int text::compare(size_t pos, size_t n, const text &tex) const
{
    return compare(pos, n, tex.data, tex.len);
}

// compare c-string
int text::compare(const char *s) const
{
    return compare(0, len, s, strlen(s));
}

// compare c-string
int text::compare(size_t pos, size_t n, const char *s) const
{
    return compare(pos, n, s, strlen(s));
}

// compare buffer
int text::compare(size_t pos, size_t len, const char *s, size_t n) const
{
    if (pos > this->len)
        throw out_of_range("Out Of Range.");
    if (len == npos || this->len < (len + pos))
        len = this->len - pos;
    size_t min_len = (len < n) ? len : n;
    for (size_t i = 0; i < min_len; i++)
    {
        if (data[pos + i] < s[i])
            return -1;
        if (data[pos + i] > s[i])
            return 1;
    }
    if (len < n)
        return -1;
    if (len > n)
        return 1;

    return 0;
}