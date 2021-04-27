#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include "../inc/sqlite3_client.h"
#include "../inc/add_livre.h"

#ifndef _ADD_LIVRE_
#define _ADD_LIVRE_

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
  return 0;
}

void add_livre() {
  char titre[160];
  char auteur[100];
  char editeur[100];
  char resume[500];
  char reference[30];
  sqlite3 *dbh;
  char *ErrMsg = 0;
  int con;

  printf("Entrez la \033[1mRéférence (ISBN)\033[0m : ");
  fgets(reference, 29, stdin);
  clear_buffer();
  printf("Entrez le \033[1mTitre du livre\033[0m : ");
  fgets(titre, 160, stdin);
  clear_buffer();
  printf("Entrez le \033[1mNom de l'Auteur\033[0m : ");
  fgets(auteur, 100, stdin);
  clear_buffer();
  printf("Entrez le nom de la \033[1mMaison d'Edition\033[0m : ");
  fgets(editeur, 100, stdin);
  clear_buffer();
  printf("Entrez le \033[1mResumé\033[0m : ");
  fgets(resume, 254, stdin);
  clear_buffer();

  con = sqlite3_open(DB_FILE, &dbh);
  if(con) {
    fprintf(stderr, "\033[31mErreur SQLite3 :: \033[1m%s\033[0m\n", sqlite3_errmsg(dbh));
    exit(1);
  }
  char Query[500];
  sprintf(Query, "INSERT INTO livres(id, titre, auteur, editeur, resume, reference) VALUES(NULL, '%s', '%s', '%s', '%s', '%s');", titre, auteur, editeur, resume, reference);
  // printf("Query : %s\n", Query);
  con = sqlite3_exec(dbh, Query, callback, 0, &ErrMsg);
  if( con != SQLITE_OK ){
    fprintf(stderr, "\033[31mErreur SQL :: \033[1m%s\033[0m\n", ErrMsg);
    sqlite3_free(ErrMsg);
  } else {
    fprintf(stdout, "\033[32mLe Livre a bien été enregistré !\033[0m\n");
  }
  sqlite3_close(dbh);
}
#endif
