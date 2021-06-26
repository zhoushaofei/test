#include <unistd.h>
#include <iostream>
#include "sql.h"
#include "sqlext.h"

using namespace std;

#define CHECK_ERROR(e, s, h, t) ({\
            if (e!=SQL_SUCCESS && e != SQL_SUCCESS_WITH_INFO) {extract_error(s, h, t); goto exit;} \
})

void extract_error(const char *fn, SQLHANDLE handle, SQLSMALLINT type)
{
	SQLINTEGER i = 0;
	SQLINTEGER NativeError;
	SQLCHAR SQLState[7];
	SQLCHAR MessageText[256];
	SQLSMALLINT TextLength;
	SQLRETURN ret;

	do
	{
		ret = SQLGetDiagRec(type, handle, ++i, SQLState, &NativeError, MessageText, sizeof(MessageText), &TextLength);
		if (SQL_SUCCEEDED(ret)) {
            cout << fn << "|" << SQLState << "|" << i << "|" << NativeError << "|" << MessageText << endl;
		}
	} while (ret == SQL_SUCCESS);
}

int main()
{
    cout << "hello" << endl;

    setenv("ODBCSYSINI", "/root/upchina/test/odbctest/msodbcsql17/etc/", 1);
    chdir("/root/upchina/test/odbctest/");

	SQLHENV _hEnv = SQL_NULL_HENV;  // Environment
	SQLHDBC _hDbc = SQL_NULL_HDBC;  // Connection handle
	// SQLHSTMT _hStmt = SQL_NULL_HSTMT;  // Statement handle
	SQLRETURN ret;

    SQLCHAR* driver = (SQLCHAR*)("Driver={ODBC Driver 17 for SQL Server};Server=172.16.8.11;"
        "Address=172.16.8.11,1455;Network=dbmssocn;Database=run;"
        "Uid=sa;Pwd=SZkingdom898;");

	// Allocate environment handle
	ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &_hEnv);
    cout << "SQLAllocHandle, ret=" << ret << endl;
	CHECK_ERROR(ret, "SQLAllocHandle(SQL_HANDLE_ENV)", _hEnv, SQL_HANDLE_ENV);

	// Set the ODBC version environment attribute
	ret = SQLSetEnvAttr(_hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);
    cout << "SQLSetEnvAttr, ret=" << ret << endl;
	CHECK_ERROR(ret, "SQLSetEnvAttr(SQL_ATTR_ODBC_VERSION)", _hEnv, SQL_HANDLE_ENV);

	// Allocate connection handle
	ret = SQLAllocHandle(SQL_HANDLE_DBC, _hEnv, &_hDbc);
    cout << "SQLAllocHandle, ret=" << ret << endl;
	CHECK_ERROR(ret, "SQLAllocHandle(SQL_HANDLE_DBC)", _hDbc, SQL_HANDLE_DBC);

	// Set login timeout to 5 seconds
	ret = SQLSetConnectAttr(_hDbc, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0);
    cout << "SQLSetConnectAttr, ret=" << ret << endl;
	CHECK_ERROR(ret, "SQLSetConnectAttr(SQL_LOGIN_TIMEOUT)", _hDbc, SQL_HANDLE_DBC);

	ret = SQLDriverConnect(_hDbc, NULL, driver, SQL_NTS, NULL, 0, NULL, SQL_DRIVER_NOPROMPT);
    cout << "SQLDriverConnect, ret=" << ret << endl;
	CHECK_ERROR(ret, "SQLDriverConnect()", _hDbc, SQL_HANDLE_DBC);

exit:
    return 0;
}