#include <iostream>
#include <fstream>
#include <vector>
#include<map>
#include <algorithm>
using namespace std;
class Employee
{
private:
  string name;
  int age;
  string position;
  int id;
  string department;
  double salary;
  string joiningDate;

public:
    Employee (string name, int age, string position, int id,
     string department, double salary,
     string joiningDate):name (name), age (age), position (position),
    id (id), department (department), salary (salary),
    joiningDate (joiningDate)
  {
  }

  string getName () const
  {
    return name;
  }

  int getAge () const
  {
    return age;
  }

  string getPosition () const
  {
    return position;
  }

  int getId () const
  {
    return id;
  }

  string getDepartment () const
  {
    return department;
  }

  double getSalary () const
  {
    return salary;
  }

  string getJoiningDate () const
  {
    return joiningDate;
  }

  void display () const
  {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Position: " << position << endl;
    cout << "ID: " << id << endl;
    cout << "Department: " << department << endl;
    cout << "Salary: " << salary << endl;
    cout << "Joining Date: " << joiningDate << endl;
  }
};

class EmployeeManagementSystem
{
private:
  vector < Employee > employees;

public:
  void addEmployee (const Employee & employee)
  {
    employees.push_back (employee);
  }

  void displayAllEmployees () const
  {
    if (employees.empty ())
      {
cout << "No employees in the system." << endl;
return;
      }

    cout << "Employee Records:" << endl;
  for (const auto & employee:employees)
      {
employee.display ();
cout << endl;
      }
  }

  void saveRecordsToFile (const string & filename) const
  {
    if (employees.empty ())
      {
cout << "No employees in the system to save." << endl;
return;
      }

    ofstream outfile (filename);
    if (outfile.is_open ())
      {
      for (const auto & employee:employees)
 {
   outfile << employee.
     getName () << ',' << employee.getAge () << ',' << employee.
     getPosition () << ',' << employee.getId () << ',' << employee.
     getDepartment () << ',' << employee.getSalary () << ',' <<
     employee.getJoiningDate () << '\n';
 }
cout << "Employee records saved to file successfully." << endl;
      }
    else
      {
cout << "Failed to open file for writing." << endl;
      }
  }

  void updateEmployeeById (int id)
  {
    bool found = false;

  for (auto & employee:employees)
      {
if (employee.getId () == id)
 {
   // Employee found, update the record
   string name, position, department, joiningDate;
   int age;
   double salary;

   cout << "Enter updated details for Employee with ID " << id <<
     endl;

   cout << "Enter Employee Name: ";
   cin.ignore ();
   getline (cin, name);

   cout << "Enter Employee Age: ";
   cin >> age;

   cout << "Enter Employee Position: ";
   cin.ignore ();
   getline (cin, position);

   cout << "Enter Employee Department: ";
   getline (cin, department);

   cout << "Enter Employee Salary: ";
   cin >> salary;

   cout << "Enter Employee Joining Date: ";
   cin.ignore ();
   getline (cin, joiningDate);

   // Update the employee's record
   employee =
     Employee (name, age, position, id, department, salary,
joiningDate);

   cout << "Employee record updated successfully." << endl;

   found = true;
   break;
 }
      }

    if (!found)
      {
cout << "Employee with ID " << id << " not found." << endl;
      }
  }
  void searchEmployeeById () const
  {
    int id;
      cout << "Enter the Employee ID to search for: ";
      cin >> id;

    bool found = false;

    for (const auto & employee:employees)
      {
if (employee.getId () == id)
 {
   // Employee found, display the record
   cout << "Employee Record for ID " << id << ":" << endl;
   employee.display ();
   found = true;
   break;
 }
      }

    if (!found)
      {
cout << "Employee with ID " << id << " not found." << endl;
      }
  }
  void removeEmployeeById (int id)
  {
    bool found = false;

    for (auto it = employees.begin (); it != employees.end (); ++it)
      {
if (it->getId () == id)
 {
   employees.erase (it);
   cout << "Employee with ID " << id << " removed successfully." <<
     endl;
   found = true;
   break;
 }
      }

    if (!found)
      {
cout << "Employee with ID " << id << " not found." << endl;
      }
  }

};

bool
authenticateManager (const string & username, const string & password)
{
  // Check if the username and password match any manager credentials
  vector < string > managerUsernames =
  {
  "manager1", "manager2", "manager3"};
  vector < string > managerPasswords =
  {
  "password1", "password2", "password3"};

  for (size_t i = 0; i < managerUsernames.size (); ++i)
    {
      if (username == managerUsernames[i] && password == managerPasswords[i])
{
 return true;
}
    }
  return false;
}

bool
authenticateEmployee (const string & username, const string & password)
{
  // Check if the username and password match any employee credentials

  for (int i = 1; i <= 40; i++)
    {
      string employeeUsername = "employee" + to_string (i);
      string employeePassword = "p" + to_string (i);

      if (username == employeeUsername && password == employeePassword)
{
 return true;
}
    }
  return false;
}



void
logout ()
{
  cout << "Logout successful. Goodbye" << endl;
}

void
exitSystem ()
{
  cout << "Exiting the Employee Management System. Goodbye!" << endl;
}

map < string, vector < pair < string, string >>> employee_records;
void
clock_in_out ()
{
  string employee_id, sign_in_time, sign_out_time;
  cout << "Enter your employee ID: ";
  cin >> employee_id;

  cout << "Enter your sign-in time (HH:MM): ";
  cin >> sign_in_time;

  cout << "Enter your sign-out time (HH:MM): ";
  cin >> sign_out_time;

  employee_records[employee_id].push_back (
   {
   sign_in_time, sign_out_time});
}

void
calculate_hours_worked ()
{
  string employee_id;
  cout << "Enter your employee ID: ";
  cin >> employee_id;

  if (employee_records.find (employee_id) == employee_records.end ())
    {
      cout << "No record found for employee ID: " << employee_id << endl;
      return;
    }

  int total_minutes_worked = 0;

for (auto record:employee_records[employee_id])
    {
      int sign_in_hour = stoi (record.first.substr (0, 2));
      int sign_in_minute = stoi (record.first.substr (3, 2));

      int sign_out_hour = stoi (record.second.substr (0, 2));
      int sign_out_minute = stoi (record.second.substr (3, 2));

      int minutes_worked =
(sign_out_hour - sign_in_hour) * 60 + (sign_out_minute -
      sign_in_minute);

      total_minutes_worked += minutes_worked;
    }

  int hours = total_minutes_worked / 60;
  int minutes = total_minutes_worked % 60;
  cout << "Total hours worked: " << hours << " hours and " << minutes <<
    " minutes" << endl;
}

void
employeeManagementSystem ()
{
  EmployeeManagementSystem ems;
      // Manager or employee successfully logged in
      int choice;
      bool loggedIn = true;
      while (loggedIn)
{
 cout << "Employee Management System" << endl;
 cout << "1. Add Employee" << endl;
 cout << "2. Display All Employees" << endl;
 cout << "3. Save Records to File" << endl;
 cout << "4. Search Employee by ID" << endl;
 cout << "5. Update Employee Record by ID" << endl;
 cout << "6. Remove Employee Record by ID" << endl;
 cout << "7. Logout" << endl;
 cout << "Enter your choice: ";
 cin >> choice;
 switch (choice)
   {
   case 1:
     {
// Add Employee
string name, position, department, joiningDate;
int age, id;
double salary;

cout << "Enter Employee Name: ";
cin.ignore ();
getline (cin, name);
cout << "Enter Employee Age: ";
cin >> age;
cout << "Enter Employee Position: ";
cin.ignore ();
getline (cin, position);
cout << "Enter Employee ID: ";
cin >> id;
cout << "Enter Employee Department: ";
cin.ignore ();
getline (cin, department);
cout << "Enter Employee Salary: ";
cin >> salary;
cout << "Enter Employee Joining Date: ";
cin.ignore ();
getline (cin, joiningDate);

Employee employee (name, age, position, id, department,
  salary, joiningDate);
ems.addEmployee (employee);
cout << "Employee added successfully." << endl;
break;
     }
   case 2:
     // Display All Employees
     ems.displayAllEmployees ();
     break;
   case 3:
     {
// Save Records to File
string filename;
cout << "Enter the filename to save the records: ";
cin.ignore ();
getline (cin, filename);
ems.saveRecordsToFile (filename);
break;
     }
   case 4:
     // Search Employee by ID
     ems.searchEmployeeById ();
     break;
   case 5:
     {
// Update Employee Record by ID
int employeeId;
cout << "Enter the Employee ID to update the record: ";
cin >> employeeId;
ems.updateEmployeeById (employeeId);
// Find the employee with the given ID and update their record
// Add implementation here
break;
     }
   case 6:
     {
// Remove Employee Record by ID
int employeeId;
cout << "Enter the Employee ID to remove the record: ";
cin >> employeeId;
ems.removeEmployeeById (employeeId);
break;
     }
   case 7:
     // Logout
     logout ();
     loggedIn = false;
     break;
   default:
     cout << "Invalid choice. Please try again." << endl;
   }
   
}
   
}
 
 
void employeedata()
{
     int choice;
      bool loggedIn = true;
   while (loggedIn) {
        cout << "Enter your choice:" << endl;
        cout << "1. Clock in/out" << endl;
        cout << "2. Calculate hours worked" << endl;
        cout << "3. Logout" << endl;
        cout << ">> ";
        cin >> choice;

        switch (choice) {
        case 1:
            clock_in_out();
            break;
        case 2:
            calculate_hours_worked();
            break;
        case 3:
            cout << "Logout successfully!!" << endl;
            logout ();
            loggedIn = false;
     break;
           
        default:
            cout << "Invalid choice" << endl;
            break;
        }

        cout << endl;
   }
   
}
   

bool
login ()
{
  int userType;
  cout << "Select user type:" << endl;
  cout << "1. Manager" << endl;
  cout << "2. Employee" << endl;
  cout << "Enter your choice: ";
  cin >> userType;

  if (userType == 1)
    {
      int loginAttempts = 0;

      while (loginAttempts < 3)
{
 string username, password;
 cout << "Manager Login" << endl;
 cout << "Username: ";
 cin >> username;
 cout << "Password: ";
 cin >> password;

 if (authenticateManager (username, password))
   {
     cout << "Login successful. Welcome, manager!" << endl;
     employeeManagementSystem();
     return true;
   }
 else
   {
     cout << "Invalid username or password. Please try again." <<
endl;
     loginAttempts++;
   }
}

      cout << "Maximum login attempts reached. Access denied." << endl;
      return false;
    }
  else if (userType == 2)
    {
      cout << "Welcome, employee!" << endl;
      int loginAttempts = 0;
      while (loginAttempts < 3)
{
 string username, password;
 cout << "Employee Login" << endl;
 cout << "Username: ";
 cin >> username;
 cout << "Password: ";
 cin >> password;

 if (authenticateEmployee (username, password))
   {
     cout << "Login successful. Welcome, employee!" << endl;
     employeedata();
     return true;
   }
 else
   {
     cout << "Invalid username or password. Please try again." <<
endl;
     loginAttempts++;
   }
}

      cout << "Maximum login attempts reached. Access denied." << endl;
      return false;
    }

  else
    {
      cout << "Invalid user type. Exiting the program." << endl;
      return false;
    }
}

int
main ()
{
  bool loggedIn = false;
  while (true)
    {
      cout << "Employee Management System" << endl;
      cout << "1. Login" << endl;
      cout << "2. Exit" << endl;
      cout << "Enter your choice: ";
      int choice;
      cin >> choice;
      if (choice == 1)
{
 login();
}
      else if (choice == 2)
{
 exitSystem ();
 break;
}
      else
{
 cout << "Invalid choice. Please try again." << endl;
}
    }

  return 0;
}
