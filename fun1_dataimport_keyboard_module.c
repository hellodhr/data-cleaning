//文件名：fun1_dataimport_keyboard_module.c
//模块：fun1_dataimport_keyboard_module

//说明：键盘输入数据导入到结构体数组
//问题：
//上一次修改：2013-11-23 20:21:16

#define 	DATAIMPORT_KEYBOARD_NUMBER 		      500		//读取的文本数据的行数
															//*******最大宏定义数值为
															//*******最大宏定义数值为
#define		CHAR_ELEMENT 				      15		//结构体struct_origin_row_data数组origin_row_data的[每个元素]所包含的字节数
#define		FACTOR_NUMBER					  7			//每条记录的属性个数

#include	<stdio.h>
#include	<stdlib.h>
#include	<windows.h>
#include	<stdio.h>

void fun1_dataimport_keyboard_module(void);
	int fun_current_keyboard_max_row_number(int current_keyboard_max_row_number);

	/*结构体数组变量 声明 开始*/
	struct struct_dataimport_keyboard_data        //行结构体记录
	{
		char				record_time[CHAR_ELEMENT];	
		char				price[CHAR_ELEMENT];
		char				signal_volume[CHAR_ELEMENT];
		char				closing_time[CHAR_ELEMENT];
		char				total_volume[CHAR_ELEMENT];
		char				ave_price[CHAR_ELEMENT];
		char				flag[CHAR_ELEMENT];
	};
	/*结构体数组变量 声明 结束*/

	/*声明变量 键盘输入数据结构体数组 开始*/
	struct struct_dataimport_keyboard_data dataimport_keyboard_data[DATAIMPORT_KEYBOARD_NUMBER] = {"1"};
	struct struct_dataimport_keyboard_data *p_dataimport_keyboard_data = NULL;//*p_origin_row_data = dataimport_keyboard_data;
	/*声明变量 键盘输入数据结构体数组 结束*/
/*
int main(void)
{
	fun1_dataimport_keyboard_module();
}
*/
int fun_current_keyboard_max_row_number(int current_keyboard_max_row_number)
{
	static int stage1 = 0, stage2 = 0, stage3 = 0;

	if ((current_keyboard_max_row_number == 1) && (stage3 == 0))
		return 0;
	else if ((current_keyboard_max_row_number != 1) && (stage3 == 0))
	{
		stage2 = current_keyboard_max_row_number;
		stage3 = 1;
		return 0;
	}
	else if ((stage2 != 0) && (stage3 == 1))
	{
		return stage2;
	}
	return 0;
}

void fun1_dataimport_keyboard_module(void)
{
	int dataimport_keyboard_number = 0;
	int	i = 0;
	char flag_temp[] = "None";

	fun_current_keyboard_max_row_number(1);//键盘行数开关

	printf("即将开始录入数据，请输入要通过键盘录入数据的行数:");
	scanf("%d", &dataimport_keyboard_number);

	if (dataimport_keyboard_number > DATAIMPORT_KEYBOARD_NUMBER)
	{
		printf("录入数据条数超过一次键盘录入数据条数的最大值，请减少数目后重试。\n");
		system("pause");
		fun1_dataimport_keyboard_module();
	}
	else if (dataimport_keyboard_number <= 0)
	{
		printf("录入数据为负数，请输入一个正整数的数据条数。\n");
		system("pause");
		fun1_dataimport_keyboard_module();
	}
	else if ((dataimport_keyboard_number > 0) && (dataimport_keyboard_number <= DATAIMPORT_KEYBOARD_NUMBER ))
	{
		fun_current_keyboard_max_row_number(dataimport_keyboard_number);

		printf("数据录入即将开始......\n");	
		system("pause");
		system("cls");
		printf("请根据提示，依次录入%d条数据。\n", dataimport_keyboard_number);

		for (i=0; i<dataimport_keyboard_number; i++)
		{
			printf("请输入第【%d】条数据的数值\n", (i+1));
			printf("1.record_time:");
			scanf("%s", dataimport_keyboard_data[i].record_time);
			printf("\n");	

			printf("2.price:");
			scanf("%s", dataimport_keyboard_data[i].price);
			printf("\n");	

			printf("3.signal_volume:");
			scanf("%s", dataimport_keyboard_data[i].signal_volume);
			printf("\n");

			printf("4.closing_time:");
			scanf("%s", dataimport_keyboard_data[i].closing_time);
			printf("\n");

			printf("5.total_volume:");
			scanf("%s", dataimport_keyboard_data[i].total_volume);
			printf("\n");

			printf("6.ave_price:");
			scanf("%s", dataimport_keyboard_data[i].ave_price);
			printf("\n");

			printf("7.flag:\n");
			//printf("Flag的值请输入数字:\n'1'代表'ture','0'代表'false'。\n");
			//printf("请输入数字:");
			scanf("%s", flag_temp);
			strcpy(dataimport_keyboard_data[i].flag, flag_temp);
			//printf("%d", flag_temp);

/*			if ((flag_temp != 0) || (flag_temp != 1))
				while_flag = 1;
			else 
				while_flag = 0;
			while(while_flag)
			{
				if ((flag_temp != 0) || (flag_temp != 1))
				{
					printf("输入错误，请重新输入:");
					scanf("%d", &flag_temp);
					//printf("%d", flag_temp);
				}
				else
					while_flag = 0;
			}
			if (flag_temp == 1)
			{
				strcpy(dataimport_keyboard_data[i].flag, "true");
				dataimport_keyboard_data[i].flag[5] = '\0';
			}	
			else if (flag_temp == 0)
			{
				strcpy(dataimport_keyboard_data[i].flag, "false");
				dataimport_keyboard_data[i].flag[6] = '\0';
			}
*/
		}
	}

	/*录入数据 输出到屏幕上	开始*/
	printf("已经完成从键盘到结构体数组的存储，准备开始将存储结果输出到屏幕上。\n");
	system("pause");
	printf("NO.\trecord_time\tprice\tsignal_volume\tclosing_time\ttotal_volume\tave_price\tflag\n");
	for (i=0; i<dataimport_keyboard_number; i++)
	{
		printf("[%d]\t", (i+1));
		printf(".%s.\t", dataimport_keyboard_data[i].record_time);
		printf(".%s.\t", dataimport_keyboard_data[i].price);
		printf(".%s.\t", dataimport_keyboard_data[i].signal_volume);
		printf(".%s.\t", dataimport_keyboard_data[i].closing_time);
		printf(".%s.\t", dataimport_keyboard_data[i].total_volume);
		printf(".%s.\t", dataimport_keyboard_data[i].ave_price);
		printf(".%s.\n", dataimport_keyboard_data[i].flag);		
	}
	/*将录入进结构体数组中的数据 输出到屏幕上	结束*/
	printf("\n数据装载完毕。总计键盘输入数据%d条。\n", i);
}