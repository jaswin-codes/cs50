// Helper functions to apply filters to images

#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Nested FOR loops both rows and columns of each pixel in image
    for (int i = 0, n = height; i < n; i++)
    {
        for (int j = 0, m = width; j < m; j++)
        {
            // Temp value for average of 3
            int average =
                round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0, n = height; i < n; i++)
    {
        // swap pixels in row so except middle
        for (int j = 0, m = (width / 2); j < m; j++)
        {
            // Create temporary pixel to hold while swapping
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blue image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Make a copy of pixels so it does not change
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0, n = height; i < n; i++)
    {
        for (int j = 0, m = width; j < m; j++)
        {
            int sumred = 0;
            int sumblue = 0;
            int sumgreen = 0;
            int count = 0;

            // Above row
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                sumred += copy[i - 1][j - 1].rgbtRed;
                sumblue += copy[i - 1][j - 1].rgbtBlue;
                sumgreen += copy[i - 1][j - 1].rgbtGreen;
                count++;
            }
            if (i - 1 >= 0)
            {
                sumred += copy[i - 1][j].rgbtRed;
                sumblue += copy[i - 1][j].rgbtBlue;
                sumgreen += copy[i - 1][j].rgbtGreen;
                count++;
            }
            if (i - 1 >= 0 && j + 1 < width)
            {
                sumred += copy[i - 1][j + 1].rgbtRed;
                sumblue += copy[i - 1][j + 1].rgbtBlue;
                sumgreen += copy[i - 1][j + 1].rgbtGreen;
                count++;
            }

            // Current row
            if (j - 1 >= 0)
            {
                sumred += copy[i][j - 1].rgbtRed;
                sumblue += copy[i][j - 1].rgbtBlue;
                sumgreen += copy[i][j - 1].rgbtGreen;
                count++;
            }
            // Current pixel
            sumred += copy[i][j].rgbtRed;
            sumblue += copy[i][j].rgbtBlue;
            sumgreen += copy[i][j].rgbtGreen;
            count++;

            if (j + 1 < width)
            {
                sumred += copy[i][j + 1].rgbtRed;
                sumblue += copy[i][j + 1].rgbtBlue;
                sumgreen += copy[i][j + 1].rgbtGreen;
                count++;
            }

            // Row below
            if (i + 1 < height && j - 1 >= 0)
            {
                sumred += copy[i + 1][j - 1].rgbtRed;
                sumblue += copy[i + 1][j - 1].rgbtBlue;
                sumgreen += copy[i + 1][j - 1].rgbtGreen;
                count++;
            }
            if (i + 1 < height)
            {
                sumred += copy[i + 1][j].rgbtRed;
                sumblue += copy[i + 1][j].rgbtBlue;
                sumgreen += copy[i + 1][j].rgbtGreen;
                count++;
            }
            if (i + 1 < height && j + 1 < width)
            {
                sumred += copy[i + 1][j + 1].rgbtRed;
                sumblue += copy[i + 1][j + 1].rgbtBlue;
                sumgreen += copy[i + 1][j + 1].rgbtGreen;
                count++;
            }

            // Calculate averages and set pixel to new colors
            image[i][j].rgbtRed = round((float) sumred / count);
            image[i][j].rgbtBlue = round((float) sumblue / count);
            image[i][j].rgbtGreen = round((float) sumgreen / count);
        }
    }
    return;
}

// Detect edges/boundary
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Create temp array so does not get mixed up
    RGBTRIPLE temp[height][width];

    for (int i = 0, n = height; i < n; i++)
    {
        for (int j = 0, m = width; j < m; j++)
        {
            int Gxred = 0;
            int Gxblue = 0;
            int Gxgreen = 0;
            int Gyred = 0;
            int Gyblue = 0;
            int Gygreen = 0;

            // Top row
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                Gxred += image[i - 1][j - 1].rgbtRed * Gx[0][0];
                Gxblue += image[i - 1][j - 1].rgbtBlue * Gx[0][0];
                Gxgreen += image[i - 1][j - 1].rgbtGreen * Gx[0][0];
                Gyred += image[i - 1][j - 1].rgbtRed * Gy[0][0];
                Gyblue += image[i - 1][j - 1].rgbtBlue * Gy[0][0];
                Gygreen += image[i - 1][j - 1].rgbtGreen * Gy[0][0];
            }
            if (i - 1 >= 0)
            {
                Gxred += image[i - 1][j].rgbtRed * Gx[0][1];
                Gxblue += image[i - 1][j].rgbtBlue * Gx[0][1];
                Gxgreen += image[i - 1][j].rgbtGreen * Gx[0][1];
                Gyred += image[i - 1][j].rgbtRed * Gy[0][1];
                Gyblue += image[i - 1][j].rgbtBlue * Gy[0][1];
                Gygreen += image[i - 1][j].rgbtGreen * Gy[0][1];
            }
            if (i - 1 >= 0 && j + 1 < width)
            {
                Gxred += image[i - 1][j + 1].rgbtRed * Gx[0][2];
                Gxblue += image[i - 1][j + 1].rgbtBlue * Gx[0][2];
                Gxgreen += image[i - 1][j + 1].rgbtGreen * Gx[0][2];
                Gyred += image[i - 1][j + 1].rgbtRed * Gy[0][2];
                Gyblue += image[i - 1][j + 1].rgbtBlue * Gy[0][2];
                Gygreen += image[i - 1][j + 1].rgbtGreen * Gy[0][2];
            }

            // Current row
            if (j - 1 >= 0)
            {
                Gxred += image[i][j - 1].rgbtRed * Gx[1][0];
                Gxblue += image[i][j - 1].rgbtBlue * Gx[1][0];
                Gxgreen += image[i][j - 1].rgbtGreen * Gx[1][0];
                Gyred += image[i][j - 1].rgbtRed * Gy[1][0];
                Gyblue += image[i][j - 1].rgbtBlue * Gy[1][0];
                Gygreen += image[i][j - 1].rgbtGreen * Gy[1][0];
            }
            Gxred += image[i][j].rgbtRed * Gx[1][1];
            Gxblue += image[i][j].rgbtBlue * Gx[1][1];
            Gxgreen += image[i][j].rgbtGreen * Gx[1][1];
            Gyred += image[i][j].rgbtRed * Gy[1][1];
            Gyblue += image[i][j].rgbtBlue * Gy[1][1];
            Gygreen += image[i][j].rgbtGreen * Gy[1][1];

            if (j + 1 < width)
            {
                Gxred += image[i][j + 1].rgbtRed * Gx[1][2];
                Gxblue += image[i][j + 1].rgbtBlue * Gx[1][2];
                Gxgreen += image[i][j + 1].rgbtGreen * Gx[1][2];
                Gyred += image[i][j + 1].rgbtRed * Gy[1][2];
                Gyblue += image[i][j + 1].rgbtBlue * Gy[1][2];
                Gygreen += image[i][j + 1].rgbtGreen * Gy[1][2];
            }

            // Bottom row
            if (i + 1 < height && j - 1 >= 0)
            {
                Gxred += image[i + 1][j - 1].rgbtRed * Gx[2][0];
                Gxblue += image[i + 1][j - 1].rgbtBlue * Gx[2][0];
                Gxgreen += image[i + 1][j - 1].rgbtGreen * Gx[2][0];
                Gyred += image[i + 1][j - 1].rgbtRed * Gy[2][0];
                Gyblue += image[i + 1][j - 1].rgbtBlue * Gy[2][0];
                Gygreen += image[i + 1][j - 1].rgbtGreen * Gy[2][0];
            }

            if (i + 1 < height)
            {
                Gxred += image[i + 1][j].rgbtRed * Gx[2][1];
                Gxblue += image[i + 1][j].rgbtBlue * Gx[2][1];
                Gxgreen += image[i + 1][j].rgbtGreen * Gx[2][1];
                Gyred += image[i + 1][j].rgbtRed * Gy[2][1];
                Gyblue += image[i + 1][j].rgbtBlue * Gy[2][1];
                Gygreen += image[i + 1][j].rgbtGreen * Gy[2][1];
            }

            if (i + 1 < height && j + 1 < width)
            {
                Gxred += image[i + 1][j + 1].rgbtRed * Gx[2][2];
                Gxblue += image[i + 1][j + 1].rgbtBlue * Gx[2][2];
                Gxgreen += image[i + 1][j + 1].rgbtGreen * Gx[2][2];
                Gyred += image[i + 1][j + 1].rgbtRed * Gy[2][2];
                Gyblue += image[i + 1][j + 1].rgbtBlue * Gy[2][2];
                Gygreen += image[i + 1][j + 1].rgbtGreen * Gy[2][2];
            }

            //  Use Sobel formula
            int newred = round(sqrt(Gxred * Gxred + Gyred * Gyred));
            int newgreen = round(sqrt(Gxgreen * Gxgreen + Gygreen * Gygreen));
            int newblue = round(sqrt(Gxblue * Gxblue + Gyblue * Gyblue));

            // make 255 max/cap
            if (newred > 255)
                newred = 255;
            if (newgreen > 255)
                newgreen = 255;
            if (newblue > 255)
                newblue = 255;

            // Store in temp array
            temp[i][j].rgbtRed = newred;
            temp[i][j].rgbtGreen = newgreen;
            temp[i][j].rgbtBlue = newblue;
        }
    }
    // Copy temp image from array back to original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}
