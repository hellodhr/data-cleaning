//�ļ�����fun1_dataimport_keyboard_module.c
//ģ�飺fun1_dataimport_keyboard_module

//˵���������������ݵ��뵽�ṹ������
//���⣺
//��һ���޸ģ�2013-11-23 20:21:16

#define 	DATAIMPORT_KEYBOARD_NUMBER 		      500		//��ȡ���ı����ݵ�����
															//*******���궨����ֵΪ
															//*******���궨����ֵΪ
#define		CHAR_ELEMENT 				      15		//�ṹ��struct_origin_row_data����origin_row_data��[ÿ��Ԫ��]���������ֽ���
#define		FACTOR_NUMBER					  7			//ÿ����¼�����Ը���

#include	<stdio.h>
#include	<stdlib.h>
#include	<windows.h>
#include	<stdio.h>

void fun1_dataimport_keyboard_module(void);
	int fun_current_keyboard_max_row_number(int current_keyboard_max_row_number);

	/*�ṹ��������� ���� ��ʼ*/
	struct struct_dataimport_keyboard_data        //�нṹ���¼
	{
		char				record_time[CHAR_ELEMENT];	
		char				price[CHAR_ELEMENT];
		char				signal_volume[CHAR_ELEMENT];
		char				closing_time[CHAR_ELEMENT];
		char				total_volume[CHAR_ELEMENT];
		char				ave_price[CHAR_ELEMENT];
		char				flag[CHAR_ELEMENT];
	};
	/*�ṹ��������� ���� ����*/

	/*�������� �����������ݽṹ������ ��ʼ*/
	struct struct_dataimport_keyboard_data dataimport_keyboard_data[DATAIMPORT_KEYBOARD_NUMBER] = {"1"};
	struct struct_dataimport_keyboard_data *p_dataimport_keyboard_data = NULL;//*p_origin_row_data = dataimport_keyboard_data;
	/*�������� �����������ݽṹ������ ����*/
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

	fun_current_keyboard_max_row_number(1);//������������

	printf("������ʼ¼�����ݣ�������Ҫͨ������¼�����ݵ�����:");
	scanf("%d", &dataimport_keyboard_number);

	if (dataimport_keyboard_number > DATAIMPORT_KEYBOARD_NUMBER)
	{
		printf("¼��������������һ�μ���¼���������������ֵ���������Ŀ�����ԡ�\n");
		system("pause");
		fun1_dataimport_keyboard_module();
	}
	else if (dataimport_keyboard_number <= 0)
	{
		printf("¼������Ϊ������������һ��������������������\n");
		system("pause");
		fun1_dataimport_keyboard_module();
	}
	else if ((dataimport_keyboard_number > 0) && (dataimport_keyboard_number <= DATAIMPORT_KEYBOARD_NUMBER ))
	{
		fun_current_keyboard_max_row_number(dataimport_keyboard_number);

		printf("����¼�뼴����ʼ......\n");	
		system("pause");
		system("cls");
		printf("�������ʾ������¼��%d�����ݡ�\n", dataimport_keyboard_number);

		for (i=0; i<dataimport_keyboard_number; i++)
		{
			printf("������ڡ�%d�������ݵ���ֵ\n", (i+1));
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
			//printf("Flag��ֵ����������:\n'1'����'ture','0'����'false'��\n");
			//printf("����������:");
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
					printf("�����������������:");
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

	/*¼������ �������Ļ��	��ʼ*/
	printf("�Ѿ���ɴӼ��̵��ṹ������Ĵ洢��׼����ʼ���洢����������Ļ�ϡ�\n");
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
	/*��¼����ṹ�������е����� �������Ļ��	����*/
	printf("\n����װ����ϡ��ܼƼ�����������%d����\n", i);
}