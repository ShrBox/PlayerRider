#include "pch.h"

void entry()
{
	std::cout << "[PlayerRider] Loaded!\n";
}

THook(bool, "?attack@Player@@UEAA_NAEAVActor@@@Z", Player* pl, Actor* ac)
{
	if (pl->getCarriedItem().getId() == 271 && ac->getEntityTypeId() == 1)
	{
		SymCall("?_removeRider@Actor@@MEAAXAEBUActorUniqueID@@_N11@Z", void, Actor*, const ActorUniqueID*, bool, bool, bool)
			(
			ac, &pl->getUniqueID(), true, true, true
			);
		pl->kill();
		auto pl2 = LocateS<WLevel>()->getPlayer(pl->getNameTag());
		pl2.value().sendText(u8"����������");
		return false;
	}
	if (pl->getCarriedItem().getId() == 270 && ac->getEntityTypeId() == 1)
	{
		auto ac2 = LocateS<WLevel>()->getPlayer(ac->getNameTag());
		auto pl2 = LocateS<WLevel>()->getPlayer(pl->getNameTag());
		if (ac2.value()->getCarriedItem().getId() != 270) {
			pl2.value().sendText(u8"ֻ�е��Է�Ҳ����ľ��ʱ������Է�", TextType{ TIP });
			return false;
		}
		ac2.value()->addRider(*pl);
		pl2.value().sendText(u8"��ΪBUG������Ҫ��ľ������Է�����������ȡ������״̬");
		return false;
	}
	return original(pl, ac);
}