%% NAME:  Hüseyin Eren Güler
%% ID:    15050111014

function result = perform_math(a,b,c)
  result = zeros(size(a,1),size(a,2));
  for x=1:size(result,1)
    for y=1:size(result,2)
      result(x,y)=(b(x)*b(x))+(a(x,y)*c(y))+exp((c(y)*c(y))-b(y));
    end
  end
end