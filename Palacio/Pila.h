template <class T> class Pila{
protected:
    class NodoPila{
    public:
        NodoPila* siguiente;
        T elemento;
        NodoPila(T x){
            elemento = x;
            siguiente = 0;
        }
    };
    NodoPila* primero;
public:
    Pila(){
        primero = 0;
    }
    void insertar(T e){
        NodoPila* nuevo = new NodoPila(e);
        nuevo->siguiente = primero;
        primero = nuevo;
    }
    T quitar(){
        if(pilaVacia()){
            throw "Pila Vacía, no se puede extraer";
        }
        T aux = primero->elemento;
        primero = primero->siguiente;
        return aux;
    }
    T cimaPila() const{
        if (pilaVacia())
            throw "Pila Vacía";
        return primero->elemento;
    }
    bool pilaVacia() const{
        return primero == 0;
    }
    void limpiarPila(){
        NodoPila* aux;
        while(!pilaVacia()){
            aux = primero;
            primero = primero->siguiente;
            delete aux;
        }
    }
    int size() const{
        int contador = 0;
        NodoPila* aux = primero;
        while(aux != 0){
            contador++;
            aux = aux->siguiente;
        }
        return contador;
    }
    ~Pila(){
        limpiarPila();
    }
};