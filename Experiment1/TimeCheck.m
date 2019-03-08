function ret=TimeCheck(inputs)
%对各种排序方法进行测试
ret=zeros(20,5);    %预分配时间数组空间
for i=1:20
    tic;    %计时开始
    BubbleSort(inputs(:,i));
    ret(i,1)=toc;   %计时结束并写入数组
end
for i=1:20
    tic;
    SelectionSort(inputs(:,i));
    ret(i,2)=toc;
end
for i=1:20
    tic;
    InsertionSort(inputs(:,i));
    ret(i,3)=toc;
end
for i=1:20
    tic;
    MergeSort(inputs(:,i));
    ret(i,4)=toc;
end
for i=1:20
    tic;
    QuickSort(inputs(:,i));
    ret(i,5)=toc;
end
end