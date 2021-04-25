#include <sqlite3.h>

extern const char* DB_FILE;

void clear_buffer();

char *trim(char*);

sqlite3* connect();
