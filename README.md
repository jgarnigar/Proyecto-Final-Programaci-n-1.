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

Creamos las validaciones con try´s, esto nos ayuda a 