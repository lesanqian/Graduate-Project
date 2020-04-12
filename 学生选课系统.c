#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
#include<string> 
using namespace std;

#define SIZE_STU 10
#define SIZE_COU 10
#define SIZE_SEL 10
void home(void);
void choose(void);
void searchke(void);
//选课信息部分：
void dayis(char a[]);
void dayix(char a[]);
void daers(char a[]);
void daerx(char a[]);
void dasans(char a[]);
void dasanx(char a[]);
void dasis(char a[]);
void dasix(char a[]);
int kecheng();
/*选课查询部分*/
void dayis1(char a[]);
void dayix1(char a[]);
void daers1(char a[]);
void daerx1(char a[]);
void dasans1(char a[]);
void dasanx1(char a[]);
void dasis1(char a[]);
void dasix1(char a[]);
/*已修课程结构体*/
struct course {
	char course_ID[9];
	int guo;
};
/*选修课程*/
struct xuancourse
{
	char course_id[9];
	char course_name[100];
}xuan[SIZE_COU];
/*专业课关系结构体*/
struct zhuanye
{
	char course_id[10];
	int guo;
}zhuan[10];
/*学生信息结构体*/
struct student {
	char stu_ID[20];
	struct xuancourse xuan1[10];
}stu[SIZE_STU];
struct student1 {
	char stu_ID[20];
	struct course  ke[10];
}stu1[SIZE_STU];
/*课程信息结构体*/
struct course_info {
	char course_ID[9];
	char course_name[100];
	char property[9];
	char period[9];
	char credit[9];
	char time[9];
	int people;
}cou[SIZE_COU];
/*选课记录结构体*/
struct select {
	int s;//存放学生信息的数组下标 
	int c;//存放课程信息的数组下标 
}sel[SIZE_SEL];

//全局变量i,j,x分别是学生,课程,选课信息数组下标
int i = -1;
int j = -1;
int x = -1;

int main(void) {
	//进入欢迎界面 
	home();
	return 0;
}

//欢迎界面 
void home(void) {
	printf("\n-------------------------欢迎进入选课系统！----------------------");
	int h;
	printf("\n\n                    请选择你要进行的操作：");
	printf("\n                         1.开始选课");
	printf("\n                         2.选课查询");
	printf("\n                         3.退出系统");
	printf("\n                                                      ");
	printf("\n                        请输入：");
	scanf("%d", &h);
	system("cls");
	switch (h) {
	case 1:
		choose();
		break;
	case 2:
		searchke();
		break;
	default:
		system("cls");
		printf("BYE!");
		break;
	}
}
/*开始选课*/
void choose(void) {
	char stu_id[15];
	FILE *fp;
	printf("\n-------------------------欢迎进入选课系统！----------------------");
	//输入选课学生信息 
	fp = fopen("ID.txt", "r");
	int i = 0;
	while(fscanf(fp,"%s",stu[i].stu_ID)!=EOF)
		i++;
	printf("\n\n                 请输入选课人学号：");
	fflush(stdin);
	scanf("%s", stu_id);
	int h, flag = 0;
	for (h = 0; h <= i; h++) {
		if (strcmp(stu[h].stu_ID, stu_id) == 0) {
			flag = 0;
			break;
		}
		else {
			flag = 1;
		}
	}
	if (flag || i == -1) {
		printf("\n                 不存在此学号\n");
		system("pause");
		system("cls");
		home();
	}
	printf("\n\n                 请输入当前学年：");
	char a[4];
	cin >> a;
	printf("\n\n                 请输入选课人学期：");
	int n;
	cin >> n;
	int z;
	z = a[3] - stu_id[1];
	system("cls");
	if (n == 1)
	{
		switch (z)
		{
		case 0:
			dayis(stu_id);
			break;
		case 1:
			daers(stu_id);
			break;
		case 2:
			dasans(stu_id);
			break;
		case 3:
			dasis(stu_id);
			break;
		}
	}
	else
	{
		switch (z)
		{
		case 1:
			dayix(stu_id);
			break;
		case 2:
			daerx(stu_id);
			break;
		case 3:
			dasanx(stu_id);
			break;
		case 4:
			dasix(stu_id);
			break;
		}
	}
	printf("请继续以下操作：");
	system("pause");
	system("cls");
	home();
}
int kecheng()
{
	FILE *fp;
	fp = fopen("专业课关系.txt", "r");
	int i=0,n;
	while (fscanf(fp, "%s", zhuan[i].course_id) != EOF)
		i++;
	n = i;
	for (i = 0; i < n; i++)
	{
		zhuan[i].guo = 1;
	}
	return n;
}
void dayis(char a[])
{
	FILE *fp,*f1;
	fp = fopen("大一上.txt", "r");
	int i = 0,n,j=0,flag=0,m;
	while (fscanf(fp, "%s %s", cou[i].course_ID,cou[i].course_name) != EOF)
		i++;
	n = i;
	for (i = 0; i < n; i++)
		cout << cou[i].course_ID <<"  "<<cou[i].course_name<<endl;
	printf("  请输入要添加课程的代码\n");
	for (i = 0;i<3; i++)
	{
		cin >> xuan[i].course_id;
		for (j = 0; j < n; j++)
		{
			if (strcmp(xuan[i].course_id, cou[j].course_ID) == 0)
			{
				strcpy(xuan[i].course_name,cou[j].course_name);
				flag = 1;
			}
		}
		if (flag == 1)
			printf("\n 选课成功，请继续选课\n");
		else
		{
			i--;
			printf("\n 输入有误，请重新输入\n");
		}
	}
	m = i;
	f1 = fopen("大一上学生选课.txt", "w");
	fprintf(f1, "%s", a);
	for (i = 0; i < 3; i++)
	{
		fprintf(f1, "\n %s    %s", xuan[i].course_id,xuan[i].course_name);
	}
	fclose(f1);
	fclose(fp);

}
void dayix(char a[])
{
	FILE *fp, *f1,*f2;
	fp = fopen("大一下.txt", "r");
	int i = 0, n, j = 0, flag = 0, m,s,k;
	while (fscanf(fp, "%s %s", cou[i].course_ID, cou[i].course_name) != EOF)
		i++;
	n = i;
	f2 = fopen("大一学生信息.txt", "r");
	for (i = 0; i < 2; i++)
	{
		fscanf(f2, "%s", stu1[i].stu_ID);
		for (j = 0; j < 8; j++)
			fscanf(f2, "%s %d", stu1[i].ke[j].course_ID, &stu1[i].ke[j].guo);
		if (strcmp(stu1[i].stu_ID, a) == 0)
			s = i;
	}
	int y;
	y = kecheng();
	for (i = 0; i < 8; i++)
		{
			for (j = 0; j < y; j++)
			   if (strcmp(stu1[s].ke[i].course_ID, zhuan[j].course_id) == 0)
				        zhuan[j].guo = stu1[s].ke[i].guo;
		}
	for (i = 0; i < n; i++)
		cout << cou[i].course_ID << "  " << cou[i].course_name << endl;
	printf("  请输入要添加课程的代码\n");
	for (i = 0; i < 3; i++)
	{
		cin >> xuan[i].course_id;
		for (j = 0; j < n; j++)
		{
			if (strcmp(xuan[i].course_id, cou[j].course_ID) == 0)
			{
				strcpy(xuan[i].course_name, cou[j].course_name);
				flag = 1;
			}
		}
		if (flag == 1)
		{
			int flad = 1;
			for (j = 0; j < y; j++)
			{
				if (strcmp(xuan[i].course_id, zhuan[j].course_id) == 0)
					for (k = 0; k < j; k++)
					{
						if (zhuan[k].guo == 0)
						{
							flad = 0;
							i--;
							printf("\n抱歉您之前的课程没通过，无法选修该课程，请重新选择\n");
							break;
						}
					}
			}
			if (flad == 1 && i + 1 != 3)
				printf("\n 选课成功，请继续选课\n");
			else
				if(flad==1&&i+1==3)
				printf("\n选课结束\n");
		}
		else
		{
			i--;
			printf("\n 输入有误，请重新输入\n");
		}
	}
	m = i;
	f1 = fopen("大一下学生选课.txt", "w");
	fprintf(f1, "%s", a);
	for (i = 0; i < 3; i++)
	{
		fprintf(f1, "\n %s    %s", xuan[i].course_id, xuan[i].course_name);
	}
	fclose(f1);
	fclose(fp);
}
void daers(char a[])
{
	FILE *fp, *f1,*f2;
	fp = fopen("大二上.txt", "r");
	int i = 0, n, j = 0, flag = 0, m,s,k;
	while (fscanf(fp, "%s %s", cou[i].course_ID, cou[i].course_name) != EOF)
		i++;
	n = i;
	f2 = fopen("大二学生信息.txt", "r");
	for (i = 0; i < 2; i++)
	{
		fscanf(f2, "%s", stu1[i].stu_ID);
		for (j = 0; j < 8; j++)
			fscanf(f2, "%s %d", stu1[i].ke[j].course_ID, &stu1[i].ke[j].guo);
		if (strcmp(stu1[i].stu_ID, a) == 0)
			s = i;
	}
	int y;
	y = kecheng();
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < y; j++)
			if (strcmp(stu1[s].ke[i].course_ID, zhuan[j].course_id) == 0)
				zhuan[j].guo = stu1[s].ke[i].guo;
	}
	for (i = 0; i < n; i++)
		cout << cou[i].course_ID << "  " << cou[i].course_name << endl;
	printf("  请输入要添加课程的代码\n");
	for (i = 0; i < 3; i++)
	{
		cin >> xuan[i].course_id;
		for (j = 0; j < n; j++)
		{
			if (strcmp(xuan[i].course_id, cou[j].course_ID) == 0)
			{
				strcpy(xuan[i].course_name, cou[j].course_name);
				flag = 1;
			}
		}
		if (flag == 1)
		{
			int flad = 1;
			for (j = 0; j < y; j++)
			{
				if (strcmp(xuan[i].course_id, zhuan[j].course_id) == 0)
					for (k = 0; k < j; k++)
					{
						if (zhuan[k].guo == 0)
						{
							flad = 0;
							i--;
							printf("\n抱歉您之前的课程没通过，无法选修该课程，请重新选择\n");
							break;
						}
					}
			}
			if (flad == 1 && i + 1 != 3)
				printf("\n 选课成功，请继续选课\n");
			else
				if (flad == 1 && i + 1 == 3)
					printf("\n选课结束\n");
		}
		else
		{
			i--;
			printf("\n 输入有误，请重新输入\n");
		}
	}
	m = i;
	f1 = fopen("大二上学生选课.txt", "w");
	fprintf(f1, "%s", a);
	for (i = 0; i < 3; i++)
	{
		fprintf(f1, "\n %s    %s", xuan[i].course_id, xuan[i].course_name);
	}
	fclose(f1);
	fclose(fp);
}
void daerx(char a[])
{
	FILE *fp, *f1,*f2;
	fp = fopen("大二下.txt", "r");
	int i = 0, n, j = 0, flag = 0, m,s,k;
	while (fscanf(fp, "%s %s", cou[i].course_ID, cou[i].course_name) != EOF)
		i++;
	n = i;
	f2 = fopen("大二学生信息.txt", "r");
	for (i = 0; i < 2; i++)
	{
		fscanf(f2, "%s", stu1[i].stu_ID);
		for (j = 0; j < 8; j++)
			fscanf(f2, "%s %d", stu1[i].ke[j].course_ID, &stu1[i].ke[j].guo);
		if (strcmp(stu1[i].stu_ID, a) == 0)
			s = i;
	}
	int y;
	y = kecheng();
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < y; j++)
			if (strcmp(stu1[s].ke[i].course_ID, zhuan[j].course_id) == 0)
				zhuan[j].guo = stu1[s].ke[i].guo;
	}
	for (i = 0; i < n; i++)
		cout << cou[i].course_ID << "  " << cou[i].course_name << endl;
	printf("  请输入要添加课程的代码\n");
	for (i = 0; i < 3; i++)
	{
		cin >> xuan[i].course_id;
		for (j = 0; j < n; j++)
		{
			if (strcmp(xuan[i].course_id, cou[j].course_ID) == 0)
			{
				strcpy(xuan[i].course_name, cou[j].course_name);
				flag = 1;
			}
		}
		if (flag == 1)
		{
			int flad = 1;
			for (j = 0; j < y; j++)
			{
				if (strcmp(xuan[i].course_id, zhuan[j].course_id) == 0)
					for (k = 0; k < j; k++)
					{
						if (zhuan[k].guo == 0)
						{
							flad = 0;
							i--;
							printf("\n抱歉您之前的课程没通过，无法选修该课程，请重新选择\n");
							break;
						}
					}
			}
			if (flad == 1 && i + 1 != 3)
				printf("\n 选课成功，请继续选课\n");
			else
				if (flad == 1 && i + 1 == 3)
					printf("\n选课结束\n");
		}
		else
		{
			i--;
			printf("\n 输入有误，请重新输入\n");
		}
	}
	m = i;
	f1 = fopen("大二下学生选课.txt", "w");
	fprintf(f1, "%s", a);
	for (i = 0; i < 3; i++)
	{
		fprintf(f1, "\n %s    %s", xuan[i].course_id, xuan[i].course_name);
	}
	fclose(f1);
	fclose(fp);
}
void dasans(char a[])
{
	FILE *fp, *f1,*f2;
	fp = fopen("大三上.txt", "r");
	int i = 0, n, j = 0, flag = 0, m,s,k;
	while (fscanf(fp, "%s %s", cou[i].course_ID, cou[i].course_name) != EOF)
		i++;
	n = i;
	f2 = fopen("大三学生信息.txt", "r");
	for (i = 0; i < 2; i++)
	{
		fscanf(f2, "%s", stu1[i].stu_ID);
		for (j = 0; j < 8; j++)
			fscanf(f2, "%s %d", stu1[i].ke[j].course_ID, &stu1[i].ke[j].guo);
		if (strcmp(stu1[i].stu_ID, a) == 0)
			s = i;
	}
	int y;
	y = kecheng();
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < y; j++)
			if (strcmp(stu1[s].ke[i].course_ID, zhuan[j].course_id) == 0)
				zhuan[j].guo = stu1[s].ke[i].guo;
	}
	for (i = 0; i < n; i++)
		cout << cou[i].course_ID << "  " << cou[i].course_name << endl;
	printf("  请输入要添加课程的代码\n");
	for (i = 0; i < 3; i++)
	{
		cin >> xuan[i].course_id;
		for (j = 0; j < n; j++)
		{
			if (strcmp(xuan[i].course_id, cou[j].course_ID) == 0)
			{
				strcpy(xuan[i].course_name, cou[j].course_name);
				flag = 1;
			}
		}
		if (flag == 1)
		{
			int flad = 1;
			for (j = 0; j < y; j++)
			{
				if (strcmp(xuan[i].course_id, zhuan[j].course_id) == 0)
					for (k = 0; k < j; k++)
					{
						if (zhuan[k].guo == 0)
						{
							flad = 0;
							i--;
							printf("\n抱歉您之前的课程没通过，无法选修该课程，请重新选择\n");
							break;
						}
					}
			}
			if (flad == 1 && i + 1 != 3)
				printf("\n 选课成功，请继续选课\n");
			else
				if (flad == 1 && i + 1 == 3)
					printf("\n选课结束\n");
		}
		else
		{
			i--;
			printf("\n 输入有误，请重新输入\n");
		}
	}
	m = i;
	f1 = fopen("大三上学生选课.txt", "w");
	fprintf(f1, "%s", a);
	for (i = 0; i < 3; i++)
	{
		fprintf(f1, "\n %s    %s", xuan[i].course_id, xuan[i].course_name);
	}
	fclose(f1);
	fclose(fp);
}
void dasanx(char a[])
{
	FILE *fp, *f1,*f2;
	fp = fopen("大三下.txt", "r");
	int i = 0, n, j = 0, flag = 0, m,s,k;
	while (fscanf(fp, "%s %s", cou[i].course_ID, cou[i].course_name) != EOF)
		i++;
	n = i;
	f2 = fopen("大三学生信息.txt", "r");
	for (i = 0; i < 2; i++)
	{
		fscanf(f2, "%s", stu1[i].stu_ID);
		for (j = 0; j < 8; j++)
			fscanf(f2, "%s %d", stu1[i].ke[j].course_ID, &stu1[i].ke[j].guo);
		if (strcmp(stu1[i].stu_ID, a) == 0)
			s = i;
	}
	int y;
	y = kecheng();
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < y; j++)
			if (strcmp(stu1[s].ke[i].course_ID, zhuan[j].course_id) == 0)
				zhuan[j].guo = stu1[s].ke[i].guo;
	}
	for (i = 0; i < n; i++)
		cout << cou[i].course_ID << "  " << cou[i].course_name << endl;
	printf("  请输入要添加课程的代码\n");
	for (i = 0; i < 3; i++)
	{
		cin >> xuan[i].course_id;
		for (j = 0; j < n; j++)
		{
			if (strcmp(xuan[i].course_id, cou[j].course_ID) == 0)
			{
				strcpy(xuan[i].course_name, cou[j].course_name);
				flag = 1;
			}
		}
		if (flag == 1)
		{
			int flad = 1;
			for (j = 0; j < y; j++)
			{
				if (strcmp(xuan[i].course_id, zhuan[j].course_id) == 0)
					for (k = 0; k < j; k++)
					{
						if (zhuan[k].guo == 0)
						{
							flad = 0;
							i--;
							printf("\n抱歉您之前的课程没通过，无法选修该课程，请重新选择\n");
							break;
						}
					}
			}
			if (flad == 1 && i + 1 != 3)
				printf("\n 选课成功，请继续选课\n");
			else
				if (flad == 1 && i + 1 == 3)
					printf("\n选课结束\n");
		}
		else
		{
			i--;
			printf("\n 输入有误，请重新输入\n");
		}
	}
	m = i;
	f1 = fopen("大三下学生选课.txt", "w");
	fprintf(f1, "%s", a);
	for (i = 0; i < 3; i++)
	{
		fprintf(f1, "\n %s    %s", xuan[i].course_id, xuan[i].course_name);
	}
	fclose(f1);
	fclose(fp);
}
void dasis(char a[])
{
	FILE *fp, *f1,*f2;
	fp = fopen("大四上.txt", "r");
	int i = 0, n, j = 0, flag = 0, m,s,k;
	while (fscanf(fp, "%s %s", cou[i].course_ID, cou[i].course_name) != EOF)
		i++;
	n = i;
	f2 = fopen("大四学生信息.txt", "r");
	for (i = 0; i < 2; i++)
	{
		fscanf(f2, "%s", stu1[i].stu_ID);
		for (j = 0; j < 8; j++)
			fscanf(f2, "%s %d", stu1[i].ke[j].course_ID, &stu1[i].ke[j].guo);
		if (strcmp(stu1[i].stu_ID, a) == 0)
			s = i;
	}
	int y;
	y = kecheng();
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < y; j++)
			if (strcmp(stu1[s].ke[i].course_ID, zhuan[j].course_id) == 0)
				zhuan[j].guo = stu1[s].ke[i].guo;
	}
	for (i = 0; i < n; i++)
		cout << cou[i].course_ID << "  " << cou[i].course_name << endl;
	printf("  请输入要添加课程的代码\n");
	for (i = 0; i < 3; i++)
	{
		cin >> xuan[i].course_id;
		for (j = 0; j < n; j++)
		{
			if (strcmp(xuan[i].course_id, cou[j].course_ID) == 0)
			{
				strcpy(xuan[i].course_name, cou[j].course_name);
				flag = 1;
			}
		}
		if (flag == 1)
		{
			int flad = 1;
			for (j = 0; j < y; j++)
			{
				if (strcmp(xuan[i].course_id, zhuan[j].course_id) == 0)
					for (k = 0; k < j; k++)
					{
						if (zhuan[k].guo == 0)
						{
							flad = 0;
							i--;
							printf("\n抱歉您之前的课程没通过，无法选修该课程，请重新选择\n");
							break;
						}
					}
			}
			if (flad == 1 && i + 1 != 3)
				printf("\n 选课成功，请继续选课\n");
			else
				if (flad == 1 && i + 1 == 3)
					printf("\n选课结束\n");
		}
		else
		{
			i--;
			printf("\n 输入有误，请重新输入\n");
		}
	}
	m = i;
	f1 = fopen("大四上学生选课.txt", "w");
	fprintf(f1, "%s", a);
	for (i = 0; i < 3; i++)
	{
		fprintf(f1, "\n %s    %s", xuan[i].course_id, xuan[i].course_name);
	}
	fclose(f1);
	fclose(fp);
}
void dasix(char a[])
{
	FILE *fp, *f1,*f2;
	fp = fopen("大四下.txt", "r");
	int i = 0, n, j = 0, flag = 0, m,s,k;
	while (fscanf(fp, "%s %s", cou[i].course_ID, cou[i].course_name) != EOF)
		i++;
	n = i;
	f2 = fopen("大四学生信息.txt", "r");
	for (i = 0; i < 2; i++)
	{
		fscanf(f2, "%s", stu1[i].stu_ID);
		for (j = 0; j < 8; j++)
			fscanf(f2, "%s %d", stu1[i].ke[j].course_ID, &stu1[i].ke[j].guo);
		if (strcmp(stu1[i].stu_ID, a) == 0)
			s = i;
	}
	int y;
	y = kecheng();
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < y; j++)
			if (strcmp(stu1[s].ke[i].course_ID, zhuan[j].course_id) == 0)
				zhuan[j].guo = stu1[s].ke[i].guo;
	}
	for (i = 0; i < n; i++)
		cout << cou[i].course_ID << "  " << cou[i].course_name << endl;
	printf("  请输入要添加课程的代码\n");
	for (i = 0; i < 3; i++)
	{
		cin >> xuan[i].course_id;
		for (j = 0; j < n; j++)
		{
			if (strcmp(xuan[i].course_id, cou[j].course_ID) == 0)
			{
				strcpy(xuan[i].course_name, cou[j].course_name);
				flag = 1;
			}
		}
		if (flag == 1)
		{
			int flad = 1;
			for (j = 0; j < y; j++)
			{
				if (strcmp(xuan[i].course_id, zhuan[j].course_id) == 0)
					for (k = 0; k < j; k++)
					{
						if (zhuan[k].guo == 0)
						{
							flad = 0;
							i--;
							printf("\n抱歉您之前的课程没通过，无法选修该课程，请重新选择\n");
							break;
						}
					}
			}
			if (flad == 1 && i + 1 != 3)
				printf("\n 选课成功，请继续选课\n");
			else
				if (flad == 1 && i + 1 == 3)
					printf("\n选课结束\n");
		}
		else
		{
			i--;
			printf("\n 输入有误，请重新输入\n");
		}
	}
	m = i;
	f1 = fopen("大四下学生选课.txt", "w");
	fprintf(f1, "%s", a);
	for (i = 0; i < 3; i++)
	{
		fprintf(f1, "\n %s    %s", xuan[i].course_id, xuan[i].course_name);
	}
	fclose(f1);
	fclose(fp); 
}
//选课查询
void searchke()
{
	char stu_id[15];
	FILE *fp;
	printf("\n-------------------------欢迎进入选课系统！----------------------");
	//输入选课学生信息 
	fp = fopen("ID.txt", "r");
	int i = 0;
	while (fscanf(fp, "%s", stu[i].stu_ID) != EOF)
		i++;
	printf("\n\n                 请输入学号：");
	fflush(stdin);
	scanf("%s", stu_id);
	int h, flag = 0;
	for (h = 0; h <= i; h++) {
		if (strcmp(stu[h].stu_ID, stu_id) == 0) {
			flag = 0;
			break;
		}
		else {
			flag = 1;
		}
	}
	if (flag || i == -1) {
		printf("\n                 不存在此学号\n");
		system("pause");
		system("cls");
		home();
	}
	printf("\n\n                 请输入当前学年：");
	char a[4];
	cin >> a;
	printf("\n\n                 请输入选课人学期：");
	int n;
	cin >> n;
	int z;
	z = a[3] - stu_id[1];
	system("cls");
	if (n == 1)
	{
		switch (z)
		{
		case 0:
			dayis1(stu_id);
			break;
		case 1:
			daers1(stu_id);
			break;
		case 2:
			dasans1(stu_id);
			break;
		case 3:
			dasis1(stu_id);
			break;
		}
	}
	else
	{
		switch (z)
		{
		case 1:
			dayix1(stu_id);
			break;
		case 2:
			daerx1(stu_id);
			break;
		case 3:
			dasanx1(stu_id);
			break;
		case 4:
			dasix1(stu_id);
			break;
		}
	}
	system("pause");
	system("cls");
	home();
}
void dayis1(char a[])
{
	FILE *fp;
	fp = fopen("大一上学生选课.txt", "r");
	if (fp == NULL)
	{
		printf("\n您还未选课，请先选课\n");
	}
	else
	{
		int i = 0, n, j = 0;
		while (fscanf(fp, "%s", stu[i].stu_ID) != EOF)
		{
			for (j = 0; j < 3; j++)
				fscanf(fp, "%s %s", stu[i].xuan1[j].course_id, stu[i].xuan1[j].course_name);
			i++;
		}
		n = i;
		for (i = 0; i < n; i++)
		{
			printf("%s\n ", stu[i].stu_ID);
			for (j = 0; j < 3; j++)
				printf("%s %s\n", stu[i].xuan1[j].course_id, stu[i].xuan1[j].course_name);
		}
		system("pause");
	}
}
void dayix1(char a[])
{
	FILE *fp;
	fp = fopen("大一下学生选课.txt", "r");
	if (fp == NULL)
	{
		printf("\n您还未选课，请先选课\n");
	}
	else
	{
		int i = 0, n, j = 0;
		while (fscanf(fp, "%s", stu[i].stu_ID) != EOF)
		{
			for (j = 0; j < 3; j++)
				fscanf(fp, "%s %s", stu[i].xuan1[j].course_id, stu[i].xuan1[j].course_name);
			i++;
		}
		n = i;
		for (i = 0; i < n; i++)
		{
			printf("%s\n ", stu[i].stu_ID);
			for (j = 0; j < 3; j++)
				printf("%s %s\n", stu[i].xuan1[j].course_id, stu[i].xuan1[j].course_name);
		}
	}
	system("pause");
}
void daers1(char a[])
{
	FILE *fp;
	fp = fopen("大二上学生选课.txt", "r");
	if (fp == NULL)
	{
		printf("\n您还未选课，请先选课\n");
	}
	else
	{
		int i = 0, n, j = 0;
		while (fscanf(fp, "%s", stu[i].stu_ID) != EOF)
		{
			for (j = 0; j < 3; j++)
				fscanf(fp, "%s %s", stu[i].xuan1[j].course_id, stu[i].xuan1[j].course_name);
			i++;
		}
		n = i;
		for (i = 0; i < n; i++)
		{
			printf("%s \n", stu[i].stu_ID);
			for (j = 0; j < 3; j++)
				printf("%s %s\n", stu[i].xuan1[j].course_id, stu[i].xuan1[j].course_name);
		}
		system("pause");
	}
}
void daerx1(char a[])
{
	FILE *fp;
	fp = fopen("大二下学生选课.txt", "r");
	if (fp == NULL)
	{
		printf("您还未选课，请先选课");
		home();
	}
	else
	{
		int i = 0, n, j = 0;
		while (fscanf(fp, "%s", stu[i].stu_ID) != EOF)
		{
			for (j = 0; j < 3; j++)
				fscanf(fp, "%s %s", stu[i].xuan1[j].course_id, stu[i].xuan1[j].course_name);
			i++;
		}
		n = i;
		for (i = 0; i < n; i++)
		{
			printf("%s\n ", stu[i].stu_ID);
			for (j = 0; j < 3; j++)
				printf("%s %s\n", stu[i].xuan1[j].course_id, stu[i].xuan1[j].course_name);
		}
		system("pause");
	}
}
void dasans1(char a[])
{
	FILE *fp;
	fp = fopen("大三上学生选课.txt", "r");
	if (fp == NULL)
	{
		printf("\n您还未选课，请先选课\n");
	}
	else
	{
		int i = 0, n, j = 0;
		while (fscanf(fp, "%s", stu[i].stu_ID) != EOF)
		{
			for (j = 0; j < 3; j++)
				fscanf(fp, "%s %s", stu[i].xuan1[j].course_id, stu[i].xuan1[j].course_name);
			i++;
		}
		n = i;
		for (i = 0; i < n; i++)
		{
			printf("%s \n", stu[i].stu_ID);
			for (j = 0; j < 3; j++)
				printf("%s %s\n", stu[i].xuan1[j].course_id, stu[i].xuan1[j].course_name);
		}
		system("pause");
	}
}
void dasanx1(char a[])
{
	FILE *fp;
	fp = fopen("大三下学生选课.txt", "r");
	if (fp == NULL)
	{
		printf("\n您还未选课，请先选课\n");
	}
	else
	{
		int i = 0, n, j = 0;
		while (fscanf(fp, "%s", stu[i].stu_ID) != EOF)
		{
			for (j = 0; j < 3; j++)
				fscanf(fp, "%s %s", stu[i].xuan1[j].course_id, stu[i].xuan1[j].course_name);
			i++;
		}
		n = i;
		for (i = 0; i < n; i++)
		{
			printf("%s\n ", stu[i].stu_ID);
			for (j = 0; j < 3; j++)
				printf("%s %s\n", stu[i].xuan1[j].course_id, stu[i].xuan1[j].course_name);
		}
		system("pause");
	}
}
void dasis1(char a[])
{
	FILE *fp;
	fp = fopen("大四上学生选课.txt", "r");
	if (fp == NULL)
	{
		printf("\n您还未选课，请先选课\n");
	}
	else
	{
		int i = 0, n, j = 0;
		while (fscanf(fp, "%s", stu[i].stu_ID) != EOF)
		{
			for (j = 0; j < 3; j++)
				fscanf(fp, "%s %s", stu[i].xuan1[j].course_id, stu[i].xuan1[j].course_name);
			i++;
		}
		n = i;
		for (i = 0; i < n; i++)
		{
			printf("%s\n ", stu[i].stu_ID);
			for (j = 0; j < 3; j++)
				printf("%s %s\n", stu[i].xuan1[j].course_id, stu[i].xuan1[j].course_name);
		}
		system("pause");
	}
}
void dasix1(char a[])
{
	FILE *fp;
	fp = fopen("大四下学生选课.txt", "r");
	if (fp == NULL)
	{
		printf("\n您还未选课，请先选课\n");
	}
	else
	{
		int i = 0, n, j = 0;
		while (fscanf(fp, "%s", stu[i].stu_ID) != EOF)
		{
			for (j = 0; j < 3; j++)
				fscanf(fp, "%s %s", stu[i].xuan1[j].course_id, stu[i].xuan1[j].course_name);
			i++;
		}
		n = i;
		for (i = 0; i < n; i++)
		{
			printf("%s\n ", stu[i].stu_ID);
			for (j = 0; j < 3; j++)
				printf("%s %s\n", stu[i].xuan1[j].course_id, stu[i].xuan1[j].course_name);
		}
		system("pause");
	}
}
