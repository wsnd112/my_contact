#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
//实现函数;
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
	return -1;//找不到姓名
}


void AddContact(struct Contact* ps)
{
	if (MAX == ps->size)
	{
		printf("通讯录满了！\n");
	}
	else
	{
		printf("请输入姓名：");
		scanf("%s", ps->date[ps->size].name);
		printf("请输入年龄：");
		scanf("%d", &(ps->date[ps->size].age));
		printf("请输入性别：");
		scanf("%s", ps->date[ps->size].sex);
		printf("请输入电话：");
		scanf("%s", ps->date[ps->size].tele);
		printf("请输入住址：");
		scanf("%s", ps->date[ps->size].addr);
		ps->size++;
		printf("添加成功。\n");
	}
}


void DelContact(struct Contact* ps)
{
	char name[NAME_MAX];
	printf("请输入要删除联系人的姓名：");
	scanf("%s", name);
	//查找
	//查到了返回下标
	//查不到返回-1
	int ret = FindByName(ps, name);
	if (ret == -1)
	{
		printf("找不到联系人！\n");
	}
	else//删除联系人
	{
		int j = 0;
		for (j = ret; j < ps->size - 1; j++)
		{
			ps->date[j] = ps->date[j + 1];
		}
		ps->size--;
		printf("删除成功。\n");
	}
}


void SearchContact(const struct Contact* ps)
{
	char name[NAME_MAX];
	printf("请输入联系人姓名：");
	scanf("%s", name);
	int ret = FindByName(ps, name);
	if (-1 == ret)
	{
		printf("查不到联系人！\n");
	}
	else
	{
		printf("%-12s\t%-12s\t%-12s\t%-12s\t%-12s\n", "姓名", "年龄", "性别", "电话", "住址");
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
	printf("请输入要修改联系人的姓名：");
	scanf("%s", name);
	int ret = FindByName(ps, name);
	if (ret == -1)
	{
		printf("找不到联系人！\n");
	}
	else
	{
		printf("请输入姓名：");
		scanf("%s", ps->date[ret].name);
		printf("请输入年龄：");
		scanf("%d", &(ps->date[ret].age));
		printf("请输入性别：");
		scanf("%s", ps->date[ret].sex);
		printf("请输入电话：");
		scanf("%s", ps->date[ret].tele);
		printf("请输入住址：");
		scanf("%s", ps->date[ret].addr);
		printf("修改成功。\n");
	}
}

void ShowContact(const struct Contact* ps)
{
	printf("%-12s\t%-12s\t%-12s\t%-12s\t%-12s\n", "姓名", "年龄", "性别", "电话", "住址");
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




