import math
import os
import time

# Constants
M_PI = 3.14159265358979323846
WIDTH = 120
HEIGHT = 30
THETA_SPACING = 0.07
PHI_SPACING = 0.02
R1 = 0.5
R2 = 1.5
K2 = 5
K1 = WIDTH * K2 * 2 / (8 * (R1 + R2))

# Light source gradient
LIGHT = ".,-~:;=!*#$@"

def render_frame(A, B):
    # Frame buffer and z-buffer
    frame = [[' ' for _ in range(WIDTH)] for _ in range(HEIGHT)]
    z_buffer = [[0 for _ in range(WIDTH)] for _ in range(HEIGHT)]

    # Precompute sin and cos of A and B
    cosA, sinA = math.cos(A), math.sin(A)
    cosB, sinB = math.cos(B), math.sin(B)

    # Loop through angles theta and phi
    theta = 0
    while theta < 2 * M_PI:
        costheta, sintheta = math.cos(theta), math.sin(theta)
        phi = 0
        while phi < 2 * M_PI:
            cosphi, sinphi = math.cos(phi), math.sin(phi)

            # 3D coordinates of the donut
            x = R2 + R1 * costheta
            y = R1 * sintheta
            z = 0

            # Rotate around x and y axes
            x_rot = x * (cosB * cosphi + sinA * sinB * sinphi) - y * cosA * sinB
            y_rot = x * (sinB * cosphi - sinA * cosB * sinphi) + y * cosA * cosB
            z_rot = K2 + cosA * x * sinphi + y * sinA

            # Perspective projection
            z_inv = 1 / z_rot
            x_proj = int(WIDTH / 2 + K1 * x_rot * z_inv)
            y_proj = int(HEIGHT / 2 - K1 * y_rot * z_inv * 0.5)  # Adjust for aspect ratio

            # Clamp the projected coordinates to screen bounds
            x_proj = max(0, min(WIDTH - 1, x_proj))
            y_proj = max(0, min(HEIGHT - 1, y_proj))

            # Calculate brightness (surface normal)
            L = cosphi * costheta * sinB - cosA * costheta * sinphi - sinA * sintheta + cosB * (cosA * sintheta - costheta * sinA * sinphi)

            if L > 0:
                if z_inv > z_buffer[y_proj][x_proj]:
                    z_buffer[y_proj][x_proj] = z_inv
                    brightness_index = int(L * 8)
                    frame[y_proj][x_proj] = LIGHT[brightness_index]

            phi += PHI_SPACING
        theta += THETA_SPACING

    # Print the frame
    os.system('cls' if os.name == 'nt' else 'clear')  # Clear the terminal
    for y in range(HEIGHT):
        print(''.join(frame[y]))

def main():
    A, B = 0, 0  # Rotation angles
    while True:
        render_frame(A, B)
        time.sleep(0.03)  # Sleep for 30ms
        A += 0.07  # Increment rotation angles
        B += 0.03

if __name__ == "__main__":
    main()