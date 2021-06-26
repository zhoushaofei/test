#if !defined(__MA_CLI_FISL_TRADE_API_H__)
#define __MA_CLI_FISL_TRADE_API_H__

#include "maCliTradeApi.h"
#include "maCliFislTradeApiStruct.h"

BGN_NAMESPACE_MACLI

class MATRADEAPI CCliFislTradeSpi : virtual public CCliTradeSpi
{
public:
  // ���ȯ��Ϣ��ѯ��Ӧ
  virtual int OnRspQryUndlStkInfo(CFirstSetField *p_pFirstSetField, CRspFislQryUndlStkInfoField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ����֤ȯ��Ϣ��ѯ��Ӧ
  virtual int OnRspQryColStkInfo(CFirstSetField *p_pFirstSetField, CRspFislQryColStkInfoField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // LOF��Ϣ��ѯ
  virtual int OnRspQryLofInfo(CFirstSetField *p_pFirstSetField, CRspFislQryLofInfoField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ����ί����Ӧ
  virtual int OnRspOrder(CFirstSetField *p_pFirstSetField, CRspFislOrderField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ί�г�����Ӧ
  virtual int OnRspCancelOrder(CFirstSetField *p_pFirstSetField, CRspFislCancelOrderField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ���ɽ�����������Ӧ
  virtual int OnRspMaxTradeQty(CFirstSetField *p_pFirstSetField, CRspFislMaxTradeQtyField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ������ȯֱ�ӻ�����Ӧ
  virtual int OnRspMarginRepay(CFirstSetField *p_pFirstSetField, CRspFislMarginRepayField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �����ʽ��ѯ��Ӧ
  virtual int OnRspQryExpendableFund(CFirstSetField *p_pFirstSetField, CRspFislQryExpendableFundField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ���ùɷݲ�ѯ��Ӧ
  virtual int OnRspQryExpendableShares(CFirstSetField *p_pFirstSetField, CRspFislQryExpendableSharesField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ����ί�в�ѯ��Ӧ
  virtual int OnRspQryCurrDayOrder(CFirstSetField *p_pFirstSetField, CRspFislQryCurrDayOrderField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ���ճɽ���ѯ��Ӧ
  virtual int OnRspQryCurrDayFill(CFirstSetField *p_pFirstSetField, CRspFislQryCurrDayFillField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �ɶ��˻���ѯ��Ӧ
  virtual int OnRspQryStkholderAcct(CFirstSetField *p_pFirstSetField, CRspFislQryStkholderAcctField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �ɳ���ί�в�ѯ��Ӧ
  virtual int OnRspQryCanWithdrawOrder(CFirstSetField *p_pFirstSetField, CRspFislQryCanWithdrawOrderField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �����ʽ��ѯ��Ӧ[����]
  virtual int OnRspQryExpendableFundEx(CFirstSetField *p_pFirstSetField, CRspFislQryExpendableFundExField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ���ùɷݲ�ѯ��Ӧ[����]
  virtual int OnRspQryExpendableSharesEx(CFirstSetField *p_pFirstSetField, CRspFislQryExpendableSharesExField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ����ί�в�ѯ��Ӧ[����]
  virtual int OnRspQryCurrDayOrderEx(CFirstSetField *p_pFirstSetField, CRspFislQryCurrDayOrderExField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ���ճɽ���ѯ��Ӧ[����]
  virtual int OnRspQryCurrDayFillEx(CFirstSetField *p_pFirstSetField, CRspFislQryCurrDayFillExField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �ɶ��˻���ѯ��Ӧ[����]
  virtual int OnRspQryStkholderAcctEx(CFirstSetField *p_pFirstSetField, CRspFislQryStkholderAcctExField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �ɳ���ί�в�ѯ��Ӧ[����]
  virtual int OnRspQryCanWithdrawOrderEx(CFirstSetField *p_pFirstSetField, CRspFislQryCanWithdrawOrderExField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ������ȯЭ���ѯ��Ӧ
  virtual int OnRspQryMarginProtocol(CFirstSetField *p_pFirstSetField, CRspFislQryMarginProtocolField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ������ȯ��Լ��ѯ��Ӧ
  virtual int OnRspQryMarginContract(CFirstSetField *p_pFirstSetField, CRspFislQryMarginContractField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ������ȯ��֤���������ѯ��Ӧ
  virtual int OnRspQryMarginDepositAvl(CFirstSetField *p_pFirstSetField, CRspFislQryMarginDepositAvlField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ������ȯ���ÿ��ö�Ȳ�ѯ��Ӧ
  virtual int OnRspQryMarginCreditAvl(CFirstSetField *p_pFirstSetField, CRspFislQryMarginCreditAvlField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ���ÿͻ��ʲ���ծ��ѯ��Ӧ
  virtual int OnRspQryCreditCustDebts(CFirstSetField *p_pFirstSetField, CRspFislQryCreditCustDebtsField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ������ȯ�ʽ�ͷ���ѯ��Ӧ
  virtual int OnRspQryMarginFundCash(CFirstSetField *p_pFirstSetField, CRspFislQryMarginFundCashField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ������ȯ�ɷ�ͷ���ѯ��Ӧ
  virtual int OnRspQryMarginSharesCash(CFirstSetField *p_pFirstSetField, CRspFislQryMarginSharesCashField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  
  // �ɳ�������ѯ��Ӧ
  virtual int OnRspQryCanRepay(CFirstSetField *p_pFirstSetField, CRspFislQryCanRepayField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ֤ȯ��ֵ��Ȳ�ѯ��Ӧ
  virtual int OnRspQryMktQuota(CFirstSetField *p_pFirstSetField, CRspFislMktQuotaField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ���ʺ�Լ���ܲ�ѯ��Ӧ
  virtual int OnRspQryFiContractSum(CFirstSetField *p_pFirstSetField, CRspFislQryFiContractSumField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // ��ȯ��Լ���ܲ�ѯ��Ӧ
  virtual int OnRspQrySlContractSum(CFirstSetField *p_pFirstSetField, CRspFislQrySlContractSumField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �ʽ𻮲���Ӧ
  virtual int OnRspQryFundTransfer(CFirstSetField *p_pFirstSetField, CRspFislFundTransferField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �û���¼������Ӧ
  virtual int OnRspUserLogin(CFirstSetField *p_pFirstSetField, CRspFislUserLoginField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  
  // ȷ�ϻر�
  virtual int OnRtnOrderConfirm(CRtnFislOrderConfirmField *p_pRtnOrderConfirmField) {return 0;}

  // �ɽ��ر�
  virtual int OnRtnOrderFill(CRtnFislOrderFillField *p_pRtnOrderFillField) {return 0;}

  // ������ȯ��ծ������ˮ��ѯ[����]��Ӧ
  virtual int OnRspQryRpcRepaymentDetail(CFirstSetField *p_pFirstSetField, CRspFislQryRpcRepaymentDetailField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ʽ��ѯ[����]��Ӧ
  virtual int OnRspQryRpcFund(CFirstSetField *p_pFirstSetField, CRspFislQryRpcFundField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �����ʽ���ˮ��ѯ[����]��Ӧ
  virtual int OnRspQryRpcFundDetail(CFirstSetField *p_pFirstSetField, CRspFislQryRpcFundDetailField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �¹��깺�ͻ���ֵ��Ȳ�ѯ[����]��Ӧ
  virtual int OnRspQryRpcIPOSubscriptionLimit(CFirstSetField *p_pFirstSetField, CRspFislQryRpcIPOSubscriptionLimitField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��֤ת��[����]��Ӧ
  virtual int OnRspRpcBankStkTrans(CFirstSetField *p_pFirstSetField, CRspFislRpcBankStkTransField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ�˻����[����]��Ӧ
  virtual int OnRspQryRpcFundBala(CFirstSetField *p_pFirstSetField, CRspFislQryRpcFundBalaField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��֤ת�ʲ�ѯ[����]��Ӧ
  virtual int OnRspQryRpcBankStkTransInfo(CFirstSetField *p_pFirstSetField, CRspFislQryRpcBankStkTransInfoField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �޸��ʽ�����[����]��Ӧ
  virtual int OnRspRpcChgFundPwd(CFirstSetField *p_pFirstSetField, CRspFislRpcChgFundPwdField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �޸Ľ�������[����]��Ӧ
  virtual int OnRspRpcChgTrdPwd(CFirstSetField *p_pFirstSetField, CRspFislRpcChgTrdPwdField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ȡ��ͨת��(����)�˺�(410601) [����]��Ӧ
  virtual int OnRspQryRpcBankAcct(CFirstSetField *p_pFirstSetField, CRspFislQryRpcBankAcctField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ȡ��ͨ�ⲿ(����)�˺�(410602) [����]��Ӧ
  virtual int OnRspQryRpcOtherBankAcct(CFirstSetField *p_pFirstSetField, CRspFislQryRpcOtherBankAcctField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �����¹��嵥��ѯ(411549) [����]��Ӧ
  virtual int OnRspQryRpcIPO(CFirstSetField *p_pFirstSetField, CRspFislQryRpcIPOField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Ų�ѯ(411518) [����]��Ӧ
  virtual int OnRspQryRpcDistribution(CFirstSetField *p_pFirstSetField, CRspFislQryRpcDistributionField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ֵ������ǩ��ѯ(411547) [����]��Ӧ
  virtual int OnRspQryRpcMktCapPlacing(CFirstSetField *p_pFirstSetField, CRspFislQryRpcMktCapPlacingField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ǩ��ʷ��ѯ(411560) [����]��Ӧ
  virtual int OnRspQryRpcWinningHistory(CFirstSetField *p_pFirstSetField, CRspFislQryRpcWinningHistoryField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ֵ���۽���˳���޸ģ�411548��[����]��Ӧ
  virtual int OnRspRpcChgMktCapDistDeliOrder(CFirstSetField *p_pFirstSetField, CRspFislRpcChgMktCapDistDeliOrderField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �����ѯ(411520) [����]��Ӧ
  virtual int OnRspQryRpcDeliOrder(CFirstSetField *p_pFirstSetField, CRspFislQryRpcDeliOrderField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ʲ�ѯ(411521) [����]��Ӧ
  virtual int OnRspQryRpcChkAcct(CFirstSetField *p_pFirstSetField, CRspFislQryRpcChkAcctField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ί�л���(410514) [����]��Ӧ
  virtual int OnRspQryRpcOrderSummary(CFirstSetField *p_pFirstSetField, CRspFislQryRpcOrderSummaryField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ճɽ�����(410516) [����]��Ӧ
  virtual int OnRspQryRpcMatchSummary(CFirstSetField *p_pFirstSetField, CRspFislQryRpcMatchSummaryField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ʷί����ϸ��ѯ(411511) [����]��Ӧ
  virtual int OnRspQryRpcHistoryOrderDetail(CFirstSetField *p_pFirstSetField, CRspFislQryRpcHistoryOrderDetailField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ʷ�ɽ���ϸ��ѯ(411513) [����]��Ӧ
  virtual int OnRspQryRpcHistoryMatchDetail(CFirstSetField *p_pFirstSetField, CRspFislQryRpcHistoryMatchDetailField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ת������ҵ����Ϣ(410211) [����]��Ӧ
  virtual int OnRspQryRpcBankTransBasicInfo(CFirstSetField *p_pFirstSetField, CRspFislQryRpcBankTransBasicInfoField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ʵ���ѯ(411525) [����]��Ӧ
  virtual int OnRspQryRpcStatement(CFirstSetField *p_pFirstSetField, CRspFislQryRpcStatementField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ֤ȯ��Ϣ��Ӧ
  virtual int OnRspRpcStkInfo(CFirstSetField *p_pFirstSetField, CRspFislRpcStkInfoField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����������Ϣ(ҵ�����)��Ӧ
  virtual int OnRspRpcOrgInfo(CFirstSetField *p_pFirstSetField, CRspFislRpcOrgInfoField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ȡ�ֵ���Ϣ��Ӧ
  virtual int OnRspRpcDictInfo(CFirstSetField *p_pFirstSetField, CRspFislRpcDictInfoField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ��ǰϵͳ״̬��Ӧ
  virtual int OnRspQryRpcCurSysStat(CFirstSetField *p_pFirstSetField, CRspFislQryRpcCurSysStatField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �û���¼��Ӧ
  virtual int OnRspRpcLogin(CFirstSetField *p_pFirstSetField, CRspFislRpcLoginField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ɶ���ʧ��Ӧ
  virtual int OnRspRpcTrdacctReportLoss(CFirstSetField *p_pFirstSetField, CRspFislRpcTrdacctReportLossField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ʽ��ʻ���ʧ��Ӧ
  virtual int OnRspRpcCuacctReportLoss(CFirstSetField *p_pFirstSetField, CRspFislRpcCuacctReportLossField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �������ɶ��ʻ���Ӧ
  virtual int OnRspRpcSetMainTrdacct(CFirstSetField *p_pFirstSetField, CRspFislRpcSetMainTrdacctField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �������ʲ��˺���Ӧ
  virtual int OnRspRpcSetMainCuacct(CFirstSetField *p_pFirstSetField, CRspFislRpcSetMainCuacctField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �޸���ϵ��ʽ(���Ͻ���ʹ��)��Ӧ
  virtual int OnRspRpcChgContact(CFirstSetField *p_pFirstSetField, CRspFislRpcChgContactField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ����ϲ�ѯ��Ӧ
  virtual int OnRspQryRpcCustInfo(CFirstSetField *p_pFirstSetField, CRspFislQryRpcCustInfoField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �޸Ĵ���Ȩ����Ӧ
  virtual int OnRspRpcChgProxyPermisson(CFirstSetField *p_pFirstSetField, CRspFislRpcChgProxyPermissonField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �޸Ĳ�����ʽ��Ӧ
  virtual int OnRspRpcChgOperMode(CFirstSetField *p_pFirstSetField, CRspFislRpcChgOperModeField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ�ͻ�������ʽ��Ӧ
  virtual int OnRspQryRpcCustOperMode(CFirstSetField *p_pFirstSetField, CRspFislQryRpcCustOperModeField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �޸Ŀͻ���ϵ����Ϣ��Ӧ
  virtual int OnRspRpcChgCustInfo(CFirstSetField *p_pFirstSetField, CRspFislRpcChgCustInfoField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ�ͻ��ʽ��ʺ�Ȩ����Ӧ
  virtual int OnRspQryRpcCuacctPermission(CFirstSetField *p_pFirstSetField, CRspFislQryRpcCuacctPermissionField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �޸��ʽ��ʺ�Ȩ����Ӧ
  virtual int OnRspRpcChgCuacctPermission(CFirstSetField *p_pFirstSetField, CRspFislRpcChgCuacctPermissionField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ�ͻ�֤ȯ�ʺ�Ȩ����Ӧ
  virtual int OnRspQryRpcTrdacctPermission(CFirstSetField *p_pFirstSetField, CRspFislQryRpcTrdacctPermissionField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ÿͻ�֤ȯ�ʺ�Ȩ����Ӧ
  virtual int OnRspRpcSetTrdacctPermission(CFirstSetField *p_pFirstSetField, CRspFislRpcSetTrdacctPermissionField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ������ȯ������޲�ѯ��Ӧ
  virtual int OnRspQryRpcUpLimitQuota(CFirstSetField *p_pFirstSetField, CRspFislQryRpcUpLimitQuotaField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ������ȯ��ȱ����Ӧ
  virtual int OnRspRpcChgLimitQuota(CFirstSetField *p_pFirstSetField, CRspFislRpcChgLimitQuotaField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ȱ��������Ӧ
  virtual int OnRspRpcChgLimitQuotaApplication(CFirstSetField *p_pFirstSetField, CRspFislRpcChgLimitQuotaApplicationField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ȱ������ȡ����Ӧ
  virtual int OnRspRpcChgLimitQuotaApplicationCancel(CFirstSetField *p_pFirstSetField, CRspFislRpcChgLimitQuotaApplicationCancelField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ȱ�������ѯ��Ӧ
  virtual int OnRspQryRpcChgLimitQuotaApplication(CFirstSetField *p_pFirstSetField, CRspFislQryRpcChgLimitQuotaApplicationField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ȡ֤ȯ����ǰ���¼۵�,֧������������Ӧ
  virtual int OnRspRpcStkAvlAndLatestPrice(CFirstSetField *p_pFirstSetField, CRspFislRpcStkAvlAndLatestPriceField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ȡ���������,֧������������Ӧ
  virtual int OnRspRpcMaxStkQty(CFirstSetField *p_pFirstSetField, CRspFislRpcMaxStkQtyField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ί������ҵ��,֧���������ף���ΧԼ��������ȯί����Ӧ
  virtual int OnRspRpcOrder(CFirstSetField *p_pFirstSetField, CRspFislRpcOrderField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ί�г�����Ӧ
  virtual int OnRspRpcOrderCancel(CFirstSetField *p_pFirstSetField, CRspFislRpcOrderCancelField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ί�г�����ѯ��Ӧ
  virtual int OnRspQryRpcOrderCancel(CFirstSetField *p_pFirstSetField, CRspFislQryRpcOrderCancelField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���óɱ���Ӧ
  virtual int OnRspRpcResetCost(CFirstSetField *p_pFirstSetField, CRspFislRpcResetCostField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ӯ�����ü�����Ӧ
  virtual int OnRspRpcCalcFee(CFirstSetField *p_pFirstSetField, CRspFislRpcCalcFeeField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ���ѯ����ѯ�ͻ��ɶ�������Ӧ
  virtual int OnRspQryRpcTrdacct(CFirstSetField *p_pFirstSetField, CRspFislQryRpcTrdacctField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ʽ��ѯ��Ӧ
  virtual int OnRspQryRpcCuacct(CFirstSetField *p_pFirstSetField, CRspFislQryRpcCuacctField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ɷ���ϸ��ѯ��Ӧ
  virtual int OnRspQryRpcStkDetail(CFirstSetField *p_pFirstSetField, CRspFislQryRpcStkDetailField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ɷݻ��ܲ�ѯ��Ӧ
  virtual int OnRspQryRpcStkSummary(CFirstSetField *p_pFirstSetField, CRspFislQryRpcStkSummaryField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ʽ��ʻ���ѯ��Ӧ
  virtual int OnRspQryRpcCuacct2(CFirstSetField *p_pFirstSetField, CRspFislQryRpcCuacct2Field *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ���ѯ�����ݹɶ����룬��ѯ�ɶ�������Ӧ
  virtual int OnRspQryRpcTrdacct2(CFirstSetField *p_pFirstSetField, CRspFislQryRpcTrdacct2Field *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ���ѯ�����ݹɶ����룬�ʽ��ʻ���ѯ�ͻ�������Ӧ
  virtual int OnRspQryRpcTrdacct3(CFirstSetField *p_pFirstSetField, CRspFislQryRpcTrdacct3Field *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ί����ϸ��ѯ��Ӧ
  virtual int OnRspQryRpcOrderDetail(CFirstSetField *p_pFirstSetField, CRspFislQryRpcOrderDetailField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ճɽ���ϸ��ѯ��Ӧ
  virtual int OnRspQryRpcMatchDetail(CFirstSetField *p_pFirstSetField, CRspFislQryRpcMatchDetailField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ʷί�л��ܣ���֤ȯ���������������Ӧ
  virtual int OnRspRpcHisOrderSummary(CFirstSetField *p_pFirstSetField, CRspFislRpcHisOrderSummaryField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ʷ�ɽ����ܣ���֤ȯ���������������Ӧ
  virtual int OnRspRpcHisMatchSummary(CFirstSetField *p_pFirstSetField, CRspFislRpcHisMatchSummaryField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ǩ��ѯ��Ӧ
  virtual int OnRspQryRpcLottery(CFirstSetField *p_pFirstSetField, CRspFislQryRpcLotteryField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ί�л���ordergroup+stkcode+bsflag��Ӧ
  virtual int OnRspRpcOrderSummary(CFirstSetField *p_pFirstSetField, CRspFislRpcOrderSummaryField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ί�в�ѯ�����ӡ���Ӧ
  virtual int OnRspQryRpcBatchOrder(CFirstSetField *p_pFirstSetField, CRspFislQryRpcBatchOrderField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �����ʽ��ȡ��ѯ��Ӧ
  virtual int OnRspQryRpcCreditCuacctCanDraw(CFirstSetField *p_pFirstSetField, CRspFislQryRpcCreditCuacctCanDrawField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Ʊ��ѯ������Ӧ
  virtual int OnRspQryRpcMkt(CFirstSetField *p_pFirstSetField, CRspFislQryRpcMktField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���������ѯ��Ӧ
  virtual int OnRspQryRpcMktIntention(CFirstSetField *p_pFirstSetField, CRspFislQryRpcMktIntentionField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯӪҵ��ĳһҵ�������걨ϯλ��Ӧ
  virtual int OnRspQryRpcSeat(CFirstSetField *p_pFirstSetField, CRspFislQryRpcSeatField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ�ʽ��˻���Ϣ��Ӧ
  virtual int OnRspQryRpcCuacctAcctInfo(CFirstSetField *p_pFirstSetField, CRspFislQryRpcCuacctAcctInfoField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ����������Ѳ�ѯ��Ӧ
  virtual int OnRspQryRpcCustSpecialFee(CFirstSetField *p_pFirstSetField, CRspFislQryRpcCustSpecialFeeField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Ϣ����˰������ϸ��ѯ��Ӧ
  virtual int OnRspQryRpcDividendBonusTaxDetail(CFirstSetField *p_pFirstSetField, CRspFislQryRpcDividendBonusTaxDetailField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �趨����ת��ת���ƻ���Ӧ
  virtual int OnRspRpcSetPeriodicalTransferPlan(CFirstSetField *p_pFirstSetField, CRspFislRpcSetPeriodicalTransferPlanField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯ����ת��ת���ƻ���Ӧ
  virtual int OnRspQryRpcPeriodicalTransferPlan(CFirstSetField *p_pFirstSetField, CRspFislQryRpcPeriodicalTransferPlanField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ɾ������ת��ת���ƻ���Ӧ
  virtual int OnRspRpcDelPeriodicalTransferPlan(CFirstSetField *p_pFirstSetField, CRspFislRpcDelPeriodicalTransferPlanField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����֤ȯ��ѯ��Ӧ
  virtual int OnRspQryRpcGuaranteedStk(CFirstSetField *p_pFirstSetField, CRspFislQryRpcGuaranteedStkField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���֤ȯ��ѯ��Ӧ
  virtual int OnRspQryRpcUnderlyingStk(CFirstSetField *p_pFirstSetField, CRspFislQryRpcUnderlyingStkField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �����������ݲ�ѯ��Ӧ
  virtual int OnRspQryRpcFinancingCreditData(CFirstSetField *p_pFirstSetField, CRspFislQryRpcFinancingCreditDataField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ȯ�������ݲ�ѯ��Ӧ
  virtual int OnRspQryRpcMarginCreditData(CFirstSetField *p_pFirstSetField, CRspFislQryRpcMarginCreditDataField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ÿͻ��ʲ���ծ��ѯ��Ӧ
  virtual int OnRspQryRpcCreditCustBalance(CFirstSetField *p_pFirstSetField, CRspFislQryRpcCreditCustBalanceField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ������ȯ��Լ��ѯ��Ӧ
  virtual int OnRspQryRpcContract(CFirstSetField *p_pFirstSetField, CRspFislQryRpcContractField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ͬ��Ϣ��ѯ��Ӧ
  virtual int OnRspQryRpcAgreementInfo(CFirstSetField *p_pFirstSetField, CRspFislQryRpcAgreementInfoField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ΧԼ��ֱ�ӻ��ֱ�ӻ�����Ӧ
  virtual int OnRspRpcDirectRepayment(CFirstSetField *p_pFirstSetField, CRspFislRpcDirectRepaymentField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ѯȯ����ȯ�ʻ�ͷ����Ӧ
  virtual int OnRspQryRpcMarginAcctPosi(CFirstSetField *p_pFirstSetField, CRspFislQryRpcMarginAcctPosiField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���ÿͻ���ת�뵣��֤ȯ��ѯ��Ӧ
  virtual int OnRspQryRpcCreditCustCanTransferInGuaranteedStk(CFirstSetField *p_pFirstSetField, CRspFislQryRpcCreditCustCanTransferInGuaranteedStkField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ͶƱ������ѯ��Ӧ
  virtual int OnRspQryRpcVotingScheme(CFirstSetField *p_pFirstSetField, CRspFislQryRpcVotingSchemeField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ͶƱ�µ���Ӧ
  virtual int OnRspRpcVotingOrder(CFirstSetField *p_pFirstSetField, CRspFislRpcVotingOrderField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ͶƱ�����ѯ��Ӧ
  virtual int OnRspQryRpcVotingResult(CFirstSetField *p_pFirstSetField, CRspFislQryRpcVotingResultField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ͶƱ���ͳ����Ӧ
  virtual int OnRspRpcVotingResultStatistics(CFirstSetField *p_pFirstSetField, CRspFislRpcVotingResultStatisticsField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ���ͶƱ�鰸��ѯ��Ӧ
  virtual int OnRspQryRpcCanVoteBill(CFirstSetField *p_pFirstSetField, CRspFislQryRpcCanVoteBillField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ���ͶƱָ���鰸�Ĺɷݲ�ѯ��Ӧ
  virtual int OnRspQryRpcCanVoteBillShare(CFirstSetField *p_pFirstSetField, CRspFislQryRpcCanVoteBillShareField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Ʊ��ʷ�ɷ�����ѯ��Ӧ
  virtual int OnRspQryRpcHisShareBalance(CFirstSetField *p_pFirstSetField, CRspFislQryRpcHisShareBalanceField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ������ȯ�ʺ�����������Ӧ
  virtual int OnRspRpcSelfActivate(CFirstSetField *p_pFirstSetField, CRspFislRpcSelfActivateField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ͬ��Ϣ�޸���Ӧ
  virtual int OnRspRpcChgAgreementInfo(CFirstSetField *p_pFirstSetField, CRspFislRpcChgAgreementInfoField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ��˻������ò�ѯ��Ӧ
  virtual int OnRspQryRpcAcctLvlFee(CFirstSetField *p_pFirstSetField, CRspFislQryRpcAcctLvlFeeField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ������ȯ�Զ����Լ����˳���ѯ��Ӧ
  virtual int OnRspQryRpcCustomContractRepayOrder(CFirstSetField *p_pFirstSetField, CRspFislQryRpcCustomContractRepayOrderField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ������ȯ�Զ����Լ����˳��������Ӧ
  virtual int OnRspRpcSetCustomContractRepayOrder(CFirstSetField *p_pFirstSetField, CRspFislRpcSetCustomContractRepayOrderField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ȯ����ר��֤ȯ��ѯ��Ӧ
  virtual int OnRspQryRpcSpecialMarginAcctStk(CFirstSetField *p_pFirstSetField, CRspFislQryRpcSpecialMarginAcctStkField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ������ȯ��ʷ���˽��Լ��ѯ��Ӧ
  virtual int OnRspQryRpcHisClosedContract(CFirstSetField *p_pFirstSetField, CRspFislQryRpcHisClosedContractField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Χ���ý������Բ�ѯ��Ӧ
  virtual int OnRspQryRpcCreditTradeAttribute(CFirstSetField *p_pFirstSetField, CRspFislQryRpcCreditTradeAttributeField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Լչ��������Ӧ
  virtual int OnRspRpcContractExtensionApplication(CFirstSetField *p_pFirstSetField, CRspFislRpcContractExtensionApplicationField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ��ȱȶ���ͷű�־�޸���Ӧ
  virtual int OnRspRpcChgGeometricQuotaReleaseFlag(CFirstSetField *p_pFirstSetField, CRspFislRpcChgGeometricQuotaReleaseFlagField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Լչ�������ѯ��Ӧ
  virtual int OnRspQryRpcContractExtensionApplication(CFirstSetField *p_pFirstSetField, CRspFislQryRpcContractExtensionApplicationField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Լչ������ȡ����Ӧ
  virtual int OnRspRpcContractExtensionApplicationCancel(CFirstSetField *p_pFirstSetField, CRspFislRpcContractExtensionApplicationCancelField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Χ���ղ������Ͳ�ѯ��Ӧ
  virtual int OnRspQryRpcRiskEvaluationMode(CFirstSetField *p_pFirstSetField, CRspFislQryRpcRiskEvaluationModeField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // չ�ڹ����ѯ��Ӧ
  virtual int OnRspQryRpcExtensionRule(CFirstSetField *p_pFirstSetField, CRspFislQryRpcExtensionRuleField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��չ�ں�Լ��ѯ��Ӧ
  virtual int OnRspQryRpcCanExtendContract(CFirstSetField *p_pFirstSetField, CRspFislQryRpcCanExtendContractField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ�����Ȩ�������ϸ��ѯ��Ӧ
  virtual int OnRspQryRpcGuaranteeInterestAdjustmentDetail(CFirstSetField *p_pFirstSetField, CRspFislQryRpcGuaranteeInterestAdjustmentDetailField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ���ʷά�ֵ���������ѯ��Ӧ
  virtual int OnRspQryRpcHisMaintainGuaranteeRatio(CFirstSetField *p_pFirstSetField, CRspFislQryRpcHisMaintainGuaranteeRatioField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ͷ��ԤԼ������Ӧ
  virtual int OnRspRpcFinancingPosiSubApplication(CFirstSetField *p_pFirstSetField, CRspFislRpcFinancingPosiSubApplicationField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ͷ��ԤԼ�����ѯ��Ӧ
  virtual int OnRspQryRpcFinancingPosiSubApplication(CFirstSetField *p_pFirstSetField, CRspFislQryRpcFinancingPosiSubApplicationField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ͷ����ԤԼ������Ӧ
  virtual int OnRspRpcChgFinancingPosiSubApplication(CFirstSetField *p_pFirstSetField, CRspFislRpcChgFinancingPosiSubApplicationField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ȡ������ͷ��ԤԼ������Ӧ
  virtual int OnRspRpcCancelFinancingPosiSubApplication(CFirstSetField *p_pFirstSetField, CRspFislRpcCancelFinancingPosiSubApplicationField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ���������ͷ���ѯ��Ӧ
  virtual int OnRspQryRpcLinkFinancingPosi(CFirstSetField *p_pFirstSetField, CRspFislQryRpcLinkFinancingPosiField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����Ĭ�����ʿ���ͷ����Ӧ
  virtual int OnRspRpcSetDefaultFinancingOpenPosi(CFirstSetField *p_pFirstSetField, CRspFislRpcSetDefaultFinancingOpenPosiField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ȯͷ��ԤԼ������Ӧ
  virtual int OnRspRpcMarginPosiSubApplication(CFirstSetField *p_pFirstSetField, CRspFislRpcMarginPosiSubApplicationField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ȯͷ����������Ӧ
  virtual int OnRspRpcChgMarginPosiApplication(CFirstSetField *p_pFirstSetField, CRspFislRpcChgMarginPosiApplicationField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ȯͷ��ԤԼ��ѯ��Ӧ
  virtual int OnRspQryRpcMarginPosiSub(CFirstSetField *p_pFirstSetField, CRspFislQryRpcMarginPosiSubField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ȯ����ͷ��ָ����Ӧ
  virtual int OnRspRpcMarginOpenPosiAppoint(CFirstSetField *p_pFirstSetField, CRspFislRpcMarginOpenPosiAppointField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ͻ�������ȯͷ���ѯ��Ӧ
  virtual int OnRspQryRpcLinkMarginPosi(CFirstSetField *p_pFirstSetField, CRspFislQryRpcLinkMarginPosiField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��ȯͷ��ԤԼȡ����Ӧ
  virtual int OnRspRpcCancelMarginPosiSub(CFirstSetField *p_pFirstSetField, CRspFislRpcCancelMarginPosiSubField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ⶳ��ǩ��Ԥ������ʽ���Ӧ
  virtual int OnRspRpcUnfreezePreFrozenFunds(CFirstSetField *p_pFirstSetField, CRspFislRpcUnfreezePreFrozenFundsField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �������۽ɿ�, ֧������������Ӧ
  virtual int OnRspRpcCancelRation(CFirstSetField *p_pFirstSetField, CRspFislRpcCancelRationField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ϵͳ̽����Ӧ
  virtual int OnRspBizStatus(CFirstSetField *p_pFirstSetField, CRspFislBizStatusField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Ѻ�ɷ���ϸ��ѯ(���ͻ�)��Ӧ
  virtual int OnRspQryPledgeShares(CFirstSetField *p_pFirstSetField, CRspFislQryPledgeSharesField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ʽ���ˮ��ѯ��Ӧ
  virtual int OnRspQryFundFlow(CFirstSetField *p_pFirstSetField, CRspFislQryFundFlowField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ����ί��(����)��Ӧ
  virtual int OnRspOrderEx(CFirstSetField *p_pFirstSetField, CRspFislOrderExField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // �ɷ���ˮ��ѯ��Ӧ
  virtual int OnRspQryStockFlow(CFirstSetField *p_pFirstSetField, CRspFislQryStockFlowField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ���н����ղ�ѯ��Ӧ
  virtual int OnRspQrySettDate(CFirstSetField *p_pFirstSetField, CRspFislQrySettDateField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

private:

};

class MATRADEAPI CCliFislTradeApi : virtual public CCliTradeApi
{
public:
  // Ĭ�Ϲ��캯��
  CCliFislTradeApi(void);

  // ��������
  virtual ~CCliFislTradeApi(void);

  // ���ȯ��Ϣ��ѯ����
  virtual int ReqQryUndlStkInfo(CReqFislQryUndlStkInfoField *p_pReqField, LONGLONG p_llRequestId);

  // ����֤ȯ��Ϣ��ѯ����
  virtual int ReqQryColStkInfo(CReqFislQryColStkInfoField *p_pReqField, LONGLONG p_llRequestId);

  // LOF��Ϣ��ѯ����
  virtual int ReqQryLofInfo(CReqFislQryLofInfoField *p_pReqField, LONGLONG p_llRequestId);

  // ����ί������
  virtual int ReqOrder(CReqFislOrderField *p_pReqField, LONGLONG p_llRequestId);

  // ί�г�������
  virtual int ReqCancelOrder(CReqFislCancelOrderField *p_pReqField, LONGLONG p_llRequestId);

  // ���ɽ�������������
  virtual int ReqMaxTradeQty(CReqFislMaxTradeQtyField *p_pReqField, LONGLONG p_llRequestId);

  // ������ȯֱ�ӻ�������
  virtual int ReqMarginRepay(CReqFislMarginRepayField *p_pReqField, LONGLONG p_llRequestId);

  // �����ʽ��ѯ����
  virtual int ReqQryExpendableFund(CReqFislQryExpendableFundField *p_pReqField, LONGLONG p_llRequestId);

  // ���ùɷݲ�ѯ����
  virtual int ReqQryExpendableShares(CReqFislQryExpendableSharesField *p_pReqField, LONGLONG p_llRequestId);

  // ����ί�в�ѯ����
  virtual int ReqQryCurrDayOrder(CReqFislQryCurrDayOrderField *p_pReqField, LONGLONG p_llRequestId);

  // ���ճɽ���ѯ����
  virtual int ReqQryCurrDayFill(CReqFislQryCurrDayFillField *p_pReqField, LONGLONG p_llRequestId);

  // �ɶ��˻���ѯ����
  virtual int ReqQryStkholderAcct(CReqFislQryStkholderAcctField *p_pReqField, LONGLONG p_llRequestId);

  // �ɳ���ί�в�ѯ����
  virtual int ReqQryCanWithdrawOrder(CReqFislQryCanWithdrawOrderField *p_pReqField, LONGLONG p_llRequestId);

  // �����ʽ��ѯ����[����]
  virtual int ReqQryExpendableFundEx(CReqFislQryExpendableFundExField *p_pReqField, LONGLONG p_llRequestId);

  // ���ùɷݲ�ѯ����[����]
  virtual int ReqQryExpendableSharesEx(CReqFislQryExpendableSharesExField *p_pReqField, LONGLONG p_llRequestId);

  // ����ί�в�ѯ����[����]
  virtual int ReqQryCurrDayOrderEx(CReqFislQryCurrDayOrderExField *p_pReqField, LONGLONG p_llRequestId);

  // ���ճɽ���ѯ����[����]
  virtual int ReqQryCurrDayFillEx(CReqFislQryCurrDayFillExField *p_pReqField, LONGLONG p_llRequestId);

  // �ɶ��˻���ѯ����[����]
  virtual int ReqQryStkholderAcctEx(CReqFislQryStkholderAcctExField *p_pReqField, LONGLONG p_llRequestId);

  // �ɳ���ί�в�ѯ����[����]
  virtual int ReqQryCanWithdrawOrderEx(CReqFislQryCanWithdrawOrderExField *p_pReqField, LONGLONG p_llRequestId);

  // ������ȯЭ���ѯ����
  virtual int ReqQryMarginProtocol(CReqFislQryMarginProtocolField *p_pReqField, LONGLONG p_llRequestId);

  // ������ȯ��Լ��ѯ����
  virtual int ReqQryMarginContract(CReqFislQryMarginContractField *p_pReqField, LONGLONG p_llRequestId);

  // ������ȯ��֤���������ѯ����
  virtual int ReqQryMarginDepositAvl(CReqFislQryMarginDepositAvlField *p_pReqField, LONGLONG p_llRequestId);

  // ������ȯ���ÿ��ö�Ȳ�ѯ����
  virtual int ReqQryMarginCreditAvl(CReqFislQryMarginCreditAvlField *p_pReqField, LONGLONG p_llRequestId);

  // ���ÿͻ��ʲ���ծ��ѯ����
  virtual int ReqQryCreditCustDebts(CReqFislQryCreditCustDebtsField *p_pReqField, LONGLONG p_llRequestId);

  // ������ȯ�ʽ�ͷ���ѯ����
  virtual int ReqQryMarginFundCash(CReqFislQryMarginFundCashField *p_pReqField, LONGLONG p_llRequestId);

  // ������ȯ�ɷ�ͷ���ѯ����
  virtual int ReqQryMarginSharesCash(CReqFislQryMarginSharesCashField *p_pReqField, LONGLONG p_llRequestId);
  
  // �ɳ�������ѯ
  virtual int ReqQryCanRepay(CReqFislQryCanRepayField *p_pReqField, LONGLONG p_llRequestId);

  // ֤ȯ��ֵ��Ȳ�ѯ
  virtual int ReqQryMktQuota(CReqFislMktQuotaField *p_pReqField, LONGLONG p_llRequestId);

  // ���ʺ�Լ���ܲ�ѯ
  virtual int ReqQryFiContractSum(CReqFislQryFiContractSumField *p_pReqField, LONGLONG  p_llRequestId);

  // ��ȯ��Լ���ܲ�ѯ
  virtual int ReqQrySlContractSum(CReqFislQrySlContractSumField *p_pReqField, LONGLONG  p_llRequestId);

  //�ʽ𻮲�
  virtual int ReqQryFundTransfer(CReqFislFundTransferField *p_pReqField, LONGLONG p_llRequestId);

  // �û���¼����
  virtual int ReqUserLogin(CReqFislUserLoginField *p_pReqField, LONGLONG p_llRequestId);
  
  // ������ȯ��ծ������ˮ��ѯ[����]����
  virtual int ReqQryRpcRepaymentDetail(CReqFislQryRpcRepaymentDetailField *p_pReqField, LONGLONG p_llRequestId);
  // �ʽ��ѯ[����]����
  virtual int ReqQryRpcFund(CReqFislQryRpcFundField *p_pReqField, LONGLONG p_llRequestId);
  // �����ʽ���ˮ��ѯ[����]����
  virtual int ReqQryRpcFundDetail(CReqFislQryRpcFundDetailField *p_pReqField, LONGLONG p_llRequestId);
  // �¹��깺�ͻ���ֵ��Ȳ�ѯ[����]����
  virtual int ReqQryRpcIPOSubscriptionLimit(CReqFislQryRpcIPOSubscriptionLimitField *p_pReqField, LONGLONG p_llRequestId);
  // ��֤ת��[����]����
  virtual int ReqRpcBankStkTrans(CReqFislRpcBankStkTransField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ�˻����[����]����
  virtual int ReqQryRpcFundBala(CReqFislQryRpcFundBalaField *p_pReqField, LONGLONG p_llRequestId);
  // ��֤ת�ʲ�ѯ[����]����
  virtual int ReqQryRpcBankStkTransInfo(CReqFislQryRpcBankStkTransInfoField *p_pReqField, LONGLONG p_llRequestId);
  // �޸��ʽ�����[����]����
  virtual int ReqRpcChgFundPwd(CReqFislRpcChgFundPwdField *p_pReqField, LONGLONG p_llRequestId);
  // �޸Ľ�������[����]����
  virtual int ReqRpcChgTrdPwd(CReqFislRpcChgTrdPwdField *p_pReqField, LONGLONG p_llRequestId);
  // ��ȡ��ͨת��(����)�˺�(410601) [����]����
  virtual int ReqQryRpcBankAcct(CReqFislQryRpcBankAcctField *p_pReqField, LONGLONG p_llRequestId);
  // ��ȡ��ͨ�ⲿ(����)�˺�(410602) [����]����
  virtual int ReqQryRpcOtherBankAcct(CReqFislQryRpcOtherBankAcctField *p_pReqField, LONGLONG p_llRequestId);
  // �����¹��嵥��ѯ(411549) [����]����
  virtual int ReqQryRpcIPO(CReqFislQryRpcIPOField *p_pReqField, LONGLONG p_llRequestId);
  // ��Ų�ѯ(411518) [����]����
  virtual int ReqQryRpcDistribution(CReqFislQryRpcDistributionField *p_pReqField, LONGLONG p_llRequestId);
  // ��ֵ������ǩ��ѯ(411547) [����]����
  virtual int ReqQryRpcMktCapPlacing(CReqFislQryRpcMktCapPlacingField *p_pReqField, LONGLONG p_llRequestId);
  // ��ǩ��ʷ��ѯ(411560) [����]����
  virtual int ReqQryRpcWinningHistory(CReqFislQryRpcWinningHistoryField *p_pReqField, LONGLONG p_llRequestId);
  // ��ֵ���۽���˳���޸ģ�411548��[����]����
  virtual int ReqRpcChgMktCapDistDeliOrder(CReqFislRpcChgMktCapDistDeliOrderField *p_pReqField, LONGLONG p_llRequestId);
  // �����ѯ(411520) [����]����
  virtual int ReqQryRpcDeliOrder(CReqFislQryRpcDeliOrderField *p_pReqField, LONGLONG p_llRequestId);
  // ���ʲ�ѯ(411521) [����]����
  virtual int ReqQryRpcChkAcct(CReqFislQryRpcChkAcctField *p_pReqField, LONGLONG p_llRequestId);
  // ����ί�л���(410514) [����]����
  virtual int ReqQryRpcOrderSummary(CReqFislQryRpcOrderSummaryField *p_pReqField, LONGLONG p_llRequestId);
  // ���ճɽ�����(410516) [����]����
  virtual int ReqQryRpcMatchSummary(CReqFislQryRpcMatchSummaryField *p_pReqField, LONGLONG p_llRequestId);
  // ��ʷί����ϸ��ѯ(411511) [����]����
  virtual int ReqQryRpcHistoryOrderDetail(CReqFislQryRpcHistoryOrderDetailField *p_pReqField, LONGLONG p_llRequestId);
  // ��ʷ�ɽ���ϸ��ѯ(411513) [����]����
  virtual int ReqQryRpcHistoryMatchDetail(CReqFislQryRpcHistoryMatchDetailField *p_pReqField, LONGLONG p_llRequestId);
  // ת������ҵ����Ϣ(410211) [����]����
  virtual int ReqQryRpcBankTransBasicInfo(CReqFislQryRpcBankTransBasicInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ���ʵ���ѯ(411525) [����]����
  virtual int ReqQryRpcStatement(CReqFislQryRpcStatementField *p_pReqField, LONGLONG p_llRequestId);
  // ֤ȯ��Ϣ����
  virtual int ReqRpcStkInfo(CReqFislRpcStkInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ����������Ϣ(ҵ�����)����
  virtual int ReqRpcOrgInfo(CReqFislRpcOrgInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ȡ�ֵ���Ϣ����
  virtual int ReqRpcDictInfo(CReqFislRpcDictInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ��ǰϵͳ״̬����
  virtual int ReqQryRpcCurSysStat(CReqFislQryRpcCurSysStatField *p_pReqField, LONGLONG p_llRequestId);
  // �û���¼����
  virtual int ReqRpcLogin(CReqFislRpcLoginField *p_pReqField, LONGLONG p_llRequestId);
  // �ɶ���ʧ����
  virtual int ReqRpcTrdacctReportLoss(CReqFislRpcTrdacctReportLossField *p_pReqField, LONGLONG p_llRequestId);
  // �ʽ��ʻ���ʧ����
  virtual int ReqRpcCuacctReportLoss(CReqFislRpcCuacctReportLossField *p_pReqField, LONGLONG p_llRequestId);
  // �������ɶ��ʻ�����
  virtual int ReqRpcSetMainTrdacct(CReqFislRpcSetMainTrdacctField *p_pReqField, LONGLONG p_llRequestId);
  // �������ʲ��˺�����
  virtual int ReqRpcSetMainCuacct(CReqFislRpcSetMainCuacctField *p_pReqField, LONGLONG p_llRequestId);
  // �޸���ϵ��ʽ(���Ͻ���ʹ��)����
  virtual int ReqRpcChgContact(CReqFislRpcChgContactField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ����ϲ�ѯ����
  virtual int ReqQryRpcCustInfo(CReqFislQryRpcCustInfoField *p_pReqField, LONGLONG p_llRequestId);
  // �޸Ĵ���Ȩ������
  virtual int ReqRpcChgProxyPermisson(CReqFislRpcChgProxyPermissonField *p_pReqField, LONGLONG p_llRequestId);
  // �޸Ĳ�����ʽ����
  virtual int ReqRpcChgOperMode(CReqFislRpcChgOperModeField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ�ͻ�������ʽ����
  virtual int ReqQryRpcCustOperMode(CReqFislQryRpcCustOperModeField *p_pReqField, LONGLONG p_llRequestId);
  // �޸Ŀͻ���ϵ����Ϣ����
  virtual int ReqRpcChgCustInfo(CReqFislRpcChgCustInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ�ͻ��ʽ��ʺ�Ȩ������
  virtual int ReqQryRpcCuacctPermission(CReqFislQryRpcCuacctPermissionField *p_pReqField, LONGLONG p_llRequestId);
  // �޸��ʽ��ʺ�Ȩ������
  virtual int ReqRpcChgCuacctPermission(CReqFislRpcChgCuacctPermissionField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ�ͻ�֤ȯ�ʺ�Ȩ������
  virtual int ReqQryRpcTrdacctPermission(CReqFislQryRpcTrdacctPermissionField *p_pReqField, LONGLONG p_llRequestId);
  // ���ÿͻ�֤ȯ�ʺ�Ȩ������
  virtual int ReqRpcSetTrdacctPermission(CReqFislRpcSetTrdacctPermissionField *p_pReqField, LONGLONG p_llRequestId);
  // ������ȯ������޲�ѯ����
  virtual int ReqQryRpcUpLimitQuota(CReqFislQryRpcUpLimitQuotaField *p_pReqField, LONGLONG p_llRequestId);
  // ������ȯ��ȱ������
  virtual int ReqRpcChgLimitQuota(CReqFislRpcChgLimitQuotaField *p_pReqField, LONGLONG p_llRequestId);
  // ��ȱ����������
  virtual int ReqRpcChgLimitQuotaApplication(CReqFislRpcChgLimitQuotaApplicationField *p_pReqField, LONGLONG p_llRequestId);
  // ��ȱ������ȡ������
  virtual int ReqRpcChgLimitQuotaApplicationCancel(CReqFislRpcChgLimitQuotaApplicationCancelField *p_pReqField, LONGLONG p_llRequestId);
  // ��ȱ�������ѯ����
  virtual int ReqQryRpcChgLimitQuotaApplication(CReqFislQryRpcChgLimitQuotaApplicationField *p_pReqField, LONGLONG p_llRequestId);
  // ȡ֤ȯ����ǰ���¼۵�,֧��������������
  virtual int ReqRpcStkAvlAndLatestPrice(CReqFislRpcStkAvlAndLatestPriceField *p_pReqField, LONGLONG p_llRequestId);
  // ȡ���������,֧��������������
  virtual int ReqRpcMaxStkQty(CReqFislRpcMaxStkQtyField *p_pReqField, LONGLONG p_llRequestId);
  // ί������ҵ��,֧���������ף���ΧԼ��������ȯί������
  virtual int ReqRpcOrder(CReqFislRpcOrderField *p_pReqField, LONGLONG p_llRequestId);
  // ί�г�������
  virtual int ReqRpcOrderCancel(CReqFislRpcOrderCancelField *p_pReqField, LONGLONG p_llRequestId);
  // ί�г�����ѯ����
  virtual int ReqQryRpcOrderCancel(CReqFislQryRpcOrderCancelField *p_pReqField, LONGLONG p_llRequestId);
  // ���óɱ�����
  virtual int ReqRpcResetCost(CReqFislRpcResetCostField *p_pReqField, LONGLONG p_llRequestId);
  // ӯ�����ü�������
  virtual int ReqRpcCalcFee(CReqFislRpcCalcFeeField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ���ѯ����ѯ�ͻ��ɶ���������
  virtual int ReqQryRpcTrdacct(CReqFislQryRpcTrdacctField *p_pReqField, LONGLONG p_llRequestId);
  // �ʽ��ѯ����
  virtual int ReqQryRpcCuacct(CReqFislQryRpcCuacctField *p_pReqField, LONGLONG p_llRequestId);
  // �ɷ���ϸ��ѯ����
  virtual int ReqQryRpcStkDetail(CReqFislQryRpcStkDetailField *p_pReqField, LONGLONG p_llRequestId);
  // �ɷݻ��ܲ�ѯ����
  virtual int ReqQryRpcStkSummary(CReqFislQryRpcStkSummaryField *p_pReqField, LONGLONG p_llRequestId);
  // �ʽ��ʻ���ѯ����
  virtual int ReqQryRpcCuacct2(CReqFislQryRpcCuacct2Field *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ���ѯ�����ݹɶ����룬��ѯ�ɶ���������
  virtual int ReqQryRpcTrdacct2(CReqFislQryRpcTrdacct2Field *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ���ѯ�����ݹɶ����룬�ʽ��ʻ���ѯ�ͻ���������
  virtual int ReqQryRpcTrdacct3(CReqFislQryRpcTrdacct3Field *p_pReqField, LONGLONG p_llRequestId);
  // ����ί����ϸ��ѯ����
  virtual int ReqQryRpcOrderDetail(CReqFislQryRpcOrderDetailField *p_pReqField, LONGLONG p_llRequestId);
  // ���ճɽ���ϸ��ѯ����
  virtual int ReqQryRpcMatchDetail(CReqFislQryRpcMatchDetailField *p_pReqField, LONGLONG p_llRequestId);
  // ��ʷί�л��ܣ���֤ȯ�����������������
  virtual int ReqRpcHisOrderSummary(CReqFislRpcHisOrderSummaryField *p_pReqField, LONGLONG p_llRequestId);
  // ��ʷ�ɽ����ܣ���֤ȯ�����������������
  virtual int ReqRpcHisMatchSummary(CReqFislRpcHisMatchSummaryField *p_pReqField, LONGLONG p_llRequestId);
  // ��ǩ��ѯ����
  virtual int ReqQryRpcLottery(CReqFislQryRpcLotteryField *p_pReqField, LONGLONG p_llRequestId);
  // ����ί�л���ordergroup+stkcode+bsflag����
  virtual int ReqRpcOrderSummary(CReqFislRpcOrderSummaryField *p_pReqField, LONGLONG p_llRequestId);
  // ����ί�в�ѯ�����ӡ�����
  virtual int ReqQryRpcBatchOrder(CReqFislQryRpcBatchOrderField *p_pReqField, LONGLONG p_llRequestId);
  // �����ʽ��ȡ��ѯ����
  virtual int ReqQryRpcCreditCuacctCanDraw(CReqFislQryRpcCreditCuacctCanDrawField *p_pReqField, LONGLONG p_llRequestId);
  // ��Ʊ��ѯ��������
  virtual int ReqQryRpcMkt(CReqFislQryRpcMktField *p_pReqField, LONGLONG p_llRequestId);
  // ���������ѯ����
  virtual int ReqQryRpcMktIntention(CReqFislQryRpcMktIntentionField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯӪҵ��ĳһҵ�������걨ϯλ����
  virtual int ReqQryRpcSeat(CReqFislQryRpcSeatField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ�ʽ��˻���Ϣ����
  virtual int ReqQryRpcCuacctAcctInfo(CReqFislQryRpcCuacctAcctInfoField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ����������Ѳ�ѯ����
  virtual int ReqQryRpcCustSpecialFee(CReqFislQryRpcCustSpecialFeeField *p_pReqField, LONGLONG p_llRequestId);
  // ��Ϣ����˰������ϸ��ѯ����
  virtual int ReqQryRpcDividendBonusTaxDetail(CReqFislQryRpcDividendBonusTaxDetailField *p_pReqField, LONGLONG p_llRequestId);
  // �趨����ת��ת���ƻ�����
  virtual int ReqRpcSetPeriodicalTransferPlan(CReqFislRpcSetPeriodicalTransferPlanField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯ����ת��ת���ƻ�����
  virtual int ReqQryRpcPeriodicalTransferPlan(CReqFislQryRpcPeriodicalTransferPlanField *p_pReqField, LONGLONG p_llRequestId);
  // ɾ������ת��ת���ƻ�����
  virtual int ReqRpcDelPeriodicalTransferPlan(CReqFislRpcDelPeriodicalTransferPlanField *p_pReqField, LONGLONG p_llRequestId);
  // ����֤ȯ��ѯ����
  virtual int ReqQryRpcGuaranteedStk(CReqFislQryRpcGuaranteedStkField *p_pReqField, LONGLONG p_llRequestId);
  // ���֤ȯ��ѯ����
  virtual int ReqQryRpcUnderlyingStk(CReqFislQryRpcUnderlyingStkField *p_pReqField, LONGLONG p_llRequestId);
  // �����������ݲ�ѯ����
  virtual int ReqQryRpcFinancingCreditData(CReqFislQryRpcFinancingCreditDataField *p_pReqField, LONGLONG p_llRequestId);
  // ��ȯ�������ݲ�ѯ����
  virtual int ReqQryRpcMarginCreditData(CReqFislQryRpcMarginCreditDataField *p_pReqField, LONGLONG p_llRequestId);
  // ���ÿͻ��ʲ���ծ��ѯ����
  virtual int ReqQryRpcCreditCustBalance(CReqFislQryRpcCreditCustBalanceField *p_pReqField, LONGLONG p_llRequestId);
  // ������ȯ��Լ��ѯ����
  virtual int ReqQryRpcContract(CReqFislQryRpcContractField *p_pReqField, LONGLONG p_llRequestId);
  // ��ͬ��Ϣ��ѯ����
  virtual int ReqQryRpcAgreementInfo(CReqFislQryRpcAgreementInfoField *p_pReqField, LONGLONG p_llRequestId);
  // ��ΧԼ��ֱ�ӻ��ֱ�ӻ�������
  virtual int ReqRpcDirectRepayment(CReqFislRpcDirectRepaymentField *p_pReqField, LONGLONG p_llRequestId);
  // ��ѯȯ����ȯ�ʻ�ͷ������
  virtual int ReqQryRpcMarginAcctPosi(CReqFislQryRpcMarginAcctPosiField *p_pReqField, LONGLONG p_llRequestId);
  // ���ÿͻ���ת�뵣��֤ȯ��ѯ����
  virtual int ReqQryRpcCreditCustCanTransferInGuaranteedStk(CReqFislQryRpcCreditCustCanTransferInGuaranteedStkField *p_pReqField, LONGLONG p_llRequestId);
  // ͶƱ������ѯ����
  virtual int ReqQryRpcVotingScheme(CReqFislQryRpcVotingSchemeField *p_pReqField, LONGLONG p_llRequestId);
  // ͶƱ�µ�����
  virtual int ReqRpcVotingOrder(CReqFislRpcVotingOrderField *p_pReqField, LONGLONG p_llRequestId);
  // ͶƱ�����ѯ����
  virtual int ReqQryRpcVotingResult(CReqFislQryRpcVotingResultField *p_pReqField, LONGLONG p_llRequestId);
  // ͶƱ���ͳ������
  virtual int ReqRpcVotingResultStatistics(CReqFislRpcVotingResultStatisticsField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ���ͶƱ�鰸��ѯ����
  virtual int ReqQryRpcCanVoteBill(CReqFislQryRpcCanVoteBillField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ���ͶƱָ���鰸�Ĺɷݲ�ѯ����
  virtual int ReqQryRpcCanVoteBillShare(CReqFislQryRpcCanVoteBillShareField *p_pReqField, LONGLONG p_llRequestId);
  // ��Ʊ��ʷ�ɷ�����ѯ����
  virtual int ReqQryRpcHisShareBalance(CReqFislQryRpcHisShareBalanceField *p_pReqField, LONGLONG p_llRequestId);
  // ������ȯ�ʺ�������������
  virtual int ReqRpcSelfActivate(CReqFislRpcSelfActivateField *p_pReqField, LONGLONG p_llRequestId);
  // ��ͬ��Ϣ�޸�����
  virtual int ReqRpcChgAgreementInfo(CReqFislRpcChgAgreementInfoField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ��˻������ò�ѯ����
  virtual int ReqQryRpcAcctLvlFee(CReqFislQryRpcAcctLvlFeeField *p_pReqField, LONGLONG p_llRequestId);
  // ������ȯ�Զ����Լ����˳���ѯ����
  virtual int ReqQryRpcCustomContractRepayOrder(CReqFislQryRpcCustomContractRepayOrderField *p_pReqField, LONGLONG p_llRequestId);
  // ������ȯ�Զ����Լ����˳����������
  virtual int ReqRpcSetCustomContractRepayOrder(CReqFislRpcSetCustomContractRepayOrderField *p_pReqField, LONGLONG p_llRequestId);
  // ��ȯ����ר��֤ȯ��ѯ����
  virtual int ReqQryRpcSpecialMarginAcctStk(CReqFislQryRpcSpecialMarginAcctStkField *p_pReqField, LONGLONG p_llRequestId);
  // ������ȯ��ʷ���˽��Լ��ѯ����
  virtual int ReqQryRpcHisClosedContract(CReqFislQryRpcHisClosedContractField *p_pReqField, LONGLONG p_llRequestId);
  // ��Χ���ý������Բ�ѯ����
  virtual int ReqQryRpcCreditTradeAttribute(CReqFislQryRpcCreditTradeAttributeField *p_pReqField, LONGLONG p_llRequestId);
  // ��Լչ����������
  virtual int ReqRpcContractExtensionApplication(CReqFislRpcContractExtensionApplicationField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ��ȱȶ���ͷű�־�޸�����
  virtual int ReqRpcChgGeometricQuotaReleaseFlag(CReqFislRpcChgGeometricQuotaReleaseFlagField *p_pReqField, LONGLONG p_llRequestId);
  // ��Լչ�������ѯ����
  virtual int ReqQryRpcContractExtensionApplication(CReqFislQryRpcContractExtensionApplicationField *p_pReqField, LONGLONG p_llRequestId);
  // ��Լչ������ȡ������
  virtual int ReqRpcContractExtensionApplicationCancel(CReqFislRpcContractExtensionApplicationCancelField *p_pReqField, LONGLONG p_llRequestId);
  // ��Χ���ղ������Ͳ�ѯ����
  virtual int ReqQryRpcRiskEvaluationMode(CReqFislQryRpcRiskEvaluationModeField *p_pReqField, LONGLONG p_llRequestId);
  // չ�ڹ����ѯ����
  virtual int ReqQryRpcExtensionRule(CReqFislQryRpcExtensionRuleField *p_pReqField, LONGLONG p_llRequestId);
  // ��չ�ں�Լ��ѯ����
  virtual int ReqQryRpcCanExtendContract(CReqFislQryRpcCanExtendContractField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ�����Ȩ�������ϸ��ѯ����
  virtual int ReqQryRpcGuaranteeInterestAdjustmentDetail(CReqFislQryRpcGuaranteeInterestAdjustmentDetailField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ���ʷά�ֵ���������ѯ����
  virtual int ReqQryRpcHisMaintainGuaranteeRatio(CReqFislQryRpcHisMaintainGuaranteeRatioField *p_pReqField, LONGLONG p_llRequestId);
  // ����ͷ��ԤԼ��������
  virtual int ReqRpcFinancingPosiSubApplication(CReqFislRpcFinancingPosiSubApplicationField *p_pReqField, LONGLONG p_llRequestId);
  // ����ͷ��ԤԼ�����ѯ����
  virtual int ReqQryRpcFinancingPosiSubApplication(CReqFislQryRpcFinancingPosiSubApplicationField *p_pReqField, LONGLONG p_llRequestId);
  // ����ͷ����ԤԼ��������
  virtual int ReqRpcChgFinancingPosiSubApplication(CReqFislRpcChgFinancingPosiSubApplicationField *p_pReqField, LONGLONG p_llRequestId);
  // ȡ������ͷ��ԤԼ��������
  virtual int ReqRpcCancelFinancingPosiSubApplication(CReqFislRpcCancelFinancingPosiSubApplicationField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ���������ͷ���ѯ����
  virtual int ReqQryRpcLinkFinancingPosi(CReqFislQryRpcLinkFinancingPosiField *p_pReqField, LONGLONG p_llRequestId);
  // ����Ĭ�����ʿ���ͷ������
  virtual int ReqRpcSetDefaultFinancingOpenPosi(CReqFislRpcSetDefaultFinancingOpenPosiField *p_pReqField, LONGLONG p_llRequestId);
  // ��ȯͷ��ԤԼ��������
  virtual int ReqRpcMarginPosiSubApplication(CReqFislRpcMarginPosiSubApplicationField *p_pReqField, LONGLONG p_llRequestId);
  // ��ȯͷ������������
  virtual int ReqRpcChgMarginPosiApplication(CReqFislRpcChgMarginPosiApplicationField *p_pReqField, LONGLONG p_llRequestId);
  // ��ȯͷ��ԤԼ��ѯ����
  virtual int ReqQryRpcMarginPosiSub(CReqFislQryRpcMarginPosiSubField *p_pReqField, LONGLONG p_llRequestId);
  // ��ȯ����ͷ��ָ������
  virtual int ReqRpcMarginOpenPosiAppoint(CReqFislRpcMarginOpenPosiAppointField *p_pReqField, LONGLONG p_llRequestId);
  // �ͻ�������ȯͷ���ѯ����
  virtual int ReqQryRpcLinkMarginPosi(CReqFislQryRpcLinkMarginPosiField *p_pReqField, LONGLONG p_llRequestId);
  // ��ȯͷ��ԤԼȡ������
  virtual int ReqRpcCancelMarginPosiSub(CReqFislRpcCancelMarginPosiSubField *p_pReqField, LONGLONG p_llRequestId);
  // �ⶳ��ǩ��Ԥ������ʽ�����
  virtual int ReqRpcUnfreezePreFrozenFunds(CReqFislRpcUnfreezePreFrozenFundsField *p_pReqField, LONGLONG p_llRequestId);
  // �������۽ɿ�, ֧��������������
  virtual int ReqRpcCancelRation(CReqFislRpcCancelRationField *p_pReqField, LONGLONG p_llRequestId);
  // ϵͳ̽������
  virtual int ReqBizStatus(CReqFislBizStatusField *p_pReqField, LONGLONG p_llRequestId);
  // ��Ѻ�ɷ���ϸ��ѯ(���ͻ�)����
  virtual int ReqQryPledgeShares(CReqFislQryPledgeSharesField *p_pReqField, LONGLONG p_llRequestId);
  // �ʽ���ˮ��ѯ����
  virtual int ReqQryFundFlow(CReqFislQryFundFlowField *p_pReqField, LONGLONG p_llRequestId);
  // ����ί������
  virtual int ReqOrderEx(CReqFislOrderExField *p_pReqField, LONGLONG p_llRequestId);
  // �ɷ���ˮ��ѯ����
  virtual int ReqQryStockFlow(CReqFislQryStockFlowField *p_pReqField, LONGLONG p_llRequestId);
  // ���н����ղ�ѯ����
  virtual int ReqQrySettDate(CReqFislQrySettDateField *p_pReqField, LONGLONG p_llRequestId);

public:
  // �첽�ص�����
  void OnArCallback(const char *p_pszMsgId, const unsigned char *p_pszDataBuff, int p_iDataLen);

  // �����ص�����
  void OnPsCallback(const char *p_pszAcceptSn, const unsigned char *p_pszDataBuff, int p_iDataLen);
  
private:
  // ֤ȯ��Ϣ��ѯ��Ӧ[����]
  void OnRspQryStkInfoEx(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ���ȯ��Ϣ��ѯ��Ӧ
  void OnRspQryUndlStkInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ����֤ȯ��Ϣ��ѯ��Ӧ
  void OnRspQryColStkInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // LOF��Ϣ��ѯ
  void OnRspQryLofInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ����ί����Ӧ
  void OnRspOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ���ί����Ӧ
  void OnRspCombOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ί�г�����Ӧ
  void OnRspCancelOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ���ɽ�����������Ӧ
  void OnRspMaxTradeQty(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ����ί����Ӧ
  void OnRspQuantityOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ����������Ӧ
  void OnRspQuantityCancelOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ETF ����ί����Ӧ
  void OnRspEtfOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ����ί�����ɽ�����������Ӧ
  void OnRspEtfMaxTradeQty(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ������ȯֱ�ӻ�����Ӧ
  void OnRspMarginRepay(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �����ʽ��ѯ��Ӧ
  void OnRspQryExpendableFund(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ���ùɷݲ�ѯ��Ӧ
  void OnRspQryExpendableShares(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ����ί�в�ѯ��Ӧ
  void OnRspQryCurrDayOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ���ճɽ���ѯ��Ӧ
  void OnRspQryCurrDayFill(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �ɶ��˻���ѯ��Ӧ
  void OnRspQryStkholderAcct(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �ɳ���ί�в�ѯ��Ӧ
  void OnRspQryCanWithdrawOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �����ʽ��ѯ��Ӧ[����]
  void OnRspQryExpendableFundEx(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ���ùɷݲ�ѯ��Ӧ[����]
  void OnRspQryExpendableSharesEx(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ����ί�в�ѯ��Ӧ[����]
  void OnRspQryCurrDayOrderEx(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ���ճɽ���ѯ��Ӧ[����]
  void OnRspQryCurrDayFillEx(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �ɶ��˻���ѯ��Ӧ[����]
  void OnRspQryStkholderAcctEx(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �ɳ���ί�в�ѯ��Ӧ[����]
  void OnRspQryCanWithdrawOrderEx(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ETF �ɷֹɳֲֲ�ѯ��Ӧ
  void OnRspQryEftCotPosition(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ������ȯЭ���ѯ��Ӧ
  void OnRspQryMarginProtocol(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ������ȯ��Լ��ѯ��Ӧ
  void OnRspQryMarginContract(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ������ȯ��֤���������ѯ��Ӧ
  void OnRspQryMarginDepositAvl(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ������ȯ���ÿ��ö�Ȳ�ѯ��Ӧ
  void OnRspQryMarginCreditAvl(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ���ÿͻ��ʲ���ծ��ѯ��Ӧ
  void OnRspQryCreditCustDebts(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ������ȯ�ʽ�ͷ���ѯ��Ӧ
  void OnRspQryMarginFundCash(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ������ȯ�ɷ�ͷ���ѯ��Ӧ
  void OnRspQryMarginSharesCash(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  
  // �ɳ�������ѯ��Ӧ
  void OnRspQryCanRepay(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // ֤ȯ��ֵ��Ȳ�ѯ��Ӧ
  void OnRspQryMktQuota(CFirstSetField *p_pFirstSetField, LONGLONG  p_llRequestId, int p_iFieldNum);

  // ���ʺ�Լ���ܲ�ѯ��Ӧ
  void OnRspQryFiContractSum(CFirstSetField *p_pFirstSetField, LONGLONG  p_llRequestId, int p_iFieldNum);

  // ��ȯ��Լ���ܲ�ѯ��Ӧ
  void OnRspQrySlContractSum(CFirstSetField *p_pFirstSetField, LONGLONG  p_llRequestId, int p_iFieldNum);

  // �ʽ𻮲���Ӧ
  void OnRspQryFundTransfer(CFirstSetField *p_pFirstSetField, LONGLONG  p_llRequestId, int p_iFieldNum);

  // �û���¼������Ӧ
  void OnRspUserLogin(CFirstSetField *p_pFirstSetField, LONGLONG  p_llRequestId, int p_iFieldNum);
  // ������ȯ��ծ������ˮ��ѯ[����]��Ӧ
  void OnRspQryRpcRepaymentDetail(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ʽ��ѯ[����]��Ӧ
  void OnRspQryRpcFund(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �����ʽ���ˮ��ѯ[����]��Ӧ
  void OnRspQryRpcFundDetail(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �¹��깺�ͻ���ֵ��Ȳ�ѯ[����]��Ӧ
  void OnRspQryRpcIPOSubscriptionLimit(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��֤ת��[����]��Ӧ
  void OnRspRpcBankStkTrans(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ�˻����[����]��Ӧ
  void OnRspQryRpcFundBala(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��֤ת�ʲ�ѯ[����]��Ӧ
  void OnRspQryRpcBankStkTransInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �޸��ʽ�����[����]��Ӧ
  void OnRspRpcChgFundPwd(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �޸Ľ�������[����]��Ӧ
  void OnRspRpcChgTrdPwd(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ȡ��ͨת��(����)�˺�(410601) [����]��Ӧ
  void OnRspQryRpcBankAcct(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ȡ��ͨ�ⲿ(����)�˺�(410602) [����]��Ӧ
  void OnRspQryRpcOtherBankAcct(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �����¹��嵥��ѯ(411549) [����]��Ӧ
  void OnRspQryRpcIPO(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Ų�ѯ(411518) [����]��Ӧ
  void OnRspQryRpcDistribution(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ֵ������ǩ��ѯ(411547) [����]��Ӧ
  void OnRspQryRpcMktCapPlacing(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ǩ��ʷ��ѯ(411560) [����]��Ӧ
  void OnRspQryRpcWinningHistory(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ֵ���۽���˳���޸ģ�411548��[����]��Ӧ
  void OnRspRpcChgMktCapDistDeliOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �����ѯ(411520) [����]��Ӧ
  void OnRspQryRpcDeliOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ʲ�ѯ(411521) [����]��Ӧ
  void OnRspQryRpcChkAcct(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ί�л���(410514) [����]��Ӧ
  void OnRspQryRpcOrderSummary(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ճɽ�����(410516) [����]��Ӧ
  void OnRspQryRpcMatchSummary(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ʷί����ϸ��ѯ(411511) [����]��Ӧ
  void OnRspQryRpcHistoryOrderDetail(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ʷ�ɽ���ϸ��ѯ(411513) [����]��Ӧ
  void OnRspQryRpcHistoryMatchDetail(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ת������ҵ����Ϣ(410211) [����]��Ӧ
  void OnRspQryRpcBankTransBasicInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ʵ���ѯ(411525) [����]��Ӧ
  void OnRspQryRpcStatement(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ֤ȯ��Ϣ��Ӧ
  void OnRspRpcStkInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����������Ϣ(ҵ�����)��Ӧ
  void OnRspRpcOrgInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ȡ�ֵ���Ϣ��Ӧ
  void OnRspRpcDictInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ��ǰϵͳ״̬��Ӧ
  void OnRspQryRpcCurSysStat(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �û���¼��Ӧ
  void OnRspRpcLogin(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ɶ���ʧ��Ӧ
  void OnRspRpcTrdacctReportLoss(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ʽ��ʻ���ʧ��Ӧ
  void OnRspRpcCuacctReportLoss(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �������ɶ��ʻ���Ӧ
  void OnRspRpcSetMainTrdacct(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �������ʲ��˺���Ӧ
  void OnRspRpcSetMainCuacct(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �޸���ϵ��ʽ(���Ͻ���ʹ��)��Ӧ
  void OnRspRpcChgContact(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ����ϲ�ѯ��Ӧ
  void OnRspQryRpcCustInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �޸Ĵ���Ȩ����Ӧ
  void OnRspRpcChgProxyPermisson(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �޸Ĳ�����ʽ��Ӧ
  void OnRspRpcChgOperMode(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ�ͻ�������ʽ��Ӧ
  void OnRspQryRpcCustOperMode(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �޸Ŀͻ���ϵ����Ϣ��Ӧ
  void OnRspRpcChgCustInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ�ͻ��ʽ��ʺ�Ȩ����Ӧ
  void OnRspQryRpcCuacctPermission(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �޸��ʽ��ʺ�Ȩ����Ӧ
  void OnRspRpcChgCuacctPermission(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ�ͻ�֤ȯ�ʺ�Ȩ����Ӧ
  void OnRspQryRpcTrdacctPermission(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ÿͻ�֤ȯ�ʺ�Ȩ����Ӧ
  void OnRspRpcSetTrdacctPermission(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ������ȯ������޲�ѯ��Ӧ
  void OnRspQryRpcUpLimitQuota(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ������ȯ��ȱ����Ӧ
  void OnRspRpcChgLimitQuota(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ȱ��������Ӧ
  void OnRspRpcChgLimitQuotaApplication(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ȱ������ȡ����Ӧ
  void OnRspRpcChgLimitQuotaApplicationCancel(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ȱ�������ѯ��Ӧ
  void OnRspQryRpcChgLimitQuotaApplication(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ȡ֤ȯ����ǰ���¼۵�,֧������������Ӧ
  void OnRspRpcStkAvlAndLatestPrice(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ȡ���������,֧������������Ӧ
  void OnRspRpcMaxStkQty(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ί������ҵ��,֧���������ף���ΧԼ��������ȯί����Ӧ
  void OnRspRpcOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ί�г�����Ӧ
  void OnRspRpcOrderCancel(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ί�г�����ѯ��Ӧ
  void OnRspQryRpcOrderCancel(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���óɱ���Ӧ
  void OnRspRpcResetCost(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ӯ�����ü�����Ӧ
  void OnRspRpcCalcFee(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ���ѯ����ѯ�ͻ��ɶ�������Ӧ
  void OnRspQryRpcTrdacct(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ʽ��ѯ��Ӧ
  void OnRspQryRpcCuacct(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ɷ���ϸ��ѯ��Ӧ
  void OnRspQryRpcStkDetail(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ɷݻ��ܲ�ѯ��Ӧ
  void OnRspQryRpcStkSummary(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ʽ��ʻ���ѯ��Ӧ
  void OnRspQryRpcCuacct2(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ���ѯ�����ݹɶ����룬��ѯ�ɶ�������Ӧ
  void OnRspQryRpcTrdacct2(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ���ѯ�����ݹɶ����룬�ʽ��ʻ���ѯ�ͻ�������Ӧ
  void OnRspQryRpcTrdacct3(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ί����ϸ��ѯ��Ӧ
  void OnRspQryRpcOrderDetail(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ճɽ���ϸ��ѯ��Ӧ
  void OnRspQryRpcMatchDetail(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ʷί�л��ܣ���֤ȯ���������������Ӧ
  void OnRspRpcHisOrderSummary(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ʷ�ɽ����ܣ���֤ȯ���������������Ӧ
  void OnRspRpcHisMatchSummary(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ǩ��ѯ��Ӧ
  void OnRspQryRpcLottery(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ί�л���ordergroup+stkcode+bsflag��Ӧ
  void OnRspRpcOrderSummary(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ί�в�ѯ�����ӡ���Ӧ
  void OnRspQryRpcBatchOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �����ʽ��ȡ��ѯ��Ӧ
  void OnRspQryRpcCreditCuacctCanDraw(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Ʊ��ѯ������Ӧ
  void OnRspQryRpcMkt(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���������ѯ��Ӧ
  void OnRspQryRpcMktIntention(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯӪҵ��ĳһҵ�������걨ϯλ��Ӧ
  void OnRspQryRpcSeat(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ�ʽ��˻���Ϣ��Ӧ
  void OnRspQryRpcCuacctAcctInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ����������Ѳ�ѯ��Ӧ
  void OnRspQryRpcCustSpecialFee(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Ϣ����˰������ϸ��ѯ��Ӧ
  void OnRspQryRpcDividendBonusTaxDetail(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �趨����ת��ת���ƻ���Ӧ
  void OnRspRpcSetPeriodicalTransferPlan(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯ����ת��ת���ƻ���Ӧ
  void OnRspQryRpcPeriodicalTransferPlan(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ɾ������ת��ת���ƻ���Ӧ
  void OnRspRpcDelPeriodicalTransferPlan(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����֤ȯ��ѯ��Ӧ
  void OnRspQryRpcGuaranteedStk(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���֤ȯ��ѯ��Ӧ
  void OnRspQryRpcUnderlyingStk(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �����������ݲ�ѯ��Ӧ
  void OnRspQryRpcFinancingCreditData(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ȯ�������ݲ�ѯ��Ӧ
  void OnRspQryRpcMarginCreditData(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ÿͻ��ʲ���ծ��ѯ��Ӧ
  void OnRspQryRpcCreditCustBalance(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ������ȯ��Լ��ѯ��Ӧ
  void OnRspQryRpcContract(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ͬ��Ϣ��ѯ��Ӧ
  void OnRspQryRpcAgreementInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ΧԼ��ֱ�ӻ��ֱ�ӻ�����Ӧ
  void OnRspRpcDirectRepayment(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ѯȯ����ȯ�ʻ�ͷ����Ӧ
  void OnRspQryRpcMarginAcctPosi(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���ÿͻ���ת�뵣��֤ȯ��ѯ��Ӧ
  void OnRspQryRpcCreditCustCanTransferInGuaranteedStk(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ͶƱ������ѯ��Ӧ
  void OnRspQryRpcVotingScheme(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ͶƱ�µ���Ӧ
  void OnRspRpcVotingOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ͶƱ�����ѯ��Ӧ
  void OnRspQryRpcVotingResult(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ͶƱ���ͳ����Ӧ
  void OnRspRpcVotingResultStatistics(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ���ͶƱ�鰸��ѯ��Ӧ
  void OnRspQryRpcCanVoteBill(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ���ͶƱָ���鰸�Ĺɷݲ�ѯ��Ӧ
  void OnRspQryRpcCanVoteBillShare(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Ʊ��ʷ�ɷ�����ѯ��Ӧ
  void OnRspQryRpcHisShareBalance(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ������ȯ�ʺ�����������Ӧ
  void OnRspRpcSelfActivate(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ͬ��Ϣ�޸���Ӧ
  void OnRspRpcChgAgreementInfo(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ��˻������ò�ѯ��Ӧ
  void OnRspQryRpcAcctLvlFee(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ������ȯ�Զ����Լ����˳���ѯ��Ӧ
  void OnRspQryRpcCustomContractRepayOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ������ȯ�Զ����Լ����˳��������Ӧ
  void OnRspRpcSetCustomContractRepayOrder(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ȯ����ר��֤ȯ��ѯ��Ӧ
  void OnRspQryRpcSpecialMarginAcctStk(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ������ȯ��ʷ���˽��Լ��ѯ��Ӧ
  void OnRspQryRpcHisClosedContract(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Χ���ý������Բ�ѯ��Ӧ
  void OnRspQryRpcCreditTradeAttribute(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Լչ��������Ӧ
  void OnRspRpcContractExtensionApplication(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ��ȱȶ���ͷű�־�޸���Ӧ
  void OnRspRpcChgGeometricQuotaReleaseFlag(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Լչ�������ѯ��Ӧ
  void OnRspQryRpcContractExtensionApplication(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Լչ������ȡ����Ӧ
  void OnRspRpcContractExtensionApplicationCancel(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Χ���ղ������Ͳ�ѯ��Ӧ
  void OnRspQryRpcRiskEvaluationMode(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // չ�ڹ����ѯ��Ӧ
  void OnRspQryRpcExtensionRule(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��չ�ں�Լ��ѯ��Ӧ
  void OnRspQryRpcCanExtendContract(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ�����Ȩ�������ϸ��ѯ��Ӧ
  void OnRspQryRpcGuaranteeInterestAdjustmentDetail(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ���ʷά�ֵ���������ѯ��Ӧ
  void OnRspQryRpcHisMaintainGuaranteeRatio(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ͷ��ԤԼ������Ӧ
  void OnRspRpcFinancingPosiSubApplication(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ͷ��ԤԼ�����ѯ��Ӧ
  void OnRspQryRpcFinancingPosiSubApplication(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ͷ����ԤԼ������Ӧ
  void OnRspRpcChgFinancingPosiSubApplication(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ȡ������ͷ��ԤԼ������Ӧ
  void OnRspRpcCancelFinancingPosiSubApplication(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ���������ͷ���ѯ��Ӧ
  void OnRspQryRpcLinkFinancingPosi(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����Ĭ�����ʿ���ͷ����Ӧ
  void OnRspRpcSetDefaultFinancingOpenPosi(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ȯͷ��ԤԼ������Ӧ
  void OnRspRpcMarginPosiSubApplication(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ȯͷ����������Ӧ
  void OnRspRpcChgMarginPosiApplication(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ȯͷ��ԤԼ��ѯ��Ӧ
  void OnRspQryRpcMarginPosiSub(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ȯ����ͷ��ָ����Ӧ
  void OnRspRpcMarginOpenPosiAppoint(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ͻ�������ȯͷ���ѯ��Ӧ
  void OnRspQryRpcLinkMarginPosi(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��ȯͷ��ԤԼȡ����Ӧ
  void OnRspRpcCancelMarginPosiSub(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ⶳ��ǩ��Ԥ������ʽ���Ӧ
  void OnRspRpcUnfreezePreFrozenFunds(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �������۽ɿ�, ֧������������Ӧ
  void OnRspRpcCancelRation(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ϵͳ̽����Ӧ
  void OnRspBizStatus(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ��Ѻ�ɷ���ϸ��ѯ(���ͻ�)��Ӧ
  void OnRspQryPledgeShares(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ʽ���ˮ��ѯ��Ӧ
  void OnRspQryFundFlow(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ����ί��(����)��Ӧ
  void OnRspOrderEx(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // �ɷ���ˮ��ѯ��Ӧ
  void OnRspQryStockFlow(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);
  // ���н����ղ�ѯ��Ӧ
  void OnRspQrySettDate(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

private:

};

END_NAMESPACE_MACLI

#endif  //__MA_CLI_FISL_TRADE_API_H__