//文件名：fun2_dataprocess_pre_type_conversion.c
//模块：fun2_dataprocess_pre_type_conversion
//说明：类型转换，将字符串转换成整型，浮点型等
//问题：
//
//上一次修改：2013-11-24 1:40:36
#define		STRUCT_ARRAY_NUMBER 			      9784		//读取的文本数据的行数 数据类型转换存储结果 结构体数组元素个数
#define		CHAR_ELEMENT	15

#include	<conio.h>
#include	<math.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<windows.h>

__int64 fun2_dataprocess_pre_type_conversion_char2int64(char time_string_value[CHAR_ELEMENT]);
void fun2_dataprocess_pre_type_conversion(void);
	
	struct struct_dataprocess_type_conversion        //行结构体记录
	{
		__int64				record_time;	
		double				price;
		long				signal_volume;
		__int64				closing_time;
		long				total_volume;
		double				ave_price;
		char				flag[CHAR_ELEMENT];
	};
	struct struct_dataprocess_type_conversion dataprocess_type_conversion_data[STRUCT_ARRAY_NUMBER];

__int64 fun2_dataprocess_pre_type_conversion_char2int64(char time_string_value[CHAR_ELEMENT])
{
	char		 p1[15]="\0";
	char		 p2[15]="\0";
	char		 char_temp = '0';

	__int64		 p1_number = 0;
	__int64		 p2_number = 0;
	__int64		 i = 0;
	__int64		 time_int_value = 0;
	__int64		 p1_int_value = 0;
	__int64		 p2_int_value = 0;
		
	p1_number = (strlen(time_string_value))/2;
	strcpy(p2, (time_string_value + p1_number));
	time_string_value[p1_number] = '\0';
	strcpy(p1, time_string_value);
	time_int_value = (__int64)(atol(p2) + atol(p1) * pow(10, strlen(p2)));

	return time_int_value;
}

void fun2_dataprocess_pre_type_conversion(void)
{
	int i = 0;
	int j = 0;
	int type_conversion_data_number = 0;
	int input_style = 0;//1是键盘录入，2是文件导入。因为两个数据录入的时候文件第一行是元素名称，所以，用Input_style控制类型转换的行数和次数

	printf("\n开始对数据进行类型转换。字符串到高精度浮点/整型。\n");

	if (origin_row_data[0].record_time[0] == '1')	//存在键盘输入结构体数组，不存在文件结构体数组。符合条件就是，这个文件结构体数组没有，取初始化的数值。
	{
		type_conversion_data_number = fun_current_keyboard_max_row_number(1);//函数里面放任何数值都可以，第三阶段传出键盘录入数据的数值

		input_style = 1;	//键盘数据处理 标识
		printf("开始处理键盘录入数据。文件数据行数:%d\n", type_conversion_data_number);
		printf("Keyboard--->>>type_conversion_data_number = %d\n", type_conversion_data_number);
	}
	else if (dataimport_keyboard_data[0].record_time[0] == '1')		//存在文件结构体数组，不存在键盘结构体数组。符合条件就是，这个键盘结构体数组没有，取初始化的数值。
	{
		type_conversion_data_number = fun_current_doc_max_row_number();
		printf("%d", fun_current_doc_max_row_number());

		input_style = 2;	//文件数据处理 标识
		printf("开始处理文件录入数据。文件数据行数:%d\n", type_conversion_data_number);
		printf("Doc--->>>type_conversion_data_number = %d\n", type_conversion_data_number);
	}
	else
	{
		printf("数据字符串类型转换失败。没有导入文件数据或键盘录入数据，无法进行字符串类型转换。\n");
		system("pause");
		return;
	}

	printf("转换过后数据输出结果:\n");
	system("pause");
	switch(input_style)
	{
		case 1://键盘录入的数据处理方式
			{
				printf(" No.\trecord_time\tprice\tsignal_volume\tclosing_time\ttotal_time\tave_price\tflag\n");
				for (i=0; i<type_conversion_data_number; i++)
				{
					dataprocess_type_conversion_data[i].record_time = fun2_dataprocess_pre_type_conversion_char2int64(dataimport_keyboard_data[i].record_time);
					dataprocess_type_conversion_data[i].price = atof(dataimport_keyboard_data[i].price);
					dataprocess_type_conversion_data[i].signal_volume = atol(dataimport_keyboard_data[i].signal_volume);
					dataprocess_type_conversion_data[i].closing_time = fun2_dataprocess_pre_type_conversion_char2int64(dataimport_keyboard_data[i].closing_time);
					dataprocess_type_conversion_data[i].total_volume = atol(dataimport_keyboard_data[i].total_volume);
					dataprocess_type_conversion_data[i].ave_price = atof(dataimport_keyboard_data[i].ave_price);
					strcpy(dataprocess_type_conversion_data[i].flag, dataimport_keyboard_data[i].flag);
					
					//键盘录入数据 屏幕回显
					printf(".%d.\t", (i+1));
					printf(".%I64d.\t", dataprocess_type_conversion_data[i].record_time);
					printf(".%0.2lf.\t", dataprocess_type_conversion_data[i].price);
					printf(".%d.\t", dataprocess_type_conversion_data[i].signal_volume);
					printf(".%I64d.\t", dataprocess_type_conversion_data[i].closing_time);
					printf(".%d.\t", dataprocess_type_conversion_data[i].total_volume);
					printf(".%0.8lf.\t", dataprocess_type_conversion_data[i].ave_price);
					printf(".%s.\n", dataprocess_type_conversion_data[i].flag);
				}
				printf("\n数据类型转换完成。\n");
				break;
			}
		case 2://文件录入的数据处理方式
			{
				printf(" No.\trecord_time\tprice\tsignal_volume\tclosing_time\ttotal_time\tave_price\tflag\n");
				for (i=0, j=1; j<type_conversion_data_number; i++, j++)
				{
					dataprocess_type_conversion_data[i].record_time = fun2_dataprocess_pre_type_conversion_char2int64(origin_row_data[j].record_time);
					dataprocess_type_conversion_data[i].price = atof(origin_row_data[j].price);
					dataprocess_type_conversion_data[i].signal_volume = atol(origin_row_data[j].signal_volume);
					dataprocess_type_conversion_data[i].closing_time = fun2_dataprocess_pre_type_conversion_char2int64(origin_row_data[j].closing_time);
					dataprocess_type_conversion_data[i].total_volume = atol(origin_row_data[j].total_volume);
					dataprocess_type_conversion_data[i].ave_price = atof(origin_row_data[j].ave_price);
					strcpy(dataprocess_type_conversion_data[i].flag, origin_row_data[j].flag);

					//文件录入数据 屏幕回显
					printf("【%d】\t", (i+1));
					printf(".%I64d.\t", dataprocess_type_conversion_data[i].record_time);
					printf(".%0.2lf.\t", dataprocess_type_conversion_data[i].price);
					printf(".%d.\t\t", dataprocess_type_conversion_data[i].signal_volume);
					printf(".%I64d.\t", dataprocess_type_conversion_data[i].closing_time);
					printf(".%d.\t\t", dataprocess_type_conversion_data[i].total_volume);
					printf(".%0.8lf.\t", dataprocess_type_conversion_data[i].ave_price);
					printf(".%s.\n", dataprocess_type_conversion_data[i].flag);
				}
				printf("\n数据类型转换完成。\n");
				break;
			}
		default:
			{
				printf("数据转换没有操作对象。没有文件和键盘读入数据。\n");
				break;
			}
	}
	printf("请返回主界面，现在可进行[2]数据处理。\n");
	system("pause");
}