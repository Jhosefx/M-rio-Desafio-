#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Definições de constantes
#define MAP_WIDTH 20
#define MAP_HEIGHT 5
#define PLAYER_CHAR 'P'
#define COIN_CHAR '$'
#define OBSTACLE_CHAR '#'

// Estrutura para representar o jogador
struct Player {
    int x, y;
    int coins;
};

// Função para inicializar o jogador
void initPlayer(struct Player *player) {
    player->x = 0;
    player->y = MAP_HEIGHT - 1;
    player->coins = 0;
}

// Função para desenhar o mapa
void drawMap(struct Player player) {
    // Mapa estático
    char map[MAP_HEIGHT][MAP_WIDTH] = {
        "###################",
        "#                 #",
        "#                 #",
        "#                 #",
        "###################"
    };

    // Colocar o jogador e as moedas no mapa
    map[player.y][player.x] = PLAYER_CHAR;

    // Desenhar o mapa
    system("cls"); // Limpar a tela
    for (int i = 0; i < MAP_HEIGHT; i++) {
        printf("%s\n", map[i]);
    }
}

// Função principal
int main() {
    struct Player player;
    char input;

    initPlayer(&player);

    while (1) {
        drawMap(player);

        // Verificar se o jogador chegou ao fim do mapa
        if (player.x == MAP_WIDTH - 1) {
            printf("\nParabéns! Você venceu!\n");
            printf("Total de moedas coletadas: %d\n", player.coins);
            break;
        }

        // Ler entrada do jogador
        printf("\nW - cima, A - esquerda, S - baixo, D - direita: ");
        input = getch();

        // Mover o jogador
        switch (input) {
            case 'w':
            case 'W':
                if (player.y > 0)
                    player.y--;
                break;
            case 's':
            case 'S':
                if (player.y < MAP_HEIGHT - 1)
                    player.y++;
                break;
            case 'a':
            case 'A':
                if (player.x > 0)
                    player.x--;
                break;
            case 'd':
            case 'D':
                if (player.x < MAP_WIDTH - 1)
                    player.x++;
                break;
        }
    }

    return 0;
}
