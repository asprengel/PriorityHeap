#pragma once


class PrioQueue
{
public:
	PrioQueue(int length = 1000);
	PrioElement& maximum() const;
	PrioElement extractMax();
	void insert(const int num);

private:
	void upHeap();
	void downHeap();
	void swapDatShit(unsigned a, unsigned b);

	int n;
	unsigned int lenght;
	PrioElement **field;
};

inline PrioQueue::PrioQueue(int length)
{
	this->lenght = length + 1;
	n = 0; 
	field = new PrioElement*[this->lenght + 1];
	field[0] = NULL;
	for (size_t i = 1; i < this->lenght + 1; i++)
	{
		field[i] = new PrioElement();
	}
}


PrioElement & PrioQueue::maximum() const
{
	return *field[lenght];
}

PrioElement PrioQueue::extractMax()
{
	PrioElement max = *field[1];
	swapDatShit(1, lenght);
	downHeap();
	lenght--;
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
	if (pos == 1) return;
	while (pos > 1 && *field[pos / 2] < *field[pos]) { swapDatShit(pos / 2, pos); pos = pos / 2; }

	for (size_t i = 1; i < n; i++)
	{
		cout << *field[i] << "\t";
	}
	cout << endl;
}

void PrioQueue::downHeap()
{
	unsigned int pos = 1;

	while (true)
	{

		if (lenght <= pos * 2 && *field[pos] < *field[pos * 2] && *field[pos * 2] < *field[pos * 2 + 1])
		{
			swapDatShit(pos, pos * 2);
			pos = pos * 2;
		}
		else if (lenght <= pos * 2 + 1 && *field[pos] < *field[pos * 2 + 1])
		{
			swapDatShit(pos, pos * 2 + 1);
			pos = pos * 2 + 1;
		}
		else
			break;
	}
}

void PrioQueue::swapDatShit(unsigned a, unsigned b)
{
	PrioElement* buf;
	buf = field[a];
	field[a] = field[b];
	field[a] = buf;
}
