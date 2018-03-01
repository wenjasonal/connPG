/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "lwwfdw.pgc"
#include <stdlib.h>    
//#include <sqlca.h>
    
//EXEC SQL INCLUDE sqlca;    
    
int main() {  
    void print_sqlca();

    /* exec sql begin declare section */
          
          
          
    
#line 10 "lwwfdw.pgc"
  struct varchar_1  { int len; char arr[ 45 ]; }  caSignno [ 10 ] ;
 
#line 11 "lwwfdw.pgc"
  struct varchar_2  { int len; char arr[ 10 ]; }  caBusinesstypecode [ 10 ] ;
 
#line 12 "lwwfdw.pgc"
  struct varchar_3  { int len; char arr[ 40 ]; }  caEmail [ 10 ] ;
/* exec sql end declare section */
#line 13 "lwwfdw.pgc"

	
    { ECPGconnect(__LINE__, 0, "paydev@10.136.1.32:5432" , "paydev" , "paydev" , NULL, 0); }
#line 15 "lwwfdw.pgc"

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
        { ECPGtrans(__LINE__, NULL, "begin transaction");}
#line 54 "lwwfdw.pgc"
 
	ECPGset_var( 0, ( caEmail ), __LINE__);\
 ECPGset_var( 1, ( caBusinesstypecode ), __LINE__);\
 ECPGset_var( 2, ( caSignno ), __LINE__);\
 /* declare tb_cur cursor for select signno , businesstypecode , email from tb_addconsign */
#line 56 "lwwfdw.pgc"

	//if(sqlca.sqlcode){}
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare tb_cur cursor for select signno , businesstypecode , email from tb_addconsign", ECPGt_EOIT, 
	ECPGt_varchar,(caSignno),(long)45,(long)10,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(caBusinesstypecode),(long)10,(long)10,sizeof(struct varchar_2), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(caEmail),(long)40,(long)10,sizeof(struct varchar_3), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 58 "lwwfdw.pgc"

	//if(sqlca.sqlcode){}
        //EXEC SQL WHENEVER NOT FOUND DO BREAK;
        while(1)
        {
         memset( caSignno, 0x00, sizeof(caSignno));
         memset( caBusinesstypecode, 0x00, sizeof(caBusinesstypecode));
         memset( caEmail, 0x00, sizeof(caEmail));
	 { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch 10 tb_cur", ECPGt_EOIT, 
	ECPGt_varchar,(caSignno),(long)45,(long)10,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(caBusinesstypecode),(long)10,(long)10,sizeof(struct varchar_2), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(caEmail),(long)40,(long)10,sizeof(struct varchar_3), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(caSignno),(long)45,(long)10,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(caBusinesstypecode),(long)10,(long)10,sizeof(struct varchar_2), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(caEmail),(long)40,(long)10,sizeof(struct varchar_3), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 66 "lwwfdw.pgc"
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
         //printf("id=%d, name=%s\n", caID, caName); //char name
         printf("signno=%*s, businesstypecode=%*s,  email=%*s\n", caSignno[i].len, caSignno[i].arr, caBusinesstypecode[i].len, caBusinesstypecode[i].arr, caEmail[i].len, caEmail[i].arr);//varchar name
         //break; //testing
         }
         //if(sqlca.sqlcode==100) break;
//break; //testing
        }

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close tb_cur", ECPGt_EOIT, ECPGt_EORT);}
#line 85 "lwwfdw.pgc"

     { ECPGtrans(__LINE__, NULL, "commit");}
#line 86 "lwwfdw.pgc"


//更改记录
    // EXEC SQL update tb_addconsign SET email='lww-testecpg@qq.com' where signno='6221887900000461019';
     { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update tb_addconsign set email = '' where signno = '6221887900000461019'", ECPGt_EOIT, ECPGt_EORT);}
#line 90 "lwwfdw.pgc"
 //恢复表原数据
     { ECPGtrans(__LINE__, NULL, "commit");}
#line 91 "lwwfdw.pgc"
 //未执行commit的话也同样更新完成

//查询更改后数据
        { ECPGtrans(__LINE__, NULL, "begin transaction");}
#line 94 "lwwfdw.pgc"

        ECPGset_var( 3, ( caEmail ), __LINE__);\
 ECPGset_var( 4, ( caBusinesstypecode ), __LINE__);\
 ECPGset_var( 5, ( caSignno ), __LINE__);\
 /* declare tb_cur_1 cursor for select signno , businesstypecode , email from tb_addconsign where signno = '6221887900000461019' */
#line 96 "lwwfdw.pgc"

        //if(sqlca.sqlcode){}
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare tb_cur_1 cursor for select signno , businesstypecode , email from tb_addconsign where signno = '6221887900000461019'", ECPGt_EOIT, 
	ECPGt_varchar,(caSignno),(long)45,(long)10,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(caBusinesstypecode),(long)10,(long)10,sizeof(struct varchar_2), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(caEmail),(long)40,(long)10,sizeof(struct varchar_3), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 98 "lwwfdw.pgc"

        //if(sqlca.sqlcode){}
        //EXEC SQL WHENEVER NOT FOUND DO BREAK;
        while(1)
        {
         memset( caSignno, 0x00, sizeof(caSignno));
         memset( caBusinesstypecode, 0x00, sizeof(caBusinesstypecode));
         memset( caEmail, 0x00, sizeof(caEmail));
         { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch 1 tb_cur_1", ECPGt_EOIT, 
	ECPGt_varchar,(caSignno),(long)45,(long)10,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(caBusinesstypecode),(long)10,(long)10,sizeof(struct varchar_2), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(caEmail),(long)40,(long)10,sizeof(struct varchar_3), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(caSignno),(long)45,(long)10,sizeof(struct varchar_1), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(caBusinesstypecode),(long)10,(long)10,sizeof(struct varchar_2), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,(caEmail),(long)40,(long)10,sizeof(struct varchar_3), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 106 "lwwfdw.pgc"
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
         //printf("id=%d, name=%s\n", caID, caName); //char name
         printf("signno=%*s, businesstypecode=%*s,  email=%*s\n", caSignno[i].len, caSignno[i].arr, caBusinesstypecode[i].len, caBusinesstypecode[i].arr, caEmail[i].len, caEmail[i].arr);//varchar name
         //break; //testing
         }
         //if(sqlca.sqlcode==100) break;
//break; //testing
        }
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close tb_cur_1", ECPGt_EOIT, ECPGt_EORT);}
#line 124 "lwwfdw.pgc"

     { ECPGtrans(__LINE__, NULL, "commit");}
#line 125 "lwwfdw.pgc"


      //EXEC SQL WHENEVER SQLERROR CALL print_sqlca();
	
     { ECPGdisconnect(__LINE__, "ALL");}
#line 129 "lwwfdw.pgc"

    
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
