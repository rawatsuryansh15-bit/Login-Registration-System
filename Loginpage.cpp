#include <iostream>
#include <vector>
using namespace std;
class User {
private:
    string username;
    string password;

public:
    User(string username, string password){
        this->username = username;
        this->password = password;
    }
    string getUsername(){
        return this->username;
    }
    bool checkPassword(string password){
        if(this->password == password){
            return true;
        }
        else return false;
    }
};
class LoginSystem {
private:
    vector<User> users;

public:
    void registerUser(){
        string username, password;
        cin.ignore();
        cout<<"Enter the username : ";
        getline(cin,username);
        cout<<"Enter the password : ";
        getline(cin,password);
        User u1(username,password);
        users.push_back(u1);
    }
    // void loginUser(){
    //     string username, password;
    //     cout<<"Enter your username : ";
    //     cin.ignore();
    //     getline(cin,username);
    //     cout<<"Enter your password : ";
    // }
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
        // else if (choice == 2)
        //     system.loginUser();
    } while (choice != 3);

}