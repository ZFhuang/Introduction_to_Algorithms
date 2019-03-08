function ret=PointOneBillion(inputs,big)
%对某规模的数进行分块快速排序
Range=ceil(length(inputs)/big); %计算出分块的数量
temp=zeros(big,Range);  %预分配内存
for i=1:Range
    temp(:,i)=inputs(big*(i-1)+1:big*i);    %分块
end
tic
parfor i=1:Range
    temp(:,i)=QuickSort(temp(:,i)); %快速排序
    %temp(:,i)=sort(temp(:,i)); %内置的排序函数
end
toc
tic
pointer=ones(Range,1);  %对于每一组保存一个下标指针
pointer=pointer(:); %转为列优先
line=temp(1,:); %用于对比每组最小值的队列
line=line(:);
for i=1:length(inputs)
    [inputs(i),index]=min(line);    %找到队列中的最小值
    pointer(index)=pointer(index)+1;    %指针加一
    if pointer(index)>big
        line(index)=100;    %当遍历完一组后将其赋值为一个很大的数作为结尾
    else
        line(index)=temp(pointer(index),index); %否则给队列输入新的数值
    end
end
ret=inputs;
toc
end