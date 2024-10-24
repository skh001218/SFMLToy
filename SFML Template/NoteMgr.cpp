#include "stdafx.h"
#include "NoteMgr.h"

void NoteMgr::Init()
{
	for (int i = 0; i < 54; i++)
	{
		int j = 1;
		if (i < 6) // index 0~5 1만원 (6 / 6)
		{
			notes.push_back(Note("Note_ID_" + std::to_string(i), "Resources/images/note" + std::to_string(j) + "m.png", j * 10000));
			if (i == 5)
				j++;
		}
		if (i < 14) // index 6~13 2만원 (8 / 14)
		{
			notes.push_back(Note("Note_ID_" + std::to_string(i), "Resources/images/note" + std::to_string(j) + "m.png", j * 10000));
			if (i == 13)
				j++;
		}
		if (i < 22) // index 14~21 3만원 (8 / 22)
		{
			notes.push_back(Note("Note_ID_" + std::to_string(i), "Resources/images/note" + std::to_string(j) + "m.png", j * 10000));
			if (i == 21)
				j++;
		}
		if (i < 28) // index 22~27 4만원 (6 / 28)
		{
			notes.push_back(Note("Note_ID_" + std::to_string(i), "Resources/images/note" + std::to_string(j) + "m.png", j * 10000));
			if (i == 27)
				j++;
		}
		if (i < 34) // index 28~33 5만원 (6 / 34)
		{
			notes.push_back(Note("Note_ID_" + std::to_string(i), "Resources/images/note" + std::to_string(j) + "m.png", j * 10000));
			if (i == 33)
				j++;
		}
		if (i < 39) // index 34~38 6만원 (5 / 39)
		{
			notes.push_back(Note("Note_ID_" + std::to_string(i), "Resources/images/note" + std::to_string(j) + "m.png", j * 10000));
			if (i == 38)
				j++;
		}
		if (i < 44) // index 39~43 7만원 (5 / 44)
		{
			notes.push_back(Note("Note_ID_" + std::to_string(i), "Resources/images/note" + std::to_string(j) + "m.png", j * 10000));
			if (i == 43)
				j++;
		}
		if (i < 49) // index 44~48 8만원 (5 / 49)
		{
			notes.push_back(Note("Note_ID_" + std::to_string(i), "Resources/images/note" + std::to_string(j) + "m.png", j * 10000));
			if (i == 49)
				j++;
		}
		if (i < 54) // index 49~53 9만원 (5 / 54)
		{
			notes.push_back(Note("Note_ID_" + std::to_string(i), "Resources/images/note" + std::to_string(j) + "m.png", j * 10000));
		}
	}
}

void NoteMgr::SetNotes()
{




}
