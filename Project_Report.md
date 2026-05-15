# Hospital Management System - Project Report
**Egypt University of Informatics (EUI)**
**Phase 2 Final Submission**

## 1. Project Overview
The Hospital Management System is a comprehensive C++ console application designed to digitize and manage the operational workflows of a hospital. The system addresses the needs of three primary stakeholders: Administrators, Doctors, and Patients. By leveraging modern programming paradigms, the application facilitates the management of medical records, staff administration, and automated appointment scheduling. 

## 2. Application of Object-Oriented Programming (OOP)
To ensure the system is scalable, maintainable, and robust, we strictly adhered to the four pillars of Object-Oriented Programming:

### 2.1. Encapsulation
We utilized Encapsulation to protect the internal state of our objects. All class attributes (such as passwords, medical histories, and IDs) are declared as `private` or `protected`. They can only be accessed or modified through safe, public getter and setter methods. This ensures that sensitive hospital data cannot be manipulated directly from outside the class.

### 2.2. Abstraction
The system utilizes Abstraction through the creation of an abstract `User` base class. The `User` class acts as a generalized template for anyone accessing the system. It contains common attributes like ID, username, and password, but defines a pure virtual `login()` method (`virtual bool login() = 0;`). This prevents the instantiation of a generic "User" and forces derived classes to provide their specific login implementation.

### 2.3. Inheritance
Inheritance was employed to eliminate code redundancy and establish a clear hierarchical relationship. The `Admin`, `Doctor`, and `Patient` classes all inherit from the abstract `User` class. They acquire all base attributes and methods but introduce their own unique properties. For example, the `Doctor` class adds a vector of slots and specialization, while the `Patient` class includes medical history and an appointment pointer.

### 2.4. Polymorphism
Polymorphism is demonstrated through the overridden `login()` function. Even though `Admin`, `Doctor`, and `Patient` objects are all technically "Users", calling the `login()` function on them will execute different behaviors depending on their object type. This allows the system's main loop to handle authentication dynamically based on the user's role.

## 3. Bonus Features Implemented
To elevate the quality of our project, our team successfully implemented two advanced bonus features:

### 3.1. Data Persistence (File I/O)
To ensure the system is practical, data must survive beyond a single runtime session. We integrated File Handling using the `<fstream>` library. Upon launching the program, `loadData()` reads existing doctors and patients from `.txt` files into `std::vector` lists. When the user exits, `saveData()` writes all updated lists back to the files, ensuring no data loss occurs between sessions.

### 3.2. Advanced Search Functionality
We enhanced the Patient interface by implementing a dynamic search algorithm. Patients are not required to know a doctor's ID to book an appointment. Instead, they can query the system to search for doctors based on their specific *Medical Specialization* or filter doctors by a specific *Available Time Slot*.

## 4. System Stability and Exception Handling
To build a resilient application, we utilized robust Exception Handling techniques. In console applications, unexpected user input can easily cause infinite loops or fatal crashes. We implemented `try-catch` blocks throughout all UI menus. 
- `std::invalid_argument` is thrown and caught when a user inputs a wrong menu choice.
- `std::runtime_error` is used to handle login failures. 
- Input streams are automatically cleared and ignored if a user inputs a character instead of an integer, guaranteeing uninterrupted execution.

## 5. Conclusion
Through the development of this Hospital Management System, our team successfully translated theoretical OOP concepts into a functional, real-world application. The project meets all Phase 2 requirements, demonstrates clean coding practices, and incorporates extra features that significantly enhance its usability.
