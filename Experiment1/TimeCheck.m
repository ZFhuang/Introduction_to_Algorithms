function ret=TimeCheck(inputs)
%�Ը������򷽷����в���
ret=zeros(20,5);    %Ԥ����ʱ������ռ�
for i=1:20
    tic;    %��ʱ��ʼ
    BubbleSort(inputs(:,i));
    ret(i,1)=toc;   %��ʱ������д������
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