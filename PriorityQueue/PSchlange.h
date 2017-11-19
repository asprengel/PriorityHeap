#pragma once


class PrioQueue
{
public:
	PrioQueue(int lenght = 1000);
	virtual ~PrioQueue();
	PrioElement& maximum() const;
	PrioElement extractMax();
	void update(int,int);
	void insert(const int num);
	void remove(int);
private:
	void upHeap();
	void downHeap();
	void swapDatShit(unsigned a, unsigned b);
	unsigned int getPos(unsigned int id);

	int n;
	unsigned int lenght;
	PrioElement **field;
};

inline PrioQueue::PrioQueue(int lenght)
{
	this->lenght = lenght + 1;
	n = 0; 
	field = new PrioElement*[this->lenght];
	field[0] = NULL;
	for (size_t i = 1; i < this->lenght; i++)
	{
		field[i] = new PrioElement();
	}
}

inline PrioQueue::~PrioQueue()
{
	for (size_t i = 0; i < lenght; i++)
	{
		delete[] field[i];
	}
}


PrioElement & PrioQueue::maximum() const
{
	return *field[lenght];
}

PrioElement PrioQueue::extractMax()
{
	PrioElement max = *field[1];
	swapDatShit(1, n);
	n--;
	downHeap();
	return max;
}

void PrioQueue::insert(const int num)
{
	field[++n]->set_priority(num);
	upHeap();
}

void PrioQueue::upHeap()
{
	usigned int pos = n;

	while (pos > 1 && *field[pos / 2] < *field[pos]) 
	{ 
		swapDatShit(pos, pos/2); 
		pos = pos / 2; 
	}

	//for (size_t i = 1; i < n + 1; i++)
	//{
	//	cout << *field[i] << "\t";
	//}
	//cout << endl;
}

void PrioQueue::downHeap()
{
	unsigned int pos = 1;

	while (true)
	{
		//Das hier ist eine if Abfrage
		if (pos * 2 <= n && *field[pos] < *field[pos * 2] && (n>pos * 2 + 1 ? *field[pos * 2] > *field[pos * 2 + 1] : true))
		{
			swapDatShit(pos, pos * 2);
			pos = pos * 2;
		}
		else if (pos * 2 + 1 <= n && *field[pos] < *field[pos * 2 + 1])
		{
			swapDatShit(pos, pos * 2 + 1);
			pos = pos * 2 + 1;
		}
		else
			break;
	}
}

inline void PrioQueue::swapDatShit(unsigned a, unsigned b)
{
	PrioElement* buf;
	buf = field[a];
	field[a] = field[b];
	field[b] = buf;
}

inline void PrioQueue::update(int id, int d)
{
	n = lenght - 1;

	unsigned int pos = getPos(id);
	if (pos == 0) return;

	if (id > lenght-1) 
	{
		cout << "id groesser als Feldlaenge" << endl;
		return;
	}
	if (d==0)
	{
		cout << "Keine Aenderungen vorgenommen: d=0" << endl;
		return;
	}

	field[pos]->set_priority(field[pos]->priority() + d);

	for (size_t i = 1; i < lenght; i++)
	{
		upHeap();
		n--;
	}

	n = lenght - 1;
}

inline void PrioQueue::remove(int id)
{
	usigned int pos = getPos(id);
	if (pos == 0) return;

	swapDatShit(pos, n);
	n--;
	downHeap();
}


inline unsigned int PrioQueue::getPos(unsigned int id)
{
	for (size_t i = 1; i < n; i++)
	{
		if (field[i]->getId() == id)
			return i;
	}
	return 0;
}