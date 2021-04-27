/**
 * @file inc/main.h
 * @version 1.0
 * @brief Les prototypes des fonctions du point d'entrée du programme
 * @author [KOUASSI Yao Kan](https://about.me/nightwalker.y)
 * @date 25 Avril 2021
 * 
 * Contient les prototypes des fonctions du lib/main.c
 **/
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/**
 * Affiche un figlet (bannière) au démarrage du programme
 * 
 * @fn int figlet(void)
 * @brief Affichage de la bannière au lancement du programme
 * @param void
 * @return int 0
 **/
int figlet(void);

/**
 * @fn int print_menu(void)
 * @brief Affichage du menu principal du programme
 * @param void
 * @return int 0
 **/
int print_menu(void);

/**
 * @fn main(int argc, char* argv[])
 * @brief Le point d'entrée de l'application
 * 
 * Présente l'application et gère les actions de l'utilisateur
 * 
 * @param argc int Le nombre d'arguments+1 fournits à l'appel en ligne de commande
 * @param argv char** La liste des arguments fournits à l'appel en ligne de commande
 * @return int 
 **/
int main(int argc, char* argv[]);