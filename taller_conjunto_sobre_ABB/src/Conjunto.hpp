
template <class T>
Conjunto<T>::Conjunto() {
    // Completar
    _raiz=NULL;
}

template <class T>
Conjunto<T>::~Conjunto() { 
    // Completar
    if(_raiz!=NULL){
        destructorNodo(_raiz);
    }
}

template<class T>
void Conjunto<T>::destructorNodo(Nodo* n) {
    if(n!=NULL){
        destructorNodo(n->der);
        destructorNodo(n->izq);
        delete n;
    }
}
template <class T>
Conjunto<T>::Nodo::Nodo(const T &v) :valor(v),izq(NULL),der(NULL){};

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    return perteneceAux(clave, _raiz);
}

template <class T>
bool Conjunto<T>::perteneceAux(const T& clave ,Nodo* n) const {
    bool res= false;
    if((n->valor)==clave){
        res = true;
    }else{
        res = perteneceAux(clave,(n->der))||perteneceAux(clave,(n->izq));
    }
    return res;
}
template <class T>
void Conjunto<T>::insertar(const T& clave) {
    if(!pertenece(clave)){
        insertarAux(_raiz, clave);
    }
}

template <class T>
void Conjunto<T>::insertarAux(Nodo*& n, const T& clave) {
    if(n!=NULL){
        if((n->valor) > clave){
            insertarAux((n->izq),clave);
        }else{
            insertarAux((n->der), clave);
        }
    }else{
        n = new Nodo(clave);
    }
}

template <class T>
void Conjunto<T>::remover(const T& clave) {
    if(!pertenece(clave)){
        if(_raiz != NULL){
            removerAux(_raiz, clave);
        }
    }
}

template <class T>
void Conjunto<T>::removerAux(Nodo*& n, const T& clave) {
    if((n->valor)==clave){
        Nodo* m = n;
        if((n->izq)!=NULL && (n->der)!=NULL) {
            m->valor = (maximo(m->izq))->valor;
            removerAux(m->izq, m->valor);
        }else{
            &m = NULL;
        }
        delete(n);

    }else{
        removerAux((n->der), clave);
        removerAux((n->izq), clave);
    }

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
    return cardinalAux(_raiz);
}

template <class T>
unsigned int Conjunto<T>::cardinalAux(Nodo* n) const{
    unsigned int res =0;
    if(n != NULL){
        res = 1 + cardinalAux(n->izq) + cardinalAux(n->der);
    }
    return res;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}

