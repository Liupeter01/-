#include"EditAndDelete.h"

void InitEditAndDelete()//��ʼ���༭��ɾ��
{
          if (_access("ware_base.dat", 0) == -1)    //�ж��ļ��Ƿ����
          {
                    printf("��δ������������ƷĿ¼������ѡ��1\n");
                    return;
          }
          /*�ӻ�����Ϣ���ļ��л����Ʒ���ƣ�������Ϣ�ıȽ�*/
          struct Commodity* compare = NULL;  //���ڴӻ�����Ϣ���������Ϣ
          FILE* pfr = fopen("ware_base.dat", "r");
          while (!feof(pfr))
          {
                    char* temp = (char*)calloc(MAXBYTE, sizeof(char));
                    fgets(temp, MAXBYTE, pfr);
                    printf("%s", temp);
                    compare = LoadMem(compare, temp);
          }
          fclose(pfr);
          /*�ڴ�������*/

          while (1)
          {
                    char* px[2] = { "ɾ��","�޸�" };
                    printf("\n��ѡ���ܣ�(1ɾ����2�޸ġ�0�˳�)��");
                    int i = 0;
                    scanf("%d", &i);

                    char target[MAXBYTE] = { 0 };  //���ڴ�Ų��ҵ���Ʒ����
                    if (i == 1)
                    {
                              printf("������Ҫ%s��Ʒ�����ƣ�", px[i - 1]);
                              scanf("%s", target);
                              compare = Delete(compare, target);  //����ɾ������
                              printf("ɾ���ɹ�!\n");
                    }
                    else if (i == 2)
                    {
                              printf("������Ҫ%s��Ʒ�����ƣ�", px[i - 1]);
                              scanf("%s", target);
                              compare = Edit(compare, target);  //���ñ༭����
                              printf("�޸ĳɹ�!\n");
                    }
                    else if (i == 0)
                    {
                              break;
                    }
                    else
                    {
                              printf("�������\n");
                    }
          }
         
          /*
          *ֱ�Ӹ����ļ�
          */
          FILE* pfw = fopen("ware_base.dat", "w");
          struct Commodity* p2 = compare;
          while (p2 != NULL)
          {
                    fprintf(pfw, "%s,%s,%s,%.2lf,%s,%d,%s,%d\n",
                              p2->Name,
                              p2->Variety,
                              p2->Manufacture,
                              p2->Price,
                              p2->Valid_date,
                              p2->Left,
                              p2->Addition,
                              p2->TransAcation  //����״̬
                    );
                    p2 = p2->pnext;
          }
          fclose(pfw);
          FreeCommodityMemory(compare);
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

Commodity* Delete(Commodity* phead,char*data)
{
          Commodity* p1 = phead;
          Commodity* p2 = NULL;

          int status = 0;

          while (p1 != NULL)
          {
                    if (strcmp(p1->Name, data)!=0)
                    {
                              p2 = p1;
                              p1 = p1->pnext;
                    }
                    else
                    {
                              status = 1;
                              break;
                    }
          }
          
          if (status != 1)
          {
                    printf("��Ʒû�б��ҵ�\n");
                    return phead;
          }
          else
          {
                    if (!p1->TransAcation)
                    {
                              if (p1 == phead)   //p1��ͷ�ڵ�
                              {
                                        phead = phead->pnext;
                                        free(p1->Name);
                                        free(p1->Variety);
                                        free(p1->Valid_date);
                                        free(p1->Manufacture);
                                        free(p1->Addition);
                                        free(p1);
                                        return phead;
                              }
                              else
                              {
                                        p2->pnext = p1->pnext;
                                        free(p1->Name);
                                        free(p1->Variety);
                                        free(p1->Valid_date);
                                        free(p1->Manufacture);
                                        free(p1->Addition);
                                        free(p1);
                                        return phead;
                              }
                    }
                    else
                    {
                              printf("��ǰ��Ʒ���н�����Ϣʱ������ɾ��!\n");
                              return phead;
                    }
          }      
}

Commodity* Edit(Commodity* phead, char* data)
{
          Commodity* p1 = phead;
          int status = 0;

          while (p1 != NULL)
          {
                    if (strcmp(p1->Name, data) != 0)
                    {
                              p1 = p1->pnext;
                    }
                    else
                    {
                              status = 1;
                              break;
                    }
          }
          if (!status)
          {
                    printf("��Ʒû�б��ҵ�\n");
                    return phead;
          }
          else
          {
                    printf("\n��������Ҫ�޸ĵ�����(1��Ʒ���ࡢ2�������ҡ�3�۸�4��Ч�ڡ�5��ע)��");
                    char temp[MAXBYTE]={0};
                    int choice = -1;
                    scanf("%d", &choice);
                    if (choice == 1)  //��Ʒ����
                    {
                              printf("�������޸ĵ������ݣ�");
                              scanf("%s", temp);
                              free(p1->Variety);
                              p1->Variety = (char*)malloc(sizeof(char) * (strlen(temp) + 1));
                              strcpy(p1->Variety, temp);
                    }
                    else if (choice == 2)//��������
                    {
                              printf("�������޸ĵ������ݣ�");
                              scanf("%s", temp);
                              free(p1->Manufacture);
                              p1->Manufacture = (char*)malloc(sizeof(char) * (strlen(temp) + 1));
                              strcpy(p1->Manufacture, temp);
                    }
                    else if (choice == 3)//�۸�
                    {
                              printf("�������޸ĵ������ݣ�");
                              scanf("%lf", &p1->Price);
                    }
                    else if (choice == 4)//��Ч��
                    {
                              free(p1->Valid_date);
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
                              p1->Valid_date = (char*)malloc(sizeof(char) * (strlen(temp) + 1));
                              strcpy(p1->Valid_date, temp);
                    }
                    else if (choice == 5)//��ע
                    {
                              printf("�������޸ĵ������ݣ�");
                              scanf("%s", temp);
                              free(p1->Addition);
                              p1->Addition = (char*)malloc(sizeof(char) * (strlen(temp) + 1));
                              strcpy(p1->Addition, temp);
                    }
                    else if(choice<1 || choice>5)
                    {
                              printf("�������\n");
                    }
                    return phead;
          }
}