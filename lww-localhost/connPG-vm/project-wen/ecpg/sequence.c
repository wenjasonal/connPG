/* Processed by ecpg (4.12.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "sequence.pgc"
#include <stdlib.h>

int main()
{
  /* exec sql whenever sqlerror  sqlprint ; */
#line 5 "sequence.pgc"

  { ECPGconnect(__LINE__, 0, "test@10.136.1.143:5432" , "lww" , "lww" , NULL, 0); 
#line 6 "sequence.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 6 "sequence.pgc"

  /*
  if(sqlca.sqlcode)
    printf("Connect database ERROR! sqlca.sqlcode=%s!\n", sqlca.sqlcode);
  else
    printf("Connect database OK!\n");
  */
  /* exec sql begin declare section */
     
     
     
     
     
     
  
#line 14 "sequence.pgc"
 long lastVal ;
 
#line 15 "sequence.pgc"
 long session_lastVal ;
 
#line 16 "sequence.pgc"
 long nextVal [ 5 ] ;
 
#line 17 "sequence.pgc"
 long currVal ;
 
#line 18 "sequence.pgc"
 long setVal ;
 
#line 19 "sequence.pgc"
 int i ;
/* exec sql end declare section */
#line 20 "sequence.pgc"


  //EXEC SQL DROP SEQUENCE myseq;
  /*//first test
    EXEC SQL CREATE SEQUENCE myseq 
           MINVALUE 1
           MAXVALUE 999999
           START WITH 1
           INCREMENT BY 1
           CACHE 5 
           CYCLE;
  EXEC SQL COMMIT; 
  */
  for(i=0; i<3; i++)
  {  
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select nextval ( 'myseq' )", ECPGt_EOIT, 
	ECPGt_long,&(nextVal[i]),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 35 "sequence.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 35 "sequence.pgc"

    printf("The sequence next_value: nextval%d = %d\n", i, nextVal[i]);
   }
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select currval ( 'myseq' )", ECPGt_EOIT, 
	ECPGt_long,&(currVal),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 38 "sequence.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 38 "sequence.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select last_value from myseq", ECPGt_EOIT, 
	ECPGt_long,&(lastVal),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 39 "sequence.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 39 "sequence.pgc"

  printf("The sequence current_value of my session: currval = %d\n", currVal);
  printf("The sequence last_value of my session: lastval = %d\n", lastVal);

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select setval ( 'myseq' , 1 )", ECPGt_EOIT, 
	ECPGt_long,&(setVal),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 43 "sequence.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 43 "sequence.pgc"

  printf("setval()--manual set the sequence's value：setVal = %d\n", setVal);

  { ECPGdisconnect(__LINE__, "ALL");
#line 46 "sequence.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 46 "sequence.pgc"


  /* exec sql whenever sqlerror  sqlprint ; */
#line 48 "sequence.pgc"

  { ECPGconnect(__LINE__, 0, "test@10.136.1.143:5432" , "lww" , "lww" , NULL, 0); 
#line 49 "sequence.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 49 "sequence.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select nextval ( 'myseq' )", ECPGt_EOIT, 
	ECPGt_long,&(nextVal[0]),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 50 "sequence.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 50 "sequence.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select lastval ( )", ECPGt_EOIT, 
	ECPGt_long,&(session_lastVal),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 51 "sequence.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 51 "sequence.pgc"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select last_value from myseq", ECPGt_EOIT, 
	ECPGt_long,&(lastVal),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 52 "sequence.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 52 "sequence.pgc"

  printf("after reconnect db get nextval(): nextval = %d\n", nextVal[0]);
  printf("lastval()--the last value in current session had been used: session_lastval = %d\n", session_lastVal);
  printf("after reconnect db get last_value (about cache): lastval = %d\n", lastVal);
 
  { ECPGdisconnect(__LINE__, "ALL");
#line 57 "sequence.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 57 "sequence.pgc"

  return 0;  
 }
