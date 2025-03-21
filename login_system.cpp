#include <iostream>

using namespace std;

struct person
{
    std::string username;
    std::string password;
    char side;
    int personCode;
};

enum side
{
    RegularUser = 'r',  //This category includes public users who have access to the site but limited features are available to them.
    Member      = 'm',  //These users are registered on the site and have more access than regular users.
    Contributor = 'c',  //These users can create content but usually require approval from administrators.
    Editor      = 'e',  //These users are responsible for reviewing and editing content submitted by authors.
    Admins      = 'a',  //These users have full access to the site and can manage all sections.
    Developer   = 'd',  //These users are responsible for the technical development and maintenance of the site.
    Security    = 's'   //These users are responsible for site security and have special access to manage security.

};

// Function to display a visual welcome
void displayWelcomeMessage() {
    std::cout << "******************************************\n";
    std::cout << "*                                        *\n";
    std::cout << "*   your welcome to login person system  *\n";
    std::cout << "*                                        *\n";
    std::cout << "*          Project: Login System         *\n";
    std::cout << "*        Author: [Amir Aghabakloo]       *\n";
    std::cout << "*                                        *\n";
    std::cout << "******************************************\n";
    std::cout << "\n";
}

// Function to display instructions
void displayInstructions() {
    std::cout << "Beginner's Guide to Writing a Login System:\n";
    std::cout << "1. Create a data structure to store user information.\n";
    std::cout << "2. Request the user's username and password.\n";
    std::cout << "3. Compare the entered information with the stored data.\n";
    std::cout << "4. If the information matches, log the user into the system.\n";
    std::cout << "5. Otherwise, display an error message.\n";
    std::cout << "\n";
}

// Function to display person information
void display(person **p, int length)
{
    for(int i=0; i<length; i++)
        cout << "UserName: " << p[i]->username << "\tPassWord: " << p[i]->password << "\tSide: "
             << p[i]->side << "\t PersonCode: " << p[i]->personCode << endl;
}

int main() {

    displayWelcomeMessage();

    displayInstructions();

    int length = 7;
    const int width = 4;

    person **p = new person*[length];

    p[0] = new person({"leilamahmudi" ,"@leila:0990" ,RegularUser ,1379});
    p[1] = new person({"aminagha" ,"@Amin:0936" ,Member ,1386});
    p[2] = new person({"mahdismusavi" ,"@Mahdis:0903" ,Contributor ,1386});
    p[3] = new person({"fatimosavi" ,"@Fati:0936" ,Editor ,1390});
    p[4] = new person({"amirbagloo" ,"@Almnv:991" ,Admins ,1369});
    p[5] = new person({"sadrabakal" ,"@Sadra:0477" ,Developer ,1400});
    p[6] = new person({"alirambakal" ,"@AliRam:0369" ,Security ,1404});

    display(p, length);

    string username;
    string password;
    char side;
    int personCode;




    cout << "Enter username:";
    cin >> username;

    cout << "Enter password:\n";
    cin >> password;

    switch (side) {

    }

    for(int i=0; i<length; i++)
        delete p[i];

    delete[] p;
    cout << "Press a key to exit the program....\n";
    cin.get();

    return 0;
}
