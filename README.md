# LenorsUI

Lenor

## 用户接口函数

### PageManager`.h/cpp`

```C++
int newPage();
用于创建一个新的页面，并返回其页面编号
void addContent(int pageNumber, string content,ConsoleForegroundColor FC, ConsoleBackGroundColor BC);
向一个页面中添加内容，pageNumber为其编号，content为内容，FC与BC为内容的文字颜色和背景颜色
void linkPage(int tp, int column, int pageNumber);
添加一条页面跳转规则，tp为当前页面，column为对应的条目，pageNumber为该条目所要跳转的页面编号
void linkFunc(int tp, int column, PF func);
添加一条函数执行规则，tp为当前页面，column为对应的条目，func为要执行的函数。注意，此函数不能有参数或返回值。如果需要参数或返回值请使用全局指针或者包装器。
```

### UI`.h/cpp`

```c++
static void delay(const int &time);
延时一定的时间，单位理论值为毫秒。
void lineAnimation(const string& text, ConsoleForegroundColor FC, ConsoleBackGroundColor BC);
在新的一行动画绘制新的文字，text为对应文字，FC与BC为内容的文字颜色和背景颜色。
void clear();
清除当前UI显示的内容。
void changeColor(int col, ConsoleForegroundColor FC, ConsoleBackGroundColor BC);
更改第col行的颜色，FC与BC为内容的文字颜色和背景颜色。注意，仅使用lineAnimation绘制的文字可以调用此函数。
void textAnimation(int x, int y, const string &text, ConsoleForegroundColor FC, ConsoleBackGroundColor BC);
在屏幕上(x,y)的位置显示一行文字，text为对应文字，FC与BC为内容的文字颜色和背景颜色。
```

## 快速使用

参考`FrmSrc`与使用例，在`FrmSrc`中的`main.cpp`文件中，

`inline void setPage()`中添加新的页面和页面内容。

`inline void setLinkPage()`中添加页面之间的链接。

`inline void setLinkPage()`中添加选项与函数之间的链接。

即可直接使用。