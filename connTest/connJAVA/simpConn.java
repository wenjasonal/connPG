 package  com.test;
 import  org.postgresql. * ;
 import  java.sql. * ;

 public   class  TestDB  {
     public  TestDB()  {
    } 
     public   static   void  main(String args[])
     {
        System.out.print( " this is a test " );
         try 
          {
            Class.forName( " org.postgresql.Driver " ).newInstance();
            String url = " jdbc:postgresql://localhost:5432/postgres " ;
            Connection con = DriverManager.getConnection(url, " postgres " , " 1234 " );
            Statement st = con.createStatement();
            String sql = " select * from testtable " ;
            ResultSet rs = st.executeQuery(sql);
             while (rs.next())
             {
                System.out.print(rs.getInt( 1 ));
                System.out.println(rs.getString( 2 ));
            } 
            rs.close();
            st.close();
            con.close();
            

        } 
         catch (Exception ee)
         {
            System.out.print(ee.getMessage());
        } 
    } 
}
