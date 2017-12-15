#include "KnowledgeChecker.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Knowledgechecker Diff("Diff");
	Diff.Add("Параметризованная кривая", "непрерывное отображение r' : <a,b> -> R^2; r' - вектор, <a,b> - промежуток R", true);
	Diff.Add("Гладкая и регулярая парам. кривая", "Гладкая, если существует и неприрывна (r')'(t), t in <a,b>; Регулярная если (r')'(t) !=  0, t in <a,b>", true);
	Diff.Add("График параметризованной кривой", "Множество образованное концами векторов _r(t), отложенных от точки О", true);
	Diff.Add("Пояснение, что именно кривая, а что её параметризация", "график _r(t) - кривая, а функция _r(t) её параметризация", true);
	Diff.Add("Эквивалентность регулярной кривой кривой", "регулярная кривая _p(n), n in (g,d) <=>(эквивалентна) кривой _r(t), t in (a,b), если существует допустимая замена параметра n = phi(t), для которой phi(<a,b>) = <g,d>, и _p(phi(t)) = _r(t)", true);
	Diff.Add("Геометрическая кривая", "Все регулярные криввые разбиваются по отношению эквивалентности на непересекающиеся классы эквивалентности. Каждый такой класс и есть геом кривая", true);
	Diff.Add("Вывод об эквивалентности кривых и их графике", "Эквивалентные кривые имеют одинаковые графики, то каждой геом кривой оответсвует некоторый график", true);
	Diff.Add("Простая парам кривая", "Парам кривая _r(t) называется простой, если обратное отображение (_r(t))^-1: Г_r -> <a,b> определено и непрерывно", true);
	Diff.Add("Теорема о регулярных простых кривых и их графиках", "Регулярные простые кривые, имеющие одинаковые графики - эквивалентны", true);
	Diff.Add("Следствие из теоремы о регулярных простых кривых и их графиках", "Для простых и регулярных кривых понятия 'геометрическая кривая' и 'график кривой' однозначно определяют друг друга", true);
	Diff.Add("Теорема о регулярной кривой и окрестоности любой точки", "Пусть _r(t) = (x(t), y(t)) - регулярнаяя кривая. Для любого t_0 in <a,b> можно указать её окрестность, сужение на которую функции _r(t) эквивалентно простой регулярной кривой, график которой является графиком гладкой функции y = f(x), если x'(t_0) != 0, либо функции x = g(y), если y'(t_0) != 0", true);
	Diff.Add("Теорема о неявной функции", "Пусть функция U(x,y) определена и непрерывно дифференцируема в некоторой окрестности точки (x_0,y_0), причем U(x_0,y_0) = C_0 и U'_y(x_0,y_0) != 0. Тогда равенство U(x,y) = C_0 определяет едиинственную кривую y = phi(x), обладающую свойствами: функция phi(x) определена и непрерывно дифференциируема в некоторой окрестности точки x_0, phi(x_0) = y_0, и U(x, phi(x)) = C_0 при всех x из указанной окрестности. И ПОЯСНЕНИЕ (4 стр)", true);
	Diff.Add("", "", true);
	Diff.Add("", "", true);
	Diff.Add("", "", true);
	Diff.Add("", "", true);
	Diff.Add("", "", true);
	Diff.Add("", "", true);
	Diff.Add("", "", true);
	Diff.Add("", "", true);
	Diff.Add("", "", true);
	Diff.Add("", "", true);
	Diff.Add("", "", true);
	Diff.Add("", "", true);

	Diff.Check(0, 9);
	return 0;
}
