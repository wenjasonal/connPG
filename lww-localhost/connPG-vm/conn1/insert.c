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
   
    if (argc > 1)
        conninfo = argv[1];
    else
        conninfo = "host=127.0.0.1 dbname=test user=lww password=lww port=5432";
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

//测试 --
 else fprintf(stderr, "BEGIN\n");
    /*调用PQclear在PQresult的游标不再使用后清除游标，防止内存溢出 */
  PQclear(res);
//测试 --
 PQexec(conn,"drop table test1");

    /* 建立一个叫test1的表 */
   res = PQexec(conn,"create table test1 (name char(20),age int4)");
   if(PQresultStatus(res) != PGRES_COMMAND_OK)
   {
    fprintf(stderr, "create table failed: %s!", PQerrorMessage(conn));
    PQclear(res);
    exit_nicely(conn);
    }
   else fprintf(stderr, "create table success!\n");
   PQclear(res);

    /* 插入数据 */
    res = PQexec(conn,"insert into test1 values ('cjm',10)");
    if(PQresultStatus(res) != PGRES_COMMAND_OK)
    {
      fprintf(stderr, "insert fail: %s!", PQerrorMessage(conn));
      PQclear(res);
      exit_nicely(conn);
     }
    else fprintf(stderr, "insert success!\n");
    PQclear(res);

    res = PQexec(conn,"insert into test1 values ('eight',20)");
    if(PQresultStatus(res) != PGRES_COMMAND_OK)
    {
      fprintf(stderr, "insert fail: %s!", PQerrorMessage(conn));
      PQclear(res);
      exit_nicely(conn);
     }
    else fprintf(stderr, "insert success!\n");
    PQclear(res);
/*//？此句插入时报错？insert fail:ERROR:  Could not begin transaction on data node.
    res = PQexec(conn,"insert into test1 values ('linuxaid',30)");
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
    printf("all the data is:\n");
/*    res = PQexec(conn, "select * from test1");
    if(PQresultStatus(res)!= PGRES_COMMAND_OK)
    {
      fprintf(stderr, "select fail: %s!", PQerrorMessage(conn));
      PQclear(res);
      exit_nicely(conn);
     }
    else
    {
     fprintf(stderr, "select success!\n");
     for (i = 0; i < PQntuples(res); i++)
     {
      for (j = 0; j < PQnfields(res); j++)
          printf("%-15s", PQgetvalue(res, i, j));
      printf("\n\n");
      }
     }
    PQclear(res);
*/
    res = PQexec(conn, "DECLARE myportal CURSOR FOR select * from test1");
    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        fprintf(stderr, "DECLARE CURSOR failed: %s", PQerrorMessage(conn));
        PQclear(res);
        exit_nicely(conn);
    }
    PQclear(res);

    res = PQexec(conn, "FETCH ALL in myportal");
    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        fprintf(stderr, "FETCH ALL failed: %s", PQerrorMessage(conn));
        PQclear(res);
        exit_nicely(conn);
    }
    
        /* first, print out the attribute names */
    nFields = PQnfields(res);
    for (i = 0; i < nFields; i++)
        printf("%-15s", PQfname(res, i));
    printf("\n\n");

    /* next, print out the rows */
    for (i = 0; i < PQntuples(res); i++)
    {
        for (j = 0; j < nFields; j++)
            printf("%-15s", PQgetvalue(res, i, j));
        printf("\n");
    } 
    PQclear(res);

    /* close the portal ... we don't bother to check for errors ... */
    res = PQexec(conn, "CLOSE myportal");
    PQclear(res);

    /* end the transaction */
    res = PQexec(conn, "END");
    PQclear(res);
 
    /* 使用SQL的update函数 */
  //  PQexec(conn,"update test1 set age=25 where name='eight'");
    /* 打印出更新后的数据 */
  //  printf("the new date is:\n");
  //  res = PQexec(conn, "select * from test1");
  /*  for (i = 0; i < PQntuples(res); i++)
    {
      for (j = 0; j < PQnfields(res); j++)
          printf("%-15s", PQgetvalue(res, i, j));
      printf("\n\n");
      }
    PQclear(res);
  */
    /* 删除表 */
//    PQexec(conn,"drop table test1");
    /* 关闭和数据库的连接 */
    PQfinish(conn);
    return 0;
}
