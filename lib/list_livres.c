#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include "../inc/fort.h"
#include "../inc/sqlite3_client.h"
#include "../inc/list_livres.h"

#ifndef _LIST_LIVRES_
#define _LIST_LIVRES_

static ft_table_t *table;
static int count_livres = 0;

static int print_count_livres(void *NotUsed, int argc, char **argv, char **azColName) {
  count_livres = atoi(argv[0]);
  if(count_livres > 0) {
    table = ft_create_table();
    /* Change border style */
    ft_set_border_style(table, FT_DOUBLE2_STYLE);

    /* Set "header" type for the first row */
    ft_set_cell_prop(table, 0, FT_ANY_COLUMN, FT_CPROP_ROW_TYPE, FT_ROW_HEADER);
    ft_write_ln(table, "ID", "REFERENCE", "TITRE", "AUTEUR", "EDITION");
  } else {
    printf("\033[1m Il n'y a aucun Livre pour le moment.\033[0m\n");
  }
  return 0;
}

static int print_livres(void *NotUsed, int argc, char **argv, char **azColName) {
  // id 0, titre 1, auteur 2, editeur 3, reference 4, resume 5
  ft_u8printf_ln(table, "%s|%s|%s|%s|%s", argv[0], argv[4], argv[1], argv[2], argv[3]);
  return 0;
}

void list_livres() {
  sqlite3 *dbh;
  char *ErrMsg = 0;
  int con;
  con = sqlite3_open(DB_FILE, &dbh);
  if(con) {
    fprintf(stderr, "\033[31mErreur SQLite3 :: \033[1m%s\033[0m\n", sqlite3_errmsg(dbh));
    exit(1);
  }
  char* Query_0 = "SELECT COUNT(*) AS nb FROM livres;";
  con = sqlite3_exec(dbh, Query_0, print_count_livres, 0, &ErrMsg);
  if( con != SQLITE_OK ){
    fprintf(stderr, "\033[31mErreur SQL :: \033[1m%s\033[0m\n", ErrMsg);
    sqlite3_free(ErrMsg);
  }
  char* Query = "SELECT id,REPLACE(titre, CHAR(10), '') AS titre, REPLACE(auteur, CHAR(10), '') AS auteur, REPLACE(editeur, CHAR(10), '') AS editeur, REPLACE(reference, CHAR(10), '') AS reference, REPLACE(resume, CHAR(10), '') AS resume FROM livres ORDER BY id ASC;";
  con = sqlite3_exec(dbh, Query, print_livres, 0, &ErrMsg);
  if( con != SQLITE_OK ){
    fprintf(stderr, "\033[31mErreur SQL :: \033[1m%s\033[0m\n", ErrMsg);
    sqlite3_free(ErrMsg);
  }
  if(count_livres > 0) {
    ft_set_cell_prop(table, FT_ANY_ROW, 5, FT_CPROP_TEXT_ALIGN, FT_ALIGNED_CENTER);
    printf("%s\n", ft_to_string(table));
    ft_destroy_table(table);
  }
  sqlite3_close(dbh);
}
#endif
