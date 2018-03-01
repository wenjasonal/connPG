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
    int         nFields;
    int         i,
                j;
  
const char *paramValues_ins[2],*paramValues_upd[2], *paramValues_del[1], *paramValues_sel[1];
int paramLength_ins[2], paramLength_upd[2], paramLength_del[1], paramLength_sel[1];
int paramFormat_ins[2], paramFormat_upd[2], paramFormat_del[1], paramFormat_sel[1];

//uint32_t binaryIntVal;
 
    if (argc > 1)
        conninfo = argv[1];
    else
        conninfo = "host=10.136.2.85 dbname=singlefdw user=postgres password=postgres port=5432";
   /* 连接数据库服务器*/
   conn = PQconnectdb(conninfo);
   /* 检查连接是否成功 */
   if (PQstatus(conn) == CONNECTION_BAD)
   {
      fprintf(stderr, "Connection to database failed.");
      fprintf(stderr, "%s", PQerrorMessage(conn));
      exit_nicely(conn);
     }
//测试 -- 
   else
   {
    fprintf(stderr,"connection to %s success\n",conninfo);
    printf("connection ok\n");
    }

    /* 开始处理数据块 */
    res = PQexec(conn, "BEGIN");
    if (!res || PQresultStatus(res) != PGRES_COMMAND_OK)
    {
       fprintf(stderr, "BEGIN command failed");
       PQclear(res);
       exit_nicely(conn);
      }


    /*insert no parameter*/
/* 
 res = PQexec(conn,"insert into organ values ('77','testCode')");
    if(PQresultStatus(res) != PGRES_COMMAND_OK)
    {
      fprintf(stderr, "insert fail: %s!", PQerrorMessage(conn));
      PQclear(res);
      exit_nicely(conn);
     }
    else fprintf(stderr, "insert success!\n");

    printf("Affectted ROWS :%15s\n", PQcmdTuples(res));
    PQclear(res);
*/
    /*insert */
paramValues_ins[0]=""; //not null -- error
paramValues_ins[1]="testCodeInsert";
res = PQexecParams(conn,
                  "insert into organ values($1, $2)",
                  2,
                  NULL,
                  paramValues_ins,
                  NULL,
                  NULL,
                  1
                  );
 if(PQresultStatus(res) != PGRES_COMMAND_OK)
    {
      fprintf(stderr, "insert fail: %s!", PQerrorMessage(conn));
      PQclear(res);
      exit_nicely(conn);
     }
    else fprintf(stderr, "insert success!\n");
    printf("Affectted ROWS :%15s\n", PQcmdTuples(res));
    PQclear(res);

/*update*/
/*
paramValues_upd[0]="88";
paramValues_upd[1]="770";//not exist --error
res = PQexecParams(conn,
                   "update organ set organcode=$1 where organcode=$2",
                   2,
                   NULL,
                   paramValues_upd,
                   NULL,
                   NULL,
                   1 
                  );
 if(PQresultStatus(res) != PGRES_COMMAND_OK)
    {
      fprintf(stderr, "update fail: %s!", PQerrorMessage(conn));
      PQclear(res);
      exit_nicely(conn);
     }
    else fprintf(stderr, "update success!\n");
   
    printf("Affectted ROWS :%15s\n", PQcmdTuples(res));
    PQclear(res);
*/
/*delete*/
/*
paramValues_del[0]="88"; //not exist -- error
res = PQexecParams(conn,
                   "delete from organ where organcode=$1",
                   1,
                   NULL,
                   paramValues_del,
                   NULL,
                   NULL,
                   1
                  );
if(PQresultStatus(res) != PGRES_COMMAND_OK)
    {
      fprintf(stderr, "delete fail: %s!", PQerrorMessage(conn));
      PQclear(res);
      exit_nicely(conn);
     }
    else fprintf(stderr, "delete success!\n");

  printf("Affectted ROWS :%15s\n", PQcmdTuples(res));  
  PQclear(res);
*/
/*select*/
/*
paramValues_sel[0] = "addr";//not exist -- error
res = PQexecParams(conn,
                   "select * from organ where address=$1",
                   1,
                   NULL,
                   paramValues_sel,
                   NULL,
                   NULL,
                   0//1
                  );
if(PQresultStatus(res) != PGRES_TUPLES_OK)
 {
      fprintf(stderr, "select fail: %s!", PQerrorMessage(conn));
      PQclear(res);
      exit_nicely(conn);
     }

//show_binary_results(res); //.h

//print out the attribute names
nFields = PQnfields(res);
for(i=0; i<nFields; i++)
   printf("%-15s", PQfname(res,i));
printf("\n\n");
 //print out the rows selected
for(i=0; i<PQntuples(res); i++)
{  
  for(j=0; j<nFields; j++)
     printf("%-15s", PQgetvalue(res, i, j));
  printf("\n");
 }
//PQclear(res);
 //PGcmdTuples
printf("Affectted ROWS :%15s\n", PQcmdTuples(res));
PQclear(res);
*/
    /* end the transaction */
    res = PQexec(conn, "END");
    PQclear(res);
 
    PQfinish(conn);
    return 0;
}
