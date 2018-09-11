#include<iostream>
#include"Tools.h"
using namespace std;

///����������� P10�Ϸ�
Array InsertionSort_UP(Array inputs) {
	Array ret(inputs);
	for (int i = 1; i < ret.getLength(); i++) {
		ElementType key = ret.contain[i];	//��Ϊ�Ƚϻ�׼��ֵ����������һ��
		int j = i - 1;	//�Ӵ˿�ʼ�Ƚϴӻ�׼��ǰ��ȫ��ֵ
		while (j >= 0 && ret.contain[j] > key)	//����ǰ���ֵ���Ѿ���С���������ˣ�����ѭ��Ѱ�ҵ�һ���Ȼ�׼ֵС��ֵ�������Ǹ�ֵ�ĺ���
		{
			ret.contain[j + 1] = ret.contain[j];	//���ǵ�ֵ����ǰ����һλ��Ϊ��׼ֵ����һ���ռ�
			--j;
		}
		ret.contain[j + 1] = key;	//����׼ֵ��������
	}
	return ret;
}

///����������� P12��ϰ2.1-2
Array InsertionSort_DOWN(Array inputs) {
	Array ret(inputs);
	for (int i = 1; i < ret.getLength(); i++) {
		ElementType key = ret.contain[i];
		int j = i - 1;
		while (j >= 0 && ret.contain[j] < key)	//����ǰ���ֵ���Ѿ��Ӵ�С�����ˣ�����ѭ��Ѱ�ҵ�һ���Ȼ�׼ֵ���ֵ�������Ǹ�ֵ�ĺ���
		{
			ret.contain[j + 1] = ret.contain[j];
			--j;
		}
		ret.contain[j + 1] = key;
	}
	return ret;
}

///���Բ���v P12��ϰ2.1-3
int FindV(Array inputs, ElementType v) {
	for (int i = 0; i < inputs.getLength(); i++) {
		if (inputs.contain[i] == v) {	//���Բ���
			return i;
		}
	}
	return -1;	//-1 ��ʾNIL
}

///nλ�����������ӷ� P12��ϰ2.1-4
Array BitAddition(Array inputs1, Array inputs2) {
	int length = inputs1.getLength() > inputs2.getLength() ? inputs1.getLength() : inputs2.getLength();
	length += 1;	//��������Ҫ����ԭ���������
	Array ret(length);
	for (int i = 1; i < length; i++) {	//ѭ��������������Ķ�Ӧλ
		if (i - 1 < inputs1.getLength()) {
			ret.contain[i - 1] += inputs1.contain[i - 1];
		}
		if (i - 1 < inputs2.getLength()) {
			ret.contain[i - 1] += inputs2.contain[i - 1];
		}
		if (ret.contain[i - 1] >= 2) {
			ret.contain[i - 1] -= 2;
			ret.contain[i]++;	//��λ
		}
	}
	return ret;
}

///����ѡ������ P16��ϰ2.2-2
Array SelectionSort(Array inputs) {
	Array ret(inputs);
	for (int i = 0; i < ret.getLength() - 1; i++) {	//ѡ������ֻ��Ҫ��ǰn-1��Ԫ�ش�����
		int min = i;	//��������ĵ�һ��Ԫ�ص�����Сֵ
		for (int j = i + 1; j < ret.getLength(); j++) {
			if (ret.contain[j] < ret.contain[min]) {	//�Ƚ���Ѱ����������Сֵ�������±�
				min = j;
			}
		}
		ElementType temp = ret.contain[i];
		ret.contain[i] = ret.contain[min];
		ret.contain[min] = temp;	//���ҵ�����Сֵ��������ĵ�һ��Ԫ�ؽ���
	}
	return ret;
}

///�鲢����Ĺ鲢���� P17�·�
Array Merge(Array inputs, int start, int mid, int end) {
	int n1 = mid - start;	//������ĳ�
	int n2 = end - mid;	//������ĳ�
	Array L(inputs, start, mid);
	Array R(inputs, mid, end);	//����������С����
	int j = 0;
	int k = 0;
	for (int i = start; i < end; i++) {
		if (j >= n1) {	//��һ����β��ʱ��ֱ�ӿ�����һ��
			inputs.contain[i] = R.contain[k];
			k++;
			continue;
		}
		if (k >= n2) {	//ͬ
			inputs.contain[i] = L.contain[j];
			j++;
			continue;
		}
		if (L.contain[j] <= R.contain[k]) {	//ѡ��������һ���н�С��һ������Ϊ�ݹ�ʹ����С���鶼�Ǵ�С����������ɵģ�
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

///����鲢������Ҫ�ݹ飬�������ķֺ��� P19�·�
Array MergeSort(Array inputs, int start, int end) {
	int mid = (end + start) / 2;	//��ȡ�е�λ��

	if (start < mid) {
		inputs = MergeSort(inputs, start, mid);	//���ֵݹ�����
		inputs = MergeSort(inputs, mid, end);
		inputs = Merge(inputs, start, mid, end);	//����������һ��
	}
	return inputs;
}

///���ֲ���v P22��ϰ2.3-5
int FindV_Binary(Array inputs, ElementType v) {	//��Ҫ���Ѿ�����õ�����
	int start = 0;
	int end = inputs.getLength();
	for (int i = 0; i < inputs.getLength() / 2 + 1; i++) {	//�����������
		int mid = (start + end) / 2;	//��������
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
	return -1;	//-1 ��ʾNIL
}

///ð������ P23˼��2-2
Array BubbleSort(Array inputs) {
	for (int i = 0; i < inputs.getLength();i++) {
		for (int j = 0; j < inputs.getLength()-1; j++) {
			if (inputs.contain[j] > inputs.contain[j+1]) {	//������һ�����ϸ���
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