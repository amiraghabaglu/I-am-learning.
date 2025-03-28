#include <iostream>

using namespace std;

struct person
{
  std::string username;
  std::string password;
  char side;
  int personCode;
};

struct ClassFunctions
{
  void displayWelcomeMessage();
  void displayInstructions();
  void display(person **p, int length);
  void regularUser();
  void member();
  void editor();
  void admin();
  void developer();
  void security();
  void contributor();
};

enum side
{
  RegularUser = 'r',  //This category includes public users who have access to the site but limited features are available to them.
  Member      = 'm',  //These users are registered on the site and have more access than regular users.
  Contributor = 'c',  //These users can create content but usually require approval from administrators.
  Editor      = 'e',  //These users are responsible for reviewing and editing content submitted by authors.
  Admin       = 'a',  //These users have full access to the site and can manage all sections.
  Developer   = 'd',  //These users are responsible for the technical development and maintenance of the site.
  Security    = 's'   //These users are responsible for site security and have special access to manage security.
};

int main() {

  ClassFunctions cf;

  cf.displayWelcomeMessage();

  cf.displayInstructions();

  int length = 7;
  const int width = 4;

  person **p = new person*[length];

  p[0] = new person({"leilamahmudi" ,"@leila:0990"  ,RegularUser  ,1379});
  p[1] = new person({"aminagha"     ,"@Amin:0936"  ,Member       ,1386});
  p[2] = new person({"mahdismusavi" ,"@Mahdis:0903"  ,Contributor  ,1386});
  p[3] = new person({"fatimosavi"   ,"@Fati:0936"  ,Editor       ,1390});
  p[4] = new person({"amirbagloo"   ,"@Almnv:991"   ,Admin        ,1369});
  p[5] = new person({"sadrabakal"   ,"@Sadra:0477"  ,Developer    ,1400});
  p[6] = new person({"alirambakal"  ,"@AliRam:0369"  ,Security     ,1404});

  string username;
  string password;
  char side;
  int personCode;

  cout << "Enter username: ";
  cin >> username;

  cout << "Enter password: ";
  cin >> password;

  for(int i=0; i<7; i++)
    if(username == p[i]->username)
      if(password == p[i]->password)
      {
        side = p[i]->side;
        switch (side) {
          case RegularUser:
            cf.regularUser();
            break;

          case Member:
            cf.member();
            break;

          case Editor:
            cf.editor();
            break;

          case Admin:
            cf.admin();
            break;

          case Developer:
            cf.developer();
            break;

          case Contributor:
            cf.contributor();
            break;

          case Security:
            cf.security();
            break;
        }
      }
      
  for(int i=0; i<length; i++)
      delete p[i];
  delete[] p;
  
  cout << "Press a key to exit the program....\n";
  cin.get();

  return 0;
}

// Function to display a visual welcome
void ClassFunctions::displayWelcomeMessage() {
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
void ClassFunctions::displayInstructions() {
  std::cout << "Beginner's Guide to Writing a Login System:\n";
  std::cout << "1. Create a data structure to store user information.\n";
  std::cout << "2. Request the user's username and password.\n";
  std::cout << "3. Compare the entered information with the stored data.\n";
  std::cout << "4. If the information matches, log the user into the system.\n";
  std::cout << "5. Otherwise, display an error message.\n";
  std::cout << "\n";
}

// Function to display person information
void ClassFunctions::display(person **p, int length)
{
  for(int i=0; i<length; i++)
    cout << "UserName: " << p[i]->username << "\tPassWord: " << p[i]->password << "\tSide: "
      << p[i]->side << "\t PersonCode: " << p[i]->personCode << endl;
}

void ClassFunctions::regularUser()
{
  cout << ".....regularUser yourwelcom....." << endl;
  
  char chois;
  char order;
  string comments;
  
  cout << "Enter 'c' to comment,\n"
          "Select order 'o',\n"
          "Buy cart 'b',\n"
          "Interest 'l' or 'd',\n"
          "Exit 'e'." << endl;
  
  while(true)
  {
    cout << "enter comment: ";
    cin >> chois;
    if(chois == 'e')
      break;
    switch(chois)
    {
      case 'c':
        cout << "enter your comment:";
        cin >> comments;
        cout << "User Amir comment is: " << comments << endl;
        break;

      case 'o':
        cout << "from a to z enter a order: ";
        cin >> order;
        break;

      case 'b':
        int cart;
        cout << "your order is " << order << endl;
        cout << "enter info crdit cart: ";
        cin >> cart;
        cout << "Your order for " << order <<" will arrive in a short while." << endl;
        break;      
 
      case 'l':
        cout << "User Amir liked the product." << endl;
        break;

      case 'd':
        cout << "User Amir disliked the product." << endl;
        break;
    }
  }
}

void ClassFunctions::member()
{
  cout << "member";
}
void ClassFunctions::editor()
{
  cout << "editor";
}
void ClassFunctions::admin()
{
  cout << "admin";
}
void ClassFunctions::developer()
{
  cout << "developer";
}
void ClassFunctions::security()
{
  cout << "security";
}
void ClassFunctions::contributor()
{
  cout << "contributor";
}
