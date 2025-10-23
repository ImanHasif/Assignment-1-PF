#include <iostream>
#include <string>
using namespace std;

// Maximum limits
const int MAX_STUDENTS = 10;
const int MAX_SUBJECTS = 5;

// Structure for Subject
struct Subject {
    string subjectName;
    int credit;
    double mark;
    string grade;
    double gradePoint;
};

// Structure for Student
struct Student {
    string name;
    int age;
    Subject subjects[MAX_SUBJECTS];
    int subjectCount;
    double cpa;
};

// Function to determine grade and grade point
void calculateGrade(Subject &sub) {
    if (sub.mark >= 90 && sub.mark <= 100) {
        sub.grade = "A+";
        sub.gradePoint = 4.00;
    } else if (sub.mark >= 80) {
        sub.grade = "A";
        sub.gradePoint = 4.00;
    } else if (sub.mark >= 75) {
        sub.grade = "A-";
        sub.gradePoint = 3.67;
    } else if (sub.mark >= 70) {
        sub.grade = "B+";
        sub.gradePoint = 3.33;
    } else if (sub.mark >= 65) {
        sub.grade = "B";
        sub.gradePoint = 3.00;
    } else if (sub.mark >= 60) {
        sub.grade = "B-";
        sub.gradePoint = 2.67;
    } else if (sub.mark >= 55) {
        sub.grade = "C+";
        sub.gradePoint = 2.33;
    } else if (sub.mark >= 50) {
        sub.grade = "C";
        sub.gradePoint = 2.00;
    } else if (sub.mark >= 45) {
        sub.grade = "C-";
        sub.gradePoint = 1.67;
    } else if (sub.mark >= 40) {
        sub.grade = "D+";
        sub.gradePoint = 1.33;
    } else if (sub.mark >= 35) {
        sub.grade = "D";
        sub.gradePoint = 1.00;
    } else if (sub.mark >= 30) {
        sub.grade = "D-";
        sub.gradePoint = 0.67;
    } else {
        sub.grade = "E";
        sub.gradePoint = 0.00;
    }
}

// Function to calculate CPA
void calculateCPA(Student &stu) {
    double totalGradePoint = 0;
    int totalCredit = 0;

    for (int i = 0; i < stu.subjectCount; i++) {
        totalGradePoint += stu.subjects[i].gradePoint * stu.subjects[i].credit;
        totalCredit += stu.subjects[i].credit;
    }

    if (totalCredit > 0)
        stu.cpa = totalGradePoint / totalCredit;
    else
        stu.cpa = 0.0;
}

// Main program
int main() {
    Student students[MAX_STUDENTS];
    int studentCount;

    cout << "Enter number of students (max 10): ";
    cin >> studentCount;

    if (studentCount > MAX_STUDENTS) studentCount = MAX_STUDENTS;

    for (int i = 0; i < studentCount; i++) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        cin.ignore(); // clear buffer
        cout << "Name: ";
        getline(cin, students[i].name);
        cout << "Age: ";
        cin >> students[i].age;

        cout << "Enter number of subjects (max 5): ";
        cin >> students[i].subjectCount;
        if (students[i].subjectCount > MAX_SUBJECTS)
            students[i].subjectCount = MAX_SUBJECTS;

        for (int j = 0; j < students[i].subjectCount; j++) {
            cin.ignore();
            cout << "\nSubject " << j + 1 << " name: ";
            getline(cin, students[i].subjects[j].subjectName);
            cout << "Credit hour: ";
            cin >> students[i].subjects[j].credit;

            // Validate mark input
            do {
                cout << "Mark (0-100): ";
                cin >> students[i].subjects[j].mark;
                if (students[i].subjects[j].mark < 0 || students[i].subjects[j].mark > 100)
                    cout << "Invalid mark! Please enter between 0 and 100.\n";
            } while (students[i].subjects[j].mark < 0 || students[i].subjects[j].mark > 100);

            // Calculate grade
            calculateGrade(students[i].subjects[j]);
        }

        // Calculate CPA
        calculateCPA(students[i]);
    }

    // Display results
    cout << "\n\n===== STUDENT RESULT LIST =====\n";
    for (int i = 0; i < studentCount; i++) {
        cout << "\nName: " << students[i].name;
        cout << "\nAge: " << students[i].age;
        cout << "\nSubjects:\n";
        for (int j = 0; j < students[i].subjectCount; j++) {
            cout << "  " << students[i].subjects[j].subjectName
                 << " | Credit: " << students[i].subjects[j].credit
                 << " | Mark: " << students[i].subjects[j].mark
                 << " | Grade: " << students[i].subjects[j].grade
                 << " | Point: " << students[i].subjects[j].gradePoint << endl;
        }
        cout << "CPA: " << students[i].cpa << endl;
    }

    return 0;
}
