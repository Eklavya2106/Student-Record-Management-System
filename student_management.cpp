#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
private:
    string name, roll_no, course, address;

public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void del();
};

void Student::menu() {
    int choice;
    while (true) {
        cout << "\n\t--- STUDENT MANAGEMENT SYSTEM ---\n";
        cout << "1. Add Record\n2. Display All\n3. Modify\n4. Search\n5. Delete\n6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 6) break;

        switch (choice) {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: modify(); break;
            case 4: search(); break;
            case 5: del(); break;
            default: cout << "Invalid choice!\n";
        }
    }
}

void Student::insert() {
    cin.ignore();
    cout << "Name: "; getline(cin, name);
    cout << "Roll No: "; getline(cin, roll_no);
    cout << "Course: "; getline(cin, course);
    cout << "Address: "; getline(cin, address);

    ofstream file("studentRecord.txt", ios::app);
    file << name << "|" << roll_no << "|" << course << "|" << address << "\n";
    file.close();
    cout << "Record Saved!\n";
}

void Student::display() {
    ifstream file("studentRecord.txt");
    if (!file) { cout << "No data found!\n"; return; }

    cout << "\n--- All Students ---\n";
    while (getline(file, name, '|') && 
           getline(file, roll_no, '|') && 
           getline(file, course, '|') && 
           getline(file, address)) { 
        cout << "Roll: " << roll_no << " | Name: " << name << " | Course: " << course << endl;
    }
    file.close();
}

void Student::search() {
    string target;
    cout << "Enter Roll No to search: ";
    cin >> target;

    ifstream file("studentRecord.txt");
    bool found = false;

    while (getline(file, name, '|') && getline(file, roll_no, '|') && 
           getline(file, course, '|') && getline(file, address)) {
        if (roll_no == target) {
            cout << "Found! Name: " << name << ", Course: " << course << endl;
            found = true;
            break;
        }
    }
    file.close();
    if (!found) cout << "Student not found.\n";
}

void Student::del() {
    string target;
    cout << "Enter Roll No to delete: ";
    cin >> target;

    ifstream file("studentRecord.txt");
    ofstream temp("temp.txt");

    while (getline(file, name, '|') && getline(file, roll_no, '|') && 
           getline(file, course, '|') && getline(file, address)) {
        if (roll_no != target) {
            temp << name << "|" << roll_no << "|" << course << "|" << address << "\n";
        }
    }

    file.close();
    temp.close();
    remove("studentRecord.txt");
    rename("temp.txt", "studentRecord.txt");
    cout << "Process completed.\n";
}

void Student::modify() {
    string target;
    cout << "Enter Roll No to modify: ";
    cin >> target;

    ifstream file("studentRecord.txt");
    ofstream temp("temp.txt");
    bool found = false;

    while (getline(file, name, '|') && getline(file, roll_no, '|') && 
           getline(file, course, '|') && getline(file, address)) {
        if (roll_no == target) {
            cin.ignore();
            cout << "New Name: "; getline(cin, name);
            cout << "New Course: "; getline(cin, course);
            cout << "New Address: "; getline(cin, address);
            temp << name << "|" << roll_no << "|" << course << "|" << address << "\n";
            found = true;
        } else {
            temp << name << "|" << roll_no << "|" << course << "|" << address << "\n";
        }
    }

    file.close();
    temp.close();
    remove("studentRecord.txt");
    rename("temp.txt", "studentRecord.txt");
    cout << (found ? "Record modified!\n" : "Student not found.\n");
}

int main() {
    Student s;
    s.menu();
    return 0;
}