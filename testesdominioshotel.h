#ifndef TESTESDOMINIOSHOTEL_H
#define TESTESDOMINIOSHOTEL_H

#include<string>
#include <stdexcept>
#include "dominioshotel.h"

using namespace std;

//Testes referentes ao tipo capacidade de acomodação
class TUCapacidadeDeAcomodacao
{
    private:

    const static int VALOR_VALIDO = 5;
    const static int VALOR_INVALIDO = 15;

    CapacidadeDeAcomodacao* capacidade;

    //Estado do Teste
    int estado;

    //Declaração dos métodos
    void SetUp();
    void TearDown();
    void TestarCenarioSucesso();
    void TestarCenarioFalha();

    public:

    const static int SUCESSO =  0;
    const static int FALHA   = -1;

    int Run();
};

//Testes referentes ao objeto Diaria
class TUDiaria
{
    private:

    const static float VALOR_VALIDO = 250;
    const static float VALOR_INVALIDO = 12000;

    Diaria* diaria;

    //Estado do Teste
    int estado;

    //Declaração dos métodos
    void SetUp();
    void TearDown();
    void TestarCenarioSucesso();
    void TestarCenarioFalha();

    public:

    const static int SUCESSO =  0;
    const static int FALHA   = -1;

    int Run();
};

//Testes referentes ao objeto Data
class TUData
{
    private:

    string VALOR_VALIDO = "01/08/2003";
    string VALOR_INVALIDO = "10/04/1999";

    Data* data;

    //Estado do Teste
    int estado;

    //Declaração dos métodos
    void SetUp();
    void TearDown();
    void TestarCenarioSucesso();
    void TestarCenarioFalha();

    public:

    const static int SUCESSO =  0;
    const static int FALHA   = -1;

    int Run();
};

//Testes referentes ao objeto Estado
class TUEstado
{
    private:

    string VALOR_VALIDO = "TO";
    string VALOR_INVALIDO = "AA";

    Estado* estado;

    //Estado do Teste
    int estado_teste;

    //Declaração dos métodos
    void SetUp();
    void TearDown();
    void TestarCenarioSucesso();
    void TestarCenarioFalha();

    public:

    const static int SUCESSO =  0;
    const static int FALHA   = -1;

    int Run();
};
#endif // TESTESDOMINIOSHOTEL_H
