#ifndef BALL_H
#define BALL_H

#include <SDL2/SDL.h>

/* Constants */
extern const int BALL_WIDTH;

typedef enum BallEdge {
  BALL_EDGE_TOP,
  BALL_EDGE_BOTTOM,
  BALL_EDGE_LEFT,
  BALL_EDGE_RIGHT
} BallEdge_t;

typedef struct {
  int x_vel;
  int y_vel;
}Velocity;

typedef struct{
  SDL_Rect rect;
  Velocity vel;  
}Ball;


Ball ball_create();

void ball_update_position(Ball *ball);
int ball_render(SDL_Renderer *renderer, Ball *ball);

#endif