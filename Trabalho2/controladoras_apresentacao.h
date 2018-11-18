#ifndef CONTROLADORAS_APRESENTACAO_H_
#define CONTROLADORAS_APRESENTACAO_H_

#include "dominios_hotel.h"
#include "dominios_usuario.h"
#include "entidades.h"
#include "interfaces.h"
#include <list>
#include <iterator>
#include "dominios_usuario.h"
#include "controladoras_servico.h"

using namespace std;

//Classe Controladora na navegação-------------------------------------
class CntrNavegacaoInicial:public INavegacao{
        //Constantes para identificar a opção escolhida.
        static const unsigned int NUMERO_OPCOES = 2;
        static const unsigned int OPCAO_ENCERRAR = 0;
        static const unsigned int OPCAO_REGISTRAR_USUARIO = 1;
        static const unsigned int OPCAO_LOGAR_USUARIO = 2;

        void apresentarOpcoes();
public:
       CntrNavegacaoInicial(){}
       void executar();
};

//Classe controladora da apresentação do usuário--------------------------
class CntrAprUsuario:public IAprUsuario {

private:
    // Referencia para o servidor
    IServUsuario *cntr_serv_usuario;
public:
    bool CadastrarUsuario() throw(runtime_error);
    Usuario* AutenticarUsuario() throw(runtime_error);
    void SetCntrAprUsuario(IServUsuario*);
};

void inline CntrAprUsuario::SetCntrAprUsuario(IServUsuario *cntr_serv_usuario){
    this->cntr_serv_usuario = cntr_serv_usuario;
}

#endif