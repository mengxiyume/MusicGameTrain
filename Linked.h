#pragma once

#include"Structur.h"

Drop* GetDrop(Drop* Last);
ReLine* GetLine(ReLine* Last);
ReLine* GetRepateLine(size_t ReNumber);

void CloseDrop(Drop* dest);
void CloseLine(ReLine* dest);
void CloseRepate(ReLine* dest);