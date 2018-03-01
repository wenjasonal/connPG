/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "mutlicolfetch_all.pgc"
#include <stdlib.h>    
//#include <sqlca.h>
    
//EXEC SQL INCLUDE sqlca;    
    
int main() {  
    void print_sqlca();

    /* exec sql begin declare section */
          
          
    
#line 10 "mutlicolfetch_all.pgc"
 int caID [ 3 ] ;
 
#line 11 "mutlicolfetch_all.pgc"
  struct varchar_1  { int len; char arr[ 30 ]; }  caName [ 3 ] ;
/* exec sql end declare section */
#line 12 "mutlicolfetch_all.pgc"

	
    { ECPGconnect(__LINE__, 0, "lwwtest@10.136.2.133:5432" , "lww" , "lww" , NULL, 0); }
#line 14 "mutlicolfetch_all.pgc"

    if(sqlca.sqlcode)
    {
      printf("Connect DB error! sqlcode=%d!\n", sqlca.sqlcode);
    }
	//EXEC SQL BEGIN TRANSACTION;
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "drop table test_ecpg_tbl", ECPGt_EOIT, ECPGt_EORT);}
#line 20 "mutlicolfetch_all.pgc"
//testing
        { ECPGtrans(__LINE__, NULL, "commit");}
#line 21 "mutlicolfetch_all.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "create table test_ecpg_tbl ( id int , name varchar ( 10 ) )", ECPGt_EOIT, ECPGt_EORT);}
#line 22 "mutlicolfetch_all.pgc"

        { ECPGtrans(__LINE__, NULL, "commit");}
#line 23 "mutlicolfetch_all.pgc"

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "create unique index idx1 on test_ecpg_tbl ( id )", ECPGt_EOIT, ECPGt_EORT);}
#line 24 "mutlicolfetch_all.pgc"

       	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 25 "mutlicolfetch_all.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into test_ecpg_tbl values ( 1 , 'varchar123' )", ECPGt_EOIT, ECPGt_EORT);}
#line 26 "mutlicolfetch_all.pgc"

        if(sqlca.sqlcode)
           {
             print_sqlca();
           }
        { ECPGtrans(__LINE__, NULL, "commit");}
#line 31 "mutlicolfetch_all.pgc"

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into test_ecpg_tbl values ( 2 , '一二三四五六七八九十' )", ECPGt_EOIT, ECPGt_EORT);}
#line 32 "mutlicolfetch_all.pgc"

          if(sqlca.sqlcode)
           {
             print_sqlca();
           }
	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 37 "mutlicolfetch_all.pgc"

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into test_ecpg_tbl values ( 3 , '0123456789' )", ECPGt_EOIT, ECPGt_EORT);}
#line 38 "mutlicolfetch_all.pgc"

        if(sqlca.sqlcode)
           {
             print_sqlca();
           }
        { ECPGtrans(__LINE__, NULL, "commit");}
#line 43 "mutlicolfetch_all.pgc"



        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update test_ecpg_tbl set id = 100 where id = 1", ECPGt_EOIT, ECPGt_EORT);}
#line 46 "mutlicolfetch_all.pgc"

        { ECPGtrans(__LINE__, NULL, "commit");}
#line 47 "mutlicolfetch_all.pgc"

//      EXEC SQL delete from test_ecpg_tbl where id=100;
  //    EXEC SQL COMMIT;
	
     { ECPGtrans(__LINE__, NULL, "begin transaction");}
#line 51 "mutlicolfetch_all.pgc"
 
	ECPGset_var( 0, ( caName ), __LINE__);\
 ECPGset_var( 1, ( caID ), __LINE__);\
 /* declare tb_cur cursor for select id , name from test_ecpg_tbl */
#line 53 "mutlicolfetch_all.pgc"

	//if(sqlca.sqlcode){}
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare tb_cur cursor for select id , name from test_ecpg_tbl", ECPGt_EOIT, 
	ECPGt_int,(caID),(long)1,(long)3,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(caName),(long)30,(long)3,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 55 "mutlicolfetch_all.pgc"

	//if(sqlca.sqlcode){}
        //EXEC SQL WHENEVER NOT FOUND DO BREAK;
        while(1)
        {
         memset( caName, 0x00, sizeof( caName));
	 { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch 2 tb_cur", ECPGt_EOIT, 
	ECPGt_int,(caID),(long)1,(long)3,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(caName),(long)30,(long)3,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,(caID),(long)1,(long)3,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(caName),(long)30,(long)3,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 61 "mutlicolfetch_all.pgc"
//cursor select mutli-column
         printf("%d\n", sqlca.sqlerrd[2]);
         if(sqlca.sqlcode==100)
          {
           //print_sqlca();
           break;
          }
         int i=0;
        for( i=0 ; i<sqlca.sqlerrd[2]; i++)
         //printf("id=%d, name=%s\n", caID, caName); //char name
         printf("id=%d, name=%*s\n", caID[i], caName[i].len, caName[i].arr);//varchar name
         //if(sqlca.sqlcode==100) break;
        }

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close tb_cur", ECPGt_EOIT, ECPGt_EORT);}
#line 75 "mutlicolfetch_all.pgc"

     { ECPGtrans(__LINE__, NULL, "commit");}
#line 76 "mutlicolfetch_all.pgc"


      //EXEC SQL delete from test_ecpg_tbl where id=100;
      //EXEC SQL COMMIT;

      //EXEC SQL WHENEVER SQLERROR CALL print_sqlca();
	
     { ECPGdisconnect(__LINE__, "ALL");}
#line 83 "mutlicolfetch_all.pgc"

    
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
