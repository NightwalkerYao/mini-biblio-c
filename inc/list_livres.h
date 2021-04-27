/**
 * @file inc/list_livres.h 
 * @version 1.0
 * @brief Les prototypes des fonctions qui affichent la liste des Livres
 * @author [KOUASSI Yao Kan](https://about.me/nightwalker.y)
 * @date 25 Avril 2021
 **/

#include <sqlite3.h>
#include "sqlite3_client.h"
#include "fort.h"

static ft_table_t *table;
static int count_livres;

/**
 * @fn static int print_count_livres(void *NotUsed, int argc, char **argv, char **azColName)
 * @param NotUsed void * 
 * @param int argc 
 * @param argv char**
 * @param azColName char**
 * @return int 0
 * 
 * Callback pour la requete de comptage des Livres
 * 
 **/
static int print_count_livres(void *NotUsed, int argc, char **argv, char **azColName);

/**
 * @fn static int print_livres(void *NotUsed, int argc, char **argv, char **azColName)
 * @param NotUsed void * 
 * @param int argc 
 * @param argv char**
 * @param azColName char**
 * @return int 0
 * 
 * Callback pour la requete de selection et affichage des Livres
 * 
 **/
static int print_livres(void *NotUsed, int argc, char **argv, char **azColName);

/**
 * @fn void list_livres(void)
 * @param void 
 * @return void
 * 
 * Affiche la liste des Livres de la base de donnees
 * 
 **/
void list_livres(void);
