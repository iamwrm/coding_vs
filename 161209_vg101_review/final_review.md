# vg101 final




## 一把包括所有的头文件
```
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdlib>
```






## 使用流来分隔一行的多个单词
```
#include <sstream>

string line, word;
getline(cin, line);
stringstream stream(line);
vector<string> v;
while (stream >> word)
	{		
		cout << word << endl;
		v.push_back(word);
	}
sort(v.begin(), v.end());

```


用``endl`` 代替 `` \n ``

函数重载

## extern
可以不用


## getline
返回值	两类参数表
```
istream& getline (istream& is, string& str, char delim); // end when find delim
istream& getline (istream& is, string& str);
```




## vector
push_back()


## 实现复数类

TODO:自己实现复数类，带上operator overlording
``my_complex.cpp``
## new 和 delete

delete[]	释放数组

## operator

一元和二元
（一定要实现）
复习slide


## file IO
```
fstream database_file_in;
database_file_in.open("test.txt", std::ostream::in);
```

## reverse
find
sort
自带函数


## bmp
会用jigang的代码 save load
example code


## 关键 字符处理

## algorithm 库函数中的自带函数
find
sort
reverse

# 成员函数
vector

string

# vector 
## iterator
```
s.begin();
s.end();
```
## member function
```
s.size();
s.length();
s.clear();	//清空

s[];
s.at();
s.back();
s.front();

```

`` swap(s1,s2)`` 交换两个string



## 例题
去年的题是自己实现rational number

## 例题 for 最后一题
自定义类
矩阵
Mat(row,column)
实现加法
元素存成private
把矩阵 逐行 print 出来
(实现一个自己的类)

## TODO
自己实现 complex string matrix 

# iterator
使用 it 来下标访问，遍历、



