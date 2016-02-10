//文件名：fun3_dataoutput_text.c
//模块：fun3_dataoutput_text
//说明：数据文本文件形式输出
//问题：
//上一次修改：2013-11-24 18:29:25

#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

//void fun3_dataoutput_text(void); 让data_rinse文件声明自定义函数
void fun3_dataoutput_null_out_text(int null_or_notnull);

void fun3_dataoutput_null_out_text(int null_or_notnull)//null_or_notnull 为1：空数据文件存储 为2：非空数据文件存储
{
	FILE *fp_output_txt = NULL;
	int i = 0;

	printf("文件存储开始。数据将存储到D盘根目录下的文件'data_rinse_log.txt'。\n");
	system("pause");
	/*外部文件打开或创建 开始*/
	if ((fp_output_txt = fopen("d:\\data_rinse_log.txt", "at+")) == NULL)
	{
		printf("无法打开文件，请按任意键退出!\n");
		system("pause");
		exit(1);		
	}
	/*外部文件打开或创建 结束*/

	switch(null_or_notnull)
	{
		case 1://null
			{
				printf("空数据存储开始。\n空数据存储回显。\n");
				system("pause");
				printf(" No.\trecord_time\tprice\tsignal_volume\tclosing_time\ttotal_time\tave_price\tflag\n");
				for (i=0; dataprocess_null_problem_data[i].record_time != 0; i++)
				{
					fprintf(fp_output_txt, "%I64d%0.2lf%d%I64d%d%0.8lf%s", dataprocess_null_problem_data[i].record_time, dataprocess_null_problem_data[i].price, dataprocess_null_problem_data[i].signal_volume, dataprocess_null_problem_data[i].closing_time, dataprocess_null_problem_data[i].total_volume, dataprocess_null_problem_data[i].ave_price, dataprocess_null_problem_data[i].flag);

					printf("【%d】\t", (i+1));
					printf(".%I64d.\t", dataprocess_null_problem_data[i].record_time);
					printf(".%0.2lf.\t", dataprocess_null_problem_data[i].price);
					printf(".%d.\t\t", dataprocess_null_problem_data[i].signal_volume);
					printf(".%I64d.\t", dataprocess_null_problem_data[i].closing_time);
					printf(".%d.\t\t", dataprocess_null_problem_data[i].total_volume);
					printf(".%0.8lf.\t", dataprocess_null_problem_data[i].ave_price);
					printf(".%s.\n", dataprocess_null_problem_data[i].flag);
				}
				break;
			}
		case 2://notnull
			{
				printf("非空数据存储开始。\n非空数据存储回显。\n");
				system("pause");
				printf(" No.\trecord_time\tprice\tsignal_volume\tclosing_time\ttotal_time\tave_price\tflag\n");
				for (i=0; dataprocess_null_result_data[i].record_time != 0; i++)
				{
					fprintf(fp_output_txt, "%I64d\t%0.2lf\t%d\t%I64d\t%d\t%0.8lf\t%s\n", dataprocess_null_problem_data[i].record_time, dataprocess_null_problem_data[i].price, dataprocess_null_problem_data[i].signal_volume, dataprocess_null_problem_data[i].closing_time, dataprocess_null_problem_data[i].total_volume, dataprocess_null_problem_data[i].ave_price, dataprocess_null_problem_data[i].flag);

					printf("【%d】\t", (i+1));
					printf(".%I64d.\t", dataprocess_null_result_data[i].record_time);
					printf(".%0.2lf.\t", dataprocess_null_result_data[i].price);
					printf(".%d.\t\t", dataprocess_null_result_data[i].signal_volume);
					printf(".%I64d.\t", dataprocess_null_result_data[i].closing_time);
					printf(".%d.\t\t", dataprocess_null_result_data[i].total_volume);
					printf(".%0.8lf.\t", dataprocess_null_result_data[i].ave_price);
					printf(".%s.\n", dataprocess_null_result_data[i].flag);
				}
				break;
			}
		default:
			{
				printf("输出内容选择失败。请重试。\n");
				system("pause");
				return;
				break;
			}
	}
	printf("文件存储完成。存储结果请查看D盘根目录下的文本文件'data_rinse_log.txt'。\n");
	system("pause");
}

void fun3_dataoutput_text(void)
{
	int function3_dataoutput_text_choice = 0;
	char function3_dataoutput_pre_text_choice = '0';
	
	printf("========================================智能数据清洗系统================================\n");
	printf("请从下列选项中选择【文本输出】清洗结果                                                  \n");
	printf("                                                                                        \n");
	printf("                                  [1]输出空数据                                         \n");
	printf("                                  [2]输出非空数据                                       \n");
	printf("                                  [3]返回上一层                                         \n");
	printf("                                                                                        \n");
	printf("==========================================请您选择序号==================================\n");
	scanf("%c",&function3_dataoutput_pre_text_choice);

	if (function3_dataoutput_pre_text_choice == '1')
		function3_dataoutput_text_choice = 1;
	else
	{
		if (function3_dataoutput_pre_text_choice == '2')
			function3_dataoutput_text_choice = 2;
		else
		{
			if (function3_dataoutput_pre_text_choice == '3')
				function3_dataoutput_text_choice = 3;
			else
				function3_dataoutput_text_choice = 0;
		}
	}

	switch(function3_dataoutput_text_choice)
	{
		case 1://输出空数据到文本文件
			{
				system("cls");
				fun3_dataoutput_null_out_text(1);
				break;
			}
		case 2://输出非空数据到文本文件
			{
				system("cls");
				fun3_dataoutput_null_out_text(2);
				break;
			}
		case 3://返回上一层[格式输出]
			{
				system("cls");
				function3_dataoutput();
				break;
			}
		default:
			{
				system("cls");
				fun3_dataoutput_text();
				break;
			}
	}
}