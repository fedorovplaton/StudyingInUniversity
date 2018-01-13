#include "KnowledgeChecker.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Knowledgechecker M("MathAn2.1");
	M.Add("N-мерная ячейка", "происзведенеи по n (a_i, b_i) ", false);
    M.Add("Функция мн-ва","подмножество всех подможеств X", false);
    M.Add("Аддитивная и счетно аддитивня функция","В аддитивной сумма до n непересекающихся множеств и f(сумма) = суммеf(E_i); В счетно аддитивной до бесконечности", false);
    M.Add("Длина промежутка","f(<a,b>) = b - a", false);
    M.Add("Th: длина рпомежутка как аддетивная функция"," в R^n длина промежутка как ф-я - аддитивная ф-я", false);
    M.Add("Th: лемма об общем измельчении","есть конечно семейство промежутков в R, то существует более общее дизъюнктное измельчение", true);
    M.Add("Что такое произведение конечно аддитивных ф-ий и обобщенные прямоугольники","ф-ия fxg заданная на AxB - обобщенные прямоугольники", false);
    M.Add("D(f) удовлетворяет св-ву конечных изельчений","для любых мн-в из D существует конечное дизъюктивное разбиение", true);
    M.Add("Полукольцо","Eps - подможество множества всех подмножеств и 1) 0 in Eps 2)A,B in Eps => A&B in Eps 3) A,B in Eps => A-B можно разбить на dis", true);
    M.Add("Th: Eps - полукольцо, тогда верны 3 пункта","1)A (minus) (куча A_i in Eps) можно разб    ить на dis 2)Eps обладает св-вом конечных измельчений 3) есть адд ф-я f ->[0,inf] и A in Eps = u(A_i) => f(A) <= summa f(A_i) - полуаддитивность", false);
    M.Add("Кольцо","Eps in 2^X, A,B in Eps => A|B in Eps, A&B in Eps, A-B in Eps, 0 in Eps", false);
    M.Add("Th: Как сделать из полукольца кольцо (2) формулировки","Eps - полукольцо, Ep = {A: существует натуральное n: существует сумейство A_i in Eps разбивающих A}; ЛИБО из таких А что существует семейтво A_i in Eps и тогда uAi in Eps", true);
    M.Add("Th: продолжение аддитивной ф-ии с полукольца на кольцо","Есть полукольцо и ф-я аддитивная, тогда существует единственная аддитивная ф-я из кольцо(от этого полукольца) на R и эта ф-я на полукольце равна первой ф-ии", false);
    M.Add("Th: о аддитивности ф-ии длины отрезка на R","Eps, f(<a,b>) = b-a => f счет адд", false);
    M.Add("Элементарная мера Стильтьеса","хзхзхззхзх", false);
    M.Add("Лебеговский объем(предмера) в R^n","ф-я f заданная на полукольце и f(произвдеение по n <a_i,b_i>) = произведение по n (b_i - a_i)", true);
    M.Add("Th: об аддитивности Лебеговского объема","Лебеговский объем счетно аддитивен", false);
    M.Add("Th: об произедении счетно-адд ф-ий","произведенеи 2 счетно-адд полож ф-ий - ф-я G(AxB) = fxg(AxB) = f(A) * g(B)", false);
    M.Add("Th: о продолжении счетно-адд ф-ии с полукольца на кольцо","продолжили счет-адд ф-ю с полукольца на кольцо тоже счет-адд", false);
    M.Add("Внешняя мера(просто и Лебега) отвечающая предмере f","f - предмера на X, D - полукольцо, f(0) = 0, f = [0,inf], тогда число f* = inf(сумма от 1 до inf f(E_i)), и f* = [0,inf], E in uE_i, Ei in D(f); А вот если это на R^n и f - это длина промежутка, то это внешняя мера Лебега", true);
    M.Add("Th: о аддитивности внешней меры","f - предмера на X, = [0,inf], тогда f* счетно-полуаддитивна", false);
    M.Add("Отличие абстрактной внешней меры от внешней меры и что это","внешняя мера достроенна от чего-то, а абстрактная просто обладает такими же св-вами как и внешняя; абстрактная внешняя мера f*: 1)f*(0) = 0 2)f* счетно полуаддитивна 3)f* монотонна", true);
    M.Add("Сигма-алгебра","_E - подмножество множества всех подмножеств X, тогда _E - сигма-алгебра, если 1)0 in _E, X in _E 2)E in _E => X-E in _E 3)E_i in _E => для любого n in N, uE_i in _E", true);
    M.Add("Th: об аддитивности абстрактных внешних мер"," f* - абстрактная внешняя мера, тогда если E in X, A in X, f*(A) = f*(A-E) + f*(A&E) то говорят что E хорошо разбивает A, тогда 1)если при заданном E р-во выполняется для любого A, то такое E - f*-измеримо, и множество из таких f* является сигма-алгеброй, 2)f* счет-адд на такой алгебре 3)бесконенчо объединение, пересечение E_i из такой алгебры лежат в этой алгебре", false);
    //24
    M.Add("Th: об абстрактной внешней мере на (x,ro)","(x,ro) - метрическое пространство; A,B in X ro(A,B) != 0, f*(A+B) = f*(A) + f*(B), тогда для любого замкнутого или открытого Е из X оно f* измеримо", false);
    M.Add("Диадические кубы и их св-ва","1)Разбивает R => разбивает R^n, т.е изв-ны кубы для более мерных пространств зная менее 2) Все кубы ранга k+1 разбивают кубы ранга k 3) Диадические кубы упорядочены отношением включения, т.е для кубов разных рангов либо 1 в другом либо не пересекаются, для кубов одного ранга они dis 4)Диадических кубов счетное кол-во", true);
    M.Add("Th: о разбитии открытого мн-ва на диадические ячейки","S - открыто in R^n то существует последовательность {delta_i}_i_1->inf таких что 1) для любого i: delta_i - диадическая ячейка 2)это семейство разбивает S", true);
    M.Add("Th: о предмере, внешн мере и множестве внешне измеримых","пусть f- предмера на полукольце, f* внешняя мера достроенная, _E - множество f*-измеримых. Тогда 1)Каждое E in D(f) т.е f-измеримое так же f*-измеримо 2)Если существует семейтво бесконенчое E_i in D(f) делящих E не обязательно dis то E f*-измеримо 3)E = пересечению по k до inf(объединению по i до inf [E_k_i in D(f)]) то E внешне f-измеримо", false);
    M.Add("Стандартное продолжение","Пусть мю предмера, тогда мю* суженное на _E алгебру внешеизмеримых множеств называется стандартным продолжением", true);
    M.Add("Измеримость по Лебегу и мера Лебега на мн-ве Е","Если мю предмера Лебега или Лебеговский объём то внешне мю-измеримо множество называется изморимостью по Лебегу. Если Е in R^n измеримо по лебегу (внешне измеримо относительно Лебеговского объёма), то мю*(Е) - мера Лебега", true);
    M.Add("Что такое мера на X","мю из _E(алгебры) подможества множества всех подмножеств в R и счет-адд и мю(0)  = 0, то мю - мера", true);
    M.Add("Th: о продоожении предмеры и мере","Стандартное продолжение любой предмеры на X является мерой на том же X", false);
    M.Add("Полная мера","мю - полная мера если для любого E in D(мю) мю(0) = 0 => 2^E in D(мю) и их мера 0 Т.е любое подмножество множества меры 0 мю-измеримо и меры 0", true);
    M.Add("Мера Лебега через Лебеговский объём и что такое мн-во измеримое по Лебегу","Мера Лебега - стандартное продолжение лебеговского объёма. Мн-во Е измеримое по Лебегу рав-но внешне-измеримо относительно Лебеговского объёма т.е для любого А из R^n: мю*(А) = мю*(A&E) + мю*(A-E) ", false);
    M.Add("Th: эквивалентные утверждения отн-но изм-ти по Лебегу","1) Е изм-мо по Лебегу 2) существует последователность компактов E_i и множество E_0 внешней меры 0 такое что E = u(E_i) i:0->inf 3) существует последовательность открытых G_i и мн-во E_0 меры 0: E = пересечение от G_i от 1 до inf - E_0", false);
    M.Add("Th: абстрактная внешняя мера на метрическом пр-ве","мю* абстр внешняя мера на (x,ro) пусть A,B: ro(A,B) != 0 => mu*(A+B) = mu*(A) + mu*(B), тогда все открытые E in (X, ro) mu*-измеримы, тем более замкнутые", false);
    M.Add("внешняя мера и сумма ряд, РЯД","Если ro(A+B) != 0, mu*(A+B) = mu*(A) + mu*(B), то для любого {A_k in A} (mu*(A) < inf); delta_ro(A_k, A_l) != 0 k != l; mu*(sumA_k_1->inf) = sum mu*(A_k) и ряд сх-ся (т.к mu*(uA_k) <= mu*(A) < inf) Кроме того mu*(u(A_k) объединение до N) = sum do N mu*(A_k) -> (n - > inf mu*(sum(A_k) do inf))", false);
    M.Add("Точное определение измеримости по Лебегу", "A измеримо по Лебегу <=> A in R^n и для любого B in R^n mu*(B) = mu*(A&B) + mu*(B-A) (A хорошо разбивает любое B) <=> A = K_i от 0 до inf K_0 меры 0, остальные - компакты in R^n <=> A = пересечению до inf G_n (munis) G_0 меры 0, G_n - откр", true);
    M.Add("3-я фундаментальная теорема теории мер","Пусть mu* - абстрактная внешняя мера заданная 2^x, (X,ro) - метрическое пр-во. Пусть A,B in (X,ro) ro(A,B) > 0 => mu*(A + B) + mu*(A) + mu*(B), Тогда все открытые E in (X, ro) mu*-измеримы, замкнутые тоже ro(A,B) = inf(x,y)", true);
    M.Add("Борелевская оболочка E_0","Пусть X!=0 - произвольное мн-во, E_0 - произвольная совокупность подмножеств X со св-вами 1)E - сигма-алгебра 2)E_0 in E 3)если E' обладает 1 и 2 то E in E', т.е Е наименьшая по запасу множеств сигма-алгебра in E_0", true);
    M.Add("mu мера на Х","(X, ro) - пр-во с мерой, если mu - ф-я заданная на некоторой сигма-алгебре подмножеств X счет-адд-на со значениями в [0,inf) говорят mu мера на X обозначают (X,D(mu),mu) и мн-ва из D(mu) измеримые мн-ва", true);
    M.Add("Th: Измеримость по Лебегу и Борелю что это и равносильные определения","Из-мо по Борелю <=> пренадлежит наименьшей сигма-алгебре содержащей все открытые мн-ва.Равносильны 4 вещи 1) E in R^n измеримо по Лебегу <=> существует борелевское E' in E : d(E-E') = 0, d*(E-E') = 0 d - длина отрезка <=> существует E'': E in E'': d*(E''-E) = 0 <=> борелевское E''': E in E''' : d*( (E'''-E) | (E-E''')) = 0", true);
    M.Add("Непрерывность меры сверху и снизу","(x,ro), A_n последовательность измеримых мн-в Пусть A_n in A_n+1 для любого n in N => mu(u_infA_n) = lim(mu(A_n)) - непрерывность меры снизу. Если же A_n+1 in A_n для любого n и существует n_0: mu(A_n) < inf => lim mu(A_n) = mu(пересечени_infA_n) непрерывность меры сверху ", true);
    M.Add("Измеримая ф-я f","(x,a), (y,b) f:X->Y измеримо, если прообраз любого измерим Обычно X - R^n с мерой Лебега а Y = R - совокупность борелевских мн-в", true);
    M.Add("Th: Простейшие предложения об измеримости отображения 5 шкук","1)f:A->Y измеримо => A-из-мо 2)f:X->Y, X=A+B, f - изм-мо, A,B- изм-мы <=> f|A - изм-мо & f|B - изм-мо", false);
    //Далее только имхо важное
    M.Add("Свойства измеримых ф-ий","1)Линейная комбинация измеримых ф-ий измерима 2) куча фи-й из E -> R, mu: R^n -> R и непрерывна => mu(f1, f2, ... f2) - изм-ма 3) f_i из (x,ro) - изм-мы тогда sup f_i(x) = f(x) - изм-м",true);
    M.Add("Полуоткрытый подграфик"," f >= 0, тогда {(x,y): y in [0,f(x)]} наз-ся полуоткрытым подграфиком f(x) - Pi_f; П_f = (Pi_f | E) x {0} - хз чо это", true);
    M.Add("Эквивалентные опрееделения измеримой ф-ии на (x, ro) - > R","f - измеримо <=> f^-1(B) - измеримо <=> прообраз открытого измерим <=> f^(-1) ((a,inf]) изм-мо <=> существует семейство измеримых ступенчатых ф-ий т.е для любого n существует разбиение E_n_1 .. E_n_k : f|E_n_k = c_i и E_n_i изм-мо", true);
    M.Add("Изм-мость через полож и отрич части и что это","Полож отрич части понятны. А f изм-мо <=> f- - изм-мо и f+ изм-мо", true);
    M.Add("Что такое итегралл"," Пусть f: E in (X, mu) -> R+inf изм и f >= 0 тогда (muxnu)(Pi_f) наз-ся интеграллом int_E f(x)d(mu(x)) = int_E fd(mu)", true);
    M.Add("Теорема Леви о предельном переходе под знаком интегралла","Пусть f_n: E in (X, mu) -> R+inf, f_n >= 0 & изм-мы. для любого х in E f_n(x) возростает по n, lim f_n(x) = f(x) in R+inf, тогда  lim_n->inf int_E f_nd(mu) = int_E fd(mu) ", true);
    M.Add("Простейшие св-ва интегралла ","1) 0<=f<=g на E in (X,mu) => int <= int 2) f >= 0 изм-мо на E in (X,mu), тогда разбиваем Е и получаему сумма интеграллов 3)f >= 0, int_E f = 0 <=> f = 0 почти везде т.е {x in E | f(x) = 0} меры 0", true);
    M.Add("Интегрируемая и суммируемая ф-я","Если хотя 1 из двух интеграллов(полож или отриц) < inf то f - интегрируемая а если оба то суммируемая ATTENTION int_E f(x)d(mu(x)) = int_E f+ - int_E f- <--WARNING--> ", true);
    M.Add("Почти везде","За исключением мн-ва меры 0", true);
    M.Add("сигма-конечная мера","(X, mu), mu - сигма конечна если если существует E_i, i in N, X = u(E_i) & mu(E_i) < inf",true);
    M.Add("Принцип Кавальери","Пусть E изм-мо в (X, mu) x (Y, nu), с мерой (mu x nu) - стандартное продолжение объёма и меры mu x nu сигма-конечны, т.е существует покрытие {x_i}_inf мн-ва X, и такое же для Y !конечной меры!,  (muxnu)(E) = int_X nu(E_x) * d(mu(x)), где E_x сечение E, т.е {y in Y: (x,y) in E}, E с фиксированным X", true);
    M.Add("Теорема Тонелли","f: E in (X, mu)x(Y, nu) -> [0, inf] изм (X,mu)(Y,nu) - пр-ва с сигма-конечной алгеброй, тогда для почти всех Х f_x(Y) = f(x,y) заданная на E_x in Y и int_E fd(muxnu) = int_X d(mu(x)) * int_Ex f(x,y)d(nu(y))", true);
    M.Add("Какие бывают меры и что такое дискретная мера","Меры: Конечная mu(x) = c < inf, Вероятностная mu(x) = 1, Сигма-конечная существует покрытие из конечно измеримых, Дискретная мера нужных нам точек 1, остальных 0", true);
    M.Add("Теорема Фуббини","E in= (значок пренадлжеит ранвно) (XxY, muxnu), mu, nu - сигма конечны f: E->R+inf, Если f суммируема, то int_f_Ex f(x,y)d(nu(y)) корректно определен, т.е существует для почти всех х из Х и занчения явл-ся измеримой ф-ией от х, также суммируемая на Х и верно, что int_f_E f(x,y)d(nu(y))d(mu(x)) = int_X d(mu(x)) * int_Ex f(x,y)d(nu(y))", true);
    M.Add("Мера лебега и линейное отображение, липшецева константа"," d(T(E)) = |detT| * d(E), при Липшецовой вместо det c^n ", true);
    M.Add("Аксиоматическое определение detT","Пусть mu ф-я заданная на множестве квадратных матриц T: detT != 0 и 1)mu(T)>=0 2)mu(T1T2)=mu(T1)mu(T2) 3)mu от диагональной = a^n тогда mu(T) = |detT| для любого T", true);
    M.Add("Th: об изминении меры Лебега при диффеоморфизме","mu U in R^n -> V in R^n, diff, тогда для любого E in= U nu(mu(E)) = int_E |det(d(mu(x)))|d(nu(x)) и для любого интегрируемого f на V,E in= V int_V f(x)d(nu(x)) = int_mu^-1(E) f(mu(t))|det(d(mu))|dt", true);
    M.Add("Г - ф-я и B(alf,bet)","Г(k) = int_0->inf x^(-k) * e^(-x) dx; B(a,b) = int_0->1 t^(a - 1)(1-t)^(b-1)dt, B(a,b) = Г(a)Г(б)/Г(a+b)",true);
	M.Check(0, 64); //
	return 0;
}
