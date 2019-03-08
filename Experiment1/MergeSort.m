function ret=MergeSort(inputs)
%�ݹ�鲢���� P19�·�
ret=mergeSort(inputs,1,length(inputs));
end

function ret=mergeSort(inputs,Start,End)
Mid=floor((Start+End)/2); %��Сȡ��
if Start<End
    inputs=mergeSort(inputs,Start,Mid);
    inputs=mergeSort(inputs,Mid+1,End); %Ҫע���һʹ���鲻�ص�
    inputs=merge(inputs,Start,Mid,End);
end
ret=inputs;
end

function ret= merge(inputs,Start,Mid,End)
n1=Mid-Start+1; %��һ��������ȷ�Ĵ�С
n2=End-Mid;
L=inputs(Start:Mid);
R=inputs(Mid+1:End);    %��ֹ�ص�
j=1;
k=1;
for i=Start:End
    if j > n1 	%��һ����β��ʱ��ֱ�ӿ�����һ��
        inputs(i) = R(k);
        k=k+1;
        continue;
    end
    if k > n2
        inputs(i) = L(j);
        j=j+1;
        continue;
    end
    if L(j)<=R(k) 	%ѡ��������һ���н�С��һ������Ϊ�ݹ�ʹ����С���鶼�Ǵ�С����������ɵģ�
        inputs(i) = L(j);
        j=j+1;
    else
        inputs(i)=R(k);
        k=k+1;
    end
end
ret=inputs;
end