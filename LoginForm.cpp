#include<iostream>
#include<fstream>
using namespace std;

class User {
    string userName, Email, password;
    fstream file;

public:
	void menu(){
    int choice;
	cout << "Menu";
    cout << "\n 1 - Login";
    cout << "\n 2 - SignUp";
    cout << "\n 3 - Forget Password";
    cout << "\n 4 - Exit\n";
    cout << "\nEnter Your Choice::";
    
    cin >> choice;
    cin.ignore(); 

    switch (choice) {
        case 1:
            login();
            break;
        case 2:
            signUp();
            break;
        case 3:
            forgot();
            break;
       
        default:
            cout << "Invalid Option";
    }
}
    string SearchName, SearchPass, SearchEmail;
    void login();
    void signUp();
    void forgot();
};

int main() {
    User user;
    user.menu();
    return 0;
}

void User::signUp() {
    cout << "\nEnter Your User Name::";
    getline(cin, userName);
    cout << "Enter Your Email Address::";
    getline(cin, Email);
    cout << "Enter Your Password::";
    getline(cin, password);

    file.open("loginData.txt", ios::out | ios::app);
    file << userName << "*" << Email << "*" << password << endl;
    file.close();
    cout<<"\n\n";
	menu();
}

void User::login() {
    cout << "--------Login---------\n";
    cout << "Enter Your User Name::";
    getline(cin, SearchName);
    cout << "Enter Your Password::";
    getline(cin, SearchPass);

    file.open("loginData.txt", ios::in);
    bool found = false;

    while (getline(file, userName, '*') && getline(file, Email, '*') && getline(file, password, '\n')) {
        if (userName == SearchName && password == SearchPass) {
            found = true;
            cout << "\nAccount Login Successfully";
            cout << "\nUserName: " << userName << endl;
            cout << "Email: " << Email << endl<<endl<<endl;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Invalid Username or Password!\n\n";
    }
     cout<<"\n\n";
	  menu();
}

void User::forgot() {
    cout << "\nEnter Your UserName::";
    getline(cin, SearchName);
    cout << "Enter Your Email::";
    getline(cin, SearchEmail);

    file.open("loginData.txt", ios::in);
    file.seekg(0);
    bool found = false;

    while (getline(file, userName, '*') && getline(file, Email, '*') && getline(file, password, '\n')) {
        if (userName == SearchName && Email == SearchEmail) {
            found = true;
            cout << "\nAccount Found";
            cout << "Your Password: " << password << endl;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "\nRecord Not Found!!";
    }
      cout<<"\n\n";
	  menu();
}

