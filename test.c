#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//ָ���Ǹ�����������ڴ浥Ԫ�ĵ�ַ����ţ�
int main()
{
	int a = 10;//���ڴ��п���һ��ռ�
	int* p = &a;//�Ա���a��ȡ�����ĵ�ַ����&������
	//��a�ĵ�ַ�����p�����У�p����һ��ָ�����
	return 0;
}
//�ܽ᣺ָ����Ǳ�����������ŵ�ַ�ı����������ָ���з�ֵ�������ɵ�ַ����

//ָ��32λ4�ֽڣ�64λ8�ֽ�
int main()
{
	printf("%d\n", sizeof(char*));//8
	printf("%d\n", sizeof(short*));//8
	printf("%d\n", sizeof(int*));//8
	printf("%d\n", sizeof(double*));//8
	return 0;
}

int main()
{
	int a = 0x11223344;//0x - 16���Ʊ�־
	int* pa = &a;
	char* pc = &a;

	printf("%p\n", pa);
	printf("%p\n", pc);//������ͬ

	return 0;
}

int main()
{
	int a = 0x11223344;
	//int* pa = &a;
	//*pa = 0;//a�ĸ��ֽڶ����0
	char* pa = &a;
	*pa = 0;//a��һ���ֽڱ��0
	return 0;
}//ָ�����͵����壺
// 1.ָ�����;�����ָ����н����ò�����ʱ���ܹ����ʵĿռ�Ĵ�С
//��ͬ����ָ�������ʱ�����һ����int����ָ�������ʱ�ܲ����ĸ��ֽڣ�charֻ��һ��
//int* p; *p�ܷ���4���ֽ�
//char* p;  *p�ܹ�����1���ֽ�
//double* p;  *p�ܹ�����8���ֽ�
//
int main()
{
	int a = 0x11223344;
	int* pa = &a;
	char* pc = &a;
	printf("%p\n", pa);
	printf("%p\n", pa+1);//+4���ֽ�

	printf("%p\n", pc);
	printf("%p\n", pc+1);//+1���ֽ�
	return 0;
}
// 2.ָ�����;���ָ����һ���߶�Զ��ָ��Ĳ�����
//int* p;  p + 1 -> 4
//char* p;  p + 1 -> 1
//double* p;  p + 1 -> 8

//����
int main()
{
	int arr[10] = { 0 };
	int* p = arr;//������ - (�󲿷�)��Ԫ�ص�ַ
	// 1.&arr - ��������ʾ�������� - &������ȡ����������ĵ�ַ
	// 2.sizeof(arr) - sizeof(������) - ��������ʾ�������� - �������������С
	for (int i = 0; i < 10; i++)
	{
		*(p + i) = 1;//int���飬��������Ԫ��ռ4���ֽڣ�����int����ָ��+1����ָ����һ��Ԫ��
	}
	return 0;
}

//Ұָ�� - ָ��ָ��λ�ò���֪
// 1.ָ��δ��ʼ��
int main()
{
	int a;//�ֲ���������ʼ����Ĭ�������ֵ
	int* p;//�ֲ���ָ��������ͱ���ʼ�����ֵ
	*p = 20;//������ڴ�ռ䣬so dangerous
	return 0;
}
// 2.ָ��Խ�����
int main()
{
	int arr[10] = { 0 };
	int* p = arr;
	for (int i = 0; i < 12; i++)
	{
		*p++ = i;//p�������鷶Χʱ��ΪҰָ��
		//*p = i
		//P++
	}
	return 0;
}
// 3.ָ��ָ����ڴ�ռ��ͷ�
int* test()
{
	int a = 10;
	return &a;
}
int main()
{
	int* p = test();
	printf("%d\n", *p);//test���������ڴ�ռ��ͷţ�a�Ŀռ��Ѿ��ͷţ�*pָ�˸�����
	return 0;
}

int main()
{
	//int* p = NULL;//NULL - ������ʼ��ָ�룬��ָ�븳ֵ����֪����ָ��ָʲô����ֵ��ֹ����Ұָ�룩
	////   ��ָ��
	int a = 10;
	int* pa = &a;
	*pa = 20;
	//������Ч��ָ��
	pa = NULL;
	*pa = 0;//error
	if (pa != NULL)//�жϴ�ʱָ���ܲ�����,�����Ч��
	{
	};
	return 0;
}

//ָ������
// 1.ָ��+-����
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int* p = arr;
	for (i = 0; i < sz; i++)
	{
		/*printf("%d\n", *p);
		p++;*/
		printf("%d\n", *(p++));
	}
	return 0;
}
// 2.ָ��-ָ�� - �õ��м�Ԫ�صĸ���
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	char arr1[5] = { 0 };
	printf("%d\n", &arr[9] - &arr[0]);//9
	printf("%D\n", &arr[9] - &arr1[0]);//error,���δ֪
	return 0;
}


int my_strlen(char* str)
{
	char* start = str;
	char* end = str;
	while (*end != '\0')
	{
		end++;
	}
	return end - start;
}
int main()
{
	//strlen - ���ַ�������
	//�ݹ�ģ��ʵ��strlen - ��������ʽ1���ݹ鷽ʽ2
	char arr[] = "Elysia";
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}
// 3.ָ��Ĺ�ϵ����
#define N 5
int main()
{
	float values[N];
	float* p;
	//1
	for (p = &values[N]; p > &values[0];)
	{
		*--p = 0;
	}
	//2
	/*for (p = &values[N - 1]; p >= &values[0]; p--)
	{
		*p = 0;
	}*/
	return 0;
}
//�������õ�һ��д������Ϊ��׼����֤�ڶ���һ�����У�����������
// ��׼�涨������ָ������Ԫ�ص�ָ����ָ���������һ��Ԫ�غ�����ĸ��ڴ�λ�õ�ָ��Ƚϣ�
//���ǲ�������ָ���һ��Ԫ��֮ǰ���Ǹ��ڴ�λ�õ�ָ����бȽ�

//ָ������� - ͨ��ָ���������
int main()
{
	int arr[10] = { 0 };
	printf("%p\n", arr);//��Ԫ�ص�ַ
	printf("%p\n", arr+1);//+4
	printf("%p\n", &arr[0]);
	printf("%p\n", &arr[0]+1);//+4
	printf("%p\n", &arr);//���������ַ
	printf("%p\n", &arr+1);//+40
	printf("%d\n", sizeof(int* [10]));
	return 0;
}
int main()
{
	int arr[10] = { 0 };
	int* p = arr;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%p ====== %p\n", p + i, &arr[i]);
	}
	for (i = 0; i < 10; i++)
	{
		*(p + i) = i;
		printf("%d\n", *(p + i));
	}
	return 0;
}

//����ָ��
int main()
{
	int a = 10;
	int* pa = &a;//ָ�����Ϊint
	int** ppa = &pa;//ppa - ����ָ�� - ָ�����Ϊint*
	int*** pppa = &ppa;
	*ppa;//pa
	**ppa;//a
	**ppa = 20;
	printf("%d\n", **ppa);//20
	printf("%d\n", a);//20
	return 0;
}

//ָ������ - ���� - ���ָ�������
//����ָ�� - ָ��

int main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	/*int* pa = &a;
	int* pb = &b;
	int* pc = &c;*/
	int* arr[3] = { &a,&b,&c };//����ָ������
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", *(arr[i]));
	}
	return 0;
}

#include <assert.h>
int main()
{
	int* p = NULL;
	assert(p);//���Ժ������ж��Ƿ�Ϊ0����Ϊ0�򱨴���֮���·���
}

//����ָ��ͺ���ָ������
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int main()
{
	int* arr[10];//����ָ�������
	//����ָ������
	/*int(*p1)(int, int) = Add;
	int(*p2)(int, int) = Sub;*/
	
	//����ָ������ - ��ź���ָ�������
	int(*pArr[4])(int, int) = { Add,Sub };//���ͱ���һ��

}

//����ָ���������� - ת�Ʊ�
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
int main()
{
	//����ָ�������
	//ת�Ʊ�
	int(*pfArr[])(int, int) = { 0,Add,Sub,Mul,Div };

	printf("1.add\n2.sub\n3.mul\n4.div\n");
	int input = 0;
	int x = 0;
	int y = 0;
	int ret = 0;
	do
	{
		printf("��ѡ��:>");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("����������������:>");
			scanf("%d %d", &x, &y);
			ret = pfArr[input](x, y);
			printf("%d\n", ret);
		}
		else if (input == 0)
		{
			printf("�˳�������\n");
		}
		else
		{
			printf("�Ƿ����룬����ѡ��\n");
		}
	} while (input);
}

//��

void calc(int(*pf)(int, int))
{
	int x = 0;
	int y = 0;
	int ret = 0;
	printf("����������������:>");
	scanf("%d %d", &x, &y);
	ret = pf(x, y);
	printf("%d\n", ret);
}
int main()
{
	printf("1.add\n2.sub\n3.mul\n4.div\n");
	int input = 0;

	do
	{
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case1:
			calc(Add);
			break;
		case 2:
			calc(Sub);
			break;
		case 3:
			calc(Mul);
			break;
		case 4:
			calc(Div);
			break;
		}
	} while (input);
}
//�ص����� - ͨ������ָ����õĺ��� - �Ϸ���Add,Sub��
//�ص����������ɸú�����ʵ�ַ�ֱ�ӵ��ã��������ض����¼�����������ʱ�������һ�����õģ����ڶԸ��¼�������������Ӧ

//qsort��һ���⺯�������������ݽ������������������������͵�����
void qsort(void* base, //baseָ�������ĵ�һ��Ԫ��
		size_t num,    //numΪ�������Ԫ�ظ���
		size_t size,   //sizeΪ�����������Ԫ�صĴ�С����λ���ֽ�
		int (*compar)(const void*, const void*) //compar��һ������ָ�룬ָ��ĺ����ܹ��Ƚ�����Ԫ��
	);
//qsort������4������

//void* ��ʲô��
//��һ��ָ������

int main()
{
	int a = 10;
	int* p = &a;
	char* pc = &a;//int*----->char* ������

	void* pv = &a;//int*----->void* 
	//�޾������͵�ָ�룬ͨ��ָ������
	//void*���͵�ָ����������Խ��������������͵ĵ�ַ
	pv++;//error����֪���Ӽ����ֽ�
	*pv;//error
	//���ڴ�ŵ�ַ
	return 0;
}

//����qsort������������
int cmp_int(const void* e1, const void* e2) //��������ܹ��Ƚ�e1��e2ָ�������Ԫ�أ����Ҹ�������ֵ
{
	return *(int*)e1 - *(int*)e2;
} //�ص�����
void print_arr(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void test1()
{
	int arr[] = { 3,8,2,8,3,6,9,3,0,1,7,3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print_arr(arr, sz);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	print_arr(arr, sz);
}
int main()
{
	test1();
}