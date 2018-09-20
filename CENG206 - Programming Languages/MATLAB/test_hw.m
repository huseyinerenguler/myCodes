%DO NOT MODIFY THE FUNCTION  BELOW
function [] = test_hw ()
  %if you are using matlab comment below line
  pkg load image;
  
  total_grade=0;
  
  %read image
  img = imread('puppy.jpeg');
  
  
  conv_ok =1;
  
  test_filter=[0 -1 0; -1 4 -1; 0 -1 0]; %laplace filter 3x3
  conv_res = convolve_im(img, test_filter);
  ground_res = conv2(img,test_filter, 'valid');
  check = abs(ground_res) - abs(conv_res);
  if sum(abs(check(:,:))) ==0
    disp('Convolution for 3x3 works fine.');
  else
    conv_ok = 0;
    disp('Convolution part is wrong for 3x3!!!');
  end
   
   %read image
  img = imread('puppy.jpeg');
  
  test_filter=[0 0 -1 0 0; 0 -1 -1 -1 0; -1 -1 12 -1 -1; 0 -1 -1 -1 0; 0 0 -1 0 0]; %5x5
  conv_res = convolve_im(img, test_filter);
  ground_res = conv2(img,test_filter, 'valid');
  check = abs(ground_res) - abs(conv_res);
  
  if sum(abs(check(:,:))) ==0
    disp('Convolution for 5x5 works fine.');
  else
    conv_ok = 0;
    disp('Convolution part is wrong for 5x5!!!');
  end
  
  if(conv_ok ==1)
    disp('Congratulations. You got 30 points from convolution.');
    total_grade += 30;
  
  end
  
  
  %TEST histogram
  %read image again
  img = imread('puppy.jpeg');
  ground_hist = imhist(img);
  user_hist= image_histogram(img);
  check = ground_hist-user_hist;
  if(sum(check)==0)
    disp('Congratulations. You did histogram part. Got 25 points.');
    total_grade += 25;
  else
    disp('Histogram part is wrong! Try to make it correct. ');
  end
  
  
  % TEST eigen values
  eigen_mat= [0 1; -2 -3];
  [V,D] = eig(eigen_mat);
  user_eigen= eigen_val(eigen_mat);
  check  = abs(V)-abs(user_eigen);
  if sum(check(:,:) <0.3)
    disp('Congratulations, eigen part is OK. You got 25 points');
    total_grade += 25;    
  else
    disp('Eigen part is wrong. Try to make it correct. ');
  end
  
  % TEST FUNCTION
  a= [1 2 3; 3 2 1; 4 5 6];
  b= [5; 4; -1];
  c= [-1 2 -1];
  
  ground_res = [24.0183 30.0000 29.3891;13.0183 21.0000 22.3891;-2.9817 12.0000 2.3891];
  user_res =perform_math(a,b,c);
  check = abs(user_res) - abs(ground_res);
  if sum(abs(check(:,:)))< 0.2
    disp('Congratulations. You did math part.');
    total_grade+= 20;
  else
    disp('Your function for math operation did wrong. Please make it correct!');
  end
  
  disp('Your final grade is : ');
  disp( total_grade );
  
  
end

