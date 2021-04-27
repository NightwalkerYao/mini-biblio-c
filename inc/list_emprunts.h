/**
 * @file inc/list_emprunts.h 
 * @version 1.0
 * @brief Les prototypes des fonctions qui affichent la liste des Emprunts de Livres
 * @author [KOUASSI Yao Kan](https://about.me/nightwalker.y)
 * @date 25 Avril 2021
 **/

#include <sqlite3.h>
#include "sqlite3_client.h"
#include "fort.h"

static ft_table_t *table;
static int count_emprunts;

/**
 * @fn static int print_count_emprunts(void *NotUsed, int argc, char **argv, char **azColName)
 * @param NotUsed void * 
 * @param int argc 
 * @param argv char**
 * @param azColName char**
 * @return int 0
 * 
 * Callback pour la requete de comptage des Emprunts
 * 
 **/
static int print_count_emprunts(void *NotUsed, int argc, char **argv, char **azColName);

/**
 * @fn static int print_emprunts(void *NotUsed, int argc, char **argv, char **azColName)
 * @param NotUsed void * 
 * @param int argc 
 * @param argv char**
 * @param azColName char**
 * @return int 0
 * 
 * Callback pour la requete de selection et affichage des Emprunts
 * 
 **/
static int print_emprunts(void *NotUsed, int argc, char **argv, char **azColName);

/**
 * @fn void list_emprunts(void);
 * @param void 
 * @return void
 * 
 * Affiche la liste des Emprunts de Livres
 * 
 **/
void list_emprunts(void);
