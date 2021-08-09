#pragma once
#include <stdio.h>

void init();

void* malloc(size_t size);

void* realloc(void* ptr, size_t size);

void free();
