function ret=BubbleSort(inputs)
%ð������ P23˼��2-2
for i=1:length(inputs)-1
    for j=1:length(inputs)-1
        if inputs(j)>inputs(j+1)    %������һ�����˸���
            temp=inputs(j);
            inputs(j)=inputs(j+1);
            inputs(j+1)=temp;
        end
    end
end
ret=inputs;
end