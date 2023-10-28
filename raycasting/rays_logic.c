/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:20:01 by mboudrio          #+#    #+#             */
/*   Updated: 2023/10/28 11:10:21 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double normalize(double angle)
{
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

void	rotate_player(t_map_data __unused *mape, double angle)
{
	mape->r_angle += angle;
	fill_window(mape);
}

float ray_distance(float x1, float y1, float x2, float y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
bool mapHasWallAt(t_map_data *mape, float y, float x)
{
  if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
  {
    return true;
  }
  int mapGridIndexX = (int)floor(x / SQ_);
  int mapGridIndexY = (int)floor(y / SQ_);
  if (mapGridIndexX >= mape->col_count)
    return (true);
  if (mapGridIndexY >= mape->row_count)
    return (true);
  char mapContent = mape->map[mapGridIndexY][mapGridIndexX];
  return mapContent == '1';
}

float short_distance(t_map_data *mape)
{
  if (mape->horDis < mape->verDis)
    return(mape->horDis);
  else
    return(mape->verDis);
}
float	calc_vert_dis(t_map_data *mape)
{
	float	dis;
    dis = sqrt(pow((mape->vertWallHitX - mape->p_x), 2) + pow((mape->vertWallHitY - mape->p_y), 2));
	return (dis);
}
float	calc_Hor_dis(t_map_data *mape)
{
	float	dis;
	  dis = sqrt(pow(mape->horzWallHitX - mape->p_x, 2) + pow(mape->horzWallHitY - mape->p_y, 2));
	return (dis);
}
void cast_all_rays(t_map_data *mape)
{
  int i;

  i = 0;
  mape->ray_angle = mape->r_angle - (mape->FOV / 2);
  while(i < WIDTH)
  {
    cast_horizontal_Ray(mape);
    cast_vertical_Ray(mape);
    mape->ray_angle += mape->FOV  / WIDTH;
    if(mape->foundHorzWallHit)
        mape->horDis = calc_Hor_dis(mape);
    else
        mape->horDis = 100000;

    if(mape->foundVertWallHit)
        mape->verDis = calc_vert_dis(mape);
    else
        mape->verDis = 100000;
    // float main = 0.0;
    generate3DProjection(mape, i);
    // if (mape->horDis > mape->verDis)
    // {
    //     // main = mape->verDis;
    //     drawVRotationLine(mape);

    // }
    // else
    // {
    //       // main = mape->horDis;
	  //      drawHRotationLine(mape);
    // }

    i++;
  }
}

void cast_horizontal_Ray(t_map_data *mape)
{
    mape->ray_angle = normalize(mape->ray_angle);
    // printf("%f\n", mape->ray_angle * 57.2958);

    mape->isRayFacingDown = mape->ray_angle > 0 && mape->ray_angle < M_PI;
    mape->isRayFacingUp = !mape->isRayFacingDown;

    mape->isRayFacingRight = mape->ray_angle <  M_PI_2 || mape->ray_angle > 3 * M_PI_2;
    mape->isRayFacingLeft = !mape->isRayFacingRight;

    float xintercept, yintercept;
    float xstep, ystep;

    mape->foundHorzWallHit = false;
    mape->horzWallHitX = mape->p_y;
    mape->horzWallHitY = mape->p_x;

    yintercept = (int)mape->p_y / SQ_ * SQ_;
    if (mape->isRayFacingDown)
    	yintercept += SQ_;
	  else
    	yintercept -= 0.001;

    xintercept = mape->p_x + (yintercept - mape->p_y) / tan(mape->ray_angle);

    ystep = SQ_;

    if (mape->isRayFacingUp)
    	ystep = -ystep;

    xstep = ystep / tan(mape->ray_angle);

    // if (mape->isRayFacingLeft && xstep > 0)
    // 	xstep = -xstep;
	  // else if (mape->isRayFacingRight && xstep < 0)
    // 	xstep = -xstep;

    mape->nextHorzTouchX = xintercept;
    mape->nextHorzTouchY = yintercept;

    while (mape->nextHorzTouchX >= 0 && mape->nextHorzTouchX <= WIDTH && mape->nextHorzTouchY >= 0 && mape->nextHorzTouchY <= HEIGHT)
    {
        float xToCheck = mape->nextHorzTouchX;
        float yToCheck = mape->nextHorzTouchY;
        if (mape->isRayFacingUp)
            yToCheck -= 1;

        if (mapHasWallAt(mape,xToCheck, yToCheck))
		    {
            mape->horzWallHitX = mape->nextHorzTouchX;
            mape->horzWallHitY = mape->nextHorzTouchY;
            mape->foundHorzWallHit = true;
            break;
        }
		  else
		{
            mape->nextHorzTouchX += xstep;
            mape->nextHorzTouchY += ystep;
        }
    }
}
void cast_vertical_Ray(t_map_data *mape)
{
    mape->ray_angle = normalize(mape->ray_angle);
	  float xintercept, yintercept;
    float xstep, ystep;

    mape->foundVertWallHit = false;
    mape->vertWallHitX = mape->p_y;
    mape->vertWallHitY = mape->p_x;

    xintercept = (int)mape->p_x / SQ_ * SQ_;
    if (mape->isRayFacingRight)
    	xintercept += SQ_;
	  else
    	xintercept -= 0.001;

    yintercept = mape->p_y + (xintercept - mape->p_x) * tan(mape->ray_angle);

    xstep = SQ_;

    if (mape->isRayFacingLeft)
    	xstep = -xstep;

    ystep = SQ_ * tan(mape->ray_angle);

    if (mape->isRayFacingUp && ystep > 0)
    	ystep = -ystep;
	  else if (mape->isRayFacingDown && ystep < 0)
    	ystep = -ystep;

    mape->nextVertTouchX = xintercept;
    mape->nextVertTouchY = yintercept;

    while (mape->nextVertTouchX >= 0 && mape->nextVertTouchX <= WIDTH && mape->nextVertTouchY >= 0 && mape->nextVertTouchY <= HEIGHT)
	  {
        float yToCheck = mape->nextVertTouchY;
        float xToCheck = mape->nextVertTouchX;
		    if (mape->isRayFacingLeft)
    		  xToCheck -= 1;

        if (mapHasWallAt(mape,xToCheck, yToCheck))
		    {
            mape->vertWallHitX = mape->nextVertTouchX;
            mape->vertWallHitY = mape->nextVertTouchY;
            mape->foundVertWallHit = true;
            break;
        }
		    else
		    {
            mape->nextVertTouchX += xstep;
            mape->nextVertTouchY += ystep;
        }
    }
}

void generate3DProjection(t_map_data *mape, int __unused i)
{
    float distance;
    distance = short_distance(mape);
    float perpDistance = distance * cos(mape->ray_angle - mape->r_angle);
    float projectedWallHeight = (SQ_ / perpDistance) * ((WIDTH / 2) / tan(mape->FOV/2));

        int wallStripHeight = (int)projectedWallHeight;
        int wallTopPixel = (HEIGHT / 2) - (wallStripHeight / 2);
        if (wallTopPixel < 0)
            wallTopPixel = 0;
        int wallBottomPixel = (HEIGHT / 2) + (wallStripHeight / 2);
        if (wallBottomPixel > HEIGHT)
            wallBottomPixel = HEIGHT;
        DDA(mape, i, wallTopPixel, i, wallBottomPixel);
        for (int j = 0; j < wallTopPixel; j++)
        {
          if (i > 0 && i < HEIGHT && j > 0 && j < WIDTH )
          mlx_put_pixel(mape->img, i, j, 0xfffff0f0);
        }
        for (int j = wallBottomPixel; j < HEIGHT; j++)
        {
          if (i > 0 && i < HEIGHT && j > 0 && j < WIDTH )
          mlx_put_pixel(mape->img, i, j, 0xf000f000);
        }
}
