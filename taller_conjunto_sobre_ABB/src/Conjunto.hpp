
template <class T>
Conjunto<T>::Conjunto() {
    // Completar
    _raiz=NULL;
}

template <class T>
Conjunto<T>::~Conjunto() { 
    // Completar
    if(_raiz!=NULL){
        destructorNodo(_raiz->der);
        destructorNodo(_raiz->izq);
    }
    delete(_raiz);
}

template<class T>
void Conjunto<T>::destructorNodo(Nodo *n) {
    if(n!=NULL){
        destructorNodo(n->der);
        destructorNodo(n->izq);
    }
    delete n;
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    assert(false);
    return false;
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    assert(false);
}

template <class T>
void Conjunto<T>::remover(const T&) {
    assert(false);
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    assert(false);
}

template <class T>
const T& Conjunto<T>::minimo() const {
    assert(false);
}

template <class T>
const T& Conjunto<T>::maximo() const {
    assert(false);
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    assert(false);
    return 0;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}

