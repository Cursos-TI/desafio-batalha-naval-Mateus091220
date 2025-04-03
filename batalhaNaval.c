#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5 // Tamanho das matrizes de habilidade

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // Água representada por 0
        }
    }
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int orientacao) {
    if (orientacao == 0) { // Horizontal
        for (int i = coluna; i < coluna + 3; i++) {
            tabuleiro[linha][i] = 3; // Navio representado por 3
        }
    } else if (orientacao == 1) { // Vertical
        for (int i = linha; i < linha + 3; i++) {
            tabuleiro[i][coluna] = 3; // Navio representado por 3
        }
    }
}

// Função para criar uma matriz de efeito de cone
void criarMatrizCone(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i >= j && i + j <= TAMANHO_HABILIDADE - 1) {
                matriz[i][j] = 1; // Área afetada
            } else {
                matriz[i][j] = 0; // Área não afetada
            }
        }
    }
}

// Função para criar uma matriz de efeito de cruz
void criarMatrizCruz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == TAMANHO_HABILIDADE / 2 || j == TAMANHO_HABILIDADE / 2) {
                matriz[i][j] = 1; // Área afetada
            } else {
                matriz[i][j] = 0; // Área não afetada
            }
        }
    }
}

// Função para criar uma matriz de efeito de octaedro
void criarMatrizOctaedro(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i + j == TAMANHO_HABILIDADE / 2 || i - j == TAMANHO_HABILIDADE / 2 ||
                j - i == TAMANHO_HABILIDADE / 2 || i + j == TAMANHO_HABILIDADE - 1 + TAMANHO_HABILIDADE / 2) {
                matriz[i][j] = 1; // Área afetada
            } else {
                matriz[i][j] = 0; // Área não afetada
            }
        }
    }
}

// Função para sobrepor uma matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int linhaOrigem, int colunaOrigem) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linhaTabuleiro = linhaOrigem + i - TAMANHO_HABILIDADE / 2;
            int colunaTabuleiro = colunaOrigem + j - TAMANHO_HABILIDADE / 2;

            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO &&
                colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO &&
                habilidade[i][j] == 1) {
                if (tabuleiro[linhaTabuleiro][colunaTabuleiro] != 3) { // Não sobrescreve navios
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5; // Área afetada pela habilidade
                }
            }
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

    // Posiciona dois navios no tabuleiro (horizontal e vertical)
    posicionarNavio(tabuleiro, 2, 3, 0); // Navio horizontal
    posicionarNavio(tabuleiro, 5, 6, 1); // Navio vertical

    // Declaração das matrizes de habilidade
    int matrizCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int matrizCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int matrizOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    // Cria as matrizes de habilidade
    criarMatrizCone(matrizCone);
    criarMatrizCruz(matrizCruz);
    criarMatrizOctaedro(matrizOctaedro);

    // Aplica as habilidades no tabuleiro
    int linhaOrigemCone = 4, colunaOrigemCone = 4;
    int linhaOrigemCruz = 7, colunaOrigemCruz = 7;
    int linhaOrigemOctaedro = 9, colunaOrigemOctaedro = 2;

    aplicarHabilidade(tabuleiro, matrizCone, linhaOrigemCone, colunaOrigemCone);
    aplicarHabilidade(tabuleiro, matrizCruz, linhaOrigemCruz, colunaOrigemCruz);
    aplicarHabilidade(tabuleiro, matrizOctaedro, linhaOrigemOctaedro, colunaOrigemOctaedro);

    // Exibe o tabuleiro final com os navios e as áreas de efeito das habilidades
    exibirTabuleiro(tabuleiro);

    return 0;
}