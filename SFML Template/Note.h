#pragma once
#include "SpriteGo.h"
class Note : public SpriteGo
{
protected:
    int amount = 0;


public:
    Note(const std::string& name, const std::string& textId, int amt_in);
    ~Note();

    int GetAmount() const;
};

////���� �ӽ�����, ���� �����ʿ�
//Note::Note(const std::string& name_in, const std::string& textId, int amt_in)
//    :amount(amt_in)
//{
//    textureId = textId;
//    name = name_in;
//    active = false;
//}
//TEXTURE_MGR.Load("Resources/images/note1m.png");
////unquote