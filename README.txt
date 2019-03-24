rcp编译说明
一 准备工作
  1）建立用户 rcp
  2）#su - rcp
  3）复制tar.gz包
     $cp rcp-0.0.1.tar.gz .
  4)解包
     $tar zxf rcp-0.0.1.tar.gz
二 编译/安装第三方软件
  1） 编译pcoc库
     $cd ~/rcp-0.0.1/third
     $unzip poco-1.9.1.zip
     $cd poco-1.9.1
     $./configure
     $make all
     $sudo make install
  2) 安装ctp库
     $cd ~/rcp-0.0.1/third
     $unzip SHIF*.zip
     $sudo cp thostmduserapi.so /usr/local/lib/libthostmduserapi.so 
     $sudo cp thostmduserapi.so /usr/local/lib/libthosttraderapi.so
三编译rcp
  $./configure
  $make all
  $sudo make install
