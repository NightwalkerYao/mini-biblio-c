#include <sqlite3.h>
#include "sqlite3_client.h"
#include "fort.h"

static ft_table_t *table;
static int count_adherents;

static int print_count_adherents(void *NotUsed, int argc, char **argv, char **azColName);

static int print_adherents(void *NotUsed, int argc, char **argv, char **azColName);

void list_adherents();
