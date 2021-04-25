/**
 * @file inc/add_adherent.h 
 * @brief Contient les prototypes des fonctions qui gèrent l'ajout d'un nouvel Adhérent
 * @author [KOUASSI Yao Kan](https://about.me/nightwalker.y)
 * @date 25 Avril 2021
 **/
#include <sqlite3.h>
#include "sqlite3_client.h"

/**
 * Callback exécutée à la requête d'ajout
 * @param NotUsed void * 
 * @param int argc 
 * @param argv char**
 * @param azColName char**
 **/
static int callback(void *NotUsed, int argc, char **argv, char **azColName);

void add_adherent();
