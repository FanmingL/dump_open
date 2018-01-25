
pos=my_jieping;
s=serial('com9');
s.BaudRate=115200;
fopen(s);
pause(0.5);
X=[170,175,48,1,0,0];
X=uint8(X);
while 1
    cla
    img=screenShotRGB(pos(1),1600-pos(2)-pos(4),pos(3),pos(4));
    %img=imread('dump.jpg');
    img_hsv=rgb2hsv(img);
    obj=img_hsv(:,:,1)<0.8&img_hsv(:,:,1)>0.6&img_hsv(:,:,2)>0.12&img_hsv(:,:,2)<0.5&img_hsv(:,:,3)<0.6;
    screen=~(img_hsv(:,:,1)<0.8&img_hsv(:,:,1)>0.4&img_hsv(:,:,2)<0.4&img_hsv(:,:,2)>0.08);
    se=strel('disk',6);
    obj=imopen(obj,se);
    
    screen=screen&(~obj);
    screen=imopen(screen,se);
    %if size(screen,1)>(floor(obj_pos(2))+100)

    %else
    %    continue
    % end
    
    
    [row,col]=find(obj);
    if isempty(row)
        continue
    end
    obj_pos=[sum(col)/length(col),sum(row)/length(row)];
    screen_n=screen(1:(floor(obj_pos(2))+80),:);
    obj_n=obj(1:(floor(obj_pos(2))+80),:);
    img_n=img(1:(floor(obj_pos(2))+80),:,:);
    img_n(:,:,1)=double(img_n(:,:,1)).*double(screen_n);
    img_n(:,:,2)=double(img_n(:,:,2)).*double(screen_n);
    img_n(:,:,3)=double(img_n(:,:,3)).*double(screen_n);
     imshow(img_n)
      [row,col]=find(obj_n);
    obj_pos=[sum(col)/length(col),sum(row)/length(row)];
   hold on
    plot(obj_pos(1),obj_pos(2),'marker','.','markersize',50,'color','r')
    %plot(obj_pos(1),obj_pos(2)+50,'marker','.','markersize',10,'color','r')
    [row,col]=find(screen_n);
    [min_row,index]=min(row);
    min_row_col=col(index);
    plot(min_row_col,min_row,'color','b','markersize',20,'marker','.');
    J=abs(obj_pos(1)-min_row_col)/cos(pi/6);
    fprintf(['length is ',num2str(J),'\n']);
    X(5)=uint8(10+J/3);
    sum_t=0;
    for i=1:5
        sum_t=sum_t+double(X(i));
    end
    X(6)=rem(sum_t,255);
    fwrite(s,X(5),'uint8');
    pause(4.5);
end