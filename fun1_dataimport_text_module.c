//�ļ�����fun1_dataimport_text_module.c
//ģ�飺fun1_dataimport_text_module
//		void fun1_dataimport_text_module(void);
//			int fun_current_doc_max_row_number(void);
//			void fun1_dataimport_text(int current_doc_max_row_number);
//˵��������ָ��·�����������ı��ļ������ݵ��뵽�ṹ������
//���⣺
//----�ٱ���ָ��·�����ļ���
//----���ֶ�ָ������
//----�����д���
//---------���궨����ֵΪ9850������9850�������д����޷�����
//---------���궨����ֵΪ9784������9784�������д��󣬳������н����������д���
//��һ���޸ģ�2013-11-23 20:30:59

#define 	STRUCT_ARRAY_NUMBER 		      9784		//��ȡ���ı����ݵ�����
															//*******���궨����ֵΪ9850������9850�������д����޷�����
															//*******���궨����ֵΪ9784������9784�������д��󣬳������н����������д���
#define		CHAR_ELEMENT 				      15		//�ṹ��struct_origin_row_data����origin_row_data��[ÿ��Ԫ��]���������ֽ���

#include 	<stdio.h>
#include 	<conio.h>
#include 	<string.h>
#include 	<windows.h>

void fun1_dataimport_text_module(void);
	int fun_current_doc_max_row_number(void);
	void fun1_dataimport_text(int current_doc_max_row_number);

	/*�ṹ��������� ���� ��ʼ*/
	struct struct_origin_row_data        //�нṹ���¼
	{
		char				record_time[CHAR_ELEMENT];	
		char				price[CHAR_ELEMENT];
		char				signal_volume[CHAR_ELEMENT];
		char				closing_time[CHAR_ELEMENT];
		char				total_volume[CHAR_ELEMENT];
		char				ave_price[CHAR_ELEMENT];
		char				flag[CHAR_ELEMENT];
	};

	struct struct_origin_row_data origin_row_data[STRUCT_ARRAY_NUMBER] = {"1"};//current_doc_max_row_number
	struct struct_origin_row_data *p_origin_row_data = NULL;//*p_origin_row_data = origin_row_data;
	/*�ṹ��������� ���� ����*/

void fun1_dataimport_text_module(void)
{
	FILE *fp_origindata_txt = NULL;
	fp_origindata_txt = fopen("d:\\data.txt", "rb");   //fopen��һ��C�⺯�������ڴ��ļ�,"r"��ֻ��ģʽ��������ģʽ�£�����ļ����ڣ����ܳɹ���ֻ��ģʽ�򿪣�fopen����һ����0���ļ�������������ļ������ڣ���fopen����NULL��NULL��˼�ǿգ������ÿ���������һ�����ж��ļ��Ƿ����
	printf("�뽫Ҫ��ȡ���ļ�����D�̸�Ŀ¼��������Ϊ'data.txt'��\n");
	system("pause");
	printf("ȷ���Ѿ�����Ϊ'data.txt'���ļ��Ѿ�����D�̸�Ŀ¼��\n");
	system("pause");

    if (fp_origindata_txt != NULL)
		fun1_dataimport_text(fun_current_doc_max_row_number());
    else
	{
		printf("������'d:\\data.txt'�ļ����밴�ղ����������ԡ�\n");
		system("pause");
		system("cls");
		fun1_dataimport_text_module();
	}
	fclose(fp_origindata_txt);  //���ڵĻ���Ҫ�Ȱ�֮ǰ�򿪵��ļ��ص�
}

//ȷ���ⲿ�ļ�������
int fun_current_doc_max_row_number(void)
{
	int current_doc_max_row_number = 0;
	char char_temp = '1';
	FILE *fp_origindata_txt;

	/*ȷ���ļ�����������current_doc_max_row_number	��ʼ*/
		/*�ⲿ�ļ��� ��ʼ*/
	if ((fp_origindata_txt = fopen("d:\\data.txt", "rb")) == NULL)
	{
		printf("�޷����ļ����밴������˳�!\n");
		system("pause");
		exit(1);		
	}
		/*�ⲿ�ļ��� ����*/

	rewind(fp_origindata_txt);//�ļ���ָ���ʼ�����ļ�ͷ
	while((char_temp = fgetc(fp_origindata_txt)) != EOF)
	{
		if(char_temp == '\n')
			current_doc_max_row_number++;
	}
	/*ȷ���ļ�����������current_doc_max_row_number	����*/
	fclose(fp_origindata_txt);

	printf("Ԥ��ȡ���ı��ļ��ܼ�������%d�С�\n������������򽫿�ʼװ�����ݣ�����װ����ɵ����ݻ��Ե���Ļ�ϡ�\n", current_doc_max_row_number);
	system("pause");
	return current_doc_max_row_number;
}

void fun1_dataimport_text(int current_doc_max_row_number)
{
	/*����void fun1_dataimport_text �������� ��ʼ*/
	int i = 0, j = 0;
	char char_temp = '1';
	FILE *fp_origindata_txt;

	//����ѽṹ������������ŵ���������

	printf("��������Ľṹ������ռ��Ѿ�ȫ������ɹ���\n");
	/*��̬����ṹ������ �ڴ��С ��ʼ*/
	/*
	if (!(p_origin_row_data=(struct struct_origin_row_data *)malloc(current_doc_max_row_number*sizeof(struct struct_origin_row_data))))
	{
		printf("Memory is not accessed!\n");
		exit(1);/*�ڴ����ʧ��ʱ�쳣�˳���Ҳ��Ҫstdlib.h
	}
	*/
	//printf("%d", sizeof(struct struct_origin_row_data));
	/*��̬����ṹ������ �ڴ��С ����*/
	/*����void fun1_dataimport_text �������� ����*/

	printf("�����ṹ�������Ѿ���ɣ�׼����ʼ���ļ��е����ݴ洢���ṹ�����顣\n");
	/*�ⲿ�ļ��� ��ʼ*/
	if ((fp_origindata_txt = fopen("d:\\data.txt", "rb")) == NULL)
	{
		printf("�޷����ļ����밴������˳�!\n");
		getch();
		exit(1);		
	}
	/*�ⲿ�ļ��� ����*/

	/*�ļ����뵽�ṹ������	��ʼ*/
	rewind(fp_origindata_txt);//�ļ���ָ�뷵���ļ�ͷ�����ļ�����ȷ��֮���ٴζ��ļ���ָ��ص���ʼλ��
	for (i=0; i<current_doc_max_row_number; i++)
	{
		for (j=0; j<CHAR_ELEMENT; j++)
		{
			char_temp = fgetc(fp_origindata_txt);

			if ((char_temp != 32) && (char_temp != '\n'))
				origin_row_data[i].record_time[j] = char_temp;
			else
			{
				origin_row_data[i].record_time[j] = '\0';
				if (j == 0)
				{
					origin_row_data[i].record_time[j] = char_temp;
				}//�ӵڶ�����ʼ�ǿգ������ַ������ɰ�������
			}
		}


		for (j=0; j<CHAR_ELEMENT; j++)
		{
			char_temp = fgetc(fp_origindata_txt);

			if ((char_temp != 32) && (char_temp != '\n'))
				origin_row_data[i].price[j] = char_temp;
			else
			{
				origin_row_data[i].price[j] = '\0';
				if (j == 0)
				{
					origin_row_data[i].price[j] = char_temp;
				}
			}
		}


		for (j=0; j<CHAR_ELEMENT; j++)
		{
			char_temp = fgetc(fp_origindata_txt);

			if ((char_temp != 32) && (char_temp != '\n'))
				origin_row_data[i].signal_volume[j] = char_temp;
			else
			{
				origin_row_data[i].signal_volume[j] = '\0';
				if (j == 0)
				{
					origin_row_data[i].signal_volume[j] = char_temp;
				}
			}
		}


		for (j=0; j<CHAR_ELEMENT; j++)
		{
			char_temp = fgetc(fp_origindata_txt);

			if ((char_temp != 32) && (char_temp != '\n'))
				origin_row_data[i].closing_time[j] = char_temp;
			else
			{
				origin_row_data[i].closing_time[j] = '\0';
				if (j == 0)
				{
					origin_row_data[i].closing_time[j] = char_temp;
				}
			}
		}


		for (j=0; j<CHAR_ELEMENT; j++)
		{
			char_temp = fgetc(fp_origindata_txt);

			if ((char_temp != 32) && (char_temp != '\n'))
				origin_row_data[i].total_volume[j] = char_temp;
			else
			{
				origin_row_data[i].total_volume[j] = '\0';
				if (j == 0)
				{
					origin_row_data[i].total_volume[j] = char_temp;
				}
			}
		}


		for (j=0; j<CHAR_ELEMENT; j++)
		{
			char_temp = fgetc(fp_origindata_txt);

			if ((char_temp != 32) && (char_temp != '\n'))
				origin_row_data[i].ave_price[j] = char_temp;
			else
			{
				origin_row_data[i].ave_price[j] = '\0';
				if (j == 0)
				{
					origin_row_data[i].ave_price[j] = char_temp;
				}
			}
		}

		/*����ṹ�������7����Աorigin_row_data[i].flag ��ʼ*/
		char_temp = fgetc(fp_origindata_txt);
		if (char_temp == 32)
		{
			origin_row_data[i].flag[0] = char_temp;
			origin_row_data[i].flag[1] = '\0';
		}
		else
		{
			j = 0;
			while(char_temp != 32)
			{
				origin_row_data[i].flag[j] = char_temp;
				j++;
				char_temp = fgetc(fp_origindata_txt);
			}
			origin_row_data[i].flag[j] = '\0';
		}
		/*����ṹ�������7����Աorigin_row_data[i].flag ����*/

		char_temp = fgetc(fp_origindata_txt);
		while(char_temp != '\n')
		{
			char_temp = fgetc(fp_origindata_txt);
		}
	}					
	/*�ļ����뵽�ṹ������	����*/

	
	/*¼������ �������Ļ��	��ʼ*/
	printf("�Ѿ���ɴ��ļ����ṹ������Ĵ洢��׼����ʼ���洢����������Ļ�ϡ�\n");
	system("pause");
	for (i=0; i<current_doc_max_row_number; i++)
	{
		printf("[%d]\t", i);
		printf(".%s.\t", origin_row_data[i].record_time);
		printf(".%s.\t", origin_row_data[i].price);
		printf(".%s.\t", origin_row_data[i].signal_volume);
		printf(".%s.\t", origin_row_data[i].closing_time);
		printf(".%s.\t", origin_row_data[i].total_volume);
		printf(".%s.\t", origin_row_data[i].ave_price);
		printf(".%s.\n", origin_row_data[i].flag);		
	}
	/*��¼����ṹ�������е����� �������Ļ��	����*/

	if ((char_temp = fgetc(fp_origindata_txt)) == EOF)
		printf("\n����װ����ϡ�\n�ɹ������ļ�'data.txt'����%d�����ݣ�ʵ������Ϊ%d�����ݣ���һ����Ԫ��������ʶΪ0����\n", current_doc_max_row_number, current_doc_max_row_number-1);
	else
		printf("\nװ�����ݲ���ȫ��װ��ʧ�ܡ������ļ����ݣ������ԡ�\n");
	system("pause");

	/*�ⲿ�ļ��ر� ��ʼ*/
	fclose(fp_origindata_txt);
	/*�ⲿ�ļ��ر� ����*/
}