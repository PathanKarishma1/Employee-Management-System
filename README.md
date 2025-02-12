# Employee Management System (C - Hash Table & Linked List)

## 1. Project Overview

This is a **C-based Employee Management System** that efficiently stores and retrieves employee records using a **hash table with chaining (linked lists)**. The system allows users to:

- **Add new employees** with details like ID, name, date of birth (DOB), date of joining (DOJ), salary, designation, and department.
- **Search for an employee** by their unique ID.
- **Update employee details** (name, salary, department, etc.).
- **Delete an employee** from the system.
- **Retrieve all employees within a specific department**.
- **Display all employees** stored in the system.

---

## 2. Features

✅ **Efficient Employee Management** – Uses **hash table** for **fast lookup**.  
✅ **Chaining for Collision Resolution** – Uses **linked lists** for handling collisions in the hash table.  
✅ **Modular Code** – Functions are well-structured for better **readability & reusability**.  
✅ **Supports Updates & Deletions** – Modify employee details or remove them from the system.  
✅ **Department-Based Search** – Lists employees working in a given department.  

---

## 3. Data Structures Used

- **Hash Table** (Array of linked lists for efficient lookups).
- **Linked List** (Handles hash collisions through chaining).
- **Structs** for Employee and Hash Table Storage.

---

## 4. How It Works

### 1️⃣ Hashing & Storage

- Employees are stored in a **hash table** using the formula:
  ```c
  index = (Employee ID) % TABLE_SIZE;
  ```
- If a collision occurs (same index), employees are stored as a **linked list** at that index.

### 2️⃣ Operations

| **Function**           | **Description**                                                  |
| ---------------------- | ---------------------------------------------------------------- |
| `insert()`             | Adds a new employee to the hash table.                           |
| `search()`             | Finds an employee by ID.                                         |
| `updateEmployee()`     | Modifies an employee’s details (name, salary, department, etc.). |
| `deleteEmployee()`     | Removes an employee by ID.                                       |
| `searchByDepartment()` | Lists all employees in a given department.                       |
| `displayHashTable()`   | Prints all employee records.                                     |

---

## 5. Installation & Usage

### 📌 Prerequisites

- **C Compiler** (e.g., `gcc` for Linux/macOS or `MinGW` for Windows).
- **Terminal/Command Prompt** to run the program.

### 📥 Compilation

To compile the program:

```bash
gcc employee_management.c -o employee_management
```

### ▶️ Running the Program

After compiling, execute:

```bash
./employee_management
```

### 📌 Example Run

```
Menu:
1. Insert Employee
2. Search Employee
3. Update Employee
4. Delete Employee
5. Search by Department
6. Display All
0. Exit
Enter choice: 1

Enter ID: 101
Enter Name: Karishma
Enter Date of Birth (YYYY-MM-DD): 1995-12-23
Enter Date of Joining (YYYY-MM-DD): 2022-08-01
Enter Salary: 75000
Enter Designation: Software Engineer
Enter Department: IT
Employee inserted successfully!
```

---

## 6. File Structure

```
├── employee_management.c   # Main C source code
├── README.md               # Project documentation (this file)
```

---

## 7. Code Explanation

### Employee Struct

```c
struct Employee {
    int id;
    char name[50];
    char dob[12];
    char doj[12];
    float salary;
    char designation[50];
    char department[50];
    struct Employee *next;
};
```
- Stores **employee information**.
- `next` is a **pointer** for **chaining** in case of hash collisions.

### Hash Table

```c
#define TABLE_SIZE 10
struct Hashtable {
    struct Node *table[TABLE_SIZE];
};
```
- Uses an **array of linked lists** for storing employees.

### Hash Function

```c
int hashFunction(int key) {
    return key % TABLE_SIZE;
}
```
- **Distributes employees** across different table indexes.

### Insert, Search, Update, and Delete Operations

```c
void insert(struct Hashtable *ht, struct Employee emp);
struct Employee *search(struct Hashtable *ht, int id);
void updateEmployee(struct Hashtable *ht, int id);
void deleteEmployee(struct Hashtable *ht, int id);
```

- **Insert**: Adds a new employee at the hashed index.
- **Search**: Finds an employee by ID.
- **Update**: Modifies employee details.
- **Delete**: Removes an employee from the table.

### Display and Search by Department

```c
void displayHashTable(struct Hashtable *ht);
void searchByDepartment(struct Hashtable *ht, char *department);
```

- **Display**: Lists all employees.
- **Department Search**: Finds employees by department.

---

## Author

👤 **Karishma Pathan**  
📧 [pathan.karishma1910@gmail.com]  

---

