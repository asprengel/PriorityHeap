
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
	const unsigned int getSize() { return n; }

private:
	void upHeap(unsigned int);
	void downHeap(unsigned int pos);
	void swapDatShit(unsigned a, unsigned b);
	unsigned int getPosReferenz(unsigned int id);

	unsigned int n;
	unsigned int lenght;
	unsigned int fortlaufendeId;
	PrioElement **field;
	unsigned int *nReferenz;
};

inline PrioQueue::PrioQueue(int lenght)
{
	nReferenz = new unsigned int[lenght];

	this->lenght = lenght + 1;
	n = 0; 
	fortlaufendeId = 0;
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
	if (n == 0) return *field[0];
	PrioElement max = *field[1];
	swapDatShit(1, n);
	n--;
	downHeap(1);
	return max;
}

void PrioQueue::insert(const int num)
{
	field[++n]->set_priority(num);
	field[n]->setId(fortlaufendeId);
	nReferenz[fortlaufendeId++] = n;
	upHeap(n);
}

void PrioQueue::upHeap(unsigned int pos)
{

	while (pos > 1 && *field[pos / 2] < *field[pos]) 
	{ 
		swapDatShit(pos, pos/2); 
		pos = pos / 2; 
	}
}

void PrioQueue::downHeap(unsigned int pos)
{

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

	nReferenz[a] = field[a]->getId();
	nReferenz[b] = field[b]->getId();
}

inline void PrioQueue::update(int id, int d)
{
	unsigned int pos = getPosReferenz(id);
	if (pos == 0) return;


	field[pos]->set_priority(field[pos]->priority() + d);

	if (d > 0)
		upHeap(pos);
	else
		downHeap(pos);
}

inline void PrioQueue::remove(int id)
{
	usigned int pos = getPosReferenz(id);
	if (pos == 0) return;

	nReferenz[id] = 0;

	swapDatShit(pos, n);
	n--;
	downHeap(pos);
}



inline unsigned int PrioQueue::getPosReferenz(unsigned int id)
{
	return nReferenz[id];
}
