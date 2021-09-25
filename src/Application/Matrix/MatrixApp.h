/**
 * @file MatrixApp.h
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @version 0.1
 * @date 23-08-212021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _H_MATRIXAPP
#define _H_MATRIXAPP

#include "Application/Application.h"

/**
 * @brief Matrix Application. A screen saver that looks like the matrix movie screen saver
 * 
 */
class MatrixApp : public Application
{
private:
  /** Array of vertical position for each column */
  int positions[32];

  virtual void doUpdate();
  virtual void doBegin();
  virtual void draw();

public:
  using Application::Application;
};

#endif