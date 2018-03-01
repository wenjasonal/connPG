#include <stdio.h>
#include <stdlib.h>
#include "libpq-fe.h"
int main()
{
PGconn *conn;
const char *conn_str="host=10.136.2.45 dbname=test user=lww password=lww port=25432";
conn=PQconnectdb(conn_str);
if(PQstatus(conn)==CONNECTION_BAD)
{
fprintf(stderr,"connection to %s failed\n",conn_str);
PQerrorMessage(conn);
}
else 
{fprintf(stderr,"connection to %s success\n",conn_str);
printf("connection ok\n");
}
PQfinish(conn);
return EXIT_SUCCESS;
}
