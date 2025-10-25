#include <iostream>
#include <string>
using namespace std;
class CompteBancaire {
private:
    double solde;
   string codeSecret;

public:
    CompteBancaire(double montantInitial, const string& code){
    solde=montantInitial;
	 codeSecret=code;	
	}

   
    CompteBancaire(const string& code){
	
    solde=0.0;
    codeSecret=code;
    }

    void afficherSolde() const {
        cout << solde << "dh" << endl;
    }

    void retrait(double montant) {
        if (montant <= 0) {
            cout << "Montant invalide " << endl;
            return;
        }
        if (montant > solde) {
            cout << "Solde insuffisant." << endl;
            return;
        }
        solde -= montant;
        cout << "Retrait de " << montant << "dh effectue. Nouveau solde : " << solde << "dh" << endl;
    }

    void retrait(double montant, const std::string& code) {
        if (code != codeSecret) {
            cout << "Code de securite incorrect." << endl;
            return;
        }
        if (montant <= 0) {
            cout << "Montant invalide " <<endl;
            return;
        }
        if (montant > solde) {
          cout << "Solde insuffisant ." <<endl;
            return;
        }
        solde -= montant;
        cout << "Retrait de " << montant << "dh effectue avec code. Nouveau solde : " << solde << "dh" << endl;
    }
};

int main() {
    
    CompteBancaire compte1(2000.0, "3456"); 
    CompteBancaire compte2("1234");         
    cout << "Solde du compte 1: " ;
    compte1.afficherSolde();
    cout << "Solde du compte 2: " ;
    compte2.afficherSolde();

    compte1.retrait(300);                   
    compte1.retrait(900, "12345");           
    compte2.retrait(200, "1234");          
    compte2.retrait(90);                    

    return 0;
}

