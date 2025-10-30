#include <iostream>
using namespace std;

// Définition de la classe Pile
class Pile {
private:
    int* elements;   // tableau dynamique pour stocker les éléments
    int tailleMax;   // taille maximale de la pile
    int sommet;      // indice du sommet de la pile

public:
    // Constructeur : initialise une pile vide de taille donnée
    Pile(int taille = 10) {
        tailleMax = taille;
        elements = new int[tailleMax];
        sommet = -1; // la pile est vide
    }

    // Destructeur : libère la mémoire
    ~Pile() {
        delete[] elements;
    }

    // Empiler un élément (push)
    void push(int valeur) {
        if (sommet == tailleMax - 1) {
            cout << "Erreur : pile pleine !" << endl;
        } else {
            sommet++;
            elements[sommet] = valeur;
            cout << valeur << " empilé dans la pile." << endl;
        }
    }

    // Dépiler un élément (pop)
    int pop() {
        if (sommet == -1) {
            cout << "Erreur : pile vide !" << endl;
            return -1; // valeur par défaut en cas d'erreur
        } else {
            int valeur = elements[sommet];
            sommet--;
            cout << valeur << " dépilé de la pile." << endl;
            return valeur;
        }
    }

    // Vérifier si la pile est vide
    bool estVide() {
        return (sommet == -1);
    }

    // Afficher la pile
    void afficher() {
        if (estVide()) {
            cout << "Pile vide." << endl;
        } else {
            cout << "Contenu de la pile : ";
            for (int i = 0; i <= sommet; i++) {
                cout << elements[i] << " ";
            }
            cout << endl;
        }
    }
};

// Programme principal
int main() {
    // Création de deux piles
    Pile p1(5);
    Pile p2(3);

    cout << "--- Pile p1 ---" << endl;
    p1.push(10);
    p1.push(20);
    p1.push(30);
    p1.afficher();
    p1.pop();
    p1.afficher();

    cout << "\n--- Pile p2 ---" << endl;
    p2.push(5);
    p2.push(15);
    p2.afficher();
    p2.pop();
    p2.pop();
    p2.pop(); // test de dépilement sur pile vide

    return 0;
}
