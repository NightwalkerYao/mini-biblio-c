/**
 * @file inc/add_emprunt.h 
 * @version 1.0
 * @brief Les prototypes des fonctions qui gèrent l'ajout d'un nouvel Emprunt
 * @author [KOUASSI Yao Kan](https://about.me/nightwalker.y)
 * @date 25 Avril 2021
 **/
#include <sqlite3.h>
#include "sqlite3_client.h"

/**
 * @fn static int callback_emprunt(void *NotUsed, int argc, char **argv, char **azColName)
 * 
 * Callback pour la requete d'enregistrement de l'emprunt
 * 
 * @param NotUsed void * 
 * @param int argc 
 * @param argv char**
 * @param azColName char**
 * @return int 0
 **/
static int callback_emprunt(void *NotUsed, int argc, char **argv, char **azColName);

/**
 * @fn static int set_existing_emp(void *NotUsed, int argc, char **argv, char **azColName)
 * @param NotUsed void * 
 * @param int argc 
 * @param argv char**
 * @param azColName char**
 * @return int 0
 * 
 * Callback pour la requete d'enregistrement de l'emprunt
 * 
 **/
static int set_existing_emp(void *NotUsed, int argc, char **argv, char **azColName);

/**
 * @fn void add_emprunt()
 * @param void 
 * @return void
 * 
 * Enregistre un nouvel Emprunt dans la base de donnees. Les informations de l'Emprunt sont 
 * demandees de façon interactive
 * 
 **/
void add_emprunt(void);
