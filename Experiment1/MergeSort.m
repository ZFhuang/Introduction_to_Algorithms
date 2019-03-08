function ret=MergeSort(inputs)
%递归归并排序 P19下方
ret=mergeSort(inputs,1,length(inputs));
end

function ret=mergeSort(inputs,Start,End)
Mid=floor((Start+End)/2); %向小取整
if Start<End
    inputs=mergeSort(inputs,Start,Mid);
    inputs=mergeSort(inputs,Mid+1,End); %要注意加一使数组不重叠
    inputs=merge(inputs,Start,Mid,End);
end
ret=inputs;
end

function ret= merge(inputs,Start,Mid,End)
n1=Mid-Start+1; %加一来计算正确的大小
n2=End-Mid;
L=inputs(Start:Mid);
R=inputs(Mid+1:End);    %防止重叠
j=1;
k=1;
for i=Start:End
    if j > n1 	%当一个到尾部时，直接拷入另一个
        inputs(i) = R(k);
        k=k+1;
        continue;
    end
    if k > n2
        inputs(i) = L(j);
        j=j+1;
        continue;
    end
    if L(j)<=R(k) 	%选择两个第一个中较小的一个（因为递归使两个小数组都是从小到大排序完成的）
        inputs(i) = L(j);
        j=j+1;
    else
        inputs(i)=R(k);
        k=k+1;
    end
end
ret=inputs;
end