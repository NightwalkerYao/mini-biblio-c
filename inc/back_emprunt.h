/**
 * @file inc/back_emprunt.h 
 * @version 1.0
 * @brief Les prototypes des fonctions qui gèrent le retour d'un Livre
 * @author [KOUASSI Yao Kan](https://about.me/nightwalker.y)
 * @date 25 Avril 2021
 **/
#include <sqlite3.h>
#include "sqlite3_client.h"

/**
 * @fn static int callback_back_emprunt(void *NotUsed, int argc, char **argv, char **azColName)
 * @param NotUsed void * 
 * @param int argc 
 * @param argv char**
 * @param azColName char**
 * @return int 0
 * 
 * Callback pour la requete d'enregistrement du retour de livre
 * 
 **/
static int callback_back_emprunt(void *NotUsed, int argc, char **argv, char **azColName);

/**
 * @fn static int set_existing_emp_to_back(void *NotUsed, int argc, char **argv, char **azColName)
 * @param NotUsed void * 
 * @param int argc 
 * @param argv char**
 * @param azColName char**
 * @return int 0
 * 
 * Callback pour la requete la verification de l'existence de l'Emprunt
 * 
 **/
static int set_existing_emp_to_back(void *NotUsed, int argc, char **argv, char **azColName);

/**
 * @fn void back_emprunt()
 * @param void 
 * @return void
 * 
 * Enregistre le retour du Livre en base de donnees
 * 
 **/
void back_emprunt();
