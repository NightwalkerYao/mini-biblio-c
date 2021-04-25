/**
 * @file main.c 
 * @brief Le point d'entrée de l'application
 * Contient la définition de la fonction principale, gère la logique de toute l'application 
 * et les interactions avec l'utilisateur.
 * @author [KOUASSI Yao Kan](https://about.me/nightwalker.y)
 * @date 25 Avril 2021
 **/

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "inc/add_adherent.h"
#include "inc/add_emprunt.h"
#include "inc/add_livre.h"
#include "inc/back_emprunt.h"
#include "inc/delete_adherent.h"
#include "inc/delete_livre.h"
#include "inc/find_adherent.h"
#include "inc/find_livre.h"
#include "inc/fort.h"
#include "inc/list_adherents.h"
#include "inc/list_emprunts.h"
#include "inc/list_livres.h"
#include "inc/seed.h"
#include "./inc/sqlite3_client.h"

/**
 * Affiche un figlet au démarrage de l'application
 * @param void
 * @return int 0
 **/
int figlet(void) {
  printf("\
\t88                        88888888ba  88 88          88 88              \n\
\t88                        88      \"8b \"\" 88          88 \"\"              \n\
\t88                        88      ,8P    88          88                 \n\
\t88          ,adPPYYba,    88aaaaaa8P' 88 88,dPPYba,  88 88  ,adPPYba,   \n\
\t88          \"\"     `Y8    88\"\"\"\"\"\"8b, 88 88P'    \"8a 88 88 a8\"     \"8a  \n\
\t88          ,adPPPPP88    88      `8b 88 88       d8 88 88 8b       d8  \n\
\t88          88,    ,88    88      a8P 88 88b,   ,a8\" 88 88 \"8a,   ,a8\"  \n\
\t88888888888 `\"8bbdP\"Y8    88888888P\"  88 8Y\"Ybbd8\"'  88 88  `\"YbbdP\"\n");
  return 0;
}

/**
 * Affiche le menu principale de l'application
 * @param void
 * @return int 0
 **/
int print_menu(void) {
  printf("\n\tBIENVENUE DANS LE GESTIONNAIRE DE \033[1;36mLA BIBLIOTHEQUE v1.0\033[0m\n");
  printf("\n\t\033[33;1mVoici une liste de ce que vous pouvez faire\033[0m\n\n");
  printf("\t\033[1;35mEMPRUNTS\033[0m\n\
          \033[1;34m1\033[0m. Ajouter un Emprunt\n\
          \033[1;34m2\033[0m. Lister les Emprunts\n\
          \033[1;34m3\033[0m. Rendre un Emprunt\n");
  printf("\t\033[1;35mADHERENTS\033[0m\n\
          \033[1;34m4\033[0m. Ajouter un Adhérent\n\
          \033[1;34m5\033[0m. Lister les Adhérents\n\
          \033[1;34m6\033[0m. Rechercher des Adhérents\n\
          \033[1;34m7\033[0m. Supprimer un Adhérent\n");
  printf("\t\033[1;35mLIVRES\033[0m\n\
          \033[1;34m8\033[0m. Ajouter un Livre\n\
          \033[1;34m9\033[0m. Lister les Livres\n\
          \033[1;34m10\033[0m. Rechercher des Livres\n\
          \033[1;34m11\033[0m. Supprimer un Livre\n");
  printf("\t\033[1;35mDIVERS\033[0m\n\
          \033[1;34m12\033[0m. Tester la connexion à la BDD\n\
          \033[1;34m13\033[0m. Seeder la BDD\n\n");
  return 0;
}

/**
 * Le point d'entrée de l'application
 * Présente l'application et gère les actions de l'utilisateur
 * @param argc int Le nombre d'arguments+1 fournits à l'appel en ligne de commande
 * @param argv char** La liste des arguments fournits à l'appel en ligne de commande
 * @return int
 **/
int main(int argc, char* argv[]) {
  figlet();
  char choice[15], continuer = 'O';
  int ichoice, c;
  do {
    print_menu();
    do {
      printf("Votre choix : ");
      scanf("%s", choice);
      while (1) {
        c = getchar();
        if (c == '\n')
        break;
      }
      ichoice = atoi(choice);
      if(strcmp(trim(choice), "quitter") == 0 || strcmp(trim(choice), "Quitter") == 0) {
        continuer = 'N';
        printf("Sortie de l'application...\n");
        sleep(1);
        exit(0);
      } else if(!(ichoice >= 1 && ichoice <= 13)) {
        printf("\033[31mErreur :: \033[1mChoix non disponible\033[0m\n");
      }  
    } while (!(ichoice >= 1 && ichoice <= 13));

    if(continuer == 'O' || continuer == 'o') {
      switch (ichoice) {
        case 1:
          printf("Ajout d'un Emprunt : \n");
          add_emprunt();
          break;
        case 2:
          printf("Liste des Emprunts : \n");
          list_emprunts();
          break;
        case 3:
          printf("Rendre un Livre : \n");
          back_emprunt();
          break;
        case 4:
          printf("Ajout d'un Adhérent : \n");
          add_adherent();
          break;
        case 5:
          printf("Liste des Adhérents : \n");
          list_adherents();
          break;
        case 6:
          printf("Recherche d'Adhérents : \n");
          find_adherent();
          break;
        case 7:
          printf("Suppression d'Adhérent : \n");
          delete_adherent();
          break;
        case 8:
          printf("Ajout de Livre : \n");
          add_livre();
          break;
        case 9:
          printf("Liste des Livres : \n");
          list_livres();
          break;
        case 10:
          printf("Recherche de Livres : \n");
          find_livre();
          break;
        case 11:
          printf("Suppression de Livre : \n");
          delete_livre();
          break;
        case 12:
          printf("Test de la connexion à la BDD : \n");
          connect();
          break;
        case 13:
          printf("Population de la BDD avec des Livres et des Adhérents : \n");
          seed();
          break;
      }
    }    
    printf("Voulez-vous faire autre chose ? (O/N) ");
    scanf("%c", &continuer);
    while (1) {
      c = getchar();
      if (c == '\n')
      break;
    }
  } while (continuer == 'O' || continuer == 'o');
  
  printf("Sortie de l'application...\n");
  sleep(1);
  exit(0);
}