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
