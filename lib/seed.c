#include <sqlite3.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../inc/sqlite3_client.h"
#include "../inc/seed.h"

#ifndef _SEED_
#define _SEED_

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
  return 0;
}

void seed() {
  sqlite3 *dbh;
  char *zErrMsg = 0;
  int rc;
  rc = sqlite3_open(DB_FILE, &dbh);
  if(rc) {
    fprintf(stderr, "\033[31mErreur SQLite3 :: \033[1m%s\033[0m\n", sqlite3_errmsg(dbh));
    exit(1);
  }

  char *Query = "INSERT INTO livres(id, titre, auteur, editeur, resume, reference) VALUES\
  (NULL, 'Mastering C Programming in 7 days', 'Confused Programer', 'Packt Pub', 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.', '2366UT909'),\
  (NULL, 'La Ronde Des Jours', 'Bernard B. Dadie', 'CEDA', 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.', '9870IU67'),\
  (NULL, 'Zadig ou la Destinee', 'Voltaire', 'Belin', 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.', '23124TY090'),\
  (NULL, 'Rebelle', 'Fatou Keita', 'NEI', 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.', '08757HG9'),\
  (NULL, 'Never Trust Anyone!', 'Anonymous', 'Unknown', 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.', '9PYU67578'),\
  (NULL, 'Rui Blas', 'Victor Hugo', 'Nathan', 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.', '9PYU67548'),\
  (NULL, 'Hamlet', 'Shakespear', 'Flamarion', 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.', '956U67578'),\
  (NULL, 'La Voie de Ma Rue', 'Sylvain Kean Zo', 'Valesse', 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.', '9PYU67545');";

  // printf("SQL :: %s\n", Query);
  printf("Ajout des Livres...\n");
  rc = sqlite3_exec(dbh, Query, callback, 0, &zErrMsg);

  if( rc != SQLITE_OK ){
    fprintf(stderr, "\033[31mErreur SQL :: \033[1m%s\033[0m\n", zErrMsg);
    sqlite3_free(zErrMsg);
  } else {
    fprintf(stdout, "\033[32mLivres ajoutés avec succès !\033[0m\n");
  }

  Query = "INSERT INTO adherents(id, nom, contact, adresse) VALUES\
  (NULL, 'Touré Marie Rose', 'marie@rose.com', '545 Rue du commerce, Plateau'),\
  (NULL, 'Kouadio Louis', '07463242423', 'Yopougon Academie'),\
  (NULL, 'Sam Smith', '0145353409', '66000 CEDEX Paris'),\
  (NULL, 'Sanogo Ahmed', '0589324242', 'Adjamé 220 Logements'),\
  (NULL, 'Nanan Leblanc', '05656423423', 'BP 300 Issia'),\
  (NULL, 'Anabelle Dupont', '03229787908', 'Porte du Port, Marseille'),\
  (NULL, 'Blé Mathurin', '0753424240', 'Bouaké Air France'),\
  (NULL, 'Digbeu Steve', '04845352243', 'KM 4 Bvd Marseille Treichville');";

  printf("Ajout des Adhérents...\n");
  rc = sqlite3_exec(dbh, Query, callback, 0, &zErrMsg);

  if( rc != SQLITE_OK ){
    fprintf(stderr, "\033[31mErreur SQL :: \033[1m%s\033[0m\n", zErrMsg);
    sqlite3_free(zErrMsg);
  } else {
    fprintf(stdout, "\033[32mAdhérents ajoutés avec succès !\033[0m\n");
  }
  sqlite3_close(dbh);
}
#endif
