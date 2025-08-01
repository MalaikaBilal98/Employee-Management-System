# Employee-Management-System
A C++ console-based Employee Management System that allows managers to manage employee records and employees to track their work hours. This project demonstrates **OOP concepts, file handling, and console-based authentication**.

# Features

# Manager Panel

* Add new employees
* View all employee records
* Search employees by ID
* Update employee details by ID
* Delete employee records by ID
* Save records to a CSV file

# Employee Panel

* Clock in/out with timestamps
* Calculate total hours worked
* View logout option for session end

# Authentication System

* **Manager Login:** Predefined usernames and passwords
* **Employee Login:** Auto-generated credentials (`employee1` to `employee40` with passwords `p1` to `p40`)
* **Login Attempts:** Maximum of 3 before access is denied

# Tech Stack

* Language: C++
* Paradigm: Object-Oriented Programming (OOP)
* STL Containers: `vector`, `map`
* File Handling: `fstream` for reading/writing CSV files
* Console I/O: `cin`, `cout` for user interaction

