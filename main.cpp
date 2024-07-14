#include <iostream>
#include <clocale>
#include "helpers.h"
#include "usuario.h"
#include "factura.h"
#include "producto.h"
#include "text arts.h"

#define USUARIOS_MAXIMOS 3

#define USUARIO "ManuelG"
#define CLAVE "manuelgarcia10"
#define PUESTO "Supervisor"

#define USUARIO2 "Diosito"
#define CLAVE2 "jesucristo01"
#define PUESTO2 "Jefe de empresa"

#define USUARIO3 "AntonioH"
#define CLAVE3 "antoniohuerta32"
#define PUESTO3 "Empleado"

using namespace std;

typedef enum {CREAR=1, MOSTRAR, ENVIAR, ELIMINAR, CERRAR_SESION} opcionesMenuPrincipal;
Usuario *usuarios[USUARIOS_MAXIMOS];
int indiceUsuarioAccedido;

int menuFacturas();
void salirDeMenu();
void inicializar();
void menuInicial();
void iniciarSesion();
void cerrarSesion();
void validarUsuarioOpcionCrear();
void validarUsuarioOpcionMostrar();
void validarUsuarioOpcionEnviar();
void validarUsuarioOpcionEliminar();
void pantallaMenuFacturacion();

int main()
{
    int opcion;
    setlocale(LC_ALL ,"");
    inicializar();
    menuInicial();
    if(indiceUsuarioAccedido>=C_0){
        do{
            system(CLEAR);
            opcion=menuFacturas();
            system(CLEAR);
            switch(opcion){
                case CREAR:         validarUsuarioOpcionCrear();    break;
                case MOSTRAR:       validarUsuarioOpcionMostrar();  break;
                case ENVIAR:        validarUsuarioOpcionEnviar();   break;
                case ELIMINAR:      validarUsuarioOpcionEliminar(); break;
                case CERRAR_SESION: cerrarSesion();                 break;
                default:            cout << "Opción no valida" << endl;
            }
            if(opcion!=CERRAR_SESION){
                cout << "\t\t\t\t\t\t";
                pausaDespuesDeGetline();
            }
        }while(indiceUsuarioAccedido>=C_0);
    }
    cout << "Cerrando Programa..." << endl;
    return 0;
}

int menuFacturas(){
    int opcion;
    pantallaMenuFacturacion();
    cout << "\t\t\t\t1) Crear factura" << endl;
    cout << "\t\t\t\t2) Mostrar factura" << endl;
    cout << "\t\t\t\t3) Enviar factura" << endl;
    cout << "\t\t\t\t4) Eliminar factura" << endl;
    cout << "\t\t\t\t5) Cerrar del sistema" << endl;
    cout << "\t\t\t\t-> ";
    cin >> opcion;
    return opcion;
}

void menuInicial(){
    int opcion;
    presentacionPantallaInicial();
    cin  >> opcion;
    system(CLEAR);
    if(opcion==C_1){
        cin.ignore();
        iniciarSesion();
    }else{
        indiceUsuarioAccedido=-1;
    }

}

void salirDeMenu(){
    cout << "Cerrando programa" << endl;
}

void inicializar(){
    usuarios[C_0]=new Usuario((char*)USUARIO, (char*)CLAVE, (char*)PUESTO, C_0);
    usuarios[C_1]=new Usuario((char*)USUARIO2, (char*)CLAVE2, (char*)PUESTO2, C_0);
    usuarios[C_2]=new Usuario((char*)USUARIO3, (char*)CLAVE3, (char*)PUESTO3, C_0);
    generarBaseDeDatos();
    folioEntero1=0;
    folioEntero2=0;
    for(int i=0; i<FACTURAS_MAXIMAS; i++){
        enviado[i]=false;
    }
}

void iniciarSesion(){
    char usuario[TAMANIO_NOMBRE_USUARIO+1], clave[TAMANIO_CLAVE_USUARIO+1];
    int cantidadIntentos;
    bool accesoConcedido;
    cantidadIntentos=3;
    do{
        accesoConcedido=false;
        cout << "\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\tUSUARIO: ";
        cin.getline(usuario, TAMANIO_NOMBRE_USUARIO+1);
        cout << "\t\t\t\t\t\tCONTRASEÑA: ";
        cin.getline(clave, TAMANIO_CLAVE_USUARIO+1);
        for(int i=0; i<USUARIOS_MAXIMOS && !accesoConcedido; i++){
            if(!strcmpi(usuario, usuarios[i]->getNombre())
               && !strcmpi(clave, usuarios[i]->getClave())){
                accesoConcedido=true;
                indiceUsuarioAccedido=i;
            }else{
                accesoConcedido=false;
            }
        }
        if(accesoConcedido){
            cout << "\t\t\t\t\t\tAcceso concedido, bienvenido" << endl;
            cout << "\t\t\t\t\t\t";
            pausaDespuesDeGetline();
            system(CLEAR);
        }else{
            cout << "\t\t\t\t\t\tError, usuario y/o contraseña no validos" << endl;
            cout << "\t\t\t\t\t\tIntentos restantes " << cantidadIntentos-1 << endl;
            cout << "\t\t\t\t\t\t";
            pausaDespuesDeGetline();
            system(CLEAR);
            cantidadIntentos--;
            if(cantidadIntentos==C_0){
                cout << "\t\t\t\t\t\tLimite de intentos alcanzado, inicio de sesión bloqueado\n";
                indiceUsuarioAccedido=-1;
            }
        }
    }while(!accesoConcedido && cantidadIntentos!=C_0);
}

void cerrarSesion(){
    cout << "\t\t\t\t\t\tCerrando sesion de " << usuarios[indiceUsuarioAccedido]->getNombre() << endl;
    cout << "\t\t\t\t\t\t";
    pausa();
    system(CLEAR);
    indiceUsuarioAccedido=-1;
    menuInicial();
}

void validarUsuarioOpcionCrear(){
    if(indiceUsuarioAccedido!=C_0){
        crearFactura();
    }else{
        cout << "\t\t\t\t\t\tSu tipo de usuario no tiene permitido usar esta opción" << endl;
    }
}

void validarUsuarioOpcionMostrar(){
    if(indiceUsuarioAccedido!=C_2){
        mostrarFactura();
    }else{
        cout << "\t\t\t\t\t\tSu tipo de usuario no tiene permitido usar esta opción" << endl;
    }
}

void validarUsuarioOpcionEnviar(){
    if(indiceUsuarioAccedido!=C_0){
        ingresarFacturaBuscar();
    }else{
        cout << "\t\t\t\t\t\tSu tipo de usuario no tiene permitido usar esta opción" << endl;
    }
}

void validarUsuarioOpcionEliminar(){
    if(indiceUsuarioAccedido!=C_2){
        ingresarEliminarFactura();
    }else{
        cout << "\t\t\t\t\t\tSu tipo de usuario no tiene permitido usar esta opción" << endl;
    }
}

void pantallaMenuFacturacion(){
    int tamanioPuestoNombre, tamanioColumna;
    tamanioPuestoNombre=1;
    tamanioColumna=28;
    cout << "\n\n";
    cout << "\t\t\t _______________________________________________________________________ " << endl;
    cout << "\t\t\t|                                                                       |" << endl;
    cout << "\t\t\t|     BIENVENIDO AL SISTEMA DE FACTURACIÓN ";
    cout << usuarios[indiceUsuarioAccedido]->getPuesto();
    tamanioPuestoNombre=tamanioPuestoNombre+strlen(usuarios[indiceUsuarioAccedido]->getPuesto());
    cout << " " << usuarios[indiceUsuarioAccedido]->getNombre();
    tamanioPuestoNombre=tamanioPuestoNombre+strlen(usuarios[indiceUsuarioAccedido]->getNombre());
    espacios(tamanioPuestoNombre, tamanioColumna);
    cout << "\n\t\t\t|_______________________________________________________________________|" << endl;
    cout << "\n\n\n\n\n\n\n";

}
