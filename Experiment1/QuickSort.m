function ret=QuickSort(inputs)
%�ݹ�������� P95�·�
ret=quickSort(inputs,1,length(inputs));
end

function ret=quickSort(inputs,Start,End)
if Start<End
    [Mid,inputs]=partition(inputs,Start,End);   %�õ������±�
    inputs=quickSort(inputs,Start,Mid-1);   %�ݹ�
    inputs=quickSort(inputs,Mid+1,End);
end
ret=inputs;
end

function [Mid,ret]=partition(inputs,Start,End)
pivot=inputs(End);  %ȡ���һ��Ԫ����Ϊ��Ԫ
i=Start-1;  %�����±�һ��ʼ�궨�����鿪ͷ
for j=Start:End-1   %����
    if inputs(j)<=pivot %ÿ������С�ڵ�����Ԫʱ
        i=i+1;  %���û����±꽫�仮������
        temp=inputs(j); %��������
        inputs(j)=inputs(i);
        inputs(i)=temp;
    end
end
temp=inputs(i+1);   %�������߶���С����Ԫ����
inputs(i+1)=inputs(End);    %Ȼ����Ԫ�����м�
inputs(End)=temp;   %�����Ұ벿���Ǵ�����Ԫ������

Mid=i+1;    %���ջ����±�Ϊ��Ԫ�±�
ret=inputs;
end