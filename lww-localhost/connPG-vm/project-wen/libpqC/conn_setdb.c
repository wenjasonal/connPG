#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libpq-fe.h"

static void
exit_nicely(PGconn *conn)
{
    PQfinish(conn);
    exit(1);
}

int main()
{
 const char    *pghost,
               *pgport,
               *pgoptions,
               *pgtty;
 const char    *dbName;
 const char    *login,
               *pwd;

    PGconn     *conn;
    PGresult   *res;

    pghost = "10.136.1.143";       /* host name of the backend server */
    pgport = "5432";            /* port of the backend server */
    pgoptions = NULL;           /* special options to start up the backend server */
    pgtty = NULL;               /* debugging tty for the backend server */
    dbName = "test";            /* change this to the name of your test database */
    login = "lww";     //login = getenv("PGUSER"); /*fprintf(stderr, "login user is '%s'\n", login);*/
    pwd = "lww";    // pwd = getenv("PGPWD");     /*fprintf(stderr, "login user password is '%s'\n", pwd);*/
    //conn = PQsetdb(pghost, pgport, pgoptions, pgtty, dbName);  /*fprintf(stderr, "login user is '%s'\n", login);*/
    conn = PQsetdbLogin(pghost, pgport, pgoptions, pgtty, dbName, login, pwd);

    if (PQstatus(conn) == CONNECTION_BAD)
    {
        fprintf(stderr, "Connection to database '%s' in host '%s' failed.\n", dbName, pghost);
        fprintf(stderr, "%s", PQerrorMessage(conn));
        exit_nicely(conn);
    }
    else
    {
        fprintf(stderr, "Connection to database '%s' in host '%s' success.\n", dbName, pghost);
        printf("connection OK\n");
        exit_nicely(conn);
    }		   
 
    PQfinish(conn);
    return 0;
}
