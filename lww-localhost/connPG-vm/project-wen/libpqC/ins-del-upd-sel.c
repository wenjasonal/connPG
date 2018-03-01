#include <stdio.h>
#include <stdlib.h>
#include "libpq-fe.h"

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


  conninfo="host=10.136.1.143 dbname=test user=lww password=lww port=5432";
  conn=PQconnectdb(conninfo);
  if(PQstatus(conn)==CONNECTION_BAD)
  {
    fprintf(stderr,"connection to %s failed\n",conninfo);
    PQerrorMessage(conn);
  }
  else
  {
    fprintf(stderr,"connection to %s success\n",conninfo);
    printf("connection ok\n");
  }
  
    /* 开始处理数据块 */
  res = PQexec(conn, "BEGIN");
  if (!res || PQresultStatus(res) != PGRES_COMMAND_OK)
  {
     fprintf(stderr, "BEGIN command failed\n");
     PQclear(res);
     exit_nicely(conn);
   }
   //测试
  PQexec(conn,"drop table test1");
  /* 建立一个叫test1的表 */
  PQexec(conn,"create table test1 (name char(20),age int4)");
  /* 插入数据 */
  PQexec(conn, "insert into test1 values ('cjmall',10)");
  PQexec(conn, "insert into test1 values ('eightall',20)");
  PQexec(conn, "insert into test1 values ('justtest',30)");
  /* 开始查询 */
  printf("All the data is:\n");
  //运用游标进行查询操作
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

  /*删除数据*/
  res = PQexec(conn, "delete from test1 where name='justtest'");
  PQclear(res);

  /* 使用SQL的update函数 */
  PQexec(conn,"update test1 set age=25 where name='eightall'");
  /* 打印出更新后的数据 */
  printf("\n\nThe new data is:\n");
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


  /* commit the transaction */
  res = PQexec(conn, "COMMIT");
  PQclear(res);

  PQfinish(conn);
  return EXIT_SUCCESS;
}

