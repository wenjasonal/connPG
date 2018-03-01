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
  
const char *paramValues[2];
int paramLength[2];
int paramFormat[2];
//uint32_t binaryIntVal;
 
    if (argc > 1)
        conninfo = argv[1];
    else
        conninfo = "host=10.136.1.32 dbname=singlefdw user=postgres password=postgres port=5432";
        //conninfo = "host=10.50.6.83 dbname=test user=lww password=lww port=5432";
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


    /* 插入数据 */
 /* res = PQexec(conn,"insert into organ values ('77','testCode')");
    if(PQresultStatus(res) != PGRES_COMMAND_OK)
    {
      fprintf(stderr, "insert fail: %s!", PQerrorMessage(conn));
      PQclear(res);
      exit_nicely(conn);
     }
    else fprintf(stderr, "insert success!\n");
    PQclear(res);
*/
    /* 开始查询 */
paramValues[0]="33";
paramValues[1]="lwwtest";
res = PQexecParams(conn,
                  "insert into organ values($1, $2)",
                  2,
                  NULL,
                  paramValues,
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
    PQclear(res);

    /* end the transaction */
    res = PQexec(conn, "END");
    PQclear(res);
 
    PQfinish(conn);
    return 0;
}
