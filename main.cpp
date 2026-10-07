#include <iostream>
#include <raylib.h>

float spaceship_x = 450;
float spaceship_y = 700;

float particle_x;
float particle_y;
float particle_speed = 0.2;
bool particle_active = false;

struct Enemy
{
    float x;
    float y;
    float speed;
    float health;
    bool alive;
    Texture2D texture;
    float scale;
    Rectangle rect;
};

Enemy enemy1, enemy2, enemy3, enemy4, enemy5;

void spaceship_movement()
{
    if (IsKeyDown(KEY_W))
        spaceship_y -= 1;

    if (IsKeyDown(KEY_A))
        spaceship_x -= 1;

    if (IsKeyDown(KEY_S))
        spaceship_y += 1;

    if (IsKeyDown(KEY_D))
        spaceship_x += 1;

    if (spaceship_x < 0)
        spaceship_x = 0;

    if (spaceship_x > 700 - 121)
        spaceship_x = 700 - 121;

    if (spaceship_y < 0)
        spaceship_y = 0;

    if (spaceship_y > 1150 - 120.4)
        spaceship_y = 1150 - 120.4;
}


void collision(Enemy& enemy)
{
    if (!enemy.alive || !particle_active)
        return;

    if (CheckCollisionCircleRec(
        {particle_x, particle_y},
        5,
        enemy.rect))
    {
        particle_active = false;

        enemy.health -= 1;

        std::cout << enemy.health << std::endl;

        if (enemy.health <= 0)
        {
            enemy.alive = false;
        }
    }
}


void enemy_movement(Enemy& enemy)
{
    if (!enemy.alive)
        return;

    if (enemy.speed > 0 && enemy.x > GetScreenWidth())
    {
        enemy.x = 50;
    }

    if (enemy.speed < 0 && enemy.x < 0)
    {
        enemy.x = 950;
    }

    enemy.x += enemy.speed;

    enemy.rect = {
        enemy.x,
        enemy.y,
        enemy.texture.width * enemy.scale,
        enemy.texture.height * enemy.scale
    };

    DrawTextureEx(
        enemy.texture,
        {enemy.x, enemy.y},
        0.0f,
        enemy.scale,
        WHITE
    );
}


void particle()
{
    if (IsKeyPressed(KEY_X))
    {
        particle_y = spaceship_y;
        particle_x = spaceship_x + 57;
        particle_active = true;
    }

    if (particle_active)
    {
        DrawCircle(particle_x, particle_y, 5, WHITE);
        particle_y -= particle_speed;
    }

    if (particle_y < 0)
        particle_active = false;
}


int main(void)
{
    InitWindow(700, 1150, "Space Shooter");

    Texture2D spaceship = LoadTexture("BAOyZX.png");

    Texture2D enemyTexture1 =
        LoadTexture("32295-6-space-invaders-transparent-background.png");

    Texture2D enemyTexture2 =
        LoadTexture("32282-4-space-invaders-free-download.png");

    Texture2D star = LoadTexture("gala.jpg");


    // Enemy 1
    enemy1.x = 0;
    enemy1.y = 100;
    enemy1.speed = 0.1;
    enemy1.health = 2;
    enemy1.alive = true;
    enemy1.texture = enemyTexture1;
    enemy1.scale = 0.08;


    // Enemy 2
    enemy2.x = 900;
    enemy2.y = 200;
    enemy2.speed = -0.1;
    enemy2.health = 2;
    enemy2.alive = true;
    enemy2.texture = enemyTexture2;
    enemy2.scale = 0.05;


    // Enemy 3
    enemy3.x = 200;
    enemy3.y = 300;
    enemy3.speed = 0.15;
    enemy3.health = 2;
    enemy3.alive = true;
    enemy3.texture = enemyTexture1;
    enemy3.scale = 0.08;


    // Enemy 4
    enemy4.x = 700;
    enemy4.y = 400;
    enemy4.speed = 0.12;
    enemy4.health = 2;
    enemy4.alive = true;
    enemy4.texture = enemyTexture2;
    enemy4.scale = 0.05;


    // Enemy 5
    enemy5.x = 500;
    enemy5.y = 500;
    enemy5.speed = -0.08;
    enemy5.health = 2;
    enemy5.alive = true;
    enemy5.texture = enemyTexture1;
    enemy5.scale = 0.08;


    while (!WindowShouldClose())
    {
        spaceship_movement();

        BeginDrawing();

        ClearBackground(BLACK);

        DrawTextureEx(
            star,
            {0, 0},
            0.0f,
            1.5f,
            WHITE
        );

        DrawTextureEx(
            spaceship,
            {spaceship_x, spaceship_y},
            0.0f,
            0.2f,
            WHITE
        );


        enemy_movement(enemy1);
        enemy_movement(enemy2);
        enemy_movement(enemy3);
        enemy_movement(enemy4);
        enemy_movement(enemy5);


        collision(enemy1);
        collision(enemy2);
        collision(enemy3);
        collision(enemy4);
        collision(enemy5);


        particle();

        EndDrawing();
    }

    return 0;
}