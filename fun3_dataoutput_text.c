//�ļ�����fun3_dataoutput_text.c
//ģ�飺fun3_dataoutput_text
//˵���������ı��ļ���ʽ���
//���⣺
//��һ���޸ģ�2013-11-24 18:29:25

#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

//void fun3_dataoutput_text(void); ��data_rinse�ļ������Զ��庯��
void fun3_dataoutput_null_out_text(int null_or_notnull);

void fun3_dataoutput_null_out_text(int null_or_notnull)//null_or_notnull Ϊ1���������ļ��洢 Ϊ2���ǿ������ļ��洢
{
	FILE *fp_output_txt = NULL;
	int i = 0;

	printf("�ļ��洢��ʼ�����ݽ��洢��D�̸�Ŀ¼�µ��ļ�'data_rinse_log.txt'��\n");
	system("pause");
	/*�ⲿ�ļ��򿪻򴴽� ��ʼ*/
	if ((fp_output_txt = fopen("d:\\data_rinse_log.txt", "at+")) == NULL)
	{
		printf("�޷����ļ����밴������˳�!\n");
		system("pause");
		exit(1);		
	}
	/*�ⲿ�ļ��򿪻򴴽� ����*/

	switch(null_or_notnull)
	{
		case 1://null
			{
				printf("�����ݴ洢��ʼ��\n�����ݴ洢���ԡ�\n");
				system("pause");
				printf(" No.\trecord_time\tprice\tsignal_volume\tclosing_time\ttotal_time\tave_price\tflag\n");
				for (i=0; dataprocess_null_problem_data[i].record_time != 0; i++)
				{
					fprintf(fp_output_txt, "%I64d%0.2lf%d%I64d%d%0.8lf%s", dataprocess_null_problem_data[i].record_time, dataprocess_null_problem_data[i].price, dataprocess_null_problem_data[i].signal_volume, dataprocess_null_problem_data[i].closing_time, dataprocess_null_problem_data[i].total_volume, dataprocess_null_problem_data[i].ave_price, dataprocess_null_problem_data[i].flag);

					printf("��%d��\t", (i+1));
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
				printf("�ǿ����ݴ洢��ʼ��\n�ǿ����ݴ洢���ԡ�\n");
				system("pause");
				printf(" No.\trecord_time\tprice\tsignal_volume\tclosing_time\ttotal_time\tave_price\tflag\n");
				for (i=0; dataprocess_null_result_data[i].record_time != 0; i++)
				{
					fprintf(fp_output_txt, "%I64d\t%0.2lf\t%d\t%I64d\t%d\t%0.8lf\t%s\n", dataprocess_null_problem_data[i].record_time, dataprocess_null_problem_data[i].price, dataprocess_null_problem_data[i].signal_volume, dataprocess_null_problem_data[i].closing_time, dataprocess_null_problem_data[i].total_volume, dataprocess_null_problem_data[i].ave_price, dataprocess_null_problem_data[i].flag);

					printf("��%d��\t", (i+1));
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
				printf("�������ѡ��ʧ�ܡ������ԡ�\n");
				system("pause");
				return;
				break;
			}
	}
	printf("�ļ��洢��ɡ��洢�����鿴D�̸�Ŀ¼�µ��ı��ļ�'data_rinse_log.txt'��\n");
	system("pause");
}

void fun3_dataoutput_text(void)
{
	int function3_dataoutput_text_choice = 0;
	char function3_dataoutput_pre_text_choice = '0';
	
	printf("========================================����������ϴϵͳ================================\n");
	printf("�������ѡ����ѡ���ı��������ϴ���                                                  \n");
	printf("                                                                                        \n");
	printf("                                  [1]���������                                         \n");
	printf("                                  [2]����ǿ�����                                       \n");
	printf("                                  [3]������һ��                                         \n");
	printf("                                                                                        \n");
	printf("==========================================����ѡ�����==================================\n");
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
		case 1://��������ݵ��ı��ļ�
			{
				system("cls");
				fun3_dataoutput_null_out_text(1);
				break;
			}
		case 2://����ǿ����ݵ��ı��ļ�
			{
				system("cls");
				fun3_dataoutput_null_out_text(2);
				break;
			}
		case 3://������һ��[��ʽ���]
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