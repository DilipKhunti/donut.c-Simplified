#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define M_PI 3.14159265358979323846
#define WIDTH 120
#define HEIGHT 30
#define THETA_SPACING 0.07
#define PHI_SPACING 0.02
#define R1 0.5
#define R2 1.5
#define K2 5
#define K1 (WIDTH * K2 * 2 / (8 * (R1 + R2)))

// Light source gradient
const char *LIGHT = ".,-~:;=!*#$@";

void render_frame(float A, float B)
{
    // Frame buffer and z-buffer
    char frame[HEIGHT][WIDTH];
    float z_buffer[HEIGHT][WIDTH];
    memset(frame, ' ', sizeof(frame));
    memset(z_buffer, 0, sizeof(z_buffer));

    // Precompute sin and cos of A and B
    float cosA = cos(A), sinA = sin(A);
    float cosB = cos(B), sinB = sin(B);

    // Loop through angles theta and phi
    for (float theta = 0; theta < 2 * M_PI; theta += THETA_SPACING)
    {
        float costheta = cos(theta), sintheta = sin(theta);

        for (float phi = 0; phi < 2 * M_PI; phi += PHI_SPACING)
        {
            float cosphi = cos(phi), sinphi = sin(phi);

            // 3D coordinates of the donut
            float x = R2 + R1 * costheta;
            float y = R1 * sintheta;
            float z = 0;

            // Rotate around x and y axes
            float x_rot = x * (cosB * cosphi + sinA * sinB * sinphi) - y * cosA * sinB;
            float y_rot = x * (sinB * cosphi - sinA * cosB * sinphi) + y * cosA * cosB;
            float z_rot = K2 + cosA * x * sinphi + y * sinA;

            // Perspective projection
            float z_inv = 1 / z_rot;
            int x_proj = (int)(WIDTH / 2 + K1 * x_rot * z_inv);
            int y_proj = (int)(HEIGHT / 2 - K1 * y_rot * z_inv * 0.5); // Adjust for aspect ratio

            // Clamp the projected coordinates to screen bounds
            x_proj = x_proj < 0 ? 0 : x_proj;
            x_proj = x_proj >= WIDTH ? WIDTH - 1 : x_proj;
            y_proj = y_proj < 0 ? 0 : y_proj;
            y_proj = y_proj >= HEIGHT ? HEIGHT - 1 : y_proj;

            // Calculate brightness (surface normal)
            float L = cosphi * costheta * sinB - cosA * costheta * sinphi - sinA * sintheta + cosB * (cosA * sintheta - costheta * sinA * sinphi);

            if (L > 0)
            {
                if (z_inv > z_buffer[y_proj][x_proj])
                {
                    z_buffer[y_proj][x_proj] = z_inv;
                    int brightness_index = (int)(L * 8);
                    frame[y_proj][x_proj] = LIGHT[brightness_index];
                }
            }
        }
    }

    // Print the frame
    printf("\x1b[H"); // Move cursor to home position
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            putchar(frame[y][x]);
        }
        putchar('\n');
    }
}

int main()
{
    float A = 0, B = 0; // Rotation angles
    while (1)
    {
        render_frame(A, B);
        A += 0.07; // Increment rotation angles
        B += 0.03;
    }
    return 0;
}