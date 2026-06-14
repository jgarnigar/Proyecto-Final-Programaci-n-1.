# ***Proyecto Final - Programación 1***

*El proyecto final de programación 1 tiene como fin evaluar la comprensión ténica de cómo manejar archivos estructuras de datos como stacks, clases y algoritmos tales como **bubble sort** .*

## ***Clase Student***

*La clase Student tiene como fin almacenar todos los datos de un estudiante, para luego ser manipulados y mostrados con un método **ToString()**.*

### ***Información Personal***

- Nombre
- Carnet
- Estado

### ***Cursos***
**Nota:** la información está abreviada en el código

- Programación
- Física
- Matemática
- Base de datos

### ***Métodos***

- Setters
- Getters
- ToString

      void toString(bool ave) {
          cout << endl;
          cout << "--------Student----------" << endl;
          cout<<"Name: "<<this->name<<endl;
          cout<<"Carnet: "<<this->carnet<<endl;
          cout<<"Status: "<<this->status<<endl;
    
            cout << "        -Notes-          " << endl;
            cout << "Programacion: " << programacion << endl;
            cout << "Matematica: " << matematica << endl;
            cout << "Fisica: " << fisica << endl;
            cout << "Base de datos: " << basedatos << endl;
    
            if (ave == true) {
                cout << "            -Promedio-            " << endl;
                cout << "Promedio total: " << (programacion + fisica + basedatos + matematica)/4 << endl;
            }
      }

*Teniendo nuestra clase definida podemos crear nuestras variables globales .*

    static Student inventory[30];
    static int index = 0;
    static bool archivoFailed = false;

- inventory: es un arreglo de longitud 30 en la cual almacenaremos los datos de todos los estudiantes. Hay una cantidad de 25 estudiantes. Sin embargo, configuramos la variable con 5 espacios extras por cualquier error. 
- index: es una variable entera la cual nos dice cuál es la última posición disponible para agregar a un nuevo estudiante.
- archivoFailed: nos indica si alguno de los archivos no fue abierto correctamente. Si en algún momento cualquiera de los 3 archivos no se abre, cambia el valor a true, lo cual verificaremos en el main.


## ***Clase LeerArchivos()***

*Dicha clase nos ayudará a leer los datos de todos los archivos y almacenarlos en el inventario creado globalmente. Leemos primero el archivo de estudiantes, almacenamos los carnets como claves principales. Cuando abramos los archivos notas y nombres, utilizaremos el carnet para encontrar el objeto correcto .*

*Para la clase LeerArchivos, creamos otra clase separada igual de importante que es ***searchCourse***, esta clase es súper importante ya que nos ayuda a obtener los valores exactos para encontrar los nombres y notas de cada estudiante haciendo uso del método ***subst()*** .*

***Archivos:*** "estudiantes.txt", "notas.txt", "nombres.txt".

## ***Menús***

*Los menús fueron creamos fuera de la funcióna main() para tocar lo menos posible esta clase, únicamente los whiles y reportes están creados directamente en el main() .*

## ***Función sort()***

*Esta función es llamada desde un principio con el objetivo de ordenar a todos los estudiantes de forma ascendente por el promedio de notas.*

    void sort() {
        Student estudiante;
        //vamos a ordenar nuestro array inventario de menor a mayor
        for (int i = 0; i < index - 2; i++) {
    
            for (int j = 0; j < index - 1 - i; j++) {
    
                if (inventory[j].getAverage() > inventory[j+1].getAverage()) {
    
                    Student temp = inventory[j];
                    inventory[j] = inventory[j+1];
                    inventory[j+1] = temp;
    
                }
            }
    
        }


    }

## ***Validaciones***

- Antes de verificar nuestros menús, observamos si la variable archivoFailed es verdadera, si es verdadera significa que alguno de los archivos no se abrió correctamente, así que mostramos un mensaje de que contacte al desarrollador y se cierra el programa.
<br>

- Lo primero que haremos será preguntar al usuario que ingrese un número dependiendo de la opción o que presione cualquier otra tecla para salir.
<br>

- Con cualquier otra tecla, nos referimos a una cadena de texto. Si el usuario ingresa una, recibirá un mensaje de agradecimiento por visitarnos, esto es realizado ya que el código dará error al momento que intentemos convertir una cadena de texto a un entero, lo cual obtiene el catch y muestra el mensaje.
<br>

- Si el usuario ingresa cualquier otro número, el sistema le indicará que no es una opción válida.
<br>

- Si el usuario ingresa un valor correcto, llamamos a la función correspondiente para dicho menú.


## ***Funciones Extras***

*Estas funciones son muy importantes durante todo el código. Sin embargo, no representan la lógica completa debido a que su objetivo es complementar el código .*


- searchStudent: esta función nos ayuda a encontrar un estudiante pasando un número de carnet como parámetro. Si el carnet coincide con algún estudiante, nos da su posición. Si no lo encuentra, nos da -1. Esto ya que nunca puede darnos un índice menor a 0 si es encontrado.

<br>

- showInventory: dicha función nos brinda la facilidad de hacer un for llamando el método ***toString()*** de la clase Student para mostrar toda su información. Tiene como parámetro un booleano el cual nos ayuda a imprimir el promedio de un estudiante si es deseado.

<br>

- Promedio61: durante los reportes nos piden encontrar a todos los estudiantes con un promedio de 61 o mayor. Con esta función logramos crear un for nuevamente el cual busca si el promedio es igual o mayor a 61, si lo es imprimir el promedio del estudiante.

<br>

- showLogo: hacemos uso de esta función para mostrar las iniciales de la Universidad Mariano Gálvez y el título del programa. 

<br>

- PromediosTotales: esta función fue creada con el propósito de calcular el promedio total de todos los estudiantes, además de mostrar el promedio total de cada materia.
