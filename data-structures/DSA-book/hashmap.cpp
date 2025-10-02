#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> people = { {"John", 32}, {"Adele", 45}, {"Bo", 29} };

    std::cout << "John is: " << people["John"] << "\n";
    std::cout << "Adele is: " << people["Adele"] << "\n";

    people["John"] = 50;

    people.insert({"Jenny", 22});
    people.insert({"Liam", 24});
    people["Kasper"] = 20;
    people["Anja"] = 30;

    people.erase("John");

    for (auto person : people) {
        std::cout << person.first << " is: " << person.second << "\n";
    }

    return 0;
}