//23.Найти сумму ряда 2 + 4 + 6 + ... + n, n - длинное четное число.
#include<string>
#include <iostream>
using namespace std;

void ravn(string &sum, string qwe, string &dv,string &s)
{
	int p = 0, r = 0;
	int summa, summa1;
	while (dv != s)
	{
		for (int i = sum.length() - 1; i > -1; i--) // иду с конца к началу
		{
			summa = sum[i] - '0' + dv[i] - '0' + p;
			p = summa / 10;
			sum[i] = summa % 10 + '0'; //сложение разряда
			summa1 = dv[i] - '0' + qwe[i] - '0' + r;
			r = summa1 / 10;
			dv[i] = summa1 % 10 + '0'; // 2+4+6....
		}
	}
}
void slojenie(string &sum, string &s)
{
	int summa,p=0;
	for (int i = sum.length() - 1; i > -1; i--) // иду с конца к началу, сложение суммы ряда до n и n
	{
		summa = sum[i] - '0' + s[i] - '0' + p;
		p = summa / 10;
		s[i] = summa % 10 + '0';
	}
	if (p)
		s = '1' + s;
}

void udalenie(string &s)
{
	int k = 1;
	while (k != 0) //удаление незначащих нулей
	{
		k = 0;
		if (s[0] == '0')
		{
			s.erase(0, 1);
			k = 1;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	string s;
	cout << "Введите длинное четное число: ";
	cin>>s;										// s это число N
	while (s[s.length()-1] % 2 != 0)			// проверка числа на правильность ввода
	{
		cout << "Это нечетное число! Повторите попытку: ";
		cin >> s;
	}
	s = "000000000000000" + s; //добавление дополнительных разрядом для операций
	string sum="0"; // СУММА
	string dv = "2"; // двойка
	while (sum.length() != s.length()) //уравнивание чисен
	{
		sum ='0' + sum;
		dv = '0' + dv;
	}
	string qwe = dv; // +2 к первой двойке
	ravn(sum, qwe, dv, s);
	slojenie(sum, s);
	udalenie(s);
	cout << "Сумма ряда 2+4+6+...+N равна : " << s;
	return 0;
}