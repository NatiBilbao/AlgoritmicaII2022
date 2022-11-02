## ROD CUTTING
Rod Cutting funciona con Programación Dinámica donde partimos desde
el tamaño de la barra y lo vamos dividiendo hasta llegar a los casos
base donde no se pueda dividir más y vamos calculando los siguientes
en base a los calculados previamente hasta llegar al resultado. 

Cada corte que se hace puede haber sido calculado previamente y ahí entra la
Programación Dinámica, ya que, nos ahorra ese cálculo.

Dada una varilla de longitud n y una lista de precios de varillas de
longitud i, dónde 1 <= i <= n, encuentre la forma óptima de cortar la
varilla en varillas más pequeñas para maximizar las ganancias.

![ROD CUTTING](https://www.techiedelight.com/wp-content/uploads/Rod-Cutting-Problem.png)

## Código base

- [Rod cutting](https://github.com/NatiBilbao/AlgoritmicaII2022/blob/main/Contenido/Capitulo%202/Programacion_dinamica/RodCutting/rodCutting.cpp) - _C++_
