#include "pch.h"

void entry()
{
	std::cout << "[MobRider] Loaded!\n";
}

THook(bool, "?attack@Player@@UEAA_NAEAVActor@@@Z", Player* pl, Actor* ac)
{
	if (pl->getCarriedItem().getId() == 270 && ac->getEntityTypeId() == 1)
	{
		auto ac2 = LocateS<WLevel>()->getPlayer(ac->getNameTag());
		auto pl2 = LocateS<WLevel>()->getPlayer(pl->getNameTag());
		if (ac2.value()->getCarriedItem().getId() != 270) {
			pl2.value().sendText(u8"只有当对方也拿着木镐时才能骑对方", TextType{ TIP });
			return false;
		}
		ac2.value()->addRider(*pl);
		pl2.value().sendText(u8"因为BUG，你需要骑上马并让被骑的玩家断开服务器才能真正地取消乘骑状态");
		return false;
	}
	return original(pl, ac);
}