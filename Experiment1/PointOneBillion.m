function ret=PointOneBillion(inputs,big)
%��ĳ��ģ�������зֿ��������
Range=ceil(length(inputs)/big); %������ֿ������
temp=zeros(big,Range);  %Ԥ�����ڴ�
for i=1:Range
    temp(:,i)=inputs(big*(i-1)+1:big*i);    %�ֿ�
end
tic
parfor i=1:Range
    temp(:,i)=QuickSort(temp(:,i)); %��������
    %temp(:,i)=sort(temp(:,i)); %���õ�������
end
toc
tic
pointer=ones(Range,1);  %����ÿһ�鱣��һ���±�ָ��
pointer=pointer(:); %תΪ������
line=temp(1,:); %���ڶԱ�ÿ����Сֵ�Ķ���
line=line(:);
for i=1:length(inputs)
    [inputs(i),index]=min(line);    %�ҵ������е���Сֵ
    pointer(index)=pointer(index)+1;    %ָ���һ
    if pointer(index)>big
        line(index)=100;    %��������һ����丳ֵΪһ���ܴ������Ϊ��β
    else
        line(index)=temp(pointer(index),index); %��������������µ���ֵ
    end
end
ret=inputs;
toc
end