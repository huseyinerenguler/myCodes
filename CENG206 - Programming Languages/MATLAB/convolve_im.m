%% NAME:  Hüseyin Eren Güler
%% ID:    15050111014

function [conv_res] = convolve_im(im, filter)
  %30 points. You need to return convolution result
  conv_res = zeros(size(im,1)-size(filter,1)+1, size(im,2)-size(filter,1)+1);
  
  %% I created a new matrix that is contains image matrix and surrounded by zeros. 
  padImage = padarray(im, [1,1]);
  
  %% These loops for scan to each pixels in image.
  for i = 2: size(padImage,1)-size(filter,1)+0
    for j = 2: size(padImage,2)-size(filter,2)+0
      
      %% First fetch 3x3 matrix from our new matrix that is contains image matrix and surrounded by zeros.
      %% Then I convert to 16-bit integer format. (Because 8 bit has max 255, but our matrix has lots of.)
      %% Finally, I found a temporary matrix by multiplying filter and our image matrix.
      temp = int16(padImage(i:i+size(filter,1)-1, j:j+size(filter,2)-1)) .*flip(filter);    
      
      %% Here, I calculate the sum of elements our temporary matrix.
      sum = 0;
      for x = 1: size(temp,1)
        for y = 1: size(temp,2)
          sum = sum + temp(x,y);
        end
      end
   
      conv_res(i-1,j-1) = sum;  
    end
  end
end