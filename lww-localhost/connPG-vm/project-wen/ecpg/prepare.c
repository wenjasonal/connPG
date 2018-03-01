/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "prepare.pgc"
#include<stdlib.h>

int main()
{
  void print_sqlca();
  /* exec sql whenever sqlerror  call print_sqlca ( ) ; */
#line 6 "prepare.pgc"


  { ECPGconnect(__LINE__, 0, "tcp:postgresql://10.136.1.143:5432/test" , "lww" , "lww" , NULL, 0); 
#line 8 "prepare.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 8 "prepare.pgc"


  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "drop table test_pre2", ECPGt_EOIT, ECPGt_EORT);
#line 10 "prepare.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 10 "prepare.pgc"
 //multi-test!
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "drop table test_pre1", ECPGt_EOIT, ECPGt_EORT);
#line 11 "prepare.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 11 "prepare.pgc"
 //multi-test!
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "create table test_pre1 ( sid int primary key , sname varchar ( 20 ) , addr varchar ( 40 ) )", ECPGt_EOIT, ECPGt_EORT);
#line 12 "prepare.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 12 "prepare.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "create table test_pre2 ( cid int primary key , cname varchar ( 20 ) , csid int references test_pre1 ( sid ) )", ECPGt_EOIT, ECPGt_EORT);
#line 13 "prepare.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 13 "prepare.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into test_pre1 values ( 1 , 'Json' , 'address1' )", ECPGt_EOIT, ECPGt_EORT);
#line 14 "prepare.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 14 "prepare.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into test_pre1 values ( 2 , 'Wang' , 'address2' )", ECPGt_EOIT, ECPGt_EORT);
#line 15 "prepare.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 15 "prepare.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into test_pre1 values ( 3 , 'Gill' , 'address3' )", ECPGt_EOIT, ECPGt_EORT);
#line 16 "prepare.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 16 "prepare.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into test_pre2 values ( 101 , '语文' , 1 )", ECPGt_EOIT, ECPGt_EORT);
#line 17 "prepare.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 17 "prepare.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into test_pre2 values ( 102 , '数学' , 2 )", ECPGt_EOIT, ECPGt_EORT);
#line 18 "prepare.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 18 "prepare.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into test_pre2 values ( 103 , '英语' , 3 )", ECPGt_EOIT, ECPGt_EORT);
#line 19 "prepare.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 19 "prepare.pgc"

  { ECPGtrans(__LINE__, NULL, "commit");
#line 20 "prepare.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 20 "prepare.pgc"

  
  /* exec sql begin declare section */
       
       
       
       
       
      
       
       
     
     
     
     
     
  
#line 23 "prepare.pgc"
 char * stmt = "select cid, cname, sid, sname, addr from test_pre1, test_pre2 where sid=csid" ;
 
#line 24 "prepare.pgc"
 char * stmt1 = "select cid, cname, sid, sname, addr from test_pre1, test_pre2 where sid=csid and sname=?" ;
 
#line 25 "prepare.pgc"
 char * cntstmt = "select count(1) from test_pre1, test_pre2 where sid=csid" ;
 
#line 26 "prepare.pgc"
 char * cntstmt1 = "select count(1) from test_pre1, test_pre2 where sid=csid and sname=?" ;
 
#line 27 "prepare.pgc"
 char * cntstmt2 = "select count(1) from test_pre1, test_pre2 where sid=csid and sid=?" ;
 
#line 28 "prepare.pgc"
 int caCID [ 5 ] , caSID [ 5 ] ;
 
#line 29 "prepare.pgc"
  struct varchar_1  { int len; char arr[ 20 ]; }  caCname [ 5 ] ;  struct varchar_2  { int len; char arr[ 20 ]; }  caSname [ 5 ] ;  struct varchar_3  { int len; char arr[ 40 ]; }  caAddr [ 5 ] ;
 
#line 30 "prepare.pgc"
 char caCname1 [ 5 ] [ 20 ] , caSname1 [ 5 ] [ 20 ] , caAddr1 [ 5 ] [ 40 ] ;
 
#line 31 "prepare.pgc"
 int i ;
 
#line 32 "prepare.pgc"
 int cnt ;
 
#line 33 "prepare.pgc"
 int a ;
 
#line 34 "prepare.pgc"
 char * b ;
 
#line 35 "prepare.pgc"
 char * c ;
/* exec sql end declare section */
#line 36 "prepare.pgc"


  //init variable
  memset(caCID, 0, sizeof(caCID));
  memset(caSID, 0, sizeof(caSID));
  memset(caCname, 0x00, sizeof(caCname));
  memset(caCname1, 0x00, sizeof(caCname1));
  memset(caSname, 0x00, sizeof(caSname));
  memset(caSname1, 0x00, sizeof(caSname1));
  memset(caAddr, 0x00, sizeof(caAddr));
  memset(caAddr1, 0x00, sizeof(caAddr1));


  //语句--prepare name from string(字串)；
  //EXEC SQL ALLOCATE DESCRIPTOR outdesc;
//EXEC SQL PREPARE myprep from :stmt;  //no-parameter
  { ECPGprepare(__LINE__, NULL, 0, "myprep1", stmt1);
#line 52 "prepare.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 52 "prepare.pgc"
 //with-parameter(带参)
  //EXEC SQL PREPARE cntprep from :cntstmt;  //no-parameter
  { ECPGprepare(__LINE__, NULL, 0, "cntprep1", cntstmt1);
#line 54 "prepare.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 54 "prepare.pgc"
 //with-parameter(带字符型参数)
  //EXEC SQL PREPARE cntprep2 from :cntstmt2; //with-parameter(带整型参数)

/*
  //语句--prepare name as statement(不带参数)；
  //可执行(Correct)!--prepare .. as ...（不带参数）--ecpg将as后面语句直接处理为字符串，同prepare...from一样可用！
  EXEC SQL prepare myprep as select cid, cname, sid, sname, addr from test_pre1, test_pre2 where sid=csid;
  //EXEC SQL prepare myprep from "select cid, cname, sid, sname, addr from test_pre1, test_pre2 where sid=csid";
  EXEC SQL PREPARE cntprep as select count(1) from test_pre1, test_pre2 where sid=csid;
  //不可执行(error)!--prepare .. as ...（带参数）--不可用，ecpg将as后语句处理为string，因此无法识别$1为参数!
  EXEC SQL prepare myins1 (int, char, char) as insert into test_pre1 values($1, $2, $3);
  EXEC SQL EXECUTE myins1(8, 'WEN', 'address8');
  EXEC SQL prepare myprep as select cid, cname, sid, sname, addr from test_pre1, test_pre2 where sid=csid;
  EXEC SQL PREPARE cntprep as select count(1) from test_pre1, test_pre2 where sid=csid; 
*/

  //FOR-IN-EXECUTE取数据！--one way 
  //EXEC SQL EXECUTE myprep1 USING SQL DESCRIPTOR indesc INTO SQL DESCRIPTOR outdesc;

  //带参语句--smtm1--prepare...from...
  b="Wang"; 
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_execute, "myprep1", 
	ECPGt_char,&(b),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,(caCID),(long)1,(long)5,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(caCname1),(long)20,(long)5,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,(caSID),(long)1,(long)5,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(caSname1),(long)20,(long)5,(20)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(caAddr1),(long)40,(long)5,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 75 "prepare.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 75 "prepare.pgc"
//对应语句smtm1--带参
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_execute, "cntprep1", 
	ECPGt_char,&(b),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(cnt),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 76 "prepare.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 76 "prepare.pgc"
 //CORRECT!--USING后跟变量
  //EXEC SQL EXECUTE cntprep1 INTO :cnt USING 'Wang'; //ERROR!--取不到cnt值--USING后字符常量
  //EXEC SQL EXECUTE cntprep2 INTO :cnt USING 2; //CORRECT!--USING后整型常量
  //printf("%d\n",cnt);

/*
  //不带参语句--smtm--prepare...from...
  EXEC SQL EXECUTE myprep INTO :caCID, :caCname1, :caSID, :caSname1, :caAddr1;//fetch语句完成取出到宿主变量
  EXEC SQL EXECUTE cntprep INTO :cnt;
*/

  printf("cid, cname, sid, sname, addr\n");
  for(i=0;i<cnt;i++)
  {
     printf("%d, %s, %d, %s, %s\n", caCID[i], caCname1[i], caSID[i], caSname1[i], caAddr1[i]);
  } 

/*
  //OPEN-FOR-EXECUTE(cursor)取数据！--another way
  EXEC SQL DECLARE mycur CURSOR FOR myprep;
  EXEC SQL OPEN mycur;
  while(1)
  {
    EXEC SQL FETCH 2 mycur INTO :caCID, :caCname, :caSID, :caSname, :caAddr;
    printf("fetch:%d\n", sqlca.sqlerrd[2]);
    if(sqlca.sqlcode == 100)
    {
      break;
     }
    for(i=0; i<sqlca.sqlerrd[2]; i++)
      printf("cid = %d, cname = %*s, sid = %d, sname = %*s, addr = %*s\n", caCID[i], caCname[i].len, caCname[i].arr, caSID[i], caSname[i].len, caSname[i].arr, caAddr[i].len, caAddr[i].arr);
  }  
  EXEC SQL CLOSE mycur;
  EXEC SQL COMMIT;
*/

  //EXEC SQL DEALLOCATE PREPARE myprep;//释放资源
  //EXEC SQL DEALLOCATE PREPARE cntprep;//释放资源
  { ECPGdeallocate(__LINE__, 0, NULL, "myprep1");
#line 114 "prepare.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 114 "prepare.pgc"
//释放资源
  { ECPGdeallocate(__LINE__, 0, NULL, "cntprep1");
#line 115 "prepare.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 115 "prepare.pgc"
//释放资源
  //EXEC SQL DEALLOCATE PREPARE cntprep2;//释放资源

  { ECPGdisconnect(__LINE__, "ALL");
#line 118 "prepare.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 118 "prepare.pgc"

  return 0;
}
void print_sqlca()
{
  fprintf(stderr, "==== sqlca ====\n");
  fprintf(stderr, "sqlcode: %ld\n", sqlca.sqlcode);
  fprintf(stderr, "sqlerrm.sqlerrml: %d\n", sqlca.sqlerrm.sqlerrml);
  fprintf(stderr, "sqlerrm.sqlerrmc: %s\n", sqlca.sqlerrm.sqlerrmc);
  fprintf(stderr, "sqlerrd: %ld %ld %ld %ld %ld %ld\n", sqlca.sqlerrd[0],sqlca.sqlerrd[1],sqlca.sqlerrd[2],
  sqlca.sqlerrd[3],sqlca.sqlerrd[4],sqlca.sqlerrd[5]);
  fprintf(stderr, "sqlwarn: %d %d %d %d %d %d %d %d\n", sqlca.sqlwarn[0], sqlca.sqlwarn[1], sqlca.sqlwarn[2],
  sqlca.sqlwarn[3], sqlca.sqlwarn[4], sqlca.sqlwarn[5],
  sqlca.sqlwarn[6], sqlca.sqlwarn[7]);
  fprintf(stderr, "sqlstate: %5s\n", sqlca.sqlstate);
  fprintf(stderr, "===============\n");
}
