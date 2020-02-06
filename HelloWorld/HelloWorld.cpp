/*
1.三个类以上
2.继承，多态，虚函数
3.重载
4.静态成员
5.菜单选项
*/
#include<iostream>
#include<fstream>
#include<windows.h>
#include<cmath>
#include<algorithm>
using namespace std;
const double PI = acos(-1);
class Plane       //平面图形类
{
public:
	Plane()          //构造函数
	{
	}
	~Plane()         //析构函数
	{
	}
	virtual double Result()   //虚函数
	{
		return 0;
	}
	double r;
};
class Circular :public Plane    //继承
{
public:
	Circular() :Plane()
	{
	}
	void Getdata(double n)
	{
		r = n;
		area = -1;
		perimeter = -1;
	}
	double Result(int k)
	{
		return 2 * r * PI;
	}
	double Result()        //函数重载
	{
		return PI * r * r;
	}
	friend bool operator < (Circular c1, Circular c2)   //运算符重载
	{
		return c1.area < c2.area;
	}
	~Circular()
	{
	};
	double r;
	double area;
	double perimeter;
	static int num;   //静态成员变量
};
class rectangle :public Plane
{
public:
	rectangle() :Plane()
	{
	}
	void Getdata(double n, double j)
	{
		r = n;
		h = j;
		area = -1;
		perimeter = -1;

	}
	double Result(int k)
	{
		return (r + h) * 2;
	}
	double Result()        //函数重载
	{
		return r * h;
	}
	friend bool operator < (rectangle c1, rectangle c2)   //运算符重载
	{
		return c1.area < c2.area;
	}
	~rectangle()
	{
	};
	double r, h;
	double area;
	double perimeter;
	static int num;   //静态成员变量
};

class Solid    //立体图形类
{
public:
	Solid()
	{
	}
	Solid(double n)
	{
		r = n;
	}
	~Solid()
	{
	}
	double r;
};

class Ball :public Solid
{
public:
	Ball() :Solid()
	{
	}
	void Getdata(double n)
	{
		r = n;
		area = -1;
		volume = -1;
	}
	double Result()
	{
		return 4 * PI * r * r;
	}
	double Result(int k)        //函数重载
	{
		return r * PI * PI * PI * 4 / 3;
	}
	friend bool operator < (Ball c1, Ball c2)   //运算符重载
	{
		return c1.area < c2.area;
	}
	~Ball()
	{
	};
	double r;
	double area;
	double volume;
	static int num;   //静态成员变量
};

class Cuboid :public Solid
{
public:
	Cuboid() :Solid()
	{
	}
	void Getdata(double n, double q, double p)
	{
		r = n;
		w = q;
		h = p;
		area = -1;
		volume = -1;
	}
	double Result()
	{
		return r * w * 2 + w * h * 2 + r * h * 2;
	}
	double Result(int k)        //函数重载
	{
		return r * w * h;
	}
	friend bool operator < (Cuboid c1, Cuboid c2)   //运算符重载
	{
		return c1.area < c2.area;
	}
	~Cuboid()
	{
	};
	double r, h, w;
	double area;
	double volume;
	static int num;   //静态成员变量
};
Circular cir[100];
rectangle rec[100];
Ball Bal[100];
Cuboid cub[100];
int Circular::num = 0;
int rectangle::num = 0;
int Ball::num = 0;
int Cuboid::num = 0;

void f1()
{
	double r;
	while (1)
	{
		system("pause");
		system("cls");
		int n;
		cout << "1.求面积\t2.求周长\n3.排序\t\t4.退出\n请输入选择:";
		cin >> n;
		if (n <= 2)
		{
			cout << "请输入圆的半径:";
			cin >> r;
			cir[cir[0].num].Getdata(r);
		}
		if (n == 1)
		{
			cir[cir[0].num].area = cir[cir[0].num].Result();
			cout << "面积为: " << cir[cir[0].num].area << endl;
		}
		else if (n == 2)
		{
			cir[cir[0].num].perimeter = cir[cir[0].num].Result(1);
			cout << "周长为: " << cir[cir[0].num].perimeter << endl;
		}
		else if (n == 3)
		{
			for (int i = 0; i < cir[0].num - 1; i++)
			{
				for (int j = 0; j < cir[0].num - 1 - i; j++)
				{
					if (cir[j] < cir[j + 1])        //运算符已重载 比较的是面积
					{
						swap(cir[j], cir[j + 1]);
					}
				}
			}
			cout << "所有圆按面积排序后为:" << endl;
			for (int i = 0; i < cir[0].num; i++)
			{
				cout << "半径:" << cir[i].r << "  面积:";
				if (cir[i].area != -1)
				{
					cout << cir[i].area << " 周长:";
				}
				else
				{
					cout << "未计算  周长:";
				}
				if (cir[i].perimeter != -1)
				{
					cout << cir[i].perimeter << endl;
				}
				else
				{
					cout << "未计算" << endl;
				}
			}
		}
		else
		{
			return;
		}
		cir[0].num++;
	}
}

void f2()
{
	double r, h;
	while (1)
	{
		system("pause");
		system("cls");
		int n;
		cout << "1.求面积\t2.求周长\n3.排序\t\t4.退出\n请输入选择:";
		cin >> n;
		if (n <= 2)
		{
			cout << "请输入长和宽:";
			cin >> r >> h;
			rec[rec[0].num].Getdata(r, h);
		}
		if (n == 1)
		{
			rec[rec[0].num].area = rec[rec[0].num].Result();
			cout << "面积为: " << rec[rec[0].num].area << endl;
		}
		else if (n == 2)
		{
			rec[rec[0].num].perimeter = rec[rec[0].num].Result(1);
			cout << "周长为: " << rec[rec[0].num].perimeter << endl;
		}
		else if (n == 3)
		{
			for (int i = 0; i < rec[0].num - 1; i++)
			{
				for (int j = 0; j < rec[0].num - 1 - i; j++)
				{
					if (rec[j] < rec[j + 1])        //运算符已重载 比较的是面积
					{
						swap(rec[j], rec[j + 1]);
					}
				}
			}
			cout << "按面积排序后为:" << endl;
			for (int i = 0; i < rec[0].num; i++)
			{
				cout << "长:" << rec[i].r << " 宽:" << rec[i].h << "  面积:";
				if (rec[i].area != -1)
				{
					cout << rec[i].area << " 周长:";
				}
				else
				{
					cout << "未计算  周长:";
				}
				if (rec[i].perimeter != -1)
				{
					cout << rec[i].perimeter << endl;
				}
				else
				{
					cout << "未计算" << endl;
				}
			}
		}
		else
		{
			return;
		}
		rec[0].num++;
	}
}

void f3()
{
	double r;
	while (1)
	{
		system("pause");
		system("cls");
		int n;
		cout << "1.求面积\t2.求体积\n3.排序\t\t4.退出\n请输入选择:";
		cin >> n;
		if (n <= 2)
		{
			cout << "请输入半径:";
			cin >> r;
			Bal[Bal[0].num].Getdata(r);
		}
		if (n == 1)
		{
			Bal[Bal[0].num].area = Bal[Bal[0].num].Result();
			cout << "面积为: " << Bal[Bal[0].num].area << endl;
		}
		else if (n == 2)
		{
			Bal[Bal[0].num].volume = Bal[Bal[0].num].Result(1);
			cout << "体积为: " << Bal[Bal[0].num].volume << endl;
		}
		else if (n == 3)
		{
			for (int i = 0; i < Bal[0].num - 1; i++)
			{
				for (int j = 0; j < Bal[0].num - 1 - i; j++)
				{
					if (Bal[j] < Bal[j + 1])        //运算符已重载 比较的是面积
					{
						swap(Bal[j], Bal[j + 1]);
					}
				}
			}
			cout << "按面积排序后为:" << endl;
			for (int i = 0; i < Bal[0].num; i++)
			{
				cout << "半径:" << Bal[i].r << "  面积:";
				if (Bal[i].area != -1)
				{
					cout << Bal[i].area << " 体积:";
				}
				else
				{
					cout << "未计算  体积:";
				}
				if (Bal[i].volume != -1)
				{
					cout << Bal[i].volume << endl;
				}
				else
				{
					cout << "未计算" << endl;
				}
			}
		}
		else
		{
			return;
		}
		Bal[0].num++;
	}
}

void f4()
{
	double r, h, w;
	while (1)
	{
		system("pause");
		system("cls");
		int n;
		cout << "1.求面积\t2.求体积\n3.排序\t\t4.退出\n请输入选择:";
		cin >> n;
		if (n <= 2)
		{
			cout << "请输入长宽高:";
			cin >> r >> w >> h;
			cub[cub[0].num].Getdata(r, w, h);
		}
		if (n == 1)
		{
			cub[cub[0].num].area = cub[cub[0].num].Result();
			cout << "面积为: " << cub[cub[0].num].area << endl;
		}
		else if (n == 2)
		{
			cub[cub[0].num].volume = cub[cub[0].num].Result(1);
			cout << "体积为: " << cub[cub[0].num].volume << endl;
		}
		else if (n == 3)
		{
			for (int i = 0; i < cub[0].num - 1; i++)
			{
				for (int j = 0; j < cub[0].num - 1 - i; j++)
				{
					if (cub[j] < cub[j + 1])        //运算符已重载 比较的是面积
					{
						swap(cub[j], cub[j + 1]);
					}
				}
			}
			cout << "按面积排序后为:" << endl;
			for (int i = 0; i < cub[0].num; i++)
			{
				cout << "长:" << cub[i].r << " 宽:" << cub[i].w << " 高:" << cub[i].h << "  面积:";
				if (cub[i].area != -1)
				{
					cout << cub[i].area << " 体积:";
				}
				else
				{
					cout << "未计算  体积:";
				}
				if (cub[i].volume != -1)
				{
					cout << cub[i].volume << endl;
				}
				else
				{
					cout << "未计算" << endl;
				}
			}
		}
		else
		{
			return;
		}
		cub[0].num++;
	}
}

void Save()
{
	fstream fout("data.txt", ios::out);
	fout << "*********************************" << endl;
	fout << "圆" << endl;
	for (int i = 0; i < cir[0].num; i++)
	{
		fout << "半径:" << cir[i].r << "  面积:";
		if (cir[i].area != -1)
		{
			fout << cir[i].area << " 周长:";
		}
		else
		{
			fout << "未计算  周长:";
		}
		if (cir[i].perimeter != -1)
		{
			fout << cir[i].perimeter << endl;
		}
		else
		{
			fout << "未计算" << endl;
		}
	}
	fout << "*********************************" << endl;
	fout << "长方形" << endl;
	for (int i = 0; i < rec[0].num; i++)
	{
		fout << "长:" << rec[i].r << " 宽:" << rec[i].h << "  面积:";
		if (rec[i].area != -1)
		{
			fout << rec[i].area << " 周长:";
		}
		else
		{
			fout << "未计算  周长:";
		}
		if (rec[i].perimeter != -1)
		{
			fout << rec[i].perimeter << endl;
		}
		else
		{
			fout << "未计算" << endl;
		}
	}
	fout << "*********************************" << endl;
	fout << "球体" << endl;
	for (int i = 0; i < Bal[0].num; i++)
	{
		cout << "半径:" << Bal[i].r << "  面积:";
		if (Bal[i].area != -1)
		{
			cout << Bal[i].area << " 体积:";
		}
		else
		{
			cout << "未计算  体积:";
		}
		if (Bal[i].volume != -1)
		{
			cout << Bal[i].volume << endl;
		}
		else
		{
			cout << "未计算" << endl;
		}
	}
	fout << "*********************************" << endl;
	fout << "长方体" << endl;
	for (int i = 0; i < cub[0].num; i++)
	{
		cout << "长:" << cub[i].r << " 宽:" << cub[i].w << " 高:" << cub[i].h << "  面积:";
		if (cub[i].area != -1)
		{
			cout << cub[i].area << " 体积:";
		}
		else
		{
			cout << "未计算  体积:";
		}
		if (cub[i].volume != -1)
		{
			cout << cub[i].volume << endl;
		}
		else
		{
			cout << "未计算" << endl;
		}
	}
	fout << "*********************************" << endl;
	fout.close();
	cout << "数据已成功保存到 data.txt 中" << endl;
}

void Menu()    //菜单选项
{
	while (1)
	{
		int n;
		cout << "************几何图形面积体积周长计算系统************\n" << endl;
		cout << "            计算机学院              NAME            \n" << endl;
		cout << "****************************************************" << endl;
		cout << "1.圆形\t\t2.长方形\n3.球体\t\t4.长方体\n5.保存\t\t6.退出\n请输入选择:" << endl;
		cin >> n;
		if (n == 1)
		{
			f1();   //二级菜单
		}
		else if (n == 2)
		{
			f2();
		}
		else if (n == 3)
		{
			f3();
		}
		else if (n == 4)
		{
			f4();
		}
		else if (n == 5)
		{
			Save();
		}
		else if (n == 6)
		{
			cout << "感谢使用" << endl;
			exit(0);
		}
		else
		{
			cout << "输入错误，请重新输入" << endl;
		}
		system("pause");
		system("cls");
	}

}
int main()
{
	Menu();
}

