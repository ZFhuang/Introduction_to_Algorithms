function ret=SelectionSort(inputs)
%ѡ������ P16��ϰ2.2-2
for i=1:length(inputs)-1
    min = i;    %��СֵĬ��Ϊ��һ��
    for j=i+1:length(inputs)
        if inputs(j)<inputs(min)    %�ҵ��ȵ�ǰ��Сֵ��С��ֵ
            min=j;  %������Сֵ�±�
        end
    end
    temp=inputs(i); %���н���
    inputs(i)=inputs(min);
    inputs(min)=temp;
end
ret=inputs;
end