// OCCIConnect.cpp
#include <iostream>
#include <occi.h>
#include <stdio.h>

using namespace std;
using namespace oracle::occi;

int main()
{
    Environment *env = Environment::createEnvironment();
    cout << "success" << endl;
    string name = "system";
    string pass = "123";
    string srvName = "192.168.26.74:1521/orcl";

    try
    {
        Connection *conn = env->createConnection(name, pass, srvName);
        cout << "conn success" << endl;

        //      数据操作,创建Statement对象
        Statement *pStmt = NULL; // Statement对象
        pStmt = conn->createStatement();
        if (NULL == pStmt)
        {
            printf("createStatement error.\n");
            return -1;
        }

        // 查询数据库时间
        std::string strTemp;
        ResultSet *pRs = pStmt->executeQuery("SELECT TO_CHAR(SYSDATE, 'YYYY-MM-DD HH24:MI:SS') FROM DUAL");
        while (pRs->next())
        {
            strTemp = pRs->getString(1);
            printf("db time:%s.\n", strTemp.c_str());
            // int类型取值用getInt()
            break;
        }
        pStmt->closeResultSet(pRs);
        //--------插入---------
        // 指定DML为自动提交
        pStmt->setAutoCommit(TRUE);
        // 设置执行的SQL语句
        //pStmt->setSQL("INSERT INTO TA (ID, NAME) VALUES (1, 'ZS')");
        pStmt->setSQL("INSERT INTO TABLE_TEST_WANG (NAME, NUM, AGE) VALUES ('胡歌', '13', '37')");

        // 执行SQL语句
        unsigned int nRet = pStmt->executeUpdate();
        if (nRet == 0)
        {
            printf("executeUpdate insert error.\n");
        }

        // 终止Statement对象
        conn->terminateStatement(pStmt);

        env->terminateConnection(conn);
    }
    catch (SQLException e)
    {
        cout << e.what() << endl;
    }

    Environment::terminateEnvironment(env);
    cout << "end!" << endl;
    return 0;
}

