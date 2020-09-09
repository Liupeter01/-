#include"SearchAndFind.h"

void InitSearchingUnit()  //��ѯģ���ʼ��
{
          if (_access("ware_base.dat", 0) == -1)    //�ж��ļ��Ƿ����
          {
                    printf("��δ������������ƷĿ¼������ѡ��1\n");
                    return;
          }
          int choice = 0;
          printf("��ӭʹ�ò�ѯϵͳ�������ѡ���ѯ(1������Ʒ������Ϣ��2������Ʒ������Ϣ��0�����ϼ��˵�)��");
          scanf("%d", &choice);
          
          while (1)
          {
                    if (choice == 1)    //��Ʒ�Ļ�����Ϣ
                    {
                              Commodity* phead_commodity = NULL;  //���ڴӻ�����Ϣ���������Ϣ
                              FILE* pfr = fopen("ware_base.dat", "r");
                              while (!feof(pfr))
                              {
                                        char* temp = (char*)calloc(MAXBYTE, sizeof(char));
                                        fgets(temp, MAXBYTE, pfr);
                                        phead_commodity = LoadCommMem(phead_commodity, temp);
                              }
                              fclose(pfr);
                              /*�ڴ�������*/

                              printf("��������Ҫ���ҵķ���(1��Ʒ���ơ�2��Ʒ���ࡢ3�������ҡ�4��Ч��)��");
                              choice = -1;
                              scanf("%d", &choice);

                              printf("��������Ҫ���ҵ����ݣ�");
                              char temp[MAXBYTE] = { 0 };
                              scanf("%s", temp);

                              Commodity* p1 = phead_commodity;
                              int status = 0;

                              if (choice == 1)//��Ʒ����
                              {
                                        while (p1 != NULL)
                                        {
                                                  if (strcmp(p1->Name, temp) == 0)
                                                  {
                                                            printf("%s,%s,%s,%lf,%s,%d,%s,%d\n",
                                                                      p1->Name,
                                                                      p1->Variety,
                                                                      p1->Manufacture,
                                                                      p1->Price,
                                                                      p1->Valid_date,
                                                                      p1->Left,
                                                                      p1->Addition,
                                                                      p1->TransAcation
                                                            );
                                                  }
                                                  p1 = p1->pnext;
                                        }
                                        break;
                              }
                              else if (choice == 2)//��Ʒ����
                              {
                                        while (p1 != NULL)
                                        {
                                                  if (strcmp(p1->Variety, temp) == 0)
                                                  {
                                                            printf("%s,%s,%s,%lf,%s,%d,%s,%d\n",
                                                                      p1->Name,
                                                                      p1->Variety,
                                                                      p1->Manufacture,
                                                                      p1->Price,
                                                                      p1->Valid_date,
                                                                      p1->Left,
                                                                      p1->Addition,
                                                                      p1->TransAcation
                                                            );
                                                  }
                                                  p1 = p1->pnext;
                                        }
                                        break;
                              }
                              else if (choice == 3)//��������
                              {
                                        while (p1 != NULL)
                                        {
                                                  if (strcmp(p1->Manufacture, temp) == 0)
                                                  {
                                                            printf("%s,%s,%s,%lf,%s,%d,%s,%d\n",
                                                                      p1->Name,
                                                                      p1->Variety,
                                                                      p1->Manufacture,
                                                                      p1->Price,
                                                                      p1->Valid_date,
                                                                      p1->Left,
                                                                      p1->Addition,
                                                                      p1->TransAcation
                                                            );
                                                  }
                                                  p1 = p1->pnext;
                                        }
                                        break;
                              }
                              else if (choice == 4)//��Ч��
                              {
                                        while (p1 != NULL)
                                        {
                                                  if (strcmp(p1->Valid_date, temp) == 0)
                                                  {
                                                            printf("%s,%s,%s,%lf,%s,%d,%s,%d\n",
                                                                      p1->Name,
                                                                      p1->Variety,
                                                                      p1->Manufacture,
                                                                      p1->Price,
                                                                      p1->Valid_date,
                                                                      p1->Left,
                                                                      p1->Addition,
                                                                      p1->TransAcation
                                                            );
                                                  }
                                                  p1 = p1->pnext;
                                        }
                                        break;
                              }
                              else
                              {
                                        printf("�������\n");
                                        break;
                              }
                              memset(temp, 0, MAXBYTE);
                              FreeCommodityMemory(phead_commodity);   //�����ڴ�     
                    }
                    else if (choice == 2)//��Ʒ�Ľ�����Ϣ
                    {
                              Transaction* phead_transaction = NULL;  //���ڴӽ�����Ϣ���������Ϣ
                              FILE* pfr = fopen("bankcard_deal.dat", "r");
                              while (!feof(pfr))
                              {
                                        char* temp = (char*)calloc(MAXBYTE, sizeof(char));
                                        fgets(temp, MAXBYTE, pfr);
                                        phead_transaction = LoadTransMem(phead_transaction, temp);
                              }
                              fclose(pfr);
                              /*�ڴ�������*/

                              printf("��������Ҫ���ҵķ���(1��Ʒ���ơ�2����ʱ�䡢"
                                        "3���׵ص㡢4�������͡�5����Ա)��");

                              choice = -1;
                              scanf("%d", &choice);
                              printf("��������Ҫ���ҵ����ݣ�");
                              char temp[MAXBYTE] = { 0 };
                              scanf("%s", temp);

                              Transaction* p1 = phead_transaction;
                              int status = 0;

                              if (choice < 0 || choice>6)
                              {
                                        printf("�������\n");
                              }
                              else if (choice == 1)//��Ʒ����
                              {
                                        while (p1 != NULL)
                                        {
                                                  if (strcmp(p1->Name, temp) == 0)
                                                  {
                                                            printf("%s,%d,%s,%s,%.2lf,%s,%s\n",
                                                                      p1->Name,
                                                                      p1->Amount,
                                                                      p1->TransTime,
                                                                      p1->Place,
                                                                      p1->Price,
                                                                      p1->TranscationType,
                                                                      p1->Operator
                                                            );
                                                  }
                                                  p1 = p1->pnext;
                                        }
                                        break;
                              }
                              else if (choice == 2)//����ʱ��
                              {
                                        while (p1 != NULL)
                                        {
                                                  if (strcmp(p1->TransTime, temp) == 0)
                                                  {
                                                            printf("%s,%d,%s,%s,%.2lf,%s,%s\n",
                                                                      p1->Name,
                                                                      p1->Amount,
                                                                      p1->TransTime,
                                                                      p1->Place,
                                                                      p1->Price,
                                                                      p1->TranscationType,
                                                                      p1->Operator
                                                            );
                                                  }
                                                  p1 = p1->pnext;
                                        }
                                        break;
                              }
                              else if (choice == 3)//���׵ص�
                              {
                                        while (p1 != NULL)
                                        {
                                                  if (strcmp(p1->Place, temp) == 0)
                                                  {
                                                            printf("%s,%d,%s,%s,%.2lf,%s,%s\n",
                                                                      p1->Name,
                                                                      p1->Amount,
                                                                      p1->TransTime,
                                                                      p1->Place,
                                                                      p1->Price,
                                                                      p1->TranscationType,
                                                                      p1->Operator
                                                            );
                                                  }
                                                  p1 = p1->pnext;
                                        }
                                        break;
                              }
                              else if (choice == 4)//��������
                              {
                                        while (p1 != NULL)
                                        {
                                                  if (strcmp(p1->TranscationType, temp) == 0)
                                                  {
                                                            printf("%s,%d,%s,%s,%.2lf,%s,%s\n",
                                                                      p1->Name,
                                                                      p1->Amount,
                                                                      p1->TransTime,
                                                                      p1->Place,
                                                                      p1->Price,
                                                                      p1->TranscationType,
                                                                      p1->Operator
                                                            );
                                                  }
                                                  p1 = p1->pnext;
                                        }
                                        break;
                              }
                              else if (choice == 5)//����Ա
                              {
                                        while (p1 != NULL)
                                        {
                                                  if (strcmp(p1->Operator, temp) == 0)
                                                  {
                                                            printf("%s,%d,%s,%s,%.2lf,%s,%s\n",
                                                                      p1->Name,
                                                                      p1->Amount,
                                                                      p1->TransTime,
                                                                      p1->Place,
                                                                      p1->Price,
                                                                      p1->TranscationType,
                                                                      p1->Operator
                                                            );
                                                  }
                                                  p1 = p1->pnext;
                                        }
                                        break;
                              }
                              memset(temp, 0, MAXBYTE);
                              FreeTransMemory(phead_transaction);
                    }
                    else if (choice == 0)
                    {
                              break;
                    }
                    else
                    {
                              printf("�������\n");
                              break;
                    }
          }
}

static Commodity* LoadCommMem(Commodity* phead, char* data)
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
                      int TransAcation  //����״̬
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

static   Transaction* LoadTransMem(Transaction* phead, char* data)
{
          Transaction* newnode = (Transaction*)malloc(sizeof(Transaction));  //������һ���ڵ�
          newnode->pnext = NULL;

          /*
          *char* Name;   //��Ʒ����
          int Amount;  //��������
          char* Place;        //���׵ص�
          char* TransTime;   //����ʱ��
          double Price;       //���׽��
          char*TranscationType;         //��������
          char*Operator;      //����Ա
          */
          char name[MAXBYTE] = { 0 };          
          char valid_date[MAXBYTE] = { 0 };
          char place[MAXBYTE] = { 0 };
          char type[MAXBYTE] = { 0 };
          char _operator[MAXBYTE] = { 0 };

          for (int i = 0; i < (int)strlen(data); ++i)
          {
                    if (data[i] == ',')
                    {
                              data[i] = ' ';
                    }
          }
          sscanf(data, " %s%d%s%s%lf%s%s",
                    name,
                    &newnode->Amount,
                    place,
                    valid_date,
                    &newnode->Price,
                    type,
                    _operator
          );

          if (strcmp(name, "") == 0)
          {
                    return phead;
          }

          newnode->Name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
          strcpy(newnode->Name, name);

          newnode->TransTime = (char*)malloc(sizeof(char) * (strlen(valid_date) + 1));
          strcpy(newnode->TransTime, valid_date);

          newnode->Place= (char*)malloc(sizeof(char) * (strlen(place) + 1));
          strcpy(newnode->Place, place);

          newnode->TranscationType = (char*)malloc(sizeof(char) * (strlen(type) + 1));
          strcpy(newnode->TranscationType, type);

          newnode->Operator= (char*)malloc(sizeof(char) * (strlen(_operator) + 1));
          strcpy(newnode->Operator, _operator);

          if (phead == NULL)   //������ͷ�ڵ�
          {
                    phead = newnode;
          }
          else
          {
                    Transaction* temp = phead;
                    while (temp->pnext != NULL)
                    {
                              temp = temp->pnext;
                    }
                    temp->pnext = newnode;  ///����
          }
          return phead;
}