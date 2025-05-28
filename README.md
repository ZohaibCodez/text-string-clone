
# 📦 Custom C++ String Class — `text`

A lightweight and educational reimplementation of the C++ `std::string` class for learning purposes. Built from scratch using only core C++ features — no STL string backend.

---

## 📚 Table of Contents

- [Features](#features)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Sample Output](#sample-output)
- [Skills Demonstrated](#skills-demonstrated)
- [Why This Project?](#why-this-project)
- [Author](#author)
- [License](#license)

---

## 🔧 Features

- Manual dynamic memory management (`new`/`delete`)
- Deep copy and move semantics (Rule of Five)
- Initializer list support
- Substring, insert, erase, replace, and append
- Comparison operators: `==`, `!=`, `<`, `>`, `<=`, `>=`
- Safe `at()`, `find()`, and `substr()` methods
- Operator overloading: `+`, `+=`, `[]`, `=`
- Stream I/O with `cin` and `cout`
- Exception-safe operations

---

## 📁 Project Structure

```

TextCloneProject/
├── include/         # Header files
│   └── text.h
├── src/             # Class implementation
│   └── text.cpp
├── tests/           # Usage examples
│   └── main.cpp
├── bin/             # Output binaries
├── Makefile         # For build automation
└── README.md        # You're reading it!
```
---

## 🚀 Getting Started

### 🔨 Build the Project

```bash
make         # Builds the project
make run     # Runs the demo
make clean   # Cleans build files
````

### 🧪 Example Usage

```cpp
#include "text.h"

int main() {
    text t1 = "Hello";
    text t2 = "World";
    text t3 = t1 + " " + t2;
    std::cout << "t3: " << t3 << std::endl;
}
```

---

## 📌 Sample Output

```
t1: Hello
t2:  World
t3 (t1 + t2): Hello World
Length of t3: 11
Capacity of t3: 12
...
```

---

## 📚 Skills Demonstrated

* Object-Oriented Programming (OOP)
* Rule of Five in C++
* Operator Overloading
* Exception handling
* Manual Memory Management
* Header and Source File Separation

---

## 💡 Why This Project?

This project is part of my second-semester coursework at PUCIT, developed to master advanced C++ concepts like dynamic memory, object lifecycles, and class design without relying on the Standard Library string class.

---

## 🧑‍💻 Author

**Mr. Zohaib**
🔗 [LinkedIn](https://www.linkedin.com/in/zohaibcodez)

---

## 📜 License

This project is licensed under the [MIT License](LICENSE).

