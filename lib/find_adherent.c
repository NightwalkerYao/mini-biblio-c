#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include "../inc/sqlite3_client.h"
#include "../inc/fort.h"
#include "../inc/find_adherent.h"

#ifndef _FIND_ADHERENT_
#define _FIND_ADHERENT_

static int compt;
static ft_table_t *table;

static int callback_find(void *NotUsed, int argc, char **argv, char **azColName) {
  ft_u8printf_ln(table, "%s|%s|%s|%s", argv[0], argv[1], argv[2], argv[3]);
  return 0;
}

static int set_existing_adherent(void *NotUsed, int argc, char **argv, char **azColName) {
  compt = atoi(argv[0]);
  return 0;
}

void find_adherent() {
  int find_by, c;
  char *col;
  do {
    printf("Rechercher avec :\n");
    printf("\033[1m\033[34m1\033[0m. L'Identifiant\033[0m\n");
    printf("\033[1m\033[34m2\033[0m. Le Nom\033[0m\n");
    printf("Votre choix : ");
    scanf("%d", &find_by);
    while (1) {
      c = getchar();
      if (c == '\n')
      break;
    }
    if(find_by != 1 && find_by != 2) {
      printf("\033[31mErreur :: \033[1mChoix non disponible\033[0m\n");
    }
  } while (find_by != 1 && find_by != 2);

  switch (find_by) {
    case 1:
    col = "id";
    break;
    default:
    col = "nom";
    break;
  }


  char q[100];
  sqlite3 *dbh;
  char *ErrMsg = 0;
  int con;

  printf("Entrez \033[1mvotre recherche\033[0m : ");
  fgets(q, 99, stdin);
  clear_buffer();
  con = sqlite3_open(DB_FILE, &dbh);
  if(con) {
    fprintf(stderr, "\033[31mErreur SQLite3 :: \033[1m%s\033[0m\n", sqlite3_errmsg(dbh));
    exit(1);
  }

  // Check if the adherent hasn't already a book
  char Query0[100];
  if(find_by == 1)
  sprintf(Query0, "SELECT COUNT(*) AS nb FROM adherents WHERE %s='%s';", col, trim(q));
  else
  sprintf(Query0, "SELECT COUNT(*) AS nb FROM adherents WHERE %s LIKE '%%%s%';", col, trim(q));
  // printf("Requete :: %s\n", Query0);
  con = sqlite3_exec(dbh, Query0, set_existing_adherent, 0, &ErrMsg);
  if( con != SQLITE_OK ) {
    fprintf(stderr, "\033[31mErreur SQL 1 :: \033[1m%s\033[0m\n", ErrMsg);
    sqlite3_free(ErrMsg);
  }

  if(compt == 0) {
    printf("\033[31mDésolé, nous n'avons rien trouvé pour votre recherche.\n");
  } else {
    table = ft_create_table();
    /* Change border style */
    ft_set_border_style(table, FT_DOUBLE2_STYLE);

    /* Set "header" type for the first row */
    ft_set_cell_prop(table, 0, FT_ANY_COLUMN, FT_CPROP_ROW_TYPE, FT_ROW_HEADER);
    ft_write_ln(table, "ID", "NOM", "CONTACT", "ADRESSE");
    char Query[200];
    if(find_by == 1) {
      sprintf(Query, "SELECT id,REPLACE(nom, CHAR(10), '') AS nom, REPLACE(contact, CHAR(10), '') AS contact, REPLACE(adresse, CHAR(10), '') AS adresse FROM adherents WHERE %s=%s ORDER BY id ASC;", col, trim(q));
    } else {
      sprintf(Query, "SELECT id,REPLACE(nom, CHAR(10), '') AS nom, REPLACE(contact, CHAR(10), '') AS contact, REPLACE(adresse, CHAR(10), '') AS adresse FROM adherents WHERE %s LIKE '%%%s%' ORDER BY id ASC;", col, trim(q));
    }
    // printf("Query : %s\n", Query);
    con = sqlite3_exec(dbh, Query, callback_find, 0, &ErrMsg);
    if( con != SQLITE_OK ){
      fprintf(stderr, "\033[31mErreur SQL 2 :: \033[1m%s\033[0m\n", ErrMsg);
      sqlite3_free(ErrMsg);
    } else {
      ft_set_cell_prop(table, FT_ANY_ROW, 4, FT_CPROP_TEXT_ALIGN, FT_ALIGNED_CENTER);
      printf("%s\n", ft_to_string(table));
      ft_destroy_table(table);
    }
  }

  sqlite3_close(dbh);
}
#endif
