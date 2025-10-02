# Mini Database Engine (C++)

This is a small project where I tried to build a **basic database engine in C++**.
The idea was to understand how a database actually works internally — things like creating tables, inserting records, storing data in files, and retrieving it later.

## Features

* Create and manage multiple tables
* Insert, view, update, and delete records (basic **CRUD operations**)
* Data is stored in files (CSV format) so it doesn’t get lost after closing the program
* Simple, menu-driven interface to try it out easily
* Can be extended further with new features like queries, sorting, etc.

## Tech Stack

* **Language:** C++ (C++11+)
* **Concepts I used:**

  * Object-Oriented Programming
  * File handling for persistent storage
  * STL containers like `vector` and `map`
  * String parsing and basic data structures

## Project Structure

```
Mini-Database-Engine/
│-- main.cpp         # main source file
│-- database.txt     # sample saved data
│-- README.md        # project documentation
```

---

## How to Run

1. Clone this repo:

   ```bash
   git clone https://github.com/<your-username>/Mini-Database-Engine.git
   cd Mini-Database-Engine
   ```
2. Compile the code:

   ```bash
   g++ main.cpp -o miniDB
   ```
3. Run it:

   ```bash
   ./miniDB
   ```

---

## Example

```
===== Mini Database Engine =====
1. Create Table
2. Insert Record
3. Display Records
4. Update Record
5. Delete Record
6. Exit
Enter your choice:
```

---

## Why I Built This

I wanted to go a bit beyond normal console projects and try something close to a **real-world system**.
This helped me strengthen my concepts of **OOP, data handling, and persistence in C++**, and gave me a rough idea of how SQL-like systems might be implemented internally.

---

## Possible Improvements

* Add query support (like `SELECT WHERE ...`)
* Indexing for faster search
* Sorting records
* Export/import to JSON or SQLite

---

## Author

Made with curiosity by **Ayushman Soni**
