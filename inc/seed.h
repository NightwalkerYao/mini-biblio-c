/**
 * @file inc/seed.h 
 * @version 1.0
 * @brief Enregistrement des Livres et des Adherents aleatoires
 * @author [KOUASSI Yao Kan](https://about.me/nightwalker.y)
 * @date 25 Avril 2021
 **/

#include <sqlite3.h>
#include "sqlite3_client.h"

/**
 * Callback exécutée à la requête de seed
 * 
 * @fn static int callback(void *NotUsed, int argc, char **argv, char **azColName)
 * @param NotUsed void * 
 * @param int argc 
 * @param argv char**
 * @param azColName char**
 * @return int 0
 **/
static int callback(void *NotUsed, int argc, char **argv, char **azColName);

/**
 * Enregistre des Livres et des Adherents predefinis, pour des raisons de test
 * 
 * @fn void seed(void)
 * @param void
 * @return void
 **/
void seed(void);
