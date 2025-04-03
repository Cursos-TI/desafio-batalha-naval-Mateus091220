#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // Água representada por 0
        }
    }
}

// Função para verificar se as coordenadas são válidas e não ultrapassam os limites do tabuleiro
int coordenadasValidas(int linha, int coluna, int orientacao) {
    if (orientacao == 0) { // Horizontal
        return (coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO);
    } else if (orientacao == 1) { // Vertical
        return (linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO);
    } else if (orientacao == 2 || orientacao == 3) { // Diagonal crescente ou decrescente
        return (linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO);
    }
    return 0; // Caso inválido
}

// Função para verificar se há sobreposição de navios
int verificarSobreposicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int orientacao) {
    if (orientacao == 0) { // Horizontal
        for (int i = coluna; i < coluna + TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha][i] != 0) {
                return 0; // Sobreposição detectada
            }
        }
    } else if (orientacao == 1) { // Vertical
        for (int i = linha; i < linha + TAMANHO_NAVIO; i++) {
            if (tabuleiro[i][coluna] != 0) {
                return 0; // Sobreposição detectada
            }
        }
    } else if (orientacao == 2) { // Diagonal crescente (linha e coluna aumentam)
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna + i] != 0) {
                return 0; // Sobreposição detectada
            }
        }
    } else if (orientacao == 3) { // Diagonal decrescente (linha aumenta, coluna diminui)
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna - i] != 0) {
                return 0; // Sobreposição detectada
            }
        }
    }
    return 1; // Sem sobreposição
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int orientacao) {
    if (orientacao == 0) { // Horizontal
        for (int i = coluna; i < coluna + TAMANHO_NAVIO; i++) {
            tabuleiro[linha][i] = 3; // Navio representado por 3
        }
    } else if (orientacao == 1) { // Vertical
        for (int i = linha; i < linha + TAMANHO_NAVIO; i++) {
            tabuleiro[i][coluna] = 3; // Navio representado por 3
        }
    } else if (orientacao == 2) { // Diagonal crescente
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna + i] = 3; // Navio representado por 3
        }
    } else if (orientacao == 3) { // Diagonal decrescente
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna - i] = 3; // Navio representado por 3
        }
    }
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); // Exibe cada posição do tabuleiro
        }
        printf("\n"); // Nova linha após cada linha do tabuleiro
    }
}

int main() {
    // Declaração do tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Coordenadas dos navios (definidas diretamente no código)
    int linhaNavio1 = 2, colunaNavio1 = 3; // Navio horizontal
    int linhaNavio2 = 5, colunaNavio2 = 6; // Navio vertical
    int linhaNavio3 = 0, colunaNavio3 = 0; // Navio diagonal crescente
    int linhaNavio4 = 0, colunaNavio4 = 9; // Navio diagonal decrescente

    // Orientação dos navios (0 = horizontal, 1 = vertical, 2 = diagonal crescente, 3 = diagonal decrescente)
    int orientacaoNavio1 = 0;
    int orientacaoNavio2 = 1;
    int orientacaoNavio3 = 2;
    int orientacaoNavio4 = 3;

    // Verifica e posiciona o primeiro navio
    if (coordenadasValidas(linhaNavio1, colunaNavio1, orientacaoNavio1) &&
        verificarSobreposicao(tabuleiro, linhaNavio1, colunaNavio1, orientacaoNavio1)) {
        posicionarNavio(tabuleiro, linhaNavio1, colunaNavio1, orientacaoNavio1);
    } else {
        printf("Erro: Posição inválida ou sobreposição para o primeiro navio.\n");
        return 1;
    }

    // Verifica e posiciona o segundo navio
    if (coordenadasValidas(linhaNavio2, colunaNavio2, orientacaoNavio2) &&
        verificarSobreposicao(tabuleiro, linhaNavio2, colunaNavio2, orientacaoNavio2)) {
        posicionarNavio(tabuleiro, linhaNavio2, colunaNavio2, orientacaoNavio2);
    } else {
        printf("Erro: Posição inválida ou sobreposição para o segundo navio.\n");
        return 1;
    }

    // Verifica e posiciona o terceiro navio
    if (coordenadasValidas(linhaNavio3, colunaNavio3, orientacaoNavio3) &&
        verificarSobreposicao(tabuleiro, linhaNavio3, colunaNavio3, orientacaoNavio3)) {
        posicionarNavio(tabuleiro, linhaNavio3, colunaNavio3, orientacaoNavio3);
    } else {
        printf("Erro: Posição inválida ou sobreposição para o terceiro navio.\n");
        return 1;
    }

    // Verifica e posiciona o quarto navio
    if (coordenadasValidas(linhaNavio4, colunaNavio4, orientacaoNavio4) &&
        verificarSobreposicao(tabuleiro, linhaNavio4, colunaNavio4, orientacaoNavio4)) {
        posicionarNavio(tabuleiro, linhaNavio4, colunaNavio4, orientacaoNavio4);
    } else {
        printf("Erro: Posição inválida ou sobreposição para o quarto navio.\n");
        return 1;
    }

    // Exibe o tabuleiro final com os navios posicionados
    exibirTabuleiro(tabuleiro);

    return 0;
}