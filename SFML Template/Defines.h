#pragma once

enum class SceneIds
{
	None = -1,
	Dev1,
	Dev2,
	Count,
};

enum class Origins
{
	// T M B 상 중 하
	// L C R 왼 중 오
	TL, TC, TR,
	ML, MC, MR,
	BL, BC, BR,
	Custom,
};

enum class ClickableTypes
{
	disabled,
	enabled,
	clicked,
};

enum class TempPlayerNo
{
	player1,
	player2,
	player3,
	player4,
	player5,
	Count,
};