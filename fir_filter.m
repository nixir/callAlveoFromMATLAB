function myFunc = fir_filter(dataIn, b)
disp(b)
myFunc = zeros(length(dataIn),1);
for index = 1:length(dataIn)
    if index < 4
        myFunc(index) = 0;
    else
        myFunc(index) = (b(1)*dataIn(index) + b(2)*dataIn(index - 1) + b(3)*dataIn(index - 2) + b(4)*dataIn(index -3));
   %     myFunc(index) = myFunc(index);
    end
end
end