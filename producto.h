#ifndef PRODUCTO_H_INCLUDED
//#include "helpers.h"
#define PRODUCTO_H_INCLUDED
#define TAMANIO_DESCRIPCION_PRODUCTO 15

#define TAMANIO_BASE_DE_DATOS_PRODUCTOS 3

class Producto{
    private:
        char descripcion[TAMANIO_DESCRIPCION_PRODUCTO+1];
        float importe;
        float precioUnitario;
        int clave;
        int cantidad;
    public:
        Producto(char* d, float i, float pU, int cl, int c){
            setDescripcion(d);
            setImporte(i);
            setPrecioUnitario(pU);
            setClave(cl);
            setCantidad(c);
        }

        void setDescripcion(char* d){
            strcpy(this->descripcion, d);
        }
        char* getDescripcion(){
            return this->descripcion;
        }

        void setImporte(float i){
            this->importe=i;
        }
        float getImporte(){
            return this->importe;
        }

        void setPrecioUnitario(float pU){
            this->precioUnitario=pU;
        }
        float getPrecioUnitario(){
            return this->precioUnitario;
        }

        void setClave(int cl){
            this->clave=cl;
        }
        int getClave(){
            return this->clave;
        }

        void setCantidad(int c){
            this->cantidad=c;
        }
        int getCantidad(){
            return this->cantidad;
        }

};

Producto *basedeDatosProductos[TAMANIO_BASE_DE_DATOS_PRODUCTOS];

void generarBaseDeDatos();
Producto* capturarProducto();
int preguntarCantidadProductos();
int retornarImporte(Producto& p);
char* retornarDescripcion(Producto& p);

void generarBaseDeDatos(){
    char vacio[]="";
    for(int i=0; i<TAMANIO_BASE_DE_DATOS_PRODUCTOS; i++){
        basedeDatosProductos[i]=new Producto(vacio, 0.0, 0.0, 0, 0);
    }
    basedeDatosProductos[0]->setDescripcion((char*)"Chaqueta");
    basedeDatosProductos[0]->setImporte(0.0);
    basedeDatosProductos[0]->setPrecioUnitario(5.00);
    basedeDatosProductos[0]->setClave(1);

    basedeDatosProductos[1]->setDescripcion((char*)"Camiseta");
    basedeDatosProductos[1]->setImporte(0.0);
    basedeDatosProductos[1]->setPrecioUnitario(7.00);
    basedeDatosProductos[1]->setClave(2);

    basedeDatosProductos[2]->setDescripcion((char*)"Pantalon");
    basedeDatosProductos[2]->setImporte(0.0);
    basedeDatosProductos[2]->setPrecioUnitario(4.00);
    basedeDatosProductos[2]->setClave(3);
}

void imprimirBaseDeDatos(){
    cout << "\t\t\t\t\t***BASE DE DATOS***" << endl;
    cout << "\t\t\t\t|-----------------------------------------------|" << endl;
    cout << "\t\t\t\t|Clave\t|Descripcion\t\t|Precio unitario|" << endl;
    cout << "\t\t\t\t|-----------------------------------------------|" << endl;
    for(int i=0; i<TAMANIO_BASE_DE_DATOS_PRODUCTOS; i++){
        cout << "\t\t\t\t|" << basedeDatosProductos[i]->getClave() << "\t|";
        cout << basedeDatosProductos[i]->getDescripcion();
        espacios(strlen(basedeDatosProductos[i]->getDescripcion()), TAMANIO_DESCRIPCION_PRODUCTO+4);
        cout << basedeDatosProductos[i]->getPrecioUnitario() << "\t\t|" << endl;
        cout << "\t\t\t\t|-----------------------------------------------|" << endl;
    }
}

Producto* capturarProducto(){
    int opcion;
    char descripcion[TAMANIO_DESCRIPCION_PRODUCTO+1];
    float importe, precioUnitario;
    int clave, cantidad;
    do{
        imprimirBaseDeDatos();
        cout << "\t\t\t\t\tIngresa la clave del producto deseado" << endl;
        cout << "\t\t\t\t\t-> ";
        cin >> opcion;
        opcion--;
        if(opcion >= 0 && opcion <= 2){
            clave=basedeDatosProductos[opcion]->getClave();
            strcpy(descripcion, basedeDatosProductos[opcion]->getDescripcion());
            precioUnitario=basedeDatosProductos[opcion]->getPrecioUnitario();
            cantidad=preguntarCantidadProductos();
            importe=precioUnitario*cantidad;
            cout << "\t\t\t\t\t\tProducto guardado" << endl;
            pausa();
        }else{
            cout << "\t\t\t\t\t\tOpción no valida" << endl;
            pausa();
        }
        system(CLEAR);
    }while(opcion < 0 || opcion > 2);
    return new Producto(descripcion, importe, precioUnitario, clave, cantidad);
}

int preguntarCantidadProductos(){
    int cantidadProductos;
    do{
        system(CLEAR);
        cout << "\t\t\t\t\t\tCuantos productos vas a querer?\n -> ";
        cin >> cantidadProductos;
        if(cantidadProductos<=0){
            cout << "\t\t\t\t\t\tCantidad no valida" << endl;
        }
    }while(cantidadProductos<=0);
    return cantidadProductos;
}

void imprimirProducto(Producto& p){
    int tamanioColumna=68;
    char cadena[10];
    cout << "\t\t\t\t\t\t|DESCRIPCION    |" << p.getDescripcion();
    espacios(strlen(p.getDescripcion()), tamanioColumna);
    cout << "\n\t\t\t\t\t\t|---------------------------------------------------------------------------------------|"<<endl;
    cout << "\t\t\t\t\t\t|CLAVE          |" << p.getClave();
    espacios(strlen(convertirEnteroACadena(p.getClave(), cadena)), tamanioColumna);
    cout << "\n\t\t\t\t\t\t|---------------------------------------------------------------------------------------|"<<endl;
    cout << "\t\t\t\t\t\t|PRECIO UNITARIO|" << p.getPrecioUnitario();
    espacios(strlen(convertirEnteroACadena(p.getPrecioUnitario(), cadena)), tamanioColumna);
    cout << "\n\t\t\t\t\t\t|---------------------------------------------------------------------------------------|"<<endl;
    cout << "\t\t\t\t\t\t|CANTIDAD       |" << p.getCantidad();
    espacios(strlen(convertirEnteroACadena(p.getCantidad(), cadena)), tamanioColumna);
    cout << "\n\t\t\t\t\t\t|---------------------------------------------------------------------------------------|"<<endl;
    cout << "\t\t\t\t\t\t|IMPORTE        |" << p.getImporte();
    espacios(strlen(convertirEnteroACadena(p.getImporte(), cadena)), tamanioColumna);
}

int retornarImporte(Producto& p){
    return p.getImporte();
}

char* retornarDescripcion(Producto& p){
    return p.getDescripcion();
}

#endif // PRODUCTO_H_INCLUDED
