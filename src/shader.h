#ifndef SHADER_H
#define SHADER_H
#include <stdio.h>
#include <iostream>

unsigned int CompileShader(unsigned int type, const std::string& sourceFile);

unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

#endif