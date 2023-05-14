#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Man {
    std::string surname;
    std::string name;
    int age;
    std::string dateOfBirth;

    Man(std::string surname, std::string name, int age, std::string dateOfBirth)
        : surname(surname), name(name), age(age), dateOfBirth(dateOfBirth) {}
};

void addMan(std::vector<Man>& people, std::string surname, std::string name, int age, std::string dateOfBirth) {
    people.push_back(Man(surname, name, age, dateOfBirth));
}

bool compareBySurname(const Man& man1, const Man& man2) {
    return man1.surname < man2.surname;
}

bool compareByName(const Man& man1, const Man& man2) {
    return man1.name < man2.name;
}

void printPeople(const std::vector<Man>& people) {
    for (const auto& person : people) {
        std::cout << "Surname: " << person.surname << ", Name: " << person.name
            << ", Age: " << person.age << ", Date of Birth: " << person.dateOfBirth << std::endl;
    }
}

void printBirthdaysInMonth(const std::vector<Man>& people, int month) {
    std::cout << "Birthdays in Month " << month << ":" << std::endl;
    for (const auto& person : people) {
        std::string delimiter = ".";
        size_t pos = person.dateOfBirth.find(delimiter);
        int personBirthMonth = std::stoi(person.dateOfBirth.substr(0, pos));
        if (personBirthMonth == month) {
            std::cout << "Name: " << person.name << ", Date of Birth: " << person.dateOfBirth << std::endl;
        }
    }
}

void searchBySurname(const std::vector<Man>& people, const std::string& surname) {
    std::cout << "Search results for surname \"" << surname << "\":" << std::endl;
    for (const auto& person : people) {
        if (person.surname == surname) {
            std::cout << "Name: " << person.name << ", Age: " << person.age
                << ", Date of Birth: " << person.dateOfBirth << std::endl;
        }
    }
}

void searchByName(const std::vector<Man>& people, const std::string& name) {
    std::cout << "Search results for name \"" << name << "\":" << std::endl;
    for (const auto& person : people) {
        if (person.name == name) {
            std::cout << "Surname: " << person.surname << ", Age: " << person.age
                << ", Date of Birth: " << person.dateOfBirth << std::endl;
        }
    }
}

void editPerson(std::vector<Man>& people, const std::string& surname, const std::string& name, int age, const std::string& dateOfBirth) {
    std::cout << "Enter the surname of the person to edit: ";
    std::string searchSurname;
    std::cin >> searchSurname;
    bool found = false;
    for (auto& person : people) {
        if (person.surname == searchSurname) {
            person.surname = surname;
            person.name = name;
            person.age = age;
            person.dateOfBirth = dateOfBirth;
            found = true;
            break;
        }
    }

    if (found) {
        std::cout << "Person information updated successfully." << std::endl;
    }
    else {
        std::cout << "Person not found." << std::endl;
    }
}

int main() {
    std::vector<Man> people;
    addMan(people, "Smith", "John", 25, "05.12.1998");
    addMan(people, "Johnson", "Robert", 30, "12.03.1993");
    addMan(people, "Williams", "David", 35, "20.07.1988");
    addMan(people, "Brown", "Michael", 28, "15.09.1995");

    std::sort(people.begin(), people.end(), compareBySurname);
    std::cout << "People sorted by surname:" << std::endl;
    printPeople(people);

    std::cout << std::endl;

    std::sort(people.begin(), people.end(), compareByName);
    std::cout << "People sorted by name:" << std::endl;
    printPeople(people);

    std::cout << std::endl;

    printBirthdaysInMonth(people, 9);

    std::cout << std::endl;

    searchBySurname(people, "Smith");

    std::cout << std::endl;

    searchByName(people, "Robert");

    std::cout << std::endl;

    editPerson(people, "Johnson", "Robert", 32, "12.03.1993");

    std::cout << std::endl;

    std::cout << "Updated people information:" << std::endl;
    printPeople(people);

    return 0;
}