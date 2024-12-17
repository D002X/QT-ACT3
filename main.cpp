#include <QApplication> // Inclut la classe QApplication pour gérer l'application Qt
#include <QtSql/QSqlDatabase> // Inclut la classe QSqlDatabase pour la gestion des bases de données
#include <QtSql/QSqlTableModel> // Inclut la classe QSqlTableModel pour représenter les données d'une table
#include <QtSql/QSqlError> // Inclut la classe QSqlError pour gérer les erreurs de base de données
#include <QTableView> // Inclut la classe QTableView pour afficher les données sous forme de tableau
#include <QDebug> // Inclut la classe QDebug pour afficher des messages de débogage
#include <QWidget> // Inclut la classe QWidget, la classe de base pour tous les objets d'interface utilisateur
#include <QVBoxLayout> // Inclut la classe QVBoxLayout pour gérer la disposition verticale des widgets

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // Crée une instance de QApplication pour gérer l'application
    
    // Connexion à la base de données MySQL
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL"); // Ajoute un driver MySQL pour la base de données
    db.setHostName("localhost"); // Définit le nom d'hôte de la base de données (localhost pour une base de données locale)
    db.setDatabaseName("jeu");  // Définit le nom de la base de données à utiliser
    db.setUserName("etudiant"); // Définit le nom d'utilisateur pour se connecter à la base de données
    db.setPassword("Passciel#2"); // Définit le mot de passe pour se connecter à la base de données
    
    // Tente d'ouvrir la connexion à la base de données
    if (!db.open()) { // Vérifie si la connexion a échoué
        qDebug() << "La connexion à la base de données a échoué :" << db.lastError().text(); // Affiche l'erreur de connexion
        return -1; // Quitte l'application avec un code d'erreur
    }
    
    qDebug() << "Connexion réussie à la base de données."; // Affiche un message de succès si la connexion est établie
    
    // Configuration du modèle pour représenter les données
    QSqlTableModel *model = new QSqlTableModel(); // Crée un nouveau modèle de table SQL
    model->setTable("jeu"); // Définit la table à afficher dans le modèle
    model->setEditStrategy(QSqlTableModel::OnFieldChange); // Définit la stratégie d'édition pour que les modifications soient enregistrées immédiatement
    model->select(); // Charge les données depuis la table dans le modèle
    
    // Vérification de l'existence des données
    if (model->rowCount() == 0) { // Vérifie si le modèle ne contient aucune ligne
        qDebug() << "Aucune donnée trouvée dans la table `jeu`."; // Affiche un message si aucune donnée n'est trouvée
    }
    
    // Création de l'interface graphique
    QWidget window; // Crée une nouvelle fenêtre principale
    QVBoxLayout *layout = new QVBoxLayout(&window); // Crée un layout vertical et l'associe à la fenêtre
    
    QTableView *tableView = new QTableView(); // Crée une nouvelle vue de tableau pour afficher les données
    tableView->setModel(model); // Associe le modèle de données à la vue de tableau
    tableView->resizeColumnsToContents(); // Ajuste la largeur des colonnes en fonction de leur contenu
    layout->addWidget(tableView); // Ajoute la vue de tableau au layout
    window.setLayout(layout); // Définit le layout de la fenêtre
    window.setWindowTitle("Affichage des joueurs"); // Définit le titre de la fenêtre
    window.resize(600, 400); // Définit la taille initiale de la fenêtre
    window.show(); // Affiche la fenêtre à l'écran
    
    return a.exec(); // Lance la boucle d'événements de l'application
}
