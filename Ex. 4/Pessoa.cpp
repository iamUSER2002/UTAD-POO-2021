#include "Pessoa.h"

Pessoa::Pessoa()
	:nome(""), morada("")
{
}

Pessoa::Pessoa(string nome, Data dataN, string morada)
	:nome(nome), dataN(dataN), morada(morada)
{
}

Pessoa::~Pessoa()
{
}

void Pessoa::Show(void)
{
	cout << "Nome: " << nome << endl;
	dataN.Show();
	cout << "Morada: " << morada << endl;
}

void Pessoa::ReadK(void)
{
	cout << "Nome: ";
	getline(cin, nome);
	cout << "Data: ";
	cin >> dataN;
	cout << "Morada: ";
	cin.ignore();
	getline(cin, morada);
}

void Pessoa::MaisNovo(const Pessoa& P)
{
	if (dataN == P.dataN)
	{
		cout << "As duas pessoas t�m a mesma idade." << endl;
		return;
	}
	cout << "Pessoa mais nova: ";
	if (dataN < P.dataN) // overload do operador '<' na classe Data
	{
		cout << "Pessoa mais nova: " << *this;
	}
	else cout << "Pessoa mais nova: " << P;
}

void Pessoa::ReadFile(ifstream& ifs)
{
	getline(ifs, nome, ';');
	dataN.ReadFile(ifs);
	ifs.ignore(); // ignorar o ';'
	getline(ifs, morada, ';');
}

void Pessoa::SaveFile(ofstream& ofs)
{
	ofs << nome << ';';
	dataN.SaveFile(ofs);
	ofs << ';';
	ofs << morada << ';';
}

bool Pessoa::operator==(const Pessoa& P)
{
	return (nome == P.nome
		&& dataN == P.dataN
		/*&& morada == P.morada*/);
}

bool Pessoa::operator!=(const Pessoa& P)
{
	return !(*this == P);
}

ostream& operator<<(ostream& os, const Pessoa& P)
{
	os << "Nome: " << P.nome << endl;
	os << "Data: " << P.dataN << endl;
	os << "Morada: " << P.morada << endl;
	return os;
}

istream& operator>>(istream& is, Pessoa& P)
{
	// cout << "Nome: ";
	getline(is, P.nome);
	// cout << "Data: ";
	is >> P.dataN;
	is.ignore();
	// cout << "Data: ";
	getline(is, P.morada);
	return is;
}