#include <iostream>

using namespace std;

struct node
{
	int val;
	node* next;
};

void Add(node*& H, int x) //dodawanie elementu na poczatek listy
{
	node* p = new node;
	p->val = x;
	p->next = H;
	H = p;
}

void Del(node*& H) //usuwanie pierwszego elementu z listy
{
	if (H != NULL)
	{
		node* p = H;
		H = H->next;
		delete p;
	}
}

void Show_list(node* H) //wyswietlanie listy
{
	cout << "H->";
	node* p = H;
	while (p != NULL)
	{
		cout << p->val << "->";
		p = p->next;
	}
	cout << "NULL" << endl;
}

void AddNext(node*& head, int pos, int value)
{
	node* nowy = new node;
	nowy->val = value;

	if (head->next != NULL || pos == 0)
	{
		node* pom = head;
		head = head->next;
		return;
	}

	node* pom = head;

	for (int i = 0; i < pos - 1; i++)
	{
		pom = pom->next;
	}
	node* e = pom->next;
	pom->next = nowy;
	nowy->next = e;
}

void DeleteEverySecond(node* H)
{
	if (H != NULL && H->next != NULL)
	{
		node* p = H;
		while (p != NULL && p->next != NULL)
		{
			node* e = p->next;
			p->next = e->next;
			delete e;
			p = p->next;
		}
	}
}

void Duplicate(node* H) // H->1->2->3 --->>> H->1->1->2->2->3->3
{
	if (H != NULL)
	{
		node* p = H;
		while (p != NULL)
		{
			Add(p->next, p->val);
			p = p->next->next;
		}
	}
}

void Copy(node* H) // // H->2->3 --->>> H->2->2->4->4->4->4
{
	if (H != NULL)
	{
		node* p = H;
		while (p != NULL)
		{
			for (int i = 1; i < p->val; i++)
			{
				Add(p->next, p->val);
				p = p->next;
			}
			p = p->next;
		}
	}
}

void UsunPodanaWartosc(node*& H, int x) //Usuñ wszystkie elementy o wartoœci x (np. 4)
{
	if (H != NULL)
	{
		while ((H->val) == x)
		{
			node* k = H;
			H = H->next;
			delete k;
		}
		node* p = H;
		while (p->next != NULL)
		{
			if (p->next->val == x)
			{
				node* e = p->next;
				p->next = e->next;
				delete e;
			}
			else
			{
				p = p->next;
			}
		}
	}
}

void UsunParzyste(node*& H) //Usuñ elementy parzyste co do wartoœci
{
	if (H != NULL)
	{
		while ((H->val) % 2 == 0)
		{
			node* k = H;
			H = H->next;
			delete k;
		}
		node* p = H;
		while (p != NULL && p->next != NULL)
		{
			if ((p->next->val) % 2 == 0)
			{
				node* e = p->next;
				p->next = e->next;
				delete e;
			}
			else
			{
				p = p->next;
			}
		}
	}
}

void UsunNieparzyste(node*& H) //Usuñ elementy nieparzyste co do wartoœci
{
	if (H != NULL)
	{
		while ((H->val) % 2 != 0)
		{
			node* k = H;
			H = H->next;
			delete k;
		}
		node* p = H;
		while (p->next != NULL)
		{
			if ((p->next->val) % 2 != 0)
			{
				node* e = p->next;
				p->next = e->next;
				delete e;
			}
			else
			{
				p = p->next;
			}
		}
	}
}

void PrzeniesParzyste(node* H) //Przenieœ elementy parzyste na koniec listy
{
	if (H != NULL)
	{
		node* p = H;
		node* T = H;
		while (p->next)
		{
			T = p->next;
			p = p->next;
		}
		node* e = H;
		while (e->next)
		{
			if ((e->next->val) % 2 == 0)
			{
				T->next = e;
				e->next = T;
				T = e->next;
			}
			e = e->next;
		}
	}
}

int ZwrocNajwiekszy(node* H)
{
	int max;
	if (H != NULL)
	{
		node* p = H;
		max = p->val;
		while (p->next)
		{
			if (p->next->val > max)
			{
				max = p->next->val;
			}
			p = p->next;
		}
	}
	return max;
}

int ZwrocNajmniejszy(node* H)
{
	int min;
	if (H != NULL)
	{
		node* p = H;
		min = p->val;
		while (p->next)
		{
			if (p->next->val < min)
			{
				min = p->next->val;
			}
			p = p->next;
		}
	}
	return min;
}

void UsunNajwiekszy(node* H)
{
	int max;
	if (H != NULL)
	{
		node* p = H;
		max = p->val;
		while (p->next)
		{
			if (p->next->val > max)
			{
				max = p->next->val;
			}
			p = p->next;
		}
	}
}

void UsunNajmniejszy(node* H)
{
	int min;
	if (H != NULL)
	{
		node* p = H;
		min = p->val;
		while (p->next)
		{
			if (p->next->val < min)
			{
				min = p->next->val;
			}
			p = p->next;
		}
	}
}

int main()
{
	node* H = NULL; // zawiera adres pocz¹tku listy
	Add(H, 4);
	Add(H, 3);
	Add(H, 19);
	Add(H, 2);
	Add(H, 8);
	Add(H, 4);
	Add(H, 1);
	Add(H, 4);
	Add(H, 4);
	Show_list(H);
	//Duplicate(H);
	//Copy(H);
	DeleteEverySecond(H);
	//UsunPodanaWartosc(H, 4);
	//Show_list(H);
	//UsunParzyste(H);
	//UsunNieparzyste(H);
	//cout << "Najwiekszy element na liscie: " << ZwrocNajwiekszy(H) << endl;
	//cout << "Najmniejszy element na liscie: " << ZwrocNajmniejszy(H) << endl;
	//Show_list(H);
	//PrzeniesParzyste(H);
	//UsunNajmniejszy(H);
	Show_list(H);

	return 0;
}