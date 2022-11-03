# EDMONDS KARP

En ciencias de la computación y teoría de grafos, el algoritmo de Edmonds-Karp es idéntico al algoritmo de Ford-Fulkerson, 
excepto porque el orden para ir buscando los caminos aumentantes está definido. 

El camino encontrado debe ser el camino más corto que tiene capacidad disponible. Esto se puede encontrar mediante una 
búsqueda en anchura, ya que dejamos que los bordes tengan unidad de longitud. 

Otra propiedad de este algoritmo es que el largo del camino aumentante más corto se incrementa monotonamente.

![Ednonds karp](https://complex-systems-ai.com/wp-content/uploads/2020/09/ek.jpg)

## Código base
- [Edmonds karp](https://github.com/NatiBilbao/AlgoritmicaII2022/blob/main/Contenido/Capitulo%203/Teoria_de_grafos/Edmonds_Karp/edmondsKarp.cpp) - _C++_

## Rerefencias
- [Edmonds Karp Max Flow Algorithm Tutorial](https://www.youtube.com/watch?v=w3Nl2XA0pxA)
