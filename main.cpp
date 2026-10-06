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
float enemy1_health = 2;
bool enemy1_alive = true;

float enemy2_speed = -0.1;
float enemy2_x = 900;
float enemy2_y = 200;
float enemy2_health = 2;
bool enemy2_alive = true;

float enemy3_speed = 0.15;
float enemy3_x = 200;
float enemy3_y = 300;
float enemy3_health = 2;
bool enemy3_alive = true;

float enemy4_speed = 0.12;
float enemy4_x = 700;
float enemy4_y = 400;
float enemy4_health = 2;
bool enemy4_alive = true;

float enemy5_speed = -0.08;
float enemy5_x = 500;
float enemy5_y = 500;
float enemy5_health = 2;
bool enemy5_alive = true;

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

void collison(Rectangle enemyrect1,Rectangle enemyrect2,Rectangle enemyrect3,Rectangle enemyrect4,Rectangle enemyrect5){
    if (CheckCollisionCircleRec(
        {particle_x,particle_y},
        5,
        enemyrect1)){
        particle_active = false;
        enemy1_health -= 1;
        std::cout<< enemy1_health << std::endl;
        
        if (enemy1_health<=0){
            enemy1_alive = false;
            }
        }
    if (CheckCollisionCircleRec(
        {particle_x,particle_y},
        5,
        enemyrect2)){
            particle_active = false;
            enemy2_health -= 1;
        if (enemy2_health<=0){
            enemy2_alive = false;
            }
        }
    if (CheckCollisionCircleRec(
        {particle_x,particle_y},
        5,
        enemyrect3)){
            particle_active = false;
            enemy3_health -= 1;
        if (enemy3_health<=0){
            enemy3_alive = false;
            }
        }
    if (CheckCollisionCircleRec(
        {particle_x,particle_y},
        5,
        enemyrect4)){
        particle_active = false;
        enemy4_health -= 1;

        if (enemy4_health<=0){
            enemy4_alive = false;
            }
        }
    if (CheckCollisionCircleRec(
        {particle_x,particle_y},
        5,
        enemyrect5)){
        particle_active = false;
        enemy5_health -= 1;
        
        if (enemy5_health<=0){
            enemy5_alive = false;
            }
        }
}

void enemy_movement(Texture2D enemy1,
    Texture2D enemy2,
    Texture2D enemy3,
    Texture2D enemy4,
    Texture2D enemy5,
    Rectangle enemyrect1
    ,Rectangle enemyrect2,
    Rectangle enemyrect3,
    Rectangle enemyrect4
    ,Rectangle enemyrect5){
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
        if(enemy1_alive)
        {
            DrawTextureEx(enemy1,{enemy1_x,enemy1_y},0.0f,0.08f,WHITE);
            enemy1_x += enemy1_speed;
            }
        if(enemy2_alive)
        {
            DrawTextureEx(enemy2,{enemy2_x,enemy2_y},0.0f,0.05f,WHITE);
            enemy2_x += enemy2_speed;
            }
        if(enemy3_alive)
        {
            DrawTextureEx(enemy3,{enemy3_x,enemy3_y},0.0f,0.08f,WHITE);
            enemy3_x += enemy3_speed;
            }
        if(enemy4_alive)
        {
            DrawTextureEx(enemy4,{enemy4_x,enemy4_y},0.0f,0.05f,WHITE);
            enemy4_x += enemy4_speed;
            }
        if(enemy5_alive)
        {
            DrawTextureEx(enemy5,{enemy5_x,enemy5_y},0.0f,0.08f,WHITE);
            enemy5_x += enemy5_speed;
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
        DrawTextureEx(star,{0,0},0.0f,1.5f,WHITE);
        DrawTextureEx(spaceship, {spaceship_x, spaceship_y},0.0f,0.2f, WHITE);
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
        Rectangle enemyrect3 = {
            enemy3_x,
            enemy3_y,
            enemy3.width * 0.08f,
            enemy3.height * 0.08f
        };
        Rectangle enemyrect4 = {
            enemy4_x,
            enemy4_y,
            enemy4.width * 0.05f,
            enemy4.height * 0.05f
        };
        Rectangle enemyrect5 = {
            enemy5_x,
            enemy5_y,
            enemy5.width * 0.08f,
            enemy5.height * 0.08f
        };
        if (enemy2_alive<=0){
            enemy2_alive = false;
        }
        if (enemy3_alive<=0){
            enemy3_alive = false;
        }
        if (enemy4_alive<=0){
            enemy4_alive = false;
        }
        enemy_movement(enemy1,
    enemy2,
    enemy3,
    enemy4,
    enemy5,
    enemyrect1,
    enemyrect2,
    enemyrect3,
    enemyrect4,
    enemyrect5);
        collison(enemyrect1,enemyrect2,enemyrect3,enemyrect4,enemyrect5);
        particle();
        EndDrawing();
    }
    return 0;
}