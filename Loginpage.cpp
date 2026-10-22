#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
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
    string getPassword(){
        return this->password;
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
        cout<<"Enter the username : ";
        getline(cin,username);
        int size = users.size();
        for(int i = 0; i<size; i++){
            if(users[i].getUsername() == username){
                cout<<"Username already exists! Try another username."<<endl;
                return;
            }
        }
    
        cout<<"Enter the password : ";
        getline(cin,password);
        User u1(username,password);
        users.push_back(u1);
        saveUsers();
    }
    void loginUser(){
        string username;
        cout<<"Enter your username : ";
        getline(cin,username);
        int size = users.size();
        bool found = false;
        for(int i = 0; i<size; i++){
            if(users[i].getUsername() == username){
                found = true;
                cout<<"Username Found!"<<endl;
                string password;
                cout<<"Enter the user password : ";
                getline(cin,password);
                if(users[i].checkPassword(password)){
                    cout<<"Login Success!"<<endl;
                    break;
                }
                else{
                    cout<<"Wrong Password!"<<endl;
                    break;
                }
            }
        }
        if(!found){
            cout<<"Username not found! Kindly Register!"<<endl;
        }
    }
    void saveUsers(){
        ofstream file("users.txt");
        for(int i = 0; i<users.size(); i++){
            file<<users[i].getUsername()<<"\n";
            file<<users[i].getPassword()<<"\n";
        }
        file.close();
    }
    void loadUsers(){
        ifstream file("users.txt");
        if(!file) return;
        string username, password;
        while(getline(file,username)&& getline(file,password)){
            User u(username,password);
            users.push_back(u);
        }
    }
};
int main() {
    LoginSystem system;
    system.loadUsers();
    int choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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