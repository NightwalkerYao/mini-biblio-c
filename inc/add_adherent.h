/**
 * @file inc/add_adherent.h 
 * @version 1.0
 * @brief Les prototypes des fonctions qui gèrent l'ajout d'un nouvel Adhérent
 * @author [KOUASSI Yao Kan](https://about.me/nightwalker.y)
 * @date 25 Avril 2021
 **/
#include <sqlite3.h>
#include "sqlite3_client.h"

/**
 * Callback exécutée à la requête d'ajout
 * 
 * @param NotUsed void * 
 * @param int argc 
 * @param argv char**
 * @param azColName char**
 * @return int 0
 **/
static int callback(void *NotUsed, int argc, char **argv, char **azColName);

/**
 * Ajoute un nouvel Adherent à la base de données en demandant ses infos de façon interactive
 * 
 * @fn void add_adherent(void)
 * @param void
 * @return void
 **/
void add_adherent(void);
