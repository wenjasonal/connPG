#include <stdio.h> 
#include <stdlib.h>
#include "libpq-fe.h"

static void
exit_nicely(PGconn *conn)
{
    PQfinish(conn);
    exit(1);
}

int main()
{
   // const char * const * keywords;
   // const char * const * values;
   // int                  expand_dbname;
    PGconn             *conn;

    const char * keywords[] = {"host", "port", "user", "password", "dbname", NULL};
    const char * values[] = {"10.136.1.143", "5432", "lww", "lww", "test", NULL};
    int expand_dbname = 0;

    fprintf(stderr, "host is '%s'\n", values[0]); //just test
    fprintf(stderr, "dbname is '%s'\n", values[4]); //just test

    conn = PQconnectdbParams(keywords, values, expand_dbname);
    if ( PQstatus(conn) == CONNECTION_BAD )
    {
       fprintf(stderr, "connection  to database '%s' in host '%s' failed!\n", values[4], values[0]);
       fprintf(stderr, PQerrorMessage(conn));
       exit_nicely(conn);
    }
    else
    {
       fprintf(stderr, "connection to database '%s' in host '%s' success!\n", values[4], values[0]);
       printf("connection OK!\n");
       exit_nicely(conn);
    }
    PQfinish(conn);
    return 0;
}
