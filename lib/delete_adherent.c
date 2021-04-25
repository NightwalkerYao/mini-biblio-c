#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include "../inc/sqlite3_client.h"
#include "../inc/delete_adherent.h"

#ifndef _DELETE_ADHERENT_
#define _DELETE_ADHERENT_

static int compt;

static int callback_delete(void *NotUsed, int argc, char **argv, char **azColName) {
  int i;
  return 0;
}

static int set_existing_adherent(void *NotUsed, int argc, char **argv, char **azColName) {
  compt = atoi(argv[0]);
  return 0;
}

void delete_adherent() {
  char id_adherent[11];
  sqlite3 *dbh;
  char *ErrMsg = 0;
  int con;

  printf("Entrez l'\033[1mIdentifiant de L'Adhérent\033[0m : ");
  scanf("%s", &id_adherent);
  // clear_buffer();

  con = sqlite3_open(DB_FILE, &dbh);
  if(con) {
    fprintf(stderr, "\033[31mErreur SQLite3 :: \033[1m%s\033[0m\n", sqlite3_errmsg(dbh));
    exit(1);
  }

  // Check if the adherent hasn't already a book
  char Query0[100];
  sprintf(Query0, "SELECT COUNT(*) AS nb FROM adherents WHERE id=%s;", id_adherent);
  con = sqlite3_exec(dbh, Query0, set_existing_adherent, 0, &ErrMsg);
  if( con != SQLITE_OK ) {
    fprintf(stderr, "\033[31mErreur SQL :: \033[1m%s\033[0m\n", ErrMsg);
    sqlite3_free(ErrMsg);
  }

  if(compt != 1) {
    printf("\033[31mDésolé, cet Adhérent n'existe pas ou plus.\n");
  } else {
    char Query[100];
    sprintf(Query, "DELETE FROM adherents WHERE id=%s;", id_adherent);
    // printf("Query : %s\n", Query);
    con = sqlite3_exec(dbh, Query, callback_delete, 0, &ErrMsg);
    if( con != SQLITE_OK ){
      fprintf(stderr, "\033[31mErreur SQL :: \033[1m%s\033[0m\n", ErrMsg);
      sqlite3_free(ErrMsg);
    } else {
      sprintf(Query, "DELETE FROM adherents_livres WHERE id_adherent=%s;", id_adherent);
      con = sqlite3_exec(dbh, Query, callback_delete, 0, &ErrMsg);
      fprintf(stdout, "\033[32mL'Adhérent a bien été supprimé !\033[0m\n");
    }
  }

  sqlite3_close(dbh);
}
#endif
