#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to store student details
struct Student {
    int rollNumber;
    string name;
    int age;
    string course;
};

// Function prototypes
void addStudent(vector<Student>& students);
void displayStudents(const vector<Student>& students);
void searchStudent(const vector<Student>& students);
void updateStudent(vector<Student>& students);
void deleteStudent(vector<Student>& students);

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n=== Student Management System ===\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                searchStudent(students);
                break;
            case 4:
                updateStudent(students);
                break;
            case 5:
                deleteStudent(students);
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

void addStudent(vector<Student>& students) {
    Student newStudent;
    cout << "Enter Roll Number: ";
    cin >> newStudent.rollNumber;
    cin.ignore(); // Clear the input buffer
    cout << "Enter Name: ";
    getline(cin, newStudent.name);
    cout << "Enter Age: ";
    cin >> newStudent.age;
    cin.ignore(); // Clear the input buffer
    cout << "Enter Course: ";
    getline(cin, newStudent.course);

    students.push_back(newStudent);
    cout << "Student added successfully!\n";
}

void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students to display.\n";
        return;
    }
    cout << "\n=== Student List ===\n";
    for (size_t i = 0; i < students.size(); ++i) {
        const Student& student = students[i];
        cout << "Roll Number: " << student.rollNumber << "\n";
        cout << "Name: " << student.name << "\n";
        cout << "Age: " << student.age << "\n";
        cout << "Course: " << student.course << "\n";
        cout << "---------------------\n";
    }
}

void searchStudent(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students to search.\n";
        return;
    }
    int rollNumber;
    cout << "Enter Roll Number to search: ";
    cin >> rollNumber;

    for (const auto& student : students) {
        if (student.rollNumber == rollNumber) {
            cout << "Student found:\n";
            cout << "Roll Number: " << student.rollNumber << "\n";
            cout << "Name: " << student.name << "\n";
            cout << "Age: " << student.age << "\n";
            cout << "Course: " << student.course << "\n";
            return;
        }
    }
    cout << "Student with Roll Number " << rollNumber << " not found.\n";
}

void updateStudent(vector<Student>& students) {
    if (students.empty()) {
        cout << "No students to update.\n";
        return;
    }
    int rollNumber;
    cout << "Enter Roll Number to update: ";
    cin >> rollNumber;

    for (auto& student : students) {
        if (student.rollNumber == rollNumber) {
            cout << "Enter new details:\n";
            cin.ignore(); // Clear the input buffer
            cout << "Enter Name: ";
            getline(cin, student.name);
            cout << "Enter Age: ";
            cin >> student.age;
            cin.ignore(); // Clear the input buffer
            cout << "Enter Course: ";
            getline(cin, student.course);
            cout << "Student updated successfully!\n";
            return;
        }
    }
    cout << "Student with Roll Number " << rollNumber << " not found.\n";
}

void deleteStudent(vector<Student>& students) {
    if (students.empty()) {
        cout << "No students to delete.\n";
        return;
    }
    int rollNumber;
    cout << "Enter Roll Number to delete: ";
    cin >> rollNumber;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->rollNumber == rollNumber) {
            students.erase(it);
            cout << "Student deleted successfully!\n";
            return;
        }
    }
    cout << "Student with Roll Number " << rollNumber << " not found.\n";
}
