#include "stdafx.h"
#include "Note.h"

Note::Note(const std::string& name_in, const std::string& textId, int amt_in)
    :amount(amt_in)
{
    textureId = textId;
    name = name_in;
    active = false;
}

Note::~Note()
{
}

int Note::GetAmount() const
{
    return amount;
}
