template <class T> class PilaEstatica{
private:
    int size;
    int primero;
    T *datos;
public:
    PilaEstatica(int s) {
        primero = -1;
        size = s;
        datos = new T[s];
    }
    void push(T e){
        if(primero == size - 1){
            throw "Pila llena";
        }
        primero++;
        datos[primero] = e;
    }
    T pop(){
        if(primero == -1){
            throw "Pila vacía";
        }
        T aux = datos[primero];
        primero--;
        return aux;
    }
    bool pilaVacia() const{
        return primero == -1;
    }
    bool pilaLlena() const{
        return primero == size - 1;
    }
    void limpiarPila(){
        while(!pilaVacia()){
            pop();
        }
    }
    ~PilaEstatica(){
        limpiarPila();
    }
};