#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Article {
public:
    string nom;
    double prixUnitaire;
    int quantite;
    double tva; 

    Article(const string& n, double prix, int q = 1, double t = 0.0){
    	nom=n;
	    prixUnitaire=prix;
	    quantite=q; 
		tva=t;
	}
        
};

class Facture {
private:
    vector<Article> articles;

public:
    
    void ajouterArticle(const string& nom, double prix) {
        articles.push_back(Article(nom, prix));
    }

    
    void ajouterArticle(const string& nom, double prix, int quantite) {
        articles.push_back(Article(nom, prix, quantite));
    }

    void ajouterArticle(const string& nom, double prix, int quantite, double tva) {
        articles.push_back(Article(nom, prix, quantite, tva));
    }

void afficherTotal() const {
    double total = 0.0;
   cout << "Details de la facture :" <<endl;
    

    for (size_t i = 0; i < articles.size(); ++i) {
        const Article& a = articles[i]; 
        double prixTTC = a.prixUnitaire * a.quantite * (1 + a.tva / 100);
             cout   << " - Prix Unitaire: " << a.prixUnitaire
                  << "dh, Quantite: " << a.quantite
                  << ", TVA: " << a.tva << "%"
                  << ", Total: " << prixTTC << "dh" << std::endl;
        total += prixTTC;
    }

    
    cout << "Montant total : " << total << "dh" << std::endl;
}

};

int main() {
    Facture f;

    f.ajouterArticle("Pen", 1.5);                 
    f.ajouterArticle("Notebook", 10.0, 2);            
    f.ajouterArticle("Imprimante", 250.0, 2, 18); 

    f.afficherTotal();

    return 0;
}

