//�ļ�����fun2_dataprocess_null.c
//ģ�飺fun2_dataprocess_null
//˵�����������޳�������ת����Ľṹ������a���޳����Ϊһ���ṹ������b��û�п�ֵ������ֵ����ṹ������c
//���⣺
//��һ���޸ģ�2013-11-24 12:37:21
#define		STRUCT_ARRAY_NUMBER 			      9784		//��ȡ���ı����ݵ����� ��������ת���洢��� �ṹ������Ԫ�ظ���
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
	int input_style = 0;//1�Ǽ���¼�룬2���ļ����롣��Ϊ��������¼���ʱ���ļ���һ����Ԫ�����ƣ����ԣ���input_style��������ת���������ʹ���

	printf("��ʼ�����ݽ��п�ֵ�޳�������\n");
	printf("��ע:��ֵ����ǰ������Ա(record_time, price, signal_volume, closing_time, total_volume, ave_price)��˵��0(��Ϊ��ǰ�������ַ�������ת���Ĳ���); ���ڵ��߸���Աflag, ��ֵ���ǿո�' '��\n");
	system("pause");

	if (origin_row_data[0].record_time[0] == '1')	//���ڼ�������ṹ�����飬�������ļ��ṹ�����顣�����������ǣ�����ļ��ṹ������û�У�ȡ��ʼ������ֵ��
	{
		process_null_data_number = fun_current_keyboard_max_row_number(1);//����������κ���ֵ�����ԣ������׶δ�������¼�����ݵ���ֵ
		input_style = 1;	//�������ݴ��� ��ʶ
	}
	else if (dataimport_keyboard_data[0].record_time[0] == '1')		//�����ļ��ṹ�����飬�����ڼ��̽ṹ�����顣�����������ǣ�������̽ṹ������û�У�ȡ��ʼ������ֵ��
	{
		process_null_data_number = fun_current_doc_max_row_number() - 1;
		input_style = 2;	//�ļ����ݴ��� ��ʶ
	}
	else
	{
		printf("��ֵ�޳�����ʧ�ܡ�ʶ�����ļ����ݻ����¼������ʧ�ܣ��޷����п�ֵ���ݵ��޳�������\n");
		system("pause");
		return;
	}

	/*��ֵ�޳����� ��ʼ*/
	switch(input_style)
	{
		case 1://�������ݿ�ֵ�޳�
			{
				for (i=0, j=0, k=0; i<process_null_data_number; i++)//j:�գ��ṹ�����飩�����±� k:�ǿգ��ṹ�����飩�����±�
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
		case 2://�ļ����ݿ�ֵ�޳�
			{
				for (i=0, j=0, k=0; i<process_null_data_number; i++)//j:�գ��ṹ�����飩�����±� k:�ǿգ��ṹ�����飩�����±�
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
				printf("��ֵ�޳�����ʧ�ܡ�ʶ�����ļ����ݻ����¼������ʧ�ܣ��޷����п�ֵ���ݵ��޳�������\n");
				system("pause");
				return;
				break;
			}
	}
	/*��ֵ�޳����� ����*/

	/*��ֵ�޳��������	��ֵ�ṹ������	����	��ʼ*/
	printf("��ʼ���Կ�ֵ���ݼ�¼:\n");
	system("pause");

	printf(" No.\trecord_time\tprice\tsignal_volume\tclosing_time\ttotal_time\tave_price\tflag\n");
	for (i=0; i<null_data_number; i++)
	{
		printf("��%d��\t", (i+1));
		printf(".%I64d.\t", dataprocess_null_problem_data[i].record_time);
		printf(".%0.2lf.\t", dataprocess_null_problem_data[i].price);
		printf(".%d.\t", dataprocess_null_problem_data[i].signal_volume);
		printf(".%I64d.\t", dataprocess_null_problem_data[i].closing_time);
		printf(".%d.\t", dataprocess_null_problem_data[i].total_volume);
		printf(".%0.8lf.\t", dataprocess_null_problem_data[i].ave_price);
		printf(".%s.\n", dataprocess_null_problem_data[i].flag);
	}
	/*��ֵ�޳��������	��ֵ�ṹ������	����	����*/

	/*��ֵ�޳�������� �����ֵ���� ��ʼ*/
	printf("ͳ�ƿ�ֵ�޳���������ֵ�������:\n");
	printf("��ֵ��¼����:%d\n", null_data_number);
	printf("�ǿ�ֵ��¼����:%d\n", notnull_data_number);
	printf("��¼������:%d\n", (notnull_data_number + null_data_number));
	system("pause");
	/*��ֵ�޳�������� �����ֵ���� ����*/
}
