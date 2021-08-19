#pragma once
#include <stdio.h>

void* asBumpMalloc(size_t size);

void* asBumpRealloc(void* ptr, size_t size);

void asBumpFree(void* ptr);
