版本一已在Word中有相关说明
版本二相对于版本一:
1.Resources->config->Waves:增加到了十个波次,即共十个关卡.
2.添加了新的类enemy2 enemy3 enemy4 enemy5
新的类只是更改了敌人属性,仍然无法攻击
更改属性:Health_Bar_Width;
    m_maxHp;
    m_currentHp;
    m_walkingSpeed;
    m_sprite;
3.audioplayer.cpp->AudioPlayer::AudioPlayer(QObject *parent)
简化了背景音乐的实现
但是其它声效仍然需要在新的计算机上手动输入文件存放地址才能播放
4.tower.cpp->m_fireRate
; // 50毫秒内击中敌人
  bullet.cpp-> void Bullet::move()-> static const int duration = 50;
从射击速度的1s改为了0.5s每发子弹

后期考虑:一共三个方向
为敌人增加攻击炮塔的效果
->
为炮塔增加拆除和升级操作
->
设计游戏进入界面

版本三:
最终的更改: 
1.新增了三类敌人(Enemy::upgrade4() Enemy::upgrade5() Enemy::upgrade6())
2.绘制了主界面(两个入口,两类模式，mywindow.h mywindow.cpp mybutton.cpp  mybutton.h)
3.绘制了游戏结局界面,多结局(三类)(
void MainWindow::paintEvent(QPaintEvent *)
end2.png win.png end.png
)
4.增加了防御塔升级功能
(
   void MainWindow::mousePressEvent(QMouseEvent *event)
)
5.增加了五个游戏彩蛋
(bool MainWindow::loadWave())
6.优化了画质
(enemy(1-7).png)
7.更改了背景音乐
(Bgmusic.mp3)