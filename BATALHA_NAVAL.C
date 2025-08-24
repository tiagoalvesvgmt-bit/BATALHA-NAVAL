#include <stdio.h>
#include <stdlib.h>

// Definicao do tamanho do tabuleiro.
// Usaremos uma matriz 5x5 para que a saida corresponda exatamente aos exemplos.
#define TAMANHO 5

// --- Protótipos das Funções ---
void inicializar_matriz(int matriz[TAMANHO][TAMANHO]);
void exibir_matriz(const char* nome_habilidade, int matriz[TAMANHO][TAMANHO]);
void criar_cone(int matriz[TAMANHO][TAMANHO], int centro_linha, int centro_coluna);
void criar_cruz(int matriz[TAMANHO][TAMANHO], int centro_linha, int centro_coluna);
void criar_octaedro(int matriz[TAMANHO][TAMANHO], int centro_linha, int centro_coluna);

// --- Função Principal (main) ---
int main() {
    // Declaracao das matrizes para cada habilidade
    int matriz_cone[TAMANHO][TAMANHO];
    int matriz_cruz[TAMANHO][TAMANHO];
    int matriz_octaedro[TAMANHO][TAMANHO];

    // Definicao das coordenadas de origem das habilidades
    // Para corresponder aos exemplos, o cone e o octaedro tem origem no topo-centro.
    // A cruz tem origem no centro.
    int centro_coluna = TAMANHO / 2;
    int centro_linha = TAMANHO / 2;
    int topo_linha = 0;
    
    // --- Etapa 1: Habilidade em Cone ---
    inicializar_matriz(matriz_cone);
    criar_cone(matriz_cone, topo_linha, centro_coluna);
    exibir_matriz("Habilidade em Cone", matriz_cone);

    // --- Etapa 2: Habilidade em Cruz ---
    inicializar_matriz(matriz_cruz);
    criar_cruz(matriz_cruz, centro_linha, centro_coluna);
    exibir_matriz("Habilidade em Cruz", matriz_cruz);

    // --- Etapa 3: Habilidade em Octaedro ---
    inicializar_matriz(matriz_octaedro);
    criar_octaedro(matriz_octaedro, topo_linha, centro_coluna);
    exibir_matriz("Habilidade em Octaedro", matriz_octaedro);

    return 0;
}

// --- Funções de Implementação ---

/**
 * @brief Inicializa todos os elementos de uma matriz com zero.
 * @param matriz A matriz 2D a ser inicializada.
 */
void inicializar_matriz(int matriz[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            matriz[i][j] = 0;
        }
    }
}

/**
 * @brief Exibe o conteúdo de uma matriz no console.
 * @param nome_habilidade A string que descreve a habilidade.
 * @param matriz A matriz 2D a ser exibida.
 */
void exibir_matriz(const char* nome_habilidade, int matriz[TAMANHO][TAMANHO]) {
    printf("--- %s ---\n", nome_habilidade);
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * @brief Preenche uma matriz com o padrão de um cone.
 * O cone se expande para fora a partir de um ponto central no topo.
 * @param matriz A matriz a ser preenchida.
 * @param centro_linha A linha de origem do cone.
 * @param centro_coluna A coluna de origem do cone.
 */
void criar_cone(int matriz[TAMANHO][TAMANHO], int centro_linha, int centro_coluna) {
    for (int i = 0; i < TAMANHO; i++) {
        // A largura do cone aumenta em 2 a cada linha
        int largura = i * 2;
        int inicio_coluna = centro_coluna - i;
        
        for (int j = inicio_coluna; j <= inicio_coluna + largura; j++) {
            // Verifica se a célula está dentro dos limites da matriz
            if (i >= centro_linha && j >= 0 && j < TAMANHO) {
                matriz[i][j] = 1;
            }
        }
    }
}

/**
 * @brief Preenche uma matriz com o padrão de uma cruz.
 * A cruz é formada por uma linha horizontal e uma vertical.
 * @param matriz A matriz a ser preenchida.
 * @param centro_linha A linha central da cruz.
 * @param centro_coluna A coluna central da cruz.
 */
void criar_cruz(int matriz[TAMANHO][TAMANHO], int centro_linha, int centro_coluna) {
    // Desenha a linha vertical
    for (int i = 0; i < TAMANHO; i++) {
        matriz[i][centro_coluna] = 1;
    }

    // Desenha a linha horizontal
    for (int j = 0; j < TAMANHO; j++) {
        matriz[centro_linha][j] = 1;
    }
}

/**
 * @brief Preenche uma matriz com o padrão de um octaedro (forma de diamante).
 * O padrão é baseado na distância de Manhattan (distância em linha reta).
 * @param matriz A matriz a ser preenchida.
 * @param centro_linha A linha central do octaedro.
 * @param centro_coluna A coluna central do octaedro.
 */
void criar_octaedro(int matriz[TAMANHO][TAMANHO], int centro_linha, int centro_coluna) {
    int raio = TAMANHO / 2;
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            // A condicao abs(dx) + abs(dy) <= raio cria o formato de diamante
            int distancia = abs(i - centro_linha) + abs(j - centro_coluna);
            if (distancia <= raio) {
                matriz[i][j] = 1;
            }
        }
    }
}