#include"data_structure.h"
#include"init.h"

Commodity* Head = NULL;//����ͷ���

/*
*��Ʒ��Ϣ¼��ģ��
*/
void InitCommdity()   //¼����Ʒ����Ϣ
{
          if (_access("ware_base.dat", 0) != -1)    //�ж��ļ��Ƿ����
          {       
                    /*�ļ������ڽ����е���Ϣ�������ڴ�*/
                    /*�ӻ�����Ϣ���ļ��л����Ʒ���ƣ�������Ϣ�ıȽ�*/
                    FILE* pfr = fopen("ware_base.dat", "r");
                    printf("----------�����г����еĻ�����Ʒ��Ϣ�������е�����-------\n\n");
                    while (!feof(pfr))
                    {
                              char* temp = (char*)calloc(MAXBYTE, sizeof(char));
                              fgets(temp, MAXBYTE, pfr);     
                              printf("%s", temp);
                              Head = LoadMem(Head, temp);
                    }
                    fclose(pfr);
                    /*�ڴ�������*/
                    printf("\n-----------------------------------------------------------------\n");
          }
          while (1)
          {
                    Head = AddNodeFromTail(Head);
                    printf("�����Ƿ���Ҫ�����Ʒ(Y/N)��");
                    getchar();
                    char c = getchar();
                    if (c == 'N')
                    {
                              printf("�����Ƿ�洢����(Y/N)��");
                              getchar();
                              if ((c = getchar()) == 'Y')
                              {
                                        WriteToFile(Head);   //���ȷ���洢������Ϣд���ļ�
                              }
                              printf("����������ҳ��\n");
                              FreeCommodityMemory(Head);
                              break;
                    }
          }
          
}

/*
*������Ʒ��Ϣ
*/
Commodity* AddNodeFromTail(Commodity* phead)   
{
          Commodity* newnode = (Commodity*)malloc(sizeof(Commodity));  //������һ���ڵ�
          newnode->pnext = NULL;
          printf("��������Ʒ�Ļ�����Ϣ\n");
          char* temp = (char*)malloc(sizeof(char) * MAXBYTE);  //��ʱ������
          printf("��������Ʒ���ƣ�");
          scanf("%s", temp);

          if (phead != NULL)
          {
                    /*��ѯ�Ƿ���Ʒ����*/
                    struct Commodity* ptemp = phead;
                    while (ptemp != NULL)
                    {
                              if (!strcmp(ptemp->Name, temp))
                              {
                                        printf("��Ʒ���������������Ա���\n");
                                        return phead;
                              }
                              else
                              {
                                        ptemp = ptemp->pnext;
                              }
                    }
          }
      
          newnode->Name = (char*)calloc(sizeof(char), strlen(temp) + 1);
          strcpy(newnode->Name, temp);
          memset(temp, 0, MAXBYTE);

          printf("��������Ʒ���ࣺ");
          scanf("%s", temp);
          newnode->Variety = (char*)calloc(sizeof(char), strlen(temp) + 1);
          strcpy(newnode->Variety, temp);
          memset(temp, 0, MAXBYTE);

          printf("��������Ʒ�������ң�");
          scanf("%s", temp);
          newnode->Manufacture = (char*)calloc(sizeof(char), strlen(temp) + 1);
          strcpy(newnode->Manufacture, temp);
          memset(temp, 0, MAXBYTE);

          printf("��������Ʒ�۸�");
          scanf("%lf", &newnode->Price);

          while (1)
          {
                    printf("��������Ʒ��Ч��(����ʾ�� ���-�·�-��)��");
                    scanf("%s", temp);
                    char* px = temp;
                    int count = 0;
                    while (*px != '\0')
                    {
                              if (*px == '-')
                              {
                                        ++count;
                              }
                              ++px;
                    }
                    if (count != 2)
                    {
                              printf("�������ڴ�������������\n");
                    }
                    else
                    {
                              break;
                    }
          }
         
          newnode->Valid_date = (char*)calloc(sizeof(char), strlen(temp) + 1);
          strcpy(newnode->Valid_date, temp);
          memset(temp, 0, MAXBYTE);

          printf("��������Ʒ�������");
          scanf("%d", &newnode->Left);

          printf("��������Ʒ��ע��");
          scanf("%s", temp);
          newnode->Addition = (char*)calloc(sizeof(char), strlen(temp) + 1);
          strcpy(newnode->Addition, temp);

          newnode->TransAcation = 0;  //��û�н�����Ϣ

          if (phead == NULL)   //������ͷ�ڵ�
          {
                    phead = newnode;
          }
          else
          {
                    Commodity* temp = phead;
                    while (temp->pnext != NULL)
                    {
                              temp = temp->pnext;
                    }
                    temp->pnext = newnode;  ///����

          }
          free(temp);  //������ݻ�����
          return phead;
}

void WriteToFile(struct Commodity* phead)  //����Ʒ������Ϣд�뵽�ļ�֮�� ware_base.dat
{
          FILE* pfw = fopen("ware_base.dat", "w");
          struct Commodity* ptemp = phead;
          while (1)
          {
                    fprintf(pfw, "%s,%s,%s,%lf,%s,%d,%s,%d\n",
                              ptemp->Name,
                              ptemp->Variety,
                              ptemp->Manufacture,
                              ptemp->Price,
                              ptemp->Valid_date,
                              ptemp->Left,
                              ptemp->Addition,
                              ptemp->TransAcation
                    );

                    if (ptemp->pnext == NULL)
                    {
                              break;
                    }
                    else
                    {
                              ptemp = ptemp->pnext;
                    }

          }
          fclose(pfw);
}

/*�����ڴ��ͷŹ���*/
void FreeTransMemory(struct Transaction* phead)
{
          struct Transaction* p1 = phead;
          struct  Transaction* p2 = NULL;
          while (p1 != NULL)
          {
                    p2 = p1;
                    p1 = p1->pnext;  
                    free(p2);
          }
}

void FreeCommodityMemory(struct Commodity* phead)
{
          struct Commodity* p1 = phead;
          struct Commodity* p2 = NULL;
          while (p1 != NULL)
          {
                    p2 = p1;
                    p1 = p1->pnext;
                    free(p2);
          }
}

static Commodity* LoadMem(Commodity* phead, char* data)
{
          Commodity* newnode = (Commodity*)malloc(sizeof(Commodity));  //������һ���ڵ�
          newnode->pnext = NULL;

          /*
          *������ʱ�������ڴ洢������Ϣ
                     char* Name;   //��Ʒ����
                      char* Variety;  //��Ʒ����
                      char* Manufacture;//��������
                      double Price;//�۸�
                     char* Valid_date;//��Ч��
                     int Left;//��Ʒ�����
                      char* Addition;     //��ע
          */
          char name[MAXBYTE] = { 0 };
          char variety[MAXBYTE] = { 0 };
          char manufacture[MAXBYTE] = { 0 };
          char valid_date[MAXBYTE] = { 0 };
          char add[MAXBYTE] = { 0 };

          for (int i = 0; i < (int)strlen(data); ++i)
          {
                    if (data[i] == ',')
                    {
                              data[i] = ' ';
                    }
          }
          sscanf(data, " %s%s%s%lf%s%d%s%d",
                    name,
                    variety,
                    manufacture,
                    &newnode->Price,
                    valid_date,
                    &newnode->Left,
                    add,
                    &newnode->TransAcation
          );

          if (strcmp(name, "") == 0)
          {
                    return phead;
          }

          newnode->Name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
          strcpy(newnode->Name, name);

          newnode->Variety = (char*)malloc(sizeof(char) * (strlen(variety) + 1));
          strcpy(newnode->Variety, variety);

          newnode->Manufacture = (char*)malloc(sizeof(char) * (strlen(manufacture) + 1));
          strcpy(newnode->Manufacture, manufacture);

          newnode->Valid_date = (char*)malloc(sizeof(char) * (strlen(valid_date) + 1));
          strcpy(newnode->Valid_date, valid_date);

          newnode->Addition = (char*)malloc(sizeof(char) * (strlen(add) + 1));
          strcpy(newnode->Addition, add);

          if (phead == NULL)   //������ͷ�ڵ�
          {
                    phead = newnode;
          }
          else
          {
                    Commodity* temp = phead;
                    while (temp->pnext != NULL)
                    {
                              temp = temp->pnext;
                    }
                    temp->pnext = newnode;  ///����
          }
          return phead;
}