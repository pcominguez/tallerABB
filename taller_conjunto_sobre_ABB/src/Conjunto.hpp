#include <vector>

template <class T>
Conjunto<T>::Conjunto()
    // Completar
    :_raiz(NULL), length(0){}

template <class T>
Conjunto<T>::~Conjunto() { 
    // Completar
    destructorNodo(_raiz);
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
    if(n != NULL) {
        if ((n->valor) == clave) {
            res = true;
        } else {
            if(clave > n->valor) {
                res = perteneceAux(clave, (n->der));
            } else {
                res = perteneceAux(clave, (n->izq));
            }
        }
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
    if(pertenece(clave)){
        Nodo* padre = NULL;
        int dir = 2;
        removerAux(_raiz, clave, padre, dir);
    }
}

template <class T>
void Conjunto<T>::removerAux(Nodo* n, const T& clave, Nodo* padre, int dir) {
    if ((n->valor) == clave) {                                  //si encontre el valor
        if ((n->izq) != NULL || (n->der) != NULL) {             //si no es hoja tengo 3 casos
            if ((n->izq) == NULL && (n->der) != NULL) {         //1  tengo solo hijo derecho
                if(dir == 0){
                    n = n->der;
                    padre = n;
                    dir = 0;
                    removerAux(n->der, n->valor, padre, dir);
                }else{
                    n = n->der;
                    padre = n;
                    dir = 1;
                    removerAux(n->izq, n->valor, padre, dir);
                }
                delete n;
            }else {
                if ((n->izq) != NULL && (n->der) == NULL) {         //2  tengo solo hijo izquierdo
                    if (dir == 0) {
                        padre->der = n->izq;
                    }else{
                        padre->izq = n->izq;
                    }
                    delete n;
                }else{
                    if ((n->izq) != NULL && (n->der) != NULL) {         //3  tengo dos hijos
                        n->valor = maximoNodo(n->izq);
                        padre = n;
                        dir = 1;
                        removerAux(n->izq, n->valor, padre, dir);
                    }
                }
            }
        }else{                                                //si es hoja tengo 2 casos
            if (padre == NULL){
                _raiz = NULL;
                delete n;
            }else {
                if (dir == 0) {                     //1
                    padre->der = NULL;
                    delete n;
                } else {                                            //2
                    padre->izq = NULL;
                    delete n;
                }
            }
        }
    } else {                                                    //si no es la clave busco en los dos subarboles
        padre = n;
        if ((n->valor) > clave) {
            dir = 1;
            removerAux((n->izq), clave, padre, dir);
        } else {
            dir = 0;
            removerAux((n->der), clave, padre, dir);
        }
    }
}


template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    vector<Nodo*> v;
    return siguienteAux(clave, _raiz, v);
}

template <class T>
const T& Conjunto<T>::siguienteAux(const T& clave ,Nodo* n, vector<Nodo*> v) const {
    Nodo *res = n;
    if (n->valor == clave) {
        if((n->der) != NULL) {
            res = res->der;
            return minimoNodo(res); 
        } else {
            int i = 0;
            while((n->valor) > (v[i]->valor)){
                i++;
            };
            return v[i]->valor;
        }
    } else {
        v.push_back(res);
        if (clave > n->valor) {
            return siguienteAux(clave, (n->der), v);
        } else {
            return siguienteAux(clave, (n->izq), v);
        }
    }
}

template <class T>
const T& Conjunto<T>::maximoNodo(typename Conjunto<T>::Nodo* n)const {
    while(n->der != NULL){
        n = n->der;
    }
    return (*n).valor;
}

template <class T>
const T& Conjunto<T>::minimoNodo(typename Conjunto<T>::Nodo* n)const {
    while(n->izq != NULL){
        n = n->izq;
    }
    return (*n).valor;
}

template <class T>
const T& Conjunto<T>::minimo() const {
    Nodo *res = _raiz;
    while(res->izq != NULL){
        res = res->izq;
    }
    return (*res).valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
    Nodo *res = _raiz;
    while(res->der != NULL){
        res = res->der;
    }
    return (*res).valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return cardinalAux(_raiz);
}

template <class T>
unsigned int Conjunto<T>::cardinalAux(Nodo* n) const{
    unsigned int res = 0;
    if(n != NULL){
        res = 1 + cardinalAux(n->izq) + cardinalAux(n->der);
    }
    return res;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}

