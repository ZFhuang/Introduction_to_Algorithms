#include<iostream>
#include"Tools.h"
using namespace std;

///升序插入排序 P10上方
Array InsertionSort_UP(Array inputs) {
	Array ret(inputs);
	for (int i = 1; i < ret.getLength(); i++) {
		ElementType key = ret.contain[i];	//作为比较基准的值，遍历数组一次
		int j = i - 1;	//从此开始比较从基准往前的全部值
		while (j >= 0 && ret.contain[j] > key)	//由于前面的值都已经从小到大排序了，所以循环寻找第一个比基准值小的值，插入那个值的后面
		{
			ret.contain[j + 1] = ret.contain[j];	//不是的值就往前面排一位，为基准值挤出一个空间
			--j;
		}
		ret.contain[j + 1] = key;	//将基准值排入数组
	}
	return ret;
}

///降序插入排序 P12练习2.1-2
Array InsertionSort_DOWN(Array inputs) {
	Array ret(inputs);
	for (int i = 1; i < ret.getLength(); i++) {
		ElementType key = ret.contain[i];
		int j = i - 1;
		while (j >= 0 && ret.contain[j] < key)	//由于前面的值都已经从大到小排序了，所以循环寻找第一个比基准值大的值，插入那个值的后面
		{
			ret.contain[j + 1] = ret.contain[j];
			--j;
		}
		ret.contain[j + 1] = key;
	}
	return ret;
}

///线性查找v P12练习2.1-3
int FindV(Array inputs, ElementType v) {
	for (int i = 0; i < inputs.getLength(); i++) {
		if (inputs.contain[i] == v) {	//线性查找
			return i;
		}
	}
	return -1;	//-1 表示NIL
}

///n位二进制整数加法 P12练习2.1-4
Array BitAddition(Array inputs1, Array inputs2) {
	int length = inputs1.getLength() > inputs2.getLength() ? inputs1.getLength() : inputs2.getLength();
	length += 1;	//申请数组要大于原来的最大者
	Array ret(length);
	for (int i = 1; i < length; i++) {	//循环加上两个数组的对应位
		if (i - 1 < inputs1.getLength()) {
			ret.contain[i - 1] += inputs1.contain[i - 1];
		}
		if (i - 1 < inputs2.getLength()) {
			ret.contain[i - 1] += inputs2.contain[i - 1];
		}
		if (ret.contain[i - 1] >= 2) {
			ret.contain[i - 1] -= 2;
			ret.contain[i]++;	//进位
		}
	}
	return ret;
}

///升序选择排序 P16练习2.2-2
Array SelectionSort(Array inputs) {
	Array ret(inputs);
	for (int i = 0; i < ret.getLength() - 1; i++) {	//选择排序只需要对前n-1个元素处理即可
		int min = i;	//将子数组的第一个元素当作最小值
		for (int j = i + 1; j < ret.getLength(); j++) {
			if (ret.contain[j] < ret.contain[min]) {	//比较来寻找真正的最小值并保存下标
				min = j;
			}
		}
		ElementType temp = ret.contain[i];
		ret.contain[i] = ret.contain[min];
		ret.contain[min] = temp;	//将找到的最小值和子数组的第一个元素交换
	}
	return ret;
}

///归并排序的归并部分 P17下方
Array Merge(Array inputs, int start, int mid, int end) {
	int n1 = mid - start;	//左数组的长
	int n2 = end - mid;	//右数组的长
	Array L(inputs, start, mid);
	Array R(inputs, mid, end);	//拷贝得两个小数组
	int j = 0;
	int k = 0;
	for (int i = start; i < end; i++) {
		if (j >= n1) {	//当一个到尾部时，直接拷入另一个
			inputs.contain[i] = R.contain[k];
			k++;
			continue;
		}
		if (k >= n2) {	//同
			inputs.contain[i] = L.contain[j];
			j++;
			continue;
		}
		if (L.contain[j] <= R.contain[k]) {	//选择两个第一个中较小的一个（因为递归使两个小数组都是从小到大排序完成的）
			inputs.contain[i] = L.contain[j];
			j++;
		}
		else {
			inputs.contain[i] = R.contain[k];
			k++;
		}
	}
	return inputs;
}

///升序归并排序，需要递归，配合上面的分函数 P19下方
Array MergeSort(Array inputs, int start, int end) {
	int mid = (end + start) / 2;	//获取中点位置

	if (start < mid) {
		inputs = MergeSort(inputs, start, mid);	//二分递归排序
		inputs = MergeSort(inputs, mid, end);
		inputs = Merge(inputs, start, mid, end);	//最终整合在一起
	}
	return inputs;
}

///二分查找v P22练习2.3-5
int FindV_Binary(Array inputs, ElementType v) {	//需要是已经排序好的数组
	int start = 0;
	int end = inputs.getLength();
	for (int i = 0; i < inputs.getLength() / 2 + 1; i++) {	//最大搜索次数
		int mid = (start + end) / 2;	//二分搜索
		if (v > inputs.contain[mid]) {
			start = mid;
			continue;
		}
		else if (v < inputs.contain[mid]) {
			end = mid;
			continue;
		}
		else {
			return mid;
		}
	}
	return -1;	//-1 表示NIL
}

///冒泡排序 P23思考2-2
Array BubbleSort(Array inputs) {
	for (int i = 0; i < inputs.getLength();i++) {
		for (int j = 0; j < inputs.getLength()-1; j++) {
			if (inputs.contain[j] > inputs.contain[j+1]) {	//像泡泡一样向上浮起
				ElementType temp = inputs.contain[j];
				inputs.contain[j] = inputs.contain[j + 1];
				inputs.contain[j + 1] = temp;
			}
		}
	}
	return inputs;
}

int main() {
	ElementType target[] = { 816,6,41,652,3,2,54,6,6154,5,6,111,230,13,134,565 };
	int length = sizeof(target) / sizeof(target[0]);
	Array targetA(target, length);

	cout << InsertionSort_UP(targetA) << endl;
	cout << InsertionSort_DOWN(targetA) << endl;
	cout << FindV(targetA, 6) << endl;

	ElementType num1[] = { 1,1,1,1,1 };
	ElementType num2[] = { 1,1,1 };
	Array Num1(num1, 5);
	Array Num2(num2, 3);

	cout << BitAddition(Num1, Num2).reverse() << endl;
	cout << SelectionSort(targetA) << endl;
	cout << MergeSort(targetA, 0, targetA.getLength()) << endl;

	Array targetB(MergeSort(targetA, 0, targetA.getLength()));
	cout << targetB << endl;
	cout << FindV(targetB, 6) << endl;
	cout << BubbleSort(targetA) << endl;

	return 0;
}