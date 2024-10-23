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
	// T M B »ó Áß ÇÏ
	// L C R ¿Þ Áß ¿À
	p04, p14, p24, p34, p44, // 0~4   //¸ò 0
	p03, p13, p23, p33, p43, // 5~9
	p02, p12, p22, p32, p42, // 10~14
	p01, p11, p21, p31, p41, // 15~19
	p00, p10, p20, p30, p40, // 20~24 // ¸ò4
	//³ª¸ÓÁö 01234
	Custom,
};

enum class ObjectType
{
	defaultOJ,
	ClickableOJ,
	ClickedOJ,
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