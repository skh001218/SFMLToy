#include "stdafx.h"
#include <iostream>

int main()
{
    FRAMEWROK.Init(1920, 1080, "SFML Framework");
    FRAMEWROK.Do();
    FRAMEWROK.Release();

    return 0;
}