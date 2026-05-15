================================================================================
                    HOSPITAL MANAGEMENT SYSTEM - USER MANUAL
================================================================================

Team Members:
1. Omar alfarouk - Team Lead
2. Mazen mohamed - Backend Developer
3. Abdullah khalid - UI & UML Designer
4. Khaled waleed - QA & Input Validation Tester
5. eyad mohamed - Documentation & Technical Writer

================================================================================
PROJECT DESCRIPTION
================================================================================

The Hospital Management System is a console-based application built in C++ to 
streamline the daily operations of a hospital. It is designed to efficiently 
manage medical records, billing procedures, and doctor-patient appointments. 
By utilizing Object-Oriented Programming (OOP) concepts, the system provides a 
robust and scalable solution for healthcare administration.

This project is divided into three main distinct interfaces: Admin, Doctor, and 
Patient. The Admin has full control over adding and removing staff and patients. 
Doctors can manage their availability by adding or removing time slots, while 
Patients can view these slots, search for doctors based on their specialization, 
and book or cancel appointments seamlessly.

Additionally, our system includes file handling capabilities to ensure data 
persistence, meaning that all registered users and appointments are saved 
locally and reloaded upon restarting the application. The system is fortified 
with strict input validation loops and manual checks to ensure data integrity 
and prevent crashes without relying on external exception libraries.

================================================================================
HOW TO RUN THE PROGRAM
================================================================================

1. Extract the project folder to your local machine.
2. Open your terminal or command prompt.
3. Navigate to the "SRC" directory inside the project folder:
   > cd "path/to/project hospital/SRC"
4. Compile the source code using the g++ compiler. You can compile all files 
   at once by running:
   > g++ *.cpp -o HospitalSystem
5. Run the generated executable file:
   - On Windows:
     > HospitalSystem.exe
   - On Mac/Linux:
     > ./HospitalSystem

Note: To access the Admin dashboard, use the default credentials:
Username: admin
Password: admin123
