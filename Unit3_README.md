# Campus Signal Issue Tracker Using Singly Linked List

## CCE-II Programming Assignment — Unit 3

### 1. Project Overview
The **Campus Signal Issue Tracker** is a menu-driven C++ console application designed to maintain records of mobile network signal problems reported at different locations on a college campus. It uses a **singly linked list** to store and manage issue records. The project demonstrates how a linked list can be used for a simple real-life record-management task.

This is an educational prototype. It records issues entered by the user; it does not measure actual mobile signal strength or automatically send complaints to network providers.

### 2. Problem Statement
Develop a menu-driven C++ application to record mobile network signal issues reported on a college campus. The application should allow the user to add, display, search, update, and delete issue records using a singly linked list. File handling should be used to preserve records between program runs.

### 3. Objectives
- Understand and implement a singly linked list in C++.
- Practise pointers and dynamic memory allocation.
- Add, view, search, update, and delete issue records.
- Save records to a text file and load them when the program starts.
- Build a simple menu-driven application for managing campus signal complaints.

### 4. Main Features
- **Add a new issue:** Enter the campus location, network provider, problem type, and description.
- **View all issues:** Display the saved issue records.
- **Search by issue ID:** Find a particular issue using its ID.
- **Update issue status:** Change the status of a reported issue.
- **Delete an issue:** Remove an issue record from the list.
- **File handling:** Store records in `issues.txt` so they can be loaded in a later run.
- **Memory management:** Dynamically create nodes and release allocated memory when it is no longer needed.

### 5. Data Structure Used: Singly Linked List
A singly linked list is a linear data structure made up of nodes. Each node stores the information for one issue and a pointer to the next node. The list begins at the `head` pointer, and the last node points to `nullptr`.

Each issue node stores the relevant issue details, such as:
- Issue ID
- Campus location
- Network provider
- Problem type
- Description
- Issue status
- Pointer to the next node

Unlike a fixed-size array, a linked list can grow or shrink dynamically as records are added or deleted.

### 6. Working Principle
1. When the program starts, it loads previously saved records from `issues.txt`, if available.
2. It displays a menu and asks the user to select an operation.
3. For adding an issue, the program creates a new node and links it into the list.
4. For viewing or searching, the program traverses the list from the head node.
5. For updating, it finds the requested issue and changes its status.
6. For deleting, it adjusts the links and releases the removed node's memory.
7. Changes are saved to `issues.txt` so that records can be reused in a future run.
8. When the user exits, the program releases the remaining dynamically allocated nodes.

### 7. Concepts Demonstrated
- Structures for grouping issue details
- Pointers and pointer-based traversal
- Singly linked list creation and manipulation
- Dynamic memory allocation using `new`
- Memory deallocation using `delete`
- Searching, updating, insertion, and deletion
- File input/output using C++ file streams
- Menu-driven program design

### 8. Software Requirements
- C++ compiler that supports C++11 or later, such as GCC/MinGW
- A code editor or IDE, such as Visual Studio Code, Code::Blocks, or an online C++ compiler
- Operating system that supports the selected C++ compiler

### 9. Compile and Run
If you have the GNU C++ compiler (`g++`), open a terminal in the folder containing `main.cpp` and run:

```bash
g++ -std=c++11 -Wall -Wextra main.cpp -o tracker
./tracker
```

On Windows with MinGW, use:

```bash
g++ -std=c++11 -Wall -Wextra main.cpp -o tracker.exe
tracker.exe
```

You can also copy `main.cpp` into an online C++ compiler, such as OnlineGDB, and run it there. File-saving behaviour depends on the online compiler's working directory and file permissions.

### 10. Project Files
- `main.cpp` — C++ source code for the application.
- `README.md` — Project overview, features, and instructions.
- `sample-output.txt` — Example console interaction and output.
- `issues.txt` — Created or updated by the program when it saves issue records; it may not be included in the repository until the program has been run and the file added.

### 11. Advantages
- Records can be added dynamically without choosing a fixed array size.
- Each issue can be identified using its ID.
- The menu makes the application straightforward to use.
- Multiple record-management operations are available in one program.
- File handling can preserve records between runs.
- The project provides practical experience with pointers and dynamic memory.

### 12. Limitations and Future Scope
**Limitations**
- The accuracy of records depends on the information entered by the user.
- The application does not measure real signal strength using hardware.
- It does not automatically contact mobile network providers.
- Searching requires traversal through the linked list.
- The text-file approach is intended for a small learning project, not simultaneous multi-user access.

**Future improvements**
- Add a graphical user interface and user login.
- Include date and time for each reported issue.
- Generate reports grouped by location, provider, or problem type.
- Use a database for managing a larger number of records.
- Explore approved hardware or APIs for actual signal measurements, if available.

### 13. Conclusion
The Campus Signal Issue Tracker demonstrates the use of a singly linked list in C++ to manage campus mobile-network issue records. It brings together node creation, pointer traversal, searching, updating, deletion, dynamic memory management, and file handling in one menu-driven application. The project is intended to help students understand data structures through a practical example.

### 14. References
- C++ class notes and learning material on pointers, structures, linked lists, and file handling.
- [cplusplus.com — C++ language reference and tutorials](https://cplusplus.com/)
- [cppreference.com — C++ language and standard library reference](https://en.cppreference.com/)
