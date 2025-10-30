#include <iostream>
#include <string>
using namespace std;

// =====================================================
// 1️- Classe Client
// =====================================================
class Client {
private:
    int id;
    string nom;
    string prenom;

public:
    // Constructeur par défaut
    Client() : id(0), nom(""), prenom("") {
        cout << "Client vide créé." << endl;
    }

    // Constructeur avec paramètres
    Client(int i, string n, string p) : id(i), nom(n), prenom(p) {
        cout << "Client créé : " << nom << " " << prenom << endl;
    }

    // Constructeur de copie
    Client(const Client& c) : id(c.id), nom(c.nom), prenom(c.prenom) {
        cout << "Copie de client effectuée : " << nom << " " << prenom << endl;
    }

    // Destructeur
    ~Client() {
        cout << "Client détruit : " << nom << " " << prenom << endl;
    }

    // Méthode d'affichage
    void afficher() const {
        cout << "Client [ID: " << id << ", Nom: " << nom << ", Prénom: " << prenom << "]" << endl;
    }
};

// =====================================================
// 2️- Classe Compte
// =====================================================
class Compte {
private:
    int numero;
    float solde;
    Client* client;                  // pointeur vers un Client
    static int nbComptes;            // compteur global de comptes

public:
    // Constructeur par défaut
    Compte() : numero(0), solde(0.0), client(nullptr) {
        nbComptes++;
        cout << "Compte vide créé. Total comptes : " << nbComptes << endl;
    }

    // Constructeur avec paramètres
    Compte(int num, float s, const Client& c)
        : numero(num), solde(s), client(new Client(c)) {
        nbComptes++;
        cout << "Compte créé pour " << num << ". Total comptes : " << nbComptes << endl;
    }

    // Constructeur de copie (copie profonde)
    Compte(const Compte& c)
        : numero(c.numero), solde(c.solde), client(new Client(*c.client)) {
        nbComptes++;
        cout << "Compte copié (numéro " << numero << "). Total comptes : " << nbComptes << endl;
    }

    // Destructeur
    ~Compte() {
        delete client; // libération du client associé
        nbComptes--;
        cout << "Compte détruit (numéro " << numero << "). Total comptes : " << nbComptes << endl;
    }

    // Afficher les infos du compte
    void afficher() const {
        cout << "Compte n°" << numero << " | Solde: " << solde << " DH" << endl;
        if (client)
            client->afficher();
        else
            cout << "Aucun client associé." << endl;
    }

    // Méthode statique pour afficher le nombre total de comptes
    static void afficherNbComptes() {
        cout << "Nombre total de comptes existants : " << nbComptes << endl;
    }

    // Getters pour appliquer des intérêts
    float getSolde() const { return solde; }
    void setSolde(float s) { solde = s; }
};

// Initialisation de la variable statique
int Compte::nbComptes = 0;

// =====================================================
// 3️- Fonction utilitaire (calcul des intérêts)
// =====================================================

// inline : car elle est courte et appelée souvent, donc éviter overhead d’appel
inline float calculInteret(float solde, float taux) {
    return solde + solde * taux / 100.0f;
}

// =====================================================
// 4️- Programme principal
// =====================================================
int main() {
    cout << "=== Création des clients ===" << endl;
    Client c1(1, "Dupont", "Jean");
    Client c2(2, "Martin", "Claire");

    cout << "\n=== Création des comptes ===" << endl;
    Compte compte1(1001, 1500.0f, c1);
    Compte compte2(1002, 2500.0f, c2);

    Compte::afficherNbComptes();

    cout << "\n=== Copie d’un compte ===" << endl;
    Compte compte3 = compte1; // constructeur de copie
    Compte::afficherNbComptes();

    cout << "\n=== Affichage des comptes ===" << endl;
    compte1.afficher();
    compte2.afficher();
    compte3.afficher();

    cout << "\n=== Application des intérêts (5%) ===" << endl;
    float nouveauSolde = calculInteret(compte1.getSolde(), 5);
    compte1.setSolde(nouveauSolde);
    compte1.afficher();

    cout << "\n=== Destruction de certains comptes ===" << endl;
    {
        Compte compteTemp(2000, 500.0f, c2);
        Compte::afficherNbComptes();
    } // fin du bloc → destructeur appelé

    Compte::afficherNbComptes();

    cout << "\n=== Fin du programme ===" << endl;
    return 0;
}
