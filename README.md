# 📚 Library Management System (C++) 
A simple and modular Library Management System built using Object-Oriented Programming in C++.
This project demonstrates clean class design, separation of concerns, and basic data handling using STL containers.

It is designed as a learning-focused project to strengthen understanding of:

- OOP principles (Encapsulation, Abstraction, Modularity)

- Class relationships

- Header/source file separation

- STL (vector, algorithm)

- Build configuration using MSYS2 + g++

```
🏗 Project Structure
LIBRARY_MANAGEMENT/
│
├── include/              # Header files (class declarations)
│   ├── book.h
│   ├── member.h
│   ├── date.h
│   ├── record.h
│   └── library.h
│
├── src/                  # Source files (class definitions)
│   ├── book.cpp
│   ├── member.cpp
│   ├── date.cpp
│   ├── record.cpp
│   ├── library.cpp
│   └── main.cpp
│
└── main.exe              # Compiled executable
```
🧠 System Design

The system follows a clean object-oriented architecture:

1️⃣ Book

Represents a book in the library.
Contains book details and availability status.

2️⃣ Member

Represents a library member.
Stores identification and contact details.

3️⃣ Date

Handles date-related logic (borrow date and due date).

4️⃣ Record

Represents a borrowing record linking:

- A Member

- A Book

- Borrow Date

- Return Date

5️⃣ Library

Acts as the controller class:

- Stores collections of books, members, and records

- Handles operations like add/remove/search

- Manages borrowing and returning

⚙️ Features

- Add new books

- Remove books

- Add members

- Borrow books

- Return books

- Track borrowing records

- Organized modular class design

> [!NOTE]
> Make sure MSYS2 (UCRT64) is installed.

Compile:
g++ -g src/Book.cpp src/Member.cpp src/Date.cpp src/Record.cpp src/Library.cpp src/main.cpp -Iinclude -o main.exe

Run:
./main.exe

🧩 Technologies Used

- C++17

- STL (vector, algorithm)

- MSYS2 (UCRT64)

- g++

🎯 Learning Objectives

This project was built to:

Practice real-world class structuring

Understand header/source separation

Learn linking and compilation process

Improve debugging skills with gdb

Strengthen STL usage

🚀 Future Improvements

File persistence (save/load data)

Search functionality

Exception handling improvements

Input validation system

CLI menu interface

Database integration (advanced version)

👤 Author

Nizam Ud Din
> Follow on Likedin: [nizamuddinraqeeb](https://linkedin.com/in/nizamuddinraqeeb)

📜 License

This project is open for learning and educational purposes.
