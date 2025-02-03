
# Documentation Technique Détaillée du Projet R-TYPE

## Introduction

Le projet **R-TYPE** est un jeu de type **shoot 'em up** développé en utilisant l'architecture **Entity-Component-System** (ECS). Le projet est divisé en plusieurs modules distincts, chacun ayant des responsabilités bien définies. Ce document est destiné aux développeurs travaillant sur le projet, et explique l'architecture, la compilation, l'organisation des fichiers, les rôles des différents modules et systèmes, ainsi que la manière dont le tout fonctionne ensemble.

## Architecture du Projet

### Structure de Dossiers

Le projet est organisé en plusieurs dossiers avec une séparation claire entre les composants du serveur, du client, et du moteur ECS. Voici la structure de base du projet :

- **`ecs/`** : Le cœur de l'architecture ECS. Contient les fichiers d'entité, de composants et de systèmes.
    - **`include/`** : Les fichiers d'en-tête des différents composants, systèmes et gestionnaires du moteur ECS.
    - **`src/`** : Les fichiers source du moteur ECS, où la logique est implémentée.

- **`server/`** : Le module serveur, responsable de la gestion des entités du serveur, des vagues d'ennemis, et de la logique de réseau.
    - **`src/`** : Le fichier principal (`main.cpp`) et les systèmes spécifiques au serveur.

- **`client/`** : Le module client, qui gère la communication avec le serveur, l'affichage du jeu, et les interactions avec le joueur.
    - **`src/`** : Le fichier principal (`main.cpp`) et les systèmes liés à l'affichage et à la gestion de la connexion au serveur.

### Architecture ECS

L'architecture ECS est basée sur trois concepts principaux : **Entités**, **Composants**, et **Systèmes**. Cette approche sépare clairement les données et la logique, permettant une grande flexibilité et extensibilité.

1. **Entity (Entité)** : Une entité représente un objet du jeu (ex : joueur, ennemi, balle). Les entités n'ont pas de données par elles-mêmes mais contiennent des composants qui définissent leur état.

2. **Component (Composant)** : Un composant représente une caractéristique ou une donnée liée à une entité (par exemple : position, texture, vitesse, santé). Chaque entité peut posséder plusieurs composants.

3. **System (Système)** : Un système est responsable de la logique qui manipule les entités en fonction de leurs composants. Les systèmes sont souvent responsables des mises à jour de l'état du jeu (par exemple : un système de mouvement, de rendu, de gestion des collisions, etc.).

Cette architecture permet de gérer de manière efficace et modulaire les différentes parties du jeu, avec une séparation claire des responsabilités.

## Rôles des Différents Modules

### Le Moteur ECS

Le moteur ECS dans le dossier **`ecs/`** est responsable de la gestion des entités et des composants du jeu, ainsi que de l'exécution des systèmes.

#### `EntityManager` (Gestion des Entités)

`EntityManager` est une classe centrale dans l'architecture ECS. Elle est responsable de la création et de la gestion des entités et de leurs composants.

- Créer une entité : `entityManager.createEntity()`
- Ajouter un composant à une entité : `entityManager.addComponent<component::Position>(entity, x, y)`

Les entités sont créées sans logique propre et sont associées à différents composants. Ces composants sont ensuite utilisés par les systèmes pour appliquer des transformations ou des comportements.

#### `SystemManager` (Gestion des Systèmes)

`SystemManager` est responsable de la gestion de tous les systèmes du jeu. Il permet d’ajouter, de mettre à jour, et de gérer l’exécution des différents systèmes.

- Ajouter un système : `systemManager.addSystem<systems::Movement>(entityManager, server)`

Les systèmes sont mis à jour chaque frame et peuvent interagir avec les entités en fonction de leurs composants.

#### `Composants`

Les composants sont des structures de données simples qui contiennent des informations spécifiques à une entité. Quelques exemples de composants incluent :

- **Position** : Contient les coordonnées d'une entité.
- **Texture** : Contient le chemin vers l'image associée à une entité.
- **Enemie** : Représente un ennemi dans le jeu, avec sa santé, ses caractéristiques, etc.

### Le Serveur

Le serveur, contenu dans le dossier **`server/`**, gère la logique principale du serveur de jeu. Il est responsable de la gestion des connexions, de l’envoi et de la réception des données entre le client et le serveur, et de la gestion des entités du serveur (comme les ennemis, les vagues, etc.).

Le serveur gère les vagues d'ennemis en les créant et en les envoyant aux clients. Cela se fait par l’intermédiaire de fonctions comme `spawnEntity()` dans le fichier `Server.cpp` :

```cpp
void spawnEntity(ecs::Entity &entity, float x, float y, const std::string &texture) {
    // Fonction pour envoyer les données d'entité au client
}
```

### Le Client

Le client, contenu dans le dossier **`client/`**, est responsable de l'affichage du jeu et de la gestion de l'interface utilisateur. Le client se connecte au serveur, reçoit les entités à afficher et interagit avec l’utilisateur.

Le client utilise **SFML** pour afficher les graphiques, gérer les entrées, et afficher les entités sur l'écran. Il se connecte au serveur en utilisant un socket TCP/UDP et reçoit les données des entités à chaque cycle de mise à jour.

```cpp
systemManager.addSystem<systems::Client>(entityManager, sf::IpAddress(serverID), serverPort, display);
```

Cela initialise un système client qui va permettre de se connecter au serveur et de récupérer les informations nécessaires pour afficher les entités sur l'écran.

## Compilation du Projet

### Prérequis

- **CMake** : Le projet utilise **CMake** comme système de compilation. Il est donc nécessaire d’avoir **CMake** installé sur votre machine.
- **SFML** : La bibliothèque **SFML** est utilisée pour la gestion de l’affichage et des entrées utilisateur.

### Compilation

1. **Cloner le dépôt** :

```bash
git clone https://github.com/matheo2027/R-Type
cd R-TYPE
```

2. **Compiler le projet** :

```bash
./CompileLinux.sh
```

3. **Exécuter le serveur et le client** :

Pour démarrer le serveur :
```bash
./build/server/r-type_server <port>
```

Pour démarrer le client :
```bash
./build/client/r-type_client <server_address> <port>
```

## Démarrage du Serveur

Le serveur est responsable de la gestion de l’état global du jeu. Il écoute les connexions des clients, crée les vagues d'ennemis, et envoie les informations nécessaires aux clients. Le serveur est lancé en exécutant `main.cpp` dans le dossier `server/` :

```cpp
int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <server port>" << std::endl;
        return 1;
    }

    int port = std::stoi(argv[1]);
    ecs::EntityManager entityManager;
    ecs::SystemManager systemManager;

    systemManager.addSystem<systems::Server>(entityManager, port);
    systems::Server &server = systemManager.getSystem<systems::Server>();
    // ...
}
```

Le serveur initialise les entités de fond et gère la création des vagues d'ennemis sur une base temporelle.

## Démarrage du Client

Le client se connecte au serveur et commence à afficher le jeu via **SFML**. Il est lancé en exécutant `main.cpp` dans le dossier `client/` :

```cpp
int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <server address> <server port>" << std::endl;
        return 1;
    }

    try {
        std::string serverID = argv[1];
        unsigned short serverPort = std::stoi(argv[2]);
        // Connexion et gestion de l'affichage...
    } catch (const std::exception &e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 84;
    }
}
```

Le client se connecte au serveur, initialise le rendu graphique, et met à jour l'affichage à chaque cycle.

## Conclusion

Le projet **R-TYPE** démontre l'utilisation d'une architecture ECS dans le cadre d'un jeu multijoueur de type shoot 'em up. Grâce à la séparation des responsabilités entre entités, composants et systèmes, il est facile d’ajouter de nouvelles fonctionnalités et de gérer la logique du jeu de manière modulaire. Le serveur et le client sont clairement séparés, ce qui permet une gestion simple des connexions réseau et des entités du jeu.

Le code est conçu pour être extensible et maintenable, avec des systèmes et des composants qui peuvent être ajoutés ou modifiés indépendamment les uns des autres.

## Plan d’Amélioration

- Ajout d’un système de gestion de la physique pour les collisions.
- Ajout de nouveaux types d’ennemis et de power-ups.
- Amélioration de la gestion des performances pour supporter un plus grand nombre d’entités.
