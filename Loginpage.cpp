#include <iostream>
#include <vector>
using namespace std;
class User {
private:
    string username;
    string password;

public:
    User(string username, string password);

    string getUsername();
    bool checkPassword(string password);
};
class LoginSystem {
private:
    vector<User> users;

public:
    void registerUser();
    void loginUser();
};
int main() {

    LoginSystem system;

    int choice;

    do {
        cout << "\n1. Register";
        cout << "\n2. Login";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
            system.registerUser();

        else if (choice == 2)
            system.loginUser();

    } while (choice != 3);

}