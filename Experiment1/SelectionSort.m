function ret=SelectionSort(inputs)
%选择排序 P16练习2.2-2
for i=1:length(inputs)-1
    min = i;    %最小值默认为第一个
    for j=i+1:length(inputs)
        if inputs(j)<inputs(min)    %找到比当前最小值更小的值
            min=j;  %更新最小值下标
        end
    end
    temp=inputs(i); %进行交换
    inputs(i)=inputs(min);
    inputs(min)=temp;
end
ret=inputs;
end