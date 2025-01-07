# RequeteSQL

**Qt Database Viewer - Affichage de données MySQL**

Ce programme en C++ utilise Qt pour se connecter à une base de données MySQL et afficher les données dans une vue sous forme de tableau (QTableView). 
Il permet de se connecter à une base de données, de charger les données d'une table spécifique et de les afficher dans une interface graphique.

**Fonctionnalités :**

    Connexion à une base de données MySQL.
    Chargement des données depuis une table MySQL dans un modèle (QSqlTableModel).
    Affichage des données dans une interface graphique avec QTableView.
    Interface simple avec une mise en page verticale pour afficher le tableau.

# Prérequis

**Avant d'exécuter ce programme, assurez-vous que vous avez installé les éléments suivants :**

1.**Qt Framework**

*Ce programme nécessite Qt 5 ou une version supérieure. Vous pouvez télécharger et installer Qt à partir du site officiel :*

https://www.qt.io/download-qt-installer

2. **MySQL**

*Assurez-vous que MySQL est installé et configuré sur votre machine, et que vous avez accès à la base de données avec un utilisateur ayant les privilèges nécessaires.*

https://dev.mysql.com/downloads/installer/

3. **Driver MySQL pour Qt**

*Qt utilise un driver pour se connecter à MySQL. Vous devrez vous assurer que le driver QMYSQL est installé et configuré. Sur certaines distributions Linux, vous devrez peut-être installer un paquet supplémentaire comme libqt5sql5-mysql pour avoir accès à ce driver.*

**Taper la commande suivante sous le terminal :**
```
sudo apt-get update && sudo apt-get upgrade
```
**Télécharger ensuite les libraries qui manque :**
```
sudo apt install build-essential libgl1-mesa-dev libxkbcommon-x11-0
```
4. **Base de données MySQL**

*La table utilisée dans ce programme s'appelle jeu. Vous devez avoir une base de données MySQL avec une table de ce nom. Voici un exemple de structure pour la table jeu :*
```
CREATE TABLE jeu (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nom VARCHAR(100),
    club VARCHAR(100),
    note INT
);
```
*Inserez maintenant dans le tableau jeu pour que chaque partie (nom , club , notes) ont des valeurs :*
```
 INSERT INTO jeu (nom, club, notes)
    VALUES ('Ronaldo', 'Madrid', 3)
    VALUES ('Grizou','Barca', 2);
```
5. **Configuration du projet**

*Le projet doit être configuré pour utiliser le module Qt SQL. Assurez-vous d'ajouter la ligne suivante dans votre fichier .pro :*
```
QT += sql

```
# Installation

1. **Clonez ce repository ou copiez le code source dans un répertoire de votre choix**.

2. **Assurez-vous d'avoir correctement installé Qt et MySQL**.

3. **Ouvrez le projet avec Qt Creator ou un autre environnement de développement compatible avec Qt**.

4. **Vérifiez les paramètres de connexion dans le code source** **(nom d'utilisateur, mot de passe, hôte, base de données)**.
```
db.setHostName("localhost");
db.setDatabaseName("jeu");
db.setUserName("etudiant");
db.setPassword("Passciel#2");
```
5.**Compilez et exécutez le programme. Une fenêtre devrait s'ouvrir et afficher les données de la table jeu**.

# Fonctionnement

Lorsque vous exécutez le programme, voici ce qui se passe :

    Connexion à la base de données MySQL : Le programme se connecte à la base de données MySQL avec les informations spécifiées dans le code source.

    Chargement des données : Une fois la connexion réussie, le programme charge les données de la table jeu à l'aide de la classe QSqlTableModel.

    Affichage des données : Les données sont affichées dans une interface graphique dans un widget QTableView.

    Interface utilisateur : La fenêtre s'affiche avec les données dans un tableau. Le tableau peut être redimensionné, et les colonnes sont ajustées automatiquement en fonction de leur contenu.
    
**Erreurs possibles**

Erreur de connexion à la base de données : Si la connexion échoue, un message d'erreur détaillant la cause de l'échec sera affiché dans la sortie de débogage. 

Cela peut être dû à un mauvais nom d'utilisateur, mot de passe ou base de données.

Exemple de message d'erreur :
```
La connexion à la base de données a échoué : QSqlError("", "Access denied for user 'etudiant'@'localhost'", "28000")
```
**Table vide** : Si la table jeu est vide, un message sera affiché dans la sortie de débogage.

Exemple :
```
Aucune donnée trouvée dans la table `jeu`.
```
*Exemple de sortie*

Si la base de données contient des données, vous devriez voir une fenêtre avec une table contenant des colonnes comme id, nom,club,notes. La fenêtre ressemblera à ceci :
```
+----+-------------+-------+---------+
| id | nom        | club |  notes    |
+----+-------------+-------+---------+
| 1  | Ronaldo    |Madrid|   3       |
| 2  | Grizou     |Barca |   2       |
+----+-------------+-------+---------+
```
**Modification qui impact directement au changement de note à la base de donnée**
```
 QSqlTableModel *model = new QSqlTableModel();    // Configuration du modèle pour représenter les données
    model->setTable("jeu"); // Nom de la table à afficher
    model->setEditStrategy(QSqlTableModel::OnFieldChange); // Modifications directement sur la base de donnée "jeu".
    model->select(); // Charger les données modifiés depuis la table jeu.
```
**Vérification de l'existence de donnée dans le tableau** 
```
if (model->rowCount() == 0) {
        qDebug() << "Aucune donnée trouvée dans la table `jeu`.";
    }
```
Cette conditions permettra de vérifier si la table jeu est bien inclus depuis la partie Mysql ou non.

Maintenant il vous reste plus qu'à compiler le projet sur QT et d'effectuer des test.

**Compiler et Lancer l'Application**

Cliquez sur le bouton Compiler dans Qt Creator.

Une fois la compilation terminée, cliquez sur le bouton Exécuter pour lancer l'application.

**Tester l'Application**

Les information de votre base de donnés est sensé apparaitre.

Modifiez les notes dans la table ou changez la depuis l'interface QT pour ajuster la note d'un joueur.

Lorsque vous changez la note sur QT,vous devez refaire la commande :

    Select *from jeu;
    
Afin de voir les nouvelles notes.
    
