/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "error_test.pgc"
#include <stdlib.h>    
//#include <sqlca.h>
#include <string.h>    
//EXEC SQL INCLUDE sqlca;    
    
int main() {  
//    void print_sqlca();

    /* exec sql begin declare section */
          
          
    
#line 10 "error_test.pgc"
 int caID [ 3 ] ;
 
#line 11 "error_test.pgc"
 char caName [ 3 ] [ 30 + 1 ] ;
/* exec sql end declare section */
#line 12 "error_test.pgc"

	
    { ECPGconnect(__LINE__, 0, "lwwtest@10.136.2.133:5432" , "lww" , "lww" , NULL, 0); }
#line 14 "error_test.pgc"

    if(sqlca.sqlcode)
    {
      printf("Connect DB error! sqlcode=%d!\n", sqlca.sqlcode);
    }
	//EXEC SQL BEGIN TRANSACTIONS;
       
       caID[0]=1;
       strcpy(caName[0], "varchar123");
       caID[1]=2;
       strcpy(caName[1],"一二三四五六七八九十");
       caID[2]=3;
       strcpy(caName[2], "0123456789");
{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ values ( $1  , $2  )", 
	ECPGt_int,&(caID[0]),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(caName[0]),(long)30 + 1,(long)1,(30 + 1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 27 "error_test.pgc"

{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ values ( $1  , $2  )", 
	ECPGt_int,&(caID[1]),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(caName[1]),(long)30 + 1,(long)1,(30 + 1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 28 "error_test.pgc"

{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into organ values ( $1  , $2  )", 
	ECPGt_int,&(caID[2]),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(caName[2]),(long)30 + 1,(long)1,(30 + 1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 29 "error_test.pgc"


/*if(sqlca.sqlcode)
           {
             print_sqlca();
           
}
EXEC SQL COMMIT;
*/
/*	EXEC SQL INSERT INTO test_ecpg_tbl values(1, 'varchar123');
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
*/

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update organ set organcode = 100 where organcode = 1", ECPGt_EOIT, ECPGt_EORT);}
#line 58 "error_test.pgc"

        { ECPGtrans(__LINE__, NULL, "commit");}
#line 59 "error_test.pgc"

//      EXEC SQL delete from organ where organcode=100;
  //    EXEC SQL COMMIT;
	
     { ECPGtrans(__LINE__, NULL, "begin transaction");}
#line 63 "error_test.pgc"
 
	ECPGset_var( 0, ( caName ), __LINE__);\
 ECPGset_var( 1, ( caID ), __LINE__);\
 /* declare tb_cur cursor for select organcode , organname from organ */
#line 65 "error_test.pgc"

	//if(sqlca.sqlcode){}
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare tb_cur cursor for select organcode , organname from organ", ECPGt_EOIT, 
	ECPGt_int,(caID),(long)1,(long)3,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(caName),(long)30 + 1,(long)3,(30 + 1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 67 "error_test.pgc"

	//if(sqlca.sqlcode){}
        //EXEC SQL WHENEVER NOT FOUND DO BREAK;
        while(1)
        {
         memset( caName, 0x00, sizeof( caName));
	 { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch 2 tb_cur", ECPGt_EOIT, 
	ECPGt_int,(caID),(long)1,(long)3,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(caName),(long)30 + 1,(long)3,(30 + 1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,(caID),(long)1,(long)3,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(caName),(long)30 + 1,(long)3,(30 + 1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 73 "error_test.pgc"

         printf("%d\n", sqlca.sqlerrd[2]);
         if(sqlca.sqlcode==100)
          {
           //print_sqlca();
           break;
          }
         int i=0;
        for( i=0 ; i<sqlca.sqlerrd[2]; i++)
         printf("id=%d, name=%s\n", caID[i], caName[i]); //char name
        // printf("id=%d, name=%*s\n", caID[i], caName[i].len, caName[i].arr);//varchar name
         //if(sqlca.sqlcode==100) break;
        }

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close tb_cur", ECPGt_EOIT, ECPGt_EORT);}
#line 87 "error_test.pgc"

     { ECPGtrans(__LINE__, NULL, "commit");}
#line 88 "error_test.pgc"


      //EXEC SQL delete from test_ecpg_tbl where id=100;
      //EXEC SQL COMMIT;

      //EXEC SQL WHENEVER SQLERROR CALL print_sqlca();
	
     { ECPGdisconnect(__LINE__, "ALL");}
#line 95 "error_test.pgc"

    
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
