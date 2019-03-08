function ret=PigeonholeSort(inputs)
%鸽巢排序，要求内存足够，数据都是整数且大于零，分布不要太过分散且数据内容不要太大
range=length(inputs);
Max=max(inputs);	%找到最大值作为鸽巢的大小
tic
temp=zeros(Max,1);	%预分配数组
for i=1:range
    temp(inputs(i))=temp(inputs(i))+1;	%将数据计数入鸽巢中
end
toc
pointer=1;	%创建下标指针
tic
range2=length(temp);	
for i=1:range2
    while temp(i)>0	%当计数不为0时，将数据放回结果中
        inputs(pointer)=i;
        pointer=pointer+1;
        temp(i)=temp(i)-1;
    end
end
ret=inputs;
toc
end