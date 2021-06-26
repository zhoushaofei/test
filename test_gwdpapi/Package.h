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
/*������Χ�ӿ�ģ�鹦����
˵����
1�����಻֧��ͬʱ����������
	�ڶ��߳��£�ÿ���̶߳�Ӧ����һ�������ʵ����
	��ÿ���߳��ڣ��Ա����һ��ʵ����ʹ�÷�ʽ��Ӧ�������һ��������ٿ�ʼ��һ������
2���ͻ���ʹ��CreateInstance��ReleaseInstance���������ͷű����һ��ʵ����
	���������д���ʵ��������ʹ��new����
*/
class DLL_EXPORT_CLASS_DECL CPackage
{
public:
	/*���������һ��ʵ��
	ע�⣺�ͷ�ʱ��ʹ��ReleaseInstance�ӿڣ�����Ҫ����deleteʵ��
	*/
	static CPackage* CreateInstance();

	/*�ͷű���ĵ�ǰʵ��
	*/
	void ReleaseInstance();

	/*��ʼ��/����ʼ��
	*/
	bool Init();
	bool UnInit();

	/*Ҫ��ģ���������ڴ�����δ���浽�ļ�����־���浽�ļ�
	��;������û�����ȱ����������ֹǰ(��ģ��ж��ǰ)�Ĳ�����־��
	�ɳ��Ե��ñ��ӿ����������(����������ֹǰ��ģ��ж��ǰ����һ�μ���)��
	*/
	static void WriteAllLogToFile();

	/*��ȡ��ģ��İ汾��
	*/
	string GetVersion();

	//���������ܺ�
	void SetFunctionCode(const char* strFunctionCode);

	//���ð�ͷflag
	//flags = 0	���״β�ѯ��������������
	//flags = 2 	��ʾ��������ĺ�����������ʱʹ�ã���һ�����ڲ�ѯ����ġ���һҳ��ʱʹ�á�
	void SetFlags(short nNewValue);

	//������������
	void SetSerialno(const char* strSerialno);

	//�������������iRecNo��ʾ������ţ�sFieldName��ʾ��������ֵ����ƣ�sFieldValue��ʾ����Ĳ���ֵ
	bool SetValue(int iRecNo, const char* sFieldName, const char* sFieldValue);

	//��շ��Ͱ����ݣ�ͬʱҲ�Զ����Ӧ�����
	void ClearSendPackage();

	/*�����������
	����ֵ�����ʧ���򷵻�false��ͬʱ�����߿��������·�ʽ�����Ϣ
		GetValue(0, "errorCode");	//��ô������
		GetValue(0, "failinfo");	//��ô�������
	*/
	bool ExchangeMessage();

	//��ȡ�������Ӧ�����ݵ�ĳ���ֶε�ֵ��iRecNo��ʾ��ţ�sFieldName��ʾ������ֶ�����
	const char*  GetValue(int iRecNo,const char* sFieldName);

	/*�ѻ������ݽ�����һ��һ�����ֶΣ�������
	����ֵ�����ʧ���򷵻�false��ͬʱ�����߿��������·�ʽ�����Ϣ
		GetValue(0, "errorCode");	//��ô������
		GetValue(0, "failinfo");	//��ô�������
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
	/*���ع��캯��
	�û���ʹ��CreateInstance()������һ��ʵ��
	*/
	CPackage();
	virtual ~CPackage();
	void* m_pPrivate;

};
}//namespace GWDPApi

#endif//PACKAGE_H
