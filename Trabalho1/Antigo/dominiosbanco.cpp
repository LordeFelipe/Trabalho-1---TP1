#include <iostream>
#include "dominiosbanco.h"

// Definições de métodos:

// Agencia:
void Agencia::Validar(string agencia) throw (invalid_argument){
	// Lança exceção se a string tiver menos ou mais que 5 dígitos
	if(agencia.length() != N_CARAC){
		throw invalid_argument("Número de caracteres invalido.");
		return;
	}

	// Lança exceção se a string não conter apenas números
	for(int i = 0; i < N_CARAC; i++){
		if(agencia.at(i) < LIMITE_INF || agencia.at(i) > LIMITE_SUP){
			throw invalid_argument("Contem carcteres invalidos.");
			return;
		}
	}
}

void Agencia::SetAgencia(string agencia) throw (invalid_argument){
	Validar(agencia);
	this->agencia = agencia;
}

// Banco:
void Banco::Validar(string banco) throw (invalid_argument){
	// Lança exceção se a string tiver menos ou mais que 3 dígitos
	if(banco.length() != N_CARAC){
		throw invalid_argument("Número de caracteres invalido.");
		return;
	}

	// Lança exceção se a string não conter apenas números
	for(int i = 0; i < N_CARAC; i++){
		if(banco.at(i) < LIMITE_INF || banco.at(i) > LIMITE_SUP){
			throw invalid_argument("Contem carcteres invalidos.");
			return;
		}
	}
}

void Banco::SetBanco(string banco) throw (invalid_argument){
	Validar(banco);
	this->banco = banco;
}

// NumeroConta:
void NumeroConta::Validar(string conta) throw (invalid_argument){
	// Lança exceção se a string tiver menos ou mais que 6 dígitos
	if(conta.length() != N_CARAC){
		throw invalid_argument("Número de caracteres invalido.");
		return;
	}

	// Lança exceção se a string não conter apenas números
	for(int i = 0; i < N_CARAC; i++){
		if(conta.at(i) < LIMITE_INF || conta.at(i) > LIMITE_SUP){
			throw invalid_argument("Contem carcteres invalidos.");
			return;
		}
	}
}

void NumeroConta::SetConta(string conta) throw (invalid_argument){
	Validar(conta);
	this->numero = conta;
}

// NUmeroCartao:
void NumeroCartao::Validar(string cartao) throw (invalid_argument){
	// Lança exceção se a string tiver menos ou mais que 16 dígitos
	if(cartao.length() != N_CARAC){
		throw invalid_argument("Número de caracteres invalido.");
		return;
	}

	// Lança exceção se a string não conter apenas números
	for(int i = 0; i < N_CARAC; i++){
		if(cartao.at(i) < LIMITE_INF || cartao.at(i) > LIMITE_SUP){
			throw invalid_argument("Contem carcteres invalidos.");
			return;
		}
	}

	// Lança exceção caso o número do cartão seja inválido
	int nDigitos = cartao.length();

    int nSoma = 0, ehSegundo = false;
    for (int i = nDigitos - 1; i >= 0; i--) {

        int d = cartao[i] - 'a';

        if (ehSegundo == true)
            d = d * 2;

        // Nos adicionamos dois digitos para lidar
        // com casos que tem dois digitos depois de dobrar
        nSoma += d / 10;
        nSoma += d % 10;

        ehSegundo = !ehSegundo;
    }
    if(nSoma % 10 != 0){
    	throw invalid_argument("Numero de Cartao invalido.");
    }
}

void NumeroCartao::SetNumero(string cartao) throw (invalid_argument){
	Validar(cartao);
	this->numero = cartao;
}

// Validade:
void Validade::Validar(string data) throw (invalid_argument){
	// Lança exceção se a string tiver menos ou mais que 5 dígitos
	if(data.length() != N_CARAC){
		throw invalid_argument("Número de caracteres invalido.");
		return;
	}

	// Lança exceção se o caractere do meio não for '/'
	if(data.at(2) != '/'){
		throw invalid_argument("Falta de caractere '/' para separar mes e ano");
		return;
	}

	// Lança exceção se o ano não conter apenas números
	for(int i = 3; i < N_CARAC; i++){
		if(data.at(i) < LIMITE_INF || data.at(i) > LIMITE_SUP){
			throw invalid_argument("Contem carcteres invalidos no ano.");
			return;
		}
	}

	// Lança exceção para meses inválidos
	if(data.at(0) == '0'){
		if(data.at(1) < '1' || data.at(1) > '9'){
			throw invalid_argument("Mes Invalido.");
			return;
		}
	}
	else if(data.at(0) == '1'){
		if(data.at(1) < '0' || data.at(1) > '2'){
			throw invalid_argument("Mes Invalido.");
			return;
		}
	}
	else{
		throw invalid_argument("Mes Invalido.");
		return;
	}
}

void Validade::SetVal(string data) throw (invalid_argument){
	Validar(data);
	this->data = data;
}
