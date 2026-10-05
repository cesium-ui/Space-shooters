#include<iostream>
#include<raylib.h>

float spaceship_x = 450;
float spaceship_y = 700;

float particle_x;
float particle_y;
float particle_speed = 0.2;
bool particle_active = false;

float enemy1_x = 0;
float enemy1_y = 100;
float enemy1_speed = 0.1;

float enemy2_speed = -0.1;
float enemy2_x = 900;
float enemy2_y = 200;

float enemy3_speed = 0.15;
float enemy3_x = 200;
float enemy3_y = 300;

float enemy4_speed = 0.12;
float enemy4_x = 700;
float enemy4_y = 400;

float enemy5_speed = -0.08;
float enemy5_x = 500;
float enemy5_y = 500;

void spaceship_movement(){

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
        if (spaceship_x>700-121)
            spaceship_x = 700-121;
        
        if (spaceship_y < 0)
            spaceship_y = 0;
        if (spaceship_y>1150-120.4)
            spaceship_y = 1150-120.4;

}

void enemy_movement(){
        enemy1_x += enemy1_speed;
        enemy2_x += enemy2_speed;
        enemy3_x += enemy3_speed;
        enemy4_x += enemy4_speed;
        enemy5_x += enemy5_speed;
        if (enemy1_x > GetScreenWidth())
{
            enemy1_x = 50;
}
        if (enemy2_x < 0)
{
            enemy2_x = 950;
}
        if (enemy3_x > GetScreenWidth())
{
            enemy3_x = 50;
}

        if (enemy4_x > GetScreenWidth())
{
            enemy4_x = 50;
}

        if (enemy5_x < 0)
{
            enemy5_x = 950;
}
}

void particle(){

    if (IsKeyPressed(KEY_X)){
        particle_y = spaceship_y;
        particle_x = spaceship_x+57;
        particle_active = true;}

    if (particle_active) {
        DrawCircle(particle_x, particle_y, 5, WHITE);
        particle_y -= particle_speed;
    }

    if (particle_y < 0)
    particle_active = false;
}

void collison(Rectangle enemyrect1,Rectangle enemyrect2){
    if (CheckCollisionCircleRec(
        {particle_x,particle_y},
        5,
        enemyrect1)){
            particle_active = false;
        }
    if (CheckCollisionCircleRec(
        {particle_x,particle_y},
        5,
        enemyrect2)){
            particle_active = false;
        }
}

int main(void)
{
    InitWindow(700, 1150, "Space Shooter");


    Texture2D spaceship = LoadTexture("BAOyZX.png");
    Texture2D enemy1 = LoadTexture("32295-6-space-invaders-transparent-background.png");
    Texture2D enemy2 = LoadTexture("32282-4-space-invaders-free-download.png");
    Texture2D enemy3 = LoadTexture("32295-6-space-invaders-transparent-background.png");
    Texture2D enemy4 = LoadTexture("32282-4-space-invaders-free-download.png");
    Texture2D enemy5 = LoadTexture("32295-6-space-invaders-transparent-background.png");
    Texture2D star = LoadTexture("gala.jpg");

    while (!WindowShouldClose())
    {
        spaceship_movement();
        BeginDrawing();
        ClearBackground(BLACK);
        enemy_movement();
        DrawTextureEx(star,{0,0},0.0f,1.5f,WHITE);
        DrawTextureEx(spaceship, {spaceship_x, spaceship_y},0.0f,0.2f, WHITE);
        DrawTextureEx(enemy1,{enemy1_x,enemy1_y},0.0f,0.08f,WHITE);
        DrawTextureEx(enemy2,{enemy2_x,enemy2_y},0.0f,0.05f,WHITE);
        DrawTextureEx(enemy3,{enemy3_x,enemy3_y},0.0f,0.08f,WHITE);
        DrawTextureEx(enemy4,{enemy4_x,enemy4_y},0.0f,0.05f,WHITE);
        DrawTextureEx(enemy5,{enemy5_x,enemy5_y},0.0f,0.08f,WHITE);
        Rectangle enemyrect1 = {
            enemy1_x,
            enemy1_y,
            enemy1.width * 0.08f,
            enemy1.height * 0.08f
        };
        Rectangle enemyrect2 = {
            enemy2_x,
            enemy2_y,
            enemy2.width * 0.05f,
            enemy2.height * 0.05f
        };
        particle();
        collison(enemyrect1,enemyrect2);
        EndDrawing();
    }
    return 0;
}