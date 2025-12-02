# 🧮 C++ Object-Oriented Calculator

> Un moteur de calcul arithmétique modulaire implémentant un pipeline de compilation complet (Lexer, Parser, Interpreter) en C++ moderne.

## 📖 À propos

Ce projet a pour objectif de concevoir une calculatrice robuste capable d'évaluer des **expressions mathématiques pleinement parenthésées**. Contrairement à une approche procédurale simpliste, ce programme simule le fonctionnement d'un compilateur en construisant un **Arbre Syntaxique Abstrait (AST)** avant l'évaluation.

Le projet a été développé dans un contexte de simulation d'intégration système (type "Windows 1.0"), mettant l'accent sur la gestion de la mémoire et l'architecture logicielle.

## 🚀 Fonctionnalités

* **Analyse Lexicale (Tokenisation) :** Découpage précis des chaînes de caractères en tokens typés (Opérateurs, Opérandes, Délimiteurs).
* **Support des Opérateurs :**
    * Binaires : Addition `+`, Soustraction `-`, Multiplication `*`, Division `/`.
    * Unaires : Négation `-`.
* **Priorité des opérations :** Gestion stricte de l'ordre de calcul via le parenthésage complet.
* **Architecture Extensible :** Ajout facile de nouveaux opérateurs grâce au pattern Factory.

## 🛠 Architecture Technique

Le projet repose sur une conception Orientée Objet stricte et l'utilisation intensive de la **STL (Standard Template Library)**.

### 1. Le Pipeline de Traitement
Le calcul suit trois étapes distinctes :
1.  **Lexer :** Transforme l'input utilisateur (ex: `((2+3)*5)`) en un `std::vector` de tokens.
2.  **Parser :** Utilise l'algorithme "Shunting Yard" modifié avec deux `std::stack` (une pour les opérateurs, une pour les opérandes) pour construire l'arbre d'expression.
3.  **Interpreter :** Parcourt l'arbre récursivement pour calculer le résultat final.

### 2. Design Patterns utilisés
* **Interpreter Pattern :** Chaque nœud de l'arbre hérite d'une classe abstraite `Expression` et possède sa propre méthode `interpret()`.
* **Factory Pattern (`OperatorFactory`) :** Centralise l'instanciation des objets opérateurs (ex: `PlusBinaryOp`, `MinusBinaryOp`) pour découpler la logique de création du parser.
* **Composite Pattern :** Traite les opérations complexes et les nombres simples de manière uniforme via une interface commune.

### 3. Structures de données (STL)
* `std::vector` : Stockage dynamique des tokens.
* `std::stack` : Gestion LIFO pour le parsing et la résolution des parenthèses imbriquées.
* `std::map` : Table de hachage associant les symboles (char) aux types d'opérateurs.

## 💻 Installation et Utilisation

### Prérequis
* Un compilateur C++ compatible (G++, Clang, MSVC).
* Make (optionnel).

### Compilation
```bash
g++ -o calculator main.cpp src/*.cpp -I include
