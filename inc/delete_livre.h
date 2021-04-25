#include <sqlite3.h>
#include "sqlite3_client.h"

static int callback_delete(void *NotUsed, int argc, char **argv, char **azColName);

static int set_existing_livre(void *NotUsed, int argc, char **argv, char **azColName);

void delete_livre();
