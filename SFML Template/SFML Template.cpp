﻿#include "stdafx.h"
#include <iostream>

int main()
{
    FRAMEWORK.Init(1920, 1080, "SFML Framework");
    FRAMEWORK.Do();
    FRAMEWORK.Release();

    return 0;
}