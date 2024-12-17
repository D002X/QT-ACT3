#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlError>
#include <QTableView>
#include <QDebug>
#include <QWidget>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Connexion à la base de données MySQL
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost"); // Optionnel : configurez si nécessaire
    db.setDatabaseName("jeu");  // Nom de la base de données
    db.setUserName("etudiant"); // Nom d'utilisateur
    db.setPassword("Passciel#2"); // Mot de passe

    if (!db.open()) {
        qDebug() << "La connexion à la base de données a échoué :" << db.lastError().text();
        return -1;
    }

    qDebug() << "Connexion réussie à la base de données.";

    // Configuration du modèle pour représenter les données
    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("jeu"); // Nom de la table à afficher
    model->setEditStrategy(QSqlTableModel::OnFieldChange); // Modifications directement sur la base
    model->select(); // Charger les données depuis la table

    // Vérification de l'existence des données
    if (model->rowCount() == 0) {
        qDebug() << "Aucune donnée trouvée dans la table `jeu`.";
    }

    // Création de l'interface graphique
    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout(&window);

    QTableView *tableView = new QTableView();
    tableView->setModel(model); // Associer le modèle au tableau
    tableView->resizeColumnsToContents(); // Ajuster les colonnes à leur contenu
    layout->addWidget(tableView);
    window.setLayout(layout);
    window.setWindowTitle("Affichage des joueurs");
    window.resize(600, 400);
    window.show();

    return a.exec();
}
