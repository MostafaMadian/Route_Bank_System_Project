# Route Bank System

### C++ Banking System — Final Course Project

A console-based banking system built with C++ using Object-Oriented Programming, file handling, data validation, inheritance, polymorphism, and separation of responsibilities.

## 🚀 Live Demo

**[Try the Live Demo](./index.html)**

> The Live Demo is a browser-based representation of the main banking workflows.
> The original course project is implemented as a C++ console application.

---

## 📌 About the Project

Route Bank is a complete banking management system developed as a final course project.

The system supports three different user roles:

- **Admin**
- **Employee**
- **Client**

Each role has its own permissions and operations.

The project combines multiple C++ concepts into one complete application and demonstrates how these concepts can be used to build a structured real-world system.

---

## 👤 User Roles

### Client

Clients can:

- Login to their account
- Check their balance
- Deposit money
- Withdraw money
- Transfer money to another client
- Edit their password
- Display their account information

### Employee

Employees can:

- Login to their account
- Check their salary
- Add clients
- Search for clients
- List clients
- Edit client passwords
- Display their information

### Admin

Admins can:

- Login to the system
- Check their salary
- Add employees
- Search for employees
- List employees
- Edit employee passwords
- Edit employee salaries
- Display their information

---

## 🏗️ Project Architecture

The project is divided into multiple classes, with each class responsible for a specific part of the system.

### Core Classes

- `Person` — Base class for users
- `Client` — Represents bank clients
- `Employee` — Represents bank employees
- `Admin` — Represents administrators

### Management Classes

- `ClientManager`
- `EmployeeManager`
- `AdminManager`

These classes handle login, menus, searching, listing, and management operations.

### Data & File Handling

- `DataStorage`
- `FileManager`
- `FilesHelper`
- `Parser`
- `DataSourceInterface`

These components handle data storage, file operations, parsing, and data access.

### Supporting Classes

- `Validation`
- `FillData`
- `Screens`

These classes provide input validation, sample data generation, and console screen functionality.

---

## 🧠 C++ Concepts Demonstrated

This project demonstrates several important C++ concepts:

- Object-Oriented Programming
- Classes & Objects
- Encapsulation
- Inheritance
- Polymorphism
- Abstract Classes
- Composition
- Constructors
- Static Members
- Setters & Getters
- Function Overloading
- Templates
- Pointers
- References
- Dynamic Memory Allocation
- STL `vector`
- File Handling
- String Parsing
- Input Validation
- Separation of Responsibilities

---

## 🔐 Data Storage

The C++ application uses text files for persistent data storage.

Example data files:

```text
AdminData.txt
EmployeeData.txt
ClientData.txt
```

Separate files are also used to keep track of the last generated ID for each user type.

The application loads data from these files and updates them when changes are made.

---

## 📁 Project Structure

```text
Route_Bank
│
├── Route_Bank.sln
├── Project.txt
│
└── Route_Bank
    │
    ├── Admin.cpp
    ├── Admin.h
    ├── AdminManager.cpp
    ├── AdminManager.h
    │
    ├── Client.cpp
    ├── Client.h
    ├── ClientManager.cpp
    ├── ClientManager.h
    │
    ├── Employee.cpp
    ├── Employee.h
    ├── EmployeeManager.cpp
    ├── EmployeeManager.h
    │
    ├── Person.cpp
    ├── Person.h
    │
    ├── DataStorage.cpp
    ├── DataStorage.h
    ├── DataSourceInterface.cpp
    ├── DataSourceInterface.h
    │
    ├── FileManager.cpp
    ├── FileManager.h
    ├── FilesHelper.cpp
    ├── FilesHelper.h
    ├── Parser.cpp
    ├── Parser.h
    │
    ├── FillData.cpp
    ├── FillData.h
    ├── Validation.cpp
    ├── Validation.h
    ├── Screens.cpp
    ├── Screens.h
    │
    └── *.txt
```

---

## 🛠️ Technologies

- **C++**
- **Object-Oriented Programming**
- **STL**
- **File I/O**
- **Visual Studio**
- **Windows Console API**

---

## ▶️ How to Run the C++ Project

1. Clone or download this repository.
2. Navigate to the `C++-Source` folder.
3. Open:

```text
C++-Source/Route_Bank.sln
```

4. Open the solution using Visual Studio.
5. Build the solution.
6. Run the application.

> The original C++ project is designed as a Windows console application.

---

## 🌐 Live Demo vs. Original C++ Project

The **Live Demo** provides a browser-friendly representation of the main banking workflows.

The **C++ Source Code** contains the original console-based implementation developed as the course project.

The Live Demo allows students to explore the project without installing Visual Studio or a C++ compiler.

---

## 🎯 Course Project Goal

This project represents the type of complete application students can build after applying the concepts covered throughout the course.

It brings together:

```text
C++ Fundamentals
        ↓
Object-Oriented Programming
        ↓
Data Handling & File I/O
        ↓
Validation
        ↓
Application Architecture
        ↓
Complete Banking System
```

---

## 📚 Educational Purpose

This project is intended to demonstrate the practical application of C++ programming concepts in a complete software project.

Students can explore both:

- The **Live Demo** to understand the application's functionality.
- The **C++ Source Code** to study its implementation and architecture.

---

## 📄 License

This project is provided for educational purposes as part of the course.
