#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include "../inc/sqlite3_client.h"
#include "../inc/delete_livre.h"

#ifndef _DELETE_LIVRE_
#define _DELETE_LIVRE_

static int compt;

static int callback_delete(void *NotUsed, int argc, char **argv, char **azColName) {
  int i;
  return 0;
}

static int set_existing_livre(void *NotUsed, int argc, char **argv, char **azColName) {
  compt = atoi(argv[0]);
  return 0;
}

void delete_livre() {
  char id_livre[11];
  sqlite3 *dbh;
  char *ErrMsg = 0;
  int con;

  printf("Entrez l'\033[1mIdentifiant du Livre\033[0m : ");
  scanf("%s", &id_livre);
  // clear_buffer();

  con = sqlite3_open(DB_FILE, &dbh);
  if(con) {
    fprintf(stderr, "\033[31mErreur SQLite3 :: \033[1m%s\033[0m\n", sqlite3_errmsg(dbh));
    exit(1);
  }

  // Check if the adherent hasn't already a book
  char Query0[100];
  sprintf(Query0, "SELECT COUNT(*) AS nb FROM livres WHERE id=%s;", id_livre);
  con = sqlite3_exec(dbh, Query0, set_existing_livre, 0, &ErrMsg);
  if( con != SQLITE_OK ) {
    fprintf(stderr, "\033[31mErreur SQL :: \033[1m%s\033[0m\n", ErrMsg);
    sqlite3_free(ErrMsg);
  }

  if(compt != 1) {
    printf("\033[31mDésolé, ce Livre n'existe pas ou plus.\n");
  } else {
    char Query[100];
    sprintf(Query, "DELETE FROM livres WHERE id=%s;", id_livre);
    // printf("Query : %s\n", Query);
    con = sqlite3_exec(dbh, Query, callback_delete, 0, &ErrMsg);
    if( con != SQLITE_OK ){
      fprintf(stderr, "\033[31mErreur SQL :: \033[1m%s\033[0m\n", ErrMsg);
      sqlite3_free(ErrMsg);
    } else {
      sprintf(Query, "DELETE FROM adherents_livres WHERE id_livre=%s;", id_livre);
      con = sqlite3_exec(dbh, Query, callback_delete, 0, &ErrMsg);
      fprintf(stdout, "\033[32mLe livre a bien été supprimé !\033[0m\n");
    }
  }

  sqlite3_close(dbh);
}
#endif
