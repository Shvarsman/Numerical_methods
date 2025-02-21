<head>
    <h1 align="center">Численные методы решения нелинейных уравнений</h1>
</head>
<body>
    <h2>Метод дихотомии</h2>
    <h3>График</h3>
    <image src="./images/func.png" alt="График, который использовался для отделения корня. Отрезок отделенного корня."></image>
    <h3>Алгоритм</h3>
    <p>Пусть функция f непрерывна на отрезке [a,b]. Поделим отрезок [a,b] пополам. Получим точку с = (a+b)/2 и два отрезка [a,c], [c,b].</p>
    <ul>
        <li>Если f(c)=0б то корень x найден</li>
        <li>Если нет, то из двух полученных отрезков [a,c] и [c,b] надо выбирать один такой:</li>
        <li>[a<sub>1</sub>,b<sub>1</sub>] = [a,c], если f(a)*f(c)<0 или</li>
        <li>[a<sub>1</sub>,b<sub>1</sub>] = [c,b], если f(c)*f(b)<0</li>
    </ul>
    <p>Новый отрезок делим пополамю Получаем середину этого отрезка c<sub>1</sub>=(a<sub>1</sub>+b<sub>1</sub>)/2 и так далее</p>
    <h3>Сводные данные по результатам работы метода дихотомии</h3>
    <table align="center"; border=1 style='border-collapse: collapse'>
        <tr>
            <th>k</th>
            <th>a<sub>k</sub></th>
            <th>b<sub>k</sub></th>
            <th>f(a<sub>k</sub>)</th>
            <th>f(b<sub>k</sub>)</th>
            <th>b<sub>k</sub>-a<sub>k</sub></th>
        </tr>
        <tr>
            <td align="center">0</td>
            <td align="center">0</td>
            <td align="center">2</td>
            <td align="center">-0.585786</td>
            <td align="center">2.83229</td>
            <td align="center">2</td>
        </tr>
        <tr>
            <td align="center">1</td>
            <td align="center">0</td>
            <td align="center">1</td>
            <td align="center">-0.585786</td>
            <td align="center">0.651446</td>
            <td align="center">1</td>
        </tr>
        <tr>
            <td align="center">2</td>
            <td align="center">0.5</td>
            <td align="center">1</td>
            <td align="center">-0.174026</td>
            <td align="center">0.651446</td>
            <td align="center">0.5</td>
        </tr>
        <tr>
            <td align="center">3</td>
            <td align="center">0.5</td>
            <td align="center">0.75</td>
            <td align="center">-0.174026</td>
            <td align="center">0.194935</td>
            <td align="center">0.25</td>
        </tr>
        <tr>
            <td align="center">4</td>
            <td align="center">0.625</td>
            <td align="center">0.75</td>
            <td align="center">-0.00174106</td>
            <td align="center">0.194935</td>
            <td align="center">0.125</td>
        </tr>
        <tr>
            <td align="center">5</td>
            <td align="center">0.625</td>
            <td align="center">0.6875</td>
            <td align="center">-0.00174106</td>
            <td align="center">0.0936897</td>
            <td align="center">0.0625</td>
        </tr>
        <tr>
            <td align="center">6</td>
            <td align="center">0.625</td>
            <td align="center">0.65625</td>
            <td align="center">-0.00174106</td>
            <td align="center">0.0452289</td>
            <td align="center">0.03125</td>
        </tr>
    </table>
    <h2>Метод Ньютона, метод Ньютона с постоянной производной, метод секущих</h2>
    <h3>Алгоритмы</h3>
    <ul>
        <li><strong>Метод Ньютона</strong></li>
        <p>x<sub>k+1</sub> = x<sub>k</sub> - f(x<sub>k</sub>)/f'(x<sub>k</sub>),
        <br>k = 0, 1, ...
        <br>Скорость сходимости - квадратичная</p>
        <li><strong>Метод Ньютона с постоянной производной</strong></li>
        <p>f(x<sub>0</sub>) * f''(x<sub>0</sub>) > 0
        <br>x<sub>0</sub> - начальное приближение
        <br>x<sub>k+1</sub> = x<sub>k</sub> - f(x<sub>k</sub>)/f'(x<sub>0</sub>),
        <br>k = 0, 1, ...
        <br>Скорость сходимости - линейная</p>
        <li><strong>Метод секущих</strong></li>
        <p>x<sub>k+1</sub> = x<sub>k</sub> - f(x<sub>k</sub>) * (x<sub>k</sub> - x<sub>k-1</sub>) / (f(x<sub>k</sub>) - f(x<sub>k-1</sub>))
        <br>Скорость сходимости - сверхлинейная</p>
    </ul>
    <h3>Сводные данные по результатам работы методов</h3>
    <table align="center"; border=1 style='border-collapse: collapse'>
        <tr>
            <th rowspan=2> Номер <br>итерации k</th>
            <th colspan=2>Метод Ньютона <br>с постоянной производной</th>
            <th colspan=2>Метод Ньютона</th>
            <th colspan=2>Метод секущих</th
        </tr>
        <tr>
            <th align="center">x<sub>k</sub></th>
            <th align="center">|x<sub>k</sub> - x<sub>k-1</sub>|</th>
            <th align="center">x<sub>k</sub></th>
            <th align="center">|x<sub>k</sub> - x<sub>k-1</sub>|</th>
            <th align="center">x<sub>k</sub></th>
            <th align="center">|x<sub>k</sub> - x<sub>k-1</sub>|</th>
        </tr>
        <tr>
            <td align="center">0</td>
            <td align="center">0.640625</td>
            <td align="center">0.0143407</td>
            <td align="center">0.640625</td>
            <td align="center">0.0143407</td>
            <td align="center">0.740625</td>
            <td align="center">0.113657</td>
        </tr>
        <tr>
            <td align="center">1</td>
            <td align="center">0.626284</td>
            <td align="center">0.000106086</td>
            <td align="center">0.626284</td>
            <td align="center">0.000107682</td>
            <td align="center">0.626968</td>
            <td align="center">0.000747654</td>
        </tr>
        <tr>
            <td align="center">2</td>
            <td align="center">0.626178</td>
            <td align="center">1.57818 * 10<sup>-6</sup></td>
            <td align="center">0.626177</td>
            <td align="center">6.11519 * 10<sup>-9</sup></td>
            <td align="center">0.62622</td>
            <td align="center">4.37773 * 10<sup>-5</sup></td>
        </tr>
        <tr>
            <td align="center">3</td>
            <td align="center">0.626177</td>
            <td align="center">2.3566 * 10<sup>-8</sup></td>
            <td align="center"> - </td>
            <td align="center"> - </td>
            <td align="center">0.626177</td>
            <td align="center">1.82689 * 10<sup>-8</sup></td>
        </tr>
    </table>
    <h2>Выводы</h2>
    <p>Методы Ньютона и секущих продемонстрировали высокую скорость сходимости к корню, однако метод Ньютона с постоянной производной оказался менее точным по сравнению с классическим методом Ньютона.
    <br>Наличие итерационного счетчика в выводах позволило отслеживать прогресс и оценивать количество шагов, необходимых для достижения заданной точности.
    </p>
    <h2>Источники</h2>
    <ul>
        <li>График - <a href=https://www.desmos.com/calculator?lang=ru>desmos.com</a></li>
        <li>Метод дихотомии - <a href=http://www.machinelearning.ru/wiki/index.php?title=%D0%9C%D0%B5%D1%82%D0%BE%D0%B4%D1%8B_%D0%B4%D0%B8%D1%85%D0%BE%D1%82%D0%BE%D0%BC%D0%B8%D0%B8>machinelearning.ru</a></li>
        <li>Остальные методы - конспект</li>
    </ul>
</body>
