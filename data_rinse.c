/************************************************************************************************************************
*�ļ�����data_rinse.c
*ģ�飺������ģ�飨ģ���ǰ���������.c�ļ���
*--------fun1_dataimport_text_module.c
*--------fun1_dataimport_keyboard_module.c
*-----------------------------------------------
*--------fun2_dataprocess_pre_type_conversion.c
*--------fun2_dataprocess_null.c
*-----------------------------------------------
*--------fun3_dataoutput_text.c
*˵����������ϴ
*���⣺
*----��ĳЩ�ط�ֱ�ӵ���main()�����˸о��ڷ�����������п��ܻᵼ�±�������ֵ�Ĺ�ϵ���Ӷ�ʧ����Ŀǰ�ƺ�û��������⡣
*��һ���޸ģ�2013-11-25 0:40:16
*************************************************************************************************************************/

#include	<conio.h>
#include	<math.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<windows.h>

/*���ļ������е��Զ��庯�� ���� ��ʼ*/
void windows_initialization(void);							//[�����д��ڳ�ʼ��]�������ʵ�λ�ã��Է���������������鿴����
int homepage(void);											//-1.[������]
void menu(void);											//0.[���ӹ��ܲ˵�]
	void function1_dataimport(void);						//1.[����ѡ��ģ��һ] ����¼��
	void fun2_dataprocess_pre_type_conversion(void);			//1.0����ת��
		void fun1_dataimport_database_appearance(void);							//1.1 [���ݿ⵼��]
		void fun1_dataimport_text_appearance(void);								//1.2 [�ļ�����]
		void fun1_dataimport_keyboard_appearance(void);							//1.3 [����¼��]

void function2_dataprocess(void);							//2.[����ѡ��ģ���] ���ݴ���
//	void fun2_dataprocess_order(struct student *fun2_p_student);				//2.1 [����] ��������չ*****����ĳ�����Խ�������
	void fun2_dataprocess_null(void);											//2.2 [������] �������ݼ�¼�޳��������ݼ�¼�����ǵ���
//	void fun2_dataprocess_range(struct student *fun2_p_student);				//2.3 [��Χ����] ���ڷ�Χ�ڵ����ݼ�¼�޳������ڷ�Χ�ڵ����ݼ�¼�����ǵ���
void function3_dataoutput(void);							//3.[����ѡ��ģ����] ��ʽ���
//	void fun3_dataoutput_database(void);										//3.1 [���ݿ����]
//	void fun3_dataoutput_text(struct student *student);							//3.2 [�ı����]
//	void fun3_dataoutput_display(void)											//3.3 [��Ļ���]
void function4_introduction(void);							//4.[����ѡ��ģ����] ʹ��˵��
void function5_quit(void);									//5.[����ѡ��ģ����] �����˳�
int main(void);
/*���ļ������е��Զ��庯�� ���� ����*/

/*��ģ�� װ��	��ʼ*/
#include	"fun1_dataimport_text_module.c"
#include	"fun1_dataimport_keyboard_module.c"
#include	"fun2_dataprocess_pre_type_conversion.c"
#include	"fun2_dataprocess_null.c"
#include	"fun3_dataoutput_text.c"
/*��ģ�� װ��	����*/



//[�����д��ڳ�ʼ��]
void windows_initialization(void)
{
	system("mode con cols=137 lines=41");//��������ڴ�С�ĳ�ʼ��
/*
	SMALL_RECT winPon={0,0,25,10};
	HANDLE con=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD buf={26,11};

	SetConsoleWindowInfo(con,1,&winPon);
	SetConsoleScreenBufferSize(con,buf);
*/
}

//3.[����ѡ��ģ����] ��ʽ���
void function3_dataoutput(void)
{
	int function3_dataoutput_choice = 0;
	char function3_dataoutput_pre_choice = '0';

	printf("========================================����������ϴϵͳ================================\n");
	printf("�������ѡ����ѡ��һ�֡���ʽ�������ʽ                                                  \n");
	printf("                                                                                        \n");
	printf("                                  [1]��������ݿ�                                       \n");
	printf("                                  [2]������ı�                                         \n");
	printf("                                  [3]�������Ļ                                         \n");
	printf("                                  [4]������һ��                                         \n");
	printf("                                                                                        \n");
	printf("==========================================����ѡ�����==================================\n");

	scanf("%c",&function3_dataoutput_pre_choice);

	if (function3_dataoutput_pre_choice == '1')
		function3_dataoutput_choice = 1;
	else
	{
		if (function3_dataoutput_pre_choice == '2')
			function3_dataoutput_choice = 2;
		else
		{
			if (function3_dataoutput_pre_choice == '3')
				function3_dataoutput_choice = 3;
			else
			{
				if (function3_dataoutput_pre_choice == '4')
					function3_dataoutput_choice = 4;
				else
					function3_dataoutput_choice = 0;
			}
		}
	}

	switch(function3_dataoutput_choice)
	{
		case 1:
			{
				system("cls");
				printf("����������ݿ⡿�Զ��庯������ʩ���r(�s_�t)�q......\n\n\n");menu();//��������ݿ�
				break;
			}
		case 2:
			{
				system("cls");
				fun3_dataoutput_text();
				menu();
				//printf("��������ı����Զ��庯������ʩ���r(�s_�t)�q......\n\n\n");menu();//�洢���ı�
				break;
			}
		case 3:
			{
				system("cls");
				printf("���������Ļ���Զ��庯������ʩ���r(�s_�t)�q......\n\n\n");menu();//�������Ļ
				break;
			}
		case 4:
			{
				system("cls");
				main();
				break;
			}
		default:
			{
				system("cls");
				function3_dataoutput();
				break;
			}
	}
}

//2.[����ѡ��ģ���] ���ݴ���
void function2_dataprocess(void)
{
	int function2_dataprocess_choice = 0;
	char function2_dataprocess_pre_choice = '0';

	printf("========================================����������ϴϵͳ================================\n");
	printf("�������ѡ����ѡ��һ�֡����ݴ�����ʽ                                                  \n");
	printf("                                                                                        \n");
	printf("                                  [1]��ֵ�޳�                                           \n");
	printf("                                  [2]��Χɸ��                                           \n");
	printf("                                  [3]����                                               \n");
	printf("                                  [4]������һ��                                         \n");
	printf("                                                                                        \n");
	printf("==========================================����ѡ�����==================================\n");

	scanf("%c",&function2_dataprocess_pre_choice);

	if (function2_dataprocess_pre_choice == '1')
		function2_dataprocess_choice = 1;
	else
	{
		if (function2_dataprocess_pre_choice == '2')
			function2_dataprocess_choice = 2;
		else
		{
			if (function2_dataprocess_pre_choice == '3')
				function2_dataprocess_choice = 3;
			else
			{
				if (function2_dataprocess_pre_choice == '4')
					function2_dataprocess_choice = 4;
				else
					function2_dataprocess_choice = 0;
			}
		}
	}

	switch(function2_dataprocess_choice)
	{
		case 1:
			{
				system("cls");
				fun2_dataprocess_null();
				menu();
				break;
			}
		case 2:
			{
				system("cls");
				printf("����Χ���ݡ��Զ��庯������ʩ��......\n�r(�s_�t)�q\n\n");menu();//��Χ����
				break;
			}
		case 3:
			{
				system("cls");
				printf("�������Զ��庯������ʩ��......\n�r(�s_�t)�q\n\n");menu();//����
				break;
			}
		case 4:
			{
				system("cls");
				main();
				break;
			}
		default:
			{
				system("cls");
				function2_dataprocess();
				break;
			}
	}
}

//1.[����ѡ��ģ��һ] ����¼��
void function1_dataimport(void)
{
	int function1_dataimport_choice = 0;
	char function1_dataimport_pre_choice = '0';

	printf("========================================����������ϴϵͳ================================\n");
	printf("�������ѡ����ѡ��һ�֡�����¼�롿��ʽ                                                  \n");
	printf("                                                                                        \n");
	printf("                                  [1]�����ݿ⵼��                                       \n");
	printf("                                  [2]���ļ�¼��                                         \n");
	printf("                                  [3]�Ӽ���¼��                                         \n");
	printf("                                  [4]������һ��                                         \n");
	printf("                                                                                        \n");
	printf("==========================================����ѡ�����==================================\n");

	scanf("%c",&function1_dataimport_pre_choice);

	if (function1_dataimport_pre_choice == '1')
		function1_dataimport_choice = 1;
	else
	{
		if (function1_dataimport_pre_choice == '2')
			function1_dataimport_choice = 2;
		else
		{
			if (function1_dataimport_pre_choice == '3')
				function1_dataimport_choice = 3;
			else
			{
				if (function1_dataimport_pre_choice == '4')
					function1_dataimport_choice = 4;
				else
					function1_dataimport_choice = 0;
			}
		}
	}

	switch(function1_dataimport_choice)
	{
		case 1:
			{
				system("cls");
				fun1_dataimport_database_appearance();//���ݿ����ݵ���
				break;
			}
		case 2:
			{
				system("cls");
				fun1_dataimport_text_appearance();//�ļ����ݵ���
				break;
			}
		case 3:
			{
				system("cls");
				fun1_dataimport_keyboard_appearance();//�������ݵ���
				break;
			}
		case 4:
			{
				system("cls");
				main();
				break;
			}
		default:
			{
				system("cls");
				function1_dataimport();
				break;
			}
	}
}

//1.1 [���ݿ⵼��]
void fun1_dataimport_database_appearance(void)
{
	printf("����ʩ���������С�(�s�F����)�s��ߩ���\n\n\n");
	menu();
}

//1.2 [�ļ�����]
void fun1_dataimport_text_appearance(void)
{
	int function1_dataimport_text_choice = 0;
	char function1_dataimport_text_pre_choice = '0';

	printf("========================================����������ϴϵͳ================================\n");
	printf("��������²���Ҫ����������ļ���¼�룺                                                  \n");
	printf("                                                                                        \n");
	printf("     ��Step.1��	 ��Ҫ����������ļ�����Ϊ'data.txt'(��ʽΪ���ı��ļ�);                  \n");
	printf("                                                                                        \n");
	printf("     ��Step.2��  ����Ϊ'data.txt'�Ĵ��ı��ļ�����D�̸�Ŀ¼��(�� 'D:\');                 \n");
	printf("                                                                                        \n");
	printf("     ��Step.3��  ����Y(��д)�����򽫿�ʼ����ָ��Ŀ¼�µ�ָ���ļ���                      \n");
	printf("                                                                                        \n");
	printf("=======================================����Y(��д)��ʼ����==============================\n");
	scanf("%c",&function1_dataimport_text_pre_choice);

	if (function1_dataimport_text_pre_choice == 'Y')
		function1_dataimport_text_choice = 1;
	else
		function1_dataimport_text_choice = 0;

	switch(function1_dataimport_text_choice)
	{
		case 1:
			{
				system("cls");
				fun1_dataimport_text_module();
				fun2_dataprocess_pre_type_conversion();
				menu();
				break;
			}
		default:
			{
				system("cls");
				fun1_dataimport_text_appearance();
				break;
			}
	}
	fun2_dataprocess_pre_type_conversion();
}

//1.3 [����¼��]
void fun1_dataimport_keyboard_appearance(void)
{
	int function1_dataimport_keyboard_choice = 0;
	char function1_dataimport_keyboard_pre_choice = '0';

	printf("========================================����������ϴϵͳ================================\n");
	printf("��������²���Ҫ����������ļ���¼�룺                                                  \n");
	printf("                                                                                        \n");
	printf("                                                                                        \n");
	printf("                                                                                        \n");
	printf("                         ����Y��д��ʼ�Ӽ����������ݡ�                                  \n");
	printf("                                                                                        \n");
	printf("                                                                                        \n");
	printf("                                                                                        \n");
	printf("=======================================����Y(��д)��ʼ����==============================\n");
	scanf("%c",&function1_dataimport_keyboard_pre_choice);

	if (function1_dataimport_keyboard_pre_choice == 'Y')
		function1_dataimport_keyboard_choice = 1;
	else
		function1_dataimport_keyboard_choice = 0;

	switch(function1_dataimport_keyboard_choice)
	{
		case 1:
			{
				system("cls");
				fun1_dataimport_keyboard_module();
				fun2_dataprocess_pre_type_conversion();
				menu();
				break;
			}
		default:
			{
				system("cls");
				fun1_dataimport_keyboard_appearance();
				break;
			}
	}
}
//������
int homepage(void)
{
	int homepage_choice=0;
	char homepage_pre_choice='0';

	printf("========================================����������ϴϵͳ================================\n");
	printf("                                                                                        \n");
	printf("                                  [1]����¼��                                           \n");
	printf("                                  [2]���ݴ���                                           \n");
	printf("                                  [3]��ʽ���                                           \n");
	printf("                                  [4]ʹ��˵��                                           \n");
	printf("                                  [5]�����˳�                                           \n");
	printf("                                                                                        \n");
	printf("==========================================����ѡ�����==================================\n");

	scanf("%c",&homepage_pre_choice);

	if (homepage_pre_choice == '1')
		homepage_choice = 1;
	else
	{
		if (homepage_pre_choice == '2')
			homepage_choice = 2;
		else
		{
			if (homepage_pre_choice == '3')
				homepage_choice = 3;
			else
			{
				if (homepage_pre_choice == '4')
					homepage_choice = 4;
				else
				{
					if (homepage_pre_choice == '5')
						homepage_choice = 5;
					else
						homepage_choice = 0;
				}
			}
		}
	}
	return homepage_choice;
}

void menu(void)
{
	int menu_choice=0;
	char menu_pre_choice='0';

	printf("========================================ϵͳ���ӹ��ܲ˵�================================\n");
	printf("�������Ҫ��������ѡ�                                                                \n");
	printf("               [1]����������   [2]��ʽ���   [3]ʹ��˵��   [4]�����˳�                  \n");
	printf("==========================================����ѡ�����==================================\n");

	scanf("%s",&menu_pre_choice);	//��ע�⡿����д%s���� %c����ֱ���������= =

	if (menu_pre_choice == '1')
		menu_choice = 1;
	else
	{
		if (menu_pre_choice == '2')
			menu_choice = 2;
		else
		{
			if (menu_pre_choice == '3')
				menu_choice = 3;
			else
			{
				if (menu_pre_choice == '4')
					menu_choice = 4;
				else
				{
					menu_choice = 0;
				}
			}
		}
	}

	switch(menu_choice)
	{
		case 1:
			{
				system("cls");
				main();
				break;
			}
		case 2:
			{
				system("cls");
				function3_dataoutput();//void function3_dataoutput(struct student *student)
				break;
			}
		case 3:
			{
				system("cls");
				function4_introduction();
				menu();
				break;
			}
		case 4:
			{
				function5_quit();
				break;
			}
		default:
			{
				system("cls");
				printf("Input wrong.Please input again.\n");
				menu();
				break;
			}
	}
}

void function4_introduction(void)
{
	printf("=========================================ϵͳʹ��˵��==================================\n");
	printf("                                                                                       \n");
	printf("��1������¼��                                                                          \n");
	printf("                                                                                       \n");
	printf("��2�����ݴ���                                                                          \n");
	printf("                                                                                       \n");
	printf("��3����ʽ���                                                                          \n");
	printf("                                                                                       \n");
	printf("��4��ʹ��˵��                                                                          \n");
	printf("                                                                                       \n");
	printf("=========================================�����������==================================\n");
}

void function5_quit(void)
{
	char quit_confirm;

	printf("Confirm Quit:Please input 'Y' again!\n");	
	scanf("%s",&quit_confirm);	//��ע�⡿����д%s���� %c����ֱ���������= =

	if (quit_confirm == 'Y')
	{
		printf("Press any Key exit!\n");
		system("pause");
		exit(0);
	}
	else
		menu();
}

int main(void)
{
	windows_initialization();
	switch(homepage())
	{
		case 1://����1 ���ݵ���
			{
				system("cls");
				function1_dataimport();
				break;
			}
		case 2://����2 ���ݴ���
			{
				system("cls");
				function2_dataprocess();
				break;
			}
		case 3://����3 ��ʽ���
			{
				system("cls");
				function3_dataoutput();//void function3_dataoutput(struct student *student)
				break;
			}
		case 4://����4 ʹ��˵��
			{
				system("cls");
				function4_introduction();
				system("pause");
				system("cls");
				main();
				break;
			}
		case 5://����5 �����˳�
			{
				function5_quit();
				break;
			}
		default://���� ����main
			{
				system("cls");
				main();
				break;
			}
	}
	system("pause");
	return 0;
}