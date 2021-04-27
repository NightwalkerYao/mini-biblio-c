/**
 * @file inc/find_adherent.h 
 * @version 1.0
 * @brief Les prototypes des fonctions qui recherchent des Adherents de la base de donnees
 * @author [KOUASSI Yao Kan](https://about.me/nightwalker.y)
 * @date 25 Avril 2021
 **/

#include <sqlite3.h>
#include "sqlite3_client.h"
#include "fort.h"

/**
 * @fn static int callback_find(void *NotUsed, int argc, char **argv, char **azColName)
 * @param NotUsed void * 
 * @param int argc 
 * @param argv char**
 * @param azColName char**
 * @return int 0
 * 
 * Callback pour la requete de recherche d'Adherent
 * 
 **/
static int callback_find(void *NotUsed, int argc, char **argv, char **azColName);

/**
 * @fn static int set_existing_adherent(void *NotUsed, int argc, char **argv, char **azColName)
 * @param NotUsed void * 
 * @param int argc 
 * @param argv char**
 * @param azColName char**
 * @return int 0
 * 
 * Callback pour la requete de verification de l'existence de l'Adherent en base de donnees
 * 
 **/
static int set_existing_adherent(void *NotUsed, int argc, char **argv, char **azColName);

/**
 * @fn void find_adherent(void)
 * @param void 
 * @return void
 * 
 * Recherche des adherents dans la base de donnees suivant les informations reçues interactivement
 * 
 **/
void find_adherent(void);
