#pragma once

#include"data_structure.h"
/*
*���ļ�����purchasing��Salesͷ�ļ����й��ԵĲ���
*/

/*����Ʒ��Ϣд�뵽�ļ�֮��bankcard_deal.dat*/
void WriteBankCardFile(struct Transaction* phead);

/*����Ʒ������Ϣ���µ�ԭ������Ʒ������Ϣ����ware_base.dat.dat*/
void UpdateBothFile(struct Transaction* phead, struct  Commodity* compare);
