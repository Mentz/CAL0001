#ifndef _I_STRUCTS_
#define _I_STRUCTS_

#include <string>
#include <vector>
#include <map>

class Data {
public:
	int ordem;
	std::string nome;
	std::string sobrenome;

	Data()
	{
		Data(0, "", "");
	}

	Data(int n, std::string p, std::string s)
	{
		this->ordem     = n;
		this->nome      = p;
		this->sobrenome = s;
	}

	Data(const Data &d)
	{
		this->ordem     = d.ordem;
		this->nome      = d.nome;
		this->sobrenome = d.sobrenome;
	}

	int operator == (Data &b)
	{
		return (this->nome == b.nome && this->sobrenome == b.sobrenome);
	}

	void operator = (Data &b){
		this -> ordem = b.ordem;
		this -> nome = b.nome;
		this -> sobrenome = b.sobrenome;
	}
};

class DataStructure {
public:
	virtual void insert(Data d)
	{
		return;
	}

	virtual int  find(Data d)
	{
		return -1;
	}
};

double inline getSeconds(clock_t t0, clock_t t1)
{
	return (t1 - t0) / (double)CLOCKS_PER_SEC;
}

#endif
