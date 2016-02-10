//�ļ�����fun2_dataprocess_pre_type_conversion.c
//ģ�飺fun2_dataprocess_pre_type_conversion
//˵��������ת�������ַ���ת�������ͣ������͵�
//���⣺
//
//��һ���޸ģ�2013-11-24 1:40:36
#define		STRUCT_ARRAY_NUMBER 			      9784		//��ȡ���ı����ݵ����� ��������ת���洢��� �ṹ������Ԫ�ظ���
#define		CHAR_ELEMENT	15

#include	<conio.h>
#include	<math.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<windows.h>

__int64 fun2_dataprocess_pre_type_conversion_char2int64(char time_string_value[CHAR_ELEMENT]);
void fun2_dataprocess_pre_type_conversion(void);
	
	struct struct_dataprocess_type_conversion        //�нṹ���¼
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
	int input_style = 0;//1�Ǽ���¼�룬2���ļ����롣��Ϊ��������¼���ʱ���ļ���һ����Ԫ�����ƣ����ԣ���Input_style��������ת���������ʹ���

	printf("\n��ʼ�����ݽ�������ת�����ַ������߾��ȸ���/���͡�\n");

	if (origin_row_data[0].record_time[0] == '1')	//���ڼ�������ṹ�����飬�������ļ��ṹ�����顣�����������ǣ�����ļ��ṹ������û�У�ȡ��ʼ������ֵ��
	{
		type_conversion_data_number = fun_current_keyboard_max_row_number(1);//����������κ���ֵ�����ԣ������׶δ�������¼�����ݵ���ֵ

		input_style = 1;	//�������ݴ��� ��ʶ
		printf("��ʼ�������¼�����ݡ��ļ���������:%d\n", type_conversion_data_number);
		printf("Keyboard--->>>type_conversion_data_number = %d\n", type_conversion_data_number);
	}
	else if (dataimport_keyboard_data[0].record_time[0] == '1')		//�����ļ��ṹ�����飬�����ڼ��̽ṹ�����顣�����������ǣ�������̽ṹ������û�У�ȡ��ʼ������ֵ��
	{
		type_conversion_data_number = fun_current_doc_max_row_number();
		printf("%d", fun_current_doc_max_row_number());

		input_style = 2;	//�ļ����ݴ��� ��ʶ
		printf("��ʼ�����ļ�¼�����ݡ��ļ���������:%d\n", type_conversion_data_number);
		printf("Doc--->>>type_conversion_data_number = %d\n", type_conversion_data_number);
	}
	else
	{
		printf("�����ַ�������ת��ʧ�ܡ�û�е����ļ����ݻ����¼�����ݣ��޷������ַ�������ת����\n");
		system("pause");
		return;
	}

	printf("ת����������������:\n");
	system("pause");
	switch(input_style)
	{
		case 1://����¼������ݴ���ʽ
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
					
					//����¼������ ��Ļ����
					printf(".%d.\t", (i+1));
					printf(".%I64d.\t", dataprocess_type_conversion_data[i].record_time);
					printf(".%0.2lf.\t", dataprocess_type_conversion_data[i].price);
					printf(".%d.\t", dataprocess_type_conversion_data[i].signal_volume);
					printf(".%I64d.\t", dataprocess_type_conversion_data[i].closing_time);
					printf(".%d.\t", dataprocess_type_conversion_data[i].total_volume);
					printf(".%0.8lf.\t", dataprocess_type_conversion_data[i].ave_price);
					printf(".%s.\n", dataprocess_type_conversion_data[i].flag);
				}
				printf("\n��������ת����ɡ�\n");
				break;
			}
		case 2://�ļ�¼������ݴ���ʽ
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

					//�ļ�¼������ ��Ļ����
					printf("��%d��\t", (i+1));
					printf(".%I64d.\t", dataprocess_type_conversion_data[i].record_time);
					printf(".%0.2lf.\t", dataprocess_type_conversion_data[i].price);
					printf(".%d.\t\t", dataprocess_type_conversion_data[i].signal_volume);
					printf(".%I64d.\t", dataprocess_type_conversion_data[i].closing_time);
					printf(".%d.\t\t", dataprocess_type_conversion_data[i].total_volume);
					printf(".%0.8lf.\t", dataprocess_type_conversion_data[i].ave_price);
					printf(".%s.\n", dataprocess_type_conversion_data[i].flag);
				}
				printf("\n��������ת����ɡ�\n");
				break;
			}
		default:
			{
				printf("����ת��û�в�������û���ļ��ͼ��̶������ݡ�\n");
				break;
			}
	}
	printf("�뷵�������棬���ڿɽ���[2]���ݴ���\n");
	system("pause");
}