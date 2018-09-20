%% NAME:  Hüseyin Eren Güler
%% ID:    15050111014

function [hist] = image_histogram(img)
  %25 points. You need to find histogram of 2D a single channel image
  hist=zeros(256,1);
  
  %% This loop is from 1 to number of rows in img matrix.
  for x=1:size(img,1)
    %% This loop is from 1 to number of columns in img matrix.
    for y=1:size(img,2)
      %% I found the value in the specified pixel in the image.
      pixelValue=img(x,y);
      %% Then I add to histogram array by added 1.
      hist(pixelValue+1)+=1;
    end
  end
end