#include <iostream>
using namespace std;

// Structure représentant un élément de la liste
struct Element {
    int valeur;
    Element* suivant;
};

// Classe Liste simplement chaînée
class Liste {
private:
    Element* premier; // pointeur vers le premier élément de la liste

public:
    // Constructeur
    Liste() : premier(nullptr) {}

    // Destructeur : libère toute la mémoire de la liste
    ~Liste() {
        while (premier != nullptr) {
            Element* temp = premier;
            premier = premier->suivant;
            delete temp;
        }
        cout << "Mémoire de la liste libérée." << endl;
    }

    // Méthode pour ajouter un élément au début
    void ajouterDebut(int val) {
        Element* nouveau = new Element; // allocation dynamique
        nouveau->valeur = val;
        nouveau->suivant = premier;
        premier = nouveau;
    }

    // Méthode pour supprimer le premier élément
    void supprimerDebut() {
        if (premier == nullptr) {
            cout << "Liste vide, rien à supprimer." << endl;
            return;
        }
        Element* temp = premier;
        premier = premier->suivant;
        delete temp; // libération de la mémoire
        cout << "Premier élément supprimé." << endl;
    }

    // Méthode pour afficher toute la liste
    void afficher() {
        if (premier == nullptr) {
            cout << "Liste vide." << endl;
            return;
        }
        Element* courant = premier;
        cout << "Liste : ";
        while (courant != nullptr) {
            cout << courant->valeur << " -> ";
            courant = courant->suivant;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Liste maListe;

    maListe.ajouterDebut(10);
    maListe.ajouterDebut(20);
    maListe.ajouterDebut(30);

    maListe.afficher();

    maListe.supprimerDebut();
    maListe.afficher();

    maListe.supprimerDebut();
    maListe.supprimerDebut();
    maListe.afficher();

    // A la fin du main, le destructeur s'occupe de libérer la mémoire
    return 0;
}
