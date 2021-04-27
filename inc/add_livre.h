/**
 * @file inc/add_livre.h 
 * @version 1.0
 * @brief Les prototypes des fonctions qui gèrent l'ajout d'un nouveau Livre
 * @author [KOUASSI Yao Kan](https://about.me/nightwalker.y)
 * @date 25 Avril 2021
 **/

#include <sqlite3.h>
#include "sqlite3_client.h"

/**
 * @fn static int callback(void *NotUsed, int argc, char **argv, char **azColName)
 * 
 * Callback pour la requete d'enregistrement d'un nouveau livre
 * 
 * @param NotUsed void * 
 * @param int argc 
 * @param argv char**
 * @param azColName char**
 * @return int 0
 **/
static int callback(void *NotUsed, int argc, char **argv, char **azColName);

/**
 * @fn void add_livre()
 * @param void 
 * @return void
 * 
 * Enregistre un nouveau Livre dans la base de donnees. Les informations du Livre sont 
 * demandees de façon interactive
 * 
 **/
void add_livre(void);
