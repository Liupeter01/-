#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#include<string.h>
#include<io.h>

 #define MAXBYTE 256

/*
*��Ʒ�Ļ�����Ϣ
*/
typedef struct Commodity
{
          char* Name;   //��Ʒ����
          char* Variety;  //��Ʒ����
          char* Manufacture;//��������
          double Price;//�۸�
          char* Valid_date;//��Ч��
          int Left;//��Ʒ�����
          char* Addition;     //��ע
          int TransAcation; //����״̬����0����û�н�����1��ʼ�˽���
          struct Commodity* pnext;   //������һ���ڵ�

}Commodity;

/*
*��Ʒ�Ĳɹ����۽�����Ϣ
*/
typedef struct Transaction
{
          char* Name;   //��Ʒ����
          int Amount;  //��������
          char* Place;        //���׵ص�
          char* TransTime;   //����ʱ��
          double Price;       //���׽��
          char*TranscationType;         //��������
          char*Operator;      //����Ա
          int TempoaryItemCount;  //��ǰ�������
          struct Transaction* pnext;   //������һ���ڵ�

}Transaction;

/*�����ڴ��ͷŹ���*/
void FreeTransMemory(struct Transaction* phead);
void FreeCommodityMemory(struct Commodity* phead);
/*
*����β�巨
* ��ͬ��Ʒ��Ϣ����Ʒ���Ʋ�����ͬ����������ͬ��Ӧ�ø������ܱ�����Ʒ��Ϣ����ʾģ��
*/
Commodity* AddNodeFromTail(Commodity* phead);
 void WriteToFile(struct Commodity* phead);   //����Ʒ��Ϣд�뵽�ļ�֮��
 static Commodity* LoadMem(Commodity* phead, char* data);