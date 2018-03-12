/**
  @file Cola.h

  Implementaci�n del TAD Cola utilizando una
  lista enlazada de nodos.

  Estructura de Datos y Algoritmos
  Facultad de Inform�tica
  Universidad Complutense de Madrid

 (c) Marco Antonio G�mez Mart�n, 2012
*/
#ifndef __LINKED_LIST_QUEUE_H
#define __LINKED_LIST_QUEUE_H

#include "Exceptions.h"
#include <string>
#include <iostream>
/**
 Implementaci�n del TAD Cola utilizando una lista enlazada.

 Las operaciones son:

 - EmptydupeQueue: -> dupeQueue. Generadora implementada en el
   constructor sin par�metros.
 - push_back: dupeQueue, Elem -> dupeQueue. Generadora
 - pop_front: dupeQueue - -> dupeQueue. Modificadora parcial.
 - front: dupeQueue - -> Elem. Observadora parcial.
 - empty: dupeQueue -> Bool. Observadora.
 - size: dupeQueue -> Entero. Observadora.

 @author Marco Antonio G�mez Mart�n
 */
template <class T>
class dupeQueue {
public:

	/** Constructor; operacion EmptydupeQueue */
	dupeQueue() : _prim(NULL), _ult(NULL), _numElems(0) {
	}

	/** Destructor; elimina la lista enlazada. */
	~dupeQueue() {
		libera();
		_prim = _ult = NULL;
	}

	/**
	 A�ade un elemento en la parte trasera de la cola.
	 Operaci�n generadora.

	 @param elem Elemento a a�adir.
	*/
	void push_back(const T &elem) {
		Nodo *nuevo = new Nodo(elem, NULL);

		if (_ult != NULL)
			_ult->_sig = nuevo;
		_ult = nuevo;
		// Si la cola estaba vac�a, el primer elemento
		// es el que acabamos de a�adir
		if (_prim == NULL)
			_prim = nuevo;
		_numElems++;
	}

	/**
	 Elimina el primer elemento de la cola.
	 Operaci�n modificadora parcial, que falla si 
	 la cola est� vac�a.

	 pop_front(Push_back(elem, EmptydupeQueue)) = EmptydupeQueue
	 pop_front(Push_back(elem, xs)) = push_back(elem, pop_front(xs)) si !empty(xs)
	 error: pop_front(EmptydupeQueue)
	*/
	void pop_front() {
		if (empty())
			throw EmptyQueueException();
		Nodo *aBorrar = _prim;
		_prim = _prim->_sig;
		delete aBorrar;
		--_numElems;
		// Si la cola se qued� vac�a, no hay
		// �ltimo
		if (_prim == NULL)
			_ult = NULL;
	}

	void display() {

		for (int i = 0; i < size(); i++) {
			T e = front();
			push_back(front());
			pop_front();
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}

	void dupe() {

		int n = size();

		for (int i = 0; i < n; i++) {
			push_back(front());
			push_back(front());
			pop_front();
		}
	}

	/**
	 Devuelve el primer elemento de la cola. Operaci�n
	 observadora parcial, que falla si la cola est� vac�a.

	 front(Push_back(elem, EmptydupeQueue)) = elem
	 front(Push_back(elem, xs)) = primero(xs) si !empty(xs)
	 error: front(EmptydupeQueue)

	 @return El primer elemento de la cola.
	 */
	const T &front() const {
		if (empty())
			throw EmptyQueueException();
		return _prim->_elem;
	}

	/**
	 Devuelve true si la cola no tiene ning�n elemento.

	 empty(EmptydupeQueue) = true
	 empty(Push_back(elem, p)) = false

	 @return true si la cola no tiene ning�n elemento.
	 */
	bool empty() const {
		return _prim == NULL;
	}

	/**
	 Devuelve el n�mero de elementos que hay en la
	 cola.
	 size(EmptydupeQueue) = 0
	 size(Push_back(elem, p)) = 1 + size(p)

	 @return N�mero de elementos.
	 */
	int size() const {
		return _numElems;
	}

	// //
	// M�TODOS DE "FONTANER�A" DE C++ QUE HACEN VERS�TIL
	// A LA CLASE
	// //

	/** Constructor copia */
	dupeQueue(const dupeQueue<T> &other) : _prim(NULL), _ult(NULL) {
		copia(other);
	}

	/** Operador de asignaci�n */
	dupeQueue<T> &operator=(const dupeQueue<T> &other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	/** Operador de comparaci�n. */
	bool operator==(const dupeQueue<T> &rhs) const {
		if (_numElems != rhs._numElems)
			return false;
		Nodo *p1 = _prim;
		Nodo *p2 = rhs._prim;
		while ((p1 != NULL) && (p2 != NULL)) {
			if (p1->_elem != p2->_elem)
				return false;
			p1 = p1->_sig;
			p2 = p2->_sig;
		}

		return (p1 == NULL) && (p2 == NULL);
	}

	bool operator!=(const dupeQueue<T> &rhs) const {
		return !(*this == rhs);
	}
	


protected:

	void libera() {
		libera(_prim);
	}

	void copia(const dupeQueue &other) {

		if (other.empty()) {
			_prim = _ult = NULL;
			_numElems = 0;
		} else {
			Nodo *act = other._prim;
			Nodo *ant;
			_prim = new Nodo(act->_elem);
			ant = _prim;
			while (act->_sig != NULL) {
				act = act->_sig;
				ant->_sig = new Nodo(act->_elem);
				ant = ant->_sig;
			}
			_ult = ant;
			_numElems = other._numElems;
		}
	}

private:

	/**
	Clase nodo que almacena internamente el elemento (de tipo T),
	y un puntero al nodo siguiente, que podr�a ser NULL si
	el nodo es el �ltimo de la lista enlazada.
	*/
	class Nodo {
	public:
		Nodo() : _sig(NULL) {}
		Nodo(const T &elem) : _elem(elem), _sig(NULL) {}
		Nodo(const T &elem, Nodo *sig) :
			_elem(elem), _sig(sig) {}

		T _elem;
		Nodo *_sig;
	};
	
	/**
	 Elimina todos los nodos de la lista enlazada cuyo
	 primer nodo se pasa como par�metro.
	 Se admite que el nodo sea NULL (no habr� nada que
	 liberar).
	 */
	static void libera(Nodo *prim) {
		while (prim != NULL) {
			Nodo *aux = prim;
			prim = prim->_sig;
			delete aux;
		}
	}

	/** Puntero al primer elemento. */
	Nodo *_prim;

	/** Puntero al �ltimo elemento. */
	Nodo *_ult;

	/** N�mero de elementos */
	int _numElems;
};

#endif // __LINKED_LIST_QUEUE_H
