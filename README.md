Para usar el programa, completar el archivo del "./matricesTest", con el siguiente formato
  parámetros
  filas, columnas
  matriz
en los parámetros actualmente se ingresan 5
1er parámetro -> en este se ingresa el formato que tomara la matriz ingresada
  -nor = matriz en formato normal o original
  -tv = matriz transversa, todos los elementos multiplicados por -1
  -tp = matriz transpuesta, las filas se vuelven columnas, por ende se invierte su orden

2do parámetro -> en este se si la operación a realizar se hará con la matriz actual o una matriz ingresada luego de la primera
  -act = trabajar con la matriz actual
  -sig = trabajar con la matriz siguiente de la primera

3er parámetro -> en este se expresa que operación se va a realizar con la matriz
  -det = realizar cálculo del determinante(aún no está terminada);
  -potN = realizar potencia de la matriz ingresada, donde N será igual a la potencia que es requerida, ejemplo (po2, po3, ...,poN);
  -sum = realizar una suma entre dos matrices, si se ingresa 1 sola, se tomará en cuenta el formato
  -prod = realizar el producto entre dos matrices, si se ingresa 1 sola, se realizará una trasnpuesta 
  para multiplicar dado que NxM no se puede multiplicar por NxM, más si se puede NxM * MxN

4to parámetro -> este delimitará el formato de la matriz siguiente, si esta fuese expresado en el parametro 2, caso contrario no se tomará en cuenta
  -nor = matriz en formato  
  -tv = matriz transversa, todos los elementos multiplicados por -1
  -tp = matriz transpuesta, las filas se vuelven columnas, por ende se invierte su orden

5to parámetro -> es para futuras implementaciones, por ahora colocar obligatoriamente 0, sino se muere un *pingüino*
