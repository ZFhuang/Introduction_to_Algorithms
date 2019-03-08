function ret=BubbleSort(inputs)
%Ã°ÅİÅÅĞò P23Ë¼¿¼2-2
for i=1:length(inputs)-1
    for j=1:length(inputs)-1
        if inputs(j)>inputs(j+1)    %ÏñÅİÅİÒ»ÑùÏò´ó¶Ë¸¡¶¯
            temp=inputs(j);
            inputs(j)=inputs(j+1);
            inputs(j+1)=temp;
        end
    end
end
ret=inputs;
end