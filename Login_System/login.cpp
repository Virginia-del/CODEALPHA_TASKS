#include <iostream>
#include <fstream>
using namespace std;

void registerUser() {
    string username, password;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ofstream file(username + ".txt");
    file << username << endl << password;
    file.close();

    cout << "Registration successful! \n";
}
void loginUser() {
    string username, password;
    string storedUser , storedPass;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file(username + ".txt");

    if (!file){
        cout << "User not found!\n";
        return;
    }
    file >> storedUser >> storedPass;

    if (username == storedUser && password == storedPass)
      cout << "Login successful!\n";
      else
      cout << "Incorrect password!\n";
}

int main(){
    int choice;

    cout << "1. Register\n2. Login\nChoice: ";
    cin >> choice;

    if(choice == 1)
     registerUser();
    else if (choice == 2)
      loginUser();
    else
      cout << "Invalid choice!\n";


    return 0;
}