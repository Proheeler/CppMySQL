#include "headers/sqlConnector.h"
#include <QString>

SQLConnector::SQLConnector()
{

    conn = mysql_init(NULL);
 /* Connect to database */
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
    {
       std::cout<<mysql_error(conn)<<std::endl;
       exit(1);
    }
}

std::string SQLConnector::getInfo()
{

//    if (mysql_query(conn, request))
//        {
//            std::cout<<mysql_error(conn)<<std::endl;
//            exit(1);
//        }

//        res = mysql_use_result(conn);

//        /* output table name */
//        printf("Result of request:\n");
//            while ((row = mysql_fetch_row(res)) != NULL)
//            {
//                      printf("%s \n", row[0]);
////                some_values1.push_back(row[0]);
//            }
////            for(auto i:some_values1){
////                std::cout<<i<<std::endl;
////            }
 }

SQLConnector::~SQLConnector()
{
    mysql_free_result(res);
    mysql_close(conn);
}
