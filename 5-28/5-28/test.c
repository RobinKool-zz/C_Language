#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//int main()
//{
//	//10000000000000000000000000010100
//	//11111111111111111111111111101011
//	//11111111111111111111111111101100
//	//00000000000000000000000000001010
//	//11111111111111111111111111110110
//	//10000000000000000000000000001001
//	//10000000000000000000000000001010
//	return 0;
//}


//void move(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//
//	while (left < right)
//	{
//		while (arr[left] % 2 == 1)
//		{
//			left++;
//		}
//
//		while (arr[right] % 2 == 0)
//		{
//			right--;
//		}
//
//		if (left < right)
//		{
//			int tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//			left++;
//			right--;
//		}
//
//	}
//
//
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//输入
//	for (int i = 0; i < 10; i++)
//	{
//		printf("请输入第%d个数字:", i+1);
//		scanf("%d", &arr[i]);
//	}
//
//
//	//调整
//	move(arr, sz);
//
//	//输出
//	for (int i = 0;i < 10;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}


int main()
{
	// 创建两个数组
	int n = 0;
	int m = 0;
	scanf("%d,%d", &n, &m);
	int arr1[20] = {0};
	int arr2[20] = {0};

}