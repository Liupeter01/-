/*
*�ɹ�ר��
*/
#pragma once
#include"SalesAndPurchasing.h"

void InitPurchasing(); //����ɹ���������
static  Commodity* LoadMem(Commodity* phead, char* data);

/*
*��Ʒ�Ĳɹ���Ϣ
* ����1��phead��Ϊ�ɹ���Ϣ�����ͷ�ڵ�
* ����2��compare���ڱȽ�����Ʒ��Ϣ���Ƿ���ڴ���Ʒ
* �����Ʒ���ڲſ��Խ������
*/
Transaction* PurchasingAddNodeFromTail(Transaction* phead, Commodity* compare);

