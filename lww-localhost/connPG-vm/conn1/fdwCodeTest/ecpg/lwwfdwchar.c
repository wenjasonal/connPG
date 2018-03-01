/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "lwwfdwchar.pgc"
#include <stdlib.h>    
//#include <sqlca.h>
    
//EXEC SQL INCLUDE sqlca;    
    
int main() {  
    void print_sqlca();

    /* exec sql begin declare section */
          
          
          
    
#line 10 "lwwfdwchar.pgc"
 char caSignno [ 45 ] ;
 
#line 11 "lwwfdwchar.pgc"
 char caBusinesstypecode [ 10 ] ;
 
#line 12 "lwwfdwchar.pgc"
 char caEmail [ 40 ] ;
/* exec sql end declare section */
#line 13 "lwwfdwchar.pgc"

	
    { ECPGconnect(__LINE__, 0, "paydev@10.136.1.32:5432" , "paydev" , "paydev" , NULL, 0); }
#line 15 "lwwfdwchar.pgc"

    if(sqlca.sqlcode)
    {
      printf("Connect DB error! sqlcode=%d!\n", sqlca.sqlcode);
    }
/*	//EXEC SQL BEGIN TRANSACTION;
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
//查询表所有数据
/*        EXEC SQL BEGIN TRANSACTION; 
	EXEC SQL DECLARE tb_cur CURSOR FOR
	     select signno, businesstypecode, email INTO :caSignno, :caBusinesstypecode, :caEmail from tb_addconsign;
	//if(sqlca.sqlcode){}
	EXEC SQL OPEN tb_cur;
	//if(sqlca.sqlcode){}
        //EXEC SQL WHENEVER NOT FOUND DO BREAK;
        while(1)
        {
         memset( caSignno, 0x00, sizeof(caSignno));
         memset( caBusinesstypecode, 0x00, sizeof(caBusinesstypecode));
         memset( caEmail, 0x00, sizeof(caEmail));
	 EXEC SQL FETCH 1 tb_cur INTO :caSignno, :caBusinesstypecode, :caEmail;//cursor select mutli-column
         printf("%d\n", sqlca.sqlerrd[2]);
//break; //testing
         if(sqlca.sqlcode==100)
          {
           //print_sqlca();
           break;
          }
         int i=0;
        for( i=0 ; i<sqlca.sqlerrd[2]; i++)
         {
         printf("signno=%s, businesstypecode=%s, email=%s\n", caSignno, caBusinesstypecode, caEmail); //char name
         //printf("signno=%*s, businesstypecode=%*s,  email=%*s\n", caSignno[i].len, caSignno[i].arr, caBusinesstypecode[i].len, caBusinesstypecode[i].arr, caEmail[i].len, caEmail[i].arr);//varchar name
         //break; //testing
         }
         //if(sqlca.sqlcode==100) break;
//break; //testing
        }

	EXEC SQL CLOSE tb_cur;
     EXEC SQL COMMIT;
*/
//更改记录
    // EXEC SQL update tb_addconsign SET email='lww-testecpg@qq.com' where signno='6221887900000461019';
     { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update tb_addconsign set email = '' where signno = '6221887900000461019'", ECPGt_EOIT, ECPGt_EORT);}
#line 90 "lwwfdwchar.pgc"
 //恢复表原数据
    // EXEC SQL COMMIT; //未执行commit的话也同样更新完成

//查询更改后数据
        { ECPGtrans(__LINE__, NULL, "begin transaction");}
#line 94 "lwwfdwchar.pgc"

        ECPGset_var( 0, ( caEmail ), __LINE__);\
 ECPGset_var( 1, ( caBusinesstypecode ), __LINE__);\
 ECPGset_var( 2, ( caSignno ), __LINE__);\
 /* declare tb_cur_1 cursor for select signno , businesstypecode , email from tb_addconsign where signno = '6221887900000461019' */
#line 96 "lwwfdwchar.pgc"

        //if(sqlca.sqlcode){}
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare tb_cur_1 cursor for select signno , businesstypecode , email from tb_addconsign where signno = '6221887900000461019'", ECPGt_EOIT, 
	ECPGt_char,(caSignno),(long)45,(long)1,(45)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(caBusinesstypecode),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(caEmail),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 98 "lwwfdwchar.pgc"

        //if(sqlca.sqlcode){}
        //EXEC SQL WHENEVER NOT FOUND DO BREAK;
        while(1)
        {
         memset( caSignno, 0x00, sizeof(caSignno));
         memset( caBusinesstypecode, 0x00, sizeof(caBusinesstypecode));
         memset( caEmail, 0x00, sizeof(caEmail));
         { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch 1 tb_cur_1", ECPGt_EOIT, 
	ECPGt_char,(caSignno),(long)45,(long)1,(45)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(caBusinesstypecode),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(caEmail),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(caSignno),(long)45,(long)1,(45)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(caBusinesstypecode),(long)10,(long)1,(10)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(caEmail),(long)40,(long)1,(40)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 106 "lwwfdwchar.pgc"
//cursor select mutli-column
         printf("%d\n", sqlca.sqlerrd[2]);
//break; //testing
         if(sqlca.sqlcode==100)
          {
           //print_sqlca();
           break;
          }
         int i=0;
        for( i=0 ; i<sqlca.sqlerrd[2]; i++)
         {
          printf("signno=%s, businesstypecode=%s, email=%s\n", caSignno, caBusinesstypecode, caEmail); //char name
         //printf("signno=%*s, businesstypecode=%*s,  email=%*s\n", caSignno[i].len, caSignno[i].arr, caBusinesstypecode[i].len, caBusinesstypecode[i].arr, caEmail[i].len, caEmail[i].arr);//varchar name
         //break; //testing
         }
         //if(sqlca.sqlcode==100) break;
//break; //testing
        }
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close tb_cur_1", ECPGt_EOIT, ECPGt_EORT);}
#line 124 "lwwfdwchar.pgc"

     { ECPGtrans(__LINE__, NULL, "commit");}
#line 125 "lwwfdwchar.pgc"


      //EXEC SQL WHENEVER SQLERROR CALL print_sqlca();
	
     { ECPGdisconnect(__LINE__, "ALL");}
#line 129 "lwwfdwchar.pgc"

    
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
