#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include "../inc/sqlite3_client.h"
#include "../inc/add_adherent.h"

#ifndef _ADD_ADHERENT_
#define _ADD_ADHERENT_

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
  return 0;
}

void add_adherent() {
  char nom[100];
  char contact[100];
  char adresse[100];
  sqlite3 *dbh;
  char *ErrMsg = 0;
  int con;

  printf("Entrez le \033[1mNom et le Prénom\033[0m : ");
  fgets(nom, 99, stdin);
  clear_buffer();
  printf("Entrez le \033[1mContact\033[0m : ");
  fgets(contact, 99, stdin);
  clear_buffer();
  printf("Entrez l'\033[1mAdresse\033[0m : ");
  fgets(adresse, 99, stdin);
  clear_buffer();

  con = sqlite3_open(DB_FILE, &dbh);
  if(con) {
    fprintf(stderr, "\033[31mErreur SQLite3 :: \033[1m%s\033[0m\n", sqlite3_errmsg(dbh));
    exit(1);
  }
  char Query[500];
  sprintf(Query, "INSERT INTO adherents(id, nom, contact, adresse) VALUES(NULL, '%s', '%s', '%s');", nom, contact, adresse);
  // printf("Query : %s\n", Query);
  con = sqlite3_exec(dbh, Query, callback, 0, &ErrMsg);
  if( con != SQLITE_OK ){
    fprintf(stderr, "\033[31mErreur SQL :: \033[1m%s\033[0m\n", ErrMsg);
    sqlite3_free(ErrMsg);
  } else {
    fprintf(stdout, "\033[32mL'Adhérent a été ajouté avec succès !\033[0m\n");
  }
  sqlite3_close(dbh);
}
#endif
