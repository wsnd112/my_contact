#define _CRT_SECURE_NO_WARNINGS 1
#define MAX 1000

//#define NAME_MAX 20
//#define SEX_MAX 5
//#define TELE_MAX 12
//#define ADDR_MAX 30

enum Max
{
	NAME_MAX = 20,
    SEX_MAX = 5,
    TELE_MAX = 12,
    ADDR_MAX = 30
};


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct ProInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
};

struct Contact
{
	struct ProInfo date[MAX];
	int size;
};


enum Opition
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

void InitContact(struct Contact* ps);//初始化通讯录
void AddContact(struct Contact* ps);//增加一个信息
void DelContact(struct Contact* ps);//删除一个信息
void SearchContact(const struct Contact* ps);//查找一个联系人
void ModifyContact(struct Contact* ps);//修改联系人
void ShowContact(const struct Contact* ps);//显示通讯录
void SortContact(const struct Contact* ps);//按年龄排序联系人