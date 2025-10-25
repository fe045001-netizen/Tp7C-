#include <iostream>
#include <string>
using namespace std;
class Contact {
private:
    string nom;
    string numero;
    string email;

public:
    Contact(const string& n) {
        nom = n;
        numero = "Non defini";
        email = "Non defini";
    }

    Contact(const  string& n, const string& num) {
        nom = n;
        numero = num;
        email = "Non defini";
    }

    Contact(const string& n, const string& num, const string& mail) {
        nom = n;
        numero = num;
        email = mail;
    }

    void afficher() const {
        cout << "Nom : " << nom << endl;
        cout << "Telephone : " << numero << endl;
        cout << "Email : " << email << endl;
       
    }
};

int main() {
    Contact c1("Kawtar", "0660319777", "Kawtar@example.com");
    Contact c2("Ali", "0660319556");
    Contact c3("Imane");

    c1.afficher();
    c2.afficher();
    c3.afficher();

    return 0;
}

