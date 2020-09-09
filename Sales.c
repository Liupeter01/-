#include"Sales.h"

void InitSales()//���ػ�����������Ϣ
{
          if (_access("ware_base.dat", 0) == -1)    //�ж��ļ��Ƿ����
          {
                    printf("��δ������������ƷĿ¼������ѡ��1\n");
                    return;
          }
          /*�ӻ�����Ϣ���ļ��л����Ʒ���ƣ�������Ϣ�ıȽ�*/
          Commodity* compare = NULL;  //���ڴӻ�����Ϣ���������Ϣ
          FILE* pfr = fopen("ware_base.dat", "r");
          printf("----------�����г����еĿ������۵���Ʒ�嵥-------\n\n");
          while (!feof(pfr))
          {
                    char* temp = (char*)calloc(MAXBYTE, sizeof(char));
                    fgets(temp, MAXBYTE, pfr);
                    printf("%s", temp);
                    compare = LoadMem(compare, temp);
          }
          fclose(pfr);
          /*�ڴ�������*/
          printf("\n-----------------------------------------------------------------\n");
          Transaction* saling = NULL;   //�ɹ��ṹ���ͷ�ڵ�
          while (1)
          {
                    saling = SalesAddNodeFromTail(saling, compare);
                    if (saling == NULL)
                    {
                              printf("���������쳣�����ȴ�����Ʒ�Ļ�����Ϣ\n");
                              FreeCommodityMemory(compare);
                              break;
                    }

                    printf("�����Ƿ���Ҫ���������Ϣ(Y/N)��");
                    getchar();
                    char c = getchar();
                    if (c == 'N')
                    {
                              printf("�����Ƿ���Ʒ��ˮд�뵽�ļ�(Y/N)��");
                              getchar();
                              if ((c = getchar()) == 'Y')
                              {
                                        WriteBankCardFile(saling);   //���ɹ���Ϣд����ˮ
                                        UpdateBothFile(saling, compare);  //���»�����Ϣ�ļ�
                              }
                              printf("����������ҳ!\n");
                              FreeCommodityMemory(compare);
                              FreeTransMemory(saling);
                              break;
                    }
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


/*
*��Ʒ��������Ϣ
* ����1��phead��Ϊ�ɹ���Ϣ�����ͷ�ڵ�
* ����2��compare���ڱȽ�����Ʒ��Ϣ���Ƿ���ڴ���Ʒ
* �����Ʒ���ڲſ��Խ������
*/
Transaction* SalesAddNodeFromTail(Transaction* phead, Commodity* compare)
{
          if (phead == NULL && compare == NULL)
          {
                    printf("���ݼ���ʧ��\n");
                    return NULL;
          }
          else
          {
                    Transaction* newnode = (Transaction*)malloc(sizeof(Transaction));  //������һ���ڵ�
                    newnode->pnext = NULL;
                    printf("��������Ʒ��������Ϣ\n");
                    char* temp = (char*)malloc(sizeof(char) * MAXBYTE);  //��ʱ������
                    printf("��������Ʒ���ƣ�");
                    scanf("%s", temp);

                    /*
                    *��ѯ�Ƿ���Ʒ����
                    */
                    int status = 0;
                    struct  Commodity* ptemp = compare;
                    while (1)
                    {
                              if ((ptemp == NULL))
                              {
                                        break;
                              }

                              if (!strcmp(ptemp->Name, temp))   //�������в�ѯ������Ʒ����
                              {
                                        status = 1;
                                        break;
                              }
                              ptemp = ptemp->pnext;
                    }
                    if (!status || ptemp == NULL)
                    {
                              printf("û�д���Ʒ��������Ϣ��¼���ɲ���\n");
                              return phead;
                    }

                    /*
                   *���²������������Ʒ�Ĳɹ���Ϣ������ӵ���������ݽṹ��
                    */
                    newnode->Name = (char*)calloc(sizeof(char), strlen(temp) + 1);
                    strcpy(newnode->Name, temp);
                    memset(temp, 0, MAXBYTE);

                    printf("�����뽻��������");
                    scanf("%d", &newnode->Amount);

                    /*
                    *�ڴ˴���齻��������������������ϵ
                    */
                    if (newnode->Amount >= ptemp->Left)
                    {
                              printf("�����������ڿ��������治�㣬����������\n");
                              return phead;
                    }

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
                    newnode->TransTime = (char*)calloc(sizeof(char), strlen(temp) + 1);
                    strcpy(newnode->TransTime, temp);
                    memset(temp, 0, MAXBYTE);

                    getchar();
                    printf("�����뽻�׵ص㣺");
                    scanf("%[^\n]", temp);
                    newnode->Place = (char*)calloc(sizeof(char), strlen(temp) + 1);
                    strcpy(newnode->Place, temp);
                    memset(temp, 0, MAXBYTE);

                    newnode->TranscationType = (char*)calloc(sizeof(char), strlen("����") + 1);
                    strcpy(newnode->TranscationType, "����");

                    printf("���������Ա��Ϣ��");
                    scanf("%s", temp);
                    newnode->Operator = (char*)calloc(sizeof(char), strlen(temp) + 1);
                    strcpy(newnode->Operator, temp);
                    memset(temp, 0, MAXBYTE);

                    /*
                      *���׽������Զ��Ľ��м���
                     */
                    newnode->Price = newnode->Amount * ptemp->Price;

                    if (phead == NULL)   //������ͷ�ڵ�
                    {
                              phead = newnode;
                    }
                    else
                    {
                              struct Transaction* temp = phead;
                              while (temp->pnext != NULL)
                              {
                                        temp = temp->pnext;
                              }
                              temp->pnext = newnode;  ///����
                    }

                    free(temp);  //������ݻ�����
          }
          return phead;
}