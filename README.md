# Campus Signal Issue Tracker Using Singly Linked List

### Problem Statement
Develop a menu-driven C++ application to record mobile network signal issues reported in a college campus. Each complaint stores an issue ID, campus location, network provider, problem type, description, and status. Use a singly linked list to add, display, search, update, and delete issues. Use file handling to preserve records between program runs.

### Objectives
- Apply pointers and dynamic memory allocation.
- Implement a singly linked list using a node structure.
- Perform insertion, traversal, searching, deletion, and updating.
- Save and reload issues using a text file.

### Unit III Concepts Demonstrated
- Pointer declaration and initialization: `Issue* head = nullptr`.
- Dynamic memory allocation and deallocation: `new Issue` and `delete`.
- Singly linked list: each node contains issue data and `Issue* next`.
- Linked-list traversal: move through nodes using `current = current->next`.
- Linked list as an ADT: operations are provided through functions.
- File handling: `ifstream` loads saved records and `ofstream` saves them.
- Memory cleanup: `freeList()` deletes each dynamically allocated node.

### Node Structure
Each node stores:
- `id`: unique issue number
- `location`: campus location
- `networkProvider`: mobile network provider
- `problemType`: type of signal issue
- `description`: additional details
- `status`: Pending, In Progress, or Resolved
- `next`: pointer to the next node

### Algorithm
1. Start the program and call `loadIssues()` to reconstruct the linked list from `issues.txt`.
2. Display the menu.
3. Read the user's choice.
4. For Add: create a node using `new`, assign the next ID, link it at the end, and save the list.
5. For Display: traverse from `head` until `nullptr` and print each node.
6. For Search: traverse the list and compare each node's ID with the requested ID.
7. For Update: find the node by ID, update its status, and save the list.
8. For Delete: locate the node, adjust the previous node's `next` pointer (or update `head`), delete the node, and save.
9. Repeat until Exit is selected.
10. Call `freeList()` to release all remaining nodes, then stop.

### Compile and Run
With g++:
```bash
g++ -std=c++11 -Wall -Wextra main.cpp -o tracker
./tracker
```
On Windows with MinGW:
```bash
g++ -std=c++11 -Wall -Wextra main.cpp -o tracker.exe
tracker.exe
```

The program reads/writes `issues.txt` in the current working directory. Keep it in the same directory when you want to reuse saved reports.

### Sample Input
```text
1
College Library
Jio
Weak Signal
Calls disconnect near reading area
2
6
```

### Illustrative Sample Output
```text
Welcome to Campus Signal Issue Tracker!
Saved issues loaded successfully.

===== CAMPUS SIGNAL ISSUE TRACKER =====
1. Report New Issue
2. View All Issues
3. Search Issue by ID
4. Update Issue Status
5. Delete Issue
6. Exit
Enter your choice: 1

--- Report a New Signal Issue ---
Enter campus location: College Library
Enter network provider (Jio/Airtel/Vi/Other): Jio
Enter problem type (Weak Signal/Call Drop/No Internet/Other): Weak Signal
Enter short description: Calls disconnect near reading area

Issue reported successfully. Issue ID: 1
Status: Pending

===== CAMPUS SIGNAL ISSUE TRACKER =====
1. Report New Issue
2. View All Issues
3. Search Issue by ID
4. Update Issue Status
5. Delete Issue
6. Exit
Enter your choice: 2

--- All Reported Issues ---

Issue ID: 1
Location: College Library
Network Provider: Jio
Problem Type: Weak Signal
Description: Calls disconnect near reading area
Status: Pending
------------------------------

Enter your choice: 6
Thank you for using the tracker.
```
Note: the full menu is printed before every choice; the sample above omits some repeated menu lines for readability.

### File Format
Each line in `issues.txt` contains:
`ID|Location|Provider|Problem Type|Description|Status`

Example:
```text
1|College Library|Jio|Weak Signal|Calls disconnect near reading area|Pending
```

### Functions
- `createNode()`: dynamically allocates and initializes a node.
- `loadIssues()`: reads file records and rebuilds the linked list.
- `saveIssues()`: traverses the list and saves all records.
- `addIssue()`: inserts a new issue at the end.
- `displayAll()`: traverses and displays every node.
- `searchById()`: returns the node matching an ID, or `nullptr`.
- `updateStatus()`: changes the status of an existing issue.
- `deleteIssue()`: unlinks and deletes the selected node.
- `freeList()`: frees all nodes before program exit.

### Test Cases
| Test | Action | Expected result |
|---|---|---|
| 1 | Start without an existing data file; select Display | Message that no issues are recorded |
| 2 | Add a complaint | New node added with a unique ID and Pending status |
| 3 | Display all | Every node is displayed |
| 4 | Search for an existing ID | Matching issue is displayed |
| 5 | Search for a missing ID | “No issue found” message |
| 6 | Update status to Resolved | Updated status is displayed and saved |
| 7 | Delete an existing issue | Node is removed from list and file |
| 8 | Exit and run again | Remaining saved issues are reloaded |
| 9 | Enter invalid menu input | Error message appears without crashing |

### Time Complexity
Let `n` be the number of issue nodes.
- Add at end: `O(n)` because the list is traversed to find the last node.
- Display all: `O(n)`.
- Search by ID: `O(n)`.
- Update by ID: `O(n)` to locate the node.
- Delete by ID: `O(n)` to locate the node.
- Extra memory for a new node: `O(1)` per issue.

### Limitations
- This is a local console-based tracker, not an automatic signal-strength measurement tool.
- It does not automatically submit complaints to mobile network providers.
- Records are stored in a local text file and are not shared between different computers.
- The file uses a simple delimiter-separated format, not a database.

### Future Scope
- Store date and time for each report.
- Filter issues by location, provider, or status.
- Export reports to CSV.
- Add a GUI, database, or shared web/mobile interface.
- Add authentication and roles for students and administrators.

### Conclusion
This project applies singly linked lists, pointers, dynamic memory allocation, traversal, searching, insertion, deletion, and file handling to a practical campus complaint-tracking scenario.
