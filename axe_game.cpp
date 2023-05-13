#include "raylib.h"

int main(){

    // Window Properties
    int width = 800;
    int height = 450;

    InitWindow(width,height,"BigBruh");

    //Circle coordinates

    int circle_x{200};
    int circle_y{200};

    int circle_r{50};

    int l_circle_x{circle_x - circle_r};
    int r_circle_x{circle_x + circle_r};
    int u_circle_y{circle_y - circle_r};
    int b_circle_y{circle_y + circle_r};

    //Axe coordinates
    int axe_x{400};
    int axe_y{0};

    int direction{10};
    int axe_h{50};
    int axe_w{50};

    int l_axe_x{axe_x};
    int r_axe_x{axe_x+axe_h};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y+axe_h};

    bool collisionWithAxe = 
                        (b_axe_y >= u_circle_y) && 
                        (u_axe_y <= b_circle_y) && 
                        (r_axe_x >= l_circle_x) && 
                        (l_axe_x <= r_circle_x);

    SetTargetFPS(60);
    while(!WindowShouldClose()){

        BeginDrawing();
        ClearBackground(WHITE);

        if(collisionWithAxe){
            DrawText("Game Over!", 400, 200, 20, RED);
        }else{

            //Game logic begins

            //Update edges
            l_circle_x = circle_x - circle_r;
            r_circle_x = circle_x + circle_r;
            u_circle_y = circle_y - circle_r;
            b_circle_y = circle_y + circle_r;

            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_h;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_h;

            //Update collision with axe
            collisionWithAxe = 
                        (b_axe_y >= u_circle_y) && 
                        (u_axe_y <= b_circle_y) && 
                        (r_axe_x >= l_circle_x) && 
                        (l_axe_x <= r_circle_x);

            DrawCircle(circle_x,circle_y,circle_r,GREEN);
            DrawRectangle(axe_x, axe_y, axe_w , axe_h, RED);

            axe_y+=direction;

            if(axe_y+axe_h > 450 || axe_y < 0){
                direction = -direction;
            }

            if(IsKeyDown(KEY_D) && circle_x+circle_r < width){
                circle_x+=5;
            }else if(IsKeyDown(KEY_A) && circle_x-circle_r > 0){
                circle_x-=5;
            }else if(IsKeyDown(KEY_W)&& circle_y-circle_r > 0){
                circle_y-=5;
            }else if(IsKeyDown(KEY_S) && circle_y+circle_r < height){
                circle_y+=5;
            }

            //Game logic ends
        }
        EndDrawing();

    }

}