/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "cursor-with-hold.pgc"
#include <stdlib.h>    
//#include <sqlca.h>
    
//EXEC SQL INCLUDE sqlca;    
    
int main() {  
    void print_sqlca();

    /* exec sql begin declare section */
          
          
    
#line 10 "cursor-with-hold.pgc"
 int caID [ 3 ] ;
 
#line 11 "cursor-with-hold.pgc"
  struct varchar_1  { int len; char arr[ 30 ]; }  caSID [ 3 ] ;
/* exec sql end declare section */
#line 12 "cursor-with-hold.pgc"

	
    { ECPGconnect(__LINE__, 0, "lwwtest@10.136.2.131:5432" , "lww" , "lww" , NULL, 0); }
#line 14 "cursor-with-hold.pgc"

    if(sqlca.sqlcode)
    {
      printf("Connect DB error! sqlcode=%d!\n", sqlca.sqlcode);
    }
	//EXEC SQL BEGIN TRANSACTION;
        /*
        EXEC SQL drop table test_ecpg_tbl;//testing
        EXEC SQL COMMIT;
	EXEC SQL create table test_ecpg_tbl(id int, name varchar(10));
        EXEC SQL COMMIT;
        EXEC SQL create unique index idx1 on test_ecpg_tbl(id);
       	EXEC SQL COMMIT;
	EXEC SQL INSERT INTO test_ecpg_tbl values(1, 'varchar123');
        if(sqlca.sqlcode)
           {
             print_sqlca();
           }
        EXEC SQL COMMIT;
        EXEC SQL INSERT INTO test_ecpg_tbl values(2, '一二三四五六七八九十');
          if(sqlca.sqlcode)
           {
             print_sqlca();
           }
	EXEC SQL COMMIT;
        EXEC SQL INSERT INTO test_ecpg_tbl values(3, '0123456789');
        if(sqlca.sqlcode)
           {
             print_sqlca();
           }
        EXEC SQL COMMIT;


        EXEC SQL UPDATE test_ecpg_tbl SET id=100 WHERE id=1;
        EXEC SQL COMMIT;
//      EXEC SQL delete from test_ecpg_tbl where id=100;
  //    EXEC SQL COMMIT;
	*/
     { ECPGtrans(__LINE__, NULL, "begin transaction");}
#line 52 "cursor-with-hold.pgc"
 
	ECPGset_var( 0, ( caID ), __LINE__);\
 ECPGset_var( 1, ( caSID ), __LINE__);\
 /* declare tb_cur cursor with hold for select sid , id from test */
#line 54 "cursor-with-hold.pgc"

	//if(sqlca.sqlcode){}
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare tb_cur cursor with hold for select sid , id from test", ECPGt_EOIT, 
	ECPGt_varchar,(caSID),(long)30,(long)3,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,(caID),(long)1,(long)3,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 56 "cursor-with-hold.pgc"

	//if(sqlca.sqlcode){}
        //EXEC SQL WHENEVER NOT FOUND DO BREAK;
        while(1)
        {
         memset( caSID, 0x00, sizeof( caSID));
	 { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch tb_cur", ECPGt_EOIT, 
	ECPGt_varchar,(caSID),(long)30,(long)3,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,(caID),(long)1,(long)3,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(caSID),(long)30,(long)3,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,(caID),(long)1,(long)3,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 62 "cursor-with-hold.pgc"
//cursor select mutli-column
         printf("%d\n", sqlca.sqlerrd[2]);
         if(sqlca.sqlcode==100)
          {
           //print_sqlca();
           break;
          }
   { ECPGtrans(__LINE__, NULL, "rollback");}
#line 69 "cursor-with-hold.pgc"

   { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare tb_cur cursor with hold for select sid , id from test", ECPGt_EOIT, 
	ECPGt_varchar,(caSID),(long)30,(long)3,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,(caID),(long)1,(long)3,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 70 "cursor-with-hold.pgc"

   if(sqlca.sqlcode!=0)
   {
     printf("OPEN tb_cur error! sqlca.sqlcode=[%d], sqlca.state=[%s]!",sqlca.sqlcode, sqlca.sqlstate);
     return (-1);
    }
         int i=0;
        for( i=0 ; i<sqlca.sqlerrd[2]; i++)
         //printf("id=%d, name=%s\n", caID, caName); //char name
         printf("id=%d, sid=%*s\n", caID[i], caSID[i].len, caSID[i].arr);//varchar sid
         //if(sqlca.sqlcode==100) break;
        }
       { ECPGtrans(__LINE__, NULL, "begin transaction");}
#line 82 "cursor-with-hold.pgc"

       { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update test set sid = 'lww' where id = 2", ECPGt_EOIT, ECPGt_EORT);}
#line 83 "cursor-with-hold.pgc"

       { ECPGtrans(__LINE__, NULL, "rollback");}
#line 84 "cursor-with-hold.pgc"

       
       { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close tb_cur", ECPGt_EOIT, ECPGt_EORT);}
#line 86 "cursor-with-hold.pgc"

     { ECPGtrans(__LINE__, NULL, "commit");}
#line 87 "cursor-with-hold.pgc"

     //EXEC SQL ROLLBACK;
/*
   //use cursor tb_cur again after above declare
    EXEC SQL BEGIN TRANSACTION;
     EXEC SQL OPEN tb_cur;
     while(1)
     {
      EXEC SQL FETCH 1 tb_cur INTO :caSID, :caID;
       printf("%d\n", sqlca.sqlerrd[2]);
         if(sqlca.sqlcode==100)
          {
           //print_sqlca();
           break;
          }
         int i=0;
        for( i=0 ; i<sqlca.sqlerrd[2]; i++)
         //printf("id=%d, name=%s\n", caID, caName); //char name
         printf("id=%d, sid=%*s\n", caID[i], caSID[i].len, caSID[i].arr);//varchar sid
         //if(sqlca.sqlcode==100) break;
        }
     EXEC SQL CLOSE tb_cur;
     EXEC SQL COMMIT;
*/

      //EXEC SQL delete from test_ecpg_tbl where id=100;
      //EXEC SQL COMMIT;

      //EXEC SQL WHENEVER SQLERROR CALL print_sqlca();
	
     { ECPGdisconnect(__LINE__, "ALL");}
#line 117 "cursor-with-hold.pgc"

    
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
