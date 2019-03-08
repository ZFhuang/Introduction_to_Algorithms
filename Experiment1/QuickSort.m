function ret=QuickSort(inputs)
%递归快速排序 P95下方
ret=quickSort(inputs,1,length(inputs));
end

function ret=quickSort(inputs,Start,End)
if Start<End
    [Mid,inputs]=partition(inputs,Start,End);   %得到划分下标
    inputs=quickSort(inputs,Start,Mid-1);   %递归
    inputs=quickSort(inputs,Mid+1,End);
end
ret=inputs;
end

function [Mid,ret]=partition(inputs,Start,End)
pivot=inputs(End);  %取最后一个元素作为主元
i=Start-1;  %划分下标一开始标定在数组开头
for j=Start:End-1   %遍历
    if inputs(j)<=pivot %每次有数小于等于主元时
        i=i+1;  %利用划分下标将其划入左半边
        temp=inputs(j); %交互划入
        inputs(j)=inputs(i);
        inputs(i)=temp;
    end
end
temp=inputs(i+1);   %至此左半边都是小于主元的数
inputs(i+1)=inputs(End);    %然后将主元换入中间
inputs(End)=temp;   %于是右半部都是大于主元的数了

Mid=i+1;    %最终划分下标为主元下标
ret=inputs;
end