#include "producto.h"
#include "domicilio.h"
#ifndef FACTURA_H_INCLUDED
#define FACTURA_H_INCLUDED
#define TAMANIO_NOMBRE_EMISOR 50
#define TAMANIO_NOMBRE_RECEPTOR 50
#define TAMANIO_TIPO_PERSONA_EMISOR 35
#define TAMANIO_RFC_EMISOR 25
#define TAMANIO_RFC_RECEPTOR 25
#define TAMANIO_TIPO_PERSONA_RECEPTOR 35
#define TAMANIO_HORA 10
#define TAMANIO_NUMERO_FOLIO 15
#define TAMANIO_RFC_MORAL 12
#define TAMANIO_RFC_FISCAL 13
#define PRODUCTOS_MAXIMOS 5
#define FACTURAS_MAXIMAS 20
#define ANIO_FOLIO "2022"
#define SEPARADOR_FOLIO_ANIO '-'
#define MAX_FISCALES 5

#define MORAL1 "Regimen General"
#define MORAL2 "Sin Fines de Lucro"

#define FISCAL1 "Asalariados"
#define FISCAL2 "Honorarios"
#define FISCAL3 "Arrendamientos de Inmuebles"
#define FISCAL4 "Actividades Empresariales"
#define FISCAL5 "Incorporacion Fiscal"

#define C_0 0
#define C_1 1
#define C_2 2
#define C_3 3
#define C_4 4
#define C_5 5
#define C_100 100
#define ULTIMO_DECIMAL 9
#define IVA 16

class Factura{
    private:
        char nombreEmisor[TAMANIO_NOMBRE_EMISOR+1];
        char RFCEmisor[TAMANIO_RFC_EMISOR+1];
        char tipoPersonaEmisor[TAMANIO_TIPO_PERSONA_EMISOR+1];
        char nombreReceptor[TAMANIO_NOMBRE_RECEPTOR+1];
        char RFCReceptor[TAMANIO_RFC_RECEPTOR+1];
        char tipoPersonaReceptor[TAMANIO_TIPO_PERSONA_RECEPTOR+1];
        char hora[TAMANIO_HORA+1];
        char numeroFolio[TAMANIO_NUMERO_FOLIO+1];
        float subTotal;
        float total;
        float IVATotal;
        Producto *productos[PRODUCTOS_MAXIMOS];
        int cantidadProductos;
        Domicilio *domicilioEmisor, *domicilioReceptor;
    public:
        Factura(char* nE, char* rE, char* tPE, char* nR, char* rR, char* tPR,
                char* h, char* nF, float sT, float t, float iT){
            setNombreEmisor(nE);
            setRFCEmisor(rE);
            setTipoPersonaEmisor(tPE);
            setNombreReceptor(nR);
            setRFCReceptor(rR);
            setTipoPersonaReceptor(tPR);
            setHora(h);
            setNumeroFolio(nF);
            setSubTotal(sT);
            setTotal(t);
            setIVATotal(iT);
            cantidadProductos=0;
        }

        void setNombreEmisor(char* nE){
            strcpy(this->nombreEmisor, nE);
        }
        char* getNombreEmisor(){
            return this->nombreEmisor;
        }

        void setRFCEmisor(char* rE){
            strcpy(this->RFCEmisor, rE);
        }
        char* getRFCEmisor(){
            return this->RFCEmisor;
        }

        void setTipoPersonaEmisor(char* tPE){
            strcpy(this->tipoPersonaEmisor, tPE);
        }
        char* getTipoPersonaEmisor(){
            return this->tipoPersonaEmisor;
        }

        void setNombreReceptor(char* nR){
            strcpy(this->nombreReceptor, nR);
        }
        char* getNombreReceptor(){
            return this->nombreReceptor;
        }

        void setRFCReceptor(char* rR){
            strcpy(this->RFCReceptor, rR);
        }
        char* getRFCReceptor(){
            return this->RFCReceptor;
        }

        void setTipoPersonaReceptor(char* tPR){
            strcpy(this->tipoPersonaReceptor, tPR);
        }
        char* getTipoPersonaReceptor(){
            return this->tipoPersonaReceptor;
        }

        void setHora(char* h){
            strcpy(this->hora, h);
        }
        char* getHora(){
            return this->hora;
        }

        void setNumeroFolio(char* nF){
            strcpy(this->numeroFolio, nF);
        }
        char* getNumeroFolio(){
            return this->numeroFolio;
        }

        void setSubTotal(float sT){
            subTotal=sT;
        }
        float getSubTotal(){
            return subTotal;
        }

        void setTotal(float t){
            total=t;
        }
        float getTotal(){
            return total;
        }

        void setIVATotal(float iT){
            IVATotal=iT;
        }
        float getIVATotal(){
            return IVATotal;
        }

        void setProducto(Producto* producto){
            productos[cantidadProductos]=producto;
            aumentarCantidadProductos();
        }
        Producto* getProducto(int i){
            return productos[i];
        }

        void aumentarCantidadProductos(){
            cantidadProductos++;
        }
        int getCantidadProductos(){
            return cantidadProductos;
        }

        void setDomicilioEmisor(Domicilio* dE){
            domicilioEmisor=dE;
        }
        Domicilio* getDomicilioEmisor(){
            return domicilioEmisor;
        }

        void setDomicilioReceptor(Domicilio* dR){
            domicilioReceptor=dR;
        }
        Domicilio* getDomicilioReceptor(){
            return domicilioReceptor;
        }
};

int cantidadFacturas=0;
Factura *facturas[FACTURAS_MAXIMAS];
bool enviado[FACTURAS_MAXIMAS];
int folioEntero1, folioEntero2;
char folioChar[TAMANIO_NUMERO_FOLIO]={'0','0','-','2','0','2','2'};

//Protipos de funciones para crear la factura
void crearFactura();
void registrarDatosEmisor();
void registrarDatosReceptor();
int validarRFC(int longitud);
void escogerMoralOFiscal(int tipoPersona, bool guardarEmisor);
void registrarDomicilioEmisor();
void registrarDomicilioReceptor();
void registrarProducto();
void generarFolio();
void calcularTotal();

//Protipos de funciones para imprimir la factura
void imprimirFactura(int indice);
void imprimirDatosEmisorReceptor(int indice);
void recorrerArregloProducto(int indice);
void imprimirCalculos(int indice);

void enviarFactura(int indice);
void mostrarFactura();
void imprimirTablaBuscar();
int buscarFactura();
void ingresarFacturaBuscar();
void ingresarEliminarFactura();
void eliminarFactura(int indice);

void crearFactura(){
    char vacio[]="";
    facturas[cantidadFacturas]=new Factura(vacio, vacio, vacio, vacio, vacio,
                                           vacio, vacio, vacio, 0.0, 0.0, 0.0);
    cin.get();
    registrarDatosEmisor();
    cin.get();
    registrarDomicilioEmisor();
    registrarDatosReceptor();
    cin.get();
    registrarDomicilioReceptor();
    registrarProducto();
    system(CLEAR);
    generarFolio();
    calcularTotal();
    imprimirFactura(cantidadFacturas);
    enviarFactura(cantidadFacturas);
    cantidadFacturas++;

}

void registrarDatosEmisor(){
    char nombreEmisor[TAMANIO_NOMBRE_EMISOR+1], RFCEmisor[TAMANIO_RFC_EMISOR+1];
    int tipoPersona;
    cout << "\t\t\t\t\t\t***DATOS DEL EMISOR***" << endl;
    cout << "\t\t\t\t\t\tNombre: ";
    cin.getline(nombreEmisor, TAMANIO_NOMBRE_EMISOR+1);
    do{
        cout << "\t\t\t\t\t\tRFC: ";
        cin.getline(RFCEmisor, TAMANIO_RFC_EMISOR+1);
        tipoPersona=validarRFC(strlen(RFCEmisor));
    }while(!tipoPersona);
    escogerMoralOFiscal(tipoPersona, true);
    facturas[cantidadFacturas]->setNombreEmisor(nombreEmisor);
    facturas[cantidadFacturas]->setRFCEmisor(RFCEmisor);

}

void registrarDatosReceptor(){
    char nombreReceptor[TAMANIO_NOMBRE_RECEPTOR+1], RFCReceptor[TAMANIO_RFC_RECEPTOR+1];
    int tipoPersona;
    cout << "\t\t\t\t\t\t***DATOS DEL RECEPTOR***" << endl;
    cout << "\t\t\t\t\t\tNombre: ";
    cin.getline(nombreReceptor, TAMANIO_NOMBRE_RECEPTOR+1);
    do{
        cout << "\t\t\t\t\t\tRFC: ";
        cin.getline(RFCReceptor, TAMANIO_RFC_RECEPTOR+1);
        tipoPersona=validarRFC(strlen(RFCReceptor));
    }while(!tipoPersona);
    escogerMoralOFiscal(tipoPersona, false);
    facturas[cantidadFacturas]->setNombreReceptor(nombreReceptor);
    facturas[cantidadFacturas]->setRFCReceptor(RFCReceptor);
}

int validarRFC(int longitud){
    int tipoPersona;
    if(longitud==TAMANIO_RFC_MORAL){
        tipoPersona=1;
    }else if(longitud==TAMANIO_RFC_FISCAL){
        tipoPersona=2;
    }else{
        cout << "\t\t\t\t\t\tRFC no valido, intentelo de nuevo" << endl;
        tipoPersona=0;
    }
    return tipoPersona;
}

void escogerMoralOFiscal(int tipoPersona, bool guardarEmisor){
    int opcion;
    char tipoPersonaOpcion[TAMANIO_TIPO_PERSONA_EMISOR];
    if(tipoPersona==C_1){
        do{
            cout << "\t\t\t\t\t\t***PERSONAS MORALES***" << endl;
            cout << "\t\t\t\t\t\t¿Que tipo se personas morales es?" << endl;
            cout << "\t\t\t\t\t\t1)Régimen General" << endl;
            cout << "\t\t\t\t\t\t2)Sin Fines De Lucro" << endl;
            cout << "\t\t\t\t\t\t-> ";
            cin >> opcion;
            switch(opcion){
                case C_1:   strcpy(tipoPersonaOpcion, MORAL1);    break;
                case C_2:   strcpy(tipoPersonaOpcion, MORAL2);    break;
                default:    cout << "Opción no valida" << endl;
            }
        }while(opcion!=C_1 && opcion!=C_2);
        if(guardarEmisor){
            facturas[cantidadFacturas]->setTipoPersonaEmisor(tipoPersonaOpcion);
        }else{
            facturas[cantidadFacturas]->setTipoPersonaReceptor(tipoPersonaOpcion);
        }
    }else{
        do{
            cout << "\t\t\t\t\t\t***PERSONAS FISCALES***" << endl;
            cout << "\t\t\t\t\t\t¿Que tipo se personas fiscales es?" << endl;
            cout << "\t\t\t\t\t\t1)Persona Asalariada" << endl;
            cout << "\t\t\t\t\t\t2)Honorarios" << endl;
            cout << "\t\t\t\t\t\t3)Arrendamiento de Inmuebles" << endl;
            cout << "\t\t\t\t\t\t4)Incorporación Fiscal" << endl;
            cout << "\t\t\t\t\t\t5)Actividades Empresariales" << endl;
            cout << "\t\t\t\t\t\t-> ";
            cin >> opcion;
            switch(opcion){
                case C_1:   strcpy(tipoPersonaOpcion, FISCAL1);     break;
                case C_2:   strcpy(tipoPersonaOpcion, FISCAL2);     break;
                case C_3:   strcpy(tipoPersonaOpcion, FISCAL3);     break;
                case C_4:   strcpy(tipoPersonaOpcion, FISCAL4);     break;
                case C_5:   strcpy(tipoPersonaOpcion, FISCAL5);     break;
                default:    cout << "Opción no valida" << endl;
            }
        }while(opcion<C_1 || opcion>C_5);
        if(guardarEmisor){
            facturas[cantidadFacturas]->setTipoPersonaEmisor(tipoPersonaOpcion);
        }else{
            facturas[cantidadFacturas]->setTipoPersonaReceptor(tipoPersonaOpcion);
        }
    }
}

void registrarDomicilioEmisor(){
    facturas[cantidadFacturas]->setDomicilioEmisor(capturarDomicilio());
    cout << "\t\t\t\t\t\t";
    pausa();
    system(CLEAR);
}

void registrarDomicilioReceptor(){
    facturas[cantidadFacturas]->setDomicilioReceptor(capturarDomicilio());
    cout << "\t\t\t\t\t\t";
    pausa();
    system(CLEAR);
}

void registrarProducto(){
    int opcion;
    do{
        facturas[cantidadFacturas]->setProducto(capturarProducto());
        cout << "\t\t\t\t\t\tquieres capturar otro producto? 1)Si  Otro numero)No" << endl;
        cout << "\t\t\t\t\t\t-> ";
        cin >> opcion;
        if(facturas[cantidadFacturas]->getCantidadProductos()==3){
            cout << "\t\t\t\t\t\tLimite de productos alcanzados" << endl;
        }else if(opcion==C_1){
            system(CLEAR);
        }
    }while(opcion==C_1 && facturas[cantidadFacturas]->getCantidadProductos()!=3);
}

void generarFolio(){
    if (folioEntero1<ULTIMO_DECIMAL){
        folioEntero1++;
    }else if (folioEntero2<ULTIMO_DECIMAL){
        folioEntero1=0;
        folioEntero2++;
    }
    folioChar[C_0]=folioEntero2+'0'; //Se le suma el caracter 0 para convertirlo de entero a caracter
    folioChar[C_1]=folioEntero1+'0'; //Se le suma el caracter 0 para convertirlo de entero a caracter
    facturas[cantidadFacturas]->setNumeroFolio(folioChar);
}

void calcularTotal(){
    float subtotal, Iva, total;
    subtotal=0;
    for(int i=0; i<facturas[cantidadFacturas]->getCantidadProductos();i++){
        subtotal=subtotal+retornarImporte(*facturas[cantidadFacturas]->getProducto(i));
    }
    Iva=(float)(subtotal*IVA)/C_100;
    total=subtotal+Iva;
    facturas[cantidadFacturas]->setSubTotal(subtotal);
    facturas[cantidadFacturas]->setIVATotal(Iva);
    facturas[cantidadFacturas]->setTotal(total);
}

void imprimirFactura(int indice){
    imprimirDatosEmisorReceptor(indice);
    imprimirDomicilioEmisorReceptor(*facturas[indice]->getDomicilioEmisor(),
                                    *facturas[indice]->getDomicilioReceptor());
    recorrerArregloProducto(indice);
    imprimirCalculos(indice);
}

void imprimirDatosEmisorReceptor(int indice){
    int tamanioColumna=39;
    cout << "\t\t\t|---------------------------------------------------------------------------------------|"<<endl;
    cout << "\t\t\t|           FACTURA           |                        FOLIO:";
    cout << facturas[indice]->getNumeroFolio() <<"                    |"<<endl;
    cout << "\t\t\t|---------------------------------------------------------------------------------------|"<<endl;
    cout << "\t\t\t|       |\t\tEMISOR\t\t\t|\t\tRECEPTOR\t\t|" << endl;
    cout << "\t\t\t|---------------------------------------------------------------------------------------|"<<endl;
    cout << "\t\t\t|Nombre |" << facturas[indice]->getNombreEmisor();
    espacios(strlen(facturas[indice]->getNombreEmisor()), tamanioColumna);
    cout << facturas[indice]->getNombreReceptor();
    espacios(strlen(facturas[indice]->getNombreReceptor()), tamanioColumna);

    cout << "\n\t\t\t|---------------------------------------------------------------------------------------|"<<endl;
    cout << "\t\t\t|RFC    |" << facturas[indice]->getRFCEmisor();
    espacios(strlen(facturas[indice]->getRFCEmisor()), tamanioColumna);
    cout << facturas[indice]->getRFCReceptor();
    espacios(strlen(facturas[indice]->getRFCReceptor()), tamanioColumna);

    cout << "\n\t\t\t|---------------------------------------------------------------------------------------|"<<endl;
    cout << "\t\t\t|PERSONA|" << facturas[indice]->getTipoPersonaEmisor();
    espacios(strlen(facturas[indice]->getTipoPersonaEmisor()), tamanioColumna);
    cout << facturas[indice]->getTipoPersonaReceptor();
    espacios(strlen(facturas[indice]->getTipoPersonaReceptor()), tamanioColumna);
}

void recorrerArregloProducto(int indice){
    cout << "\n\t\t\t|---------------------------------------------------------------------------------------|"<<endl;
    cout << "\t\t\t|=======================================================================================|"<<endl;
    cout << "\t\t\t|\t\t\t\t\t PRODUCTOS\t\t\t\t        |\n";
    for(int i=0; i<facturas[indice]->getCantidadProductos();i++){
        cout << "\t\t\t|---------------------------------------------------------------------------------------|"<<endl;
        imprimirProducto(*facturas[indice]->getProducto(i));
        if(i+1!=facturas[indice]->getCantidadProductos()){
            cout << "\n\t\t\t|---------------------------------------------------------------------------------------|\n";
        }else{
            cout << "\n\t\t\t|=======================================================================================|\n";
        }
    }
}

void imprimirCalculos(int indice){
    int tamanioColumna=76;
    char cadena[10];
    cout << "\t\t\t|\t\t\t\t\t   PAGO   \t\t\t\t        |\n";
    cout << "\t\t\t|---------------------------------------------------------------------------------------|"<<endl;
    cout << "\t\t\t|SUBTOTAL|" << facturas[indice]->getSubTotal();
    espacios(strlen(convertirEnteroACadena(facturas[indice]->getSubTotal(), cadena)), tamanioColumna);
    cout << "\n\t\t\t|---------------------------------------------------------------------------------------|"<<endl;
    cout << "\t\t\t|IVA     |" << facturas[indice]->getIVATotal();
    espacios(strlen(convertirEnteroACadena(facturas[indice]->getIVATotal(), cadena)), tamanioColumna);
    cout << "\n\t\t\t|---------------------------------------------------------------------------------------|"<<endl;
    cout << "\t\t\t|TOTAL   |" << facturas[indice]->getTotal();
    espacios(strlen(convertirEnteroACadena(facturas[indice]->getTotal(), cadena)), tamanioColumna);
    cout << "\n\t\t\t|---------------------------------------------------------------------------------------|"<<endl;
}

void enviarFactura(int indice){
    int opcion;
    if(!enviado[indice]){
        cout << "\t\t\t\t\t\tQuieres enviar la factura? 1)Si  Otro numero)No \n-> ";
        cin >> opcion;
        if(opcion==C_1){
            cout << "\t\t\t\t\t\tFactura enviada con exito" << endl;
            enviado[indice]=true;
        }else{
            cout << "\t\t\t\t\t\tFactura no enviada" << endl;
        }
        cin.get();
    }else{
        cout << "\t\t\t\t\t\tLa factura ya se ha enviado" << endl;
    }
}

void mostrarFactura(){
    int indice;
    indice=buscarFactura();
    if(indice>=C_0){
        system(CLEAR);
        imprimirFactura(indice);
    }else if(cantidadFacturas!=C_0){
        cout << "\t\t\t\t\t\tNo existe ese numero de folio" << endl;
    }
}

void imprimirTablaBuscar(){
    int tamanioColumna;
    tamanioColumna=18;
    cout << "\t\t\t|-----------------------------------------------------------------------|"<<endl;
    cout << "\t\t\t|\tFOLIO\t\t|\tNombre\t\t|\tDescripción\t|" << endl;
    cout << "\t\t\t|-----------------------------------------------------------------------|"<<endl;
    for(int i=0; i<cantidadFacturas; i++){
        for(int j=0; j<facturas[i]->getCantidadProductos(); j++){
            cout << "\t\t\t|" << facturas[i]->getNumeroFolio();
            espacios(strlen(facturas[i]->getNumeroFolio()), tamanioColumna);
            cout << facturas[i]->getNombreEmisor();
            espacios(strlen(facturas[i]->getNombreEmisor()), tamanioColumna);
            cout << retornarDescripcion(*facturas[i]->getProducto(j));
            espacios(strlen(retornarDescripcion(*facturas[i]->getProducto(j))), tamanioColumna);
            cout << endl;
        }
        cout << "\t\t\t|-----------------------------------------------------------------------|"<<endl;
    }
}

int buscarFactura(){
    char folioBuscado[TAMANIO_NUMERO_FOLIO+1];
    int indiceFolioEncontrado;
    indiceFolioEncontrado=-1;
    if(cantidadFacturas!=C_0){
        imprimirTablaBuscar();
        cout << "\t\t\t\t\t\tIngresa el folio de la factura \n-> ";
        cin.get();
        cin.getline(folioBuscado, TAMANIO_NUMERO_FOLIO+1);
        for(int i=0; i<cantidadFacturas && indiceFolioEncontrado<C_0; i++){
            if(!strcmp(facturas[i]->getNumeroFolio(), folioBuscado)){
                indiceFolioEncontrado=i;
            }
        }
    }else{
        cout << "\t\t\t\t\t\tNo hay ninguna factura registrada" << endl;
    }
    return indiceFolioEncontrado;
}

void ingresarFacturaBuscar(){
    int indice;
    indice=buscarFactura();
    if(indice>=C_0){
        system(CLEAR);
        imprimirFactura(indice);
        enviarFactura(indice);
    }else if(cantidadFacturas!=C_0){
        cout << "\t\t\t\t\t\tNo existe ese numero de folio" << endl;
    }
}

void ingresarEliminarFactura(){
    int indice;
    indice=buscarFactura();
    if(indice>=C_0){
        system(CLEAR);
        imprimirFactura(indice);
        eliminarFactura(indice);
    }else if(cantidadFacturas!=C_0){
        cout << "\t\t\t\t\t\tNo existe ese numero de folio" << endl;
    }
}

void eliminarFactura(int indice){
    int opcion;
    if(!enviado[indice]){
        cout << "\t\t\t\t\t\tSeguro que quieres eliminar la factura? 1)Si  Otro numero)No \n-> ";
        cin >> opcion;
        if(opcion==C_1){
            while(indice<cantidadFacturas){
                facturas[indice]=facturas[indice+1];
                indice++;
            }
            facturas[indice]=nullptr;
            delete facturas[indice];
            cantidadFacturas--;
            cout << "\t\t\t\t\t\tLa factura fue eliminada con exito" << endl;
        }else{
            cout << "\t\t\t\t\t\tLa factura no fue eliminada" << endl;
        }

    }else{
        cout << "\t\t\t\t\t\tNo se puede eliminar la factura porque ya fue enviada" << endl;
    }
}

#endif // FACTURA_H_INCLUDED
