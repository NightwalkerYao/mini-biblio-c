#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include "../inc/fort.h"
#include "../inc/sqlite3_client.h"
#include "../inc/list_adherents.h"

#ifndef _LIST_ADHERENTS_
#define _LIST_ADHERENTS_

static ft_table_t *table;
static int count_adherents = 0;

static int print_count_adherents(void *NotUsed, int argc, char **argv, char **azColName) {
  count_adherents = atoi(argv[0]);
  if(count_adherents > 0) {
    table = ft_create_table();
    /* Change border style */
    ft_set_border_style(table, FT_DOUBLE2_STYLE);

    /* Set "header" type for the first row */
    ft_set_cell_prop(table, 0, FT_ANY_COLUMN, FT_CPROP_ROW_TYPE, FT_ROW_HEADER);
    ft_write_ln(table, "ID", "NOM", "CONTACT", "ADRESSE");
  } else {
    printf("\033[1m Il n'y a aucun Adhérent pour le moment.\033[0m\n");
  }
  return 0;
}

static int print_adherents(void *NotUsed, int argc, char **argv, char **azColName) {
  ft_u8printf_ln(table, "%s|%s|%s|%s", argv[0], argv[1], argv[2], argv[3]);
  return 0;
}

void list_adherents() {
  sqlite3 *dbh;
  char *ErrMsg = 0;
  int con;
  con = sqlite3_open(DB_FILE, &dbh);
  if(con) {
    fprintf(stderr, "\033[31mErreur SQLite3 :: \033[1m%s\033[0m\n", sqlite3_errmsg(dbh));
    exit(1);
  }
  char* Query_0 = "SELECT COUNT(*) AS nb FROM adherents;";
  con = sqlite3_exec(dbh, Query_0, print_count_adherents, 0, &ErrMsg);
  if( con != SQLITE_OK ){
    fprintf(stderr, "\033[31mErreur SQL :: \033[1m%s\033[0m\n", ErrMsg);
    sqlite3_free(ErrMsg);
  }
  char* Query = "SELECT id,REPLACE(nom, CHAR(10), '') AS nom, REPLACE(contact, CHAR(10), '') AS contact, REPLACE(adresse, CHAR(10), '') AS adresse FROM adherents ORDER BY id ASC;";
  con = sqlite3_exec(dbh, Query, print_adherents, 0, &ErrMsg);
  if( con != SQLITE_OK ){
    fprintf(stderr, "\033[31mErreur SQL :: \033[1m%s\033[0m\n", ErrMsg);
    sqlite3_free(ErrMsg);
  }
  if(count_adherents > 0) {
    ft_set_cell_prop(table, FT_ANY_ROW, 4, FT_CPROP_TEXT_ALIGN, FT_ALIGNED_CENTER);
    printf("%s\n", ft_to_string(table));
    ft_destroy_table(table);
  }
  sqlite3_close(dbh);
}
#endif
