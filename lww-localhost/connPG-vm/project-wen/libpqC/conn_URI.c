#include <stdio.h>
#include <stdlib.h>
#include "libpq-fe.h"
int main()
{
  PGconn *conn;
//  const char *conn_str="host=127.0.0.1 dbname=test user=lww password=lww port=5432";
  const char *conn_str="postgresql://lww:lww@127.0.0.1:5432/test";
  conn=PQconnectdb(conn_str);
  if(PQstatus(conn)==CONNECTION_BAD)
  {
    fprintf(stderr,"connection to %s failed\n",conn_str);
    PQerrorMessage(conn);
    //PQreset(conn); //reconnect
  }
  else 
  {
    fprintf(stderr,"connection to %s success\n",conn_str);
    printf("connection ok\n");
  }
  PQfinish(conn);
  return EXIT_SUCCESS;
}
