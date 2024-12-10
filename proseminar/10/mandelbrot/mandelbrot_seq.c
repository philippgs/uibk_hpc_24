#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// Include that allows to print result as an image
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#define DEFAULT_SIZE_X 1280
#define DEFAULT_SIZE_Y 720

// RGB image will hold 3 color channels
#define NUM_CHANNELS 3
// max iterations cutoff
#define MAX_ITER 10000

#define IND(Y, X, SIZE_Y, SIZE_X, CHANNEL) ((Y) * (SIZE_X) * (NUM_CHANNELS) + (X) * (NUM_CHANNELS) + (CHANNEL))

void HSVToRGB(double H, double S, double V, double* R, double* G, double* B);

void calcMandelbrot(uint8_t* image, int sizeX, int sizeY) {
	struct timeval start, end;
	gettimeofday(&start, NULL);
	const float left = -2.5, right = 1;
	const float bottom = -1, top = 1;

	for(int pixelY = 0; pixelY < sizeY; pixelY++) {
		// scale y pixel into mandelbrot coordinate system
		const float cy = (pixelY / (float)sizeY) * (top - bottom) + bottom;
		for(int pixelX = 0; pixelX < sizeX; pixelX++) {
			// scale x pixel into mandelbrot coordinate system
			const float cx = (pixelX / (float)sizeX) * (right - left) + left;
			float x = 0;
			float y = 0;
			int numIterations = 0;

			// Check if the distance from the origin becomes 
			// greater than 2 within the max number of iterations.
			while((x * x + y * y <= 2 * 2) && (numIterations < MAX_ITER)) {
				float x_tmp = x * x - y * y + cx;
				y = 2 * x * y + cy;
				x = x_tmp;
				numIterations += 1;
			}
			
			// Normalize iteration and write it to pixel position			
			double value = fabs((numIterations / (float)MAX_ITER)) * 200;

			double red = 0;
			double green = 0;
			double blue = 0;

			HSVToRGB(value, 1.0, 1.0, &red, &green, &blue);

			int channel = 0;
			image[IND(pixelY, pixelX, sizeY, sizeX, channel++)] = (uint8_t)(red * UINT8_MAX);
			image[IND(pixelY, pixelX, sizeY, sizeX, channel++)] = (uint8_t)(green * UINT8_MAX);
			image[IND(pixelY, pixelX, sizeY, sizeX, channel++)] = (uint8_t)(blue * UINT8_MAX);
		}
	}
	gettimeofday(&end, NULL);
	double timeElapsed = (end.tv_sec + end.tv_usec * 1e-6) - (start.tv_sec + start.tv_usec * 1e-6);
	printf("Mandelbrot set calculation for %dx%d took: %f seconds.\n", sizeX, sizeY, timeElapsed);
}

int main(int argc, char** argv) {

	int sizeX = DEFAULT_SIZE_X;
	int sizeY = DEFAULT_SIZE_Y;

	if(argc == 3) {
		sizeX = atoi(argv[1]);
		sizeY = atoi(argv[2]);
	} else {
		printf("No arguments given, using default size\n");
	}

	uint8_t* image = malloc(NUM_CHANNELS * sizeX * sizeY * sizeof(uint8_t));

	calcMandelbrot(image, sizeX, sizeY);

	const int stride_bytes = 0;
	stbi_write_png("mandelbrot_seq.png", sizeX, sizeY, NUM_CHANNELS, image, stride_bytes);

	free(image);

	return EXIT_SUCCESS;
}

void HSVToRGB(double H, double S, double V, double* R, double* G, double* B) {
	if (H >= 1.00) {
		V = 0.0;
		H = 0.0;
	}

	double step = 1.0/6.0;
	double vh = H/step;

	int i = (int)floor(vh);

	double f = vh - i;
	double p = V*(1.0 - S);
	double q = V*(1.0 - (S*f));
	double t = V*(1.0 - (S*(1.0 - f)));

	switch (i) {
		case 0:
			{
				*R = V;
				*G = t;
				*B = p;
				break;
			}
		case 1:
			{
				*R = q;
				*G = V;
				*B = p;
				break;
			}
		case 2:
			{
				*R = p;
				*G = V;
				*B = t;
				break;
			}
		case 3:
			{
				*R = p;
				*G = q;
				*B = V;
				break;
			}
		case 4:
			{
				*R = t;
				*G = p;
				*B = V;
				break;
			}
		case 5:
			{
				*R = V;
				*G = p;
				*B = q;
				break;
			}
	}
}
