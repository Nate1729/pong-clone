#include <stdio.h>

#include <SDL2/SDL.h>

#include "ball.h"
#include "constants.h"

const int BALL_WIDTH = 5;

Ball ball_create()
{
  SDL_Rect rect = {
    .h=BALL_WIDTH,
    .w=BALL_WIDTH,
    .x=(SCREEN_WIDTH-BALL_WIDTH)/2,
    .y=0
  };

  Velocity initial_ball_velocity = {.x_vel=10, .y_vel=5};

  return (Ball) {
    .rect=rect,
    .vel=initial_ball_velocity
  };
}

void ball_update_position(Ball *ball)
{
  /* Collision Detection */
  int edge_left = ball->rect.x;
  int edge_right = edge_left + ball->rect.w;
  int edge_top = ball->rect.y;
  int edge_bottom = edge_top + ball->rect.h;

  if (edge_left + ball->vel.x_vel < 0)
  {
    printf("Right Player Scored!\n");
    ball_reset(ball);
  }
  if (edge_right + ball->vel.x_vel > SCREEN_WIDTH)
  {
    printf("Left Player Scored!\n");
    ball_reset(ball);
  }
  if (edge_top + ball->vel.y_vel < 0)
  {
    printf("Collision with TOP edge of screen!\n");
    ball->vel.y_vel *= -1;
  }
  if (edge_bottom + ball->vel.y_vel > SCREEN_HEIGHT)
  {
    printf("Collision with BOTTOM edge of screen!\n");
    ball->vel.y_vel *= -1;
  }

  /* Updating the ball position */
  ball->rect.x += ball->vel.x_vel;
  ball->rect.y += ball->vel.y_vel;
}

void ball_reset(Ball *ball)
{
  Ball new_ball = ball_create();
  memcpy(ball, &new_ball, sizeof(Ball));
}

int ball_render(SDL_Renderer *renderer, Ball *ball)
{
  int render_result;
  render_result = SDL_RenderFillRect(renderer, &ball->rect);

  return render_result;
}
