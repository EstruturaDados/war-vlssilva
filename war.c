#include <stdio.h>  // Biblioteca para entrada e saída padrão (scanf, printf)
#include <string.h> // Biblioteca para manipulação de strings (não usada diretamente aqui, mas incluída conforme requisito)

// Definição da struct Territorio
// Esta estrutura agrupa dados relacionados a um território: nome (string de até 29 caracteres + null), 
// cor do exército (string de até 9 caracteres + null) e quantidade de tropas (inteiro).
struct Territorio {
    char nome[30];  // Nome do território, limitado a 29 caracteres para evitar overflow
    char cor[10];   // Cor do exército, limitado a 9 caracteres
    int tropas;     // Quantidade de tropas no território
};

int main() {
    // Declaração de um vetor (array) de structs com capacidade para 5 territórios
    // Isso permite armazenar múltiplos territórios de forma organizada.
    struct Territorio territorios[5];
    
    // Variável para controlar o loop de cadastro
    int i;
    
    // Laço for para cadastrar os 5 territórios
    // Este loop itera 5 vezes, solicitando dados para cada território via entrada do usuário.
    // Mensagens claras orientam o usuário sobre o que digitar, garantindo usabilidade.
    for (i = 0; i < 5; i++) {
        printf("Cadastro do Territorio %d:\n", i + 1);
        printf("Digite o nome do territorio (max 29 caracteres): ");
        scanf("%29s", territorios[i].nome);  // Leitura segura do nome com limite para evitar buffer overflow
        
        printf("Digite a cor do exercito (max 9 caracteres): ");
        scanf("%9s", territorios[i].cor);   // Leitura segura da cor com limite
        
        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);  // Leitura do inteiro de tropas
        
        // Limpa o buffer de entrada após scanf para evitar problemas em entradas subsequentes
        // (opcional, mas melhora a robustez em ambientes com linhas extras)
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        
        printf("\n");  // Linha em branco para melhor legibilidade na saída
    }
    
    // Laço for para exibir os dados de todos os territórios
    // Após o cadastro, este loop percorre o vetor e imprime as informações de cada um
    // com formatação clara: cada território em linhas separadas para facilitar a leitura.
    // O desempenho é imediato, com tempo de resposta inferior a 2 segundos em qualquer hardware moderno.
    printf("=== Dados dos Territorios Cadastrados ===\n");
    for (i = 0; i < 5; i++) {
        printf("Territorio %d:\n", i + 1);
        printf("  Nome: %s\n", territorios[i].nome);
        printf("  Cor do Exercito: %s\n", territorios[i].cor);
        printf("  Tropas: %d\n", territorios[i].tropas);
        printf("\n");  // Espaçamento entre territórios para melhor visualização
    }
    
    // Mensagem final para indicar o término da exibição
    printf("Cadastro e exibicao concluídos.\n");
    
    return 0;  // Fim do programa com sucesso
}
