#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

const float g = 9.8f;
float TimeAtMaxHeight;
int MaxJumpHeight;

int InputChek()
{
	if (0 == scanf("%d", &MaxJumpHeight))
	{
		printf("\n" "incorrect input" "\n");
		exit(1);
	}
}

void CalculateTimeAtMaxHeight(int MaxJumpHeight)
{
	TimeAtMaxHeight = sqrt(MaxJumpHeight * 2 / g);
	printf("TimeAtMaxHeight=%f\n", TimeAtMaxHeight);
}

void CalculateTraveledDistance(float CurrentTime, float g, float TimeAtMaxHeight)
{
	float InitialVelocity = g * TimeAtMaxHeight;
	float TraveledDistance = InitialVelocity * CurrentTime - 0.5 * g * CurrentTime * CurrentTime;
	printf("CurrentTime=%f, TraveledDistance=%f\n", CurrentTime, TraveledDistance);
}

void PrintResult()
{
	bool flag = false;
	float CurrentTime = 0;
	while (CurrentTime < TimeAtMaxHeight * 2)
	{
		CurrentTime += 0.1f;
		if (CurrentTime > TimeAtMaxHeight && !flag)
		{
			flag = true;
			CalculateTraveledDistance(TimeAtMaxHeight, g, TimeAtMaxHeight);
		}
		CalculateTraveledDistance(CurrentTime, g, TimeAtMaxHeight);
	}
	CalculateTraveledDistance(TimeAtMaxHeight * 2, g, TimeAtMaxHeight);
}

int main(int, char *[])
{
	printf("MaxJumpHeight: ");
	int MaxJumpHeight = InputChek();
	CalculateTimeAtMaxHeight(MaxJumpHeight);
	PrintResult();
	return 0;
}