#include <iostream>
#include <vector>

struct Student {
    std::string surname;
    std::string group;
    std::vector<int> grades;

    Student(std::string surname, std::string group, std::vector<int> grades)
        : surname(surname), group(group), grades(grades) {}
};

void addStudent(std::vector<Student>& students, std::string surname, std::string group, std::vector<int> grades) {
    students.push_back(Student(surname, group, grades));
}

void printExcellentStudents(const std::vector<Student>& students) {
    std::cout << "Excellent Students:" << std::endl;
    for (const auto& student : students) {
        int excellentCount = 0;
        for (const auto& grade : student.grades) {
            if (grade >= 75) {
                excellentCount++;
            }
        }
        double excellentPercentage = (static_cast<double>(excellentCount) / student.grades.size()) * 100;
        if (excellentPercentage > 75) {
            std::cout << "Surname: " << student.surname << ", Group: " << student.group << std::endl;
        }
    }
}

void printLowPerformingStudents(const std::vector<Student>& students) {
    std::cout << "Low Performing Students:" << std::endl;
    for (const auto& student : students) {
        int lowCount = 0;
        for (const auto& grade : student.grades) {
            if (grade == 2 || grade == 3) {
                lowCount++;
            }
        }
        double lowPercentage = (static_cast<double>(lowCount) / student.grades.size()) * 100;
        if (lowPercentage > 50) {
            std::cout << "Surname: " << student.surname << ", Group: " << student.group << std::endl;
        }
    }
}

int main() {
    std::vector<Student> students;

    // Adding students
    addStudent(students, "Smith", "Group A", { 80, 90, 85, 95, 75 });
    addStudent(students, "Johnson", "Group B", { 70, 60, 65, 80, 75 });
    addStudent(students, "Williams", "Group A", { 90, 85, 95, 75, 80 });
    addStudent(students, "Brown", "Group C", { 60, 70, 80, 75, 90 });

    // Printing excellent students
    printExcellentStudents(students);

    std::cout << std::endl;

    // Printing low performing students
    printLowPerformingStudents(students);

    return 0;
}
