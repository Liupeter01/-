#pragma once
/*
*ɾ��Ĺ��ܼ���
*/
#include"data_structure.h"

void InitEditAndDelete(); //��ʼ���༭��ɾ��
Commodity* Delete(Commodity* phead, char* data);
Commodity* Edit(Commodity*phead, char* data);
static Commodity* LoadMem(Commodity* phead, char* data);