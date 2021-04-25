#include <sqlite3.h>
#include "sqlite3_client.h"
#include "fort.h"

static int callback_find(void *NotUsed, int argc, char **argv, char **azColName);

static int set_existing_adherent(void *NotUsed, int argc, char **argv, char **azColName);

void find_adherent();
