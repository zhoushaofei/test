#if !defined(__MA_CLI_FUTURE_TRADE_API_H__)
#define __MA_CLI_FUTURE_TRADE_API_H__

#include "maCliApi.h"
#include "maCliTradeApi.h"
#include "maCliFutureTradeApiStruct.h"

BGN_NAMESPACE_MACLI

class MATRADEAPI CCliFutureTradeSpi : virtual public CCliTradeSpi
{
public:
	// �û���¼������Ӧ
	virtual int OnRspUserLogin(CFirstSetField *p_pFirstSetField, CRspFutureUserLoginField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
	//�ڻ��ǳ�
	virtual int OnRspUserLogout(CFirstSetField *p_pFirstSet, CRspFutureUserLogoutField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
	//����¼��
	virtual int OnRspOrder(CFirstSetField *p_pFirstSet, CRspFutureOrderField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
	//��������
	virtual int OnRspChgOrder(CFirstSetField *p_pFirstSet, CRspFutureChgOrderField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
	//������ѯ
	virtual int OnRspQryOrderInfo(CFirstSetField *p_pFirstSet, CRspFutureOrderInfoField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
	//�ɽ���ѯ
	virtual int OnRspQryMatchInfo(CFirstSetField *p_pFirstSet, CRspFutureMatchInfoField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
	//Ͷ���߲�ѯ
	virtual int OnRspQryCustInfo(CFirstSetField *p_pFirstSet, CRspFutureCustInfoField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
	//Ͷ���ֲֲ߳�ѯ
	virtual int OnRspQryPosInfo(CFirstSetField *p_pFirstSet, CRspFuturePosInfoField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
	//��Լ��ѯ
	virtual int OnRspQryContractInfo(CFirstSetField *p_pFirstSet, CRspFutureContractInfoField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
	//Ͷ�����ʽ��ѯ
	virtual int OnRspQryFundInfo(CFirstSetField *p_pFirstSet, CRspFutureFundInfoField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
	//���ɿ�������
	virtual int OnRspQryAvlQty(CFirstSetField *p_pFirstSet, CRspFutureAvlQtyField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
	//����ƽ������
	virtual int OnRspQryAvlPos(CFirstSetField *p_pFirstSet, CRspFutureAvlPosField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
	//�ͻ�����ѯ
	virtual int OnRspQryUsersOnline(CFirstSetField *p_pFirstSet, CRspFutureUsersOnlineField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
	//�������ʲ�ѯ
	virtual int OnRspQryFee(CFirstSetField *p_pFirstSet, CRspFutureFeeField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
	//��֤���ʲ�ѯ
	virtual int OnRspQryMargin(CFirstSetField *p_pFirstSet, CRspFutureMarginField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
	//�������ڲ�ѯ
	virtual int OnRspQryDateInfo(CFirstSetField *p_pFirstSet, CRspFutureDateInfoField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
	//ί������
	virtual int OnRtnOrder(CRtnFutureOrderField* p_pField){return 0;}
	//�ɽ�����
	virtual int OnRtnMatch(CRtnFutureMatchField* p_pField){return 0;}
private:

};

class MATRADEAPI CCliFutureTradeApi : virtual public CCliTradeApi
{
public:
	// Ĭ�Ϲ��캯��
	CCliFutureTradeApi(void);
	// ��������
	virtual ~CCliFutureTradeApi(void);
	
	// �û���¼����
	virtual int ReqUserLogin(CReqFutureUserLoginField *p_pReqField, LONGLONG p_llRequestId);
	//�ڻ��ǳ�
	virtual int ReqUserLogout(CReqFutureUserLogoutField *p_pReqField, LONGLONG p_llRequestId);	
	//����¼��
	virtual int ReqOrder(CReqFutureOrderField *p_pReqField, LONGLONG p_llRequestId);	
	//��������
	virtual int ReqChgOrder(CReqFutureChgOrderField *p_pReqField, LONGLONG p_llRequestId);	
	//������ѯ
	virtual int ReqQryOrderInfo(CReqFutureOrderInfoField *p_pReqField, LONGLONG p_llRequestId);	
	//�ɽ���ѯ
	virtual int ReqQryMatchInfo(CReqFutureMatchInfoField *p_pReqField, LONGLONG p_llRequestId);	
	//Ͷ���߲�ѯ
	virtual int ReqQryCustInfo(CReqFutureCustInfoField *p_pReqField, LONGLONG p_llRequestId);	
	//Ͷ���ֲֲ߳�ѯ
	virtual int ReqQryPosInfo(CReqFuturePosInfoField *p_pReqField, LONGLONG p_llRequestId);	
	//��Լ��ѯ
	virtual int ReqQryContractInfo(CReqFutureContractInfoField *p_pReqField, LONGLONG p_llRequestId);	
	//Ͷ�����ʽ��ѯ
	virtual int ReqQryFundInfo(CReqFutureFundInfoField *p_pReqField, LONGLONG p_llRequestId);	
	//���ɿ�������
	virtual int ReqQryAvlQty(CReqFutureAvlQtyField *p_pReqField, LONGLONG p_llRequestId);	
	//����ƽ������
	virtual int ReqQryAvlPos(CReqFutureAvlPosField *p_pReqField, LONGLONG p_llRequestId);	
	//�ͻ�����ѯ
	virtual int ReqQryUsersOnline(CReqFutureUsersOnlineField *p_pReqField, LONGLONG p_llRequestId);	
	//�������ʲ�ѯ
	virtual int ReqQryFee(CReqFutureFeeField *p_pReqField, LONGLONG p_llRequestId);	
	//��֤���ʲ�ѯ
	virtual int ReqQryMargin(CReqFutureMarginField *p_pReqField, LONGLONG p_llRequestId);	
	//�������ڲ�ѯ
	virtual int ReqQryDateInfo(CReqFutureDateInfoField *p_pReqField, LONGLONG p_llRequestId);

public:
	// �첽�ص�����
	void OnArCallback(const char *p_pszMsgId, const unsigned char *p_pszDataBuff, int p_iDataLen);
	// �����ص�����
	void OnPsCallback(const char *p_pszAcceptSn, const unsigned char *p_pszDataBuff, int p_iDataLen);
	
private:
	// �û���¼������Ӧ
	void OnRspUserLogin(CFirstSetField *p_pFirstSetField, LONGLONG  p_llRequestId, int p_iFieldNum);	
	//�ڻ��ǳ�
	void OnRspUserLogout(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);	
	//����¼��
	void OnRspOrder(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);	
	//��������
	void OnRspChgOrder(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);	
	//������ѯ
	void OnRspQryOrderInfo(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);	
	//�ɽ���ѯ
	void OnRspQryMatchInfo(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);	
	//Ͷ���߲�ѯ
	void OnRspQryCustInfo(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);	
	//Ͷ���ֲֲ߳�ѯ
	void OnRspQryPosInfo(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);	
	//��Լ��ѯ
	void OnRspQryContractInfo(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);	
	//Ͷ�����ʽ��ѯ
	void OnRspQryFundInfo(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);	
	//���ɿ�������
	void OnRspQryAvlQty(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);	
	//����ƽ������
	void OnRspQryAvlPos(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);	
	//�ͻ�����ѯ
	void OnRspQryUsersOnline(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);	
	//�������ʲ�ѯ
	void OnRspQryFee(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);	
	//��֤���ʲ�ѯ
	void OnRspQryMargin(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);	
	//�������ڲ�ѯ
	void OnRspQryDateInfo(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);

private:

};

END_NAMESPACE_MACLI

#endif//__MA_CLI_FUTURE_TRADE_API_H__