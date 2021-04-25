#include <sqlite3.h>
#include "sqlite3_client.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName);

void seed();
