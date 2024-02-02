#include "raylib.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Bouncing Ball");

    // Ball variables
    float ballRadius = 20.0f;
    Vector2 ballPosition = {(float)screenWidth / 2, (float)screenHeight / 2};
    Vector2 ballSpeed = {5.0f, 4.0f};

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Update
        ballPosition.x += ballSpeed.x;
        ballPosition.y += ballSpeed.y;

        // Bounce off walls
        if ((ballPosition.x + ballRadius > screenWidth) || (ballPosition.x - ballRadius < 0))
            ballSpeed.x *= -1;

        if ((ballPosition.y + ballRadius > screenHeight) || (ballPosition.y - ballRadius < 0))
            ballSpeed.y *= -1;

        // Draw
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawCircleV(ballPosition, ballRadius, MAROON);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

