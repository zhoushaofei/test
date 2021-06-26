#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

using namespace std;

#ifdef  WIN32
#ifdef __cplusplus 
#define DLL_EXPORT_C_DECL extern "C" __declspec(dllexport)
#define DLL_IMPORT_C_DECL extern "C" __declspec(dllimport)
#define DLL_EXPORT_DECL extern __declspec(dllexport)
#define DLL_IMPORT_DECL extern __declspec(dllimport)
#define DLL_EXPORT_CLASS_DECL __declspec(dllexport)
#define DLL_IMPORT_CLASS_DECL __declspec(dllimport)
#else
#define DLL_EXPORT_DECL __declspec(dllexport)
#define DLL_IMPORT_DECL __declspec(dllimport)
#endif
#else
#ifdef __cplusplus
#define DLL_EXPORT_C_DECL extern "C"
#define DLL_IMPORT_C_DECL extern "C"
#define DLL_EXPORT_DECL extern
#define DLL_IMPORT_DECL extern
#define DLL_EXPORT_CLASS_DECL
#define DLL_IMPORT_CLASS_DECL
#else
#define DLL_EXPORT_DECL extern
#define DLL_IMPORT_DECL extern
#endif
#endif

namespace GWDPApi
{
/*根网外围接口模块功能类
说明：
1）本类不支持同时处理多个请求。
	在多线程下，每个线程都应创建一个本类的实例。
	在每个线程内，对本类的一个实例的使用方式，应该是完成一次请求后，再开始下一个请求。
2）客户须使用CreateInstance和ReleaseInstance来创建、释放本类的一个实例，
	而不能自行创建实例（包括使用new）。
*/
class DLL_EXPORT_CLASS_DECL CPackage
{
public:
	/*创建本类的一个实例
	注意：释放时需使用ReleaseInstance接口，而不要自行delete实例
	*/
	static CPackage* CreateInstance();

	/*释放本类的当前实例
	*/
	void ReleaseInstance();

	/*初始化/反初始化
	*/
	bool Init();
	bool UnInit();

	/*要求本模块立即把内存中尚未保存到文件的日志保存到文件
	用途：如果用户发现缺少主程序终止前(或本模块卸载前)的部分日志，
	可尝试调用本接口来解决问题(在主程序终止前或本模块卸载前调用一次即可)。
	*/
	static void WriteAllLogToFile();

	/*获取本模块的版本号
	*/
	string GetVersion();

	//设置请求功能号
	void SetFunctionCode(const char* strFunctionCode);

	//设置包头flag
	//flags = 0	在首次查询或者其他操作。
	//flags = 2 	表示连续请求的后续请求（请求时使用），一般用于查询请求的“下一页”时使用。
	void SetFlags(short nNewValue);

	//设置请求包序号
	void SetSerialno(const char* strSerialno);

	//设置请求参数，iRecNo表示请求域号，sFieldName表示数据项的字典名称，sFieldValue表示具体的参数值
	bool SetValue(int iRecNo, const char* sFieldName, const char* sFieldValue);

	//清空发送包数据（同时也自动清空应答包）
	void ClearSendPackage();

	/*与服务器交互
	返回值：如果失败则返回false，同时调用者可以用以下方式获得信息
		GetValue(0, "errorCode");	//获得错误代码
		GetValue(0, "failinfo");	//获得错误描述
	*/
	bool ExchangeMessage();

	//获取解析后的应答数据的某个字段的值，iRecNo表示域号，sFieldName表示请求的字段名称
	const char*  GetValue(int iRecNo,const char* sFieldName);

	/*把缓冲数据解析成一个一个的字段，供访问
	返回值：如果失败则返回false，同时调用者可以用以下方式获得信息
		GetValue(0, "errorCode");	//获得错误代码
		GetValue(0, "failinfo");	//获得错误描述
	*/
	bool ChangeToStruct(char* byBuf, int lLen);

	// caller gets an integer that is not less than the stream length
	int EstimateToStreamLength();
	// caller must ensure that buf is long enough.
	bool ChangeToStreamChecked(char *buf, int lLen);

	// Added on 2014.6.23 by Luo Ji (intern)
	// User must ensure that outBuff is 6 times the length of plain or larger.
	void EncryptUnsafe(char *plain, char *password, char *outBuff);
	void DecryptUnsafe(char *plain, char *password, char *outBuff);
	
protected:
	/*隐藏构造函数
	用户须使用CreateInstance()来创建一个实例
	*/
	CPackage();
	virtual ~CPackage();
	void* m_pPrivate;

};
}//namespace GWDPApi

#endif//PACKAGE_H
