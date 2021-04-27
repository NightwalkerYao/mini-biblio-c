#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include "../inc/sqlite3_client.h"
#include "../inc/back_emprunt.h"

#ifndef _BACK_EMPRUNT_
#define _BACK_EMPRUNT_

int compt;

static int callback_back_emprunt(void *NotUsed, int argc, char **argv, char **azColName) {
  return 0;
}

static int set_existing_emp_to_back(void *NotUsed, int argc, char **argv, char **azColName) {
  compt = atoi(argv[0]);
  return 0;
}

void back_emprunt() {
  char id_livre[11];
  char id_adherent[11];
  // char date_sortie[30];
  char date_retour[30];
  sqlite3 *dbh;
  char *ErrMsg = 0;
  int con;

  printf("Entrez l'\033[1mIdentifiant du Livre\033[0m : ");
  fgets(id_livre, 10, stdin);
  clear_buffer();
  printf("Entrez l'\033[1mIdentifiant de l'Adherent\033[0m : ");
  fgets(id_adherent, 10, stdin);
  clear_buffer();

  con = sqlite3_open(DB_FILE, &dbh);
  if(con) {
    fprintf(stderr, "\033[31mErreur SQLite3 :: \033[1m%s\033[0m\n", sqlite3_errmsg(dbh));
    exit(1);
  }

  // Check if the adherent hasn't already a book
  char Query0[100];
  sprintf(Query0, "SELECT COUNT(*) AS nb FROM adherents_livres WHERE id_adherent=%d AND etat='emprunte';", atoi(id_adherent));
  con = sqlite3_exec(dbh, Query0, set_existing_emp_to_back, 0, &ErrMsg);
  if( con != SQLITE_OK ){
    fprintf(stderr, "\033[31mErreur SQL :: \033[1m%s\033[0m\n", ErrMsg);
    sqlite3_free(ErrMsg);
  }

  if(compt < 1) {
    printf("\033[1;31mDésolé, cet Adhérent n'a pas d'Emprunt en cours.\033[0m\n");
  } else {
    char Query[150];
    sprintf(Query, "UPDATE adherents_livres SET date_retour=datetime('now'), etat='%s' WHERE id_adherent='%s' AND id_livre='%s';", "rendu", id_adherent, id_livre);
    // printf("Query : %s\n", Query);
    con = sqlite3_exec(dbh, Query, callback_back_emprunt, 0, &ErrMsg);
    if( con != SQLITE_OK ){
      fprintf(stderr, "\033[31mErreur SQL :: \033[1m%s\033[0m\n", ErrMsg);
      sqlite3_free(ErrMsg);
    } else {
      fprintf(stdout, "\033[32mLe Livre a bien été rendu !\033[0m\n");
    }
  }

  sqlite3_close(dbh);
}
#endif
