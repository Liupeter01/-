/*
*����ר��
*/
#pragma once
#include"SalesAndPurchasing.h"

void InitSales();   //���ػ�����������Ϣ
static  Commodity* LoadMem(Commodity* phead, char* data);

/*
*��Ʒ��������Ϣ
* ����1��phead��Ϊ�ɹ���Ϣ�����ͷ�ڵ�
* ����2��compare���ڱȽ�����Ʒ��Ϣ���Ƿ���ڴ���Ʒ
* �����Ʒ���ڲſ��Խ������
*/
Transaction* SalesAddNodeFromTail(Transaction* phead, Commodity* compare);
