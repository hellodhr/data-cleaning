/************************************************************************************************************************
*文件名：data_rinse.c
*模块：下属子模块（模块是包含的其它.c文件）
*--------fun1_dataimport_text_module.c
*--------fun1_dataimport_keyboard_module.c
*-----------------------------------------------
*--------fun2_dataprocess_pre_type_conversion.c
*--------fun2_dataprocess_null.c
*-----------------------------------------------
*--------fun3_dataoutput_text.c
*说明：数据清洗
*问题：
*----①某些地方直接调用main()，个人感觉在返回主界面后有可能会导致变量与数值的关系链接丢失，但目前似乎没有这个问题。
*上一次修改：2013-11-25 0:40:16
*************************************************************************************************************************/

#include	<conio.h>
#include	<math.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<windows.h>

/*本文件程序中的自定义函数 声明 开始*/
void windows_initialization(void);							//[命令行窗口初始化]调整到适当位置，以方便后面输出结果并查看内容
int homepage(void);											//-1.[主界面]
void menu(void);											//0.[附加功能菜单]
	void function1_dataimport(void);						//1.[功能选项模块一] 数据录入
	void fun2_dataprocess_pre_type_conversion(void);			//1.0类型转换
		void fun1_dataimport_database_appearance(void);							//1.1 [数据库导入]
		void fun1_dataimport_text_appearance(void);								//1.2 [文件导入]
		void fun1_dataimport_keyboard_appearance(void);							//1.3 [键盘录入]

void function2_dataprocess(void);							//2.[功能选项模块二] 数据处理
//	void fun2_dataprocess_order(struct student *fun2_p_student);				//2.1 [排序] 还可以扩展*****按照某个属性进行排序
	void fun2_dataprocess_null(void);											//2.2 [空数据] 将空数据记录剔除（空数据记录被覆盖掉）
//	void fun2_dataprocess_range(struct student *fun2_p_student);				//2.3 [范围数据] 不在范围内的数据记录剔除（不在范围内的数据记录被覆盖掉）
void function3_dataoutput(void);							//3.[功能选项模块三] 格式输出
//	void fun3_dataoutput_database(void);										//3.1 [数据库输出]
//	void fun3_dataoutput_text(struct student *student);							//3.2 [文本输出]
//	void fun3_dataoutput_display(void)											//3.3 [屏幕输出]
void function4_introduction(void);							//4.[功能选项模块四] 使用说明
void function5_quit(void);									//5.[功能选项模块五] 程序退出
int main(void);
/*本文件程序中的自定义函数 声明 结束*/

/*子模块 装载	开始*/
#include	"fun1_dataimport_text_module.c"
#include	"fun1_dataimport_keyboard_module.c"
#include	"fun2_dataprocess_pre_type_conversion.c"
#include	"fun2_dataprocess_null.c"
#include	"fun3_dataoutput_text.c"
/*子模块 装载	结束*/



//[命令行窗口初始化]
void windows_initialization(void)
{
	system("mode con cols=137 lines=41");//对输出窗口大小的初始化
/*
	SMALL_RECT winPon={0,0,25,10};
	HANDLE con=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD buf={26,11};

	SetConsoleWindowInfo(con,1,&winPon);
	SetConsoleScreenBufferSize(con,buf);
*/
}

//3.[功能选项模块三] 格式输出
void function3_dataoutput(void)
{
	int function3_dataoutput_choice = 0;
	char function3_dataoutput_pre_choice = '0';

	printf("========================================智能数据清洗系统================================\n");
	printf("请从下列选项中选择一种【格式输出】方式                                                  \n");
	printf("                                                                                        \n");
	printf("                                  [1]输出到数据库                                       \n");
	printf("                                  [2]输出到文本                                         \n");
	printf("                                  [3]输出到屏幕                                         \n");
	printf("                                  [4]返回上一层                                         \n");
	printf("                                                                                        \n");
	printf("==========================================请您选择序号==================================\n");

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
				printf("【输出到数据库】自定义函数正在施工╮(╯_╰)╭......\n\n\n");menu();//输出到数据库
				break;
			}
		case 2:
			{
				system("cls");
				fun3_dataoutput_text();
				menu();
				//printf("【输出到文本】自定义函数正在施工╮(╯_╰)╭......\n\n\n");menu();//存储到文本
				break;
			}
		case 3:
			{
				system("cls");
				printf("【输出到屏幕】自定义函数正在施工╮(╯_╰)╭......\n\n\n");menu();//输出到屏幕
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

//2.[功能选项模块二] 数据处理
void function2_dataprocess(void)
{
	int function2_dataprocess_choice = 0;
	char function2_dataprocess_pre_choice = '0';

	printf("========================================智能数据清洗系统================================\n");
	printf("请从下列选项中选择一种【数据处理】方式                                                  \n");
	printf("                                                                                        \n");
	printf("                                  [1]空值剔除                                           \n");
	printf("                                  [2]范围筛除                                           \n");
	printf("                                  [3]排序                                               \n");
	printf("                                  [4]返回上一层                                         \n");
	printf("                                                                                        \n");
	printf("==========================================请您选择序号==================================\n");

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
				printf("【范围数据】自定义函数正在施工......\n╮(╯_╰)╭\n\n");menu();//范围数据
				break;
			}
		case 3:
			{
				system("cls");
				printf("【排序】自定义函数正在施工......\n╮(╯_╰)╭\n\n");menu();//排序
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

//1.[功能选项模块一] 数据录入
void function1_dataimport(void)
{
	int function1_dataimport_choice = 0;
	char function1_dataimport_pre_choice = '0';

	printf("========================================智能数据清洗系统================================\n");
	printf("请从下列选项中选择一种【数据录入】方式                                                  \n");
	printf("                                                                                        \n");
	printf("                                  [1]从数据库导入                                       \n");
	printf("                                  [2]从文件录入                                         \n");
	printf("                                  [3]从键盘录入                                         \n");
	printf("                                  [4]返回上一层                                         \n");
	printf("                                                                                        \n");
	printf("==========================================请您选择序号==================================\n");

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
				fun1_dataimport_database_appearance();//数据库数据导入
				break;
			}
		case 2:
			{
				system("cls");
				fun1_dataimport_text_appearance();//文件数据导入
				break;
			}
		case 3:
			{
				system("cls");
				fun1_dataimport_keyboard_appearance();//键盘数据导入
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

//1.1 [数据库导入]
void fun1_dataimport_database_appearance(void)
{
	printf("正在施工，请绕行。(╯‵□′)╯︵┻━┻\n\n\n");
	menu();
}

//1.2 [文件导入]
void fun1_dataimport_text_appearance(void)
{
	int function1_dataimport_text_choice = 0;
	char function1_dataimport_text_pre_choice = '0';

	printf("========================================智能数据清洗系统================================\n");
	printf("请根据以下操作要求完成数据文件的录入：                                                  \n");
	printf("                                                                                        \n");
	printf("     【Step.1】	 将要导入的数据文件命名为'data.txt'(格式为纯文本文件);                  \n");
	printf("                                                                                        \n");
	printf("     【Step.2】  将名为'data.txt'的纯文本文件放入D盘根目录下(即 'D:\');                 \n");
	printf("                                                                                        \n");
	printf("     【Step.3】  输入Y(大写)，程序将开始导入指定目录下的指定文件。                      \n");
	printf("                                                                                        \n");
	printf("=======================================输入Y(大写)开始导入==============================\n");
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

//1.3 [键盘录入]
void fun1_dataimport_keyboard_appearance(void)
{
	int function1_dataimport_keyboard_choice = 0;
	char function1_dataimport_keyboard_pre_choice = '0';

	printf("========================================智能数据清洗系统================================\n");
	printf("请根据以下操作要求完成数据文件的录入：                                                  \n");
	printf("                                                                                        \n");
	printf("                                                                                        \n");
	printf("                                                                                        \n");
	printf("                         输入Y大写开始从键盘输入数据。                                  \n");
	printf("                                                                                        \n");
	printf("                                                                                        \n");
	printf("                                                                                        \n");
	printf("=======================================输入Y(大写)开始导入==============================\n");
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
//主界面
int homepage(void)
{
	int homepage_choice=0;
	char homepage_pre_choice='0';

	printf("========================================智能数据清洗系统================================\n");
	printf("                                                                                        \n");
	printf("                                  [1]数据录入                                           \n");
	printf("                                  [2]数据处理                                           \n");
	printf("                                  [3]格式输出                                           \n");
	printf("                                  [4]使用说明                                           \n");
	printf("                                  [5]程序退出                                           \n");
	printf("                                                                                        \n");
	printf("==========================================请您选择序号==================================\n");

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

	printf("========================================系统附加功能菜单================================\n");
	printf("请根据需要输入下列选项：                                                                \n");
	printf("               [1]返回主界面   [2]格式输出   [3]使用说明   [4]程序退出                  \n");
	printf("==========================================请您选择序号==================================\n");

	scanf("%s",&menu_pre_choice);	//【注意】这里写%s才行 %c不行直接跳过这句= =

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
	printf("=========================================系统使用说明==================================\n");
	printf("                                                                                       \n");
	printf("【1】数据录入                                                                          \n");
	printf("                                                                                       \n");
	printf("【2】数据处理                                                                          \n");
	printf("                                                                                       \n");
	printf("【3】格式输出                                                                          \n");
	printf("                                                                                       \n");
	printf("【4】使用说明                                                                          \n");
	printf("                                                                                       \n");
	printf("=========================================按任意键返回==================================\n");
}

void function5_quit(void)
{
	char quit_confirm;

	printf("Confirm Quit:Please input 'Y' again!\n");	
	scanf("%s",&quit_confirm);	//【注意】这里写%s才行 %c不行直接跳过这句= =

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
		case 1://功能1 数据导入
			{
				system("cls");
				function1_dataimport();
				break;
			}
		case 2://功能2 数据处理
			{
				system("cls");
				function2_dataprocess();
				break;
			}
		case 3://功能3 格式输出
			{
				system("cls");
				function3_dataoutput();//void function3_dataoutput(struct student *student)
				break;
			}
		case 4://功能4 使用说明
			{
				system("cls");
				function4_introduction();
				system("pause");
				system("cls");
				main();
				break;
			}
		case 5://功能5 程序退出
			{
				function5_quit();
				break;
			}
		default://清屏 调用main
			{
				system("cls");
				main();
				break;
			}
	}
	system("pause");
	return 0;
}