#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include "../inc/sqlite3_client.h"
#include "../inc/add_emprunt.h"

#ifndef _ADD_EMPRUNT_
#define _ADD_EMPRUNT_

static int compt;

static int callback_emprunt(void *NotUsed, int argc, char **argv, char **azColName) {
  return 0;
}

static int set_existing_emp(void *NotUsed, int argc, char **argv, char **azColName) {
  compt = atoi(argv[0]);
  return 0;
}

void add_emprunt() {
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
  printf("Entrez l'\033[1mIdentifiant de l'Adhérent\033[0m : ");
  fgets(id_adherent, 10, stdin);
  clear_buffer();
  printf("Entrez la \033[1mDate de retour\033[0m (Format : AAAA-mm-jj HH:mm:ss) : ");
  fgets(date_retour, 29, stdin);
  clear_buffer();

  con = sqlite3_open(DB_FILE, &dbh);
  if(con) {
    fprintf(stderr, "\033[31mErreur SQLite3 :: \033[1m%s\033[0m\n", sqlite3_errmsg(dbh));
    exit(1);
  }

  // Check if the adherent hasn't already a book
  char Query0[100];
  sprintf(Query0, "SELECT COUNT(*) AS nb FROM adherents_livres WHERE id_adherent=%d AND etat='emprunte';", atoi(id_adherent));
  con = sqlite3_exec(dbh, Query0, set_existing_emp, 0, &ErrMsg);
  if( con != SQLITE_OK ) {
    fprintf(stderr, "\033[31mErreur SQL :: \033[1m%s\033[0m\n", ErrMsg);
    sqlite3_free(ErrMsg);
  }

  if(compt > 0) {
    printf("\033[31mDésolé, cet Adhérent a déjà un Emprunt en cours.\nIl doit rendre le Livre précédent pour en prendre un nouveau.\n");
  } else {
    char Query[500];
    sprintf(Query, "INSERT INTO adherents_livres(id_adherent, id_livre, date_sortie, date_retour) VALUES('%s', '%s', datetime('now'), '%s');", id_adherent, id_livre, date_retour);
    // printf("Query : %s\n", Query);
    con = sqlite3_exec(dbh, Query, callback_emprunt, 0, &ErrMsg);
    if( con != SQLITE_OK ){
      fprintf(stderr, "\033[31mErreur SQL :: \033[1m%s\033[0m\n", ErrMsg);
      sqlite3_free(ErrMsg);
    } else {
      fprintf(stdout, "\033[32mEmprunt bien enregistré !\033[0m\n");
    }
  }

  sqlite3_close(dbh);
}
#endif
