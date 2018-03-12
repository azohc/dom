#ifndef _COLAVIP
#define _COLAVIP


template <class T>
class ColaVIP{
public:

	ColaVIP(int p) {
		_numPriorities = p;
		_first = NULL;
		_last = NULL;
		_n = 0;
	}

	void push(int p, const T &elem) {
		Node*node = new Node(elem, p);
		
		if (_last != NULL)
			_last->_next = node;
		_last = node;

		if (_first == NULL)
			_first = node;

		_n++;
	}
	
	T const &front() const {	//al ser const, no deberia dejarme editar los elementos de la Cola no?
		if (empty())			//otra idea era un while de 0 a numPriorities, iterando desde _first a _last
			throw "Queue is empty";			//buscando el elemento con la prioridad mas baja para devolverlo

		if (_first == _last)
			return _first->_e;

		Node*aux = _first;
		int priorityCheck = 0;
		
		while (priorityCheck < _numPriorities)
		{
			aux = _first;
			while (aux != NULL && aux->_p != priorityCheck)
				aux = aux->_next;
			
			if (aux != NULL)
				return aux->_e;

			priorityCheck++;
		}
	}

	void pop() {
		if (empty())
			throw "Queue is empty";

		Node*aux = _first;
		int priorityCheck = 0;
		bool popped = false;

		if (_first == _last)//one element
		{
			delete aux;		//does this make _first and _last == NULL as well?
			popped = true;
			_n--;
		}

		while (priorityCheck < _numPriorities && !popped)
		{
			unsigned i = 0;
			while (_first->_p != priorityCheck && i < size())	//rotate queue to make _first == lowest p
			{
				aux = _first;
				push(_first->_p, _first->_e);
				_n--;
				_first = _first->_next;
				delete aux;
				i++;
			}

			if (_first->_p == priorityCheck)	//only pop if first element is == priorityCheck
			{
				aux = _first;
				_first = _first->_next;
				delete aux;
				_n--;

				while (i < size()) {
					aux = _first;
					push(_first->_p, _first->_e);
					_n--;
					_first = _first->_next;
					delete aux;
					i++;
				}
				popped = true;
			}
			priorityCheck++;
		}
	}

	bool empty() const {
		return _first == NULL;
	}

	size_t size() const {
		return _n;
	}


private:

	class Node {
	public:
		Node() : _next(NULL) {}
		Node(const T &e, int p) : _next(NULL), _p(p), _e(e) {}
		Node(const T &e, int p, Node *next) : _next(next), _p(e), _e(e) {}

		Node *_next;	//next node
		T _e;			//element
		int _p;			//priority
	};

	Node *_first;	//pointer to first node
	Node *_last;	//pointer to last node
	int _n;				//number of elements
	int _numPriorities;	//number of priorities
};
#endif