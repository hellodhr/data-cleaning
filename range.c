
#include<stdio.h>
#include<math.h>

double SUM(double x[],int n);
double AVRG(double x[],int n);
double SD(double x[],int n);
int PauTa(double x[],int n);
int Chauvenet(double x[],int n);
int Grubbs_1(double x[],int n);
int Grubbs_2(double x[],int n);

static int n;
static double a[500];

int main()
{
	int i, choose, leap = 1;
	double avg, sd, v[500], M = 0, AH = 0, vmax = 0;
	double P, PX[]={12.71, 4.303, 3.182, 2.776, 2.571, 2.447, 2.365, 2.306, 2.262, 2.228, 2.131, 2.086, 2.06, 2.042, 2.021, 2.000, 1.980, 1.960};
	printf("�����������ܸ���: \n");
	scanf("%d",&n);
	printf("����������: \n");
	for(i = 0; i < n; i++)		scanf("%lf", &a[i]);
	avg = AVRG(a, n);
	sd = SD(a, n);
	printf("\n�������ݵ�ƽ��ֵΪ%lf, ��׼��Ϊ%lf \n", avg, sd);
	while(leap)
	{
		printf("��ѡ��ִ����ļ��鷨: \n1. ���ؼ��鷨 \n2. Фά�ɼ��鷨 \n3.������˹���鷨(���Ÿ���99%%) \n4.������˹���鷨(���Ÿ���95%%) \n5. ֹͣ���� \n ");
		scanf("%d", &choose);
		if(choose == 1&&n < 10)		printf("��������С��10,����ʹ�����ؼ��鷨��\n");
		else if(choose == 2&&n < 5)		printf("��������С��5,����ʹ��Фά�ɼ��鷨��\n");
		else switch(choose)
		{
			case 1 : leap = PauTa(a,n);		break;
			case 2 : leap = Chauvenet(a,n);		break;
			case 3 : leap = Grubbs_1(a,n);		break;
			case 4 : leap = Grubbs_2(a,n);		break;
			case 5 : leap = 0;		break;
			default : printf("�������������ѡ�� \n");		break;
		}
	}
	avg = AVRG(a, n);
	sd = SD(a, n);
	for(i=0; i < n; i++)
	{
		v[i]=a[i] - avg;
		if(vmax * vmax <= v[i] * v[i])		vmax = v[i];
	}
	printf("�ִ�����޳����,ʣ����������(������Ϊ�в�): \n");
	for(i = 0; i < n; i++)		printf("%f(%f)", a[i], v[i]);
	printf("\n�������ݵ�ƽ��ֵΪ%lf, ��׼��Ϊ%lf \n", avg, sd);
	for(i = 0;i < n; i++)		M += v[i];
	for(i = (n + 1) / 2;i < n; i++)		M -= v[i];
	M = sqrt(M * M);
	vmax = sqrt(vmax * vmax);
	if(M >= vmax)		printf("\n���������Ʒ��о�,�����۽���ϵͳ�� \n");
	else printf("\n���������Ʒ��о�,�������۽���ϵͳ�� \n");
	for(i = 0; i < n-1; i++)		AH += v[i] * v[i+1];
	if((AH * AH) >=((n - 1) * sd * sd * sd * sd))		printf("\n���ݰ���-��÷��׼��, ����������ϵͳ��\n");
	else printf("\n���ݰ���-��÷��׼��, ������������ϵͳ��\n");
	if(n > 120)		P = PX[37];
	else if(n > 60)		P = PX[16];
	else if(n > 40)		P = PX[15];
	else if(n > 30)		P = PX[14];
	else if(n > 25)		P = PX[13];
	else if(n > 20)		P = PX[12];
	else if(n > 15)		P = PX[11];
	else if(n > 10)		P = PX[10];
	else P = PX[n-1];
	printf("\n �������ݵ���������Ϊ[%lf,%lf](���Ÿ���Ϊ95%%)\n",(avg - P * sd),(avg + P * sd));
	return 0;
}

double SUM(double x[],int n)
{
	double s = 0;
	int i;
	for(i = 0; i < n; i++)		s += x[i];
	return s;

}

double AVRG(double x[],int n)
{
	double aver = 0;
	aver = SUM(x , n) / n;
	return aver;

}

double SD(double x[],int n)
{
	double aver, sd, SUM = 0;
	int i;
	aver = AVRG(x, n);
	for(i = 0; i < n; i++)		SUM += x[i] * x[i];
	sd = sqrt((SUM - n * aver * aver) / (n-1));
	return sd;

}

int PauTa(double x[],int n)
{
	int i, j = 0, leap;
	double v[500], temp = 0, aver, sd;
	aver = AVRG(x, n);
	sd = SD(x, n);
	for(i = 0; i < n; i++)		v[i] = x[i] - aver;
	for(i = 0; i < n; i++)
	{
		if((v[i] * v[i] >= 9 * sd * sd) && (v[i] * v[i] > temp * temp))
		{
			temp = v[i];
			j = i+1;
		}
	}
	if(j)
	{
		for(i = j-1; i < n; i++)		x[i] = x[i+1];
		n--;
		printf("�������ؼ����㷨�������޳�������Ϊ%lf \n%d%", x[j-1], n);
		leap = 1;
	}
	else
	{
		printf("�������ؼ����㷨��û��Ҫ�޳������� \n");
		leap = 0;
	}
	return leap;

}

int Chauvenet(double x[],int n)
{
	int i,j = 0,leap;
	double v[500], temp = 0, ch, aver, sd;
	double 
		chx[] = {0, 0, 0, 0, 1.65, 1.73, 1.79, 1.86, 1.92, 2.00, 2.04, 2.07, 2.10, 2.13, 2.16, 2.18, 2.20, 2.22, 2.24, 2.26, 2.28, 2.30, 2.32, 2.33, 2.34, 2.35, 2.37, 2.38, 2.39, 2.45, 2.50, 2.58, 2.64, 2.74, 2.81, 3.02};
	if(n > 36)		ch = chx[35];
	else ch = chx[n-1];
	aver = AVRG(x, n);
	sd = SD(x, n);
	for(i = 0; i < n; i++)		v[i] = x[i] - aver;
	for(i = 0; i < n; i++)
	{
		if((v[i] * v[i]) >= (ch * ch * sd * sd) && (v[i] * v[i]) >= (temp * temp))
		{
			j = i + 1;
			temp = v[i];
		}
	}
	if(j)
	{
		printf("����Фά�ɼ��鷨�������޳��˵�%d������%lf \n", j, x[j-1]);
		for(i = j-1; i < n-1; i++)		x[i] = x[i+1];
		leap = 1;
		n--;
	}
	else
	{
		printf("����Фά�ɼ��鷨��û��Ҫ�޳����� \n");
		leap = 0;
	}
	return leap;
}

int Grubbs_1(double x[], int n)
{
	int i, max = 0, min = 0, leap;
	double v[500], temp = 0, g, sd, aver;
	double
		gx[30] = {0, 0, 1.15, 1.46, 1.67, 1.82, 1.94, 2.03, 2.11, 2.18, 2.23, 2.29, 2.33, 2.37, 2.41, 2.44, 2.47, 2.50, 2.53, 2.56, 2.58, 2.60, 2.62, 2.64, 2.66, 2.74, 2.81, 2.87, 2.96, 3.17};
	if(n >= 100)		g = gx[29];
	else if(n >= 50)		g = gx[28];
	else if(n >= 40)		g = gx[27];
	else if(n >= 35)		g = gx[26];
	else if(n >= 30)		g = gx[25];
	else if(n >= 25)		g = gx[24];
	else g = gx[n-1];
	aver = AVRG(x, n);
	sd = SD(x, n);
	for(i = 0; i < n; i++)
	{
		v[i] = x[i] - aver;
		if(x[min] > x[i])		min = i;
		if(max < x[i])		max = i;
	}
	if(v[max] * v[max] < v[min] * v[min])		max = min;
	if(v[max] * v[max] > g * g * sd * sd)
	{
		printf("���ݸ�����˹���鷨�������޳��˵�%d������%lf(���Ÿ���99%%) \n", max, x[max]);
		for(i = max; i < n; i++)		x[i] = x[i+1];
		leap = 1;
		n--;
	}
	else
	{
		printf("���ݸ�����˹���鷨��û��Ҫ�޳����� \n");
		leap = 0;
	}
	return leap;
}

int Grubbs_2(double x[], int n)
{
	int i, max = 0, min = 0, leap;
	double v[500], temp = 0, g, sd, aver;
	double
		gx[30] = {0, 0, 1.16, 1.49, 1.75, 1.94, 2.10, 2.22, 2.32, 2.41, 2.48, 2.55, 2.61, 2.66, 2.71, 2.75, 2.79, 2.82, 2.85, 2.88, 2.91, 2.94, 2.96, 2.99, 3.01, 3.10, 3.18, 3.24, 3.34, 3.58};
	if(n >= 100)		g = gx[29];
	else if(n >= 50)		g = gx[28];
	else if(n >= 40)		g = gx[27];
	else if(n >= 35)		g = gx[26];
	else if(n >= 30)		g = gx[25];
	else if(n >= 25)		g = gx[24];
	else g = gx[n-1];
	aver = AVRG(x, n);
	sd = SD(x, n);
	for(i = 0; i < n; i++)
	{
		v[i] = x[i] - aver;
		if(x[min] > x[i])		min = i;
		if(max < x[i])		max = i;
	}
	if(v[max] * v[max] < v[min] * v[min])		max = min;
	if(v[max] * v[max] > g * g * sd * sd)
	{
		printf("���ݸ�����˹���鷨�������޳��˵�%d������%lf(���Ÿ���95%%) \n", max, x[max]);
		for(i = max; i < n; i++)		x[i] = x[i+1];
		leap = 1;
		n--;
	}
	else
	{
		printf("���ݸ�����˹���鷨��û��Ҫ�޳����� \n");
		leap = 0;
	}
	return leap;
}