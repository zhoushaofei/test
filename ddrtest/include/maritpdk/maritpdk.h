#pragma once



#include <map>
#include <vector>
#include <string>
using std::string;
using std::map;
using std::vector;

#include "itpdk/itpdk_typedef.h"
#include "itpdk/itpdk_dict.h"
#include "maritpdk/maritpdk_struct.h"
using namespace MarItpdk;


//////////////////////////////////////////////////////////////////////////
//��ȡʱ������뼶����linux��winͬGetTickCount64��
ITPDK_API int64 MARITPDK_GetTickCount();
//��ȡʱ���΢�뼶����linux��winͬGetTickCount64��
ITPDK_API int64 MARITPDK_GetDoubleTickCount();
//��ѯϵͳ��������
ITPDK_API int64 MARITPDK_GetTradeDate();
////��ȡ������ϵͳ����
ITPDK_API int64 MARITPDK_GetSystemDate();
//��ȡ��������ʱ��(�����׷�����ʱ������)
ITPDK_API int64 MARITPDK_GetReviseTimeAsLong();
//��ȡ��������ʱ��(�����׷�����ʱ������)
ITPDK_API void MARITPDK_GetReviseTime(char *buffer);
//////////////////////////////////////////////////////////////////////////
//���������ļ�����·����ITPDK_Init ����ǰ������Ч
ITPDK_API void MARITPDK_SetProfilePath(const char *path);
//�����Ƿ��¼��־
ITPDK_API void MARITPDK_SetWriteLog(bool bLog);
//�����Ƿ��¼Fix��־
ITPDK_API void MARITPDK_SetFixWriteLog(bool bLog);

//��������־·����ITPDK_Init ����ǰ������Ч
ITPDK_API void MARITPDK_SetLogPath(const char *path);
//��ʼ��
ITPDK_API bool MARITPDK_Init(int commsize);
//�˳�
ITPDK_API void MARITPDK_Exit();
//��ȡ���������Ϣ�ʹ�����
ITPDK_API int64 MARITPDK_GetLastError(char *result_msg);
//�������´�����Ϣ
ITPDK_API void MARITPDK_SetLastError(int64 result_code, const char *result_msg, const char* result_text = nullptr, ITPDK_CusReqInfo* cusreqinfo = nullptr);



/*
	������Ϣ�ص�����
		��Ϣ����pMsgΪjson��

		������Ϣ -- NOTIFY_PUSH_WITHDRAW
		�ϵ���Ϣ -- NOTIFY_PUSH_INVALID
		ȷ����Ϣ -- NOTIFY_PUSH_ORDER
            WTH		int64		ί�к�
			KHH		char[]		�ͻ���
            YYB     char[]      Ӫҵ��
            GDH     char[]      �ɶ���
			JYS		char[]		������
			ZQDM	char[]		֤ȯ����
            XWH     char[]      ϯλ��
            BZ      char[]      ����
            SBJG    int64        �걨���
            JYLB    int64        �������
            CXBZ    char        ������־
            CXWTH   int64        ����ί�к�
            CJBH    char[]      �ɽ����
            CJSJ    char[]      �ɽ�ʱ��
            CJSL    int64        �ɽ�����
            CJJG    double      �ɽ��۸�
            CJJE    doube       �ɽ����
		�ɽ���Ϣ -- NOTIFY_PUSH_MATCH
			KHH		char[]		�ͻ���
			JYS		char[]		������
			ZQDM	char[]		֤ȯ����
			WTH		int64		ί�к�
			CJSL	int64		�ɽ�����
			CJJG	double		�ɽ��۸�
		�ʲ��䶯��Ϣ -- NOTIFY_ASSETVARY
			KHH		char[]		�ͻ���
			ZJZH	char[]		�ʽ��˺�
			ZZC		double		���ʲ�
			KYZJ	double		�����ʽ�
			ZXSZ	double		������ֵ

	func		[in]		�ص�����
*/
ITPDK_API void MARITPDK_SetMsgCallback(pMessageCallbackMethod func);

// �첽�ص�����
ITPDK_API void MARITPDK_SetFuncCallback(pAsyncCallbackFunc func);

// ���ӵ��ߡ��ָ��¼��ص�����
/*
pConnEventCallback

pKhh		[in]		�ͻ���
pConnKey	[in]		����������
nEvent		[in]		�¼�:��0���ָ���1���Ͽ�
pData       [in]        �����ֶ�
*/
ITPDK_API void MARITPDK_SetConnEventCallback(pConnEventCallback func);


// ����վ����Ϣ
ITPDK_API bool MARITPDK_SetNode(const char *val);

// ����ί�з�ʽ
ITPDK_API bool MARITPDK_SetWTFS(const char *val);

/*
	���׵�¼
	lpKeyName	[in]		ʹ�õ�����Keyֵ
	khh			[in]		�ͻ���
	pwd			[in]		��������
	return				�ɹ�����>0��ʧ�ܷ���<=0
*/
ITPDK_API int64 MARITPDK_TradeLogin(const char *lpKeyName, const char *khh, const char *pwd);
/*
	���׵�¼
	lpKeyName	[in]		ʹ�õ�����Keyֵ
	cusreqinfo	[in/out]	�ͻ���Ϣ
	return				�ɹ�����>0��ʧ�ܷ���<=0
*/
ITPDK_API int64 MARITPDK_TradeLoginEx(const char* lpKeyName, ITPDK_CusReqInfo& cusreqinfo);

/*
    �ǳ� 
    KhhOrZjzh			[in]		�ͻ���
*/
ITPDK_API int64 MARITPDK_TradeLogout(const char* KhhOrZjzh);


//////////////////////////////////////////////////////////
//������ӿ�
//////////////////////////////////////////////////////////

/*
	���ý���

	lpKhh		[in]		�ͻ���
	lpJys		[in]		������
	lpZqdm		[in]		֤ȯ����
	nJylb		[in]		�������(JYLB_BUY��JYLB_SALE��JYLB_RZMR��JYLB_MQHK��JYLB_MQHQ��JYLB_RQMC��JYLB_DBWTJ��JYLB_DBWFH��JYLB_HQHZ��JYLB_ZJHK��JYLB_PHDJMR��JYLB_PHDJMC)
	lWtsl		[in]		ί������
	lfWtjg		[in]		ί�м۸�(��������Ϊ�м�ʱ���ò�������Ч���������Ϊ ֱ�ӻ���ʱ������������ֶ�)
	lDdlx		[in]		��������(DDLX_XJWT,DDLX_SJWT)
	lpGdh		[in]		�ɶ���
	nTCLX		[in]		ͷ������  1��ͨͷ�� 2ר��ͷ��(����: ��0 Ĭ��ר�� ,����: ��0 ������������)
	lpHYBH		[in]		ָ��������ծ��ˮ��
	nChlx		[in]		��������: 0-���˽᷽ʽ) 1-ֻ����Ϣ
	nFlag		[in]	    ���������־����ȯ��תҵ��ר�ã� 0����ʵʱӰ�츺ծ 1����ʵʱӰ�츺 -1����û�����볷�������־��ί��
	return				�ɹ�����ί�кţ�ʧ�ܷ���<0
*/
ITPDK_API int64 MARITPDK_MarginEntrust(const char *lpKhh,const char *lpJys,const char *lpZqdm,int nJylb,int64 lWtsl,double lfWtjg, int64 lDdlx,const char *lpGdh,int nTCLX,const char * lpHYBH,int nChlx,int nFlag);
ITPDK_API int64 MARITPDK_MarginEntrustEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb, int64 lWtsl, double lfWtjg, int64 lDdlx, int nTCLX, const char* lpHYBH, int nChlx, int nFlag);

/*
	���ý��׽ӿ�(�첽)

	lpKhh		[in]		�ͻ���
	lpJys		[in]		������
	lpZqdm		[in]		֤ȯ����
	nJylb		[in]		�������(JYLB_BUY��JYLB_SALE��JYLB_RZMR��JYLB_MQHK��JYLB_MQHQ��JYLB_RQMC��JYLB_DBWTJ��JYLB_DBWFH��JYLB_HQHZ��JYLB_ZJHK��JYLB_PHDJMR��JYLB_PHDJMC)
	lWtsl		[in]		ί������
	lfWtjg		[in]		ί�м۸�(��������Ϊ�м�ʱ���ò�������Ч)
	lDdlx		[in]		��������(DDLX_XJWT,DDLX_SJWT)
	lpGdh		[in]		�ɶ���
	nTCLX		[in]		ͷ������  1��ͨͷ�� 2ר��ͷ��(����: ��0 Ĭ��ר�� ,����: ��0 ������������)
	lpHYBH		[in]		ָ��������ծ��ˮ��
	nChlx		[in]		��������: 0-���˽᷽ʽ) 1-ֻ����Ϣ
	nFlag		[in]	    ���������־����ȯ��תҵ��ר�ã� 0����ʵʱӰ�츺ծ 1����ʵʱӰ�츺
	nKFSBDBH    [in]        �����̱��ر�ţ���δ�ͣ�����itpdk�Զ�����(�Զ���ί�кţ���ȷ�ϡ��ɽ���������Ϣ�л������ֵ)
	return				�ɹ����ؿ����̱��ر�ţ�ʧ�ܷ���<0
*/
ITPDK_API int64 MARITPDK_MarginEntrust_ASync(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, int64 lWtsl, double lfWtjg, int64 lDdlx, const char* lpGdh, int nTCLX, const char* lpHYBH, int nChlx,  int nFlag, int64 nKFSBDBH = 0);
ITPDK_API int64 MARITPDK_MarginEntrustEx_ASync(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb, int64 lWtsl, double lfWtjg, int64 lDdlx, int nTCLX, const char* lpHYBH,  int nChlx ,  int nFlag, int64 nKFSBDBH = 0);


/*
	����ί����ͨ����

	lpKhh		[in]		�ͻ���
	lpGdh		[in]		�ɶ���
	lWth		[in]		ί�к�
    nJylb       [in]       �������
	return				�ɹ�����>0��ʧ�ܷ���<0
*/
ITPDK_API int64 MARITPDK_MarginOrderWithdraw(const char *lpKhh,const char *lpGdh, int64 lWth,int nJylb);
ITPDK_API int64 MARITPDK_MarginOrderWithdrawEx(ITPDK_CusReqInfo& cusreqinfo, int64 lWth, int nJylb);
/*
	����ί����ͨ����(�첽)

	lpKhh		[in]		�ͻ���
	lpGdh		[in]		�ɶ���
	lWth		[in]		ί�к�
	nJylb       [in]       �������
	nKFSBDBH	[in]        ��ˮ�ţ�͸���ֶΣ��ڻص�������ͨ����ֵƥ����ã�
								��δ�͸��ֶΣ��ɽӿ��ڲ����ɡ�
	return				�ɹ�����>0��ʧ�ܷ���<0
*/
ITPDK_API int64 MARITPDK_MarginOrderWithdraw_ASync(const char* lpKhh, const char* lpGdh, int64 lWth, int nJylb, int64 nKFSBDBH = 0);
ITPDK_API int64 MARITPDK_MarginOrderWithdrawEx_ASync(ITPDK_CusReqInfo& cusreqinfo, int64 lWth, int nJylb, int64 nKFSBDBH = 0);
/*
	����ί�п����̴��볷��

	lpKhh		[in]		�ͻ���
	lpGdh		[in]		�ɶ���
	nCxkfsbdh	[in]		����ί�к�
	nJylb       [in]       �������
	return				�ɹ�����>0��ʧ�ܷ���<0
*/
ITPDK_API int64 MARITPDK_MarginOrderKFSDMWithdraw(const char* lpKhh, const char* lpGdh, int64 nCxkfsbdh, int nJylb);
ITPDK_API int64 MARITPDK_MarginOrderKFSDMWithdrawEx(ITPDK_CusReqInfo& cusreqinfo, int64 nCxkfsbdh, int nJylb);

/*
	����ί�п����̴��볷��(�첽)

	lpKhh		[in]		�ͻ���
	lpGdh		[in]		�ɶ���
	nCxkfsbdh	[in]		����ί�к�
	nJylb       [in]       �������
	nKFSBDBH	[in]        ��ˮ�ţ�͸���ֶΣ��ڻص�������ͨ����ֵƥ����ã�
								��δ�͸��ֶΣ��ɽӿ��ڲ����ɡ�
	return				�ɹ�����>0��ʧ�ܷ���<0
*/
ITPDK_API int64 MARITPDK_MarginOrderKFSDMWithdraw_ASync(const char* lpKhh, const char* lpGdh, int64 nCxkfsbdh, int nJylb, int64 nKFSBDBH = 0);
ITPDK_API int64 MARITPDK_MarginOrderKFSDMWithdrawEx_ASync(ITPDK_CusReqInfo& cusreqinfo, int64 nCxkfsbdh, int nJylb, int64 nKFSBDBH = 0);



/*
	���ÿ�ί����������
	lpKhh		[in]		�ͻ���
	lpJys		[in]		������
	lpZqdm		[in]		֤ȯ����
	nJylb		[in]		�������(JYLB_BUY��JYLB_SALE)
	lfWtjg		[in]		ί�м۸�(��������Ϊ�м�ʱ���ò�������Ч)
	lDdlx		[in]		��������(DDLX_XJWT,DDLX_SJWT)
	lpGdh		[in]		�ɶ���
	lpDfGdh		[in]		�Է��ɶ���
	nTCLX		[in]		ͷ������  1��ͨͷ�� 2ר��ͷ��
	nCHBZ       [in]        ������־��0-���� 1-��ͨ 2-ר��
	lpHYBH      [in]        ��Լ��ţ���ȯ��ת��ָ����Լ��ţ�

*/
ITPDK_API int64 MARITPDK_MarginTradableQty(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, double lfWtjg, int64 lDdlx, const char* lpGdh, const char* lpDfGdh, int nTCLX, int nCHBZ, const char* lpHYBH);
ITPDK_API int64 MARITPDK_MarginTradableQtyEx(ITPDK_CusReqInfo& cusreqinfo,const char *lpJys,const char *lpZqdm,int nJylb,double lfWtjg, int64 lDdlx ,int nTCLX, int nCHBZ, const char* lpHYBH);


//////////////////////////////////////////////////////////
//��ѯ��ӿ�
//////////////////////////////////////////////////////////


/*
	��ѯ�ʽ���Ϣ

	khh			[in]		�ͻ���
	arInfo		[out]		�������
	return				���ز�ѯ���ļ�¼��
*/
ITPDK_API int64 MARITPDK_QueryFundInfo(const char* khh, vector<ITPDK_XYZJZH>& arInfo);
ITPDK_API int64 MARITPDK_QueryFundInfoEx(ITPDK_CusReqInfo& cusreqinfo, vector<ITPDK_XYZJZH>& arInfo);

/*
	��ѯ�ɶ���Ϣ

	khh			[in]		�ͻ���
	arInfo		[out]		�������
	return				���ز�ѯ���ļ�¼��
*/
ITPDK_API int64 MARITPDK_QueryAccInfo(const char* khh, vector<ITPDK_XYGDH>& arInfo);
ITPDK_API int64 MARITPDK_QueryAccInfoEx(ITPDK_CusReqInfo& cusreqinfo, vector<ITPDK_XYGDH>& arInfo);

/*
	��ѯ���ø�ծ

	lpKhh		[in]		�ͻ���
	lpJys		[in]		������
	lpGdh		[in]		�ɶ���
	lpZqdm		[in]		֤ȯ����
	lpHybh		[in]		��Լ���
	nJylb		[in]		�������
	nRowcount	[in]		��������
	nBrowindex	[in]		��ҳ������
	nKsrq		[in]		��ʼ����
	nJsrq		[in]		��������
	lWth		[in]		ί�к�
	nType		[in]		�Ƿ��˽�(0 ���к�Լ,1 ���˽� 2δ�˽�)
	nTclx		[in]		ͷ������(0 �������� 1 ��ͨ 2 ר��)
	arInfo		[out]		�������
	return  ��������

*/
ITPDK_API int64 MARITPDK_QueryDebts(const char* lpKhh, const char* lpJys, const char* lpGdh, const char* lpZqdm, const char* lpHybh, int64 nJylb, int64 nRowcount, const char* nBrowindex, int64 nKsrq, int64 nJsrq, int64 lWth, int64 nType, int64 nTclx, vector<ITPDK_XYFZ>& arInfo);
ITPDK_API int64 MARITPDK_QueryDebtsEx(ITPDK_CusReqInfo& cusreqinfo, const char * lpJys,const char * lpZqdm ,const char * lpHybh, int64 nJylb, int64 nRowcount, const char * nBrowindex, int64 nKsrq, int64 nJsrq, int64 lWth, int64 nType, int64 nTclx, vector<ITPDK_XYFZ>& arInfo);


/*
	���ڲ�ѯ����ί��

	khh			[in]		�ͻ���
	nType		[in]		�Ƿ����ѯ�ɳ�ί�У�0��ѯȫ����1��ѯ�ɳ���
	nSortType	[in]		����ʽ����ǰ��֧������
	nRowcount	[in]		��������
	nBrowindex	[in]		��ҳ����ί�кţ�
	jys			[in]		��������Ϊ��ʱ��ѯ���н�������
	zqdm		[in]		֤ȯ���루Ϊ��ʱ��ѯ���д��룩
	nJylb		[in]		�������
	sCxbz		[in]		������־
	lWth		[in]		ί�кţ�Ϊ��ʱ��ѯ����ί�кţ�
	arInfo		[out]		�������
	return				���ز�ѯ���ļ�¼��
*/
ITPDK_API int64 MARITPDK_QueryOrders_MR_DRWT(const char* khh, int nType, int nSortType, int nRowcount, int64 nBrowindex, const char* jys, const char* zqdm, int nJylb, const char* sCxbz, int64 lWth, vector<ITPDK_XYDRWT>& arInfo);
ITPDK_API int64 MARITPDK_QueryOrders_MR_DRWTEx(ITPDK_CusReqInfo& cusreqinfo, int nType, int nSortType, int nRowcount, int64 nBrowindex, const char *jys, const char *zqdm, int nJylb, const char *sCxbz, int64 lWth, vector<ITPDK_XYDRWT>& arInfo);

/*
	���ڲ�ѯʵʱ�ɽ�


	khh			[in]		�ͻ���
	nType		[in]		�Ƿ��ѯ�ɳ���ί�в��֣�0��ѯȫ����1 ���� ��������CDSL>0���֣�  
	nSortType	[in]		����ʽ��0����1����
	nRowcount	[in]		��������
	nBrowindex	[in]		��ҳ�����ɽ���ţ�
	jys			[in]		��������Ϊ��ʱ��ѯ���н�������
	zqdm		[in]		֤ȯ���루Ϊ��ʱ��ѯ���д��룩
	nJylb		[in]		�������	
	lWth		[in]		ί�кţ�Ϊ��ʱ��ѯ����ί�кţ�
	arInfo		[out]		�������
	return				���ز�ѯ���ļ�¼��
*/
ITPDK_API int64 MARITPDK_QueryMatchs_MR_SSCJ(const char *khh, int nType, int nSortType, int nRowcount, int64 nBrowindex, const char *jys, const char *zqdm,int nJylb, int64 lWth, vector<ITPDK_XYSSCJ>& arInfo);
ITPDK_API int64 MARITPDK_QueryMatchs_MR_SSCJEx(ITPDK_CusReqInfo& cusreqinfo, int nType, int nSortType, int nRowcount, int64 nBrowindex, const char* jys, const char* zqdm, int nJylb, int64 lWth, vector<ITPDK_XYSSCJ>& arInfo);

/*
	���ڲ�ѯ�ֲ�


	khh			[in]		�ͻ���
	nFlag		[in]		��չ��־��0����չ��1��չ��
	nSortType	[in]		����ʽ����ǰ��֧������
	nRowcount	[in]		��������
	nBrowindex	[in]		��ҳ����ί�кţ�
	gdh			[in]		�ɶ���
	jys			[in]		��������Ϊ��ʱ��ѯ���н�������
	zqdm		[in]		֤ȯ���루Ϊ��ʱ��ѯ���д��룩
	arInfo		[out]		�������
	
	return				���ز�ѯ���ļ�¼��
*/
ITPDK_API int64 MARITPDK_QueryPosition_MR_ZQGL(const char *khh, int nFlag, int nSortType, int nRowcount, int64 nBrowindex,const char * gdh, const char *jys, const char *zqdm, vector<ITPDK_XYZQGL>& arInfo);
ITPDK_API int64 MARITPDK_QueryPosition_MR_ZQGLEx(ITPDK_CusReqInfo& cusreqinfo, int nFlag, int nSortType, int nRowcount, int64 nBrowindex, const char* jys, const char* zqdm, vector<ITPDK_XYZQGL>& arInfo);

/*
	���ڲ�ѯ�����ʲ�


	khh			[in]		�ͻ���
	jys			[in]		������
	zqdm		[in]		֤ȯ����
	nFlag		[in]		��չ��־��0����չ��1��չ��
	
	arInfo		[out]		�������
	return				���ز�ѯ���ļ�¼��
*/
ITPDK_API int64 MARITPDK_QueryTradeData_MR_XYZC(const char *khh, const char* jys, const char* zqdm, int nFlag , vector<ITPDK_XYZC>& arInfo);
ITPDK_API int64 MARITPDK_QueryTradeData_MR_XYZCEx(ITPDK_CusReqInfo& cusreqinfo, const char* jys, const char* zqdm, int nFlag, vector<ITPDK_XYZC>& arInfo);


/*
	���ڲ�ѯ�ͻ�����ȯ��Ϣ


    khh			[in]		�ͻ���
	jys			[in]		������
	zqdm		[in]		֤ȯ����
	tcxz		[in]		ͷ����Դ(1 ��ͨͷ�� 2 ר��ͷ�� 0����)
	nRowcount	[in]		��������
	nBrowindex	[in]		��ҳ������
	arInfo		[out]		�������
		
	return				���ز�ѯ���ļ�¼��
*/
ITPDK_API int64 MARITPDK_QueryTradeData_MR_KRQXX(const char *khh,const char * jys,const char * zqdm ,int32 tcxz, int nRowcount, int64 nBrowindex, vector<ITPDK_RQZQ>& arInfo);
ITPDK_API int64 MARITPDK_QueryTradeData_MR_KRQXXEx(ITPDK_CusReqInfo& cusreqinfo, const char* jys, const char* zqdm, int32 tcxz, int nRowcount, int64 nBrowindex, vector<ITPDK_RQZQ>& arInfo);

/*
	���ڲ�ѯ�ͻ������ʽ���Ϣ


	khh			[in]		�ͻ���
	tcxz		[in]		ͷ����Դ(1 ��ͨͷ�� 2 ר��ͷ�� 0����)
	arInfo		[out]		�������

	return				���ز�ѯ���ļ�¼��
*/
ITPDK_API int64 MARITPDK_QueryTradeData_MR_KRZJXX(const char* khh, int32 tcxz, vector<ITPDK_KRZJXX>& arInfo);
ITPDK_API int64 MARITPDK_QueryTradeData_MR_KRZJXXEx(ITPDK_CusReqInfo& cusreqinfo, int32 tcxz, vector<ITPDK_KRZJXX>& arInfo);



