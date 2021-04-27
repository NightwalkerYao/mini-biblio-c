/**
 * @file inc/delete_livre.h 
 * @version 1.0
 * @brief Les prototypes des fonctions qui suppriment des Livres de la base de donnees
 * @author [KOUASSI Yao Kan](https://about.me/nightwalker.y)
 * @date 25 Avril 2021
 **/

#include <sqlite3.h>
#include "sqlite3_client.h"

/**
 * @fn static int callback_delete(void *NotUsed, int argc, char **argv, char **azColName)
 * @param NotUsed void * 
 * @param int argc 
 * @param argv char**
 * @param azColName char**
 * @return int 0
 * 
 * Callback pour la requete de suppression de livre
 * 
 **/
static int callback_delete(void *NotUsed, int argc, char **argv, char **azColName);

/**
 * @fn static int set_existing_livre(void *NotUsed, int argc, char **argv, char **azColName)
 * @param NotUsed void * 
 * @param int argc 
 * @param argv char**
 * @param azColName char**
 * @return int 0
 * 
 * Callback pour la requete de verification de l'existence du Livre en base de donnees
 * 
 **/
static int set_existing_livre(void *NotUsed, int argc, char **argv, char **azColName);

/**
 * @fn void delete_livre(void)
 * @param void 
 * @return void
 * 
 * Supprime des livres de la base de donnees suivant les informations de livres fournies interactivement
 * 
 **/
void delete_livre(void);
