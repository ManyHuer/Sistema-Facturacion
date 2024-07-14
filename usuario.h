#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#define TAMANIO_NOMBRE_USUARIO 50
#define TAMANIO_CLAVE_USUARIO 20
#define TAMANIO_PUESTO_USUARIO 30

class Usuario{
    private:
        char nombre[TAMANIO_NOMBRE_USUARIO+1];
        char clave[TAMANIO_CLAVE_USUARIO+1];
        char puesto[TAMANIO_PUESTO_USUARIO+1];
        //char qr[];
        int cantidadFacturas;
    public:
        Usuario(char *n, char* c, char* p, int cF){
            setNombre(n);
            setClave(c);
            setPuesto(p);
            setCantidadFacturas(cF);
        }

        void setNombre(char* n){
            strcpy(this->nombre, n);
        }
        char* getNombre(){
            return this->nombre;
        }

        void setClave(char* c){
            strcpy(this->clave, c);
        }
        char* getClave(){
            return this->clave;
        }

        void setPuesto(char* p){
            strcpy(this->puesto, p);
        }
        char* getPuesto(){
            return this->puesto;
        }

        void setCantidadFacturas(int cF){
            cantidadFacturas=cF;
        }
        int getCantidadFacturas(){
            return cantidadFacturas;
        }

};


#endif // USUARIO_H_INCLUDED
