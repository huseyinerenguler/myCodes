%% NAME:  Hüseyin Eren Güler
%% ID:    15050111014

function [eigen_values] = eigen_val(mat1)
  %25 points. You need only find eigen values. You do not need to find vectors.
  eigen_values=zeros(size(mat1,1), size(mat1,2));
  
  % mat1 = [a b ; c d]
   
  a = mat1(1,1);
  b = mat1(1,2);
  c = mat1(2,1);
  d = mat1(2,2);
  
  
  %% Determinant of our matrix and I matrix is zero. So roots are;
  x1 = (a+d + sqrt(((a-d)*(a-d)) + (4*b*c))) / 2;
  x2 = (a+d - sqrt(((a-d)*(a-d)) + (4*b*c))) / 2;
  
  V1 = -d + x1 - b;
  V2 = a - x1 + c;
  V3 = b;
  V4 = a + x2;
  
  %% k1 and k2 are arbitrary constant.
  k1 = 1;
  k2 = 3;
  
  eigen_values(1,1) = V1*k1;
  eigen_values(1,2) = V3*k2;
  eigen_values(2,1) = V2*k1;
  eigen_values(2,2) = V4*k2;
  
end