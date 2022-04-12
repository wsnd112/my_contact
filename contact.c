#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
//ʵ�ֺ���;
void InitContact(struct Contact* ps)
{
	memset(ps, 0, sizeof(ps->date));
	ps->size = 0;
}

static int FindByName(const struct Contact* ps, char* name)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->date[i].name, name))
		{
			return i;
		}
	}
	return -1;//�Ҳ�������
}


void AddContact(struct Contact* ps)
{
	if (MAX == ps->size)
	{
		printf("ͨѶ¼���ˣ�\n");
	}
	else
	{
		printf("������������");
		scanf("%s", ps->date[ps->size].name);
		printf("���������䣺");
		scanf("%d", &(ps->date[ps->size].age));
		printf("�������Ա�");
		scanf("%s", ps->date[ps->size].sex);
		printf("������绰��");
		scanf("%s", ps->date[ps->size].tele);
		printf("������סַ��");
		scanf("%s", ps->date[ps->size].addr);
		ps->size++;
		printf("��ӳɹ���\n");
	}
}


void DelContact(struct Contact* ps)
{
	char name[NAME_MAX];
	printf("������Ҫɾ����ϵ�˵�������");
	scanf("%s", name);
	//����
	//�鵽�˷����±�
	//�鲻������-1
	int ret = FindByName(ps, name);
	if (ret == -1)
	{
		printf("�Ҳ�����ϵ�ˣ�\n");
	}
	else//ɾ����ϵ��
	{
		int j = 0;
		for (j = ret; j < ps->size - 1; j++)
		{
			ps->date[j] = ps->date[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ���\n");
	}
}


void SearchContact(const struct Contact* ps)
{
	char name[NAME_MAX];
	printf("��������ϵ��������");
	scanf("%s", name);
	int ret = FindByName(ps, name);
	if (-1 == ret)
	{
		printf("�鲻����ϵ�ˣ�\n");
	}
	else
	{
		printf("%-12s\t%-12s\t%-12s\t%-12s\t%-12s\n", "����", "����", "�Ա�", "�绰", "סַ");
		printf("%-12s\t%-12d\t%-12s\t%-12s\t%-12s\n",
			ps->date[ret].name,
			ps->date[ret].age,
			ps->date[ret].sex,
			ps->date[ret].tele,
			ps->date[ret].addr);
	}
}


void ModifyContact(struct Contact* ps)
{
	char name[NAME_MAX];
	printf("������Ҫ�޸���ϵ�˵�������");
	scanf("%s", name);
	int ret = FindByName(ps, name);
	if (ret == -1)
	{
		printf("�Ҳ�����ϵ�ˣ�\n");
	}
	else
	{
		printf("������������");
		scanf("%s", ps->date[ret].name);
		printf("���������䣺");
		scanf("%d", &(ps->date[ret].age));
		printf("�������Ա�");
		scanf("%s", ps->date[ret].sex);
		printf("������绰��");
		scanf("%s", ps->date[ret].tele);
		printf("������סַ��");
		scanf("%s", ps->date[ret].addr);
		printf("�޸ĳɹ���\n");
	}
}

void ShowContact(const struct Contact* ps)
{
	printf("%-12s\t%-12s\t%-12s\t%-12s\t%-12s\n", "����", "����", "�Ա�", "�绰", "סַ");
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%-12s\t%-12d\t%-12s\t%-12s\t%-12s\n",
			ps->date[i].name,
			ps->date[i].age,
			ps->date[i].sex,
			ps->date[i].tele,
			ps->date[i].addr);
	}
}
int compar_age(const void* p1, const void* p2)
{
	return (((struct Contact*)p1)->date->age - ((struct Contact*)p2)->date->age);
}
int compar_name(const void* p1, const void* p2)
{
	return strcmp(((struct Contact*)p1)->date->name, ((struct Contact*)p2)->date->name);
}

void SortContact(const struct Contact* ps)
{
	qsort(ps->date, ps->size, sizeof(ps->date[0]), compar_age);
	ShowContact(ps);
}




