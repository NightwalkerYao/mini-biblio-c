/**
 * @file inc/delete_adherent.h 
 * @version 1.0
 * @brief Les prototypes des fonctions qui suppriment des Adherent de la base de donnees
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
 * Callback pour la requete de suppression d'adherent
 * 
 **/
static int callback_delete(void *NotUsed, int argc, char **argv, char **azColName);

/**
 * @fn static int set_existing_adherent(void *NotUsed, int argc, char **argv, char **azColName)
 * @param NotUsed void * 
 * @param int argc 
 * @param argv char**
 * @param azColName char**
 * @return int 0
 * 
 * Callback pour la requete de verification de l'existence de l'adherent en base de donnees
 * 
 **/
static int set_existing_adherent(void *NotUsed, int argc, char **argv, char **azColName);

/**
 * @fn void delete_adherent()
 * @param void 
 * @return void
 * 
 * Supprime des adherents de la base de donnees suivant les informations des adherents fournies interactivement
 * 
 **/
void delete_adherent();
