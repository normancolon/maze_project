#include "../hdrs/h.h"

/**
 * distanceBetweenPoints - Finds the distance between two points
 * @x1: x coordinate of the starting point
 * @y1: y coordinate of the starting point
 * @x2: x coordinate of the end point
 * @y2: y coordinate of the end point
 * Return: the distance between two points
 */
float distanceBetweenPoints(float x1, float y1, float x2, float y2)
{
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

/**
 * isRayFacingDown - check if the ray is facing down
 * @angle: current ray angle
 * Return: true if facing down, false otherwise
 */
bool isRayFacingDown(float angle)
{
    return (angle > 0 && angle < PI);
}

/**
 * isRayFacingUp - check if the ray is facing up
 * @angle: current ray angle
 * Return: true if facing up, false otherwise
 */
bool isRayFacingUp(float angle)
{
    return !isRayFacingDown(angle);
}

/**
 * isRayFacingRight - check if the ray is facing to the right
 * @angle: current ray angle
 * Return: true if facing right, false otherwise
 */
bool isRayFacingRight(float angle)
{
    return (angle < 0.5 * PI || angle > 1.5 * PI);
}

/**
 * isRayFacingLeft - check if the ray is facing to the left
 * @angle: current ray angle
 * Return: true if facing left, false otherwise
 */
bool isRayFacingLeft(float angle)
{
    return !isRayFacingRight(angle);
}
