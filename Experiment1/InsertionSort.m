function ret=InsertionSort(inputs)
%�������� P10�Ϸ�
for i=2:length(inputs)
    key = inputs(i);	%��Ϊ�Ƚϻ�׼��ֵ����������һ��
    j = i - 1;	%�Ӵ˿�ʼ�Ƚϴӻ�׼��ǰ��ȫ��ֵ
    while j > 0 && inputs(j) > key	%����ǰ���ֵ���Ѿ���С���������ˣ�����ѭ��Ѱ�ҵ�һ���Ȼ�׼ֵС��ֵ�������Ǹ�ֵ�ĺ���
        inputs(j + 1) = inputs(j);	%���ǵ�ֵ����ǰ����һλ��Ϊ��׼ֵ����һ���ռ�
        j=j-1;
    end
    inputs(j + 1) = key;	%����׼ֵ��������
end
ret=inputs;
end