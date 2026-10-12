#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
using namespace std;

const string DATA_FILE = "issues.txt";

struct Issue {
    int id;
    string location;
    string networkProvider;
    string problemType;
    string description;
    string status;
    Issue* next;
};

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string cleanField(string value) {
    for (char &ch : value) {
        if (ch == '|') ch = '/';
    }
    return value;
}

Issue* createNode(int id, const string& location, const string& provider,
                  const string& problem, const string& description,
                  const string& status) {
    Issue* node = new Issue;
    node->id = id;
    node->location = location;
    node->networkProvider = provider;
    node->problemType = problem;
    node->description = description;
    node->status = status;
    node->next = nullptr;
    return node;
}

int findHighestId(Issue* head) {
    int highest = 0;
    for (Issue* current = head; current != nullptr; current = current->next) {
        if (current->id > highest) highest = current->id;
    }
    return highest;
}

bool saveIssues(Issue* head) {
    ofstream file(DATA_FILE.c_str());
    if (!file) {
        cout << "Error: Could not open issues.txt for saving.\n";
        return false;
    }

    for (Issue* current = head; current != nullptr; current = current->next) {
        file << current->id << '|'
             << cleanField(current->location) << '|'
             << cleanField(current->networkProvider) << '|'
             << cleanField(current->problemType) << '|'
             << cleanField(current->description) << '|'
             << cleanField(current->status) << '\n';
    }
    return true;
}

Issue* loadIssues() {
    ifstream file(DATA_FILE.c_str());
    Issue* head = nullptr;
    Issue* tail = nullptr;
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string idText, location, provider, problem, description, status;

        if (!getline(ss, idText, '|')) continue;
        if (!getline(ss, location, '|')) continue;
        if (!getline(ss, provider, '|')) continue;
        if (!getline(ss, problem, '|')) continue;
        if (!getline(ss, description, '|')) continue;
        if (!getline(ss, status)) continue;

        int id;
        try {
            id = stoi(idText);
        } catch (...) {
            continue;
        }

        Issue* node = createNode(id, location, provider, problem, description, status);
        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

void addIssue(Issue*& head) {
    int id = findHighestId(head) + 1;
    string location, provider, problem, description;

    cout << "\n--- Report a New Signal Issue ---\n";
    cout << "Enter campus location: ";
    getline(cin >> ws, location);
    cout << "Enter network provider (Jio/Airtel/Vi/Other): ";
    getline(cin, provider);
    cout << "Enter problem type (Weak Signal/Call Drop/No Internet/Other): ";
    getline(cin, problem);
    cout << "Enter short description: ";
    getline(cin, description);

    Issue* node = createNode(id, cleanField(location), cleanField(provider),
                             cleanField(problem), cleanField(description), "Pending");

    if (head == nullptr) {
        head = node;
    } else {
        Issue* current = head;
        while (current->next != nullptr) current = current->next;
        current->next = node;
    }

    if (saveIssues(head)) {
        cout << "\nIssue reported successfully. Issue ID: " << id
             << "\nStatus: Pending\n";
    }
}

void displayOne(const Issue* item) {
    cout << "\nIssue ID: " << item->id << '\n'
         << "Location: " << item->location << '\n'
         << "Network Provider: " << item->networkProvider << '\n'
         << "Problem Type: " << item->problemType << '\n'
         << "Description: " << item->description << '\n'
         << "Status: " << item->status << '\n'
         << "------------------------------\n";
}

void displayAll(Issue* head) {
    if (head == nullptr) {
        cout << "\nNo issues have been reported yet.\n";
        return;
    }

    cout << "\n--- All Reported Issues ---\n";
    for (Issue* current = head; current != nullptr; current = current->next) {
        displayOne(current);
    }
}

Issue* searchById(Issue* head, int targetId) {
    Issue* current = head;
    while (current != nullptr) {
        if (current->id == targetId) return current;
        current = current->next;
    }
    return nullptr;
}

void searchIssue(Issue* head) {
    int id;
    cout << "Enter Issue ID to search: ";
    if (!(cin >> id)) {
        cout << "Invalid input. Enter a numeric ID.\n";
        clearInput();
        return;
    }
    clearInput();

    Issue* found = searchById(head, id);
    if (found != nullptr) displayOne(found);
    else cout << "No issue found with ID " << id << ".\n";
}

void updateStatus(Issue* head) {
    int id, choice;
    cout << "Enter Issue ID to update: ";
    if (!(cin >> id)) {
        cout << "Invalid input. Enter a numeric ID.\n";
        clearInput();
        return;
    }

    Issue* found = searchById(head, id);
    if (found == nullptr) {
        clearInput();
        cout << "No issue found with ID " << id << ".\n";
        return;
    }

    cout << "Current status: " << found->status << '\n';
    cout << "1. Pending\n2. In Progress\n3. Resolved\n";
    cout << "Choose new status: ";
    if (!(cin >> choice)) {
        cout << "Invalid input.\n";
        clearInput();
        return;
    }
    clearInput();

    if (choice == 1) found->status = "Pending";
    else if (choice == 2) found->status = "In Progress";
    else if (choice == 3) found->status = "Resolved";
    else {
        cout << "Invalid status choice. No change made.\n";
        return;
    }

    if (saveIssues(head)) cout << "Status updated to: " << found->status << '\n';
}

void deleteIssue(Issue*& head) {
    int id;
    cout << "Enter Issue ID to delete: ";
    if (!(cin >> id)) {
        cout << "Invalid input. Enter a numeric ID.\n";
        clearInput();
        return;
    }
    clearInput();

    Issue* current = head;
    Issue* previous = nullptr;

    while (current != nullptr && current->id != id) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "No issue found with ID " << id << ".\n";
        return;
    }

    if (previous == nullptr) head = current->next;
    else previous->next = current->next;

    delete current;
    if (saveIssues(head)) cout << "Issue deleted successfully.\n";
}

void showMenu() {
    cout << "\n===== CAMPUS SIGNAL ISSUE TRACKER =====\n"
         << "1. Report New Issue\n"
         << "2. View All Issues\n"
         << "3. Search Issue by ID\n"
         << "4. Update Issue Status\n"
         << "5. Delete Issue\n"
         << "6. Exit\n"
         << "Enter your choice: ";
}

void freeList(Issue*& head) {
    while (head != nullptr) {
        Issue* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Issue* head = loadIssues();
    int choice;

    cout << "Welcome to Campus Signal Issue Tracker!\n";
    cout << "Saved issues loaded successfully.\n";

    do {
        showMenu();
        if (!(cin >> choice)) {
            cout << "Invalid input. Enter a number from 1 to 6.\n";
            clearInput();
            continue;
        }
        clearInput();

        switch (choice) {
            case 1: addIssue(head); break;
            case 2: displayAll(head); break;
            case 3: searchIssue(head); break;
            case 4: updateStatus(head); break;
            case 5: deleteIssue(head); break;
            case 6: cout << "Thank you for using the tracker.\n"; break;
            default: cout << "Invalid choice. Select 1 to 6.\n";
        }
    } while (choice != 6);

    freeList(head);
    return 0;
}
