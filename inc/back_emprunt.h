#include <sqlite3.h>
#include "sqlite3_client.h"

static int callback_back_emprunt(void *NotUsed, int argc, char **argv, char **azColName);

static int set_existing_emp_to_back(void *NotUsed, int argc, char **argv, char **azColName);

void back_emprunt();
