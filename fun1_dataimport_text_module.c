//文件名：fun1_dataimport_text_module.c
//模块：fun1_dataimport_text_module
//		void fun1_dataimport_text_module(void);
//			int fun_current_doc_max_row_number(void);
//			void fun1_dataimport_text(int current_doc_max_row_number);
//说明：单个指定路径和行数的文本文件的数据导入到结构体数组
//问题：
//----①必须指定路径和文件名
//----②手动指定行数
//----③运行错误：
//---------最大宏定义数值为9850，大于9850弹出运行错误，无法存入
//---------最大宏定义数值为9784，大于9784弹出运行错误，程序运行结束弹出运行错误
//上一次修改：2013-11-23 20:30:59

#define 	STRUCT_ARRAY_NUMBER 		      9784		//读取的文本数据的行数
															//*******最大宏定义数值为9850，大于9850弹出运行错误，无法存入
															//*******最大宏定义数值为9784，大于9784弹出运行错误，程序运行结束弹出运行错误
#define		CHAR_ELEMENT 				      15		//结构体struct_origin_row_data数组origin_row_data的[每个元素]所包含的字节数

#include 	<stdio.h>
#include 	<conio.h>
#include 	<string.h>
#include 	<windows.h>

void fun1_dataimport_text_module(void);
	int fun_current_doc_max_row_number(void);
	void fun1_dataimport_text(int current_doc_max_row_number);

	/*结构体数组变量 声明 开始*/
	struct struct_origin_row_data        //行结构体记录
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
	/*结构体数组变量 声明 结束*/

void fun1_dataimport_text_module(void)
{
	FILE *fp_origindata_txt = NULL;
	fp_origindata_txt = fopen("d:\\data.txt", "rb");   //fopen是一个C库函数，用于打开文件,"r"是只读模式，在这种模式下，如果文件存在，则能成功以只读模式打开，fopen返回一个非0的文件描述符，如果文件不存在，则fopen返回NULL（NULL意思是空）。正好可以利用这一点来判断文件是否存在
	printf("请将要读取的文件放入D盘根目录，并起名为'data.txt'。\n");
	system("pause");
	printf("确认已经将名为'data.txt'的文件已经放在D盘根目录。\n");
	system("pause");

    if (fp_origindata_txt != NULL)
		fun1_dataimport_text(fun_current_doc_max_row_number());
    else
	{
		printf("不存在'd:\\data.txt'文件，请按照操作流程重试。\n");
		system("pause");
		system("cls");
		fun1_dataimport_text_module();
	}
	fclose(fp_origindata_txt);  //存在的话，要先把之前打开的文件关掉
}

//确定外部文件的行数
int fun_current_doc_max_row_number(void)
{
	int current_doc_max_row_number = 0;
	char char_temp = '1';
	FILE *fp_origindata_txt;

	/*确定文件行数并存入current_doc_max_row_number	开始*/
		/*外部文件打开 开始*/
	if ((fp_origindata_txt = fopen("d:\\data.txt", "rb")) == NULL)
	{
		printf("无法打开文件，请按任意键退出!\n");
		system("pause");
		exit(1);		
	}
		/*外部文件打开 结束*/

	rewind(fp_origindata_txt);//文件内指针初始化到文件头
	while((char_temp = fgetc(fp_origindata_txt)) != EOF)
	{
		if(char_temp == '\n')
			current_doc_max_row_number++;
	}
	/*确定文件行数并存入current_doc_max_row_number	结束*/
	fclose(fp_origindata_txt);

	printf("预读取的文本文件总计行数：%d行。\n按任意键，程序将开始装载数据，并将装载完成的数据回显到屏幕上。\n", current_doc_max_row_number);
	system("pause");
	return current_doc_max_row_number;
}

void fun1_dataimport_text(int current_doc_max_row_number)
{
	/*函数void fun1_dataimport_text 变量声明 开始*/
	int i = 0, j = 0;
	char char_temp = '1';
	FILE *fp_origindata_txt;

	//这里把结构体数组的声明放到函数外面

	printf("声明定义的结构体数组空间已经全部申请成功。\n");
	/*动态分配结构体数组 内存大小 开始*/
	/*
	if (!(p_origin_row_data=(struct struct_origin_row_data *)malloc(current_doc_max_row_number*sizeof(struct struct_origin_row_data))))
	{
		printf("Memory is not accessed!\n");
		exit(1);/*内存分配失败时异常退出。也需要stdlib.h
	}
	*/
	//printf("%d", sizeof(struct struct_origin_row_data));
	/*动态分配结构体数组 内存大小 结束*/
	/*函数void fun1_dataimport_text 变量声明 结束*/

	printf("声明结构体数组已经完成，准备开始将文件中的内容存储到结构体数组。\n");
	/*外部文件打开 开始*/
	if ((fp_origindata_txt = fopen("d:\\data.txt", "rb")) == NULL)
	{
		printf("无法打开文件，请按任意键退出!\n");
		getch();
		exit(1);		
	}
	/*外部文件打开 结束*/

	/*文件读入到结构体数组	开始*/
	rewind(fp_origindata_txt);//文件内指针返回文件头。对文件行数确定之后，再次对文件内指针回到初始位置
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
				}//从第二个开始是空，则跑字符，依旧挨个遍历
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

		/*存入结构体数组第7个成员origin_row_data[i].flag 开始*/
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
		/*存入结构体数组第7个成员origin_row_data[i].flag 结束*/

		char_temp = fgetc(fp_origindata_txt);
		while(char_temp != '\n')
		{
			char_temp = fgetc(fp_origindata_txt);
		}
	}					
	/*文件读入到结构体数组	结束*/

	
	/*录入数据 输出到屏幕上	开始*/
	printf("已经完成从文件到结构体数组的存储，准备开始将存储结果输出到屏幕上。\n");
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
	/*将录入进结构体数组中的数据 输出到屏幕上	结束*/

	if ((char_temp = fgetc(fp_origindata_txt)) == EOF)
		printf("\n数据装载完毕。\n成功导入文件'data.txt'所有%d行数据，实际数据为%d行数据（第一行是元素名，标识为0）。\n", current_doc_max_row_number, current_doc_max_row_number-1);
	else
		printf("\n装载数据不完全，装载失败。请检查文件内容，并重试。\n");
	system("pause");

	/*外部文件关闭 开始*/
	fclose(fp_origindata_txt);
	/*外部文件关闭 结束*/
}