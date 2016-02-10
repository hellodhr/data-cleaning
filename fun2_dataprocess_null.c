//文件名：fun2_dataprocess_null.c
//模块：fun2_dataprocess_null
//说明：空数据剔除在类型转换后的结构体数组a，剔除结果为一个结构体数组b（没有空值），空值存入结构体数组c
//问题：
//上一次修改：2013-11-24 12:37:21
#define		STRUCT_ARRAY_NUMBER 			      9784		//读取的文本数据的行数 数据类型转换存储结果 结构体数组元素个数
#define		CHAR_ELEMENT						  15

#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

	void fun2_dataprocess_null(void);

	struct struct_dataprocess_type_conversion dataprocess_null_result_data[STRUCT_ARRAY_NUMBER];
	struct struct_dataprocess_type_conversion dataprocess_null_problem_data[STRUCT_ARRAY_NUMBER];

void fun2_dataprocess_null(void)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int process_null_data_number = 0;
	int null_data_number = 0;
	int notnull_data_number = 0;
	int input_style = 0;//1是键盘录入，2是文件导入。因为两个数据录入的时候文件第一行是元素名称，所以，用input_style控制类型转换的行数和次数

	printf("开始对数据进行空值剔除操作。\n");
	printf("附注:空值对于前六个成员(record_time, price, signal_volume, closing_time, total_volume, ave_price)来说是0(因为此前经过了字符串类型转换的操作); 对于第七个成员flag, 空值就是空格' '。\n");
	system("pause");

	if (origin_row_data[0].record_time[0] == '1')	//存在键盘输入结构体数组，不存在文件结构体数组。符合条件就是，这个文件结构体数组没有，取初始化的数值。
	{
		process_null_data_number = fun_current_keyboard_max_row_number(1);//函数里面放任何数值都可以，第三阶段传出键盘录入数据的数值
		input_style = 1;	//键盘数据处理 标识
	}
	else if (dataimport_keyboard_data[0].record_time[0] == '1')		//存在文件结构体数组，不存在键盘结构体数组。符合条件就是，这个键盘结构体数组没有，取初始化的数值。
	{
		process_null_data_number = fun_current_doc_max_row_number() - 1;
		input_style = 2;	//文件数据处理 标识
	}
	else
	{
		printf("空值剔除操作失败。识别导入文件数据或键盘录入数据失败，无法进行空值数据的剔除操作。\n");
		system("pause");
		return;
	}

	/*空值剔除操作 开始*/
	switch(input_style)
	{
		case 1://键盘数据空值剔除
			{
				for (i=0, j=0, k=0; i<process_null_data_number; i++)//j:空（结构体数组）数据下标 k:非空（结构体数组）数据下标
				{
					if ((dataprocess_type_conversion_data[i].record_time == 0) || (dataprocess_type_conversion_data[i].price == 0) || (dataprocess_type_conversion_data[i].signal_volume == 0) || (dataprocess_type_conversion_data[i].closing_time == 0) || (dataprocess_type_conversion_data[i].total_volume == 0) || (dataprocess_type_conversion_data[i].ave_price == 0) || (dataprocess_type_conversion_data[i].flag[0] == ' '))
					{
						dataprocess_null_problem_data[j].record_time = dataprocess_type_conversion_data[i].record_time;
						dataprocess_null_problem_data[j].price = dataprocess_type_conversion_data[i].price;
						dataprocess_null_problem_data[j].signal_volume = dataprocess_type_conversion_data[i].signal_volume;
						dataprocess_null_problem_data[j].closing_time = dataprocess_type_conversion_data[i].closing_time;
						dataprocess_null_problem_data[j].total_volume = dataprocess_type_conversion_data[i].total_volume;
						dataprocess_null_problem_data[j].ave_price = dataprocess_type_conversion_data[i].ave_price;
						strcpy(dataprocess_null_problem_data[j].flag, dataprocess_type_conversion_data[i].flag);

						j++;
					}
					else
					{
						dataprocess_null_result_data[k].record_time = dataprocess_type_conversion_data[i].record_time;
						dataprocess_null_result_data[k].price = dataprocess_type_conversion_data[i].price;
						dataprocess_null_result_data[k].signal_volume = dataprocess_type_conversion_data[i].signal_volume;
						dataprocess_null_result_data[k].closing_time = dataprocess_type_conversion_data[i].closing_time;
						dataprocess_null_result_data[k].total_volume = dataprocess_type_conversion_data[i].total_volume;
						dataprocess_null_result_data[k].ave_price = dataprocess_type_conversion_data[i].ave_price;
						strcpy(dataprocess_null_result_data[k].flag, dataprocess_type_conversion_data[i].flag);

						k++;
					}
					null_data_number = j;
					notnull_data_number = k;
				}
				break;
			}
		case 2://文件数据空值剔除
			{
				for (i=0, j=0, k=0; i<process_null_data_number; i++)//j:空（结构体数组）数据下标 k:非空（结构体数组）数据下标
				{
					if ((dataprocess_type_conversion_data[i].record_time == 0) || (dataprocess_type_conversion_data[i].price == 0) || (dataprocess_type_conversion_data[i].signal_volume == 0) || (dataprocess_type_conversion_data[i].closing_time == 0) || (dataprocess_type_conversion_data[i].total_volume == 0) || (dataprocess_type_conversion_data[i].ave_price == 0) || (dataprocess_type_conversion_data[i].flag[0] == ' '))
					{
						dataprocess_null_problem_data[j].record_time = dataprocess_type_conversion_data[i].record_time;
						dataprocess_null_problem_data[j].price = dataprocess_type_conversion_data[i].price;
						dataprocess_null_problem_data[j].signal_volume = dataprocess_type_conversion_data[i].signal_volume;
						dataprocess_null_problem_data[j].closing_time = dataprocess_type_conversion_data[i].closing_time;
						dataprocess_null_problem_data[j].total_volume = dataprocess_type_conversion_data[i].total_volume;
						dataprocess_null_problem_data[j].ave_price = dataprocess_type_conversion_data[i].ave_price;
						strcpy(dataprocess_null_problem_data[j].flag, dataprocess_type_conversion_data[i].flag);

						j++;
					}
					else
					{
						dataprocess_null_result_data[k].record_time = dataprocess_type_conversion_data[i].record_time;
						dataprocess_null_result_data[k].price = dataprocess_type_conversion_data[i].price;
						dataprocess_null_result_data[k].signal_volume = dataprocess_type_conversion_data[i].signal_volume;
						dataprocess_null_result_data[k].closing_time = dataprocess_type_conversion_data[i].closing_time;
						dataprocess_null_result_data[k].total_volume = dataprocess_type_conversion_data[i].total_volume;
						dataprocess_null_result_data[k].ave_price = dataprocess_type_conversion_data[i].ave_price;
						strcpy(dataprocess_null_result_data[k].flag, dataprocess_type_conversion_data[i].flag);

						k++;
					}
				}
					null_data_number = j;
					notnull_data_number = k;
				break;
			}
		default:
			{
				printf("空值剔除操作失败。识别导入文件数据或键盘录入数据失败，无法进行空值数据的剔除操作。\n");
				system("pause");
				return;
				break;
			}
	}
	/*空值剔除操作 结束*/

	/*空值剔除操作结果	空值结构体数组	回显	开始*/
	printf("开始回显空值数据记录:\n");
	system("pause");

	printf(" No.\trecord_time\tprice\tsignal_volume\tclosing_time\ttotal_time\tave_price\tflag\n");
	for (i=0; i<null_data_number; i++)
	{
		printf("【%d】\t", (i+1));
		printf(".%I64d.\t", dataprocess_null_problem_data[i].record_time);
		printf(".%0.2lf.\t", dataprocess_null_problem_data[i].price);
		printf(".%d.\t", dataprocess_null_problem_data[i].signal_volume);
		printf(".%I64d.\t", dataprocess_null_problem_data[i].closing_time);
		printf(".%d.\t", dataprocess_null_problem_data[i].total_volume);
		printf(".%0.8lf.\t", dataprocess_null_problem_data[i].ave_price);
		printf(".%s.\n", dataprocess_null_problem_data[i].flag);
	}
	/*空值剔除操作结果	空值结构体数组	回显	结束*/

	/*空值剔除操作结果 结果数值分析 开始*/
	printf("统计空值剔除操作的数值结果如下:\n");
	printf("空值记录条数:%d\n", null_data_number);
	printf("非空值记录条数:%d\n", notnull_data_number);
	printf("记录总条数:%d\n", (notnull_data_number + null_data_number));
	system("pause");
	/*空值剔除操作结果 结果数值分析 结束*/
}
