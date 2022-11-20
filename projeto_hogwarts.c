#include <stdio.h> // biblioteca de interação com o usuário, input output

#include <stdlib.h> // alocação de memória, "standard library"

#include <locale.h> // setlocale para portugues

#include <windows.h> // necessário para o Sleep

#define ANO_ATUAL 2022

void carta(char *sobrenome);

int main()
{

    setlocale(LC_ALL, "Portuguese");

    char nome[20], sobrenome[20]; // nome do usuário
    int ano_nasc, idade;
    int tempo;        // tempo para completar 11 anos
    int respostas[3]; // mudar tudo pra %i
    int soma_resp;    // quiz pt 1
    char resp;        // decisão s/n quiz
    float distancia;  // distância até a referência
    float tempoSeg;   // tempo de chegada da cartinha
    int seg;
    int min;
    int ms = 0.0001; // Variável que representa a "velocidade" do cronometro em milisegundos --> 1 = 1 milisegundo, 1000 = 1s.
    int hor;

    // Parte introdutória feita apenas para o desenvolvimento da parte inferior a 11 anos.
    printf("BEM-VINDO AO SISTEMA DO MINISTERIO DA MAGIA\n");
    printf("\n");

    printf("Insira o seu nome e sobrenome [Exemplo: Harry Potter]:\n"); // recebe nome do usuário
    scanf("%s %s", &nome, &sobrenome);

    printf("Insira o ano de nascimento:\n");
    scanf("%i", &ano_nasc);
    printf("\n");
    system("cls");

    // Cálculo simples da idade do usuário.
    idade = ANO_ATUAL - ano_nasc;

    // se o usuário tiver menos que 11 anos:
    if (idade >= 0 && idade < 11)
    {
        do
        {
            if (resp != '\n')
            {
                printf("Gostaria de fazer nosso teste para saber qual pode ser a sua casa de Hogwarts? \n"
                       "Digite \"s\" para \"Sim\" e \"n\" para \"Não\"\n");
            }
            scanf("%c", &resp);
        } while (resp != 's' && resp != 'n');

        // O switch foi utilizado para dar liberdade ao usuario de escolher se quer ou nao..
        // participar do teste!
        switch (resp)
        {
        case 's':
            printf("Magnifico! Iremos dar inicio ao seu teste imediatamente!\n");
            printf("\n");
            printf("\n");
            system("cls");
            printf("QUIZ SOBRE CONHECIMENTOS DO MUNDO MAGICO:\n");
            printf("\n");

            do
            {
                printf("Qual sua cor preferida?\n");
                printf("1-AZUL / 2-VERMELHO / 3-VERDE / 4-AMARELO \n");
                scanf("%i", &respostas[1]);
                printf("\n");
                if (respostas[1] < 0 || respostas[1] > 4)
                {
                    printf("Era para ter digitado um valor entre 1 e 4\n"
                           "Voce nao sabe ler? Os dementadores sugaram todos os seus neuronios?\n"
                           "Pelo visto a carta de Hogwarts nao se perdeu, ela encontrou um caminho melhor!\n"
                           "Voce pertence ao mundo trouxa!");
                    printf("\n\n");
                }
            } while (respostas[1] < 0 || respostas[1] > 4);

            do
            {
                printf("Qual animal voce prefere?\n");
                printf("1-AGUIA / 2-LEAO / 3-COBRA / 4-GUAXINIM \n");
                scanf("%i", &respostas[2]);
                printf("\n");
                if (respostas[2] < 0 || respostas[2] > 4)
                {
                    printf("Era para ter digitado um valor entre 1 e 4\n"
                           "Voce nao sabe ler? Os dementadores sugaram todos os seus neuronios?\n"
                           "Pelo visto a carta de Hogwarts nao se perdeu, ela encontrou um caminho melhor!\n"
                           "Voce pertence ao mundo trouxa!");
                    printf("\n\n");
                }
            } while (respostas[2] < 0 || respostas[2] > 4);

            do
            {
                printf("Com qual caracteristica voce se identifica mais?\n");
                printf("1-INTELIGENTE / 2-CORAJOSO / 3-BRAVO / 4-BONZINHO \n");
                scanf("%i", &respostas[3]);
                printf("\n");
                if (respostas[3] < 0 || respostas[3] > 4)
                {
                    printf("Era para ter digitado um valor entre 1 e 4\n"
                           "Voce nao sabe ler? Os dementadores sugaram todos os seus neuronios?\n"
                           "Pelo visto a carta de Hogwarts nao se perdeu, ela encontrou um caminho melhor!\n"
                           "Voce pertence ao mundo trouxa!");
                    printf("\n\n");
                }
            } while (respostas[3] < 0 || respostas[3] > 4);

            // Organização da resposta do quiz
            soma_resp = respostas[1] + respostas[2] + respostas[3];

            system("cls");
            printf("Prezado/a Sr./Sra %s, \n\n", sobrenome);

            // Estrutura if para a decisão de qual pode ser a casa do usuário.
            if (soma_resp > 0 && soma_resp <= 3)
            {
                printf("A sua casa pode vir a ser Corvinal!");
                printf("\n");
            }
            else if (soma_resp > 3 && soma_resp <= 6)
            {
                printf("A sua casa pode vir a ser Grifinória!");
                printf("\n");
            }
            else if (soma_resp > 6 && soma_resp <= 9)
            {
                printf("A sua casa pode vir a ser Sonserina!");
                printf("\n");
            }
            else
            {
                printf("A sua casa pode vir a ser Lufa-Lufa!");
                printf("\n");
            }
            break;

        case 'n':
            printf("Tudo bem, aguarde calmamente a sua cartinha!\n");
            printf("\n");
            break;
        default:
            printf("Não sabe digitar corretamente? Os dementadores sugaram todos os seus neurônios?\n"
                   "Da próxima vez, digite (s/n), com letras minúsculas");
            printf("\n");
            break;
        }
        // Cálculo simples do tempo faltante para o usuário completar 11 anos.
        tempo = 11 - idade;
        printf("E faltam %i anos para voce receber a sua carta de hogwarts!\n\n", tempo);
    }
    else if (idade == 11)
    {
        printf("Insira a sua distância até a escola de magia em km: "); // recebe distância até a referência (SP)
        scanf("%f", &distancia);

        // calcula tempo para chegada da carta (em segundos)
        tempo = (distancia * 1000) / 20; // s = m/(m/s)
        system("cls");                     // clear screen

        seg = tempo;

        if (seg % 60 == 0)
        {                               // se seg = 60
            min = ((min + (seg / 60))); // min = 1
            seg = 0;
        }
        else
        {
            if (seg > 60)
            {                               // se passar de 60 segundos
                min = ((min + (seg / 60))); // min é o quociente da divisão seg/60
                seg = ((seg % 60));         // seg é o resto
                                            /* ex.: tempo = 135
                                            min = 135 / 60 = 2
                                            seg = 135 % 60 = 15
                                            2minutos e 15 segundos
                                            */
            }
        }
        if (min % 60 == 0)
        {                               // se min = 60
            hor = ((hor + (min / 60))); // hor = 1
            min = 0;
        }
        else if (min > 60)
        {                               // se passar de 1h
            hor = ((hor + (min / 60))); // hor é o quociente da divisão min / 60
            min = ((min % 60));         // min é o restocalc
        }

        for (seg, hor, min;; seg--)
        { // descrecem os segundos == contagem regressiva
            if (hor == 0 && min == 0 && seg == 0 || seg < 0)
            {                  // quando o tempo acaba ou seg < 0
                system("cls"); // limpa a tela
                printf("Sua carta chegou!\n");
                carta(sobrenome); // exibe conteúdo da carta
                return 0;
            }              // se o cronômetro ainda não zerou,
            system("cls"); // limpa a tela e exibe o cronômetro
            printf("\n\t Sua carta chegará em %02i horas, %02i min e %02i segundos!", hor, min, seg);
            Sleep(ms); // sistema pausa por tempo determinado pela variável "ms"

            if (seg == 0)
            {                   // quando seg = 0,
                min--;          // decresce minuto
                seg = seg + 60; // seg = 60
            }
            if (min < 0)
            {                   // quando minuto é "negativo",
                hor--;          // decresce hora
                min = min + 60; // min = 60
            }
        }
    }
    else if (idade > 11)
    {
        do
        {
            if (resp != '\n') // se o enter não for digitado
            {
                printf("Gostaria de realizar o nosso teste e enviar seu currículo para o Ministério da Magia? \n"
                       "Digite \"s\" para \"Sim\" e \"n\" para \"Não\"\n");
            }
            scanf("%c", &resp);
        } while (resp != 's' && resp != 'n');

        switch (resp) // O switch foi utilizado para dar liberdade ao usuario de escolher se quer ou nao..
        // participar do teste!
        {
        case 's':
            printf("Magnífico! Iremos dar início ao seu teste imediatamente!\n");
            printf("\n");
            printf("\n");

            system("cls");
            printf("BEM-VINDO AO TESTE DE RECRUTAMENTO DO MINISTÉRIO DA MAGIA \n");
            printf("\n");

            do
            {
                printf("Qual foi a sua matéria preferida do Ensino Médio trouxa?\n");
                printf("1-HISTÓRIA / 2-MATEMÁTICA / 3-BIOLOGIA / 4-FÍSICA \n");
                scanf("%i", &respostas[1]);
                printf("\n");
                if (respostas[1] < 0 || respostas[1] > 4)
                {
                    printf("Era para ter digitado um valor entre 1 e 4\n"
                           "Você não sabe ler? Os dementadores sugaram todos os seus neurônios?\n"
                           "Pelo visto a carta de Hogwarts não se perdeu, ela encontrou um caminho melhor!\n"
                           "Você pertence ao mundo trouxa!");
                    printf("\n\n");
                }
            } while (respostas[1] < 0 || respostas[1] > 4);

            do
            {
                printf("Qual criatura abaixo voce mais se identifica?\n");
                printf("1-VAMPIRO / 2-LOBISOMEN / 3-SEREIAS / 4-ELFOS \n");
                scanf("%i", &respostas[2]);
                printf("\n");
                if (respostas[2] < 0 || respostas[2] > 4)
                {
                    printf("Era para ter digitado um valor entre 1 e 4\n"
                           "Você não sabe ler? Os dementadores sugaram todos os seus neurônios?\n"
                           "Pelo visto a carta de Hogwarts não se perdeu, ela encontrou um caminho melhor!\n"
                           "Você pertence ao mundo trouxa!");
                    printf("\n\n");
                }
            } while (respostas[2] < 0 || respostas[2] > 4);

            do
            {
                printf("Com qual caracteristica voce se identifica mais?\n");
                printf("1-INTELIGENTE / 2-CORAJOSO / 3-BRAVO / 4-BONZINHO \n");
                scanf("%i", &respostas[3]);
                printf("\n");
                if (respostas[3] < 0 || respostas[3] > 4)
                {
                    printf("Era para ter digitado um valor entre 1 e 4\n"
                           "Você não sabe ler? Os dementadores sugaram todos os seus neurônios?\n"
                           "Pelo visto a carta de Hogwarts não se perdeu, ela encontrou um caminho melhor!\n"
                           "Você pertence ao mundo trouxa!");
                    printf("\n\n");
                }
            } while (respostas[3] < 0 || respostas[3] > 4);

            soma_resp = respostas[1] + respostas[2] + respostas[3];

            if (soma_resp > 0 && soma_resp <= 3)
            {
                printf("VOCÊ PODE TRABALHAR NO TRIBUNAL DE DEFESA DAS CRIATURAS MÁGICAS DO MINISTÉRIO DA MAGIA!");
                printf("\n");
            }
            else if (soma_resp > 3 && soma_resp <= 6)
            {
                printf("VOCÊ PODE TRABALHAR NO BANCO GRINGOTES JUNTO COM OS DUENDES");
                printf("\n");
            }
            else if (soma_resp > 6 && soma_resp <= 9)
            {
                printf("VOCÊ PODE TRABALHAR COMO ESPIÃO DO MINISTÉRIO SECRETO DA MAGIA!");
                printf("\n");
            }
            else
            {
                printf("Era para ter digitado um valor entre 1 e 4\n"
                       "Você não sabe ler? Os dementadores sugaram todos os seus neurônios?\n"
                       "Pelo visto a carta de Hogwarts não se perdeu, ela encontrou um caminho melhor!\n"
                       "Você pertence ao mundo trouxa!");
                printf("\n\n");
            }

            break;
        case 'n':
            printf("Infelizmente você é apenas mais um na estatística de bruxos desempregados!\n"
                   "Espero que aproveite sua vida, trouxa");
            printf("\n");
            printf("\n");
            break;
        default:
            printf("Não sabe digitar corretamente? Os dementadores sugaram todos os seus neurônios?\n"
                   "Da próxima vez, digite (s/n), com letras minúsculas");
            printf("\n");
            printf("\n");
            break;
        }
    }
    else
    {
        printf("Você não tem a pedra filosofal para estar vivo a tanto tempo!");
    }

    return 0;
}

void carta(char *sobrenome)
{
    printf("\t\t\t\t\tESCOLA DE MAGIA E BRUXARIA DE HOGWARTS\n"
           "\n\nDiretor: Alvo Dumbledore"
           "\n(Ordem de Merlim, Primeira Classe, Grande Feiticeiro, Bruxo Chefe, Cacique Supremo, Confederação Internacional de Bruxos)"
           "\n\nPrezado/a Sr./Sra %s,"
           "\n\nTemos o prazer de informar que V. Sa. tem uma vaga na Escola de Magia e Bruxaria de Hogwarts."
           "\nEstamos anexando uma lista dos livros e equipamentos necessários."
           "\nO ano letivo começa em 1o de setembro. Aguardamos sua coruja até 31 de julho, no mais tardar."
           "\n\nAtenciosamente,"
           "\n\nMinerva McGonagall"
           "\nDiretora Substituta", sobrenome);
}
