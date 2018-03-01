#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

static void exit_nicely(PGconn *conn)
{
   PQfinish(conn);
   exit(1);
 }

int main(int argc, char **argv)
{
   const char *conninfo;    
   PGconn     *conn;
   PGresult   *res;
   int         i,
               j;

   if (argc > 1)
      conninfo = argv[1];
   else
      conninfo = "host=10.136.2.45 port=25432 user=lww password=lww dbname=test";

   //connect db server
   conn = PQconnectdb(conninfo);
   //check connection 
   if (PQstatus(conn) == CONNECTION_BAD)
   {
      fprintf(stderr, "connection to database fail.\n");
      fprintf(stderr, "%s", PQerrorMessage(conn));
      exit_nicely(conn);
    }
   else 
   {
      fprintf(stderr, "connection to %s success.\n", conninfo);
      printf("connection OK.\n");
    }

   //start a transaction 
   res = PQexec(conn, "BEGIN");
   if (!res || PQresultStatus(res) != PGRES_COMMAND_OK)
   {
      fprintf(stderr, "BEGIN command failed.\n");
      PQclear(res);
      exit_nicely(conn);
    }
  
   PQclear(res);
   
   PQexec(conn, "drop table test2");//multi-test!!
   PQexec(conn, "create table test2(id int, name varchar(20), age int)");//create table
   //insert
   PQexec(conn, "insert into test2 values(1, 'Zhao', 16)");
   PQexec(conn, "insert into test2 values(2, 'Qian', 17)");
   PQexec(conn, "insert into test2 values(3, 'Sun',  18)");
   PQexec(conn, "insert into test2 values(4, 'Li',   19)");
 
   //output the insert data
   printf("All the data is:\n");

   res = PQexec(conn, "DECLARE myportal CURSOR FOR select * from test2");
   if (!res || PQresultStatus(res) != PGRES_COMMAND_OK)
   {
      fprintf(stderr, "DECLARE CURSOR failed: %s.\n", PQerrorMessage(conn));
      PQclear(res);
      exit_nicely(conn);
    }
   PQclear(res);
   res = PQexec(conn, "FETCH ALL in myportal");
   if (!res || PQresultStatus(res) != PGRES_TUPLES_OK)
   {
      fprintf(stderr, "FETCH ALL failed: %s.\n", PQerrorMessage(conn));
      PQclear(res);
      exit_nicely(conn);
    }
/*   res = PQexec(conn, "select * from test2");
   if(!res || PQresultStatus(res) != PGRES_COMMAND_OK)
   {
      fprintf(stderr, "select failed: %s.\n", PQerrorMessage(conn));
      PQclear(res);
      exit_nicely(conn);
    }
*/   
   //output attribute name
   for(i = 0; i < PQnfields(res); i++)
     printf("%-15s", PQfname(res, i));
   
   printf("\n\n");
   
   //output selection rows
   for(i = 0; i < PQntuples(res); i++)
   {
     for(j =0; j < PQnfields(res); j++)
       printf("%-15s", PQgetvalue(res, i, j));
     printf("\n");
    }
   PQclear(res);
 //close cursor
   res = PQexec(conn, "CLOSE myportal");
   PQclear(res);
 
  //delete
  PQexec(conn, "delete from test2 where age=18");
  //update
  PQexec(conn, "update test2 set age=20 where age=17");
 //print the new data
   printf("The new data is: \n");
   res = PQexec(conn, "DECLARE myportal CURSOR FOR select * from test2");
   if (!res || PQresultStatus(res) != PGRES_COMMAND_OK)
   {
      fprintf(stderr, "DECLARE CURSOR failed: %s.\n", PQerrorMessage(conn));
      PQclear(res);
      exit_nicely(conn);
    }
   PQclear(res);
   res = PQexec(conn, "FETCH ALL in myportal");
   if (!res || PQresultStatus(res) != PGRES_TUPLES_OK)
   {
      fprintf(stderr, "FETCH ALL failed: %s.\n", PQerrorMessage(conn));
      PQclear(res);
      exit_nicely(conn);
    }
     //output attribute name
   for(i = 0; i < PQnfields(res); i++)
     printf("%-15s", PQfname(res, i));

   printf("\n\n");

   //output selection rows
   for(i = 0; i < PQntuples(res); i++)
   {
     for(j =0; j < PQnfields(res); j++)
       printf("%-15s", PQgetvalue(res, i, j));
     printf("\n");
    }
   PQclear(res);
 //close cursor
   res = PQexec(conn, "CLOSE myportal");
   PQclear(res);

  //commit the transaction
   res = PQexec(conn, "COMMIT");
   PQclear(res);

  //close database connection
   PQfinish(conn);
   return 0;
 }
