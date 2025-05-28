# 📦 Custom C++ String Class — `text`

A lightweight and educational reimplementation of the C++ `std::string` class for learning purposes. Created from scratch using core C++ features only — no STL string backend involved.

---

## 🔧 Features

- Fully dynamic memory management (manual `new/delete`)
- Deep copy, move semantics, and initializer list support
- Substring, insert, erase, replace, and append operations
- Comparisons: `==`, `!=`, `<`, `>`, `<=`, `>=`
- Custom `at()`, `substr()`, `find()` functions
- Operator overloading: `+`, `+=`, `[]`, assignment
- Stream input/output (`cin`, `cout`)
- Safe bounds-checked methods with exception handling

---

## 📁 Project Structure

```
TextCloneProject/
├── include/         # Header files
│   └── text.h
├── src/             # Class implementation
│   └── text.cpp
├── tests/           # Example usage / demo
│   └── main.cpp
├── bin/             # Compiled binary output (auto-created)
├── Makefile         # To build and run
└── README.md        # This file
```

---
## 🚀 Getting Started


### 🔨 Build the Project

```bash
make         # Builds the project
make run     # Builds and runs demo
make clean   # Cleans build artifacts
```

### 📌 Sample Output

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

- Object-Oriented Programming (OOP)
- Rule of Five in C++
- Operator Overloading
- Manual memory management
- Exception safety
- Header/interface separation

---

## 💡 Why This Project?

This project is part of my second semester C++ journey at PUCIT, aimed at mastering core OOP, dynamic memory, and custom class design principles.

---

## 🧑‍💻 Author

**Mr. Zohaib** — [LinkedIn](www.linkedin.com/in/zohaibcodez) 

---

## 📜 License

This project is free to use under the [MIT License](LICENSE).
