#include <iostream>
#include <cstdlib> // pour rand()
using namespace std;

class Fichier {
private:
    char* P;     // pointeur vers la zone mémoire
    size_t taille; // longueur en octets

public:
    // Constructeur
    Fichier(size_t t) : P(nullptr), taille(t) {
        cout << "Constructeur appelé, taille = " << taille << " octets." << endl;
    }

    // Destructeur
    ~Fichier() {
        delete[] P; // libération de la mémoire
        cout << "Destructeur appelé, mémoire libérée." << endl;
    }

    // Méthode Creation : alloue la mémoire
    void Creation() {
        P = new char[taille];
        cout << "Mémoire allouée à l'adresse " << static_cast<void*>(P) << endl;
    }

    // Méthode Remplit : remplit la mémoire avec des valeurs aléatoires
    void Remplit() {
        if (!P) {
            cout << "Erreur : mémoire non allouée !" << endl;
            return;
        }
        for (size_t i = 0; i < taille; ++i) {
            P[i] = 'A' + rand() % 26; // lettres aléatoires A-Z
        }
        cout << "Mémoire remplie." << endl;
    }

    // Méthode Affiche : affiche le contenu
    void Affiche() {
        if (!P) {
            cout << "Erreur : mémoire non allouée !" << endl;
            return;
        }
        cout << "Contenu de la mémoire : ";
        for (size_t i = 0; i < taille; ++i) {
            cout << P[i];
        }
        cout << endl;
    }
};

int main() {
    size_t taille;
    cout << "Entrez la taille du fichier : ";
    cin >> taille;

    // Création de l'objet dynamiquement
    Fichier* monFichier = new Fichier(taille);

    // Appel des méthodes
    monFichier->Creation();
    monFichier->Remplit();
    monFichier->Affiche();

    // Destruction de l'objet
    delete monFichier;

    return 0;
}
