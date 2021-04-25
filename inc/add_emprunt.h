#include <sqlite3.h>
#include "sqlite3_client.h"

static int callback_emprunt(void *NotUsed, int argc, char **argv, char **azColName);

static int set_existing_emp(void *NotUsed, int argc, char **argv, char **azColName);

void add_emprunt();
