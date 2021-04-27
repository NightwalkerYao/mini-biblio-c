#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include "../inc/sqlite3_client.h"
#include "../inc/fort.h"
#include "../inc/list_emprunts.h"

#ifndef _LIST_EMPRUNTS_
#define _LIST_EMPRUNTS_

static ft_table_t *table;
static int count_emprunts = 0;

static int print_count_emprunts(void *NotUsed, int argc, char **argv, char **azColName) {
  count_emprunts = atoi(argv[0]);
  if(count_emprunts > 0) {
    table = ft_create_table();
    /* Change border style */
    ft_set_border_style(table, FT_DOUBLE2_STYLE);

    /* Set "header" type for the first row */
    ft_set_cell_prop(table, 0, FT_ANY_COLUMN, FT_CPROP_ROW_TYPE, FT_ROW_HEADER);
    ft_write_ln(table, "ADHERENT", "LIVRE", "AUTEUR", "DATE DE SORTIE", "DATE DE RETOUR", "ETAT");
  } else {
    printf("\033[1m Il n'y a aucun Emprunt pour le moment.\033[0m\n");
  }
  return 0;
}

static int print_emprunts(void *NotUsed, int argc, char **argv, char **azColName) {
  // id_adherent 0, id_livre 1, date_sortie 2, date_retour 3, etat 4, nom_adherent 5, titre_livre 6, auteur_livre 7
  if(strcmp(argv[4], "emprunte") == 0) {
    ft_u8printf_ln(table, "[%s]%s|[%s]%s|%s|%s|%s|%s", argv[0], argv[5], argv[1], argv[6], argv[7], argv[2], argv[3], "Non Rendu");
  } else {
    ft_u8printf_ln(table, "[%s]%s|[%s]%s|%s|%s|%s|%s", argv[0], argv[5], argv[1], argv[6], argv[7], argv[2], argv[3], "Rendu");
  }
  return 0;
}

void list_emprunts() {
  sqlite3 *dbh;
  char *ErrMsg = 0;
  int con;
  con = sqlite3_open(DB_FILE, &dbh);
  if(con) {
    fprintf(stderr, "\033[31mErreur SQLite3 :: \033[1m%s\033[0m\n", sqlite3_errmsg(dbh));
    exit(1);
  }
  char* Query_0 = "SELECT COUNT(*) AS nb FROM adherents_livres;";
  con = sqlite3_exec(dbh, Query_0, print_count_emprunts, 0, &ErrMsg);
  if( con != SQLITE_OK ){
    fprintf(stderr, "\033[31mErreur SQL :: \033[1m%s\033[0m\n", ErrMsg);
    sqlite3_free(ErrMsg);
  }
  char* Query = "SELECT al.id_adherent AS id_adherent, al.id_livre AS id_livre, al.date_sortie AS date_sortie, REPLACE(al.date_retour, CHAR(10), '') AS date_retour, REPLACE(al.etat, CHAR(10), '') AS etat, REPLACE(a.nom, CHAR(10), '') AS nom_adherent, REPLACE(l.titre, CHAR(10), '') AS titre_livre, REPLACE(l.auteur, CHAR(10), '') AS auteur_livre FROM adherents_livres al LEFT JOIN adherents a ON al.id_adherent=a.id LEFT JOIN livres l ON al.id_livre=l.id ORDER BY al.date_sortie ASC;";
  con = sqlite3_exec(dbh, Query, print_emprunts, 0, &ErrMsg);
  if( con != SQLITE_OK ){
    fprintf(stderr, "\033[31mErreur SQL :: \033[1m%s\033[0m\n", ErrMsg);
    sqlite3_free(ErrMsg);
  }
  if(count_emprunts > 0) {
    ft_set_cell_prop(table, FT_ANY_ROW, 6, FT_CPROP_TEXT_ALIGN, FT_ALIGNED_CENTER);
    printf("%s\n", ft_to_string(table));
    ft_destroy_table(table);
  }
  sqlite3_close(dbh);
}
#endif
