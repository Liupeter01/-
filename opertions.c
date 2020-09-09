#include"opertions.h"
#include"EditAndDelete.h"
#include"Sales.h"
#include"purchasing.h"
#include"init.h"
#include"SearchAndFind.h"
#include"statistics.h"

void Menu()   //������ʼ�˵���
{
          while (1)
          {
                    printf("\n       ��ӭʹ��С�ͳ��й���ϵͳ by�����    \n"
                              "                  ѡ��˵�         \n"
                              "             1��¼����Ʒ�Ļ�����Ϣ                \n"
                              "             2����Ʒ�ɹ�����                \n"
                              "             3����Ʒ���۹���                \n"
                              "             4��ά����Ʒ������Ϣ(�����޸ġ�ɾ��)                \n"
                              "             5�������Ʒ������Ϣ                \n"
                              "             6�������Ʒ������Ϣ                \n"
                              "             7����ѯ����                \n"
                              "             8��ͳ�ƹ���                \n"
                              "             9���˳�ϵͳ                \n"
                    );

                    printf("\n��������Ҫִ�еĲ�����");
                    int choice = -1;
                    scanf_s("%d", &choice);
                    switch (choice)
                    {
                    case 1:InitCommdity(); break;
                    case 2:InitPurchasing(); break;   //�ɹ�����
                    case 3:InitSales(); break;   //����
                    case 4:InitEditAndDelete(); break; //�޸�ɾ��
                    case 5:DisplayAllBasicInfo(); break;
                    case 6:DisplayAllTransInfo(); break;
                    case 7:InitSearchingUnit(); break;
                    case 8:InitStatistics(); break;
                    case 9:Quit(); break;
                    default: printf("�����������������!!!!\n");
                              break;
                    }
          }
}

void DisplayAllBasicInfo()  //���ȫ����Ʒ�Ļ�����Ϣ
{
          if (_access("ware_base.dat", 0) == -1)    //�ж��ļ��Ƿ����
          {
                    printf("��δ������������ƷĿ¼������ѡ��1\n");
                    return;
          }
          FILE* pfr = fopen("ware_base.dat", "r");
          while (!feof(pfr))
          {
                    char mem[MAXBYTE] = { 0 };
                    fgets(mem, MAXBYTE, pfr);
                    printf("%s", mem);
                    memset(mem, 0, MAXBYTE);
          }
          fclose(pfr);
          fclose(pfr);
}

void DisplayAllTransInfo() //���ȫ����Ʒ�Ľ�����Ϣ
{
          FILE* pfr = fopen("bankcard_deal.dat", "r");
          while (!feof(pfr))
          {
                    char mem[MAXBYTE] = { 0 };
                    fgets(mem, MAXBYTE, pfr);
                    printf("%s", mem);
                    memset(mem, 0, MAXBYTE);
          }
          fclose(pfr);
}