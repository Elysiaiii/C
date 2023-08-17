#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//指针是个变量，存放内存单元的地址（编号）
int main()
{
	int a = 10;//在内存中开辟一块空间
	int* p = &a;//对变量a，取出它的地址，用&操作符
	//将a的地址存放在p变量中，p就是一个指针变量
	return 0;
}
//总结：指针就是变量，用来存放地址的变量（存放在指针中发值都被当成地址处理）

//指针32位4字节，64位8字节
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
	int a = 0x11223344;//0x - 16进制标志
	int* pa = &a;
	char* pc = &a;

	printf("%p\n", pa);
	printf("%p\n", pc);//两个相同

	return 0;
}

int main()
{
	int a = 0x11223344;
	//int* pa = &a;
	//*pa = 0;//a四个字节都变成0
	char* pa = &a;
	*pa = 0;//a第一个字节变成0
	return 0;
}//指针类型的意义：
// 1.指针类型决定了指针进行解引用操作的时候，能够访问的空间的大小
//不同类型指针解引用时结果不一样，int类型指针解引用时能操作四个字节，char只有一个
//int* p; *p能访问4个字节
//char* p;  *p能够访问1个字节
//double* p;  *p能够访问8个字节
//
int main()
{
	int a = 0x11223344;
	int* pa = &a;
	char* pc = &a;
	printf("%p\n", pa);
	printf("%p\n", pa+1);//+4个字节

	printf("%p\n", pc);
	printf("%p\n", pc+1);//+1个字节
	return 0;
}
// 2.指针类型决定指针走一步走多远（指针的步长）
//int* p;  p + 1 -> 4
//char* p;  p + 1 -> 1
//double* p;  p + 1 -> 8

//例子
int main()
{
	int arr[10] = { 0 };
	int* p = arr;//数组名 - (大部分)首元素地址
	// 1.&arr - 数组名表示整个数组 - &数组名取出整个数组的地址
	// 2.sizeof(arr) - sizeof(数组名) - 数组名表示整个数组 - 计算整个数组大小
	for (int i = 0; i < 10; i++)
	{
		*(p + i) = 1;//int数组，单个数组元素占4个字节，所以int类型指针+1正好指向下一个元素
	}
	return 0;
}

//野指针 - 指针指向位置不可知
// 1.指着未初始化
int main()
{
	int a;//局部变量不初始化，默认是随机值
	int* p;//局部的指针变量，就被初始化随机值
	*p = 20;//随机找内存空间，so dangerous
	return 0;
}
// 2.指针越界访问
int main()
{
	int arr[10] = { 0 };
	int* p = arr;
	for (int i = 0; i < 12; i++)
	{
		*p++ = i;//p超出数组范围时成为野指针
		//*p = i
		//P++
	}
	return 0;
}
// 3.指针指向的内存空间释放
int* test()
{
	int a = 10;
	return &a;
}
int main()
{
	int* p = test();
	printf("%d\n", *p);//test函数结束内存空间释放，a的空间已经释放，*p指了个空气
	return 0;
}

int main()
{
	//int* p = NULL;//NULL - 用来初始化指针，给指针赋值（不知道让指针指什么，赋值防止出现野指针）
	////   空指针
	int a = 10;
	int* pa = &a;
	*pa = 20;
	//用完无效化指针
	pa = NULL;
	*pa = 0;//error
	if (pa != NULL)//判断此时指针能不能用,检测有效性
	{
	};
	return 0;
}

//指针运算
// 1.指针+-整数
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
// 2.指针-指针 - 得到中间元素的个数
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	char arr1[5] = { 0 };
	printf("%d\n", &arr[9] - &arr[0]);//9
	printf("%D\n", &arr[9] - &arr1[0]);//error,结果未知
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
	//strlen - 求字符串长度
	//递归模拟实现strlen - 计数器方式1，递归方式2
	char arr[] = "Elysia";
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}
// 3.指针的关系运算
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
//尽量采用第一种写法，因为标准不保证第二种一定可行（看编译器）
// 标准规定：允许指向数组元素的指针与指向数组最后一个元素后面的哪个内存位置的指针比较，
//但是不允许与指向第一个元素之前的那个内存位置的指针进行比较

//指针和数组 - 通过指针访问数组
int main()
{
	int arr[10] = { 0 };
	printf("%p\n", arr);//首元素地址
	printf("%p\n", arr+1);//+4
	printf("%p\n", &arr[0]);
	printf("%p\n", &arr[0]+1);//+4
	printf("%p\n", &arr);//整个数组地址
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

//二级指针
int main()
{
	int a = 10;
	int* pa = &a;//指向对象为int
	int** ppa = &pa;//ppa - 二级指针 - 指向对象为int*
	int*** pppa = &ppa;
	*ppa;//pa
	**ppa;//a
	**ppa = 20;
	printf("%d\n", **ppa);//20
	printf("%d\n", a);//20
	return 0;
}

//指针数组 - 数组 - 存放指针的数组
//数组指针 - 指针

int main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	/*int* pa = &a;
	int* pb = &b;
	int* pc = &c;*/
	int* arr[3] = { &a,&b,&c };//整型指针数组
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
	assert(p);//断言函数，判断是否为0，若为0则报错，反之无事发生
}

//函数指针和函数指针数组
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
	int* arr[10];//整型指针的数组
	//函数指针数组
	/*int(*p1)(int, int) = Add;
	int(*p2)(int, int) = Sub;*/
	
	//函数指针数组 - 存放函数指针的数组
	int(*pArr[4])(int, int) = { Add,Sub };//类型必须一样

}

//函数指针数组作用 - 转移表
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
	//函数指针的数组
	//转移表
	int(*pfArr[])(int, int) = { 0,Add,Sub,Mul,Div };

	printf("1.add\n2.sub\n3.mul\n4.div\n");
	int input = 0;
	int x = 0;
	int y = 0;
	int ret = 0;
	do
	{
		printf("请选择:>");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("请输入两个操作数:>");
			scanf("%d %d", &x, &y);
			ret = pfArr[input](x, y);
			printf("%d\n", ret);
		}
		else if (input == 0)
		{
			printf("退出计算器\n");
		}
		else
		{
			printf("非法输入，重新选择\n");
		}
	} while (input);
}

//或

void calc(int(*pf)(int, int))
{
	int x = 0;
	int y = 0;
	int ret = 0;
	printf("请输入两个操作数:>");
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
		printf("请选择:>");
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
//回调函数 - 通过函数指针调用的函数 - 上方的Add,Sub等
//回调函数不是由该函数的实现方直接调用，而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或条件进行响应

//qsort是一个库函数，用来对数据进行排序，它可以排序任意类型的数据
void qsort(void* base, //base指向待排序的第一个元素
		size_t num,    //num为待排序的元素个数
		size_t size,   //size为待排序的数组元素的大小，单位是字节
		int (*compar)(const void*, const void*) //compar是一个函数指针，指向的函数能够比较两个元素
	);
//qsort函数有4个参数

//void* 是什么？
//是一种指针类型

int main()
{
	int a = 10;
	int* p = &a;
	char* pc = &a;//int*----->char* 不合适

	void* pv = &a;//int*----->void* 
	//无具体类型的指针，通用指针类型
	//void*类型的指针变量，可以接受任意数据类型的地址
	pv++;//error，不知到加几个字节
	*pv;//error
	//用于存放地址
	return 0;
}

//测试qsort排序整型数组
int cmp_int(const void* e1, const void* e2) //这个函数能够比较e1和e2指向的两个元素，并且给出返回值
{
	return *(int*)e1 - *(int*)e2;
} //回调函数
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