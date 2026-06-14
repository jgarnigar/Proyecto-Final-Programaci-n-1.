#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Student {

    //la modificacion de atributos es completamente privada
private:
    //student's info
    string name;
    string status;
    int carnet;

    //notas
    float programacion = 0;
    float matematica = 0;
    float fisica = 0;
    float basedatos = 0;
    float average = 0;

public:

    void setName(string name) {
        this->name = name;
    }

    void setCarnet(int carnet) {
        this->carnet = carnet;
    }

    void setStatus(string status) {
        this->status = status;
    }

    void setPrgramacion(float programacion) {
        this->programacion = programacion;
    }

    void setMatematica(float matematica) {
        this->matematica = matematica;
    }

    void setFisica(float fisica) {
        this->fisica = fisica;
    }

    void setBasedatos(float basedatos) {
        this->basedatos = basedatos;
    }

    void setAverage(float average) {
        this->average = average;
    }

    //Como los datos deben ser mostrados, los getters son publicos

    float getAverage() {
        return (programacion + fisica + basedatos + matematica) / 4;
    }

    string getName() {
        return this->name;
    }

    string getStatus() {
        return this->status;
    }

    int getCarnet() {
        return this->carnet;
    }

    float getFisica() {
        return this->fisica;
    }

    float getProgramacion() {
        return this->programacion;
    }

    float getMatematica() {
        return this->matematica;
    }

    float getBasedatos() {
        return this->basedatos;
    }


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


};


// Creamos nuestro inventario

static Student inventory[30];
static int index = 0;
static bool archivoFailed = false;

// segun los datos, deberia ser un maximo de 25, lo cual vereficaremos mas adelante.

//funciones

int searchStudent(int carnet) {
    //inicia en -1, si encuentra a un alumno con el carnet, muestra su indice, sino muestra -1

    int found = -1;

    for (int i = 0; i < index; i++) {
        if (inventory[i].getCarnet() == carnet) {
            found = i;
        }
    }

    return found;

}

// clase para los cursos

class SearchCourse {

public:

    int fisica = 15;
    int programacion = 21;
    int matematica = 19;
    int basedatos = 18;

};


class LeerArchivos {

public:

    //string values[2] = {"activo", "inactivo"};

    void LeerEstudiantes(string file) {

        Student student;
        string text;

        ifstream StudentsFile(file);

        if (StudentsFile.is_open()) {

            while (getline (StudentsFile, text)) {

                string carnet = text.substr(0,7);
                int convert = stoi(carnet);

                student.setCarnet(convert);


                string status = text.substr(8,-1);

                student.setStatus(status);

                inventory[index] = student;
                index += 1;
            }
        }
        else {
            cout << "Unable to open file";
            archivoFailed = true;
        }

        StudentsFile.close();

    }

    void LeerNombres(string file) {
        Student student;
        string text;

        ifstream StudentsFile(file);

        if (StudentsFile.is_open()) {

            while (getline (StudentsFile, text)) {

                string carnet = text.substr(0,7);
                int convert = stoi(carnet);

                string name = text.substr(8,-1);

                int found = searchStudent(convert);

                if (found > -1) {
                    inventory[found].setName(name);
                }else {
                    continue;
                }

            }
        }
        else {
            cout << "Unable to open file";
            archivoFailed = true;
        }

        StudentsFile.close();

    }


    void LeerNotas(string file) {
        SearchCourse searchCousre;
        Student student;
        string text;

        ifstream StudentsFile(file);

        if (StudentsFile.is_open()) {

            while (getline (StudentsFile, text)) {

                string carnet = text.substr(0,7);
                int convert = stoi(carnet);
                int found = searchStudent(convert);

                if (found == -1) {
                    cout << "Not found" << endl;
                    continue;
                }

                string course = text.substr(8,1);

                if (course == "P") {
                    string gradeString = text.substr(searchCousre.programacion,-1);
                    float gradeFloat = stof(gradeString);

                    inventory[found].setPrgramacion(gradeFloat);
                }else if (course == "F") {
                    string gradeString = text.substr(searchCousre.fisica,-1);
                    float gradeFloat = stof(gradeString);

                    inventory[found].setFisica(gradeFloat);

                }else if (course == "B") {
                    string gradeString = text.substr(searchCousre.basedatos,-1);
                    float gradeFloat = stof(gradeString);

                    inventory[found].setBasedatos(gradeFloat);

                }else if (course == "M") {
                    string gradeString = text.substr(searchCousre.matematica,-1);
                    float gradeFloat = stof(gradeString);

                    inventory[found].setMatematica(gradeFloat);
                }



            }
        }
        else {
            cout << "Unable to open file";
            archivoFailed = true;
        }

        StudentsFile.close();

    }

};


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

void showInventory(bool val) {

    for (int i = 0; i < index; i++) {
        inventory[i].toString(val);
    }
}


// para evitar tocar main, crearemos los menus en funciones


string MenuPrincipal() {

    string result;

    cout << "--------------Bienvenido--------------" << endl;
    cout << "Ingrese 1 para ver a todos los estudiantes " << endl;
    cout << "Ingrese 2 para buscar a un estudiante por numero de carnet " << endl;
    cout << "Ingrese 3 para calcular el promedio de un estudiante" << endl;
    cout << "Ingrese 4 para proceder a insertar a los estudiantes activos a la base de datos " << endl;
    cout << "Ingrese 5 para ver reportes " << endl;
    cout << "Ingrese cualquier otra tecla para salir del programa " << endl;

    getline(cin, result);

    return result;

}

void PromediosTotales() {

    float totalAverage = 0;
    float totalProgra = 0;
    float totalMate = 0;
    float totalBase = 0;
    float totalFisica = 0;

    for (int i = 0; i < index; i++) {
        totalAverage += inventory[i].getAverage();

        totalProgra += inventory[i].getProgramacion();
        totalMate += inventory[i].getMatematica();
        totalBase += inventory[i].getBasedatos();
        totalFisica += inventory[i].getFisica();
    }

    cout << "-------- Promedios De Todos Los Estudiantes ----------" << endl;
    cout << "Promedio Total: " << totalAverage/(index) << endl;
    cout << "Promedio Programacion: " << totalProgra/(index) << endl;
    cout << "Promedio Matematica: " << totalMate/(index) << endl;
    cout << "Promedio Base de datos: " << totalBase/(index) << endl;
    cout << "Promedio Fisica: " << totalFisica/(index) << endl;

}

int Menu2(bool ave) {
    string result;
    cout << "Ingrese el numero de carnet del estudiante que desea buscar por favor! " << endl;
    getline(cin, result);

    try {
        int resultInt = stoi(result);

        int indexStudent = searchStudent(resultInt);

        if (indexStudent > -1) {
            inventory[indexStudent].toString(ave);

        }else if (indexStudent == -1) {
            cout << "Estudiante no encontrado, revise el numero de carnet por favor! " << endl;
            cout << "Estaba buscando el promedio de todos? " << endl;
            PromediosTotales();


        }else {
            cout << "Ha ocurrido un error, contacte al desarrollador! " << endl;
        }

    }catch (exception& e) {
        cout << "Valor incorrecto! " << endl;

        return -2;

    }

}



void Menu3() {
    cout << "---------- Promedio ---------" << endl;
    Menu2(true);


}

void Promedio61() {
    float ave = 0;
    for (int i = 0; i < index; i++) {
        ave = inventory[i].getAverage();

        if (ave >= 61) {
            inventory[i].toString(true);
        }

    }
}

void showLogo() {

    const char* logo = R"(
          _   _  __  __   ____
         | | | ||  \/  | / ___|
         | | | || |\/| || |  _
         | |_| || |  | || |_| |
          \___/ |_|  |_| \____|

    -----------------------------------
        Universidad Mariano Galvez
             Proyecto Final
    -----------------------------------
    )";

    cout << logo << endl;
}


int main() {


    LeerArchivos archivo;
    archivo.LeerEstudiantes("estudiantes.txt");
    archivo.LeerNombres("nombres.txt");
    archivo.LeerNotas("notas.txt");
    sort();

    if (archivoFailed == true) {
        cout << "Hubo un problema con los archivos, contacte al desarollador!" << endl;
        return 0;
    }

    showLogo();

    // verificamos si el indice si es de 25, signicia que la nueva posicion que tomara es la 25, o sea index 24 del ultimo objeto
    //cout << index << endl;
    // como solo era para depurar, lo comentamos, pero justamente da 25


    while (true) {
        string stringResult = MenuPrincipal();

        // intentaremos convertir el string a un int

        try {

            int result = stoi(stringResult);

            if (result == 1 ) {

                showInventory(false);

            }else if (result == 2) {

                Menu2(false);

            }else if (result == 3) {

                //calcular el promedio de todos los estudiantes
                //como sabemos que el indice es exacto, lo utilizaremos para este resultado.
                Menu3();


            }else if (result == 4) {

                cout << "Datos agregados exitosamente!" << endl;

            }else if (result == 5) {

                while (true) {

                    string resultadoReportes;

                    cout << "-------- Reportes -------- " << endl;
                    cout << "Presione 1 para ver a los estudiantes con promedio mayor o igual a 61" << endl;
                    cout << "Presione 2 para ver a los estudiantes ordenados ascendentemente por promedio " << endl;
                    cout << "Presione 3 para ver al estudiante con mayor promedio " << endl;
                    cout << "Presione 4 para ver a la cantidad de estudiantes activos " << endl;
                    cout << "Presione 5 para regresar al menu anterior " << endl;

                    getline(cin, resultadoReportes);

                    try {

                        int resultado2 = stoi(resultadoReportes);

                        if (resultado2 == 1) {
                            Promedio61();

                        }else if (resultado2 == 2) {
                            // promedio ascendente

                            showInventory(true);

                        }else if (resultado2 == 3) {
                            // mayor promedio

                            inventory[index-1].toString(true);

                        } else if ( resultado2 == 4) {
                            int num = 0;
                            for (int i = 0; i < index-1; i++) {
                                if (inventory[i].getStatus() == "Activo") {
                                    num+= 1;
                                }
                            }

                            cout << "Hay " << num << " estudiantes activos!" << endl;

                        }else if (resultado2 == 5) {
                            cout << "--------------Menu Principal--------------" << endl;
                            cout << endl;
                            break;

                        }else {
                            cout << "Opcion no valida! " << endl;
                        }

                    }catch (exception& e) {
                        cout << "Opcion no valida! " << endl;
                    }

                }

            }else {
                cout << "Opcion no valida! " << endl;
            }



        } catch (exception e) {
            cout << "        Gracias por visitarnos! " << endl;
            showLogo();
            break;
        }

    }


    return 0;
}