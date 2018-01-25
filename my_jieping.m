function answer=my_jieping
 im=screenShotRGB;
 imshow(im);
 [answer(1),answer(2)]=ginput(1);
 [x,y]=ginput(1);
 answer(3)=x-answer(1);
 answer(4)=y-answer(2);
 answer=fix(answer);
 close all