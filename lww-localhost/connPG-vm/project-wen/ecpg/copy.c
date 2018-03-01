/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "copy.pgc"
#include <stdlib.h>

int main()
{
  { ECPGconnect(__LINE__, 0, "test@10.136.1.143" , "lww" , "lww" , NULL, 0); }
#line 5 "copy.pgc"

  if(sqlca.sqlcode)
  {
     printf("CONNECT TO DATABASE ERROR! sqlca.sqlcode=%d\n", sqlca.sqlcode);
   }
  else 
     printf("CONNECT TO DATABASE OK!\n");

  /* exec sql begin declare section */
     
     
      
  
#line 14 "copy.pgc"
 int cacid [ 10 ] ;
 
#line 15 "copy.pgc"
  struct varchar_1  { int len; char arr[ 30 ]; }  cacname [ 10 ] ;
 
#line 16 "copy.pgc"
 int i , cnt ;
/* exec sql end declare section */
#line 17 "copy.pgc"


  { ECPGtrans(__LINE__, NULL, "begin transaction");}
#line 19 "copy.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "drop table test_copy", ECPGt_EOIT, ECPGt_EORT);}
#line 20 "copy.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "create table test_copy ( cid int not null , cname varchar ( 30 ) )", ECPGt_EOIT, ECPGt_EORT);}
#line 21 "copy.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into test_copy values ( 1 , 'COPY值1' )", ECPGt_EOIT, ECPGt_EORT);}
#line 22 "copy.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into test_copy values ( 2 , 'COPY值2' )", ECPGt_EOIT, ECPGt_EORT);}
#line 23 "copy.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into test_copy values ( 3 , 'COPY值3' )", ECPGt_EOIT, ECPGt_EORT);}
#line 24 "copy.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into test_copy values ( 4 , '中文导出到文件' )", ECPGt_EOIT, ECPGt_EORT);}
#line 25 "copy.pgc"

  
  printf("\n==========copy table's data to csv file==========\n");
  /* declare mycursor cursor with hold for select cid , cname from test_copy order by cid */
#line 28 "copy.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare mycursor cursor with hold for select cid , cname from test_copy order by cid", ECPGt_EOIT, ECPGt_EORT);}
#line 29 "copy.pgc"

  while(1)
  {
    memset(cacname, 0x00, sizeof(cacname));
 
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch from mycursor", ECPGt_EOIT, 
	ECPGt_int,(cacid),(long)1,(long)10,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(cacname),(long)30,(long)10,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 34 "copy.pgc"

    //printf("%d\n", sqlca.sqlerrd[2]);
    if(sqlca.sqlcode == 100)
    { 
       break;
     }
    for(i=0; i<sqlca.sqlerrd[2]; i++)
    {
     printf("cid = %d, cname = %*s\n", cacid[i], cacname[i].len, cacname[i].arr);
    }
  }
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close mycursor", ECPGt_EOIT, ECPGt_EORT);}
#line 45 "copy.pgc"

  
  //copy data to file -- copy表数据到文件
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "copy ( select cid , cname from test_copy ) to '/tmp/mycopy.csv' with ( FORMAT csv , header , delimiter ',' , encoding 'UTF8' )", ECPGt_EOIT, ECPGt_EORT);}
#line 48 "copy.pgc"

  
  printf("\n==========delete table all data==========\n");
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from test_copy", ECPGt_EOIT, ECPGt_EORT);}
#line 51 "copy.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select count ( 1 ) from test_copy", ECPGt_EOIT, 
	ECPGt_int,&(cnt),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 52 "copy.pgc"

  printf("table count(*) = %d\n");
 
  printf("\n======copy from csv file into table======\n");
  //copy file to table -- copy文件数据到表
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "copy test_copy from '/tmp/mycopy.csv' with ( FORMAT csv , header , delimiter ',' , encoding 'UTF8' )", ECPGt_EOIT, ECPGt_EORT);}
#line 57 "copy.pgc"


  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare mycursor cursor with hold for select cid , cname from test_copy order by cid", ECPGt_EOIT, ECPGt_EORT);}
#line 59 "copy.pgc"

  while(1)
  {
    memset(cacname, 0x00, sizeof(cacname));

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch from mycursor", ECPGt_EOIT, 
	ECPGt_int,(cacid),(long)1,(long)10,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(cacname),(long)30,(long)10,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 64 "copy.pgc"

    //printf("%d\n", sqlca.sqlerrd[2]);
    if(sqlca.sqlcode == 100)
    {
       break;
     }
    for(i=0; i<sqlca.sqlerrd[2]; i++)
    {
     printf("cid = %d, cname = %*s\n", cacid[i], cacname[i].len, cacname[i].arr);
    }
  }
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close mycursor", ECPGt_EOIT, ECPGt_EORT);}
#line 75 "copy.pgc"


  { ECPGtrans(__LINE__, NULL, "commit");}
#line 77 "copy.pgc"

 
  { ECPGdisconnect(__LINE__, "ALL");}
#line 79 "copy.pgc"

  return 0;
}

