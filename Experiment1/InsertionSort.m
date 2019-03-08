function ret=InsertionSort(inputs)
%插入排序 P10上方
for i=2:length(inputs)
    key = inputs(i);	%作为比较基准的值，遍历数组一次
    j = i - 1;	%从此开始比较从基准往前的全部值
    while j > 0 && inputs(j) > key	%由于前面的值都已经从小到大排序了，所以循环寻找第一个比基准值小的值，插入那个值的后面
        inputs(j + 1) = inputs(j);	%不是的值就往前面排一位，为基准值挤出一个空间
        j=j-1;
    end
    inputs(j + 1) = key;	%将基准值排入数组
end
ret=inputs;
end