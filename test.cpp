#include<iostream>
#include<cstdlib>
using namespace std;

template<typename T>
struct  Node
{
	T data;
	Node* next;
	Node* prior;
};
template<typename T>
class ListSet
{
public:
	ListSet() :length(0)
	{
		head = new Node<T>;
		head->next = head;
		head->prior = head;
	}
	ListSet(const ListSet<T>& Set):length(0)
	{
		head = new Node<T>;
		head->next = head;
		head->prior = head;
		Node<T>* p = Set.GetelementNode(1);
		for (int i = 1; i <= Set.getlength(); i++)
		{
			this->push(p->data);
			p = p->next;
		}
	}
	~ListSet()
	{
		while (length)  pop();
		delete head;
	}
	int getlength()const { return length; }
	int findRepeated(T element)
	{
		Node<T>* p = head;
		for (int i = 1; i <= length; i++)
		{
			p = p->next;
			if (element == p->data) return i;
		}
		return 0;
	}          
	void push(T  element)
	{
		if (findRepeated(element))
		{
			cout << "element repeated is not supported by set" << endl;
			return;
		}
		Node<T>* s = new Node<T>;
		s->data = element;
		head->prior->next = s;
		s->prior = head->prior;
		s->next = head;
		head->prior = s;
		length++;
	}
	void pop()
	{
		Node<T>*s = new Node<T>;
		s = head->prior;
		s->next = head;
		head->prior = s->prior;
		delete s;
		length--;
	}
	void deleteelement(int index)
	{
		if (index <= 0 || index > length)
		{
			cout << "the index which is to be deleted out of range" << endl;
			return;
		}
		int i = 0;
		Node<T>*p = head;
		while (i != index)
		{
			p = p->next;
			i++;
		}
		Node<T>* s = new Node<T>;
		s = p;
		s->prior->next = s->next;
		s->next->prior = s->prior;
		delete s;
		length--;
	}
	void insert(int index, T element)
	{
		if (index > length || index <= 0)
		{
			cout << "the index which is to be inserted out of range" << endl;
			return;
		}
		if (isRepeated(element))
		{
			cout << "element repeated is not supported by set" << endl;
			return;
		}
		int i = 0;
		Node<T>*p = head;
		while (i != index - 1 && p != NULL)
		{
			p = p->next;
			i++;
		}
		Node<T>* s = new Node<T>;
		s->data = element;
		s->next = p->next;
		s->prior = p;
		p->next = s;
		s->next->prior = s;
		length++;
	}
	void print()
	{
		if (!length)
		{
			cout << "no element" << endl;
			return;
		}
		Node<T>*p = head;
		for (int i = 1; i <= length; i++)
		{
			p = p->next;
			cout << p->data << " ";
		}
		cout << endl;
	}
	T& operator[](int index)
	{
		if (index <= 0 || index > length)
		{
			cout << "the index which is to be got out of range" << endl;
			exit(7);
		}
		int i = 0;
		Node<T>* p = head;
		while (i != index)
		{
			p = p->next;
			i++;
		}
		return p->data;
	}
	Node<T>* GetelementNode(int index)const
	{
		if (index <= 0 || index > length)
		{
			cout << "the index which is to be got out of range" << endl;
			exit(7);
		}
		int i = 0;
		Node<T>* p = head;
		while (i != index)
		{
			p = p->next;
			i++;
		}
		return p;
	}
	void MinusAnotherSet(ListSet & set)
	{
		for (int j = 1; j <= set.getlength(); j++)
		{
				int index = findRepeated(set[j]);   
				if (index) deleteelement(index);   
		}
	}
	friend ListSet<T> UnionSet(ListSet<T>& Set1, ListSet<T>& Set2)
	{
		ListSet<T> Set = Set1;                 
		for (int i = 1; i <= Set2.length; i++)   
		{
			int  a = Set2[i];                      
			if (!Set1.findRepeated(a)) Set.push(a);  
		}                                         
		return Set;                                
	}
	friend ListSet<T> IntersectionSet(ListSet<T> & Set1, ListSet<T> &Set2)
	{
		ListSet<T> Set;     
		for (int i = 1; i <= Set2.length; i++)
		{
			int  a = Set2[i];         
			if (Set1.findRepeated(a)) Set.push(a);   
		}                             
		return Set;
	}
private:
	Node<T>* head;
	int length;
};

int main()
{
	ListSet<int>A, B;
	A.push(2);
    	A.push(1);

	A.push(6);
	A.push(2);
	A.push(8);
	A.push(9);
	B.push(1);
	B.push(6);
	B.push(7);
	cout << "A:";
	A.print();
	cout << "B:";
	B.print();
	ListSet<int>C1 = UnionSet(A, B);
	cout << "A∪B:";
	C1.print();
	ListSet<int>C2 = IntersectionSet(A,B);
	cout << "A∩B:";
	C2.print();
	cout << "execued A=A-B....." << endl;
	A.MinusAnotherSet(B);
	cout << "A:";
	A.print();
	return 0;
}
